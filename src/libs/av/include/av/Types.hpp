

#pragma once

#include <string_view>

#include "utils/Exception.hpp"

namespace Av {

	class Exception : public LmsException
	{
		public:
			using LmsException::LmsException;
	};

	enum class Format
	{
		MP3,
		OGG_OPUS,
		MATROSKA_OPUS,
		OGG_VORBIS,
		WEBM_VORBIS,
	};

	std::string_view formatToMimetype(Format format);
}

