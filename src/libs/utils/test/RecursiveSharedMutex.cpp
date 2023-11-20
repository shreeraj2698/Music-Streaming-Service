

#include <atomic>
#include <chrono>
#include <thread>
#include <vector>

#include <gtest/gtest.h>

#include "utils/RecursiveSharedMutex.hpp"

TEST(RecursiveSharedMutex, SingleThreaded)
{
	{
		RecursiveSharedMutex mutex;

		{
			std::unique_lock lock {mutex};
		}

		{
			std::shared_lock lock {mutex};
		}

		{
			std::unique_lock lock1 {mutex};
			std::unique_lock lock2 {mutex};
		}

		{
			std::shared_lock lock1 {mutex};
			std::shared_lock lock2 {mutex};
		}

		{
			std::unique_lock lock1 {mutex};
			std::shared_lock lock2 {mutex};
		}
	}
}

TEST(RecursiveSharedMutex, MultiThreaded)
{
	{
		constexpr std::size_t nbThreads {10};
		std::vector<std::thread> threads;

		RecursiveSharedMutex mutex;
		std::atomic<std::size_t> nbUnique {};
		std::atomic<std::size_t> nbShared {};
		for (std::size_t i {}; i < nbThreads; ++i)
		{
			threads.emplace_back([&]
			{
				{
					std::unique_lock lock {mutex};

					std::shared_lock lock2 {mutex};

					assert(nbUnique == 0);
					assert(nbShared == 0);
					nbUnique++;
					std::this_thread::sleep_for(std::chrono::milliseconds(5));
					assert(nbUnique == 1);
					assert(nbShared == 0);
					nbUnique--;
				}

				{
					std::shared_lock lock {mutex};
					std::shared_lock lock2 {mutex};

					assert(nbUnique == 0);
					nbShared++;

					std::this_thread::sleep_for(std::chrono::milliseconds(15));

					assert(nbShared > 0);
					assert(nbShared <= nbThreads);
					assert(nbUnique == 0);
					nbShared--;
				}
			});
		}

		for (std::thread& t : threads)
			t.join();
	}
}
