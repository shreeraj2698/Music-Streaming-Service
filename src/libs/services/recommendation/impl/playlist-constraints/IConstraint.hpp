

#pragma once

#include <vector>

#include "services/recommendation/Types.hpp"

namespace Recommendation::PlaylistGeneratorConstraint
{
	class IConstraint
	{
		public:
			virtual ~IConstraint() = default;

			// compute the score of the track at index trackIndex
			// 0: best
			// 1: worst
			// > 1 : violation
			virtual float computeScore(const TrackContainer& trackIds, std::size_t trackIndex) = 0;
	};
} // namespace Recommendation
