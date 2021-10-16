set(TEST_NAME_CPP17 cpp17_tests)

set(TEST_CPP17_SOURCES
    test_type_traits.cpp
    test_utility.cpp
)

add_executable(${TEST_NAME_CPP17} ${TEST_CPP17_SOURCES})

target_include_directories(${TEST_NAME_CPP17}
    PUBLIC
      ${CMAKE_CURRENT_SOURCE_DIR}/../../include
)

set_property(TARGET ${TEST_NAME_CPP17} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${TEST_NAME_CPP17} PROPERTY CXX_EXTENSIONS OFF)


target_compile_options(${TEST_NAME_CPP17} PRIVATE
    -Wall -Wextra -Wpedantic -Wundef -Wpointer-arith -Wno-long-long
    -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused 
    -Woverloaded-virtual -Wconversion -Wsign-conversion -Wdouble-promotion
    -Wformat=2 -Wduplicated-cond -Wduplicated-branches 
    -Wlogical-op -Wuseless-cast)

target_link_libraries(${TEST_NAME_CPP17} PRIVATE Catch2::Catch2WithMain)

target_compile_definitions(${TEST_NAME_CPP17} PRIVATE STDBP_DISABLE_DEPRECATION)

catch_discover_tests(${TEST_NAME_CPP17})

