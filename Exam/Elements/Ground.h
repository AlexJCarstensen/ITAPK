//
// Created by plex on 10/21/16.
//

#ifndef EXAM_GROUND_H
#define EXAM_GROUND_H

#include "IElement.h"

namespace pokemonGame
{
    class Ground : public IElement
    {
    public:
        Ground() = default;

        Elements getElement();

        Elements getWeakness();

        Elements getSuper();

    private:
        Elements elements_{Elements::GROUND};
        Elements weakness_{Elements::WATER};
        Elements super_{Elements::LIGHTNING};
    };
}

#endif //EXAM_GROUND_H
