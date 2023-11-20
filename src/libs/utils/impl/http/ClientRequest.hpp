

#pragma once

#include <memory>
#include <variant>
#include "utils/http/ClientRequestParameters.hpp"

namespace Http
{
	class ClientRequest
	{
		public:
			ClientRequest(ClientGETRequestParameters&& GETParams) : _parameters {std::move(GETParams)} {}
			ClientRequest(ClientPOSTRequestParameters&& POSTParams) : _parameters {std::move(POSTParams)} {}

			std::size_t retryCount {};

			const ClientRequestParameters& getParameters() const
			{
				const ClientRequestParameters* res;

				std::visit([&](const auto& parameters)
				{
					res = &static_cast<const ClientRequestParameters&>(parameters);
				}, _parameters);

				return *res;
			}


			enum class Type
			{
				GET,
				POST
			};
			Type getType() const
			{
				if (std::holds_alternative<ClientGETRequestParameters>(_parameters))
					return Type::GET;
				else
					return Type::POST;
			}

			const ClientGETRequestParameters& getGETParameters() const
			{
				return std::get<ClientGETRequestParameters>(_parameters);
			}

			const ClientPOSTRequestParameters& getPOSTParameters() const
			{
				return std::get<ClientPOSTRequestParameters>(_parameters);
			}

		private:
			std::variant<ClientGETRequestParameters, ClientPOSTRequestParameters> _parameters;
	};
}
