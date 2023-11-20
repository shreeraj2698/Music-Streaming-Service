

#pragma once

#ifndef LMS_SUPPORT_IMAGE_GM
#error "Bad configuration"
#endif

#include <Magick++.h>

#include "image/IEncodedImage.hpp"

namespace Image::GraphicsMagick
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

			Magick::Blob _blob;
	};
}
