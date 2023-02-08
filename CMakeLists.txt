cmake_minimum_required(VERSION 3.5)

project(guess_number)

add_executable(
	guess_number
	main.cpp
)
set_target_properties(guess_number PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)
