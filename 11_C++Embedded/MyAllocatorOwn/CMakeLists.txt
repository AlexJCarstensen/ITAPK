cmake_minimum_required(VERSION 3.6)
project(MyAllocatorOwn)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp SmallObjectHeap.h SmallObjectAllocator.h)
add_executable(MyAllocatorOwn ${SOURCE_FILES})