

#pragma once

#include "Logger.hpp"

class WtLogger final : public Logger
{
	public:
		void processLog(const Log& log) override;
};

