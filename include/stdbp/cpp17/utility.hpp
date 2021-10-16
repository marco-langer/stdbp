#ifndef STDBP_CPP17_UTILITY_HPP_INCLUDE
#define STDBP_CPP17_UTILITY_HPP_INCLUDE

#include <stdbp/cpp17/common.hpp>
#include <stdbp/cpp17/type_traits.hpp>

STDBP_CPP17_NAMESPACE_BEGIN

#ifndef __cpp_lib_cmp_equal

template <typename T, typename U>
constexpr std::enable_if_t<detail::is_standard_integer<T> && detail::is_standard_integer<U>, bool>
cmp_equal(T t, U u) noexcept {
  using UT = std::make_unsigned_t<T>;
  using UU = std::make_unsigned_t<U>;

  if constexpr (std::is_signed_v<T> && std::is_signed_v<U>) {
    return t == u;
  } else if constexpr (std::is_signed_v<T>) {
    return t < 0 ? false : UT(t) == u;
  } else {
    return u < 0 ? false : t == UU(u);
  }
}

template <typename T, typename U>
constexpr std::enable_if_t<detail::is_standard_integer<T> && detail::is_standard_integer<U>, bool>
cmp_not_equal(T t, U u) noexcept {
  return !cmp_equal(t, u);
}

template <typename T, typename U>
constexpr std::enable_if_t<detail::is_standard_integer<T> && detail::is_standard_integer<U>, bool>
cmp_less(T t, U u) noexcept {
  using UT = std::make_unsigned_t<T>;
  using UU = std::make_unsigned_t<U>;

  if constexpr (std::is_signed_v<T> && std::is_signed_v<U>) {
    return t < u;
  } else if constexpr (std::is_signed_v<T>) {
    return t < 0 ? true : UT(t) < u;
  } else {
    return u < 0 ? false : t < UU(u);
  }
}

template <typename T, typename U>
constexpr std::enable_if_t<detail::is_standard_integer<T> && detail::is_standard_integer<U>, bool>
cmp_greater(T t, U u) noexcept {
  return cmp_less(u, t);
}

template <typename T, typename U>
constexpr std::enable_if_t<detail::is_standard_integer<T> && detail::is_standard_integer<U>, bool>
cmp_less_equal(T t, U u) noexcept {
  return !cmp_greater(t, u);
}

template <typename T, typename U>
constexpr std::enable_if_t<detail::is_standard_integer<T> && detail::is_standard_integer<U>, bool>
cmp_greater_equal(T t, U u) noexcept {
  return !cmp_less(t, u);
}

#else

template <typename T, typename U>
using cmp_equal STDBP_CPP17_DEPRECATED = std::cmp_equal<T, U>;

template <typename T, typename U>
using cmp_not_equal STDBP_CPP17_DEPRECATED = std::cmp_not_equal<T, U>;

template <typename T, typename U>
using cmp_less STDBP_CPP17_DEPRECATED = std::cmp_less<T, U>;

template <typename T, typename U>
using cmp_greater STDBP_CPP17_DEPRECATED = std::cmp_greater<T, U>;

template <typename T, typename U>
using cmp_less_equal STDBP_CPP17_DEPRECATED = std::cmp_less_equal<T, U>;

template <typename T, typename U>
using cmp_greater_equal STDBP_CPP17_DEPRECATED = std::cmp_greater_equal<T, U>;

#endif

#ifndef __cpp_lib_to_underlying

template <typename Enum>
constexpr std::enable_if_t<
  std::is_enum_v<Enum>,
  std::underlying_type_t<Enum>
>
to_underlying(Enum e) noexcept {
  return static_cast<std::underlying_type_t<Enum>>(e);
}

#else

template <typename Enum>
using to_underlying STDBP_CPP17_DEPRECATED = std::to_underlying<Enum>;

#endif

STDBP_CPP17_NAMESPACE_END

#endif
