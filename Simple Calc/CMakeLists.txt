cmake_minimum_required(VERSION 3.2)
project(Simple_Calc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})



set(SOURCE_FILES main.cpp)
add_executable(Simple_Calc ${SOURCE_FILES})

target_link_libraries(Simple_Calc ${CURSES_LIBRARIES})

