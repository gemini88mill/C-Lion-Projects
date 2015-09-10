cmake_minimum_required(VERSION 3.2)
project(Sudokode)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES sudokode.c)
add_executable(Sudokode ${SOURCE_FILES})