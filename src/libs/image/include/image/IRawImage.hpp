

#pragma once

#include <filesystem>
#include <memory>

#include "image/IEncodedImage.hpp"

namespace Image
{
	class IRawImage
	{
		public:
			virtual ~IRawImage() = default;
			virtual void resize(ImageSize width) = 0;
			virtual std::unique_ptr<IEncodedImage> encodeToJPEG(unsigned quality) const = 0;
	};

	void init(const std::filesystem::path& path);
	std::unique_ptr<IRawImage> decodeImage(const std::byte* encodedData, std::size_t encodedDataSize);
	std::unique_ptr<IRawImage> decodeImage(const std::filesystem::path& path);
}

