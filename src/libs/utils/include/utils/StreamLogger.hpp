

#pragma once

#include "utils/EnumSet.hpp"
#include "utils/Logger.hpp"

class StreamLogger final : public Logger
{
	public:
		static constexpr EnumSet<Severity> defaultSeverities {Severity::FATAL, Severity::ERROR, Severity::WARNING, Severity::INFO};

		StreamLogger(std::ostream& oss, EnumSet<Severity> severities = defaultSeverities);

		void processLog(const Log& log);

	private:
		std::ostream& _os;
		const EnumSet<Severity> _severities;
};

