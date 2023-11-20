

#pragma once

#include <memory>

namespace Database
{
	class Db;
}

namespace Recommendation
{
	class IEngine;
	std::unique_ptr<IEngine> createClustersEngine(Database::Db& db);
}

