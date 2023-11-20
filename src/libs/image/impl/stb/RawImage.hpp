

#pragma once

#ifndef LMS_SUPPORT_IMAGE_STB
#error "Bad configuration"
#endif

#include <cstddef>
#include <filesystem>

#include "image/IEncodedImage.hpp"
#include "image/IRawImage.hpp"

namespace Image::STB
{
	class RawImage : public IRawImage
	{
		public:
			RawImage(const std::byte* encodedData, std::size_t encodedDataSize);
			RawImage(const std::filesystem::path& path);

			void resize(ImageSize width) override;
			std::unique_ptr<IEncodedImage> encodeToJPEG(unsigned quality) const override;

			ImageSize getWidth() const;
			ImageSize getHeight() const;
			const std::byte* getData() const;

		private:
			int _width;
			int _height;
			using UniquePtrFree = std::unique_ptr<unsigned char, decltype(&std::free)>;
			UniquePtrFree _data {nullptr, std::free};
	};
}

