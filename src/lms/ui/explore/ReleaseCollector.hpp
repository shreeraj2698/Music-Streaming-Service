

#pragma once

#include <vector>

#include "DatabaseCollectorBase.hpp"

#include "services/database/Object.hpp"
#include "services/database/ReleaseId.hpp"
#include "services/database/Types.hpp"

namespace Database
{
	class Release;
}

namespace UserInterface
{
	class ReleaseCollector : public DatabaseCollectorBase
	{
		public:
			using DatabaseCollectorBase::DatabaseCollectorBase;

			Database::RangeResults<Database::ReleaseId>	get(Database::Range range);
			void reset() { _randomReleases.reset(); }

		private:
			Database::RangeResults<Database::ReleaseId> getRandomReleases(Range range);
			std::optional<Database::RangeResults<Database::ReleaseId>> _randomReleases;
	};
} // ns UserInterface

