file(GLOB SRC_FILES *.cpp)
add_library(day${DayNumber} ${SRC_FILES})


target_include_directories(day${DayNumber} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})


include_directories(${CMAKE_BINARY_DIR}/day4/src/rust_bingo)
message(STATUS "cmake_binary_dir: " ${CMAKE_BINARY_DIR})

include_directories(include)

add_subdirectory(rust_bingo)

add_executable(day${DayNumber}_answer main.cpp)
target_link_libraries(day${DayNumber}_answer day${DayNumber} rust_bingo)
