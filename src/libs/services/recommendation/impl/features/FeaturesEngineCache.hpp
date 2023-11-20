

#pragma once

#include <filesystem>
#include <unordered_map>

#include "services/database/TrackId.hpp"
#include "som/Network.hpp"

namespace Recommendation {

class FeaturesEngineCache
{
	public:
		static void invalidate();

		static std::optional<FeaturesEngineCache> read();
		void write() const;

	private:
		using TrackPositions = std::unordered_map<Database::TrackId, std::vector<SOM::Position>>;

		FeaturesEngineCache(SOM::Network network, TrackPositions trackPositions);

		static std::optional<SOM::Network> createNetworkFromCacheFile(const std::filesystem::path& path);
		static std::optional<TrackPositions> createObjectPositionsFromCacheFile(const std::filesystem::path& path);
		static bool objectPositionToCacheFile(const TrackPositions& trackPositions, const std::filesystem::path& path);

		friend class FeaturesEngine;

		SOM::Network		_network;
		TrackPositions		_trackPositions;
};

} // namespace Recommendation
