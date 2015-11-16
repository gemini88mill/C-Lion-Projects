cmake_minimum_required(VERSION 3.3)
project(boogle)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES boogle.c)
add_executable(boogle ${SOURCE_FILES})