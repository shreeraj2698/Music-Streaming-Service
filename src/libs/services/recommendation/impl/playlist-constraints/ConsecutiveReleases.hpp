

#pragma once

#include "IConstraint.hpp"

#include "services/database/ReleaseId.hpp"

namespace Database
{
	class Db;
}

namespace Recommendation::PlaylistGeneratorConstraint
{
	class ConsecutiveReleases : public IConstraint
	{
		public:
			ConsecutiveReleases(Database::Db& db);

		private:
			 float computeScore(const std::vector<Database::TrackId>& trackIds, std::size_t trackIndex) override;

			 Database::ReleaseId getReleaseId(Database::TrackId trackId);

			 Database::Db& _db;
	};
} // namespace Recommendation

