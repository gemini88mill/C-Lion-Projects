cmake_minimum_required(VERSION 3.2)
project(Physics)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Physics ${SOURCE_FILES} physics.h)