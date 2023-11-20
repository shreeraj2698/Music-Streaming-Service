

#pragma once

#include "services/database/Object.hpp"
#include "services/database/TrackId.hpp"
#include "DatabaseCollectorBase.hpp"

namespace Database
{
	class Track;
}

namespace UserInterface
{
	class TrackCollector : public DatabaseCollectorBase
	{
		public:
			using DatabaseCollectorBase::DatabaseCollectorBase;

			Database::RangeResults<Database::TrackId>	get(Database::Range range);
			void reset() { _randomTracks.reset(); }

		private:
			Database::RangeResults<Database::TrackId> getRandomTracks(Range range);
			std::optional<Database::RangeResults<Database::TrackId>> _randomTracks;
	};
} // ns UserInterface

