

#pragma once

#include <optional>
#include <string>
#include <string_view>

#include "utils/String.hpp"

class UUID
{
	public:
		static std::optional<UUID> fromString(std::string_view str);

		std::string_view getAsString() const { return _value; }

	private:
		UUID(std::string_view value);
		std::string _value;
};

namespace StringUtils
{
	template <>
	std::optional<UUID>
	readAs(std::string_view str);
}

