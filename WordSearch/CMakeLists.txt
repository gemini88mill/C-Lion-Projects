cmake_minimum_required(VERSION 3.2)
project(WordSearch)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES wordsearch.c)
add_executable(WordSearch ${SOURCE_FILES})