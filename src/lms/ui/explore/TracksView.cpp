

#include "TracksView.hpp"

#include <Wt/WPushButton.h>

#include "services/database/Session.hpp"
#include "services/database/Track.hpp"
#include "utils/Logger.hpp"

#include "common/InfiniteScrollingContainer.hpp"
#include "explore/Filters.hpp"
#include "explore/PlayQueueController.hpp"
#include "explore/TrackListHelpers.hpp"
#include "LmsApplication.hpp"

using namespace Database;

namespace UserInterface {

Tracks::Tracks(Filters& filters, PlayQueueController& playQueueController)
: Template {Wt::WString::tr("Lms.Explore.Tracks.template")}
, _filters {filters}
, _playQueueController {playQueueController}
, _trackCollector {filters, _defaultMode, _maxCount}
{
	addFunction("tr", &Wt::WTemplate::Functions::tr);
	addFunction("id", &Wt::WTemplate::Functions::id);

	auto bindMenuItem {[this](const std::string& var, const Wt::WString& title, TrackCollector::Mode mode)
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

	bindMenuItem("random", Wt::WString::tr("Lms.Explore.random"), TrackCollector::Mode::Random);
	bindMenuItem("starred", Wt::WString::tr("Lms.Explore.starred"), TrackCollector::Mode::Starred);
	bindMenuItem("recently-played", Wt::WString::tr("Lms.Explore.recently-played"), TrackCollector::Mode::RecentlyPlayed);
	bindMenuItem("most-played", Wt::WString::tr("Lms.Explore.most-played"), TrackCollector::Mode::MostPlayed);
	bindMenuItem("recently-added", Wt::WString::tr("Lms.Explore.recently-added"), TrackCollector::Mode::RecentlyAdded);
	bindMenuItem("all", Wt::WString::tr("Lms.Explore.all"), TrackCollector::Mode::All);

	bindNew<Wt::WPushButton>("play-btn", Wt::WString::tr("Lms.Explore.play"), Wt::TextFormat::XHTML)
		->clicked().connect([=]
		{
			_playQueueController.processCommand(PlayQueueController::Command::Play, getAllTracks());
		});

	bindNew<Wt::WPushButton>("play-shuffled", Wt::WString::tr("Lms.Explore.play-shuffled"), Wt::TextFormat::Plain)
		->clicked().connect([=]
		{
			_playQueueController.processCommand(PlayQueueController::Command::PlayShuffled, getAllTracks());
		});
	bindNew<Wt::WPushButton>("play-next", Wt::WString::tr("Lms.Explore.play-next"), Wt::TextFormat::Plain)
		->clicked().connect([=]
		{
			_playQueueController.processCommand(PlayQueueController::Command::PlayNext, getAllTracks());
		});
	bindNew<Wt::WPushButton>("play-last", Wt::WString::tr("Lms.Explore.play-last"), Wt::TextFormat::Plain)
		->clicked().connect([=]
		{
			_playQueueController.processCommand(PlayQueueController::Command::PlayOrAddLast, getAllTracks());
		});

	_container = bindNew<InfiniteScrollingContainer>("tracks", Wt::WString::tr("Lms.Explore.Tracks.template.entry-container"));
	_container->onRequestElements.connect([this]
	{
		addSome();
	});

	filters.updated().connect([this]
	{
		refreshView();
	});

	refreshView(_trackCollector.getMode());
}

void
Tracks::refreshView()
{
	_container->reset();
	_trackCollector.reset();
}

void
Tracks::refreshView(TrackCollector::Mode mode)
{
	_trackCollector.setMode(mode);
	refreshView();
}

void
Tracks::addSome()
{
	auto transaction {LmsApp->getDbSession().createSharedTransaction()};

	const auto trackIds {_trackCollector.get(Range {static_cast<std::size_t>(_container->getCount()), _batchSize})};

	for (const TrackId trackId : trackIds.results)
	{
		if (const Track::pointer track {Track::find(LmsApp->getDbSession(), trackId)})
			_container->add(TrackListHelpers::createEntry(track, _playQueueController, _filters));
	}
}

std::vector<Database::TrackId>
Tracks::getAllTracks()
{
	RangeResults<TrackId> trackIds {_trackCollector.get(Range {})};

	return std::move(trackIds.results);
}


} // namespace UserInterface

