

#include "responses/Artist.hpp"

#include "services/database/Artist.hpp"
#include "services/database/Release.hpp"
#include "services/database/TrackArtistLink.hpp"
#include "services/database/User.hpp"
#include "services/scrobbling/IScrobblingService.hpp"
#include "utils/Service.hpp"
#include "utils/String.hpp"

#include "SubsonicId.hpp"

namespace API::Subsonic
{
    using namespace Database;

    namespace Utils
    {
        std::string joinArtistNames(const std::vector<Artist::pointer>& artists)
        {
            if (artists.size() == 1)
                return artists.front()->getName();

            std::vector<std::string> names;
            names.resize(artists.size());

            std::transform(std::cbegin(artists), std::cend(artists), std::begin(names),
                [](const Artist::pointer& artist)
                {
                    return artist->getName();
                });

            return StringUtils::joinStrings(names, ", ");
        }

        std::string_view toString(TrackArtistLinkType type)
        {
            switch (type)
            {
            case TrackArtistLinkType::Arranger: return "arranger";
            case TrackArtistLinkType::Artist: return "artist";
            case TrackArtistLinkType::Composer: return "composer";
            case TrackArtistLinkType::Conductor: return "conductor";
            case TrackArtistLinkType::Lyricist: return "lyricist";
            case TrackArtistLinkType::Mixer: return "mixer";
            case TrackArtistLinkType::Performer: return "performer";
            case TrackArtistLinkType::Producer: return "producer";
            case TrackArtistLinkType::ReleaseArtist: return "albumartist";
            case TrackArtistLinkType::Remixer: return "remixer";
            case TrackArtistLinkType::Writer: return "writer";
            }

            return "unknown";
        }
    }

    Response::Node createArtistNode(const Artist::pointer& artist, Session& session, const User::pointer& user, bool id3)
    {
        Response::Node artistNode{ createArtistNode(artist) };

        artistNode.setAttribute("id", idToString(artist->getId()));
        artistNode.setAttribute("name", artist->getName());

        if (id3)
        {
            const auto releases{ Release::find(session, Release::FindParameters {}.setArtist(artist->getId())) };
            artistNode.setAttribute("albumCount", releases.results.size());
        }

        if (const Wt::WDateTime dateTime{ Service<Scrobbling::IScrobblingService>::get()->getStarredDateTime(user->getId(), artist->getId()) }; dateTime.isValid())
            artistNode.setAttribute("starred", StringUtils::toISO8601String(dateTime));

        // OpenSubsonic specific fields (must always be set)
        if (!id3)
            artistNode.setAttribute("mediaType", "artist");

        {
            std::optional<UUID> mbid{ artist->getMBID() };
            artistNode.setAttribute("musicBrainzId", mbid ? mbid->getAsString() : "");
        }

        artistNode.setAttribute("sortName", artist->getSortName());

        // roles
        Response::Node roles;
        artistNode.createEmptyArrayValue("roles");
        for (const TrackArtistLinkType linkType : TrackArtistLink::findUsedTypes(session, artist->getId()))
            artistNode.addArrayValue("roles", Utils::toString(linkType));

        return artistNode;
    }

    Response::Node createArtistNode(const Artist::pointer& artist)
    {
        Response::Node artistNode;

        artistNode.setAttribute("id", idToString(artist->getId()));
        artistNode.setAttribute("name", artist->getName());

        return artistNode;
    }
}