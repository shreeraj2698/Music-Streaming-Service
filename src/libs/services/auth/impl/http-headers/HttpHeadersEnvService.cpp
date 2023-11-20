

#include "HttpHeadersEnvService.hpp"

#include <Wt/WEnvironment.h>

#include "utils/IConfig.hpp"
#include "utils/Logger.hpp"
#include "utils/Service.hpp"

namespace Auth
{

	HttpHeadersEnvService::HttpHeadersEnvService(Database::Db& db)
		: AuthServiceBase {db}
		, _fieldName {Service<IConfig>::get()->getString("http-headers-login-field", "X-Forwarded-User")}
	{
		LMS_LOG(AUTH, INFO) << "Using http header field = '" << _fieldName << "'";
	}

	HttpHeadersEnvService::CheckResult
	HttpHeadersEnvService::processEnv(const Wt::WEnvironment& env)
	{
		const std::string loginName {env.headerValue(_fieldName)};
		if (loginName.empty())
			return {CheckResult::State::Denied};

		LMS_LOG(AUTH, DEBUG) << "Extracted login name = '" << loginName <<  "' from HTTP header";

		const Database::UserId userId {getOrCreateUser(loginName)};
		onUserAuthenticated(userId);
		return {CheckResult::State::Granted, userId};
	}

	HttpHeadersEnvService::CheckResult
	HttpHeadersEnvService::processRequest(const Wt::Http::Request& request)
	{
		const std::string loginName {request.headerValue(_fieldName)};
		if (loginName.empty())
			return {CheckResult::State::Denied};

		LMS_LOG(AUTH, DEBUG) << "Extracted login name = '" << loginName <<  "' from HTTP header";

		const Database::UserId userId {getOrCreateUser(loginName)};
		onUserAuthenticated(userId);
		return {CheckResult::State::Granted, userId};
	}

} // namespace Auth

