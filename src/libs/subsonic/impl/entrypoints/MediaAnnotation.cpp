

#include "MediaAnnotation.hpp"

#include <vector>

#include "services/database/ArtistId.hpp"
#include "services/database/ReleaseId.hpp"
#include "services/database/TrackId.hpp"
#include "services/scrobbling/IScrobblingService.hpp"
#include "utils/Service.hpp"
#include "ParameterParsing.hpp"
#include "SubsonicId.hpp"

namespace API::Subsonic
{
    using namespace Database;

    namespace
    {
        struct StarParameters
        {
            std::vector<ArtistId> artistIds;
            std::vector<ReleaseId> releaseIds;
            std::vector<TrackId> trackIds;
        };

        StarParameters getStarParameters(const Wt::Http::ParameterMap& parameters)
        {
            StarParameters res;

            // TODO handle parameters for legacy file browsing
            res.trackIds = getMultiParametersAs<TrackId>(parameters, "id");
            res.artistIds = getMultiParametersAs<ArtistId>(parameters, "artistId");
            res.releaseIds = getMultiParametersAs<ReleaseId>(parameters, "albumId");

            return res;
        }
    }

    Response handleStarRequest(RequestContext& context)
    {
        StarParameters params{ getStarParameters(context.parameters) };

        for (const ArtistId id : params.artistIds)
            Service<Scrobbling::IScrobblingService>::get()->star(context.userId, id);

        for (const ReleaseId id : params.releaseIds)
            Service<Scrobbling::IScrobblingService>::get()->star(context.userId, id);

        for (const TrackId id : params.trackIds)
            Service<Scrobbling::IScrobblingService>::get()->star(context.userId, id);

        return Response::createOkResponse(context.serverProtocolVersion);
    }

    Response handleUnstarRequest(RequestContext& context)
    {
        StarParameters params{ getStarParameters(context.parameters) };

        for (const ArtistId id : params.artistIds)
            Service<Scrobbling::IScrobblingService>::get()->unstar(context.userId, id);

        for (const ReleaseId id : params.releaseIds)
            Service<Scrobbling::IScrobblingService>::get()->unstar(context.userId, id);

        for (const TrackId id : params.trackIds)
            Service<Scrobbling::IScrobblingService>::get()->unstar(context.userId, id);

        return Response::createOkResponse(context.serverProtocolVersion);
    }

    Response handleScrobble(RequestContext& context)
    {
        const std::vector<TrackId> ids{ getMandatoryMultiParametersAs<TrackId>(context.parameters, "id") };
        const std::vector<unsigned long> times{ getMultiParametersAs<unsigned long>(context.parameters, "time") };
        const bool submission{ getParameterAs<bool>(context.parameters, "submission").value_or(true) };

        // playing now => no time to be provided
        if (!submission && !times.empty())
            throw BadParameterGenericError{ "time" };

        // playing now => only one at a time
        if (!submission && ids.size() > 1)
            throw BadParameterGenericError{ "id" };

        // if multiple submissions, must have times
        if (ids.size() > 1 && ids.size() != times.size())
            throw BadParameterGenericError{ "time" };

        if (!submission)
        {
            Service<Scrobbling::IScrobblingService>::get()->listenStarted({ context.userId, ids.front() });
        }
        else
        {
            if (times.empty())
            {
                Service<Scrobbling::IScrobblingService>::get()->listenFinished({ context.userId, ids.front() });
            }
            else
            {
                for (std::size_t i{}; i < ids.size(); ++i)
                {
                    const TrackId trackId{ ids[i] };
                    const unsigned long time{ times[i] };
                    Service<Scrobbling::IScrobblingService>::get()->addTimedListen({ {context.userId, trackId}, Wt::WDateTime::fromTime_t(static_cast<std::time_t>(time / 1000)) });
                }
            }
        }

        return Response::createOkResponse(context.serverProtocolVersion);
    }
}