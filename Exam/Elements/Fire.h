//
// Created by plex on 10/21/16.
//

#ifndef EXAM_FIRE_H
#define EXAM_FIRE_H

#include "IElement.h"

namespace pokemonGame
{
    class Fire : public IElement
    {
    public:
        Fire() = default;

        Elements getElement();

        Elements getWeakness();

        Elements getSuper();

    private:
        Elements elements_{Elements::FIRE};
        Elements weakness_{Elements::WATER};
        Elements super_{Elements::GRASS};
    };
}

#endif //EXAM_FIRE_H
