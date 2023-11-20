

#pragma once

#include <filesystem>

#include "ScanStepBase.hpp"

namespace Scanner
{
	class ScanStepRemoveOrphanDbFiles : public ScanStepBase
	{
		public:
			using ScanStepBase::ScanStepBase;

		private:
			std::string_view getStepName() const override { return "Checking orphaned entries"; }
			ScanStep getStep() const override { return ScanStep::ChekingForMissingFiles; }
			void process(ScanContext& context) override;

			void removeOrphanTracks(ScanContext& context);
			void removeOrphanClusters();
			void removeOrphanArtists();
			void removeOrphanReleases();
			bool checkFile(const std::filesystem::path& p);
	};
}
