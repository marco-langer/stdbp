#ifndef STDBP_CPP17_TYPE_TRAITS_HPP_INCLUDE
#define STDBP_CPP17_TYPE_TRAITS_HPP_INCLUDE

#include <stdbp/cpp17/common.hpp>

#include <type_traits>

STDBP_CPP17_NAMESPACE_BEGIN

namespace detail {

template <typename T, typename ... Args>
inline constexpr bool is_any_of = (... || std::is_same_v<T, Args>);

template <typename T>
inline constexpr bool is_signed_integer = is_any_of<T,
  signed char, signed short int, signed int, signed long, signed long long
>;

template <typename T>
inline constexpr bool is_unsigned_integer = is_any_of<T,
  unsigned char, unsigned short int, unsigned int, unsigned long, unsigned long long
>;

template <typename T>
inline constexpr bool is_standard_integer =
  is_signed_integer<T> || is_unsigned_integer<T>;

} // namespace detail

#ifndef __cpp_lib_bounded_array_traits

template <typename T>
struct is_bounded_array : std::false_type {};

template <typename T, std::size_t N>
struct is_bounded_array<T[N]> : std::true_type {};

template <typename T>
inline constexpr bool is_bounded_array_v = is_bounded_array<T>::value;

template <typename T>
struct is_unbounded_array : std::false_type {};

template <typename T>
struct is_unbounded_array<T[]> : std::true_type {};

template <typename T>
inline constexpr bool is_unbounded_array_v = is_unbounded_array<T>::value;

#else

template <typename T>
using is_bounded_array STDBP_CPP17_DEPRECATED = std::is_bounded_array<T>;

template <typename T>
inline constexpr bool is_bounded_array_v STDBP_CPP17_DEPRECATED = std::is_bounded_array_v<T>;

template <typename T>
using is_unbounded_array STDBP_CPP17_DEPRECATED = std::is_unbounded_array<T>;

template <typename T>
inline constexpr bool is_unbounded_array_v STDBP_CPP17_DEPRECATED = std::is_unbounded_array_v<T>;

#endif

#ifndef __cpp_lib_remove_cvref

template <typename T>
struct remove_cvref {
  using type = std::remove_cv_t<std::remove_reference_t<T>>;
};

template <typename T>
using remove_cvref_t = typename remove_cvref<T>::type;

#else

template <typename T>
using remove_cvref STDBP_CPP17_DEPRECATED = std::remove_cvref<T>;

template <typename T>
using remove_cvref_t STDBP_CPP17_DEPRECATED = std::remove_cvref_t<T>;

#endif

#ifndef __cpp_lib_type_identity

template <typename T>
struct type_identity {
  using type = T;
};

template <typename T>
using type_identity_t = typename type_identity<T>::type;

#else

template <typename T>
using type_identity STDBP_CPP17_DEPRECATED = std::type_identity<T>;

template <typename T>
using type_identity_t STDBP_CPP17_DEPRECATED = std::type_identity_t<T>;

#endif

#ifndef __cpp_lib_is_scoped_enum

namespace detail {

inline void
scoped_enum_helper(int i) {
  static_cast<void>(i);
}

} // namespace detail

template <typename T, typename = void>
struct is_scoped_enum : std::is_enum<T> {};

template <typename T>
struct is_scoped_enum<T, std::void_t<decltype(detail::scoped_enum_helper(T()))>> : std::false_type {};

template <typename T>
inline constexpr bool is_scoped_enum_v = is_scoped_enum<T>::value;

#else

template <typename T>
using is_scoped_enum STDBP_CPP17_DEPRECATED = std::is_scoped_enum<T>;

template <typename T>
inline constexpr bool is_scoped_enum_v STDBP_CPP17_DEPRECAED = std::is_scoped_enum_v<T>;

#endif

STDBP_CPP17_NAMESPACE_END

#endif
