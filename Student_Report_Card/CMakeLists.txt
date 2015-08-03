cmake_minimum_required(VERSION 3.2)
project(Student_Report_Card)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Student_Report_Card ${SOURCE_FILES} student.h)