

#pragma once

#include "metadata/IParser.hpp"

namespace MetaData
{

// Parse that makes use of AvFormat
class AvFormatParser : public IParser
{
	public:
		std::optional<Track> parse(const std::filesystem::path& p, bool debug = false) override;
};

} // namespace MetaData

