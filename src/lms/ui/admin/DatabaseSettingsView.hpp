

#pragma once

#include <Wt/WContainerWidget.h>

namespace UserInterface {

class DatabaseSettingsView : public Wt::WContainerWidget
{
	public:
		DatabaseSettingsView();

	private:
		void refreshView();
};


} // namespace UserInterface

