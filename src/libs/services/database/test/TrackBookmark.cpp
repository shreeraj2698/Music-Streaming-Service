

#include "Common.hpp"

#include "services/database/TrackBookmark.hpp"

using ScopedTrackBookmark = ScopedEntity<Database::TrackBookmark>;

using namespace Database;

TEST_F(DatabaseFixture, TrackBookmark)
{
	ScopedTrack track {session, "MyTrack"};
	ScopedUser user {session, "MyUser"};

	{
		auto transaction {session.createSharedTransaction()};
		EXPECT_EQ(TrackBookmark::getCount(session), 0);
	}

	ScopedTrackBookmark bookmark {session, user.lockAndGet(), track.lockAndGet()};

	{
		auto transaction {session.createUniqueTransaction()};

		bookmark.get().modify()->setComment("MyComment");
		bookmark.get().modify()->setOffset(std::chrono::milliseconds {5});
	}

	{
		auto transaction {session.createSharedTransaction()};

		EXPECT_EQ(TrackBookmark::getCount(session), 1);

		const auto bookmarks {TrackBookmark::find(session, user.getId(), Range {})};
		ASSERT_EQ(bookmarks.results.size(), 1);
		EXPECT_EQ(bookmarks.results.front(), bookmark.getId());
	}
	{
		auto transaction {session.createSharedTransaction()};

		auto userBookmark {TrackBookmark::find(session, user.getId(), track.getId())};
		ASSERT_TRUE(userBookmark);
		EXPECT_EQ(userBookmark, bookmark.get());

		EXPECT_EQ(userBookmark->getOffset(), std::chrono::milliseconds {5});
		EXPECT_EQ(userBookmark->getComment(), "MyComment");
	}
}
