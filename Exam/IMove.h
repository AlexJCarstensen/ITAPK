//
// Created by ubuntuudvikling on 10/10/16.
//

#ifndef EXAM_IMOVE_H
#define EXAM_IMOVE_H

#include "Element.h"
namespace pokemonGame {
    class IMove {
    public:
        IMove() = default;
        IMove(Element* element) : element_(element){}

        virtual ~IMove();

        virtual void doMove() = 0;

    private:
        Element* element_;
    };
}
#endif //EXAM_IMOVE_H
