

#include "AuthServiceBase.hpp"

#include "services/database/Db.hpp"
#include "services/database/Session.hpp"
#include "services/database/User.hpp"
#include "utils/Logger.hpp"

namespace Auth
{
	using namespace Database;

	AuthServiceBase::AuthServiceBase(Db& db)
	: _db {db}
	{}

	UserId
	AuthServiceBase::getOrCreateUser(std::string_view loginName)
	{
		Session& session {getDbSession()};
		auto transaction {session.createUniqueTransaction()};

		User::pointer user {User::find(session, loginName)};
		if (!user)
		{
			const UserType type {User::getCount(session) == 0 ? UserType::ADMIN : UserType::REGULAR};

			LMS_LOG(AUTH, DEBUG) << "Creating user '" << loginName << "', admin = " << (type == UserType::ADMIN);

			user = session.create<User>(loginName);
			user.modify()->setType(type);
		}

		return user->getId();
	}

	void
	AuthServiceBase::onUserAuthenticated(UserId userId)
	{
		Session& session {getDbSession()};
		auto transaction {session.createUniqueTransaction()};

		User::pointer user {User::find(session, userId)};
		if (user)
			user.modify()->setLastLogin(Wt::WDateTime::currentDateTime());
	}

	Session&
	AuthServiceBase::getDbSession()
	{
		return _db.getTLSSession();
	}
}
