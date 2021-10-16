#ifndef STDBP_CPP17_BIT_HPP_INCLUDE
#define STDBP_CPP17_BIT_HPP_INCLUDE

#include <stdbp/cpp17/common.hpp>

#include <cstring>
#include <type_traits>

STDBP_CPP17_NAMESPACE_BEGIN

#ifndef __cpp_lib_bit_cast

// Note: can't be constexpr here without compiler support
template <
  typename To,
  typename From
> 
std::enable_if_t<
  sizeof(From) == sizeof(To) &&
    std::is_trivially_copyable_v<From> &&
    std::is_trivially_copyable_v<To> &&
    std::is_trivially_constructible_v<To>,
  To
> bit_cast(From from) noexcept
{
  To to;
  std::memcpy(&to, &from, sizeof(from));
  return to;
}

#else

template <typename To, typename From>
using bit_cast STDBP_CPP17_DEPRECATED = std::bit_cast<To, From>;

#endif

STDBP_CPP17_NAMESPACE_END

#endif
