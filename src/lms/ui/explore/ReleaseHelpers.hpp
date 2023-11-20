

#pragma once

#include <memory>
#include <optional>

#include <Wt/WString.h>
#include <Wt/WTemplate.h>
#include <Wt/WDate.h>
#include "services/database/Object.hpp"
#include "services/database/Types.hpp"
#include "utils/EnumSet.hpp"

namespace Database
{
    class Artist;
    class Release;
}

namespace UserInterface::ReleaseListHelpers
{
    std::unique_ptr<Wt::WTemplate> createEntry(const Database::ObjectPtr<Database::Release>& release);
    std::unique_ptr<Wt::WTemplate> createEntryForArtist(const Database::ObjectPtr<Database::Release>& release, const Database::ObjectPtr<Database::Artist>& artist);
} // namespace UserInterface

namespace UserInterface::ReleaseHelpers
{
    Wt::WString buildReleaseTypeString(Database::ReleaseTypePrimary primaryType, EnumSet<Database::ReleaseTypeSecondary> secondaryTypes);
    Wt::WString buildReleaseYearString(const Wt::WDate& releaseDate, const Wt::WDate& originalReleaseDate);
}
