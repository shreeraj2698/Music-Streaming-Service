

#pragma once

#include <memory>

#include <Wt/WTemplate.h>

#include "common/ValueStringModel.hpp"
#include "services/database/Object.hpp"
#include "services/database/Types.hpp"

namespace Database
{
	class Artist;
}

namespace UserInterface
{
	using ArtistLinkTypesModel = ValueStringModel<std::optional<Database::TrackArtistLinkType>>;

	namespace ArtistListHelpers
	{
		std::unique_ptr<Wt::WTemplate> createEntry(const Database::ObjectPtr<Database::Artist>& artist);
		std::unique_ptr<ArtistLinkTypesModel> createArtistLinkTypesModel();
	}
}

