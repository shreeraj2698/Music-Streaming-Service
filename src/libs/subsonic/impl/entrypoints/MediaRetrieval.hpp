

#pragma once

#include <Wt/Http/Request.h>
#include <Wt/Http/Response.h>

#include "RequestContext.hpp"

namespace API::Subsonic
{
    void handleDownload(RequestContext& context, const Wt::Http::Request& request, Wt::Http::Response& response);
    void handleStream(RequestContext& context, const Wt::Http::Request& request, Wt::Http::Response& response);
    void handleGetCoverArt(RequestContext& context, const Wt::Http::Request& request, Wt::Http::Response& response);
}

