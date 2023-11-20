

#pragma once

#include "utils/UUID.hpp"

#include "services/database/UserId.hpp"
#include "utils/Logger.hpp"

#define LOG(sev)	LMS_LOG(SCROBBLING, sev) << "[listenbrainz] - "

namespace Database
{
	class Session;
}

namespace Scrobbling::ListenBrainz::Utils
{
	std::optional<UUID>	getListenBrainzToken(Database::Session& session, Database::UserId userId);

	std::string parseValidateToken(std::string_view msgBody);
}
