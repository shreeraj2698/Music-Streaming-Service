

#pragma once

#include "services/database/Object.hpp"
#include "SubsonicResponse.hpp"

namespace Database
{
    class Release;
    class User;
    class Session;
}

namespace API::Subsonic
{
    Response::Node createAlbumNode(const Database::ObjectPtr<Database::Release>& release, Database::Session& dbSession, const Database::ObjectPtr<Database::User>& user, bool id3);
}