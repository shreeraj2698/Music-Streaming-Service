

#include "ConsecutiveReleases.hpp"

#include "services/database/Db.hpp"
#include "services/database/Release.hpp"
#include "services/database/Session.hpp"
#include "services/database/Track.hpp"
#include "utils/Logger.hpp"

namespace Recommendation::PlaylistGeneratorConstraint
{
	ConsecutiveReleases::ConsecutiveReleases(Database::Db& db)
		: _db {db}
	{}

	float
	ConsecutiveReleases::computeScore(const std::vector<Database::TrackId>& trackIds, std::size_t trackIndex)
	{
		assert(!trackIds.empty());
		assert(trackIndex <= trackIds.size() - 1);

		const Database::ReleaseId releaseId {getReleaseId(trackIds[trackIndex])};

		constexpr std::size_t rangeSize{ 3 }; // check up to rangeSize tracks before/after the target track
		static_assert(rangeSize > 0);

		float score {};
		for (std::size_t i {1}; i < rangeSize; ++i)
		{
			if ((trackIndex >= i) && getReleaseId(trackIds[trackIndex - i]) == releaseId)
				score += (1.f / static_cast<float>(i));

			if ((trackIndex + i < trackIds.size()) && getReleaseId(trackIds[trackIndex + i]) == releaseId)
				score += (1.f / static_cast<float>(i));
		}

		return score;
	}

	Database::ReleaseId
	ConsecutiveReleases::getReleaseId(Database::TrackId trackId)
	{
		using namespace Database;

		Session& dbSession {_db.getTLSSession()};
		auto transaction {dbSession.createSharedTransaction()};

		const Track::pointer track {Track::find(dbSession, trackId)};
		if (!track)
			return {};

		const Release::pointer release {track->getRelease()};
		if (!release)
			return {};

		return release->getId();
	}
} // namespace Recommendation

