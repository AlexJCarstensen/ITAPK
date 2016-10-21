//
// Created by plex on 10/21/16.
//

#include "Ground.h"
namespace pokemonGame
{

    Ground::Ground()
    {
        elementType_ = Elements::GROUND;
        super_ = Elements::FIRE;
        weakness_ = Elements::WATER;
    }
}