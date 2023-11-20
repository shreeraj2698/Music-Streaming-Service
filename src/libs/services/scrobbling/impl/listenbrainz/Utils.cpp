

#include "Utils.hpp"

#include <Wt/Json/Object.h>
#include <Wt/Json/Parser.h>

#include "services/database/Session.hpp"
#include "services/database/User.hpp"

namespace Scrobbling::ListenBrainz::Utils
{
	std::optional<UUID>
	getListenBrainzToken(Database::Session& session, Database::UserId userId)
	{
		auto transaction {session.createSharedTransaction()};

		const Database::User::pointer user {Database::User::find(session, userId)};
		if (!user)
			return std::nullopt;

		return user->getListenBrainzToken();
	}

	std::string
	parseValidateToken(std::string_view msgBody)
	{
		std::string listenBrainzUserName;

		Wt::Json::ParseError error;
		Wt::Json::Object root;
		if (!Wt::Json::parse(std::string {msgBody}, root, error))
		{
			LOG(ERROR) << "Cannot parse 'validate-token' result: " << error.what();
			return listenBrainzUserName;
		}

		if (!root.get("valid").orIfNull(false))
		{
			LOG(INFO) << "Invalid listenbrainz user";
			return listenBrainzUserName;
		}

		listenBrainzUserName = root.get("user_name").orIfNull("");
		return listenBrainzUserName;
	}
}
