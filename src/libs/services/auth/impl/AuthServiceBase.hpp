

#pragma once

#include <string_view>
#include "services/database/UserId.hpp"

namespace Database
{
	class Db;
	class Session;
}

namespace Auth
{
	class AuthServiceBase
	{
		protected:
			AuthServiceBase(Database::Db& db);

			Database::UserId	getOrCreateUser(std::string_view loginName);
			void				onUserAuthenticated(Database::UserId userId);

			Database::Session&		getDbSession();

		private:
			Database::Db&		_db;
	};
}
