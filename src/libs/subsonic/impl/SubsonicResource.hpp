
#pragma once

#include <string>
#include <unordered_map>

#include <Wt/WResource.h>
#include <Wt/Http/Response.h>

#include "services/database/Types.hpp"
#include "ClientInfo.hpp"
#include "RequestContext.hpp"

namespace Database
{
    class Db;
}

namespace API::Subsonic
{

    class SubsonicResource final : public Wt::WResource
    {
        public:
            SubsonicResource(Database::Db& db);

        private:
            void handleRequest(const Wt::Http::Request &request, Wt::Http::Response &response) override;
            ProtocolVersion getServerProtocolVersion(const std::string& clientName) const;

            static void checkProtocolVersion(ProtocolVersion client, ProtocolVersion server);
            ClientInfo getClientInfo(const Wt::Http::ParameterMap& parameters);
            RequestContext buildRequestContext(const Wt::Http::Request& request);
            Database::UserId authenticateUser(const Wt::Http::Request& request, const ClientInfo& clientInfo);

            const std::unordered_map<std::string, ProtocolVersion> _serverProtocolVersionsByClient;
            Database::Db& _db;
    };

} // namespace
