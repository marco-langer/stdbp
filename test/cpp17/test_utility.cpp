#include <catch2/catch_test_macros.hpp>

#include "stdbp/cpp17/utility.hpp"

#include <cstdint>
#include <limits>
#include <type_traits>

using namespace stdbp;

TEST_CASE("utility") {
  SECTION("cmp_equal unsigned/unsigned") {
    constexpr auto u1 = 42u;
    constexpr auto u2 = 123u;

    constexpr auto u3 = std::uint8_t{42};
    constexpr auto u4 = std::uint8_t{123};

    REQUIRE(cmp_equal(u1, u1));
    REQUIRE(!cmp_equal(u1, u2));
    REQUIRE(!cmp_equal(u2, u1));

    REQUIRE(cmp_equal(u1, u3));
    REQUIRE(!cmp_equal(u1, u4));
    REQUIRE(!cmp_equal(u2, u3));
  }

  SECTION("cmp_equal signed/signed") {
    constexpr auto i1 = 42;
    constexpr auto i2 = -42;
    constexpr auto i3 = 123;
    constexpr auto i4 = -123;

    constexpr auto i5 = std::int8_t{42};
    constexpr auto i6 = std::int8_t{-42};
    constexpr auto i7 = std::int8_t{123};
    constexpr auto i8 = std::int8_t{-123};

    REQUIRE(cmp_equal(i1, i1));
    REQUIRE(cmp_equal(i2, i2));
    REQUIRE(!cmp_equal(i1, i2));
    REQUIRE(!cmp_equal(i2, i1));
    REQUIRE(!cmp_equal(i1, i3));
    REQUIRE(!cmp_equal(i2, i4));
  
    REQUIRE(cmp_equal(i1, i5));
    REQUIRE(cmp_equal(i2, i6));
    REQUIRE(!cmp_equal(i1, i6));
    REQUIRE(!cmp_equal(i2, i5));
    REQUIRE(!cmp_equal(i1, i7));
    REQUIRE(!cmp_equal(i2, i8));
  }

  SECTION("cmp_equal signed/unsigned") {
    constexpr auto u1 = 42u;

    constexpr auto i1 = 42;
    constexpr auto i2 = 43;
    constexpr auto i3 = -42;

    constexpr auto i4 = std::int8_t{42};
    constexpr auto i5 = std::int8_t{43};
    constexpr auto i6 = std::int8_t{-42};

    constexpr auto u32max = std::numeric_limits<unsigned int>::max();

    REQUIRE(cmp_equal(i1, u1));
    REQUIRE(!cmp_equal(i2, u1));
    REQUIRE(!cmp_equal(i3, u1));
    REQUIRE(!cmp_equal(i3, u32max - 41));

    REQUIRE(cmp_equal(i4, u1));
    REQUIRE(!cmp_equal(i5, u1));
    REQUIRE(!cmp_equal(i6, u1));
    REQUIRE(!cmp_equal(i6, u32max - 41));
  }

  SECTION("cmp_equal unsigned/signed") {
    constexpr auto u1 = 42u;

    constexpr auto i1 = 42;
    constexpr auto i2 = 43;
    constexpr auto i3 = -42;

    constexpr auto i4 = std::int8_t{42};
    constexpr auto i5 = std::int8_t{43};
    constexpr auto i6 = std::int8_t{-42};

    constexpr auto u32max = std::numeric_limits<unsigned int>::max();

    REQUIRE(cmp_equal(u1, i1));
    REQUIRE(!cmp_equal(u1, i2));
    REQUIRE(!cmp_equal(u1, i3));
    REQUIRE(!cmp_equal(u32max - 41, i3));

    REQUIRE(cmp_equal(u1, i4));
    REQUIRE(!cmp_equal(u1, i5));
    REQUIRE(!cmp_equal(u1, i6));
    REQUIRE(!cmp_equal(u32max - 41, i6));
  }

  SECTION("cmp_not_equal unsigned/unsigned") {
    constexpr auto u1 = 42u;
    constexpr auto u2 = 123u;

    constexpr auto u3 = std::uint8_t{42};
    constexpr auto u4 = std::uint8_t{123};

    REQUIRE(!cmp_not_equal(u1, u1));
    REQUIRE(cmp_not_equal(u1, u2));
    REQUIRE(cmp_not_equal(u2, u1));

    REQUIRE(!cmp_not_equal(u1, u3));
    REQUIRE(cmp_not_equal(u1, u4));
    REQUIRE(cmp_not_equal(u4, u1));
  }

  SECTION("cmp_not_equal signed/signed") {
    constexpr auto i1 = 42;
    constexpr auto i2 = -42;
    constexpr auto i3 = 123;
    constexpr auto i4 = -123;

    constexpr auto i5 = std::int8_t{42};
    constexpr auto i6 = std::int8_t{-42};
    constexpr auto i7 = std::int8_t{123};
    constexpr auto i8 = std::int8_t{-123};

    REQUIRE(!cmp_not_equal(i1, i1));
    REQUIRE(!cmp_not_equal(i2, i2));
    REQUIRE(cmp_not_equal(i1, i2));
    REQUIRE(cmp_not_equal(i1, i3));
    REQUIRE(cmp_not_equal(i2, i3));
    REQUIRE(cmp_not_equal(i2, i4));

    REQUIRE(!cmp_not_equal(i1, i5));
    REQUIRE(!cmp_not_equal(i2, i6));
    REQUIRE(cmp_not_equal(i1, i6));
    REQUIRE(cmp_not_equal(i1, i7));
    REQUIRE(cmp_not_equal(i2, i7));
    REQUIRE(cmp_not_equal(i2, i8));
  }

  SECTION("cmp_not_equal signed/unsigned") {
    constexpr auto u1 = 42u;
  
    constexpr auto i1 = 42;
    constexpr auto i2 = 43;
    constexpr auto i3 = -42;

    constexpr auto i4 = std::int8_t{42};
    constexpr auto i5 = std::int8_t{43};
    constexpr auto i6 = std::int8_t{-42};

    constexpr auto u32max = std::numeric_limits<unsigned int>::max();

    REQUIRE(!cmp_not_equal(i1, u1));
    REQUIRE(cmp_not_equal(i2, u1));
    REQUIRE(cmp_not_equal(i2, u32max - 41));
    REQUIRE(cmp_not_equal(i3, u1));
    REQUIRE(cmp_not_equal(i3, u32max - 41));

    REQUIRE(!cmp_not_equal(i4, u1));
    REQUIRE(cmp_not_equal(i5, u1));
    REQUIRE(cmp_not_equal(i5, u32max - 41));
    REQUIRE(cmp_not_equal(i6, u1));
    REQUIRE(cmp_not_equal(i6, u32max - 41));
  }

  SECTION("cmp_not_equal unsigned/signed") {
    constexpr auto u1 = 42u;

    constexpr auto i1 = 42;
    constexpr auto i2 = 43;
    constexpr auto i3 = -42;

    constexpr auto i4 = std::int8_t{42};
    constexpr auto i5 = std::int8_t{43};
    constexpr auto i6 = std::int8_t{-42};

    constexpr auto u32max = std::numeric_limits<unsigned int>::max();

    REQUIRE(!cmp_not_equal(u1, i1));
    REQUIRE(cmp_not_equal(u1, i2));
    REQUIRE(cmp_not_equal(u32max - 41, i2));
    REQUIRE(cmp_not_equal(u1, i3));
    REQUIRE(cmp_not_equal(u32max - 41, i3));

    REQUIRE(!cmp_not_equal(u1, i4));
    REQUIRE(cmp_not_equal(u1, i5));
    REQUIRE(cmp_not_equal(u32max - 41, i5));
    REQUIRE(cmp_not_equal(u1, i6));
    REQUIRE(cmp_not_equal(u32max - 41, i6));
  }

  SECTION("cmp_less unsigned/unsigned") {
    constexpr auto u1 = 42u;
    constexpr auto u2 = 123u;

    constexpr auto u3 = std::uint8_t{42};
    constexpr auto u4 = std::uint8_t{123};

    REQUIRE(!cmp_less(u1, u1));
    REQUIRE(cmp_less(u1, u2));
    REQUIRE(!cmp_less(u2, u1));

    REQUIRE(!cmp_less(u1, u3));
    REQUIRE(cmp_less(u1, u4));
    REQUIRE(!cmp_less(u2, u3));
  }

// TODO test cases missing from here on

  SECTION("cmp_less signed/signed") {
    constexpr auto i1 = 123;
    constexpr auto i2 = -123;
    constexpr auto i3 = 124;
    constexpr auto i4 = -124;

    REQUIRE(!cmp_less(i1, i1));
    REQUIRE(!cmp_less(i2, i2));
    REQUIRE(!cmp_less(i1, i2));
    REQUIRE(cmp_less(i2, i1));
    REQUIRE(cmp_less(i1, i3));
    REQUIRE(cmp_less(i4, i2));
  }

  SECTION("cmp_less signed/unsigned") {
    constexpr auto u1 = 42u;

    constexpr auto i1 = 42;
    constexpr auto i2 = -43;
    constexpr auto i3 = std::int8_t{-43};

    REQUIRE(!cmp_less(i1, u1));
    REQUIRE(cmp_less(i2, u1));
    REQUIRE(cmp_less(i3, u1));
  }

  SECTION("cmp_less unsigned/signed") {
    constexpr auto u1 = 42u;

    constexpr auto i1 = 42;
    constexpr auto i2 = -43;
    constexpr auto i3 = 43;
    constexpr auto i4 = std::int8_t{-43};
    constexpr auto i5 = std::int8_t{43};

    REQUIRE(!cmp_less(u1, i1));
    REQUIRE(!cmp_less(u1, i2));
    REQUIRE(cmp_less(u1, i3));
    REQUIRE(!cmp_less(u1, i4));
    REQUIRE(cmp_less(u1, i5));
  }

  SECTION("cmp_greater unsigned/unsigned") {
    constexpr auto u1 = 123u;
    constexpr auto u2 = 42u;

    REQUIRE(!cmp_greater(u1, u1));
    REQUIRE(cmp_greater(u1, u2));
  }

  SECTION("cmp_greater signed/signed") {
    constexpr auto i1 = 123;
    constexpr auto i2 = -123;
    constexpr auto i3 = 124;
    constexpr auto i4 = -124;

    REQUIRE(!cmp_greater(i1, i1));
    REQUIRE(!cmp_greater(i2, i2));
    REQUIRE(cmp_greater(i1, i2));
    REQUIRE(!cmp_greater(i2, i1));
    REQUIRE(cmp_greater(i3, i1));
    REQUIRE(cmp_greater(i2, i4));
  }

  SECTION("cmp_greater signed/unsigned") {
    constexpr auto u1 = 42u;
    constexpr auto i1 = 42;
    constexpr auto i2 = -43;
    constexpr auto i3 = 43;
    constexpr auto i4 = std::int8_t{-43};
    constexpr auto i5 = std::int8_t{43};

    REQUIRE(!cmp_greater(i1, u1));
    REQUIRE(!cmp_greater(i2, u1));
    REQUIRE(cmp_greater(i3, u1));
    REQUIRE(!cmp_greater(i4, u1));
    REQUIRE(cmp_greater(i5, u1));
  }

  SECTION("cmp_greater unsigned/signed") {
    constexpr auto u1 = 42u;
    constexpr auto i1 = 42;
    constexpr auto i2 = -42;
    constexpr auto i3 = 43;
    constexpr auto i4 = std::int8_t{-43};
    constexpr auto i5 = std::int8_t{43};

    REQUIRE(!cmp_greater(u1, i1));
    REQUIRE(cmp_greater(u1, i2));
    REQUIRE(!cmp_greater(u1, i3));
    REQUIRE(cmp_greater(u1, i4));
    REQUIRE(!cmp_greater(u1, i5));
  }
}

TEST_CASE("to_underlying") {
  enum UnscopedEnum : std::int16_t { Foo, Bar, Baz };
  enum class ScopedEnum : std::int16_t { Foo, Bar, Baz };

  constexpr auto x = to_underlying(UnscopedEnum{Bar});
  constexpr auto y = to_underlying(ScopedEnum{Bar});

  REQUIRE(std::is_same_v<decltype(x), const std::int16_t>);
  REQUIRE(std::is_same_v<decltype(y), const std::int16_t>);
}