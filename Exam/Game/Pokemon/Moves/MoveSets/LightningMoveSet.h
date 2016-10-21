//
// Created by plex on 10/21/16.
//

#ifndef EXAM_LIGHTNINGMOVESET_H
#define EXAM_LIGHTNINGMOVESET_H


#include "../IMoveSet.h"

namespace pokemonGame
{
    class LightningMoveSet : public IMoveSet
    {
    public:
        LightningMoveSet();

        std::shared_ptr <IMove> getNewMove(int index);
    };
}


#endif //EXAM_LIGHTNINGMOVESET_H
