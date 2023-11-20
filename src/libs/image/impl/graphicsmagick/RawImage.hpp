

#pragma once

#ifndef LMS_SUPPORT_IMAGE_GM
#error "Bad configuration"
#endif

#include <Magick++.h>

#include <cstddef>
#include <filesystem>

#include "image/IEncodedImage.hpp"
#include "image/IRawImage.hpp"

namespace Image::GraphicsMagick
{
	class RawImage : public IRawImage
	{
		public:
			RawImage(const std::byte* encodedData, std::size_t encodedDataSize);
			RawImage(const std::filesystem::path& path);

			void resize(ImageSize width) override;
			std::unique_ptr<IEncodedImage> encodeToJPEG(unsigned quality) const override;

		private:
			friend class JPEGImage;
			Magick::Image getMagickImage() const;

			Magick::Image _image;
	};
}

