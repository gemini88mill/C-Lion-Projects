cmake_minimum_required(VERSION 3.3)
project(gameofgames)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES gameofgame.c)
add_executable(gameofgames ${SOURCE_FILES})