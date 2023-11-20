

#pragma once

#include <cstddef>
#include <sys/types.h>
#include <unistd.h>

#include <filesystem>
#include <optional>

#include <boost/asio/io_context.hpp>
#include <boost/asio/posix/stream_descriptor.hpp>

#include "utils/IChildProcess.hpp"


class ChildProcess : public IChildProcess
{
	public:
		~ChildProcess();
		ChildProcess(boost::asio::io_context& ioContext, const std::filesystem::path& path, const Args& args);

	private:
		void		asyncRead(std::byte* data, std::size_t bufferSize, ReadCallback callback) override;
		std::size_t	readSome(std::byte* data, std::size_t bufferSize) override;
		bool		finished() const override;

		void	kill();
		bool	wait(bool block); // return true if waited

		using FileDescriptor = boost::asio::posix::stream_descriptor;

		boost::asio::io_context&	_ioContext;
		FileDescriptor				_childStdout;
		::pid_t						_childPID {};
		bool						_waited {};
		bool						_finished {};
		std::optional<int>			_exitCode;
};
