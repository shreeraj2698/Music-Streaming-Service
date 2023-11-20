

#pragma once

#include "services/recommendation/IPlaylistGeneratorService.hpp"
#include "services/recommendation/IRecommendationService.hpp"
#include "playlist-constraints/IConstraint.hpp"

namespace Recommendation
{
	class PlaylistGeneratorService : public IPlaylistGeneratorService
	{
		public:
			PlaylistGeneratorService(Database::Db& db, Recommendation::IRecommendationService& recommendationService);

		private:
			TrackContainer extendPlaylist(Database::TrackListId tracklistId, std::size_t maxCount) const override;

			TrackContainer getTracksFromTrackList(Database::TrackListId tracklistId) const;

			Database::Db& _db;
			Recommendation::IRecommendationService& _recommendationService;
			std::vector<std::unique_ptr<PlaylistGeneratorConstraint::IConstraint>> _constraints;
	};
} // namespace Radio
