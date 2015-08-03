cmake_minimum_required(VERSION 3.0)

project(Email_Reader)

# define the project
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Email_Reader ${SOURCE_FILES})

# set the POCO paths and libs
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
target_include_directories(Email_Reader PRIVATE "${POCO_INCLUDE_DIR}")
# link the app against POCO
target_link_libraries(Email_Reader "${POCO_LIBS}")




