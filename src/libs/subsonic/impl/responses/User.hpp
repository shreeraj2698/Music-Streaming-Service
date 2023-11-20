

#pragma once

#include "services/database/Object.hpp"
#include "SubsonicResponse.hpp"

namespace Database
{
    class User;
}

namespace API::Subsonic
{
    Response::Node createUserNode(const Database::ObjectPtr<Database::User>& user);
}