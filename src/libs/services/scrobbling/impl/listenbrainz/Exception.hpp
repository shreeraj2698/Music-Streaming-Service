

#pragma once

#include "services/scrobbling/Exception.hpp"

namespace Scrobbling::ListenBrainz
{
	class Exception : public Scrobbling::Exception
	{
		public:
			using Scrobbling::Exception::Exception;
	};
}
