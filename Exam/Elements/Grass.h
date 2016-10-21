//
// Created by plex on 10/21/16.
//

#ifndef EXAM_GRASS_H
#define EXAM_GRASS_H

#include "Element.h"

namespace pokemonGame
{
    class Grass : public Element
    {
    public:
        Grass() = default;

        Elements getElement();

        Elements getWeakness();

        Elements getSuper();

    private:
        Elements elements_{Elements::GRASS};
        Elements weakness_{Elements::FIRE};
        Elements super_{Elements::WATER};
    };
}


#endif //EXAM_GRASS_H
