

#pragma once

#include <cstddef>
#include <string_view>

namespace Image
{
	using ImageSize = std::size_t;

	class IEncodedImage
	{
		public:
			virtual ~IEncodedImage() = default;

			virtual const std::byte* getData() const = 0;
			virtual std::size_t getDataSize() const = 0;
			virtual std::string_view getMimeType() const = 0;
	};

} // namespace Cover

