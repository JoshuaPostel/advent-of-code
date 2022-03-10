file(GLOB SRC_FILES *.cpp)
add_library(day${DayNumber} ${SRC_FILES})

add_executable(day${DayNumber}_answer main.cpp)
target_link_libraries(day${DayNumber}_answer day${DayNumber})

target_include_directories(day${DayNumber} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
