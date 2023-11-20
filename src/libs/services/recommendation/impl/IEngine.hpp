

#pragma once

#include <memory>
#include "services/database/Types.hpp"
#include "services/database/TrackListId.hpp"
#include "services/recommendation/Types.hpp"
#include "utils/EnumSet.hpp"

namespace Database
{
	class Db;
}

namespace Recommendation
{
	class IEngine
	{
		public:
			virtual ~IEngine() = default;

			virtual void load(bool forceReload, const ProgressCallback& progressCallback = {}) = 0;
			virtual void requestCancelLoad() = 0;

			virtual TrackContainer findSimilarTracksFromTrackList(Database::TrackListId tracklistId, std::size_t maxCount) const = 0;
			virtual TrackContainer findSimilarTracks(const std::vector<Database::TrackId>& tracksId, std::size_t maxCount) const = 0;
			virtual ReleaseContainer getSimilarReleases(Database::ReleaseId releaseId, std::size_t maxCount) const = 0;
			virtual ArtistContainer getSimilarArtists(Database::ArtistId artistId, EnumSet<Database::TrackArtistLinkType> linkTypes, std::size_t maxCount) const = 0;
	};

	std::unique_ptr<IEngine> createEngine(Database::Db& db);

} // ns Recommendation

