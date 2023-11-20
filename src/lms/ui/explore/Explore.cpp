

#include "Explore.hpp"

#include <Wt/WApplication.h>
#include <Wt/WStackedWidget.h>

#include "ArtistsView.hpp"
#include "ArtistView.hpp"
#include "Filters.hpp"
#include "ReleasesView.hpp"
#include "ReleaseView.hpp"
#include "SearchView.hpp"
#include "TrackListView.hpp"
#include "TrackListsView.hpp"
#include "TracksView.hpp"

namespace UserInterface {

	namespace {

		void
		handleContentsPathChange(Wt::WStackedWidget* stack)
		{
			enum Idx
			{
				IdxArtists = 0,
				IdxArtist,
				IdxTrackLists,
				IdxTrackList,
				IdxReleases,
				IdxRelease,
				IdxSearch,
				IdxTracks,
			};

			static const std::map<std::string, int> indexes =
			{
				{ "/artists",		IdxArtists },
				{ "/artist",		IdxArtist },
				{ "/tracklists",	IdxTrackLists },
				{ "/tracklist",		IdxTrackList },
				{ "/releases",		IdxReleases },
				{ "/release",		IdxRelease },
				{ "/search",		IdxSearch },
				{ "/tracks",		IdxTracks },
			};

			for (const auto& index : indexes)
			{
				if (wApp->internalPathMatches(index.first))
				{
					stack->setCurrentIndex(index.second);
					return;
				}
			}
		}

	} // namespace

	Explore::Explore(Filters& filters, PlayQueue& playQueue)
		: Wt::WTemplate {Wt::WString::tr("Lms.Explore.template")}
	, _playQueueController {filters, playQueue}
	{
		addFunction("tr", &Functions::tr);

		// Contents
		Wt::WStackedWidget* contentsStack {bindNew<Wt::WStackedWidget>("contents")};
		contentsStack->setOverflow(Wt::Overflow::Visible); // wt makes it hidden by default

		// same order as enum Idx
		auto artists = std::make_unique<Artists>(filters);
		contentsStack->addWidget(std::move(artists));

		auto artist = std::make_unique<Artist>(filters, _playQueueController);
		contentsStack->addWidget(std::move(artist));

		auto trackLists {std::make_unique<TrackLists>(filters)};
		auto trackList {std::make_unique<TrackList>(filters, _playQueueController)};
		trackList->trackListDeleted.connect(trackLists.get(), &TrackLists::onTrackListDeleted);
		contentsStack->addWidget(std::move(trackLists));
		contentsStack->addWidget(std::move(trackList));

		auto releases = std::make_unique<Releases>(filters, _playQueueController);
		contentsStack->addWidget(std::move(releases));

		auto release = std::make_unique<Release>(filters, _playQueueController);
		contentsStack->addWidget(std::move(release));

		auto search = std::make_unique<SearchView>(filters, _playQueueController);
		_search = search.get();
		contentsStack->addWidget(std::move(search));

		auto tracks = std::make_unique<Tracks>(filters, _playQueueController);
		contentsStack->addWidget(std::move(tracks));

		wApp->internalPathChanged().connect(this, [=]
		{
			handleContentsPathChange(contentsStack);
		});

		handleContentsPathChange(contentsStack);
	}

	void
	Explore::search(const Wt::WString& searchText)
	{
		_search->refreshView(searchText);
	}

} // namespace UserInterface
