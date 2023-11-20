

#pragma once

#include <boost/crc.hpp>  // for boost::crc_32_type

namespace Utils
{

	class Crc32Calculator
	{
		public:

			void processBytes(const std::byte* _data, std::size_t dataSize)
			{
				_result.process_bytes(_data, dataSize);
			}

			std::uint32_t getResult() const
			{
				return _result.checksum();
			}

		private:
			using Crc32Type = boost::crc_32_type;
			Crc32Type _result;
	};

}

