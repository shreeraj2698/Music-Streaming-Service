

#include "responses/Contributor.hpp"

#include "services/database/Object.hpp"
#include "services/database/TrackArtistLink.hpp"
#include "SubsonicResponse.hpp"
#include "responses/Artist.hpp"

namespace API::Subsonic
{
    Response::Node createContributorNode(const Database::ObjectPtr<Database::TrackArtistLink>& trackArtistLink)
    {
        Response::Node contributorNode;

        contributorNode.setAttribute("role", Utils::toString(trackArtistLink->getType()));
        if (!trackArtistLink->getSubType().empty())
            contributorNode.setAttribute("subRole", trackArtistLink->getSubType());
        contributorNode.addChild("artist", createArtistNode(trackArtistLink->getArtist()));

        return contributorNode;
    }
}