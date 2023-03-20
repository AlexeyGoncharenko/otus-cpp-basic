cmake_minimum_required(VERSION 3.5)

set(target "guess_number")

project(${target})

add_executable(
	${target}
	main.cpp
	get_magic_number.cpp
	check_value.cpp
	high_scores.cpp
)
set_target_properties(
	${target} PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR 
    CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang" OR 
    CMAKE_CXX_COMPILER_ID STREQUAL "GNU") 
    target_compile_options(${target} PRIVATE 
        -g 
        -Wall 
        -Wextra 
        -Werror 
        -pedantic 
    ) 
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC") 
    target_compile_options(${target} PRIVATE 
        /W4 
        /WX 
    ) 
endif()