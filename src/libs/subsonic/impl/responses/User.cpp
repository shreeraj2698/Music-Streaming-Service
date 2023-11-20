

#include "responses/User.hpp"

#include "services/database/User.hpp"

namespace API::Subsonic
{
    using namespace Database;

    Response::Node createUserNode(const User::pointer& user)
    {
        Response::Node userNode;

        userNode.setAttribute("username", user->getLoginName());
        userNode.setAttribute("scrobblingEnabled", true);
        userNode.setAttribute("adminRole", user->isAdmin());
        userNode.setAttribute("settingsRole", true);
        userNode.setAttribute("downloadRole", true);
        userNode.setAttribute("uploadRole", false);
        userNode.setAttribute("playlistRole", true);
        userNode.setAttribute("coverArtRole", false);
        userNode.setAttribute("commentRole", false);
        userNode.setAttribute("podcastRole", false);
        userNode.setAttribute("streamRole", true);
        userNode.setAttribute("jukeboxRole", false);
        userNode.setAttribute("shareRole", false);

        Response::Node folder;
        folder.setValue("0");
        userNode.addArrayChild("folder", std::move(folder));

        return userNode;
    }
}