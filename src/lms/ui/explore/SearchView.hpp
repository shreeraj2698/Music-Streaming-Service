

#pragma once

#include <optional>
#include <unordered_map>

#include <Wt/WComboBox.h>
#include <Wt/WStackedWidget.h>
#include <Wt/WTemplate.h>

#include "services/database/Types.hpp"
#include "ArtistCollector.hpp"
#include "ReleaseCollector.hpp"
#include "TrackCollector.hpp"

namespace UserInterface
{
	class InfiniteScrollingContainer;
	class Filters;
	class PlayQueueController;

	class SearchView : public Wt::WTemplate
	{
		public:
			SearchView(Filters& filters, PlayQueueController& playQueueController);

			void refreshView(const Wt::WString& searchText);

		private:
			// same order as in the menu
			enum class Mode
			{
				Artist,
				Release,
				Track,
			};

			static constexpr Mode _defaultMode {Mode::Release};
			static inline std::unordered_map<Mode, std::size_t> _batchSizes
			{
				{Mode::Artist, 6},
				{Mode::Release, 6},
				{Mode::Track, 6},
			};
			static inline std::unordered_map<Mode, std::size_t> _maxCounts
			{
				{Mode::Artist, 8000},
				{Mode::Release, 4000},
				{Mode::Track, 4000},
			};
			std::size_t getBatchSize(Mode mode) const;
			std::size_t getMaxCount(Mode mode) const;

			void refreshView();
			void refreshView(std::optional<Database::TrackArtistLinkType> linkType);
			void addSomeArtists();
			void addSomeReleases();
			void addSomeTracks();

			PlayQueueController&	_playQueueController;
			Filters&			_filters;
			ArtistCollector		_artistCollector;
			ReleaseCollector	_releaseCollector;
			TrackCollector		_trackCollector;

			InfiniteScrollingContainer* _artists {};
			InfiniteScrollingContainer* _releases {};
			InfiniteScrollingContainer* _tracks {};

			Wt::WComboBox* _artistLinkType {};

			std::vector<InfiniteScrollingContainer*> _results;
	};

} // namespace UserInterface

