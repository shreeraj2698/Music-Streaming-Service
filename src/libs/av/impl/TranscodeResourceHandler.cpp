

#include "TranscodeResourceHandler.hpp"
#include "utils/Logger.hpp"

namespace Av
{
	namespace
	{
		std::size_t
		doEstimateContentLength(const InputFileParameters& inputFileParameters, const TranscodeParameters& transcodeParameters)
		{
			const std::size_t estimatedContentLength {transcodeParameters.bitrate / 8 * static_cast<std::size_t>(std::chrono::duration_cast<std::chrono::milliseconds>(inputFileParameters.duration).count()) / 1000};
			return estimatedContentLength;
		}
	}

	std::unique_ptr<IResourceHandler>
	createTranscodeResourceHandler(const InputFileParameters& inputFileParameters, const TranscodeParameters& transcodeParameters, bool estimateContentLength)
	{
		return std::make_unique<TranscodeResourceHandler>(inputFileParameters, transcodeParameters, estimateContentLength);
	}

	// TODO set some nice HTTP return code

	TranscodeResourceHandler::TranscodeResourceHandler(const InputFileParameters& inputFileParameters, const TranscodeParameters& transcodeParameters, bool estimateContentLength)
		: _estimatedContentLength {estimateContentLength ? std::make_optional(doEstimateContentLength(inputFileParameters, transcodeParameters)) : std::nullopt}
		, _transcoder {inputFileParameters, transcodeParameters}
	{
		if (_estimatedContentLength)
			LMS_LOG(TRANSCODE, DEBUG) << "Estimated content length = " << *_estimatedContentLength;
		else
			LMS_LOG(TRANSCODE, DEBUG) << "Not using estimated content length";
	}

	Wt::Http::ResponseContinuation*
	TranscodeResourceHandler::processRequest(const Wt::Http::Request& /*request*/, Wt::Http::Response& response)
	{
		if (_estimatedContentLength)
			response.setContentLength(*_estimatedContentLength);
		response.setMimeType(_transcoder.getOutputMimeType());
		LMS_LOG(TRANSCODE, DEBUG) << "Set mime type to " << _transcoder.getOutputMimeType();

		if (_bytesReadyCount > 0)
		{
			response.out().write(reinterpret_cast<const char *>(&_buffer[0]), _bytesReadyCount);
			_totalServedByteCount += _bytesReadyCount;
			_bytesReadyCount = 0;
		}

		if (!_transcoder.finished())
		{
			Wt::Http::ResponseContinuation *continuation {response.createContinuation()};
			continuation->waitForMoreData();
			_transcoder.asyncRead(_buffer.data(), _buffer.size(), [=](std::size_t nbBytesRead)
			{
				assert(_bytesReadyCount == 0);
				_bytesReadyCount = nbBytesRead;
				continuation->haveMoreData();
			});

			return continuation;
		}
		else
		{
			// pad with 0 if necessary as duration may not be accurate
			if (_estimatedContentLength && *_estimatedContentLength > _totalServedByteCount)
			{
				const std::size_t padSize {*_estimatedContentLength - _totalServedByteCount};

				LMS_LOG(TRANSCODE, DEBUG) << "Adding " << padSize << " padding bytes";

				for (std::size_t i {}; i < padSize; ++i)
					response.out().put(0);

				_totalServedByteCount += padSize;
			}

			LMS_LOG(TRANSCODE, DEBUG) << "Transcoding finished. Total served byte count = " << _totalServedByteCount;
		}

		return {};
	}
}

