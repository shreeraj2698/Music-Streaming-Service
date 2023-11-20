

#pragma once

#include "RequestContext.hpp"
#include "SubsonicResponse.hpp"

namespace API::Subsonic
{
    Response handleGetBookmarks(RequestContext& context);
    Response handleCreateBookmark(RequestContext& context);
    Response handleDeleteBookmark(RequestContext& context);
}
