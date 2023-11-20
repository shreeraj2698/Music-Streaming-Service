

#pragma once

#include <stdexcept>
#include <string>
#include <string_view>

class LmsException : public std::runtime_error
{
	public:
		LmsException(std::string_view error = "") : std::runtime_error {std::string {error}} {}
};

