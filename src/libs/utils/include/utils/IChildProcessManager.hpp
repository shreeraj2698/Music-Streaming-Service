
#pragma once

#include <filesystem>
#include <memory>
#include <boost/asio/io_service.hpp>

#include "IChildProcess.hpp"

class IChildProcessManager
{
	public:
		virtual ~IChildProcessManager() = default;

		virtual std::unique_ptr<IChildProcess> spawnChildProcess(const std::filesystem::path& path, const IChildProcess::Args& args) = 0;
};

std::unique_ptr<IChildProcessManager> createChildProcessManager(boost::asio::io_service& ioService);


