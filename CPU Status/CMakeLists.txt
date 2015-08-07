cmake_minimum_required(VERSION 3.2)
project(CPU_Status)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)

set(CPU_status_VERSION_MAJOR_1)

find_package(Curses REQUIRED)
find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(PkgConfig REQUIRED)

pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${CURSES_INCLUDE_DIR})
include_directories(${GLUT_INCLUDE_DIR})
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )
include_directories(${GLEW_INCLUDE_DIRS})
include_directories(${GLEW_INCLUDE_PATH})
include_directories(/usr/include)
include_directories(${GTK3_INCLUDE_DIRS})

link_directories(${GTK3_LIBRARY_DIRS})

INCLUDE(FindOpenGL REQUIRED)
INCLUDE(FindGLEW REQUIRED)


add_definitions(${GTK3_CFLAGS_OTHER})


add_executable(CPU_Status ${SOURCE_FILES} Physics.h)
target_link_libraries(CPU_Status ${CURSES_LIBRARIES})
target_link_libraries(CPU_Status ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
target_link_libraries(CPU_Status ${GLEW_LIBRARIES})
target_link_libraries(CPU_Status ${GTK3_LIBRARIES})

INCLUDE_DIRECTORIES(${OPENGL_INCLUDE_DIR})
INCLUDE_DIRECTORIES(${GLEW_INCLUDE_DIR})

message(STATUS ${GLEW_LIBRARY})