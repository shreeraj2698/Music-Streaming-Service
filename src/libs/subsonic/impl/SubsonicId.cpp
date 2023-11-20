

#include "SubsonicId.hpp"

#include "SubsonicResponse.hpp"

#include "utils/Logger.hpp"
#include "utils/String.hpp"

namespace API::Subsonic
{
    std::string idToString(Database::ArtistId id)
    {
        return "ar-" + id.toString();
    }

    std::string idToString(Database::ReleaseId id)
    {
        return "al-" + id.toString();
    }

    std::string idToString(RootId)
    {
        return "root";
    }

    std::string idToString(Database::TrackId id)
    {
        return "tr-" + id.toString();
    }

    std::string idToString(Database::TrackListId id)
    {
        return "pl-" + id.toString();
    }
} // namespace API::Subsonic

namespace StringUtils
{
    template<>
    std::optional<Database::ArtistId> readAs(std::string_view str)
    {
        std::vector<std::string_view> values{ StringUtils::splitString(str, "-") };
        if (values.size() != 2)
            return std::nullopt;

        if (values[0] != "ar")
            return std::nullopt;

        if (const auto value{ StringUtils::readAs<Database::ArtistId::ValueType>(values[1]) })
            return Database::ArtistId{ *value };

        return std::nullopt;
    }

    template<>
    std::optional<Database::ReleaseId> readAs(std::string_view str)
    {
        std::vector<std::string_view> values{ StringUtils::splitString(str, "-") };
        if (values.size() != 2)
            return std::nullopt;

        if (values[0] != "al")
            return std::nullopt;

        if (const auto value{ StringUtils::readAs<Database::ReleaseId::ValueType>(values[1]) })
            return Database::ReleaseId{ *value };

        return std::nullopt;
    }

    template<>
    std::optional<API::Subsonic::RootId> readAs(std::string_view str)
    {
        if (str == "root")
            return API::Subsonic::RootId{};

        return std::nullopt;
    }

    template<>
    std::optional<Database::TrackId> readAs(std::string_view str)
    {
        std::vector<std::string_view> values{ StringUtils::splitString(str, "-") };
        if (values.size() != 2)
            return std::nullopt;

        if (values[0] != "tr")
            return std::nullopt;

        if (const auto value{ StringUtils::readAs<Database::TrackId::ValueType>(values[1]) })
            return Database::TrackId{ *value };

        return std::nullopt;
    }

    template<>
    std::optional<Database::TrackListId> readAs(std::string_view str)
    {
        std::vector<std::string_view> values{ StringUtils::splitString(str, "-") };
        if (values.size() != 2)
            return std::nullopt;

        if (values[0] != "pl")
            return std::nullopt;

        if (const auto value{ StringUtils::readAs<Database::TrackListId::ValueType>(values[1]) })
            return Database::TrackListId{ *value };

        return std::nullopt;
    }
}
