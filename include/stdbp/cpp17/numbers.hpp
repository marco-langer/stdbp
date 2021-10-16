#ifndef STDBP_CPP17_NUMBERS_HPP_INCLUDE
#define STDBP_CPP17_NUMBERS_HPP_INCLUDE

#include <stdbp/cpp17/common.hpp>

#include <type_traits>
#ifdef __cpp_lib_math_constants
#include <numbers>
#endif

STDBP_CPP17_NAMESPACE_BEGIN

namespace numbers {

#ifndef __cpp_lib_math_constants

template <typename T>
inline constexpr T pi_v =
  std::enable_if_t<std::is_floating_point_v<T>, T>(3.141592653589793238462643383279502884L);

inline constexpr auto pi = pi_v<double>;

#else

template <typename >
using pi_v STDBP_CPP17_DEPRECATED = std::numbers::pi_v<T>;

inline constexpr auto pi STDBP_CPP17_DEPRECATED = std::numbers::pi_v<double>;

#endif

} // namespace numbers

STDBP_CPP17_NAMESPACE_END

#endif
