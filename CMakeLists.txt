cmake_minimum_required(VERSION 3.8) #recommended stanble cmake version 3.8

project(hello_world CXX) #CXX just point this's the C++ project

set(HEADERS
    move_me_out.hpp)

set(SOURCES 
    hello_world.cpp
    move_me_out.cpp)

add_executable(hello_world ${HEADERS} ${SOURCES})

target_compile_features(hello_world PUBLIC cxx_std_17)
if(MSVC)
    target_compile_options(hello_world PUBLIC /W4 /WX)
else()
    target_compile_options(hello_world PUBLIC -Wall -Wextra -Werror -pedantic)
endif()
# set_target_properties(hello_world PROPERTIES
#     CXX_STANDARD 17
#     CXX_STANDARD_REQUIRED ON
# )