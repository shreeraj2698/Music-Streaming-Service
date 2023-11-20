


#pragma once

#include <string_view>
#include <Wt/WDate.h>

#include "metadata/IParser.hpp"

namespace MetaData::Utils
{
	Wt::WDate parseDate(std::string_view dateStr);
	std::string_view readStyleToString(ParserReadStyle readStyle);

	struct PerformerArtist
	{
		Artist artist;
		std::string role;
	};

	// format is "artist name (role)"
	PerformerArtist extractPerformerAndRole(std::string_view entry);
}

namespace StringUtils
{
	template<>
	std::optional<MetaData::Release::PrimaryType> readAs(std::string_view str);

	template<>
	std::optional<MetaData::Release::SecondaryType> readAs(std::string_view str);
}

