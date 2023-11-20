
#include "ArtistListHelpers.hpp"

#include <Wt/WAnchor.h>

#include "services/database/Artist.hpp"
#include "services/database/Session.hpp"
#include "services/database/TrackArtistLink.hpp"
#include "utils/EnumSet.hpp"
#include "LmsApplication.hpp"
#include "Utils.hpp"

namespace UserInterface::ArtistListHelpers
{
	std::unique_ptr<Wt::WTemplate>
	createEntry(const Database::ObjectPtr<Database::Artist>& artist)
	{
		auto res {std::make_unique<Wt::WTemplate>(Wt::WString::tr("Lms.Explore.Artists.template.entry"))};
		res->bindWidget("name", Utils::createArtistAnchor(artist));

		return res;
	}

	std::unique_ptr<ArtistLinkTypesModel>
	createArtistLinkTypesModel()
	{
		using namespace Database;

		std::unique_ptr<ArtistLinkTypesModel> linkTypesModel {std::make_unique<ArtistLinkTypesModel>()};

		EnumSet<TrackArtistLinkType> usedLinkTypes;
		{
			auto transaction {LmsApp->getDbSession().createSharedTransaction()};
			usedLinkTypes = TrackArtistLink::findUsedTypes(LmsApp->getDbSession());
		}

		auto addTypeIfUsed {[&](TrackArtistLinkType linkType, std::string_view stringKey)
		{
			if (!usedLinkTypes.contains(linkType))
				return;

			linkTypesModel->add(Wt::WString::trn(std::string {stringKey}, 2), linkType);
		}};

		// add default one first (none)
		linkTypesModel->add(Wt::WString::tr("Lms.Explore.Artists.linktype-all"), std::nullopt);

		// TODO: sort by translated strings
		addTypeIfUsed(TrackArtistLinkType::Artist, "Lms.Explore.Artists.linktype-artist");
		addTypeIfUsed(TrackArtistLinkType::ReleaseArtist, "Lms.Explore.Artists.linktype-releaseartist");
		addTypeIfUsed(TrackArtistLinkType::Composer, "Lms.Explore.Artists.linktype-composer");
		addTypeIfUsed(TrackArtistLinkType::Conductor, "Lms.Explore.Artists.linktype-conductor");
		addTypeIfUsed(TrackArtistLinkType::Lyricist, "Lms.Explore.Artists.linktype-lyricist");
		addTypeIfUsed(TrackArtistLinkType::Mixer, "Lms.Explore.Artists.linktype-mixer");
		addTypeIfUsed(TrackArtistLinkType::Performer, "Lms.Explore.Artists.linktype-performer");
		addTypeIfUsed(TrackArtistLinkType::Producer, "Lms.Explore.Artists.linktype-producer");
		addTypeIfUsed(TrackArtistLinkType::Remixer, "Lms.Explore.Artists.linktype-remixer");

		return linkTypesModel;
	}
}

