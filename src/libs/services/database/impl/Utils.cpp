

#include "Utils.hpp"

#include "utils/String.hpp"

namespace Database::Utils
{
	std::string
	escapeLikeKeyword(std::string_view keyword)
	{
		return StringUtils::escapeString(keyword, "%_", escapeChar);
	}

	Wt::WDateTime
	normalizeDateTime(const Wt::WDateTime& dateTime)
	{
		// force second resolution
		return Wt::WDateTime::fromTime_t(dateTime.toTime_t());
	}
} // namespace Database::Utils

