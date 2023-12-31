

#pragma once

#include <chrono>
#include <shared_mutex>
#include <optional>
#include <vector>

#include <Wt/WDateTime.h>
#include <Wt/WIOService.h>
#include <Wt/WSignal.h>

#include <boost/asio/system_timer.hpp>

#include "services/database/Db.hpp"
#include "services/database/Session.hpp"
#include "services/database/Types.hpp"
#include "services/scanner/IScannerService.hpp"
#include "utils/Path.hpp"
#include "IScanStep.hpp"
#include "ScannerSettings.hpp"

namespace Recommendation
{
	class IRecommendationService;
}

namespace Scanner
{
	class ScannerService : public IScannerService
	{
		public:
			ScannerService(Database::Db& db, Recommendation::IRecommendationService& recommendationService);
			~ScannerService();

			ScannerService(const ScannerService&) = delete;
			ScannerService(ScannerService&&) = delete;
			ScannerService& operator=(const ScannerService&) = delete;
			ScannerService& operator=(ScannerService&&) = delete;

			void requestReload() override;
			void requestImmediateScan(bool force) override;

			Status	getStatus() const override;
			Events&	getEvents() override { return _events; }

		private:
			void start();
			void stop();

			// Job handling
			void scheduleNextScan();
			void scheduleScan(bool force, const Wt::WDateTime& dateTime = {});

			void abortScan();

			// Update database (scheduled callback)
			void scan(bool force);

			void scanMediaDirectory( const std::filesystem::path& mediaDirectory, bool forceScan, ScanStats& stats);

			// Helpers
			void refreshScanSettings();
			ScannerSettings readSettings();

			void notifyInProgressIfNeeded(const ScanStepStats& stats);
			void notifyInProgress(const ScanStepStats& stats);
			void reloadSimilarityEngine(ScanStats& stats);

			Recommendation::IRecommendationService&	_recommendationService;

			std::vector<std::unique_ptr<IScanStep>>	_scanSteps;

			std::mutex								_controlMutex;
			bool									_abortScan {};
			Wt::WIOService							_ioService;
			boost::asio::system_timer				_scheduleTimer {_ioService};
			Events									_events;
			std::chrono::system_clock::time_point	_lastScanInProgressEmit {};
			Database::Db&							_db;
			Database::Session						_dbSession;

			mutable std::shared_mutex			_statusMutex;
			State								_curState {State::NotScheduled};
			std::optional<ScanStats> 			_lastCompleteScanStats;
			std::optional<ScanStepStats> 		_currentScanStepStats;
			Wt::WDateTime						_nextScheduledScan;

			ScannerSettings						_settings;
	};
} // Scanner

