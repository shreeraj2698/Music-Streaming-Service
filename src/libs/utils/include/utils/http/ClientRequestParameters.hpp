

#pragma once

#include <functional>
#include <string_view>
#include <vector>

#include <Wt/Http/Message.h>

namespace Http
{
	struct ClientRequestParameters
	{
		enum class Priority
		{
			High,
			Normal,
			Low,
		};

		Priority	priority {Priority::Normal};
		std::string relativeUrl; // relative to baseUrl used by the client

		using OnSuccessFunc = std::function<void(std::string_view msgBody)>;
		OnSuccessFunc onSuccessFunc;

		using OnFailureFunc = std::function<void()>;
		OnFailureFunc onFailureFunc;
	};

	struct ClientGETRequestParameters final : public ClientRequestParameters
	{
		std::vector<Wt::Http::Message::Header> headers;
	};

	struct ClientPOSTRequestParameters final : public ClientRequestParameters
	{
		Wt::Http::Message message;
	};

} // namespace Http

