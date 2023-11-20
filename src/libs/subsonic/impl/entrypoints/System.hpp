

#pragma once

#include "RequestContext.hpp"
#include "SubsonicResponse.hpp"

namespace API::Subsonic
{
    Response handlePingRequest(RequestContext& context);
    Response handleGetLicenseRequest(RequestContext& context);
    Response handleGetOpenSubsonicExtensions(RequestContext& context);
}
