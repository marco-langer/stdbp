set(PROJECT_SOURCES
    test_type_traits.cpp
    test_utility.cpp
)

include(CTest)
include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/Catch.cmake)

add_executable(stdbp_tests ${PROJECT_SOURCES})

target_include_directories(stdbp_tests
    PUBLIC
      ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

target_link_libraries(stdbp_tests PRIVATE Catch2::Catch2WithMain)

target_compile_definitions(stdbp_tests PUBLIC STDBP_DISABLE_DEPRECATION)

catch_discover_tests(stdbp_tests)

