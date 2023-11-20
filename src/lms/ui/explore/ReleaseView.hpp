

#pragma once

#include "services/database/Object.hpp"
#include "services/database/ReleaseId.hpp"
#include "common/Template.hpp"

namespace Database
{
	class Release;
}

namespace UserInterface
{
	class Filters;
	class PlayQueueController;

	class Release : public Template
	{
		public:
			Release(Filters& filters, PlayQueueController& playQueueController);

		private:
			void refreshView();
			void refreshReleaseArtists(const Database::ObjectPtr<Database::Release>& release);
			void refreshCopyright(const Database::ObjectPtr<Database::Release>& release);
			void refreshLinks(const Database::ObjectPtr<Database::Release>& release);
			void refreshSimilarReleases(const std::vector<Database::ReleaseId>& similarReleasesId);

			Filters&				_filters;
			PlayQueueController&	_playQueueController;
			Database::ReleaseId		_releaseId;
			bool					_needForceRefresh {};
	};
} // namespace UserInterface

