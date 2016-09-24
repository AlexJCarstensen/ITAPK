cmake_minimum_required(VERSION 3.6)
project(TimerCallback)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Timer.h Events.h BindFunction.h)
add_executable(TimerCallback ${SOURCE_FILES})
find_package(Boost 1.58.0 COMPONENTS system filesystem REQUIRED)
if(Boost_FOUND)
    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")
    include_directories(${Boost_INCLUDE_DIRS})
endif()

add_executable(BoostTest main.cpp)
if(Boost_FOUND)
    target_link_libraries(BoostTest ${Boost_LIBRARIES})
endif()