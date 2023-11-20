

#pragma once

#include <Wt/WResource.h>

#include "services/database/TrackId.hpp"

namespace UserInterface
{
	class AudioFileResource : public Wt::WResource
	{
		public:
			~AudioFileResource();

			std::string getUrl(Database::TrackId trackId) const;

		private:
			void handleRequest(const Wt::Http::Request& request,
					Wt::Http::Response& response) override;
	};
} // namespace UserInterface
