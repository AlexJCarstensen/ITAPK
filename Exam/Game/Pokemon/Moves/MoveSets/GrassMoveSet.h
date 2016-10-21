//
// Created by plex on 10/21/16.
//

#ifndef EXAM_GRASSMOVESET_H
#define EXAM_GRASSMOVESET_H


#include "../IMoveSet.h"

namespace pokemonGame
{
    class GrassMoveSet : public IMoveSet
    {
    public:
        GrassMoveSet();

        std::shared_ptr <IMove> getNewMove(int index);
    };
}


#endif //EXAM_GRASSMOVESET_H
