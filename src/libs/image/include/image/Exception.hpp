

#pragma once

#include "utils/Exception.hpp"

namespace Image
{
	// internal use only
	class ImageException : public LmsException
	{
		public:
			using LmsException::LmsException;
	};

} // namespace Cover

