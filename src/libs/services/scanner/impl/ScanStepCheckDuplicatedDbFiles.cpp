

#include "ScanStepCheckDuplicatedDbFiles.hpp"

#include "services/database/Db.hpp"
#include "services/database/Session.hpp"
#include "services/database/Track.hpp"
#include "utils/Logger.hpp"

namespace Scanner
{
	void
	ScanStepCheckDuplicatedDbFiles::process(ScanContext& context)
	{
		using namespace Database;

		if (_abortScan)
			return;

		Session& session {_db.getTLSSession()};
		auto transaction {session.createSharedTransaction()};

		const RangeResults<TrackId> tracks = Track::findTrackMBIDDuplicates(session, Range {});
		for (const TrackId trackId : tracks.results)
		{
			const Track::pointer track {Track::find(session, trackId)};
			if (auto trackMBID {track->getTrackMBID()})
			{
				LMS_LOG(DBUPDATER, INFO) << "Found duplicated track MBID [" << trackMBID->getAsString() << "], file: " << track->getPath().string() << " - " << track->getName();
				context.stats.duplicates.emplace_back(ScanDuplicate {track->getId(), DuplicateReason::SameTrackMBID});
				context.currentStepStats.processedElems++;
				_progressCallback(context.currentStepStats);
			}
		}

		LMS_LOG(DBUPDATER, DEBUG) << "Found " << context.currentStepStats.processedElems << " duplicated audio files";
	}
}
