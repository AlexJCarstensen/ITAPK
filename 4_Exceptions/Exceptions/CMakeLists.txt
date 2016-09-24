cmake_minimum_required(VERSION 3.6)
project(Exceptions)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp MyArray.h Test.h MyVector.h String.h DataSet.h)
add_executable(Exceptions ${SOURCE_FILES})