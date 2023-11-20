

#pragma once

#include <optional>
#include <Wt/WTemplateFormView.h>

#include "services/database/UserId.hpp"

namespace UserInterface
{

	std::optional<Database::UserId>
	processAuthToken(const Wt::WEnvironment& env);

	class Auth : public Wt::WTemplateFormView
	{
		public:
			Auth();

			Wt::Signal<Database::UserId> userLoggedIn;
	};

} // namespace UserInterface
