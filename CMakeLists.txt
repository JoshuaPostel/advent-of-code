cmake_minimum_required(VERSION 3.15)
project(AoC)

enable_testing()
include(GoogleTest)
add_subdirectory("${PROJECT_SOURCE_DIR}/extern/googletest" "extern/googletest")

#include(CheckIPOSupported)
#check_ipo_supported(RESULT supported OUTPUT error)
#if(supported)
#    message(STATUS "IPO / LTO enabled")
#    set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
#    add_link_options(-fuse-ld=lld)
#else()
#    message(STATUS "IPO /LTO not supported: <${error}>")
#endif()

add_subdirectory(day1)
add_subdirectory(day2)
add_subdirectory(day3)

add_subdirectory(day4)
