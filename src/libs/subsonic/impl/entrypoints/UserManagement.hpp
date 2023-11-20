

#pragma once

#include "RequestContext.hpp"
#include "SubsonicResponse.hpp"

namespace API::Subsonic
{
    Response handleGetUserRequest(RequestContext& context);
    Response handleGetUsersRequest(RequestContext& context);
    Response handleCreateUserRequest(RequestContext& context);
    Response handleUpdateUserRequest(RequestContext& context);
    Response handleDeleteUserRequest(RequestContext& context);
    Response handleChangePassword(RequestContext& context);
}
