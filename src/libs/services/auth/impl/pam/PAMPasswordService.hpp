

#pragma once

#include <shared_mutex>

#include "PasswordServiceBase.hpp"

namespace Auth
{
	class PAMPasswordService: public PasswordServiceBase
	{
		public:
			using PasswordServiceBase::PasswordServiceBase;

		private:
			bool	checkUserPassword(std::string_view loginName,std::string_view password) override;
			bool	canSetPasswords() const override;
			PasswordAcceptabilityResult	checkPasswordAcceptability(std::string_view loginName, const PasswordValidationContext& context) const override;
			void	setPassword(Database::UserId userId, std::string_view newPassword) override;
	};
}
