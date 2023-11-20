

#include "utils/IOContextRunner.hpp"

#include <cstdlib>

#include "utils/Logger.hpp"

IOContextRunner::IOContextRunner(boost::asio::io_service& ioService, std::size_t threadCount)
: _ioService {ioService}
, _work {ioService}
{
	LMS_LOG(UTILS, INFO) << "Starting IO context with " << threadCount << " threads...";
	for (std::size_t i {}; i < threadCount; ++i)
	{
		_threads.emplace_back([&]
		{
			try
			{
				_ioService.run();
			}
			catch (const std::exception& e)
			{
				LMS_LOG(UTILS, FATAL) << "Exception caught in IO context: " << e.what();
				std::abort();
			}
		});
	}
}

void
IOContextRunner::stop()
{
	LMS_LOG(UTILS, DEBUG) << "Stopping IO context...";
	_work.reset();
	_ioService.stop();
	LMS_LOG(UTILS, DEBUG) << "IO context stopped!";
}

IOContextRunner::~IOContextRunner()
{
	stop();

	for (std::thread& t : _threads)
		t.join();
}
