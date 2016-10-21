//
// Created by plex on 10/21/16.
//

#ifndef EXAM_WATER_H
#define EXAM_WATER_H

#include "Element.h"

namespace pokemonGame
{
    class Water : public Element
    {
    public:
        Water() = default;

        Elements getElement();

        Elements getWeakness();

        Elements getSuper();

    private:
        Elements elements_{Elements::WATER};
        Elements weakness_{Elements::LIGHTNING};
        Elements super_{Elements::GROUND};
    };
}

#endif //EXAM_WATER_H
