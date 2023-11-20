

#pragma once

#include <Wt/WPushButton.h>
#include <Wt/WTemplate.h>
#include <Wt/WLineEdit.h>

namespace UserInterface
{

	class ScannerController : public Wt::WTemplate
	{
		public:
			ScannerController();

		private:
			void refreshContents();

			Wt::WPushButton*	_reportBtn;
			Wt::WLineEdit*		_lastScanStatus;
			Wt::WLineEdit*		_status;
			Wt::WLineEdit*		_stepStatus;
			class ReportResource* _reportResource;
	};

} // namespace DatabaseStatus

