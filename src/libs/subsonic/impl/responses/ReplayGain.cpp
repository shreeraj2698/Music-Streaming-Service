

#include "responses/ReplayGain.hpp"

#include "services/database/Track.hpp"

namespace API::Subsonic
{
    Response::Node createReplayGainNode(const Database::ObjectPtr<Database::Track>& track)
    {
        Response::Node replayGainNode;

        if (const auto trackReplayGain{ track->getTrackReplayGain() })
            replayGainNode.setAttribute("trackGain", *trackReplayGain);

        if (const auto releaseReplayGain{ track->getReleaseReplayGain() })
            replayGainNode.setAttribute("albumGain", *releaseReplayGain);

        return replayGainNode;
    }
}