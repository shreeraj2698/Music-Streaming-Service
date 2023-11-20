

#pragma once

#include <Wt/Http/Request.h>
#include <Wt/Http/Response.h>

// Helper class to serve a resource (must be saved as continuation data if not complete)
class IResourceHandler
{
	public:
		virtual ~IResourceHandler() = default;

		[[nodiscard]] virtual Wt::Http::ResponseContinuation* processRequest(const Wt::Http::Request& request, Wt::Http::Response& response) = 0;
		virtual void abort() = 0;
};

