

#pragma once

#include "IConstraint.hpp"

namespace Recommendation::PlaylistGeneratorConstraint
{
	class DuplicateTracks : public IConstraint
	{
		private:
			float computeScore(const std::vector<Database::TrackId>& trackIds, std::size_t trackIndex) override;
	};
} // namespace Recommendation::PlaylistGeneratorConstraints

