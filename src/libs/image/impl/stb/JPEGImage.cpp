

#include "JPEGImage.hpp"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>

#include "image/Exception.hpp"
#include "RawImage.hpp"

namespace Image::STB
{
	JPEGImage::JPEGImage(const RawImage& rawImage, unsigned quality)
	{
		auto writeCb {[](void* ctx, void* writeData, int writeSize)
		{
			auto& output {*reinterpret_cast<std::vector<std::byte>*>(ctx)};
			const std::size_t currentOutputSize {output.size()};
			output.resize(currentOutputSize + writeSize);
			std::copy(reinterpret_cast<const std::byte*>(writeData), reinterpret_cast<const std::byte*>(writeData) + writeSize, output.data() + currentOutputSize);
		}};

		if (stbi_write_jpg_to_func(writeCb, &_data, rawImage.getWidth(), rawImage.getHeight(), 3, rawImage.getData(), quality) == 0)
		{
			_data.clear();
			throw ImageException {"Failed to export in jpeg format!"};
		}
	}

	const std::byte*
	JPEGImage::getData() const
	{
		if (_data.empty())
				return nullptr;

		return &_data.front();
	}

	std::size_t
	JPEGImage::getDataSize() const
	{
		return _data.size();
	}
}
