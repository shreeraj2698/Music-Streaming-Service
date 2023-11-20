

#pragma once

#include <string>
#include <sstream>

#include "Service.hpp"

enum class Severity
{
    FATAL,
    ERROR,
    WARNING,
    INFO,
    DEBUG,
};

enum class Module
{
    API_SUBSONIC,
    AUTH,
    AV,
    CHILDPROCESS,
    COVER,
    DB,
    DBUPDATER,
    FEATURE,
    HTTP,
    MAIN,
    METADATA,
    REMOTE,
    SCROBBLING,
    SERVICE,
    RECOMMENDATION,
    TRANSCODE,
    UI,
    UTILS,
};

const char* getModuleName(Module mod);
const char* getSeverityName(Severity sev);

class Logger;
class Log
{
public:
    Log(Logger* logger, Module module, Severity severity);
    ~Log();

    Module getModule() const { return _module; }
    Severity getSeverity() const { return _severity; }
    std::string getMessage() const;

    std::ostringstream& getOstream() { return _oss; }

private:
    Log(const Log&) = delete;
    Log& operator=(const Log&) = delete;

    Module _module;
    Severity _severity;
    std::ostringstream _oss;
    Logger* _logger{};
};

class Logger
{
public:
    virtual ~Logger() = default;
    virtual void processLog(const Log& log) = 0;
};

#define LMS_LOG(module, severity)		Log{Service<Logger>::get(), Module::module, Severity::severity}.getOstream()
#define LMS_LOG_EX(module, severity)	Log{Service<Logger>::get(), module, severity}.getOstream()
