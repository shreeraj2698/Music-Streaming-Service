

#pragma once

#include <array>
#include <filesystem>
#include <optional>

#include "av/TranscodeParameters.hpp"
#include "utils/IResourceHandler.hpp"
#include "Transcoder.hpp"

namespace Av
{
	class TranscodeResourceHandler final : public IResourceHandler
	{
		public:
			TranscodeResourceHandler(const InputFileParameters& inputFileParameters, const TranscodeParameters& parameters, bool estimateContentLength);

		private:
			Wt::Http::ResponseContinuation* processRequest(const Wt::Http::Request& request, Wt::Http::Response& reponse) override;
			void abort() override {};

			static constexpr std::size_t _chunkSize {32768};
			std::optional<std::size_t> _estimatedContentLength;
			std::array<std::byte, _chunkSize> _buffer;
			std::size_t _bytesReadyCount {};
			std::size_t _totalServedByteCount {};
			Transcoder _transcoder;
	};
}

