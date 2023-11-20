

#include "ProtocolVersion.hpp"

namespace StringUtils
{
    template<>
    std::optional<API::Subsonic::ProtocolVersion> readAs(std::string_view str)
    {
        // Expects "X.Y.Z"
        const auto numbers{ StringUtils::splitString(str, ".") };
        if (numbers.size() < 2 || numbers.size() > 3)
            return std::nullopt;

        API::Subsonic::ProtocolVersion version;

        auto number{ StringUtils::readAs<unsigned>(numbers[0]) };
        if (!number)
            return std::nullopt;
        version.major = *number;

        number = { StringUtils::readAs<unsigned>(numbers[1]) };
        if (!number)
            return std::nullopt;
        version.minor = *number;

        if (numbers.size() == 3)
        {
            number = { StringUtils::readAs<unsigned>(numbers[2]) };
            if (!number)
                return std::nullopt;
            version.patch = *number;
        }

        return version;
    }
}

