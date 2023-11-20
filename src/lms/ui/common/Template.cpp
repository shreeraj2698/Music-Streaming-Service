

#include "Template.hpp"
#include "utils/String.hpp"

namespace UserInterface
{
	void
	Template::applyArguments(WWidget* widget, const std::vector<Wt::WString>& args)
	{
		for (const Wt::WString& arg : args)
		{
			const std::vector<std::string> operands {StringUtils::splitStringCopy(arg.toUTF8(), "=")};

			if (operands.size() == 2)
			{
				if (operands[0] == "class")
					widget->addStyleClass(operands[1]);
				else
					widget->setAttributeValue(operands[0], operands[1]);
			}
		}
	}
} // namespace UserInterface
