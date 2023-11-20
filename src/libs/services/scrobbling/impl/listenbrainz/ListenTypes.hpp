

#pragma once

#include <string>
#include <ostream>
#include <Wt/WDateTime.h>

#include "utils/UUID.hpp"

namespace Scrobbling::ListenBrainz
{
	struct Listen
	{
		std::string trackName;
		std::string releaseName;
		std::string artistName;
		std::optional<UUID> recordingMBID;
		std::optional<UUID> trackMBID;
		std::optional<UUID> releaseMBID;
		std::optional<unsigned> trackNumber;
		Wt::WDateTime listenedAt;
	};

	std::ostream& operator<<(std::ostream& os, const Listen& listen);
} // Scrobbling::ListenBrainz
