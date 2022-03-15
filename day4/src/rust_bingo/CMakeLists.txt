set(CARGO_CMD cargo build --release --verbose)
set(TARGET_DIR "release")

# TODO uncomment when adding LTO
# set(RUST_FLAGS "-Clinker-plugin-lto" "Clinker=clang-13" "-Clink-arg=fuse-ld=lld-13")

set(RUST_BINGO_LIB "${CMAKE_CURRENT_BINARY_DIR}/${TARGET_DIR}/librust_bingo.a")

set(RUST_BINGO_CXX "${CMAKE_CURRENT_BINARY_DIR}/rust_bingo.cpp")

message(STATUS "cmake_current_binary_dir: " ${CMAKE_CURRENT_BINARY_DIR})

add_library(rust_bingo STATIC ${RUST_BINGO_CXX})
add_custom_command(
    OUTPUT ${RUST_BINGO_CXX}
    COMMAND CARGO_TARGET_DIR=${CMAKE_CURRENT_BINARY_DIR} RUSTFLAGS="${RUST_FLAGS}" ${CARGO_CMD}
    COMMAND cp ${CMAKE_CURRENT_BINARY_DIR}/cxxbridge/rust_bingo/src/lib.rs.cc ${RUST_BINGO_CXX}
    COMMAND cp ${CMAKE_CURRENT_BINARY_DIR}/cxxbridge/rust_bingo/src/lib.rs.h ${CMAKE_CURRENT_BINARY_DIR}/rust_bingo.h
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(rust_bingo pthread dl ${RUST_BINGO_LIB})
