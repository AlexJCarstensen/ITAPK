//
// Created by stud on 10/18/16.
//

#ifndef EXAM_MOVESETS_H
#define EXAM_MOVESETS_H

#include "../IMoveSet.h"

namespace pokemonGame {

    class GroundMoveSet : public IMoveSet {
    public:
        GroundMoveSet();

        std::shared_ptr<IMove> getNewMove(int index);
    };
}


#endif //EXAM_MOVESETS_H
