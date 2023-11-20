

#pragma once

#include <string>
#include "ProtocolVersion.hpp"

namespace API::Subsonic
{
    struct ClientInfo
    {
        std::string name;
        std::string user;
        std::string password;
        ProtocolVersion version;
    };
}
