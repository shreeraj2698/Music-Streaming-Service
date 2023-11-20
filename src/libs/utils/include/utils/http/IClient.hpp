

#pragma once

#include <string_view>
#include <boost/asio/io_context.hpp>

#include "utils/http/ClientRequestParameters.hpp"

namespace Http
{
	class IClient
	{
		public:
			virtual ~IClient() = default;

			virtual void sendGETRequest(ClientGETRequestParameters&& request) = 0;
			virtual void sendPOSTRequest(ClientPOSTRequestParameters&& request) = 0;
	};

	std::unique_ptr<IClient> createClient(boost::asio::io_context& ioContext, std::string_view baseUrl);
} // namespace Http

