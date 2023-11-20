

#include "FeedbacksParser.hpp"

#include <Wt/Json/Array.h>
#include <Wt/Json/Object.h>
#include <Wt/Json/Value.h>
#include <Wt/Json/Parser.h>

#include "services/scrobbling/Exception.hpp"
#include "Exception.hpp"
#include "Utils.hpp"

namespace Scrobbling::ListenBrainz
{
	namespace
	{
		Feedback
		parseFeedback(const Wt::Json::Object& feedbackObj)
		{
			const std::optional<UUID> recordingMBID {UUID::fromString(static_cast<std::string>(feedbackObj.get("recording_mbid")))};
			if (!recordingMBID)
				throw Exception {"MBID not found!"};

			return Feedback
			{
				Wt::WDateTime::fromTime_t(static_cast<int>(feedbackObj.get("created"))),
					*recordingMBID,
					static_cast<FeedbackType>(static_cast<int>(feedbackObj.get("score")))
			};
		}
	}

	FeedbacksParser::Result
	FeedbacksParser::parse(std::string_view msgBody)
	{
		Result res;

		try
		{
			Wt::Json::Object root;
			Wt::Json::parse(std::string {msgBody}, root);

			const Wt::Json::Array& feedbacks = root.get("feedback");

			LOG(DEBUG) << "Got " << feedbacks.size() << " feedbacks";

			if (feedbacks.empty())
				return res;

			res.feedbackCount = feedbacks.size();

			for (const Wt::Json::Value& value : feedbacks)
			{
				try
				{
					res.feedbacks.push_back(parseFeedback(value));
				}
				catch (const Exception& e)
				{
					LOG(DEBUG) << "Cannot parse feedback: " << e.what() << ", skipping";
				}
				catch (const Wt::WException &e)
				{
					LOG(DEBUG) << "Cannot parse feedback: " << e.what() << ", skipping";
				}
			}
		}
		catch (const Wt::WException& error)
		{
			LOG(ERROR) << "Cannot parse 'feedback' result: " << error.what();
		}

		return res;
	}
} // Scrobbling::ListenBrainz
