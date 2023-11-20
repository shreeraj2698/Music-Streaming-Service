

#pragma once

#include <string>
#include <vector>
#include "services/database/Object.hpp"
#include "services/database/Types.hpp"
#include "SubsonicResponse.hpp"

namespace Database
{
    class Artist;
    class User;
    class Session;
}

namespace API::Subsonic
{
    namespace Utils
    {
        std::string joinArtistNames(const std::vector<Database::ObjectPtr<Database::Artist>>& artists);
        std::string_view toString(Database::TrackArtistLinkType type);
    }
    Response::Node createArtistNode(const Database::ObjectPtr<Database::Artist>& artist, Database::Session& session, const Database::ObjectPtr<Database::User>& user, bool id3);
    Response::Node createArtistNode(const Database::ObjectPtr<Database::Artist>& artist); // only minimal info
}