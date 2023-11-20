

#pragma once

#include <Wt/WContainerWidget.h>

namespace UserInterface {

class UserView : public Wt::WContainerWidget
{
	public:
		UserView();

	private:
		void refreshView();
};

} // namespace UserInterface


