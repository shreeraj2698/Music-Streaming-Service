

#pragma once

#include "IConstraint.hpp"

#include "services/database/ReleaseId.hpp"

namespace Database
{
	class Db;
}

namespace Recommendation::PlaylistGeneratorConstraint
{
	class ConsecutiveArtists : public IConstraint
	{
		public:
			ConsecutiveArtists(Database::Db& db);

		private:
			 float computeScore(const TrackContainer& trackIds, std::size_t trackIndex) override;
			 ArtistContainer getArtists(Database::TrackId trackId);

			 Database::Db& _db;
	};
} // namespace Recommendation::PlaylistGeneratorConstraint

