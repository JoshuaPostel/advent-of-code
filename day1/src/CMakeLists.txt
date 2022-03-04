file(GLOB SRC_FILES *.cpp)
add_library(day1 ${SRC_FILES})

target_include_directories(day1 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS day1 DESTINATION lib)
install(FILES day1.h DESTINATION include)
