cmake_minimum_required(VERSION 3.5)

project(04.linkage
		DESCRIPTION "test static library linking")

add_library(
	datetime

	STATIC

	datetime.cpp
	datetime.h
	# ... 
)