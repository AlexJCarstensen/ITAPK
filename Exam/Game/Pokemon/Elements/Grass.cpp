//
// Created by plex on 10/21/16.
//

#include "Grass.h"
namespace pokemonGame{

    Grass::Grass()
    {
        elementType_ = Elements::GRASS;
        super_ = Elements::WATER;
        weakness_ = Elements::FIRE;
    }
}