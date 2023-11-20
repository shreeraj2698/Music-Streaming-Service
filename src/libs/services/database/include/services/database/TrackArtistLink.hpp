

#pragma once

#include <string>
#include <string_view>

#include <Wt/Dbo/Dbo.h>

#include "services/database/ArtistId.hpp"
#include "services/database/IdType.hpp"
#include "services/database/Object.hpp"
#include "services/database/ReleaseId.hpp"
#include "services/database/TrackId.hpp"
#include "services/database/Types.hpp"
#include "utils/EnumSet.hpp"

LMS_DECLARE_IDTYPE(TrackArtistLinkId)

namespace Database
{
    class Artist;
    class Session;
    class Track;

    class TrackArtistLink final : public Object<TrackArtistLink, TrackArtistLinkId>
    {
    public:
        struct FindParameters
        {
            Range								range;
            std::optional<TrackArtistLinkType>  linkType;   // if set, only artists that have produced at least one track with this link type
            ArtistId							artist;		// if set, links involved with this artist
            ReleaseId							release;	// if set, artists involved in this release
            TrackId                             track;      // if set, artists involved in this track

            FindParameters& setRange(Range _range) { range = _range; return *this; }
            FindParameters& setLinkType(std::optional<TrackArtistLinkType> _linkType) { linkType = _linkType; return *this; }
            FindParameters& setArtist(ArtistId _artist) { artist = _artist; return *this; }
            FindParameters& setRelease(ReleaseId _release) { release = _release; return *this; }
            FindParameters& setTrack(TrackId _track) { track = _track; return *this; }
        };

        TrackArtistLink() = default;
        TrackArtistLink(ObjectPtr<Track> track, ObjectPtr<Artist> artist, TrackArtistLinkType type, std::string_view subType);

        static RangeResults<TrackArtistLinkId>	find(Session& session, const FindParameters& parameters);
        static pointer 							find(Session& session, TrackArtistLinkId linkId);
        static pointer							create(Session& session, ObjectPtr<Track> track, ObjectPtr<Artist> artist, TrackArtistLinkType type, std::string_view subType = {});
        static EnumSet<TrackArtistLinkType>     findUsedTypes(Session& session);
        static EnumSet<TrackArtistLinkType>     findUsedTypes(Session& session, ArtistId _artist);

        ObjectPtr<Track>		getTrack() const { return _track; }
        ObjectPtr<Artist>		getArtist() const { return _artist; }
        TrackArtistLinkType		getType() const { return _type; }
        std::string_view		getSubType() const { return _subType; }

        template<class Action>
        void persist(Action& a)
        {
            Wt::Dbo::field(a, _type, "type");
            Wt::Dbo::field(a, _subType, "subtype");

            Wt::Dbo::belongsTo(a, _track, "track", Wt::Dbo::OnDeleteCascade);
            Wt::Dbo::belongsTo(a, _artist, "artist", Wt::Dbo::OnDeleteCascade);
        }

    private:
        TrackArtistLinkType _type;
        std::string _subType;

        Wt::Dbo::ptr<Track> _track;
        Wt::Dbo::ptr<Artist> _artist;
    };
}

