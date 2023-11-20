

#pragma once

#include "services/auth/IEnvService.hpp"
#include "AuthServiceBase.hpp"

namespace Auth
{
	class HttpHeadersEnvService : public IEnvService, public AuthServiceBase
	{
		public:
			HttpHeadersEnvService(Database::Db& db);

		private:
			CheckResult	processEnv(const Wt::WEnvironment& env) override;
			CheckResult	processRequest(const Wt::Http::Request& request) override;

			std::string _fieldName;
	};

} // namespace Auth

