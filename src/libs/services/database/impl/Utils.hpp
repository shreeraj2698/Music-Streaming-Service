

#pragma once

#include <string>
#include <string_view>

#include <Wt/Dbo/Dbo.h>
#include <Wt/WDateTime.h>

#include "services/database/Types.hpp"

namespace Database::Utils
{
#define ESCAPE_CHAR_STR "\\"
	static inline constexpr char escapeChar {'\\'};
	std::string escapeLikeKeyword(std::string_view keywords);

	template <typename T>
	RangeResults<T>
	execQuery(Wt::Dbo::Query<T>& query, Range range)
	{
		RangeResults<T> res;

		auto collection {query.limit(range.size ? static_cast<int>(range.size) + 1 : -1)
							.offset(range.offset ? static_cast<int>(range.offset) : -1)
							.resultList()};

		res.results.assign(collection.begin(), collection.end());
		if (range.size && res.results.size() == static_cast<std::size_t>(range.size) + 1)
		{
			res.moreResults = true;
			res.results.pop_back();
		}
		else
			res.moreResults = false;

		res.range.offset = range.offset;
		res.range.size = res.results.size();
		return res;
	}

	template <typename T>
	RangeResults<typename T::pointer>
	execQuery(Wt::Dbo::Query<Wt::Dbo::ptr<T>>& query, Range range)
	{
		RangeResults<typename T::pointer> res;

		auto collection {query.limit(range.size ? static_cast<int>(range.size) + 1 : -1)
							.offset(range.offset ? static_cast<int>(range.offset) : -1)
							.resultList()};

		res.results.assign(collection.begin(), collection.end());
		if (range.size && res.results.size() == static_cast<std::size_t>(range.size) + 1)
		{
			res.moreResults = true;
			res.results.pop_back();
		}
		else
			res.moreResults = false;

		res.range.offset = range.offset;
		res.range.size = res.results.size();
		return res;
	}

	Wt::WDateTime normalizeDateTime(const Wt::WDateTime& dateTime);
} // namespace Database::Utils

