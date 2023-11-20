

#include "services/database/Types.hpp"

#include <set>

namespace Database
{
	static const std::set<Bitrate> allowedAudioBitrates
	{
		64000,
		96000,
		128000,
		192000,
		320000,
	};

	void visitAllowedAudioBitrates(std::function<void(Bitrate)> func)
	{
		for (Bitrate bitrate : allowedAudioBitrates)
			func(bitrate);
	}

	bool isAudioBitrateAllowed(Bitrate bitrate)
	{
		return allowedAudioBitrates.find(bitrate) != std::cend(allowedAudioBitrates);
	}

	DateRange
	DateRange::fromYearRange(int from, int to)
	{
		return DateRange {{from, 1, 1}, {to, 12, 31}};
	}
}

