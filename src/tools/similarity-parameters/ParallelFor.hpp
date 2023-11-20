

#include <functional>
#include <thread>
#include <boost/asio/io_context.hpp>

template <typename It, typename Func>
void parallel_foreach(std::size_t nbWorkers, It begin, It end, Func&& func)
{
	if (nbWorkers == 0)
		throw std::runtime_error("Invalid worker count");

	boost::asio::io_context ioContext;

	for (It it {begin}; it != end; ++it)
	{
		auto refValue {std::ref<typename It::value_type>(*it)};
		ioContext.post([refValue, &func]() { std::cout << "EXEC FROM WORKER" << std::endl; func(refValue); std::cout << "END EXEC FROM WORKER" << std::endl; });
	}

	std::vector<std::thread> threads;
	for (std::size_t i {}; i < nbWorkers - 1; ++i)
		threads.emplace_back([&]() { ioContext.run(); });

	ioContext.run();

	for (std::thread& t : threads)
		t.join();
}

