

#pragma once

#include <algorithm>
#include <functional>

namespace Utils
{

	template<class T, class Compare = std::less<>>
	constexpr T clamp(T v, T lo, T hi, Compare comp = {})
	{
		assert(!comp(hi, lo));
		return comp(v, lo) ? lo : comp(hi, v) ? hi : v;
	}

	template <typename Container, typename T>
	void
	push_back_if_not_present(Container& container, const T& val)
	{
		if (std::find(std::cbegin(container), std::cend(container), val) == std::cend(container))
			container.push_back(val);
	}

}
