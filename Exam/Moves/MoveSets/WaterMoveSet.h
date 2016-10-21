//
// Created by plex on 10/21/16.
//

#ifndef EXAM_WATERMOVESET_H
#define EXAM_WATERMOVESET_H

#include "../IMoveSet.h"

namespace pokemonGame
{
    class WaterMoveSet : public IMoveSet
    {
    public:

        WaterMoveSet();

        std::shared_ptr <IMove> getNewMove(int index);
    };
}


#endif //EXAM_WATERMOVESET_H
