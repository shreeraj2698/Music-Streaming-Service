

#pragma once

#include <functional>
#include <Wt/WValidator.h>

#include "services/auth/Types.hpp"

namespace UserInterface
{
	using PasswordValidationContextGetFunc = std::function<::Auth::PasswordValidationContext()>;
	std::unique_ptr<Wt::WValidator> createPasswordStrengthValidator(PasswordValidationContextGetFunc passwordValidationContextGetFunc);

	// Check current user password
	std::unique_ptr<Wt::WValidator> createPasswordCheckValidator();
} // namespace UserInterface

