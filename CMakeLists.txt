cmake_minimum_required(VERSION 3.12)

project(hello_world)

set(HEADERS
    example.h
    move_me_out.h)

set(SOURCES
    hello_world.cpp
    example.cpp
    move_me_out.cpp)

add_executable(hello_world ${HEADERS} ${SOURCES})

set_target_properties(hello_world PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)