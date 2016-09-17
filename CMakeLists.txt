cmake_minimum_required(VERSION 2.8)
project(word)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gcc")

set(SOURCE_FILES main.c getword.c manage_word.c manage_word.h)
add_executable(word ${SOURCE_FILES})
