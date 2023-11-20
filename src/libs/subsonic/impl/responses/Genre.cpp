

#include "responses/Genre.hpp"

#include "services/database/Cluster.hpp"

namespace API::Subsonic
{
    Response::Node createGenreNode(const Database::Cluster::pointer& cluster)
    {
        Response::Node clusterNode;

        clusterNode.setValue(cluster->getName());
        clusterNode.setAttribute("songCount", cluster->getTracksCount());
        clusterNode.setAttribute("albumCount", cluster->getReleasesCount());

        return clusterNode;
    }
}