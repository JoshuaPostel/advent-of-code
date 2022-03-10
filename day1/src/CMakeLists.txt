file(GLOB SRC_FILES *.cpp)
add_library(day1 ${SRC_FILES})

add_executable(day1_answer main.cpp)
target_link_libraries(day1_answer day1)

target_include_directories(day1 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
