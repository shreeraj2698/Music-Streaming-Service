

#pragma once

#include "services/database/ArtistId.hpp"
#include "services/database/ReleaseId.hpp"
#include "services/database/TrackId.hpp"
#include "services/database/TrackListId.hpp"
#include "utils/String.hpp"

namespace API::Subsonic
{
    struct RootId {};

    std::string idToString(Database::ArtistId id);
    std::string idToString(Database::ReleaseId id);
    std::string idToString(Database::TrackId id);
    std::string idToString(Database::TrackListId id);
    std::string idToString(RootId);
} // namespace API::Subsonic

// Used to parse parameters
namespace StringUtils
{
    template<>
    std::optional<API::Subsonic::RootId> readAs(std::string_view str);

    template<>
    std::optional<Database::ArtistId> readAs(std::string_view str);

    template<>
    std::optional<Database::ReleaseId> readAs(std::string_view str);

    template<>
    std::optional<Database::TrackId> readAs(std::string_view str);

    template<>
    std::optional<Database::TrackListId> readAs(std::string_view str);
}

