

#pragma once

#include "RequestContext.hpp"
#include "SubsonicResponse.hpp"

namespace API::Subsonic
{
    Response handleSearch2Request(RequestContext& context);
    Response handleSearch3Request(RequestContext& context);
}
