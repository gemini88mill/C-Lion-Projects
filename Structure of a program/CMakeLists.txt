cmake_minimum_required(VERSION 3.2)
project(C___Notes)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(C___Notes ${SOURCE_FILES})