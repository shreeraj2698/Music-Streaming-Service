

#include "PlaylistGeneratorService.hpp"

#include "services/database/Db.hpp"
#include "services/database/Session.hpp"
#include "services/database/Track.hpp"
#include "services/recommendation/IRecommendationService.hpp"
#include "playlist-constraints/ConsecutiveArtists.hpp"
#include "playlist-constraints/ConsecutiveReleases.hpp"
#include "playlist-constraints/DuplicateTracks.hpp"
#include "utils/Logger.hpp"

namespace Recommendation
{
	using namespace Database;

	std::unique_ptr<IPlaylistGeneratorService>
	createPlaylistGeneratorService(Db& db, Recommendation::IRecommendationService& recommendationService)
	{
		return std::make_unique<PlaylistGeneratorService>(db, recommendationService);
	}

	PlaylistGeneratorService::PlaylistGeneratorService(Db& db, Recommendation::IRecommendationService& recommendationService)
		: _db {db}
	, _recommendationService {recommendationService}
	{
		_constraints.push_back(std::make_unique<PlaylistGeneratorConstraint::ConsecutiveArtists>(_db));
		_constraints.push_back(std::make_unique<PlaylistGeneratorConstraint::ConsecutiveReleases>(_db));
		_constraints.push_back(std::make_unique<PlaylistGeneratorConstraint::DuplicateTracks>());
	}

	std::vector<TrackId>
	PlaylistGeneratorService::extendPlaylist(TrackListId tracklistId, std::size_t maxCount) const
	{
		LMS_LOG(RECOMMENDATION, DEBUG) << "Requested to extend playlist by " << maxCount << " similar tracks";

		// supposed to be ordered from most similar to least similar
		std::vector<TrackId> similarTracks {_recommendationService.findSimilarTracks(tracklistId, maxCount * 2)}; // ask for more tracks than we need as it will be easier to respect constraints

		const std::vector<TrackId> startingTracks {getTracksFromTrackList(tracklistId)};

		std::vector<TrackId> finalResult = startingTracks;
		finalResult.reserve(startingTracks.size() + maxCount);

		std::vector<float> scores;
		for (std::size_t i {}; i < maxCount; ++i)
		{
			if (similarTracks.empty())
				break;

			scores.resize(similarTracks.size(), {});

			// select the similar track that has the best score
			for (std::size_t trackIndex {}; trackIndex < similarTracks.size(); ++trackIndex)
			{
				using namespace Database::Debug;

				finalResult.push_back(similarTracks[trackIndex]);

				scores[trackIndex] = 0;
				for (const auto& constraint : _constraints)
					scores[trackIndex] += constraint->computeScore(finalResult, finalResult.size() - 1);

				finalResult.pop_back();

				// early exit if we consider we found a track with no constraint violation (since similarTracks sorted from most to least similar)
				if (scores[trackIndex] < 0.01)
					break;
			}

			// get the best score
			const std::size_t bestScoreIndex {static_cast<std::size_t>(std::distance(std::cbegin(scores), std::min_element(std::cbegin(scores), std::cend(scores))))};

			finalResult.push_back(similarTracks[bestScoreIndex]);
			similarTracks.erase(std::begin(similarTracks) + bestScoreIndex);
		}

		// for now, just get some more similar tracks
		return std::vector(std::cbegin(finalResult) + startingTracks.size(), std::cend(finalResult));
	}

	TrackContainer
	PlaylistGeneratorService::getTracksFromTrackList(Database::TrackListId tracklistId) const
	{
		TrackContainer tracks;

		Session& dbSession {_db.getTLSSession()};
		auto transaction {dbSession.createSharedTransaction()};

		Track::FindParameters params;
		params.setTrackList(tracklistId);
		params.setSortMethod(TrackSortMethod::TrackList);
		params.setDistinct(false);

		for (const TrackId trackId : Track::find(dbSession, params).results)
			tracks.push_back(trackId);

		return tracks;
	}
}
