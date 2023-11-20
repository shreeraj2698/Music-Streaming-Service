

#pragma once

#include <Wt/WDateTime.h>

#include "services/database/TrackId.hpp"
#include "services/database/UserId.hpp"

namespace Scrobbling
{
    struct Listen
    {
        Database::UserId userId{};
        Database::TrackId trackId{};
    };

    struct TimedListen : public Listen
    {
        Wt::WDateTime listenedAt;
    };
} // ns Scrobbling

