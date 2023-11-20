

#include "services/database/TrackFeatures.hpp"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "services/database/Session.hpp"
#include "services/database/Track.hpp"
#include "utils/Logger.hpp"
#include "IdTypeTraits.hpp"
#include "Utils.hpp"

namespace Database {

TrackFeatures::TrackFeatures(ObjectPtr<Track> track, const std::string& jsonEncodedFeatures)
: _data {jsonEncodedFeatures},
_track {getDboPtr(track)}
{
}

TrackFeatures::pointer
TrackFeatures::create(Session& session, ObjectPtr<Track> track, const std::string& jsonEncodedFeatures)
{
	return session.getDboSession().add(std::unique_ptr<TrackFeatures> {new TrackFeatures {track, jsonEncodedFeatures}});
}

std::size_t
TrackFeatures::getCount(Session& session)
{
	session.checkSharedLocked();

	return session.getDboSession().query<int>("SELECT COUNT(*) FROM track_features");
}

TrackFeatures::pointer
TrackFeatures::find(Session& session, TrackFeaturesId id)
{
	session.checkSharedLocked();

	return session.getDboSession().find<TrackFeatures>()
		.where("id = ?").bind(id)
		.resultValue();
}

TrackFeatures::pointer
TrackFeatures::find(Session& session, TrackId trackId)
{
	session.checkSharedLocked();

	return session.getDboSession().find<TrackFeatures>()
		.where("track_id = ?").bind(trackId)
		.resultValue();
}

RangeResults<TrackFeaturesId>
TrackFeatures::find(Session& session, Range range)
{
	session.checkSharedLocked();

	auto query {session.getDboSession().query<TrackFeaturesId>("SELECT id from track_features")};

	return Utils::execQuery(query, range);
}

FeatureValues
TrackFeatures::getFeatureValues(const FeatureName& featureNode) const
{
	FeatureValuesMap featuresValuesMap {getFeatureValuesMap({featureNode})};
	return std::move(featuresValuesMap[featureNode]);
}

FeatureValuesMap
TrackFeatures::getFeatureValuesMap(const std::unordered_set<FeatureName>& featureNames) const
{
	FeatureValuesMap res;

	try
	{
		std::istringstream iss {_data};
		boost::property_tree::ptree root;

		boost::property_tree::read_json(iss, root);

		for (const FeatureName& featureName : featureNames)
		{
			FeatureValues& featureValues {res[featureName]};

			auto node {root.get_child(featureName)};

			bool hasChildren = false;
			for (const auto& child : node.get_child(""))
			{
				hasChildren = true;
				featureValues.push_back(child.second.get_value<double>());
			}

			if (!hasChildren)
				featureValues.push_back(node.get_value<double>());
		}
	}
	catch (boost::property_tree::ptree_error& error)
	{
		LMS_LOG(DB, ERROR) << "Track " << _track.id() << ": ptree exception: " << error.what();
		res.clear();
	}

	return res;
}

} // namespace Database
