

#pragma once

#include "services/database/Object.hpp"
#include "SubsonicResponse.hpp"

namespace Database
{
    class Track;
    class User;
    class Session;
}

namespace API::Subsonic
{
    Response::Node createSongNode(const Database::ObjectPtr<Database::Track>& track, Database::Session& session, const Database::ObjectPtr<Database::User>& user);
}