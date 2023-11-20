

#pragma once

#include <Wt/WContainerWidget.h>
#include <Wt/WSignal.h>
#include <Wt/WWidget.h>

namespace UserInterface
{
	class ModalManager : public Wt::WContainerWidget
	{
		public:
			ModalManager();

			// should handle only one modal at a time
			// Widget must contain a "modal" element
			void show(std::unique_ptr<Wt::WWidget> modalWidget);
			void dispose(Wt::WWidget* modalWidget);

		private:
			Wt::JSignal<std::string> _closed;
	};
}
