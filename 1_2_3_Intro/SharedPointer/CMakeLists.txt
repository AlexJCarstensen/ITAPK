cmake_minimum_required(VERSION 3.6)
project(SharedPointer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp SharedPtr.h)
add_executable(SharedPointer ${SOURCE_FILES})