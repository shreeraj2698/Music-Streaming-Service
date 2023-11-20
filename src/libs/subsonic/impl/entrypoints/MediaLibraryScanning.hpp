

#pragma once

#include "RequestContext.hpp"
#include "SubsonicResponse.hpp"

namespace API::Subsonic::Scan
{
    Response handleGetScanStatus(RequestContext& context);
    Response handleStartScan(RequestContext& context);
}

