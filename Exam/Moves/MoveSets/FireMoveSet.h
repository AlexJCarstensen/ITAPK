//
// Created by plex on 10/21/16.
//

#ifndef EXAM_FIREMOVESET_H
#define EXAM_FIREMOVESET_H

#include "../IMoveSet.h"

namespace pokemonGame
{
    class FireMoveSet : public IMoveSet
    {
    public:
        FireMoveSet();

        std::shared_ptr <IMove> getNewMove(int index);
    };
}

#endif //EXAM_FIREMOVESET_H
