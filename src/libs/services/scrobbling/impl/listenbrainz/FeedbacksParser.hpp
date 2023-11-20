

#pragma once

#include <string_view>

#include "FeedbackTypes.hpp"

namespace Scrobbling::ListenBrainz
{
	class FeedbacksParser
	{
		public:
			struct Result
			{
				std::size_t feedbackCount {}; // >= feedbacks.size()
				std::vector<Feedback> feedbacks;
			};

			static Result parse(std::string_view msgBody);
	};

} // Scrobbling::ListenBrainz
