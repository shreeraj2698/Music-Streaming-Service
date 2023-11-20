

#pragma once

#include <Wt/WTemplate.h>
#include "PlayQueueController.hpp"

namespace UserInterface
{
	class Filters;
	class SearchView;
	class PlayQueue;

	class Explore : public Wt::WTemplate
	{
		public:
			Explore(Filters& filters, PlayQueue& playQueue);

			void search(const Wt::WString& searchText);
			PlayQueueController& getPlayQueueController() { return _playQueueController; }

		private:
			PlayQueueController _playQueueController;
			SearchView* _search {};
	};
} // namespace UserInterface

