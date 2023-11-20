

#include "JPEGImage.hpp"

#include "RawImage.hpp"
#include "image/Exception.hpp"
#include "utils/Logger.hpp"

namespace Image::GraphicsMagick
{
	JPEGImage::JPEGImage(const RawImage& rawImage, unsigned quality)
	{
		try
		{
			Magick::Image image {rawImage.getMagickImage()};
			image.magick("JPEG");
			image.quality(quality);
			image.write(&_blob);
		}
		catch (Magick::Exception& e)
		{
			LMS_LOG(COVER, ERROR) << "Caught Magick exception: " << e.what();
			throw ImageException {std::string {"Magick read error: "} + e.what()};
		}
	}

	const std::byte*
	JPEGImage::getData() const
	{
		return reinterpret_cast<const std::byte*>(_blob.data());
	}

	std::size_t
	JPEGImage::getDataSize() const
	{
		return _blob.length();
	}
}
