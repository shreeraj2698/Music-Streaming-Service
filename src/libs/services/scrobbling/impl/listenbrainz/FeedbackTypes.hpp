

#pragma once

#include <ostream>
#include <Wt/WDateTime.h>
#include "utils/UUID.hpp"

namespace Scrobbling::ListenBrainz
{
	// See https://listenbrainz.readthedocs.io/en/production/dev/feedback-json/#feedback-json-doc
	enum class FeedbackType
	{
		Love = 1,
		Hate = -1,
		Erase = 0,
	};

	struct Feedback
	{
		Wt::WDateTime	created;
		UUID			recordingMBID;
		FeedbackType	score;
	};

	std::ostream& operator<<(std::ostream& os, const Feedback& feedback);

} // Scrobbling::ListenBrainz
