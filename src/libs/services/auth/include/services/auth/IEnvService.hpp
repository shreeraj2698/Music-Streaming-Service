

#pragma once

#include <optional>
#include <string>

#include "services/database/UserId.hpp"

namespace Database
{
	class Db;
	class Session;
}

namespace Wt
{
	class WEnvironment;
}

namespace Wt::Http
{
	class Request;
}

namespace Auth
{
	class IEnvService
	{
		public:
			virtual ~IEnvService() = default;

			// Auth Token services
			struct CheckResult
			{
				enum class State
				{
					Granted,
					Denied,
					Throttled,
				};

				State state {State::Denied};
				std::optional<Database::UserId>	userId {};
			};

			virtual CheckResult			processEnv(const Wt::WEnvironment& env) = 0;
			virtual CheckResult			processRequest(const Wt::Http::Request& request) = 0;
	};

	std::unique_ptr<IEnvService> createEnvService(std::string_view backendName, Database::Db& db);
} // namespace Auth
