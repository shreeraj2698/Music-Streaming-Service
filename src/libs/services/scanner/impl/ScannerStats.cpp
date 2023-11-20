

#include "services/scanner/ScannerStats.hpp"

namespace Scanner {

ScanError::ScanError(const std::filesystem::path& _file, ScanErrorType _error, const std::string& _systemError)
: file {_file},
error {_error},
systemError {_systemError}
{
}

std::size_t
ScanStats::nbFiles() const
{
	return skips + additions + updates;
}

std::size_t
ScanStats::nbChanges() const
{
	return additions + deletions + updates;
}

unsigned
ScanStepStats::progress() const
{
	return (processedElems / static_cast<float>(totalElems ? totalElems : 1)) * 100;
}

} // namespace Scanner

