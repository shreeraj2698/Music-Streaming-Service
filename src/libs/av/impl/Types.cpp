

#include "av/Types.hpp"

namespace Av
{

	std::string_view
	formatToMimetype(Format format)
	{
		switch (format)
		{
			case Format::MP3: 			return "audio/mpeg";
			case Format::OGG_OPUS:		return "audio/opus";
			case Format::MATROSKA_OPUS:	return "audio/x-matroska";
			case Format::OGG_VORBIS:	return "audio/ogg";
			case Format::WEBM_VORBIS:	return "audio/webm";
		}

		throw Exception {"Invalid encoding"};
	}

}

