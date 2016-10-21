//
// Created by plex on 10/21/16.
//

#include "Grass.h"
namespace pokemonGame{

    Elements Grass::getElement()
    {
        return elements_;
    }

    Elements Grass::getWeakness()
    {
        return weakness_;
    }

    Elements Grass::getSuper()
    {
        return super_;
    }
}