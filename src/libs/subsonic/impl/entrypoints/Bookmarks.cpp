

#include "Bookmarks.hpp"

#include "services/database/Session.hpp"
#include "services/database/User.hpp"
#include "services/database/Track.hpp"
#include "services/database/TrackBookmark.hpp"
#include "responses/Bookmark.hpp"
#include "responses/Song.hpp"
#include "ParameterParsing.hpp"
#include "SubsonicId.hpp"

namespace API::Subsonic
{
    using namespace Database;

    Response handleGetBookmarks(RequestContext& context)
    {
        auto transaction{ context.dbSession.createSharedTransaction() };

        User::pointer user{ User::find(context.dbSession, context.userId) };
        if (!user)
            throw UserNotAuthorizedError{};

        const auto bookmarkIds{ TrackBookmark::find(context.dbSession, user->getId(), Range {}) };

        Response response{ Response::createOkResponse(context.serverProtocolVersion) };
        Response::Node& bookmarksNode{ response.createNode("bookmarks") };

        for (const TrackBookmarkId bookmarkId : bookmarkIds.results)
        {
            const TrackBookmark::pointer bookmark{ TrackBookmark::find(context.dbSession, bookmarkId) };
            Response::Node bookmarkNode{ createBookmarkNode(bookmark) };
            bookmarkNode.addArrayChild("entry", createSongNode(bookmark->getTrack(), context.dbSession, user));

            bookmarksNode.addArrayChild("bookmark", std::move(bookmarkNode));
        }

        return response;
    }

    Response handleCreateBookmark(RequestContext& context)
    {
        // Mandatory params
        TrackId trackId{ getMandatoryParameterAs<TrackId>(context.parameters, "id") };
        unsigned long position{ getMandatoryParameterAs<unsigned long>(context.parameters, "position") };
        const std::optional<std::string> comment{ getParameterAs<std::string>(context.parameters, "comment") };

        auto transaction{ context.dbSession.createUniqueTransaction() };

        const User::pointer user{ User::find(context.dbSession, context.userId) };
        if (!user)
            throw UserNotAuthorizedError{};

        const Track::pointer track{ Track::find(context.dbSession, trackId) };
        if (!track)
            throw RequestedDataNotFoundError{};

        // Replace any existing bookmark
        auto bookmark{ TrackBookmark::find(context.dbSession, user->getId(), trackId) };
        if (!bookmark)
            bookmark = context.dbSession.create<TrackBookmark>(user, track);

        bookmark.modify()->setOffset(std::chrono::milliseconds{ position });
        if (comment)
            bookmark.modify()->setComment(*comment);

        return Response::createOkResponse(context.serverProtocolVersion);
    }

    Response handleDeleteBookmark(RequestContext& context)
    {
        // Mandatory params
        TrackId trackId{ getMandatoryParameterAs<TrackId>(context.parameters, "id") };

        auto transaction{ context.dbSession.createUniqueTransaction() };

        auto bookmark{ TrackBookmark::find(context.dbSession, context.userId, trackId) };
        if (!bookmark)
            throw RequestedDataNotFoundError{};

        bookmark.remove();

        return Response::createOkResponse(context.serverProtocolVersion);
    }
}