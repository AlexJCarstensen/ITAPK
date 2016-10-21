//
// Created by plex on 10/21/16.
//

#include "Ground.h"
namespace pokemonGame
{
    Elements Ground::getElement()
    {
        return elements_;
    }

    Elements Ground::getWeakness()
    {
        return weakness_;
    }

    Elements Ground::getSuper()
    {
        return super_;
    }
}