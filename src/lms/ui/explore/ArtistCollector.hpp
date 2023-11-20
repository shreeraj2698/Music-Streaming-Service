

#pragma once

#include <optional>

#include "DatabaseCollectorBase.hpp"
#include "services/database/ArtistId.hpp"
#include "services/database/Types.hpp"

namespace Database
{
	class Artist;
}

namespace UserInterface
{
	class ArtistCollector : public DatabaseCollectorBase
	{
		public:
			using DatabaseCollectorBase::DatabaseCollectorBase;

			Database::RangeResults<Database::ArtistId>	get(Database::Range range);
			void reset() { _randomArtists.reset(); }
			void setArtistLinkType(std::optional<Database::TrackArtistLinkType> linkType) { _linkType = linkType; }

		private:
			Database::RangeResults<Database::ArtistId>	getRandomArtists(Range range);
			std::optional<Database::RangeResults<Database::ArtistId>> _randomArtists;
			std::optional<Database::TrackArtistLinkType> _linkType;
	};
} // ns UserInterface

