

#pragma once

#include <chrono>
#include <unordered_map>

#include <Wt/WDateTime.h>

#include "utils/NetAddress.hpp"
#include "utils/Exception.hpp"

namespace Auth
{
	class LoginThrottler
	{
		public:
			LoginThrottler(std::size_t maxEntries) : _maxEntries {maxEntries} {}

			// user must lock these calls to avoid races
			bool isClientThrottled(const boost::asio::ip::address& address) const;
			void onBadClientAttempt(const boost::asio::ip::address& address);
			void onGoodClientAttempt(const boost::asio::ip::address& address);

		private:
			void removeOutdatedEntries();

			const std::size_t _maxEntries;
			static constexpr std::size_t _maxBadConsecutiveAttemptCount {5};
			static constexpr std::chrono::seconds _throttlingDuration {3};

			struct AttemptInfo
			{
				Wt::WDateTime nextAttempt;
				std::size_t badConsecutiveAttemptCount{};
			};
			std::unordered_map<boost::asio::ip::address, AttemptInfo>	_attemptsInfo;
	};
} // Auth

