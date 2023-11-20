

#pragma once

#include <string_view>

#include "services/scanner/ScannerStats.hpp"

namespace Scanner
{
	class IScanStep
	{
		public:
			virtual ~IScanStep() = default;

			virtual ScanStep getStep() const = 0;
			virtual std::string_view getStepName() const = 0;

			struct ScanContext
			{
				const std::filesystem::path directory;
				const bool forceScan;
				ScanStats stats;
				ScanStepStats currentStepStats;
			};
			virtual void process(ScanContext& context) = 0;
	};
}
