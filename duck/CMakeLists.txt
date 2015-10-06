cmake_minimum_required(VERSION 3.2)
project(duck)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES duck.c)
add_executable(duck ${SOURCE_FILES})