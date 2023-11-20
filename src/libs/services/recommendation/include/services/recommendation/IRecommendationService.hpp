

#pragma once

#include <memory>
#include "utils/EnumSet.hpp"
#include "services/database/TrackListId.hpp"
#include "services/database/Types.hpp"
#include "services/recommendation/Types.hpp"

namespace Database
{
	class Db;
}

namespace Recommendation
{
	class IRecommendationService
	{
		public:
			virtual ~IRecommendationService() = default;

			virtual void load(bool forceReload, const ProgressCallback& progressCallback = {}) = 0;
			virtual void cancelLoad() = 0;  // wait for cancel done

			virtual TrackContainer findSimilarTracks(Database::TrackListId tracklistId, std::size_t maxCount) const = 0;
			virtual TrackContainer findSimilarTracks(const std::vector<Database::TrackId>& tracksId, std::size_t maxCount) const = 0;
			virtual ReleaseContainer getSimilarReleases(Database::ReleaseId releaseId, std::size_t maxCount) const = 0;
			virtual ArtistContainer getSimilarArtists(Database::ArtistId artistId, EnumSet<Database::TrackArtistLinkType> linkTypes, std::size_t maxCount) const = 0;
	};

	std::unique_ptr<IRecommendationService> createRecommendationService(Database::Db& db);
} // ns Recommendation

