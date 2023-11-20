

#include "utils/WtLogger.hpp"

#include <thread>
#include <sstream>
#include <Wt/WApplication.h>
#include <Wt/WLogger.h>

#include "utils/Logger.hpp"

namespace
{
    std::string to_string(std::thread::id id)
    {
        std::ostringstream oss;
        oss << id;
        return oss.str();
    }
}

void WtLogger::processLog(const Log& log)
{
    Wt::log(getSeverityName(log.getSeverity())) << Wt::WLogger::sep << to_string(std::this_thread::get_id()) << Wt::WLogger::sep << "[" << getModuleName(log.getModule()) << "]" << Wt::WLogger::sep << log.getMessage();
}

