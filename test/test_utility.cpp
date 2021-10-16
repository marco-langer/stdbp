#include <catch2/catch_test_macros.hpp>

#include "stdbp/cpp17/utility.hpp"

#include <limits>

using namespace stdbp;

TEST_CASE("utility") {
  SECTION("cmp_equal unsigned/unsigned") {
    unsigned int u1 = 123;
    unsigned int u2 = 123;
    unsigned int u3 = 42;

    REQUIRE(cmp_equal(u1, u2));
    REQUIRE(!cmp_equal(u1, u3));
  }

  SECTION("cmp_equal signed/signed") {
    int i1 = 123;
    int i2 = 123;
    int i3 = -123;
    int i4 = -123;

    REQUIRE(cmp_equal(i1, i2));
    REQUIRE(cmp_equal(i3, i4));
    REQUIRE(!cmp_equal(i1, i3));
  }

  SECTION("cmp_equal signed/unsigned") {
    unsigned int u1 = 42;
    int i1 = 42;
    int i2 = -42;

    REQUIRE(cmp_equal(i1, u1));
    REQUIRE(!cmp_equal(i2, u1));
    REQUIRE(!cmp_equal(i2, std::numeric_limits<unsigned int>::max() - 41));
  }

  SECTION("cmp_equal unsigned/signed") {
    unsigned int u1 = 42;
    int i1 = 42;
    int i2 = -42;

    REQUIRE(cmp_equal(u1, i1));
    REQUIRE(!cmp_equal(u1, i2));
    REQUIRE(!cmp_equal(std::numeric_limits<unsigned int>::max() - 41, i2));
  }
}
