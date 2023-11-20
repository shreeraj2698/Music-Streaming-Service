

#pragma once

#include "services/database/Db.hpp"
#include "services/database/Session.hpp"
#include "services/database/User.hpp"

namespace Scrobbling
{
    using namespace Database;

    template <typename ObjType, typename ObjIdType, typename StarredObjType>
    void ScrobblingService::star(UserId userId, ObjIdType objId)
    {
        auto scrobbler {getUserScrobbler(userId)};
        if (!scrobbler)
            return;

        typename StarredObjType::IdType starredObjId;
        {
            Session& session {_db.getTLSSession()};
            auto transaction {session.createUniqueTransaction()};

            typename StarredObjType::pointer starredObj {StarredObjType::find(session, objId, userId, *scrobbler)};
            if (!starredObj)
            {
                const typename ObjType::pointer obj {ObjType::find(session, objId)};
                if (!obj)
                    return;

                const User::pointer user {User::find(session, userId)};
                if (!user)
                    return;

                starredObj = session.create<StarredObjType>(obj, user, *scrobbler);
            }
            starredObj.modify()->setDateTime(Wt::WDateTime::currentDateTime());
            starredObjId = starredObj->getId();
        }
        _scrobblers[*scrobbler]->onStarred(starredObjId);
    }

    template <typename ObjType, typename ObjIdType, typename StarredObjType>
    void ScrobblingService::unstar(UserId userId, ObjIdType objId)
    {
        auto scrobbler {getUserScrobbler(userId)};
        if (!scrobbler)
            return;

        typename StarredObjType::IdType starredObjId;
        {
            Session& session {_db.getTLSSession()};
            auto transaction {session.createSharedTransaction()};

            typename StarredObjType::pointer starredObj {StarredObjType::find(session, objId, userId, *scrobbler)};
            if (!starredObj)
                return;

            starredObjId = starredObj->getId();
        }
        _scrobblers[*scrobbler]->onUnstarred(starredObjId);
    }

    template <typename ObjType, typename ObjIdType, typename StarredObjType>
    bool ScrobblingService::isStarred(UserId userId, ObjIdType objId)
    {
        auto scrobbler {getUserScrobbler(userId)};
        if (!scrobbler)
            return false;

        Session& session {_db.getTLSSession()};
        auto transaction {session.createSharedTransaction()};

        typename StarredObjType::pointer starredObj {StarredObjType::find(session, objId, userId, *scrobbler)};
        return starredObj && (starredObj->getScrobblingState() != ScrobblingState::PendingRemove);
    }

    template <typename ObjType, typename ObjIdType, typename StarredObjType>
    Wt::WDateTime ScrobblingService::getStarredDateTime(UserId userId, ObjIdType objId)
    {
        auto scrobbler {getUserScrobbler(userId)};
        if (!scrobbler)
            return {};

        Session& session {_db.getTLSSession()};
        auto transaction {session.createSharedTransaction()};

        typename StarredObjType::pointer starredObj {StarredObjType::find(session, objId, userId, *scrobbler)};
        if (starredObj && (starredObj->getScrobblingState() != ScrobblingState::PendingRemove))
            return starredObj->getDateTime();

        return {};
    }

} // ns Scrobbling

