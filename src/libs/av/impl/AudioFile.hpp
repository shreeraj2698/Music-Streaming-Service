

/* This file contains some classes in order to get info from file using the libavconv */

#pragma once

#include "av/IAudioFile.hpp"

struct AVFormatContext;

namespace Av
{

	class AudioFile final : public IAudioFile
	{
		public:
			AudioFile(const std::filesystem::path& p);
			~AudioFile();

			AudioFile(const AudioFile&) = delete;
			AudioFile(AudioFile&&) = delete;
			AudioFile& operator=(const AudioFile&) = delete;
			AudioFile& operator=(AudioFile&&) = delete;

			const std::filesystem::path&		getPath() const override;
			std::chrono::milliseconds			getDuration() const override;
			MetadataMap							getMetaData() const override;
			std::vector<StreamInfo>				getStreamInfo() const override;
			std::optional<StreamInfo>			getBestStreamInfo() const override;
			std::optional<std::size_t>			getBestStreamIndex() const override;
			bool								hasAttachedPictures() const override;
			void								visitAttachedPictures(std::function<void(const Picture&)> func) const override;

		private:
			std::optional<StreamInfo>			getStreamInfo(std::size_t streamIndex) const;

			const std::filesystem::path	_p;
			AVFormatContext* _context {};
	};

} // namespace Av

