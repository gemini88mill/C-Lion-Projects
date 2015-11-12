cmake_minimum_required(VERSION 3.3)
project(cake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES cake.c)

add_library(math.h cake.c)

add_executable(cake ${SOURCE_FILES})

target_link_libraries(cake m)