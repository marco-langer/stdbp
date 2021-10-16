#ifndef STDBP_CPP17_COMMON_HPP_INCLUDE
#define STDBP_CPP17_COMMON_HPP_INCLUDE

#ifndef STDBP_CPP17_NAMESPACE_BEGIN
  #define STDBP_CPP17_NAMESPACE_BEGIN namespace stdbp { inline namespace cpp17 {
#endif

#ifndef STDBP_CPP17_NAMESPACE_END
  #define STDBP_CPP17_NAMESPACE_END }}
#endif

#ifndef STDBP_CPP17_DISABLE_DEPRECATION
  #ifndef STDBP_CPP17_DEPRECATED
    #define STDBP_CPP17_DEPRECATED [[deprecated]]
  #endif
#else
  #ifndef STDBP_CPP17_DEPRECATED
    #define STDBP_CPP17_DEPRECATED
  #endif
#endif

#endif
