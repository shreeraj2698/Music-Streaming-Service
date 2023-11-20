

#pragma once

#include <optional>
#include <thread>
#include <boost/asio/io_service.hpp>

class IOContextRunner
{
	public:
		IOContextRunner(boost::asio::io_service& ioService, std::size_t threadCount);
		~IOContextRunner();

		IOContextRunner(const IOContextRunner&) = delete;
		IOContextRunner(IOContextRunner&&) = delete;
		IOContextRunner& operator=(const IOContextRunner&) = delete;
		IOContextRunner& operator=(IOContextRunner&&) = delete;

		void stop();

	private:
		boost::asio::io_service&		_ioService;
		std::optional<boost::asio::io_service::work>	_work;
		std::vector<std::thread>		_threads;
};
