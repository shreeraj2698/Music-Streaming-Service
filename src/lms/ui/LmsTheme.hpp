

#pragma once

#include <Wt/WTheme.h>

namespace UserInterface
{
	class LmsTheme : public Wt::WTheme
	{
		private:
			void init(Wt::WApplication *app) const override;

			std::string name() const override;
			std::string resourcesUrl() const override;
			std::vector<Wt::WLinkedCssStyleSheet> styleSheets() const override;
			void apply(Wt::WWidget*, Wt::WWidget*, int) const override {};
			void apply(Wt::WWidget*, Wt::DomElement&, int) const override {};
			std::string disabledClass() const override { return "disabled"; }
			std::string activeClass() const override { return "active"; };
			std::string utilityCssClass(int) const override { return ""; };
			bool canStyleAnchorAsButton() const override { return true; };
			void applyValidationStyle(Wt::WWidget* widget,
					const Wt::WValidator::Result& validation,
					Wt::WFlags<Wt::ValidationStyleFlag> flags) const override;
			bool canBorderBoxElement(const Wt::DomElement&) const override { return true; }
	};
}
