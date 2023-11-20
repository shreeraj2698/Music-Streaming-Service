

#include "Playlist.hpp"

#include "services/database/TrackList.hpp"
#include "services/database/User.hpp"
#include "SubsonicId.hpp"

namespace API::Subsonic
{
    using namespace Database;

    static const std::string_view reportedDummyDate{ "2000-01-01T00:00:00" };

    Response::Node createPlaylistNode(const TrackList::pointer& tracklist, Session&)
    {
        Response::Node playlistNode;

        playlistNode.setAttribute("id", idToString(tracklist->getId()));
        playlistNode.setAttribute("name", tracklist->getName());
        playlistNode.setAttribute("songCount", tracklist->getCount());
        playlistNode.setAttribute("duration", std::chrono::duration_cast<std::chrono::seconds>(tracklist->getDuration()).count());
        playlistNode.setAttribute("public", tracklist->isPublic());
        playlistNode.setAttribute("created", reportedDummyDate);
        playlistNode.setAttribute("owner", tracklist->getUser()->getLoginName());

        return playlistNode;
    }
}