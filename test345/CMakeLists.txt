cmake_minimum_required(VERSION 3.2)
project(test345)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c)
add_executable(test345 ${SOURCE_FILES})