cmake_minimum_required(VERSION 3.6)
project(Exam)

#set(BOOST_ROOT "C:\\Program Files\\boost_1_55_0")
#set(BOOSTROOT "C:\\Program Files\\boost_1_55_0")
#find_package(Boost 1.55.0)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp pokemonState.h Pokemon.h Move.h)

if (Boost_FOUND)
    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")
    include_directories(${Boost_INCLUDE_DIRS})
endif ()

add_executable(Exam ${SOURCE_FILES})
if (Boost_FOUND)
    target_link_libraries(Exam ${Boost_LIBRARIES})
endif ()