#ifndef STDBP_COMMON_HPP
#define STDBP_COMMON_HPP

#ifndef STDBP_NAMESPACE_BEGIN
  #define STDBP_NAMESPACE_BEGIN namespace stdbp { inline namespace cpp17 {
#endif

#ifndef STDBP_NAMESPACE_END
  #define STDBP_NAMESPACE_END }}
#endif

#ifndef STDBP_DISABLE_DEPRECATION
  #ifndef STDBP_DEPRECATED
    #define STDBP_DEPRECATED [[deprecated]]
  #endif
#else
  #ifndef STDBP_DEPRECATED
    #define STDBP_DEPRECATED
  #endif
#endif

#endif
