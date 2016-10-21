cmake_minimum_required(VERSION 3.6)
project(Exam)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp Game/States/pokemonState.h Game/Pokemon/Pokemon.h Game/Pokemon/Moves/Move.h Game/Game.h Game/Game.cpp Game/Pokemon/Moves/IMove.h Game/Pokemon/IPokemon.h Game/Player/Player.cpp Game/Player/Player.h Game/Items/IItem.h Game/Items/ItemNames.h Game/Items/Pokeball.h Game/Items/Pokeball.cpp Game/Items/Potion.h Game/Items/Potion.cpp Game/Items/Revive.h Game/Items/Revive.cpp Game/States/printStates.h Game/States/GameState.h Game/Pokemon/Moves/MoveSets/GroundMoveSet.h Game/Pokemon/Moves/MoveChoosers.h Game/Exception/NoFavoritePokemonException.h Game/Shop/Shop.cpp Game/Shop/Shop.h Game/Pokemon/Moves/IMoveSet.h Game/Pokemon/Moves/Move.cpp Game/Pokemon/Pokemon.cpp Game/Pokemon/Elements/Elements.h Game/Pokemon/Elements/IElement.h Game/Pokemon/Elements/Fire.h Game/Pokemon/Elements/Fire.cpp Game/Pokemon/Elements/Grass.h Game/Pokemon/Elements/Grass.cpp Game/Pokemon/Elements/Ground.h Game/Pokemon/Elements/Ground.cpp Game/Pokemon/Elements/Lightning.h Game/Pokemon/Elements/Lightning.cpp Game/Pokemon/Elements/Water.h Game/Pokemon/Elements/Water.cpp
        Game/Pokemon/Moves/MoveSets/FireMoveSet.h Game/Pokemon/Moves/MoveSets/FireMoveSet.cpp Game/Pokemon/Moves/MoveSets/GrassMoveSet.h Game/Pokemon/Moves/MoveSets/GrassMoveSet.cpp Game/Pokemon/Moves/MoveSets/GroundMoveSet.h Game/Pokemon/Moves/MoveSets/GroundMoveSet.cpp Game/Pokemon/Moves/MoveSets/LightningMoveSet.h Game/Pokemon/Moves/MoveSets/LightningMoveSet.cpp Game/Pokemon/Moves/MoveSets/WaterMoveSet.h Game/Pokemon/Moves/MoveSets/WaterMoveSet.cpp Game/Items/ItemNames.h Game/Exception/NoNamePokemonException.h)

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