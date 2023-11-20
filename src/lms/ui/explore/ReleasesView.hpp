

#pragma once

#include "services/database/Types.hpp"

#include "common/Template.hpp"
#include "ReleaseCollector.hpp"

namespace UserInterface
{
	class Filters;
	class InfiniteScrollingContainer;
	class PlayQueueController;

	class Releases : public Template
	{
		public:
			Releases(Filters& filters, PlayQueueController& playQueueController);

		private:
			void refreshView();
			void refreshView(ReleaseCollector::Mode mode);

			void addSome();
			std::vector<Database::ReleaseId> getAllReleases();

			static constexpr std::size_t _maxItemsPerLine {6};
			static constexpr std::size_t _batchSize {_maxItemsPerLine};
			static constexpr std::size_t _maxCount {_maxItemsPerLine * 500};

			PlayQueueController&		_playQueueController;
			Wt::WWidget*				_currentActiveItem {};
			InfiniteScrollingContainer* _container {};
			ReleaseCollector			_releaseCollector;
			static constexpr ReleaseCollector::Mode _defaultMode {ReleaseCollector::Mode::Random};
	};
} // namespace UserInterface

