cmake_minimum_required(VERSION 3.3)
project(Fantasy_Baseball)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Fantasy_Baseball ${SOURCE_FILES})