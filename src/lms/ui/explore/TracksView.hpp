

#pragma once

#include "services/database/Types.hpp"

#include "common/Template.hpp"
#include "TrackCollector.hpp"

namespace UserInterface
{
	class Filters;
	class InfiniteScrollingContainer;
	class PlayQueueController;

	class Tracks : public Template
	{
		public:
			Tracks(Filters& filters, PlayQueueController& playQueueController);

		private:
			void refreshView();
			void refreshView(TrackCollector::Mode mode);
			void addSome();

			std::vector<Database::TrackId> getAllTracks();

			static constexpr TrackCollector::Mode _defaultMode {TrackCollector::Mode::Random};
			static constexpr std::size_t _batchSize {6};
			static constexpr std::size_t _maxCount {8000};

			Filters&					_filters;
			PlayQueueController&		_playQueueController;
			Wt::WWidget*				_currentActiveItem {};
			InfiniteScrollingContainer* _container {};
			TrackCollector				_trackCollector;
	};
} // namespace UserInterface

