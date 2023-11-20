

#pragma once

#include <boost/asio/ip/address.hpp>

#ifndef BOOST_ASIO_HAS_STD_HASH
#include <functional>

namespace std
{
	template<> struct hash<boost::asio::ip::address>
	{
		std::size_t operator()(const boost::asio::ip::address& ipAddr) const;
	};

}

#endif // BOOST_ASIO_HAS_STD_HASH
