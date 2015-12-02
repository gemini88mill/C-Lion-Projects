cmake_minimum_required(VERSION 3.3)
project(Maximum_Stock_Return_)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES stock.c)
add_executable(Maximum_Stock_Return_ ${SOURCE_FILES})