

#pragma once

#include <filesystem>
#include <set>
#include <string>
#include <vector>
#include <Wt/WDateTime.h>
#include "services/database/ScanSettings.hpp"

namespace Scanner
{
	struct ScannerSettings
	{
		std::size_t											scanVersion {};
		Wt::WTime											startTime;
		Database::ScanSettings::UpdatePeriod 				updatePeriod {Database::ScanSettings::UpdatePeriod::Never};
		std::vector<std::filesystem::path>					supportedExtensions;
		Database::ScanSettings::RecommendationEngineType	recommendationServiceType;
		std::filesystem::path								mediaDirectory;
		bool												skipDuplicateMBID {};
		std::set<std::string>								clusterTypeNames;

		bool operator==(const ScannerSettings& rhs) const
		{
			return scanVersion == rhs.scanVersion
				&& startTime == rhs.startTime
				&& updatePeriod == rhs.updatePeriod
				&& supportedExtensions == rhs.supportedExtensions
				&& recommendationServiceType == rhs.recommendationServiceType
				&& mediaDirectory == rhs.mediaDirectory
				&& skipDuplicateMBID == rhs.skipDuplicateMBID
				&& clusterTypeNames == rhs.clusterTypeNames;
		}
	};
}
