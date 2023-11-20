

#pragma once

#include <shared_mutex>

#include "services/auth/IAuthTokenService.hpp"
#include "AuthServiceBase.hpp"
#include "LoginThrottler.hpp"

namespace Database
{
	class Session;
}

namespace Auth
{
	class AuthTokenService : public IAuthTokenService, public AuthServiceBase
	{
		public:
			AuthTokenService(Database::Db& db, std::size_t maxThrottlerEntries);

			AuthTokenService(const AuthTokenService&) = delete;
			AuthTokenService& operator=(const AuthTokenService&) = delete;
			AuthTokenService(AuthTokenService&&) = delete;
			AuthTokenService& operator=(AuthTokenService&&) = delete;

		private:
			AuthTokenProcessResult	processAuthToken(const boost::asio::ip::address& clientAddress, std::string_view tokenValue) override;
			std::string				createAuthToken(Database::UserId userId, const Wt::WDateTime& expiry) override;
			void					clearAuthTokens(Database::UserId userId) override;

			std::optional<AuthTokenService::AuthTokenProcessResult::AuthTokenInfo> processAuthToken(std::string_view secret);

			std::shared_mutex	_mutex;
			LoginThrottler		_loginThrottler;
	};
}
