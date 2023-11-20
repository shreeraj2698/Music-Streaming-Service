

#pragma once

#include <functional>

#include "services/scanner/ScannerStats.hpp"
#include "IScanStep.hpp"
#include "ScannerSettings.hpp"

namespace Database
{
	class Db;
}

namespace Scanner
{
	class ScanStepBase : public IScanStep
	{
		public:
			static inline const std::filesystem::path excludeDirFileName {".lmsignore"};
			using ProgressCallback = std::function<void(const ScanStepStats& stats)>;

			struct InitParams
			{
				const ScannerSettings& settings;
				ProgressCallback progressCallback;
				bool& abortScan;
				Database::Db& db;
			};
			ScanStepBase(InitParams& initParams)
				: _settings {initParams.settings}
			, _progressCallback {initParams.progressCallback}
			, _abortScan {initParams.abortScan}
			, _db {initParams.db}
			{}

		protected:
			const ScannerSettings&	_settings;
			ProgressCallback		_progressCallback;
			bool&					_abortScan;
			Database::Db&			_db;
	};
}
