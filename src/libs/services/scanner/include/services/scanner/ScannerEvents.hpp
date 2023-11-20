

#pragma once

#include <Wt/WDateTime.h>
#include <Wt/WSignal.h>

#include "ScannerStats.hpp"

namespace Scanner
{

	struct Events
	{
		// Called just after scan start
		Wt::Signal<> 				scanStarted;

		// Called just after scan complete (true if changes have been made)
		Wt::Signal<ScanStats>		scanComplete;

		// Called during scan in progress
		Wt::Signal<ScanStepStats>	scanInProgress;

		// Called after a schedule
		Wt::Signal<Wt::WDateTime>	scanScheduled;
	};

} // ns Scanner

