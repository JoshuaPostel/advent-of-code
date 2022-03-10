file(GLOB SRC_FILES *.cpp)
add_library(day1 ${SRC_FILES})

add_executable(answer main.cpp)
target_link_libraries(answer day1)

target_include_directories(day1 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
