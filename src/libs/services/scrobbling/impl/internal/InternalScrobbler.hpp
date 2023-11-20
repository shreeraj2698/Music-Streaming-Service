

#pragma once

#include "IScrobbler.hpp"

namespace Database
{
    class Db;
}

namespace Scrobbling
{
    class InternalScrobbler final : public IScrobbler
    {
    public:
        InternalScrobbler(Database::Db& db);

    private:
        // IScrobbler
        void listenStarted(const Listen& listen) override;
        void listenFinished(const Listen& listen, std::optional<std::chrono::seconds> duration) override;
        void addTimedListen(const TimedListen& listen) override;

        void onStarred(Database::StarredArtistId) override;
        void onUnstarred(Database::StarredArtistId) override;
        void onStarred(Database::StarredReleaseId) override;
        void onUnstarred(Database::StarredReleaseId) override;
        void onStarred(Database::StarredTrackId) override;
        void onUnstarred(Database::StarredTrackId) override;

        Database::Db& _db;
    };
} // Scrobbling

