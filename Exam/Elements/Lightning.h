//
// Created by plex on 10/21/16.
//

#ifndef EXAM_LIGHTNING_H
#define EXAM_LIGHTNING_H

#include "IElement.h"

namespace pokemonGame
{
    class Lightning : public IElement
    {
    public:
        Lightning() {};

        Elements getElement();

        Elements getWeakness();

        Elements getSuper();

    private:
        Elements elements_{Elements::LIGHTNING};
        Elements weakness_{Elements::GROUND};
        Elements super_{Elements::WATER};
    };
}

#endif //EXAM_LIGHTNING_H
