

#pragma once

#include <Wt/WTemplate.h>

namespace UserInterface
{

	class Template : public Wt::WTemplate
	{
		public:
			using Wt::WTemplate::WTemplate;

		private:
			void applyArguments(Wt::WWidget* w, const std::vector<Wt::WString>& args) override;
	};

} // namespace UserInterface
