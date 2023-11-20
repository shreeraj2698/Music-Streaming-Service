
#pragma once

#include <type_traits>
#include <Wt/Dbo/StdSqlTraits.h>

#include "utils/EnumSet.hpp"

namespace Wt::Dbo
{

	template<typename T>
	struct sql_value_traits<EnumSet<T>, void> : public sql_value_traits<long long>
	{
		using ValueType = typename EnumSet<T>::ValueType;
		static_assert(sizeof(long long) > sizeof(ValueType));

		static void bind(EnumSet<T> v, SqlStatement *statement, int column, int size)
		{
			sql_value_traits<long long>::bind(static_cast<long long>(v.getBitfield()), statement, column, size);
		}

		static bool read(EnumSet<T>& v, SqlStatement *statement, int column, int size)
		{
			long long val;
			if (sql_value_traits<long long>::read(val, statement, column, size))
			{
				v.setBitfield(val);
				return true;
			}
			v.clear();
			return false;
		}
	};
}

