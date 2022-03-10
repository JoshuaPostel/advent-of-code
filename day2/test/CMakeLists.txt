add_executable(day2_test Day2Test.cpp)
target_link_libraries(day2_test gtest gtest_main day2)

get_filename_component(TEST_RESOURCE_DIR resources/ ABSOLUTE)
configure_file(config.h.in config.h)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

gtest_discover_tests(day2_test)
