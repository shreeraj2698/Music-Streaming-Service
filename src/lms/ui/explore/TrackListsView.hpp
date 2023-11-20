

#pragma once

#include <unordered_map>
#include <Wt/WTemplate.h>

#include "services/database/Object.hpp"
#include "services/database/TrackListId.hpp"
#include "services/database/Types.hpp"

#include "common/Template.hpp"

namespace Database
{
	class TrackList;
}

namespace UserInterface
{
	class Filters;
	class InfiniteScrollingContainer;

	class TrackLists : public Template
	{
		public:
			TrackLists(Filters& filters);

			void onTrackListDeleted(Database::TrackListId trackListId);

		private:
			enum class Mode
			{
				RecentlyModified,
				All,
			};

			void refreshView();
			void addSome();
			void addTracklist(const Database::ObjectPtr<Database::TrackList>& trackList);

			static constexpr std::size_t _batchSize {30};
			static constexpr std::size_t _maxCount {500};

			Mode						_mode {Mode::RecentlyModified};
			Filters&					_filters;
			Wt::WWidget*				_currentActiveItem {};
			InfiniteScrollingContainer* _container {};
			std::unordered_map<Database::TrackListId, Wt::WWidget*> _trackListWidgets;
	};
} // namespace UserInterface

