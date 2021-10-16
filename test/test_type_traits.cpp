#include <catch2/catch_test_macros.hpp>

#include "stdbp/cpp17/type_traits.hpp"

using namespace stdbp;

TEST_CASE("type_traits") {
  SECTION("is_unbounded_array") {
    CHECK(is_unbounded_array<int[]>::value);
    CHECK(is_unbounded_array<const int[]>::value);
    CHECK(!is_unbounded_array<int>::value);
    CHECK(!is_unbounded_array<int[5]>::value);
    CHECK(!is_unbounded_array<int *>::value);
    CHECK(!is_unbounded_array<void>::value);

    CHECK(is_unbounded_array_v<int[]>);
    CHECK(is_unbounded_array_v<const int[]>);
    CHECK(!is_unbounded_array_v<int>);
    CHECK(!is_unbounded_array_v<int[5]>);
    CHECK(!is_unbounded_array_v<int *>);
    CHECK(!is_unbounded_array_v<void>);
  }

  SECTION("is_bounded_array") {
    CHECK(is_bounded_array<int[5]>::value);
    CHECK(is_bounded_array<const int[5]>::value);
    CHECK(!is_bounded_array<int>::value);
    CHECK(!is_bounded_array<int[]>::value);
    CHECK(!is_bounded_array<int *>::value);
    CHECK(!is_bounded_array<void>::value);

    CHECK(is_bounded_array_v<int[5]>);
    CHECK(is_bounded_array_v<const int[5]>);
    CHECK(!is_bounded_array_v<int>);
    CHECK(!is_bounded_array_v<int[]>);
    CHECK(!is_bounded_array_v<int *>);
    CHECK(!is_bounded_array_v<void>);
  }

  SECTION("remove_cvref") {
    CHECK(std::is_same_v<remove_cvref<int>::type, int>);
    CHECK(std::is_same_v<remove_cvref<const volatile int &>::type, int>);
    CHECK(std::is_same_v<remove_cvref<const volatile int &&>::type, int>);
    CHECK(std::is_same_v<remove_cvref<int *>::type, int *>);
    CHECK(std::is_same_v<remove_cvref<const volatile int * const>::type, const volatile int *>);
    CHECK(std::is_same_v<remove_cvref<const volatile int * const &>::type, const volatile int *>);
    CHECK(std::is_same_v<remove_cvref<void>::type, void>);

    CHECK(std::is_same_v<remove_cvref_t<int>, int>);
    CHECK(std::is_same_v<remove_cvref_t<const volatile int &>, int>);
    CHECK(std::is_same_v<remove_cvref_t<const volatile int &&>, int>);
    CHECK(std::is_same_v<remove_cvref_t<int *>, int *>);
    CHECK(std::is_same_v<remove_cvref_t<const volatile int * const>,const volatile int *>);
    CHECK(std::is_same_v<remove_cvref_t<const volatile int * const &>, const volatile int *>);
    CHECK(std::is_same_v<remove_cvref_t<void>, void>);
  }

  SECTION("type_identity") {
    CHECK(std::is_same_v<type_identity<const int *>::type, const int *>);
    CHECK(std::is_same_v<type_identity<void>::type, void>);

    CHECK(!std::is_same_v<type_identity<const int *>::type, int *>);
  }


  enum UnscopedEnum { Foo, Bar, Baz };
  enum class ScopedEnum { Foo, Bar, Baz };
  class Mock {};

  SECTION("is_scoped_enum") {
    CHECK(is_scoped_enum<ScopedEnum>::value);
    CHECK(!is_scoped_enum<UnscopedEnum>::value);
    CHECK(!is_scoped_enum<int>::value);
    CHECK(!is_scoped_enum<Mock>::value);

    CHECK(is_scoped_enum_v<ScopedEnum>);
    CHECK(!is_scoped_enum_v<UnscopedEnum>);
    CHECK(!is_scoped_enum_v<int>);
    CHECK(!is_scoped_enum_v<Mock>);
  }
}