

#include "ArtistsView.hpp"

#include <Wt/WPushButton.h>

#include "services/database/Artist.hpp"
#include "services/database/Session.hpp"
#include "services/database/TrackArtistLink.hpp"
#include "utils/Logger.hpp"

#include "common/InfiniteScrollingContainer.hpp"
#include "ArtistListHelpers.hpp"
#include "Filters.hpp"
#include "LmsApplication.hpp"

using namespace Database;

namespace UserInterface {

Artists::Artists(Filters& filters)
: Wt::WTemplate {Wt::WString::tr("Lms.Explore.Artists.template")}
, _artistCollector {filters, _defaultMode, _maxCount}
{
	addFunction("tr", &Wt::WTemplate::Functions::tr);

	auto bindMenuItem {[this](const std::string& var, const Wt::WString& title, ArtistCollector::Mode mode)
	{
		auto *menuItem {bindNew<Wt::WPushButton>(var, title)};
		menuItem->clicked().connect([=]
		{
			refreshView(mode);
			_currentActiveItem->removeStyleClass("active");
			menuItem->addStyleClass("active");
			_currentActiveItem = menuItem;
		});

		if (mode == _defaultMode)
		{
			_currentActiveItem = menuItem;
			_currentActiveItem->addStyleClass("active");
		}
	}};

	bindMenuItem("random", Wt::WString::tr("Lms.Explore.random"), ArtistCollector::Mode::Random);
	bindMenuItem("starred", Wt::WString::tr("Lms.Explore.starred"), ArtistCollector::Mode::Starred);
	bindMenuItem("recently-played", Wt::WString::tr("Lms.Explore.recently-played"), ArtistCollector::Mode::RecentlyPlayed);
	bindMenuItem("most-played", Wt::WString::tr("Lms.Explore.most-played"), ArtistCollector::Mode::MostPlayed);
	bindMenuItem("recently-added", Wt::WString::tr("Lms.Explore.recently-added"), ArtistCollector::Mode::RecentlyAdded);
	bindMenuItem("all", Wt::WString::tr("Lms.Explore.all"), ArtistCollector::Mode::All);

	_linkType = bindNew<Wt::WComboBox>("link-type");
	_linkType->setModel(ArtistListHelpers::createArtistLinkTypesModel());
	_linkType->changed().connect([this]
	{
		const std::optional<TrackArtistLinkType> linkType {static_cast<ArtistLinkTypesModel*>(_linkType->model().get())->getValue(_linkType->currentIndex())};
		refreshView(linkType);
	});

	LmsApp->getScannerEvents().scanComplete.connect(this, [this](const Scanner::ScanStats& stats)
	{
		if (stats.nbChanges())
			_linkType->setModel(ArtistListHelpers::createArtistLinkTypesModel());
	});

	_container = bindNew<InfiniteScrollingContainer>("artists", Wt::WString::tr("Lms.Explore.Artists.template.container"));
	_container->onRequestElements.connect([this]
	{
		addSome();
	});

	filters.updated().connect([this]
	{
		refreshView();
	});

	refreshView(_artistCollector.getMode());
}

void
Artists::refreshView()
{
	_container->reset();
	_artistCollector.reset();
}

void
Artists::refreshView(ArtistCollector::Mode mode)
{
	_artistCollector.setMode(mode);
	refreshView();
}

void
Artists::refreshView(std::optional<TrackArtistLinkType> linkType)
{
	_artistCollector.setArtistLinkType(linkType);
	refreshView();
}

void
Artists::addSome()
{
	const auto artistIds {_artistCollector.get(Range {static_cast<std::size_t>(_container->getCount()), _batchSize})};

	{
		auto transaction {LmsApp->getDbSession().createSharedTransaction()};

		for (const ArtistId artistId : artistIds.results)
		{
			if (const auto artist {Artist::find(LmsApp->getDbSession(), artistId)})
				_container->add(ArtistListHelpers::createEntry(artist));
		}
	}
}

} // namespace UserInterface

