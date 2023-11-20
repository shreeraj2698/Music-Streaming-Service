

#pragma once

#include "RequestContext.hpp"
#include "SubsonicResponse.hpp"

namespace API::Subsonic
{
    Response handleStarRequest(RequestContext& context);
    Response handleUnstarRequest(RequestContext& context);
    Response handleScrobble(RequestContext& context);
}