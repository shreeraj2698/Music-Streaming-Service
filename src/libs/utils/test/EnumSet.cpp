

#include <gtest/gtest.h>

#include "utils/EnumSet.hpp"

TEST(EnumSet, ctr)
{
	enum class Foo
	{
		One,
		Two,
	};

	{
		constexpr EnumSet<Foo> test {Foo::One};

		static_assert(!test.empty());
		static_assert(test.contains(Foo::One));
		static_assert(!test.contains(Foo::Two));

		EXPECT_TRUE(!test.empty());
		EXPECT_TRUE(test.contains(Foo::One));
		EXPECT_FALSE(test.contains(Foo::Two));

		static_assert(test.getBitfield() != 0);
	}

	{
		constexpr EnumSet<Foo> test {Foo::One, Foo::Two};
		constexpr auto bitfield {test.getBitfield()};

		EnumSet<Foo> test2;
		EXPECT_FALSE(test2.contains(Foo::One));
		EXPECT_FALSE(test2.contains(Foo::Two));

		test2.setBitfield(bitfield);

		EXPECT_TRUE(test2.contains(Foo::One));
		EXPECT_TRUE(test2.contains(Foo::Two));
		EXPECT_EQ(test, test2);
	}
}
