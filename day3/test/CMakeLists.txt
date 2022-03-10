add_executable(day${DayNumber}_test Day${DayNumber}Test.cpp)
target_link_libraries(day${DayNumber}_test gtest gtest_main day${DayNumber})

get_filename_component(TEST_RESOURCE_DIR resources/ ABSOLUTE)
configure_file(config.h.in config.h)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

gtest_discover_tests(day${DayNumber}_test)
