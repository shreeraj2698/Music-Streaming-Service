

#pragma once

#include "RequestContext.hpp"
#include "SubsonicResponse.hpp"

namespace API::Subsonic
{
    Response handleGetAlbumListRequest(RequestContext& context);
    Response handleGetAlbumList2Request(RequestContext& context);
    Response handleGetRandomSongsRequest(RequestContext& context);
    Response handleGetSongsByGenreRequest(RequestContext& context);
    Response handleGetStarredRequest(RequestContext& context);
    Response handleGetStarred2Request(RequestContext& context);
}
