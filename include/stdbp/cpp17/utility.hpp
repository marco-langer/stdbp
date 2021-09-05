#ifndef STDBP_UTILITY_HPP
#define STDBP_UTILITY_HPP

#include <type_traits>

#include "type_traits.hpp"

STDBP_NAMESPACE_BEGIN

template <typename T, typename U>
constexpr std::enable_if_t<detail::is_standard_integer<T> && detail::is_standard_integer<U>, bool>
cmp_equal(T t, U u) noexcept {
  using UT = std::make_unsigned_t<T>;
  using UU = std::make_unsigned_t<U>;

  if constexpr (std::is_signed_v<T> && std::is_signed_v<U>) {
    return t == u;
  } else if constexpr (std::is_signed_v<U>) {
    return t < 0 ? false : (static_cast<UT>(t) == u);
  } else {
    //TODO
  }
}

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
using to_underlying STDBP_DEPRECATED = std::to_underlying<Enum>;

#endif

STDBP_NAMESPACE_END

#endif