

#pragma once

#include <unordered_map>
#include <string>
#include <shared_mutex>

#include "utils/http/IClient.hpp"
#include "SendQueue.hpp"

namespace Http
{
	class Client final : public IClient
	{
		public:
			Client(boost::asio::io_context& ioContext, std::string_view baseUrl)
			: _sendQueue {ioContext, baseUrl}
			{}

		private:
			void sendGETRequest(ClientGETRequestParameters&& request) override;
			void sendPOSTRequest(ClientPOSTRequestParameters&& request) override;

			SendQueue					_sendQueue;
	};
} // namespace Http

