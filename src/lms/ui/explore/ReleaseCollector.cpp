

#include "ReleaseCollector.hpp"

#include <algorithm>

#include "services/database/Release.hpp"
#include "services/database/Session.hpp"
#include "services/database/User.hpp"
#include "services/database/TrackList.hpp"
#include "services/scrobbling/IScrobblingService.hpp"
#include "utils/Service.hpp"
#include "Filters.hpp"
#include "LmsApplication.hpp"

namespace UserInterface
{
	using namespace Database;

	RangeResults<ReleaseId>
	ReleaseCollector::get(Database::Range range)
	{
		Scrobbling::IScrobblingService& scrobbling {*Service<Scrobbling::IScrobblingService>::get()};

		range = getActualRange(range);

		RangeResults<ReleaseId> releases;
		switch (getMode())
		{
			case Mode::Random:
				releases = getRandomReleases(range);
				break;

			case Mode::Starred:
				releases = scrobbling.getStarredReleases(LmsApp->getUserId(), getFilters().getClusterIds(), range);
				break;

			case ReleaseCollector::Mode::RecentlyPlayed:
				releases = scrobbling.getRecentReleases(LmsApp->getUserId(), getFilters().getClusterIds(), range);
				break;

			case Mode::MostPlayed:
				releases = scrobbling.getTopReleases(LmsApp->getUserId(), getFilters().getClusterIds(), range);
				break;

			case Mode::RecentlyAdded:
			{
				Release::FindParameters params;
				params.setClusters(getFilters().getClusterIds());
				params.setSortMethod(ReleaseSortMethod::LastWritten);
				params.setRange(range);

				{
					auto transaction {LmsApp->getDbSession().createSharedTransaction()};
					releases = Release::find(LmsApp->getDbSession(), params);
				}
				break;
			}

			case Mode::Search:
			{
				Release::FindParameters params;
				params.setClusters(getFilters().getClusterIds());
				params.setKeywords(getSearchKeywords());
				params.setSortMethod(ReleaseSortMethod::Name);
				params.setRange(range);

				{
					auto transaction {LmsApp->getDbSession().createSharedTransaction()};
					releases = Release::find(LmsApp->getDbSession(), params);
				}
				break;
			}

			case Mode::All:
			{
				Release::FindParameters params;
				params.setClusters(getFilters().getClusterIds());
				params.setSortMethod(ReleaseSortMethod::Name);
				params.setRange(range);

				{
					auto transaction {LmsApp->getDbSession().createSharedTransaction()};
					releases = Release::find(LmsApp->getDbSession(), params);
				}
				break;
			}
		}

		if (range.offset + range.size == getMaxCount())
			releases.moreResults = false;

		return releases;
	}

	RangeResults<ReleaseId>
	ReleaseCollector::getRandomReleases(Range range)
	{
		assert(getMode() == Mode::Random);

		if (!_randomReleases)
		{
			Release::FindParameters params;
			params.setClusters(getFilters().getClusterIds());
			params.setSortMethod(ReleaseSortMethod::Random);
			params.setRange({0, getMaxCount()});

			{
				auto transaction {LmsApp->getDbSession().createSharedTransaction()};
				_randomReleases = Release::find(LmsApp->getDbSession(), params);
			}
		}

		return _randomReleases->getSubRange(range);
	}

} // ns UserInterface

