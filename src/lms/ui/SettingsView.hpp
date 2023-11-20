

#pragma once

#include <Wt/WContainerWidget.h>

namespace UserInterface {

class SettingsView : public Wt::WContainerWidget
{
	public:
		SettingsView();

	private:
		void refreshView();
};

} // namespace UserInterface

