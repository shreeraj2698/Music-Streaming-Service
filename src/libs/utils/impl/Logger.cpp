

#include "utils/Logger.hpp"

const char* getModuleName(Module mod)
{
	switch (mod)
	{
		case Module::API_SUBSONIC:	return "API_SUBSONIC";
		case Module::AUTH:			return "AUTH";
		case Module::AV:			return "AV";
		case Module::CHILDPROCESS:	return "CHILDPROC";
		case Module::COVER:			return "COVER";
		case Module::DB:			return "DB";
		case Module::DBUPDATER:		return "DB UPDATER";
		case Module::FEATURE:		return "FEATURE";
		case Module::HTTP:			return "HTTP";
		case Module::MAIN:			return "MAIN";
		case Module::METADATA:		return "METADATA";
		case Module::REMOTE:		return "REMOTE";
		case Module::SCROBBLING:	return "SCROBBLING";
		case Module::SERVICE:		return "SERVICE";
		case Module::RECOMMENDATION:	return "RECOMMENDATION";
		case Module::TRANSCODE:		return "TRANSCODE";
		case Module::UI:			return "UI";
		case Module::UTILS:			return "UTILS";
	}
	return "";
}

const char* getSeverityName(Severity sev)
{
	switch (sev)
	{
		case Severity::FATAL:		return "fatal";
		case Severity::ERROR:		return "error";
		case Severity::WARNING:		return "warning";
		case Severity::INFO:		return "info";
		case Severity::DEBUG:		return "debug";
	}
	return "";
}

Log::Log(Logger* logger, Module module, Severity severity)
	: _module {module},
	_severity {severity},
	_logger {logger}
{}

Log::~Log()
{
	if (_logger)
		_logger->processLog(*this);
}

std::string
Log::getMessage() const
{
	return _oss.str();
}

