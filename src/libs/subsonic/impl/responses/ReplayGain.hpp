

#pragma once

#include "services/database/Object.hpp"
#include "SubsonicResponse.hpp"

namespace Database
{
    class Track;
}

namespace API::Subsonic
{
    Response::Node createReplayGainNode(const Database::ObjectPtr<Database::Track>& track);
}