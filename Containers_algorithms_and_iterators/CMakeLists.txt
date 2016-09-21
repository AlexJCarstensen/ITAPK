cmake_minimum_required(VERSION 3.6)
project(Containers_algorithms_and_iterators)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Product.h product.db)
add_executable(Containers_algorithms_and_iterators ${SOURCE_FILES})