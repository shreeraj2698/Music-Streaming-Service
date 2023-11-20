

/* This file contains some classes in order to get info from file using the libavconv */

#pragma once

#include <optional>
#include <string>
#include <string_view>
#include <boost/asio/ip/address.hpp>
#include <Wt/WDateTime.h>

#include "services/database/UserId.hpp"

namespace Database
{
	class Db;
	class User;
}

namespace Auth
{
	class IAuthTokenService
	{
		public:
			virtual ~IAuthTokenService() = default;

			// Auth Token services
			struct AuthTokenProcessResult
			{
				enum class State
				{
					Granted,
					Throttled,
					Denied,
				};

				struct AuthTokenInfo
				{
					Database::UserId userId;
					Wt::WDateTime expiry;
				};

				State state {State::Denied};
				std::optional<AuthTokenInfo>	authTokenInfo {};
			};

			// Provided token is only accepted once
			virtual AuthTokenProcessResult	processAuthToken(const boost::asio::ip::address& clientAddress, std::string_view tokenValue) = 0;

			// Returns a one time token
			virtual std::string				createAuthToken(Database::UserId userid, const Wt::WDateTime& expiry) = 0;
			virtual void					clearAuthTokens(Database::UserId userid) = 0;
	};

	std::unique_ptr<IAuthTokenService> createAuthTokenService(Database::Db& db, std::size_t maxThrottlerEntryCount);
}
