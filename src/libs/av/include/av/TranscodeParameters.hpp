

#pragma once

#include <chrono>
#include <filesystem>
#include <optional>

#include "Types.hpp"

namespace Av
{
	struct InputFileParameters
	{
		std::filesystem::path trackPath;
		std::chrono::milliseconds duration;
	};

	struct TranscodeParameters
	{
		Format						format;
		std::size_t					bitrate {128000};
		std::optional<std::size_t>	stream; // Id of the stream to be transcoded (auto detect by default)
		std::chrono::milliseconds	offset {0};
		bool 						stripMetadata {true};
	};
} // namespace Av

