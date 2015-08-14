cmake_minimum_required(VERSION 3.2)
project(email_reader)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(POCO)

set(SOURCE_FILES main.cpp)
add_executable(email_reader ${SOURCE_FILES})

set(POCO_PREFIX      "/path/to/cmake_install/debug") # the directory containing "include" and "lib"
set(POCO_INCLUDE_DIR "${POCO_PREFIX}/include")
set(POCO_LIB_DIR     "${POCO_PREFIX}/lib")
set(POCO_LIBS        "${POCO_LIB_DIR}/libPocoNetd.a"
                     "${POCO_LIB_DIR}/libPocoUtild.a"
                     "${POCO_LIB_DIR}/libPocoJSONd.a"
                     "${POCO_LIB_DIR}/libPocoXMLd.a"
                     "${POCO_LIB_DIR}/libPocoFoundationd.a"
                     "pthread")

                     # set the include path for the app
                     target_include_directories(email_reader PRIVATE "${POCO_INCLUDE_DIR}")
                     # link the app against POCO
                     target_link_libraries(email_reader "${POCO_LIBS}")