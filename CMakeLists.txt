cmake_minimum_required(VERSION 4.3)
project(92004v2a C)

set(CMAKE_C_STANDARD 17)

add_executable(92004v2a src/main.c
        include/validation/validation.c
        include/validation/validation.h)

target_include_directories(92004v2a PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(92004v2a PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/liblua.a
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/libcjson.a
        m
)

target_compile_definitions(92004v2a PRIVATE
        PROJECT_DIR="${CMAKE_SOURCE_DIR}"
)