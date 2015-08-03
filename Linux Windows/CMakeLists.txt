cmake_minimum_required(VERSION 3.2)
project(Linux_Windows)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Linux_Windows ${SOURCE_FILES})