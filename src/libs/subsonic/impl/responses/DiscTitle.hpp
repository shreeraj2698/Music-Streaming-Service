

#pragma once

#include "services/database/Types.hpp"
#include "SubsonicResponse.hpp"

namespace API::Subsonic
{
    Response::Node createDiscTitle(const Database::DiscInfo& discInfo);
}