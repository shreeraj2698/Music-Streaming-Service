

#pragma once

#include <chrono>
#include <string>
#include <string_view>

#include <Wt/WContainerWidget.h>
#include <Wt/WImage.h>
#include <Wt/WInteractWidget.h>

#include "services/database/ArtistId.hpp"
#include "services/database/ClusterId.hpp"
#include "services/database/Object.hpp"
#include "services/database/ReleaseId.hpp"
#include "services/database/TrackId.hpp"

#include "resource/CoverResource.hpp"

namespace Database
{
	class Artist;
	class Cluster;
	class Release;
	class Track;
	class TrackList;
}

namespace UserInterface
{
	class Filters;
}

namespace UserInterface::Utils
{
	std::string durationToString(std::chrono::milliseconds msDuration);

	std::unique_ptr<Wt::WImage> createCover(Database::ReleaseId releaseId, CoverResource::Size size);
	std::unique_ptr<Wt::WImage> createCover(Database::TrackId trackId, CoverResource::Size size);

	std::unique_ptr<Wt::WInteractWidget> createCluster(Database::ClusterId clusterId, bool canDelete = false);

	std::unique_ptr<Wt::WContainerWidget> createArtistAnchorList(const std::vector<Database::ArtistId>& artistIds, std::string_view cssAnchorClass = "link-success");
	std::unique_ptr<Wt::WContainerWidget> createArtistDisplayNameWithAnchors(std::string_view displayName, const std::vector<Database::ArtistId>& artistIds, std::string_view cssAnchorClass = "link-success");
	std::unique_ptr<Wt::WContainerWidget> createArtistsAnchorsForRelease(Database::ObjectPtr<Database::Release> release, Database::ArtistId omitIfMatchThisArtist = {}, std::string_view cssAnchorClass = "link-success");

	Wt::WLink createArtistLink(Database::ObjectPtr<Database::Artist> artist);
	std::unique_ptr<Wt::WAnchor> createArtistAnchor(Database::ObjectPtr<Database::Artist> artist, bool setText = true);
	Wt::WLink createReleaseLink(Database::ObjectPtr<Database::Release> release);
	std::unique_ptr<Wt::WAnchor> createReleaseAnchor(Database::ObjectPtr<Database::Release> release, bool setText = true);
	std::unique_ptr<Wt::WAnchor> createTrackListAnchor(Database::ObjectPtr<Database::TrackList> trackList, bool setText = true);

	std::unique_ptr<Wt::WContainerWidget> createClustersForTrack(Database::ObjectPtr<Database::Track> track, Filters& filters);
}
