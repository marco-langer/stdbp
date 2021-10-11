#include <catch2/catch_test_macros.hpp>

#include "stdbp/cpp17/type_traits.hpp"

TEST_CASE("type_traits.is_unbounded_array") {
  CHECK(stdbp::is_unbounded_array<int[]>::value);
  CHECK(stdbp::is_unbounded_array<const int[]>::value);
  CHECK(!stdbp::is_unbounded_array<int>::value);
  CHECK(!stdbp::is_unbounded_array<int[5]>::value);
  CHECK(!stdbp::is_unbounded_array<int *>::value);
  CHECK(!stdbp::is_unbounded_array<void>::value);

  CHECK(stdbp::is_unbounded_array_v<int[]>);
  CHECK(stdbp::is_unbounded_array_v<const int[]>);
  CHECK(!stdbp::is_unbounded_array_v<int>);
  CHECK(!stdbp::is_unbounded_array_v<int[5]>);
  CHECK(!stdbp::is_unbounded_array_v<int *>);
  CHECK(!stdbp::is_unbounded_array_v<void>);
}

TEST_CASE("type_traits.is_bounded_array") {
  CHECK(stdbp::is_bounded_array<int[5]>::value);
  CHECK(stdbp::is_bounded_array<const int[5]>::value);
  CHECK(!stdbp::is_bounded_array<int>::value);
  CHECK(!stdbp::is_bounded_array<int[]>::value);
  CHECK(!stdbp::is_bounded_array<int *>::value);
  CHECK(!stdbp::is_bounded_array<void>::value);

  CHECK(stdbp::is_bounded_array_v<int[5]>);
  CHECK(stdbp::is_bounded_array_v<const int[5]>);
  CHECK(!stdbp::is_bounded_array_v<int>);
  CHECK(!stdbp::is_bounded_array_v<int[]>);
  CHECK(!stdbp::is_bounded_array_v<int *>);
  CHECK(!stdbp::is_bounded_array_v<void>);
}

TEST_CASE("type_traits.remove_cvref") {
  CHECK(std::is_same_v<stdbp::remove_cvref<int>::type, int>);
  CHECK(std::is_same_v<stdbp::remove_cvref<const volatile int &>::type, int>);
  CHECK(std::is_same_v<stdbp::remove_cvref<const volatile int &&>::type, int>);
  CHECK(std::is_same_v<stdbp::remove_cvref<int *>::type, int *>);
  CHECK(std::is_same_v<stdbp::remove_cvref<const volatile int * const>::type, const volatile int *>);
  CHECK(std::is_same_v<stdbp::remove_cvref<const volatile int * const &>::type, const volatile int *>);
  CHECK(std::is_same_v<stdbp::remove_cvref<void>::type, void>);

  CHECK(std::is_same_v<stdbp::remove_cvref_t<int>, int>);
  CHECK(std::is_same_v<stdbp::remove_cvref_t<const volatile int &>, int>);
  CHECK(std::is_same_v<stdbp::remove_cvref_t<const volatile int &&>, int>);
  CHECK(std::is_same_v<stdbp::remove_cvref_t<int *>, int *>);
  CHECK(std::is_same_v<stdbp::remove_cvref_t<const volatile int * const>,const volatile int *>);
  CHECK(std::is_same_v<stdbp::remove_cvref_t<const volatile int * const &>, const volatile int *>);
  CHECK(std::is_same_v<stdbp::remove_cvref_t<void>, void>);
}

TEST_CASE("type_traits.type_identity") {
  CHECK(std::is_same_v<stdbp::type_identity<const int *>::type, const int *>);
  CHECK(std::is_same_v<stdbp::type_identity<void>::type, void>);

  CHECK(!std::is_same_v<stdbp::type_identity<const int *>::type, int *>);
}

enum UnscopedEnum { Foo, Bar, Baz };
enum class ScopedEnum { Foo, Bar, Baz };
class Mock {};

TEST_CASE("type_traits.is_scoped_enum") {
  CHECK(stdbp::is_scoped_enum<ScopedEnum>::value);
  CHECK(!stdbp::is_scoped_enum<UnscopedEnum>::value);
  CHECK(!stdbp::is_scoped_enum<int>::value);
  CHECK(!stdbp::is_scoped_enum<Mock>::value);

  CHECK(stdbp::is_scoped_enum_v<ScopedEnum>);
  CHECK(!stdbp::is_scoped_enum_v<UnscopedEnum>);
  CHECK(!stdbp::is_scoped_enum_v<int>);
  CHECK(!stdbp::is_scoped_enum_v<Mock>);
}
