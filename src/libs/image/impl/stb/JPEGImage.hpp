

#pragma once

#include <vector>

#include "image/IEncodedImage.hpp"

namespace Image::STB
{
	class RawImage;
	class JPEGImage : public IEncodedImage
	{
		public:
			JPEGImage(const RawImage& rawImage, unsigned quality);

		private:
			const std::byte* getData() const override;
			std::size_t getDataSize() const override;
			std::string_view getMimeType() const override { return "image/jpeg"; }

			std::vector<std::byte> _data;
	};
}
