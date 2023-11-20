

#include "Common.hpp"
#include "services/database/StarredTrack.hpp"

using namespace Database;

using ScopedStarredTrack = ScopedEntity<Database::StarredTrack>;

TEST_F(DatabaseFixture, StarredTrack)
{
	ScopedTrack track {session, "MyTrack"};
	ScopedUser user {session, "MyUser"};
	ScopedUser user2 {session, "MyUser2"};

	{
		auto transaction {session.createSharedTransaction()};

		auto starredTrack {StarredTrack::find(session, track->getId(), user->getId(), Scrobbler::Internal)};
		EXPECT_FALSE(starredTrack);
		EXPECT_EQ(StarredTrack::getCount(session), 0);

		auto tracks {Track::find(session, Track::FindParameters {})};
		EXPECT_EQ(tracks.results.size(), 1);
	}

	ScopedStarredTrack starredTrack {session, track.lockAndGet(), user.lockAndGet(), Scrobbler::Internal};
	{
		auto transaction {session.createSharedTransaction()};

		auto gotTrack {StarredTrack::find(session, track->getId(), user->getId(), Scrobbler::Internal)};
		EXPECT_EQ(gotTrack->getId(), starredTrack->getId());
		EXPECT_EQ(StarredTrack::getCount(session), 1);
	}

	{
		auto transaction {session.createSharedTransaction()};

		auto tracks {Track::find(session, Track::FindParameters {})};
		EXPECT_EQ(tracks.results.size(), 1);

		tracks = Track::find(session, Track::FindParameters {}.setStarringUser(user.getId(), Scrobbler::Internal));
		EXPECT_EQ(tracks.results.size(), 1);

		tracks = Track::find(session, Track::FindParameters {}.setStarringUser(user2.getId(), Scrobbler::Internal));
		EXPECT_EQ(tracks.results.size(), 0);
	}
}

TEST_F(DatabaseFixture, Starredtrack_PendingDestroy)
{
	ScopedTrack track {session, "MyTrack"};
	ScopedUser user {session, "MyUser"};
	ScopedStarredTrack starredTrack {session, track.lockAndGet(), user.lockAndGet(), Scrobbler::Internal};

	{
		auto transaction {session.createUniqueTransaction()};

		auto tracks {Track::find(session, Track::FindParameters {}.setStarringUser(user.getId(), Scrobbler::Internal))};
		EXPECT_EQ(tracks.results.size(), 1);

		starredTrack.get().modify()->setScrobblingState(ScrobblingState::PendingRemove);
		tracks = Track::find(session, Track::FindParameters {}.setStarringUser(user.getId(), Scrobbler::Internal));
		EXPECT_EQ(tracks.results.size(), 0);
	}
}

TEST_F(DatabaseFixture, StarredTrack_dateTime)
{
	ScopedTrack track1 {session, "MyTrack1"};
	ScopedTrack track2 {session, "MyTrack2"};
	ScopedUser user {session, "MyUser"};

	ScopedStarredTrack starredTrack1 {session, track1.lockAndGet(), user.lockAndGet(), Scrobbler::Internal};
	ScopedStarredTrack starredTrack2 {session, track2.lockAndGet(), user.lockAndGet(), Scrobbler::Internal};

	const Wt::WDateTime dateTime {Wt::WDate {1950, 1, 2}, Wt::WTime {12, 30, 1}};

	{
		auto transaction {session.createSharedTransaction()};

		auto tracks {Track::find(session, Track::FindParameters {}.setStarringUser(user.getId(), Scrobbler::Internal))};
		EXPECT_EQ(tracks.results.size(), 2);
	}

	{
		auto transaction {session.createUniqueTransaction()};

		starredTrack1.get().modify()->setDateTime(dateTime);
		starredTrack2.get().modify()->setDateTime(dateTime.addSecs(-1));

		auto tracks {Track::find(session, Track::FindParameters {}.setStarringUser(user.getId(), Scrobbler::Internal)
																	.setSortMethod(TrackSortMethod::StarredDateDesc))};
		ASSERT_EQ(tracks.results.size(), 2);
		EXPECT_EQ(tracks.results[0], starredTrack1->getTrack()->getId());
		EXPECT_EQ(tracks.results[1], starredTrack2->getTrack()->getId());
	}
	{
		auto transaction {session.createUniqueTransaction()};

		starredTrack1.get().modify()->setDateTime(dateTime);
		starredTrack2.get().modify()->setDateTime(dateTime.addSecs(1));

		auto tracks {Track::find(session, Track::FindParameters {}.setStarringUser(user.getId(), Scrobbler::Internal)
																	.setSortMethod(TrackSortMethod::StarredDateDesc))};
		ASSERT_EQ(tracks.results.size(), 2);
		EXPECT_EQ(tracks.results[0], starredTrack2->getTrack()->getId());
		EXPECT_EQ(tracks.results[1], starredTrack1->getTrack()->getId());
	}
}
