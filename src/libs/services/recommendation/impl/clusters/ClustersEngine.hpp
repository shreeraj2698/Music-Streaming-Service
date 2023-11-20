

#pragma once

#include "IEngine.hpp"

namespace Recommendation
{

	class ClusterEngine : public IEngine
	{
		public:
			ClusterEngine(Database::Db& db) : _db {db} {}

			ClusterEngine(const ClusterEngine&) = delete;
			ClusterEngine(ClusterEngine&&) = delete;
			ClusterEngine& operator=(const ClusterEngine&) = delete;
			ClusterEngine& operator=(ClusterEngine&&) = delete;

		private:
			void load(bool, const ProgressCallback&) override {}
			void requestCancelLoad() override {}

			TrackContainer		findSimilarTracksFromTrackList(Database::TrackListId tracklistId, std::size_t maxCount) const override;
			TrackContainer		findSimilarTracks(const std::vector<Database::TrackId>& tracksId, std::size_t maxCount) const override;
			ReleaseContainer	getSimilarReleases(Database::ReleaseId releaseId, std::size_t maxCount) const override;
			ArtistContainer		getSimilarArtists(Database::ArtistId artistId, EnumSet<Database::TrackArtistLinkType> linkTypes, std::size_t maxCount) const override;

			Database::Db& _db;
	};

} // namespace Recommendation

