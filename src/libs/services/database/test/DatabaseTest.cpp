

#include <list>

#include "Common.hpp"

using namespace Database;

TEST_F(DatabaseFixture, MultiTracksSingleArtistSingleRelease)
{
	constexpr std::size_t nbTracks {10};
	std::list<ScopedTrack> tracks;
	ScopedArtist artist {session, "MyArtst"};
	ScopedRelease release {session, "MyRelease"};

	for (std::size_t i {}; i < nbTracks; ++i)
	{
		tracks.emplace_back(session, "MyTrack" + std::to_string(i));

		auto transaction {session.createUniqueTransaction()};

		TrackArtistLink::create(session, tracks.back().get(), artist.get(), TrackArtistLinkType::Artist);
		tracks.back().get().modify()->setRelease(release.get());
	}

	{
		auto transaction {session.createSharedTransaction()};
		EXPECT_TRUE(Release::findOrphans(session, Range {}).results.empty());
		EXPECT_TRUE(Artist::findAllOrphans(session, Range {}).results.empty());
	}

	{
		auto transaction {session.createSharedTransaction()};

		auto releases {Release::find(session, Release::FindParameters {}.setArtist(artist.getId()))};
		ASSERT_EQ(releases.results.size(), 1);
		EXPECT_EQ(releases.results.front(), release.getId());

		const auto releaseTracks {Track::find(session, Track::FindParameters {}.setRelease(release.getId()))};
		EXPECT_EQ(releaseTracks.results.size(), nbTracks);
	}
}

TEST_F(DatabaseFixture, SingleTrackSingleReleaseSingleArtist)
{
	ScopedTrack track {session, "MyTrack"};
	ScopedRelease release {session, "MyRelease"};
	ScopedArtist artist {session, "MyArtist"};

	{
		auto transaction {session.createUniqueTransaction()};

		auto trackArtistLink {TrackArtistLink::create(session, track.get(), artist.get(), TrackArtistLinkType::Artist)};
		track.get().modify()->setRelease(release.get());
	}

	{
		auto transaction {session.createUniqueTransaction()};

		auto releases {Release::find(session, Release::FindParameters {}.setArtist(artist.getId()))};
		ASSERT_EQ(releases.results.size(), 1);
		EXPECT_EQ(releases.results.front(), release.getId());

		auto artists {release->getArtists()};
		ASSERT_EQ(artists.size(), 1);
		ASSERT_EQ(artists.front()->getId(), artist.getId());
	}
}

TEST_F(DatabaseFixture, SingleUser)
{
	{
		auto transaction {session.createSharedTransaction()};
		EXPECT_TRUE(User::find(session, User::FindParameters {}).results.empty());
		EXPECT_EQ(User::getCount(session), 0);
	}

	ScopedUser user {session, "MyUser"};

	{
		auto transaction {session.createSharedTransaction()};

		EXPECT_EQ(User::find(session, User::FindParameters {}).results.size(), 1);
		EXPECT_EQ(User::getCount(session), 1);
	}
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
