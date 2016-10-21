cmake_minimum_required(VERSION 3.6)
project(Exam)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp pokemonState.h Pokemon.h Move.h Game.h Game.cpp IMove.h IPokemon.h Player.cpp Player.h IItem.h macro.h GameState.h MoveSets.h MoveChoosers.h NoFavoritePokemonException.h Shop.cpp Shop.h IMoveSet.h Move.cpp Pokemon.cpp Elements/Elements.h Elements/Element.h Elements/Fire.h Elements/Fire.cpp Elements/Grass.h Elements/Grass.cpp Elements/Ground.h Elements/Ground.cpp Elements/Lightning.h Elements/Lightning.cpp Elements/Water.h Elements/Water.cpp)
#Elements files
#set(SOURCE_FILES )
#set(SOURCE_FILES main.cpp pokemonState.h Pokemon.h Move.h Game.h Game.cpp IMove.h Elements/Element.h IPokemon.h Player.cpp Player.h IItem.h macro.h GameState.h MoveSets.h MoveChoosers.h NoFavoritePokemonException.h Shop.cpp Shop.h IMoveSet.h Move.cpp Pokemon.cpp Elements/Fire.h Elements/Fire.cpp Elements/Water.h Elements/Water.cpp)

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