

#include "responses/DiscTitle.hpp"

namespace API::Subsonic
{
    Response::Node createDiscTitle(const Database::DiscInfo& discInfo)
    {
        Response::Node discTitleNode;

        discTitleNode.setAttribute("disc", discInfo.position);
        discTitleNode.setAttribute("title", discInfo.name);

        return discTitleNode;
    }
}