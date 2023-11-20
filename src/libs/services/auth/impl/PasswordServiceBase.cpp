

#include "PasswordServiceBase.hpp"

#include <Wt/Auth/HashFunction.h>
#include <Wt/WRandom.h>

#include "internal/InternalPasswordService.hpp"
#ifdef LMS_SUPPORT_PAM
#include "pam/PAMPasswordService.hpp"
#endif // LMS_SUPPORT_PAM

#include "services/auth/Types.hpp"
#include "services/database/Session.hpp"
#include "services/database/User.hpp"
#include "utils/Exception.hpp"
#include "utils/Logger.hpp"

namespace Auth
{

	static const Wt::Auth::SHA1HashFunction sha1Function;

	std::unique_ptr<IPasswordService>
	createPasswordService(std::string_view passwordAuthenticationBackend, Database::Db& db, std::size_t maxThrottlerEntries, IAuthTokenService& authTokenService)
	{
		if (passwordAuthenticationBackend == "internal")
			return std::make_unique<InternalPasswordService>(db, maxThrottlerEntries, authTokenService);
#ifdef LMS_SUPPORT_PAM
		else if (passwordAuthenticationBackend == "pam")
			return std::make_unique<PAMPasswordService>(db, maxThrottlerEntries, authTokenService);
#endif // LMS_SUPPORT_PAM

		throw Exception {"Authentication backend '" + std::string {passwordAuthenticationBackend} + "' is not supported!"};
	}

	PasswordServiceBase::PasswordServiceBase(Database::Db& db, std::size_t maxThrottlerEntries, IAuthTokenService& authTokenService)
		: AuthServiceBase {db}
		, _loginThrottler {maxThrottlerEntries}
		, _authTokenService {authTokenService}
	{
	}

	PasswordServiceBase::CheckResult
	PasswordServiceBase::checkUserPassword(const boost::asio::ip::address& clientAddress, std::string_view loginName, std::string_view password)
	{
		LMS_LOG(AUTH, DEBUG) << "Checking password for user '" << loginName << "'";

		// Do not waste too much resource on brute force attacks (optim)
		{
			std::shared_lock lock {_mutex};

			if (_loginThrottler.isClientThrottled(clientAddress))
				return {CheckResult::State::Throttled};
		}

		const bool match {checkUserPassword(loginName, password)};
		{
			std::unique_lock lock {_mutex};

			if (_loginThrottler.isClientThrottled(clientAddress))
				return {CheckResult::State::Throttled};

			if (match)
			{
				_loginThrottler.onGoodClientAttempt(clientAddress);

				const Database::UserId userId {getOrCreateUser(loginName)};
				onUserAuthenticated(userId);
				return {CheckResult::State::Granted, userId};
			}
			else
			{
				_loginThrottler.onBadClientAttempt(clientAddress);
				return {CheckResult::State::Denied};
			}
		}
	}
} // namespace Auth

