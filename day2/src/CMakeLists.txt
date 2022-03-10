file(GLOB SRC_FILES *.cpp)
add_library(day2 ${SRC_FILES})

add_executable(day2_answer main.cpp)
target_link_libraries(day2_answer day2)

target_include_directories(day2 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
