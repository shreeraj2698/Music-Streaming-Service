

#include "ClustersEngine.hpp"

#include "services/database/Artist.hpp"
#include "services/database/Cluster.hpp"
#include "services/database/Db.hpp"
#include "services/database/Release.hpp"
#include "services/database/Session.hpp"
#include "services/database/Track.hpp"
#include "services/database/TrackList.hpp"

namespace Recommendation {

    using namespace Database;

    std::unique_ptr<IEngine> createClustersEngine(Db& db)
    {
        return std::make_unique<ClusterEngine>(db);
    }

    TrackContainer ClusterEngine::findSimilarTracks(const std::vector<TrackId>& trackIds, std::size_t maxCount) const
    {
        if (maxCount == 0)
            return {};

        Session& dbSession{ _db.getTLSSession() };
        auto transaction{ dbSession.createSharedTransaction() };

        const auto similarTrackIds{ Track::findSimilarTracks(dbSession, trackIds, Range {0, maxCount}) };
        return std::move(similarTrackIds.results);
    }

    TrackContainer ClusterEngine::findSimilarTracksFromTrackList(TrackListId tracklistId, std::size_t maxCount) const
    {
        TrackContainer res;
        if (maxCount == 0)
            return res;

        {
            Session& dbSession{ _db.getTLSSession() };
            auto transaction{ dbSession.createSharedTransaction() };

            const TrackList::pointer trackList{ TrackList::find(dbSession, tracklistId) };
            if (!trackList)
                return res;

            const auto tracks{ trackList->getSimilarTracks(0, maxCount) };
            res.reserve(tracks.size());
            std::transform(std::cbegin(tracks), std::cend(tracks), std::back_inserter(res), [](const auto& track) { return track->getId(); });
        }

        return res;
    }

    ReleaseContainer ClusterEngine::getSimilarReleases(ReleaseId releaseId, std::size_t maxCount) const
    {
        ReleaseContainer res;
        if (maxCount == 0)
            return res;

        {
            Session& dbSession{ _db.getTLSSession() };
            auto transaction{ dbSession.createSharedTransaction() };

            auto release{ Release::find(dbSession, releaseId) };
            if (!release)
                return res;

            const auto releases{ release->getSimilarReleases(0, maxCount) };
            res.reserve(releases.size());
            std::transform(std::cbegin(releases), std::cend(releases), std::back_inserter(res), [](const auto& release) { return release->getId(); });
        }

        return res;
    }

    ArtistContainer ClusterEngine::getSimilarArtists(ArtistId artistId, EnumSet<TrackArtistLinkType> artistLinkTypes, std::size_t maxCount) const
    {
        if (maxCount == 0)
            return {};

        Session& dbSession{ _db.getTLSSession() };
        auto transaction{ dbSession.createSharedTransaction() };

        auto artist{ Artist::find(dbSession, artistId) };
        if (!artist)
            return {};

        const auto similarArtistIds{ artist->findSimilarArtists(artistLinkTypes, Range {0, maxCount}) };
        return std::move(similarArtistIds.results);
    }

} // namespace Recommendation
