//
// Created by plex on 10/21/16.
//

#include "Water.h"

namespace pokemonGame
{
    Elements pokemonGame::Water::getElement()
    {
        return elements_;
    }

    Elements pokemonGame::Water::getWeakness()
    {
        return weakness_;
    }

    Elements pokemonGame::Water::getSuper()
    {
        return super_;
    }
}