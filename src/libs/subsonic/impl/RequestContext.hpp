

#pragma once

#include <string>

#include <Wt/Http/Request.h>

#include "services/database/UserId.hpp"
#include "ClientInfo.hpp"
#include "ProtocolVersion.hpp"

namespace Database
{
    class Session;
}

namespace API::Subsonic
{
    struct RequestContext
    {
        const Wt::Http::ParameterMap& parameters;
        Database::Session& dbSession;
        Database::UserId userId;
        ClientInfo clientInfo;
        ProtocolVersion serverProtocolVersion;
    };
}

