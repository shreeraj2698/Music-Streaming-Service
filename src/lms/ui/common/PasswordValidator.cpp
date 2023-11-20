

#include "PasswordValidator.hpp"

#include <Wt/WEnvironment.h>

#include "services/auth/IPasswordService.hpp"
#include "utils/Service.hpp"
#include "LmsApplication.hpp"

namespace UserInterface
{
	class PasswordStrengthValidator : public Wt::WValidator
	{
		public:
			PasswordStrengthValidator(PasswordValidationContextGetFunc passwordValidationContextGetFunc)
				: _passwordValidationContextGetFunc {std::move(passwordValidationContextGetFunc)}
			{}

		private:
			Wt::WValidator::Result validate(const Wt::WString& input) const override;
			std::string javaScriptValidate() const override { return {}; }

			PasswordValidationContextGetFunc _passwordValidationContextGetFunc;
	};

	Wt::WValidator::Result
	PasswordStrengthValidator::validate(const Wt::WString& input) const
	{
		if (input.empty())
			return Wt::WValidator::validate(input);

		const ::Auth::PasswordValidationContext context {_passwordValidationContextGetFunc()};

		switch (Service<::Auth::IPasswordService>::get()->checkPasswordAcceptability(input.toUTF8(), context))
		{
			case ::Auth::IPasswordService::PasswordAcceptabilityResult::OK:
				return Wt::WValidator::Result {Wt::ValidationState::Valid};
			case ::Auth::IPasswordService::PasswordAcceptabilityResult::TooWeak:
				return Wt::WValidator::Result {Wt::ValidationState::Invalid, Wt::WString::tr("Lms.password-too-weak")};
			case ::Auth::IPasswordService::PasswordAcceptabilityResult::MustMatchLoginName:
				return Wt::WValidator::Result {Wt::ValidationState::Invalid, Wt::WString::tr("Lms.password-must-match-login")};
		}

		throw LmsException {"internal error"};
	}

	std::unique_ptr<Wt::WValidator>
	createPasswordStrengthValidator(PasswordValidationContextGetFunc passwordValidationContextGetFunc)
	{
		return std::make_unique<PasswordStrengthValidator>(std::move(passwordValidationContextGetFunc));
	}

	class PasswordCheckValidator : public Wt::WValidator
	{
		private:
			Wt::WValidator::Result validate(const Wt::WString& input) const override;
			std::string javaScriptValidate() const override { return {}; }
	};

	Wt::WValidator::Result
	PasswordCheckValidator::validate(const Wt::WString& input) const
	{
		if (input.empty())
			return Wt::WValidator::validate(input);

		const auto checkResult {Service<::Auth::IPasswordService>::get()->checkUserPassword(
					boost::asio::ip::address::from_string(LmsApp->environment().clientAddress()),
					LmsApp->getUserLoginName(),
					input.toUTF8())};
		switch (checkResult.state)
		{
			case ::Auth::IPasswordService::CheckResult::State::Granted:
				return Wt::WValidator::Result {Wt::ValidationState::Valid};
			case ::Auth::IPasswordService::CheckResult::State::Denied:
				return Wt::WValidator::Result {Wt::ValidationState::Invalid, Wt::WString::tr("Lms.Settings.password-bad")};
			case ::Auth::IPasswordService::CheckResult::State::Throttled:
				return Wt::WValidator::Result {Wt::ValidationState::Invalid, Wt::WString::tr("Lms.password-client-throttled")};
		}

		throw LmsException {"InternalError"};
	}

	std::unique_ptr<Wt::WValidator>
	createPasswordCheckValidator()
	{
		return std::make_unique<PasswordCheckValidator>();
	}

} // namespace UserInterface

