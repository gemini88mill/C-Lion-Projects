cmake_minimum_required(VERSION 3.3)
project(genetics)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_library(math.h genetics.c)

set(SOURCE_FILES genetics.c)
add_executable(genetics ${SOURCE_FILES})

target_link_libraries(genetics m)
