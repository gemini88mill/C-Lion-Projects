cmake_minimum_required(VERSION 3.3)
project(Dinner_and_a_Movie)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES movie.c)
add_executable(Dinner_and_a_Movie ${SOURCE_FILES})