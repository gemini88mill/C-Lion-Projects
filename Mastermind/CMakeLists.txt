cmake_minimum_required(VERSION 3.2)
project(Mastermind)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES mastermind.c)
add_executable(Mastermind ${SOURCE_FILES})