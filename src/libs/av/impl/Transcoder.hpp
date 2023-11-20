

#pragma once

#include <filesystem>
#include <functional>

#include "av/TranscodeParameters.hpp"
#include "av/Types.hpp"

class IChildProcess;

namespace Av
{
	class Transcoder
	{
		public:
			Transcoder(const InputFileParameters& inputFileParameters, const TranscodeParameters& transcodeParameters);
			~Transcoder();

			Transcoder(const Transcoder&) = delete;
			Transcoder& operator=(const Transcoder&) = delete;
			Transcoder(Transcoder&&) = delete;
			Transcoder& operator=(Transcoder&&) = delete;

			// non blocking calls
			using ReadCallback = std::function<void(std::size_t nbReadBytes)>;
			void			asyncRead(std::byte* buffer, std::size_t bufferSize, ReadCallback);
			std::size_t		readSome(std::byte* buffer, std::size_t bufferSize);

			const std::string&	getOutputMimeType() const { return _outputMimeType; }
			const TranscodeParameters& getParameters() const { return _transcodeParameters; }

			bool			finished() const;

		private:
			static void init();

			void start();

			const std::size_t			_debugId {};
			const InputFileParameters	_inputFileParameters;
			const TranscodeParameters	_transcodeParameters;

			std::unique_ptr<IChildProcess>	_childProcess;

			std::string		_outputMimeType;
	};

} // namespace Av

