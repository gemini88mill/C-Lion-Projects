cmake_minimum_required(VERSION 3.2)
project(Prime_Numbers)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Prime_Numbers ${SOURCE_FILES})