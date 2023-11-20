

#include <gtest/gtest.h>

#include "utils/Logger.hpp"
#include "utils/Service.hpp"
#include "utils/StreamLogger.hpp"

int main(int argc, char **argv)
{
	// log to stdout
	Service<Logger> logger {std::make_unique<StreamLogger>(std::cout, EnumSet<Severity> {Severity::FATAL, Severity::ERROR})};

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

