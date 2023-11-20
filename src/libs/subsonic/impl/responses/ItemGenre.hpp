

#pragma once

#include <string_view>
#include "SubsonicResponse.hpp"

namespace Database
{
    class Cluster;
}

namespace API::Subsonic
{
    Response::Node createItemGenreNode(std::string_view name);
}
