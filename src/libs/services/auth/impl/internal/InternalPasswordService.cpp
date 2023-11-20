

#include "InternalPasswordService.hpp"
#include <Wt/WRandom.h>

#include "services/auth/IAuthTokenService.hpp"
#include "services/auth/Types.hpp"
#include "services/database/Session.hpp"
#include "services/database/User.hpp"
#include "utils/Exception.hpp"
#include "utils/Logger.hpp"

namespace Auth
{
	InternalPasswordService::InternalPasswordService(Database::Db& db, std::size_t maxThrottlerEntries, IAuthTokenService& authTokenService)
		: PasswordServiceBase {db, maxThrottlerEntries, authTokenService}
	{
		_validator.setMinimumLength(Wt::Auth::PasswordStrengthType::OneCharClass, 4);
		_validator.setMinimumLength(Wt::Auth::PasswordStrengthType::TwoCharClass, 4);
		_validator.setMinimumLength(Wt::Auth::PasswordStrengthType::PassPhrase, 4);
		_validator.setMinimumLength(Wt::Auth::PasswordStrengthType::ThreeCharClass, 4);
		_validator.setMinimumLength(Wt::Auth::PasswordStrengthType::FourCharClass, 4);
		_validator.setMinimumPassPhraseWords(1);
		_validator.setMinimumMatchLength(3);
	}

	bool
	InternalPasswordService::checkUserPassword(std::string_view loginName, std::string_view password)
	{
		LMS_LOG(AUTH, DEBUG) << "Checking internal password for user '" << loginName << "'";

		Database::User::PasswordHash passwordHash;
		{
			Database::Session& session {getDbSession()};
			auto transaction {session.createSharedTransaction()};

			const Database::User::pointer user {Database::User::find(session, loginName)};
			if (!user)
			{
				LMS_LOG(AUTH, DEBUG) << "hashing random stuff";
				// hash random stuff here to waste some time
				hashRandomPassword();
				return false;
			}

			// Don't allow users being created or coming from other backends
			passwordHash = user->getPasswordHash();
			if (passwordHash.salt.empty() || passwordHash.hash.empty())
			{
				// hash random stuff here to waste some time
				hashRandomPassword();
				return false;
			}
		}

		return _hashFunc.verify(std::string {password}, std::string {passwordHash.salt}, std::string {passwordHash.hash});
	}

	bool
	InternalPasswordService::canSetPasswords() const
	{
		return true;
	}

	IPasswordService::PasswordAcceptabilityResult
	InternalPasswordService::checkPasswordAcceptability(std::string_view password, const PasswordValidationContext& context) const
	{
		switch (context.userType)
		{
			case Database::UserType::ADMIN:
			case Database::UserType::REGULAR:
				return _validator.evaluateStrength(std::string {password}, context.loginName, "").isValid() ? PasswordAcceptabilityResult::OK : PasswordAcceptabilityResult::TooWeak;
			case Database::UserType::DEMO:
				return password == context.loginName ? PasswordAcceptabilityResult::OK : PasswordAcceptabilityResult::MustMatchLoginName;
		}

		throw NotImplementedException {};
	}

	void
	InternalPasswordService::setPassword(Database::UserId userId, std::string_view newPassword)
	{
		const Database::User::PasswordHash passwordHash {hashPassword(newPassword)};

		Database::Session& session {getDbSession()};
		auto transaction {session.createUniqueTransaction()};

		Database::User::pointer user {Database::User::find(session, userId)};
		if (!user)
			throw Exception {"User not found!"};

		switch (checkPasswordAcceptability(newPassword, PasswordValidationContext {user->getLoginName(), user->getType()}))
		{
			case PasswordAcceptabilityResult::OK:
				break;
			case PasswordAcceptabilityResult::TooWeak:
				throw PasswordTooWeakException {};
			case PasswordAcceptabilityResult::MustMatchLoginName:
				throw PasswordMustMatchLoginNameException {};
		}

		user.modify()->setPasswordHash(passwordHash);
		getAuthTokenService().clearAuthTokens(userId);
	}

	Database::User::PasswordHash
	InternalPasswordService::hashPassword(std::string_view password) const
	{
		const std::string salt {Wt::WRandom::generateId(32)};

		return {salt, _hashFunc.compute(std::string {password}, salt)};
	}

	void
	InternalPasswordService::hashRandomPassword() const
	{
		hashPassword(Wt::WRandom::generateId(32));
	}

} // namespace Auth

