

#include "ScanStepDiscoverFiles.hpp"
#include "utils/Logger.hpp"
#include "utils/Path.hpp"

namespace Scanner
{
	void
	ScanStepDiscoverFiles::process(ScanContext& context)
	{
		context.stats.filesScanned = 0;
		PathUtils::exploreFilesRecursive(context.directory, [&](std::error_code ec, const std::filesystem::path& path)
		{
			if (_abortScan)
				return false;

			if (!ec && PathUtils::hasFileAnyExtension(path, _settings.supportedExtensions))
			{
				context.currentStepStats.processedElems++;
				_progressCallback(context.currentStepStats);
			}

			return true;
		}, &excludeDirFileName);

		context.stats.filesScanned = context.currentStepStats.processedElems;

		LMS_LOG(DBUPDATER, DEBUG) << "Discovered " << context.stats.filesScanned << " files in '" << context.directory << "'";
	}
}
