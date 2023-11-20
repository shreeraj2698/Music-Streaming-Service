

#pragma once

#include <memory>
#include "services/database/TrackListId.hpp"
#include "services/database/Types.hpp"
#include "services/recommendation/Types.hpp"

namespace Database
{
	class Db;
}

namespace Recommendation
{
	class IRecommendationService;
	class IPlaylistGeneratorService
	{
		public:
			virtual ~IPlaylistGeneratorService() = default;

			// extend an existing playlist with similar tracks (but use playlist contraints)
			virtual TrackContainer extendPlaylist(Database::TrackListId tracklistId, std::size_t maxCount) const = 0;
	};

	std::unique_ptr<IPlaylistGeneratorService> createPlaylistGeneratorService(Database::Db& db, IRecommendationService& recommandationService);
} // ns Recommendation

