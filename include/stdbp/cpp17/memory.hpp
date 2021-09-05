#ifndef STDBP_MEMORY_HPP
#define STDBP_MEMORY_HPP

#include <memory>

#include "type_traits.hpp"

STDBP_NAMESPACE_BEGIN

#ifndef __cpp_lib_smart_ptr_for_overwrite

template <typename T>
std::enable_if_t<
  !std::is_array_v<T>,
  std::unique_ptr<T>
>
make_unique_for_overwrite()
{
  return std::unique_ptr<T>(new T);
}

template <typename T>
std::enable_if_t<
#ifdef __cpp_lib_bounded_array_traits
  std::is_unbounded_array_v<T>,
#else
  stdbp::is_unbounded_array_v<T>,
#endif
  std::unique_ptr<T>
>
make_unique_for_overwrite(std::size_t n)
{
  return std::unique_ptr<T>(new std::remove_extent_t<T>[n]);
}

template <typename T>
std::enable_if_t<
#ifdef __cpp_lib_bounded_array_traits
  std::is_bounded_array_v<T>,
#else
  stdbp::is_bounded_array_v<T>,
#endif
  std::unique_ptr<T>
>
make_unique_for_overwrite(std::size_t n) = delete;

#else

template <typename T>
make_unique_for_overwrite() STDBP_DEPRECATED = std::make_unique_for_overwrite();

#endif

STDBP_NAMESPACE_END

#endif
