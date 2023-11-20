

#pragma once

#include <filesystem>
#include <memory>

#include "services/database/ReleaseId.hpp"
#include "services/database/TrackId.hpp"
#include "image/IEncodedImage.hpp"

namespace Database
{
	class Db;
}

namespace Cover
{
	class ICoverService
	{
		public:
			virtual ~ICoverService() = default;

			virtual std::shared_ptr<Image::IEncodedImage>	getFromTrack(Database::TrackId trackId, Image::ImageSize width) = 0;
			virtual std::shared_ptr<Image::IEncodedImage>	getFromRelease(Database::ReleaseId releaseId, Image::ImageSize width) = 0;

			virtual void flushCache() = 0;

			virtual void setJpegQuality(unsigned quality) = 0; // from 1 to 100
	};

	std::unique_ptr<ICoverService> createCoverService(Database::Db& db,
										const std::filesystem::path& execPath,
										const std::filesystem::path& defaultCoverPath);

} // namespace CoverArt

