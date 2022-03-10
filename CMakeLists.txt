cmake_minimum_required(VERSION 3.14)
project(AoC)

enable_testing()
include(GoogleTest)
add_subdirectory("${PROJECT_SOURCE_DIR}/extern/googletest" "extern/googletest")

add_subdirectory(day1)
add_subdirectory(day2)
