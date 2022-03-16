add_executable(day${DayNumber}_test Day${DayNumber}Test.cpp)
target_link_libraries(day${DayNumber}_test gtest gtest_main day${DayNumber} rust_bingo)

get_filename_component(TEST_RESOURCE_DIR resources/ ABSOLUTE)
configure_file(config.h.in config.h)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

include_directories(${CMAKE_BINARY_DIR}/day4/src/rust_bingo)

include_directories(../src/include)

gtest_discover_tests(day${DayNumber}_test)
