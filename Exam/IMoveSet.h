//
// Created by stud on 10/19/16.
//

#ifndef EXAM_IMOVESET_H
#define EXAM_IMOVESET_H

#include <iostream>
#include <memory>
#include <vector>
#include "IMove.h"

namespace pokemonGame {

    class IMoveSet {
    public:
        IMoveSet() = default;

        virtual ~IMoveSet() {};

        int NumberOfMoves() {
            return moves_.size();
        };

        virtual std::shared_ptr<IMove> getNewMove(int index) = 0;

    protected:
        std::vector<std::shared_ptr<IMove>> moves_;
        std::shared_ptr<IMove> basicMove_;
    };


}

#endif //EXAM_IMOVESET_H
