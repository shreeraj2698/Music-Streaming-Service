

#pragma once

#include <memory>

#include <Wt/WWidget.h>
#include "services/database/Object.hpp"
#include "services/database/TrackId.hpp"

namespace Database
{
	class Track;
}

namespace UserInterface
{
	class PlayQueueController;
	class Filters;
}

namespace UserInterface::TrackListHelpers
{
	void showTrackInfoModal(Database::TrackId trackId, Filters& filters);
	std::unique_ptr<Wt::WWidget> createEntry(const Database::ObjectPtr<Database::Track>& track, PlayQueueController& playQueueController, Filters& filters);
} // namespace UserInterface

