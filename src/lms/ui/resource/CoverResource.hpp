

#pragma once

#include <Wt/WResource.h>
#include "services/database/ReleaseId.hpp"
#include "services/database/TrackId.hpp"

namespace UserInterface
{
	class CoverResource : public Wt::WResource
	{
		public:
			static const std::size_t maxSize {512};

			CoverResource();
			~CoverResource();

			enum class Size : std::size_t
			{
				Small = 128,
				Large = 512,
			};

			std::string getReleaseUrl(Database::ReleaseId releaseId, Size size) const;
			std::string getTrackUrl(Database::TrackId trackId, Size size) const;

		private:
			void handleRequest(const Wt::Http::Request& request, Wt::Http::Response& response) override;
	};
} // namespace UserInterface

