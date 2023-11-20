
#pragma once

#include <memory>

#include <Wt/WResource.h>

namespace Database
{
	class Db;
}

namespace API::Subsonic
{
	std::unique_ptr<Wt::WResource> createSubsonicResource(Database::Db& db);
} // namespace
