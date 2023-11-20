

#include "services/database/TrackBookmark.hpp"

#include "services/database/Session.hpp"
#include "services/database/Track.hpp"
#include "services/database/User.hpp"
#include "IdTypeTraits.hpp"
#include "Utils.hpp"

namespace Database {

TrackBookmark::TrackBookmark(ObjectPtr<User> user, ObjectPtr<Track> track)
: _user {getDboPtr(user)},
_track {getDboPtr(track)}
{
}

TrackBookmark::pointer
TrackBookmark::create(Session& session, ObjectPtr<User> user, ObjectPtr<Track> track)
{
	return session.getDboSession().add(std::unique_ptr<TrackBookmark> {new TrackBookmark {user, track}});
}

std::size_t
TrackBookmark::getCount(Session& session)
{
	session.checkSharedLocked();

	return session.getDboSession().query<int>("SELECT COUNT(*) FROM track_bookmark");
}

RangeResults<TrackBookmarkId>
TrackBookmark::find(Session& session, UserId userId, Range range)
{
	session.checkSharedLocked();

	auto query {session.getDboSession().query<TrackBookmarkId>("SELECT id from track_bookmark")
				.where("user_id = ?").bind(userId)};

	return Utils::execQuery(query, range);
}

TrackBookmark::pointer
TrackBookmark::find(Session& session, UserId userId, TrackId trackId)
{
	session.checkSharedLocked();

	return session.getDboSession().find<TrackBookmark>()
		.where("user_id = ?").bind(userId)
		.where("track_id = ?").bind(trackId)
		.resultValue();
}

TrackBookmark::pointer
TrackBookmark::find(Session& session, TrackBookmarkId id)
{
	session.checkSharedLocked();

	return session.getDboSession().find<TrackBookmark>()
		.where("id = ?").bind(id)
		.resultValue();
}

} // namespace Database

