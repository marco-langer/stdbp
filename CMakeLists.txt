cmake_minimum_required(VERSION 3.18.4)

project(STDBP LANGUAGES CXX)

include(GNUInstallDirs)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Check compiler requirements
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS "10.2.1")
    message(FATAL_ERROR "Insufficient gcc version: 10.2.1 required")
  endif()
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "CLANG")
  if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS "11.0.1")
    message(FATAL_ERROR "Insufficient clang version: 11.0.1 required")
  endif()
endif()

option(WITH_TESTS "Enable building of unit tests" ON)

if(WITH_TESTS)
    find_package(Catch2 3 REQUIRED)
    include(CTest)
    include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/Catch.cmake)
    message(STATUS "Building tests: Yes")
    enable_testing()
else()
    message(STATUS "Building tests: No")
endif()

# Set Version
set(STDBP_VERSION_MAJOR "0")
set(STDBP_VERSION_MINOR "0")
set(STDBP_VERSION_PATCH "1")
set(STDBP_VERSION "${STDBP_VERSION_MAJOR}.${STDBP_VERSION_MINOR}.${STDBP_VERSION_PATCH}")

# Build type
set(DEFAULT_BUILD_TYPE "Debug")
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE "${DEFAULT_BUILD_TYPE}")
endif()
message(STATUS "Setting up build for stdbp v${STDBP_VERSION} (${CMAKE_BUILD_TYPE})")

if (WITH_TESTS)
  add_subdirectory(test/cpp17)
endif()
