/*
 * Copyright (C) 2022 Emeric Poupon
 *
 * This file is part of LMS.
 *
 * LMS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * LMS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with LMS.  If not, see <http://www.gnu.org/licenses/>.
 */

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

