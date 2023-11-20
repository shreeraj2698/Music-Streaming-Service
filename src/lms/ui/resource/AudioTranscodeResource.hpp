

#pragma once

#include <Wt/Dbo/ptr.h>
#include <Wt/WResource.h>

#include "services/database/TrackId.hpp"

namespace Database
{
	class User;
}

namespace UserInterface
{
	class AudioTranscodeResource : public Wt::WResource
	{
		public:
			~AudioTranscodeResource();

			// Url depends on the user since settings are used in parameters
			std::string getUrl(Database::TrackId trackId) const;

			void handleRequest(const Wt::Http::Request& request, Wt::Http::Response& response);

		private:
			static constexpr std::size_t	_chunkSize {262144};
	};
} // namespace UserInterface




