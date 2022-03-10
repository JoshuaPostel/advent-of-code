add_executable(day1_test Day1Test.cpp)
target_link_libraries(day1_test gtest gtest_main day1)

get_filename_component(TEST_RESOURCE_DIR resources/ ABSOLUTE)
message(STATUS "hello world: ${TEST_RESOURCE_DIR}")
configure_file(config.h.in config.h)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

gtest_discover_tests(day1_test)
