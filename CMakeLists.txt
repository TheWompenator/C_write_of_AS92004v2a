cmake_minimum_required(VERSION 4.3)
project(92004v2a C)

set(CMAKE_C_STANDARD 17)

add_executable(92004v2a src/main.c
        include/validation.c
        include/validation.h)

target_include_directories(92004v2a PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(92004v2a PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/liblua.a
        m
)