

#include "metadata/IParser.hpp"

#include "utils/Exception.hpp"
#include "utils/Logger.hpp"

#include "AvFormatParser.hpp"
#include "TagLibParser.hpp"
#include "Utils.hpp"

namespace MetaData
{
	std::unique_ptr<IParser>
	createParser(ParserType parserType, ParserReadStyle parserReadStyle)
	{
		switch (parserType)
		{
			case ParserType::TagLib:
				LMS_LOG(METADATA, INFO) << "Creating TagLib parser with read style = " << Utils::readStyleToString(parserReadStyle);
				return std::make_unique<TagLibParser>(parserReadStyle);
			case ParserType::AvFormat:
				LMS_LOG(METADATA, INFO) << "Creating AvFormat parser";
				return std::make_unique<AvFormatParser>();
		}

		throw LmsException {"Unhandled parser type"};
	}
}

