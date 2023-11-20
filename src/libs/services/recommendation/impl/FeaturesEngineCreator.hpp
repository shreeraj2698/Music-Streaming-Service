

#pragma once

#include <memory>
#include "IEngine.hpp"

namespace Database
{
	class Db;
}

namespace Recommendation
{
	std::unique_ptr<IEngine> createFeaturesEngine(Database::Db& db);
}

