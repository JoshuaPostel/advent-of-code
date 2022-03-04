add_subdirectory("${PROJECT_SOURCE_DIR}/extern/googletest" "extern/googletest")

#include_directories()

#target_include_directories(${PROJECT_NAME} PRIVATE Day1)

add_executable(day1_test Day1Test.cpp)
target_link_libraries(day1_test gtest gtest_main day1)
#target_link_libraries(day1_test Day1 REQUIRED)
#include_directories(day1_test PRIVATE Day1)

gtest_discover_tests(day1_test)
