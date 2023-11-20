

#include "utils/UUID.hpp"

#include <regex>

#include "utils/String.hpp"

namespace StringUtils
{
	template <>
	std::optional<UUID>
	readAs(std::string_view str)
	{
		return UUID::fromString(str);
	}
}

static
bool
stringIsUUID(std::string_view str)
{
	static const std::regex re { R"([0-9a-fA-F]{8}\-[0-9a-fA-F]{4}\-[0-9a-fA-F]{4}\-[0-9a-fA-F]{4}\-[0-9a-fA-F]{12})"};

	return std::regex_match(std::cbegin(str), std::cend(str), re);
}

UUID::UUID(std::string_view str)
	: _value {StringUtils::stringToLower(str)}
{
}

std::optional<UUID>
UUID::fromString(std::string_view str)
{
	if (!stringIsUUID(str))
		return std::nullopt;

	return UUID {str};
}

