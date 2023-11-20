

#pragma once

#include <Wt/WContainerWidget.h>
#include <Wt/WTemplate.h>

namespace UserInterface {

class UsersView : public Wt::WTemplate
{
	public:
		UsersView();

	private:
		void refreshView();

		Wt::WContainerWidget* _container;
};

} // namespace UserInterface


