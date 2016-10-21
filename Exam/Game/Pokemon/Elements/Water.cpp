//
// Created by plex on 10/21/16.
//

#include "Water.h"

namespace pokemonGame
{
    Water::Water()
    {
        elementType_ = Elements::WATER;
        super_ = Elements::FIRE;
        weakness_ = Elements::GRASS;
    }
}