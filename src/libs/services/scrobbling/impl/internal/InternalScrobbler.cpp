

#include "InternalScrobbler.hpp"

#include "services/database/Db.hpp"
#include "services/database/Listen.hpp"
#include "services/database/Session.hpp"
#include "services/database/StarredArtist.hpp"
#include "services/database/StarredRelease.hpp"
#include "services/database/StarredTrack.hpp"
#include "services/database/Track.hpp"
#include "services/database/User.hpp"

namespace
{
    template <typename StarredObjType>
    void onStarred(Database::Session& session, typename StarredObjType::IdType id)
    {
        auto transaction{ session.createUniqueTransaction() };

        if (auto starredObj{ StarredObjType::find(session, id) })
            starredObj.modify()->setScrobblingState(Database::ScrobblingState::Synchronized);
    }

    template <typename StarredObjType>
    void onUnstarred(Database::Session& session, typename StarredObjType::IdType id)
    {
        auto transaction{ session.createUniqueTransaction() };

        if (auto starredObj{ StarredObjType::find(session, id) })
            starredObj.remove();
    }
}

namespace Scrobbling
{
    InternalScrobbler::InternalScrobbler(Database::Db& db)
        : _db{ db }
    {}

    void InternalScrobbler::listenStarted(const Listen&)
    {
        // nothing to do
    }

    void InternalScrobbler::listenFinished(const Listen& listen, std::optional<std::chrono::seconds> duration)
    {
        // only record tracks that have been played for at least of few seconds...
        if (duration && *duration < std::chrono::seconds{ 5 })
            return;

        addTimedListen({ listen, Wt::WDateTime::currentDateTime() });
    }

    void InternalScrobbler::addTimedListen(const TimedListen& listen)
    {
        Database::Session& session{ _db.getTLSSession() };
        auto transaction{ session.createUniqueTransaction() };

        if (Database::Listen::find(session, listen.userId, listen.trackId, Database::Scrobbler::Internal, listen.listenedAt))
            return;

        const Database::User::pointer user{ Database::User::find(session, listen.userId) };
        if (!user)
            return;

        const Database::Track::pointer track{ Database::Track::find(session, listen.trackId) };
        if (!track)
            return;

        auto dbListen{ session.create<Database::Listen>(user, track, Database::Scrobbler::Internal, listen.listenedAt) };
        dbListen.modify()->setScrobblingState(Database::ScrobblingState::Synchronized);
    }

    void InternalScrobbler::onStarred(Database::StarredArtistId starredArtistId)
    {
        ::onStarred<Database::StarredArtist>(_db.getTLSSession(), starredArtistId);
    }

    void InternalScrobbler::onUnstarred(Database::StarredArtistId starredArtistId)
    {
        ::onUnstarred<Database::StarredArtist>(_db.getTLSSession(), starredArtistId);
    }

    void InternalScrobbler::onStarred(Database::StarredReleaseId starredReleaseId)
    {
        ::onStarred<Database::StarredRelease>(_db.getTLSSession(), starredReleaseId);
    }

    void InternalScrobbler::onUnstarred(Database::StarredReleaseId starredReleaseId)
    {
        ::onUnstarred<Database::StarredRelease>(_db.getTLSSession(), starredReleaseId);
    }

    void InternalScrobbler::onStarred(Database::StarredTrackId starredTrackId)
    {
        ::onStarred<Database::StarredTrack>(_db.getTLSSession(), starredTrackId);
    }

    void InternalScrobbler::onUnstarred(Database::StarredTrackId starredTrackId)
    {
        ::onUnstarred<Database::StarredTrack>(_db.getTLSSession(), starredTrackId);
    }
} // Scrobbling

