

#pragma once

#include <filesystem>

#include "metadata/IParser.hpp"
#include "ScanStepBase.hpp"

namespace Scanner
{
	class ScanStepScanFiles : public ScanStepBase
	{
		public:
			ScanStepScanFiles(InitParams& initParams);

		private:
			ScanStep getStep() const override { return ScanStep::ScanningFiles; }
			std::string_view getStepName() const override { return "Scanning files"; }
			void process(ScanContext& context) override;

			void scanAudioFile(const std::filesystem::path& file, ScanContext& context);

			std::unique_ptr<MetaData::IParser>			_metadataParser;
	};
}
