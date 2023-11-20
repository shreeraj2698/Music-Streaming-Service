

#pragma once

#include "services/database/Object.hpp"
#include "SubsonicResponse.hpp"

namespace Database
{
    class TrackList;
    class Session;
}

namespace API::Subsonic
{
    Response::Node createPlaylistNode(const Database::ObjectPtr<Database::TrackList>& tracklist, Database::Session& session);
}