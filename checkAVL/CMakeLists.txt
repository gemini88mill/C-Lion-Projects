cmake_minimum_required(VERSION 3.3)
project(checkAVL)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES checkAVL.c)
add_executable(checkAVL ${SOURCE_FILES})