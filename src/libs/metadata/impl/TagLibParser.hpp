

#pragma once

#include <taglib/audioproperties.h>
#include "metadata/IParser.hpp"

namespace TagLib
{
	class StringList;
}

namespace MetaData
{

// Parse that makes use of AvFormat
class TagLibParser : public IParser
{
	public:
		TagLibParser(ParserReadStyle readStyle);

	private:
		std::optional<Track> parse(const std::filesystem::path& p, bool debug = false) override;
		void processTag(Track& track, const std::string& tag, const std::vector<std::string>& values, bool debug);

		const TagLib::AudioProperties::ReadStyle _readStyle;
};

} // namespace MetaData

