

#include "UUIDValidator.hpp"

#include <Wt/WRegExpValidator.h>

namespace UserInterface
{
	class RegExpValidator : public Wt::WRegExpValidator
	{
		public:
			using Wt::WRegExpValidator::WRegExpValidator;

		private:
			std::string javaScriptValidate() const override { return {}; }
	};

	std::unique_ptr<Wt::WValidator>
	createUUIDValidator()
	{
		return std::make_unique<RegExpValidator>("[a-fA-F0-9]{8}-[a-fA-F0-9]{4}-[a-fA-F0-9]{4}-[a-fA-F0-9]{4}-[a-fA-F0-9]{12}");
	}
} // namespace UserInterface
