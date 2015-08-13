cmake_minimum_required(VERSION 3.2)
project(StarDust)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp)

find_package(PkgConfig REQUIRED)

include_directories(${GTK3_INCLUDE_DIRS})

pkg_check_modules(GTK3 REQUIRED gtk+-3.0)


link_directories(${GTK3_LIBRARY_DIRS})


add_executable(StarDust ${SOURCE_FILES} src/GTK+_defs.h)

target_link_libraries(StarDust ${GTK3_LIBRARIES})