//
// Created by stud on 10/19/16.
//

#ifndef EXAM_IMOVESET_H
#define EXAM_IMOVESET_H

#include <iostream>
#include <memory>
#include <vector>
#include "IMove.h"

namespace pokemonGame
{
    class IMoveSet
    {
    public:
        IMoveSet() = default;

        virtual ~IMoveSet() {};

        virtual std::shared_ptr<IMove> getNewMove(int index) = 0;

        int NumberOfMoves()
        {
            return moves_.size();
        };
        std::shared_ptr<IMove> basicMove_;
        std::vector<std::shared_ptr<IMove>> moves_;
    };
}

#endif //EXAM_IMOVESET_H
