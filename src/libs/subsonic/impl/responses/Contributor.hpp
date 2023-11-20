

#pragma once

#include "services/database/Object.hpp"
#include "SubsonicResponse.hpp"

namespace Database
{
    class TrackArtistLink;
}

namespace API::Subsonic
{
    Response::Node createContributorNode(const Database::ObjectPtr<Database::TrackArtistLink>& trackArtistLink);
}