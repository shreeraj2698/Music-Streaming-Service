

#include "LoginNameValidator.hpp"

#include <Wt/WLengthValidator.h>
#include "services/database/User.hpp"

namespace UserInterface
{
	class LengthValidator : public Wt::WLengthValidator
	{
		private:
			std::string javaScriptValidate() const override { return {}; }
	};

	std::unique_ptr<Wt::WValidator>
	createLoginNameValidator()
	{
		auto v = std::make_unique<LengthValidator>();
		v->setMandatory(true);
		v->setMinimumLength(::Database::User::MinNameLength);
		v->setMaximumLength(::Database::User::MaxNameLength);
		return v;
	}
} // namespace UserInterface
