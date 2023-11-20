

#include "services/database/AuthToken.hpp"

#include <Wt/Dbo/WtSqlTraits.h>
#include "services/database/Session.hpp"
#include "services/database/User.hpp"
#include "StringViewTraits.hpp"
#include "IdTypeTraits.hpp"

namespace Database
{

	AuthToken::AuthToken(std::string_view value, const Wt::WDateTime& expiry, ObjectPtr<User> user)
	: _value {value}
	, _expiry {expiry}
	, _user {getDboPtr(user)}
	{
	}

	AuthToken::pointer
	AuthToken::create(Session& session, std::string_view value, const Wt::WDateTime& expiry, ObjectPtr<User> user)
	{
		return session.getDboSession().add(std::unique_ptr<AuthToken> {new AuthToken {value, expiry, user}});
	}

	void
	AuthToken::removeExpiredTokens(Session& session, const Wt::WDateTime& now)
	{
		session.checkUniqueLocked();

		session.getDboSession().execute("DELETE FROM auth_token WHERE expiry < ?").bind(now);
	}

	AuthToken::pointer
	AuthToken::find(Session& session, std::string_view value)
	{
		session.checkSharedLocked();

		return session.getDboSession().find<AuthToken>()
			.where("value = ?").bind(value)
			.resultValue();
	}
}
