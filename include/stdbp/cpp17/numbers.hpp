#ifndef STDBP_NUMBERS_HPP
#define STDBP_NUMBERS_HPP

#include <type_traits>

#ifdef __cpp_lib_math_constants
#include <numbers>
#endif

STDBP_NAMESPACE_BEGIN

namespace numbers {

#ifndef __cpp_lib_math_constants

template <typename T>
inline constexpr T pi_v =
  std::enable_if_t<std::is_floating_point_v<T>, T>(3.141592653589793238462643383279502884L);

inline constexpr auto pi = pi_v<double>;

#else

template <typename >
using pi_v STDBP_DEPRECATED = std::numbers::pi_v<T>;

inline constexpr auto pi STDBP_DEPRECATED = std::numbers::pi_v<double>;

#endif

} // namespace numbers

STDBP_NAMESPACE_END

#endif
