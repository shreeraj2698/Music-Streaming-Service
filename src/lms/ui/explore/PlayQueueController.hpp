

#pragma once

#include <vector>

#include "services/database/ArtistId.hpp"
#include "services/database/ReleaseId.hpp"
#include "services/database/TrackId.hpp"
#include "services/database/TrackListId.hpp"

namespace UserInterface
{
	class Filters;
	class PlayQueue;

	// Used to interact with the play queue, using the current exploration filters
	class PlayQueueController
	{
		public:
			PlayQueueController(Filters& filters, PlayQueue& playQueue);

			enum class Command
			{
				Play,
				PlayNext,
				PlayOrAddLast,
				PlayShuffled,
			};

			void processCommand(Command command, const std::vector<Database::ArtistId>&);
			void processCommand(Command command, const std::vector<Database::ReleaseId>&);
			void processCommand(Command command, const std::vector<Database::TrackId>&);
			void processCommand(Command command, Database::TrackListId);
			void playTrackInRelease(Database::TrackId);

			void setMaxTrackCountToEnqueue(std::size_t maxTrackCount) { _maxTrackCountToEnqueue = maxTrackCount; }

		private:
			Filters& _filters;
			PlayQueue& _playQueue;
			std::size_t _maxTrackCountToEnqueue {};
	};
}

