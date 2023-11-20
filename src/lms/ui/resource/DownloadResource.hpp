

#pragma once

#include <memory>
#include <Wt/WResource.h>

#include "services/database/ArtistId.hpp"
#include "services/database/ReleaseId.hpp"
#include "services/database/TrackId.hpp"
#include "services/database/TrackListId.hpp"
#include "utils/IZipper.hpp"
#include "utils/ZipperResourceHandlerCreator.hpp"

namespace UserInterface
{
	class DownloadResource : public Wt::WResource
	{
		public:
			static constexpr std::size_t bufferSize {32768};

			~DownloadResource();

		private:
			void handleRequest(const Wt::Http::Request& request, Wt::Http::Response& response) override;
			virtual std::unique_ptr<Zip::IZipper> createZipper() = 0;
	};

	class DownloadArtistResource : public DownloadResource
	{
		public:
			DownloadArtistResource(Database::ArtistId artistId);

		private:
			std::unique_ptr<Zip::IZipper> createZipper() override;
			Database::ArtistId _artistId;
	};

	class DownloadReleaseResource : public DownloadResource
	{
		public:
			DownloadReleaseResource(Database::ReleaseId releaseId);

		private:
			std::unique_ptr<Zip::IZipper> createZipper() override;
			Database::ReleaseId _releaseId;
	};

	class DownloadTrackResource : public DownloadResource
	{
		public:
			DownloadTrackResource(Database::TrackId trackId);

		private:
			std::unique_ptr<Zip::IZipper> createZipper() override;
			Database::TrackId _trackId;
	};

	class DownloadTrackListResource : public DownloadResource
	{
		public:
			DownloadTrackListResource(Database::TrackListId trackListId);

		private:
			std::unique_ptr<Zip::IZipper> createZipper() override;
			Database::TrackListId _trackListId;
	};
} // namespace UserInterface

