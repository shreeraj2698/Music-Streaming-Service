

#pragma once

#include <optional>

#include "ScannerEvents.hpp"
#include "ScannerStats.hpp"

namespace Database
{
	class Db;
}

namespace Recommendation
{
	class IRecommendationService;
}

namespace Scanner
{

	class IScannerService
	{
		public:
			virtual ~IScannerService() = default;

			// Async requests
			virtual void requestReload() = 0;
			virtual void requestImmediateScan(bool force) = 0;

			enum class State
			{
				NotScheduled,
				Scheduled,
				InProgress,
			};

			struct Status
			{
				State								currentState {State::NotScheduled};
				Wt::WDateTime						nextScheduledScan;
				std::optional<ScanStats>			lastCompleteScanStats;
				std::optional<ScanStepStats> 		currentScanStepStats;
			};

			virtual Status getStatus() const = 0;

			virtual Events& getEvents() = 0;
	};

	std::unique_ptr<IScannerService> createScannerService(Database::Db& db, Recommendation::IRecommendationService& recommendationEngine);

} // Scanner

