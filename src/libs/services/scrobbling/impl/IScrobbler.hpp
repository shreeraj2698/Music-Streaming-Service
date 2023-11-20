

#pragma once

#include <chrono>
#include <memory>
#include <optional>

#include "services/database/StarredArtistId.hpp"
#include "services/database/StarredReleaseId.hpp"
#include "services/database/StarredTrackId.hpp"
#include "services/scrobbling/Listen.hpp"

namespace Database
{
    class Session;
    class TrackList;
    class User;
}

namespace Scrobbling
{
    class IScrobbler
    {
    public:
        virtual ~IScrobbler() = default;

        // Listens
        virtual void listenStarted(const Listen& listen) = 0;
        virtual void listenFinished(const Listen& listen, std::optional<std::chrono::seconds> duration) = 0;
        virtual void addTimedListen(const TimedListen& listen) = 0;

        // Feedbacks
        virtual void onStarred(Database::StarredArtistId) = 0;
        virtual void onUnstarred(Database::StarredArtistId) = 0;
        virtual void onStarred(Database::StarredReleaseId) = 0;
        virtual void onUnstarred(Database::StarredReleaseId) = 0;
        virtual void onStarred(Database::StarredTrackId) = 0;
        virtual void onUnstarred(Database::StarredTrackId) = 0;
    };

    std::unique_ptr<IScrobbler> createScrobbler(std::string_view backendName);

} // ns Scrobbling

