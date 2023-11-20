

#pragma once

#include <optional>
#include <unordered_map>

#include <Wt/WComboBox.h>
#include <Wt/WTemplate.h>

#include "services/database/Types.hpp"
#include "ArtistCollector.hpp"

namespace UserInterface
{
	class Filters;
	class InfiniteScrollingContainer;

	class Artists : public Wt::WTemplate
	{
		public:
			Artists(Filters& filters);

		private:
			void refreshView();
			void refreshView(ArtistCollector::Mode mode);
			void refreshView(std::optional<Database::TrackArtistLinkType> linkType);
			void addSome();

			static constexpr std::size_t _batchSize {30};
			static constexpr std::size_t _maxCount {8000};

			Wt::WWidget*				_currentActiveItem {};
			InfiniteScrollingContainer* _container {};
			ArtistCollector				_artistCollector;
			Wt::WComboBox*				_linkType {};
			static constexpr ArtistCollector::Mode _defaultMode {ArtistCollector::Mode::Random};
	};
} // namespace UserInterface

