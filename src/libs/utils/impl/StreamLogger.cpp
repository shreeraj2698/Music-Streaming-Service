

#include <thread>

#include "utils/StreamLogger.hpp"

StreamLogger::StreamLogger(std::ostream& os, EnumSet<Severity> severities)
    : _os{ os }
    , _severities{ severities }
{
}

void StreamLogger::processLog(const Log& log)
{
    if (_severities.contains(log.getSeverity()))
        _os << std::this_thread::get_id() << " [" << getSeverityName(log.getSeverity()) << "] [" << getModuleName(log.getModule()) << "] " << log.getMessage() << std::endl;
}

