

#include "RecommendationService.hpp"

#include <unordered_map>
#include <vector>

#include "ClustersEngineCreator.hpp"
#include "FeaturesEngineCreator.hpp"

#include "services/database/Db.hpp"
#include "services/database/Session.hpp"
#include "services/database/ScanSettings.hpp"
#include "utils/Exception.hpp"
#include "utils/Logger.hpp"

namespace Recommendation
{

	static
	std::string_view
	engineTypeToString(EngineType engineType)
	{
		switch (engineType)
		{
			case EngineType::Clusters: return "clusters";
			case EngineType::Features: return "features";
		}

		throw LmsException {"Internal error"};
	}

	std::unique_ptr<IRecommendationService>
	createRecommendationService(Database::Db& db)
	{
		return std::make_unique<RecommendationService>(db);
	}

	RecommendationService::RecommendationService(Database::Db& db)
		: _db {db}
	{
	}

	TrackContainer
	RecommendationService::findSimilarTracks(Database::TrackListId trackListId, std::size_t maxCount) const
	{
		TrackContainer res;

		std::shared_lock lock {_enginesMutex};
		for (const auto& engineType : _enginePriorities)
		{
			auto itEngine {_engines.find(engineType)};
			if (itEngine == std::cend(_engines))
				continue;

			res = itEngine->second->findSimilarTracksFromTrackList(trackListId, maxCount);
			if (!res.empty())
				break;
		}

		return res;
	}

	TrackContainer
	RecommendationService::findSimilarTracks(const std::vector<Database::TrackId>& trackIds, std::size_t maxCount) const
	{
		TrackContainer res;

		std::shared_lock lock {_enginesMutex};
		for (EngineType engineType : _enginePriorities)
		{
			auto itEngine {_engines.find(engineType)};
			if (itEngine == std::cend(_engines))
				continue;

			const IEngine& engine {*itEngine->second};
			res = engine.findSimilarTracks(trackIds, maxCount);
			if (!res.empty())
			{
				LMS_LOG(RECOMMENDATION, DEBUG) << "Got " << res.size() << " similar tracks using engine '" << engineTypeToString(engineType) << "'";
				break;
			}
		}

		return res;
	}

	ReleaseContainer
	RecommendationService::getSimilarReleases(Database::ReleaseId releaseId, std::size_t maxCount) const
	{
		ReleaseContainer res;

		std::shared_lock lock {_enginesMutex};
		for (EngineType engineType : _enginePriorities)
		{
			auto itEngine {_engines.find(engineType)};
			if (itEngine == std::cend(_engines))
				continue;

			const IEngine& engine {*itEngine->second};
			res = engine.getSimilarReleases(releaseId, maxCount);
			if (!res.empty())
			{
				LMS_LOG(RECOMMENDATION, DEBUG) << "Got " << res.size() << " similar releases using engine '" << engineTypeToString(engineType) << "'";
				break;
			}

			LMS_LOG(RECOMMENDATION, DEBUG) << "No result using engine '" << engineTypeToString(engineType) << "'";
		}

		return res;
	}

	ArtistContainer
	RecommendationService::getSimilarArtists(Database::ArtistId artistId, EnumSet<Database::TrackArtistLinkType> linkTypes, std::size_t maxCount) const
	{
		ArtistContainer res;

		std::shared_lock lock {_enginesMutex};
		for (EngineType engineType : _enginePriorities)
		{
			auto itEngine {_engines.find(engineType)};
			if (itEngine == std::cend(_engines))
				continue;

			LMS_LOG(RECOMMENDATION, DEBUG) << "Trying engine '" << engineTypeToString(engineType) << "'";

			const IEngine& engine {*itEngine->second};
			res = engine.getSimilarArtists(artistId, linkTypes, maxCount);
			if (!res.empty())
			{
				LMS_LOG(RECOMMENDATION, DEBUG) << "Got " << res.size() << " similar artists using engine '" << engineTypeToString(engineType) << "'";
				return res;
			}
		}

		return res;
	}

	static
	Database::ScanSettings::RecommendationEngineType
	getRecommendationEngineType(Database::Session& session)
	{
		auto transaction {session.createSharedTransaction()};

		return Database::ScanSettings::get(session)->getRecommendationEngineType();
	}

	void
	RecommendationService::load(bool forceReload, const ProgressCallback& progressCallback)
	{
		using namespace Database;

		LMS_LOG(RECOMMENDATION, INFO) << "Reloading recommendation engines...";

		EngineContainer enginesToLoad;

		{
			std::unique_lock controlLock {_controlMutex};

			{
				std::unique_lock lock {_enginesMutex};
				_engines.clear();
			}

			switch (getRecommendationEngineType(_db.getTLSSession()))
			{
				case ScanSettings::RecommendationEngineType::Clusters:
					_enginePriorities = {EngineType::Clusters};
					enginesToLoad.try_emplace(EngineType::Clusters, createClustersEngine(_db));
					break;

				case ScanSettings::RecommendationEngineType::Features:
					_enginePriorities = {EngineType::Features, EngineType::Clusters};

					// not same order since clusters is faster to load
					enginesToLoad.try_emplace(EngineType::Clusters, createClustersEngine(_db));
					enginesToLoad.try_emplace(EngineType::Features, createFeaturesEngine(_db));
					break;
			}

			assert(_pendingEngines.empty());
			for (auto& [engineType, engine] : enginesToLoad)
				_pendingEngines.push_back(engine.get());
		}

		for (auto& [engineType, engine] : enginesToLoad)
			loadPendingEngine(engineType, std::move(engine), forceReload, progressCallback);

		_pendingEnginesCondvar.notify_all();

		LMS_LOG(RECOMMENDATION, INFO) << "Recommendation engines loaded!";
	}

	void
	RecommendationService::loadPendingEngine(EngineType engineType, std::unique_ptr<IEngine> engine, bool forceReload, const ProgressCallback& progressCallback)
	{
		if (!_loadCancelled)
		{
			LMS_LOG(RECOMMENDATION, INFO) << "Initializing engine '" << engineTypeToString(engineType) << "'...";

			auto progress {[&](const Progress& progress)
			{
				progressCallback(progress);
			}};

			engine->load(forceReload, progressCallback ? progress : ProgressCallback {});

			LMS_LOG(RECOMMENDATION, INFO) << "Initializing engine '" << engineTypeToString(engineType) << "': " << (_loadCancelled ? "aborted" : "complete");
		}

		{
			std::scoped_lock lock {_controlMutex};
			_pendingEngines.erase(std::find(std::begin(_pendingEngines), std::end(_pendingEngines), engine.get()));
		}

		if (!_loadCancelled)
		{
			std::unique_lock lock {_enginesMutex};
			_engines.emplace(engineType, std::move(engine));
		}
	}

	void
	RecommendationService::cancelLoad()
	{
		LMS_LOG(RECOMMENDATION, DEBUG) << "Cancelling loading...";

		std::unique_lock controlLock {_controlMutex};

		assert(!_loadCancelled);
		_loadCancelled = true;

		LMS_LOG(RECOMMENDATION, DEBUG) << "Still " <<  _pendingEngines.size() << " pending engines!";

		for (IEngine* engine : _pendingEngines)
		{
			engine->requestCancelLoad();
		}

		_pendingEnginesCondvar.wait(controlLock, [this] {return _pendingEngines.empty();});
		_loadCancelled = false;

		LMS_LOG(RECOMMENDATION, DEBUG) << "Cancelling loading DONE";
	}

} // ns Similarity
