

#pragma once

#include <Wt/Auth/HashFunction.h>
#include <Wt/Auth/PasswordStrengthValidator.h>

#include "services/database/User.hpp"
#include "PasswordServiceBase.hpp"
#include "LoginThrottler.hpp"

namespace Auth
{
	class IAuthTokenService;

	class InternalPasswordService : public PasswordServiceBase
	{
		public:
			InternalPasswordService(Database::Db& db, std::size_t maxThrottlerEntries, IAuthTokenService& authTokenService);

		private:
			bool	checkUserPassword(std::string_view loginName, std::string_view password) override;

			bool	canSetPasswords() const override;
			PasswordAcceptabilityResult	checkPasswordAcceptability(std::string_view loginName, const PasswordValidationContext& context) const override;
			void	setPassword(Database::UserId userId, std::string_view newPassword) override;

			Database::User::PasswordHash	hashPassword(std::string_view password) const;
			void							hashRandomPassword() const;

			const Wt::Auth::BCryptHashFunction	_hashFunc {7}; // TODO parametrize this
			Wt::Auth::PasswordStrengthValidator	_validator;
	};

}
