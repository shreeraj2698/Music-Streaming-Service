
#pragma once

#include <cstddef>
#include <functional>
#include <string>
#include <vector>

#include "utils/Exception.hpp"

class ChildProcessException : public LmsException
{
	public:
		using LmsException::LmsException;
};

class IChildProcess
{
	public:
		using Args = std::vector<std::string>;

		virtual ~IChildProcess() = default;

		enum class ReadResult
		{
			Success,
			Error,
			EndOfFile,
		};

		using ReadCallback = std::function<void(ReadResult, std::size_t)>;
		virtual void		asyncRead(std::byte* data, std::size_t bufferSize, ReadCallback callback) = 0;

		virtual std::size_t	readSome(std::byte* data, std::size_t bufferSize) = 0;
		virtual bool		finished() const = 0;
};

