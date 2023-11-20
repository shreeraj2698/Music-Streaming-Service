

#pragma once

#include <memory>

#include "utils/IResourceHandler.hpp"

namespace Av
{
	struct InputFileParameters;
	struct TranscodeParameters;

	std::unique_ptr<IResourceHandler> createTranscodeResourceHandler(const InputFileParameters& inputFileParameters, const TranscodeParameters& parameters, bool estimateContentLength);
}

