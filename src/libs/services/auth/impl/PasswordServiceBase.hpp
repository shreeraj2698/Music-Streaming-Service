

#pragma once

#include <shared_mutex>

#include "services/auth/IPasswordService.hpp"
#include "AuthServiceBase.hpp"
#include "LoginThrottler.hpp"

namespace Database
{
	class Db;
	class Session;
}

namespace Auth
{

	class PasswordServiceBase : public IPasswordService, public AuthServiceBase
	{
		public:
			PasswordServiceBase(Database::Db& db, std::size_t maxThrottlerEntries, IAuthTokenService& authTokenService);

			PasswordServiceBase(const PasswordServiceBase&) = delete;
			PasswordServiceBase& operator=(const PasswordServiceBase&) = delete;
			PasswordServiceBase(PasswordServiceBase&&) = delete;
			PasswordServiceBase& operator=(PasswordServiceBase&&) = delete;

		protected:
			IAuthTokenService&	getAuthTokenService() { return _authTokenService; }

		private:
			virtual bool	checkUserPassword(std::string_view loginName, std::string_view password) = 0;

			CheckResult		checkUserPassword(const boost::asio::ip::address& clientAddress,
												std::string_view loginName,
												std::string_view password) override;

			std::shared_mutex			_mutex;
			LoginThrottler				_loginThrottler;
			IAuthTokenService&			_authTokenService;
	};

} // namespace Auth
