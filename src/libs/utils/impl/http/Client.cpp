

#include "Client.hpp"
#include "utils/Exception.hpp"

namespace Http
{
	std::unique_ptr<IClient>
	createClient(boost::asio::io_context& ioContext, std::string_view baseUrl)
	{
		return std::make_unique<Client>(ioContext, baseUrl);
	}

	void
	Client::sendGETRequest(ClientGETRequestParameters&& GETParams)
	{
		_sendQueue.sendRequest(std::make_unique<ClientRequest>(std::move(GETParams)));
	}

	void
	Client::sendPOSTRequest(ClientPOSTRequestParameters&& POSTParams)
	{
		_sendQueue.sendRequest(std::make_unique<ClientRequest>(std::move(POSTParams)));
	}
} // namespace Http

