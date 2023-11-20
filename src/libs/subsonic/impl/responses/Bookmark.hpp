

#pragma once

#include "services/database/Object.hpp"
#include "SubsonicResponse.hpp"

namespace Database
{
    class TrackBookmark;
}

namespace API::Subsonic
{
    Response::Node createBookmarkNode(const Database::ObjectPtr<Database::TrackBookmark>& bookmark);
}