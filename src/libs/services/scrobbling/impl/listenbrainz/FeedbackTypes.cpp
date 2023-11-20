

#include "FeedbackTypes.hpp"

namespace Scrobbling::ListenBrainz
{
	std::ostream&
	operator<<(std::ostream& os, const Feedback& feedback)
	{
		os << "created = '" << feedback.created.toString() << "', recording MBID = '" << feedback.recordingMBID.getAsString() << "', score = " << static_cast<int>(feedback.score);
		return os;
	}
} // Scrobbling::ListenBrainz
