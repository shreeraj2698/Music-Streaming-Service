

#include "Common.hpp"

#include "services/database/TrackFeatures.hpp"

using ScopedTrackFeatures = ScopedEntity<Database::TrackFeatures>;

using namespace Database;

TEST_F(DatabaseFixture, TrackFeatures)
{
	ScopedTrack track {session, "MyTrack"};
	ScopedUser user {session, "MyUser"};

	{
		auto transaction {session.createSharedTransaction()};
		EXPECT_EQ(TrackFeatures::getCount(session), 0);
	}

	ScopedTrackFeatures trackFeatures {session, track.lockAndGet(), ""};

	{
		auto transaction {session.createUniqueTransaction()};
		EXPECT_EQ(TrackFeatures::getCount(session), 1);

		auto allTrackFeatures {TrackFeatures::find(session, Range {})};
		ASSERT_EQ(allTrackFeatures.results.size(), 1);
		EXPECT_EQ(allTrackFeatures.results.front(), trackFeatures.getId());
	}
}
