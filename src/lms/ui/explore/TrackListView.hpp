

#pragma once

#include "services/database/TrackListId.hpp"
#include "services/database/Types.hpp"

#include "common/Template.hpp"

namespace UserInterface
{
	class Filters;
	class InfiniteScrollingContainer;
	class PlayQueueController;

	class TrackList : public Template
	{
		public:
			TrackList(Filters& filters, PlayQueueController& playQueueController);

			Wt::Signal<Database::TrackListId> trackListDeleted;

		private:
			void refreshView();
			void addSome();

			static constexpr std::size_t _batchSize {6};
			static constexpr std::size_t _maxCount {8000};

			Filters&					_filters;
			PlayQueueController&		_playQueueController;
			Database::TrackListId		_trackListId;
			InfiniteScrollingContainer* _container {};
	};
} // namespace UserInterface

