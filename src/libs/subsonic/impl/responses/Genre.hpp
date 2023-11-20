

#pragma once

#include "services/database/Object.hpp"
#include "SubsonicResponse.hpp"

namespace Database
{
    class Cluster;
}

namespace API::Subsonic
{
    Response::Node createGenreNode(const Database::ObjectPtr<Database::Cluster>& cluster);
}
