

#include "ConsecutiveArtists.hpp"

#include <algorithm>

#include "services/database/Db.hpp"
#include "services/database/Release.hpp"
#include "services/database/Session.hpp"
#include "services/database/Track.hpp"
#include "utils/Logger.hpp"

namespace Recommendation::PlaylistGeneratorConstraint
{
	namespace
	{
		std::size_t
		countCommonArtists(const ArtistContainer& artists1, const ArtistContainer& artists2)
		{
			ArtistContainer intersection;

			std::set_intersection(std::cbegin(artists1), std::cend(artists1),
						std::cbegin(artists2), std::cend(artists2),
						std::back_inserter(intersection));

			return intersection.size();
		}
	}

	ConsecutiveArtists::ConsecutiveArtists(Database::Db& db)
		: _db {db}
	{}

	float
	ConsecutiveArtists::computeScore(const std::vector<Database::TrackId>& trackIds, std::size_t trackIndex)
	{
		assert(!trackIds.empty());
		assert(trackIndex <= trackIds.size() - 1);

		const ArtistContainer artists {getArtists(trackIds[trackIndex])};

		constexpr std::size_t rangeSize{ 3 }; // check up to rangeSize tracks before/after the target track
		static_assert(rangeSize > 0);

		float score {};
		for (std::size_t i {1}; i < rangeSize; ++i)
		{
			if (trackIndex >= i)
				score += countCommonArtists(artists, getArtists(trackIds[trackIndex - i])) / static_cast<float>(i);

			if (trackIndex + i < trackIds.size())
				score += countCommonArtists(artists, getArtists(trackIds[trackIndex + i])) / static_cast<float>(i);
		}

		return score;
	}

	ArtistContainer
	ConsecutiveArtists::getArtists(Database::TrackId trackId)
	{
		using namespace Database;

		ArtistContainer res;

		Session& dbSession {_db.getTLSSession()};
		auto transaction {dbSession.createSharedTransaction()};

		const Track::pointer track {Track::find(dbSession, trackId)};
		if (!track)
			return res;

		res = track->getArtistIds({});
		std::sort(std::begin(res), std::end(res));

		return res;
	}


} // namespace Recommendation

