

#include "DuplicateTracks.hpp"

#include <algorithm>

namespace Recommendation::PlaylistGeneratorConstraint
{
	float
	DuplicateTracks::computeScore(const std::vector<Database::TrackId>& trackIds, std::size_t trackIndex)
	{
		const auto count {std::count(std::cbegin(trackIds), std::cend(trackIds), trackIds[trackIndex])};
		return count == 1 ? 0 : 1000;
	}
} // namespace Recommendation

