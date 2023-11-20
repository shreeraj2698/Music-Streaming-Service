

#pragma once

#include "utils/String.hpp"

namespace API::Subsonic
{
    struct ProtocolVersion
    {
        unsigned major{};
        unsigned minor{};
        unsigned patch{};
    };

    static inline constexpr ProtocolVersion defaultServerProtocolVersion{ 1, 16, 0 };
    static inline constexpr std::string_view serverVersion{ "2" };
}

namespace StringUtils
{
    template<>
    std::optional<API::Subsonic::ProtocolVersion> readAs(std::string_view str);
}

