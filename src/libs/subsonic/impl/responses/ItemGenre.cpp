

#include "responses/ItemGenre.hpp"

#include "services/database/Cluster.hpp"

namespace API::Subsonic
{
    Response::Node createItemGenreNode(std::string_view name)
    {
        Response::Node genreNode;

        genreNode.setAttribute("name", name);

        return genreNode;
    }
}