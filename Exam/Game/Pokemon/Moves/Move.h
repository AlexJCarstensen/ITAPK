//
// Created by ubuntuudvikling on 10/10/16.
//

#ifndef EXAM_MOVES_H
#define EXAM_MOVES_H

#include <iostream>

#include "../Elements/IElement.h"
#include "IMove.h"
#include "../Pokemon.h"


namespace pokemonGame {

    class AttackMove : public IMove {
    public:
        AttackMove(std::shared_ptr<IElement> e, std::string name, size_t power);

        bool doMove(int lvl, IPokemon* pokemon);

        std::string getMoveName();

    private:
        size_t power_;
        std::string name_;
    };
}

#endif //EXAM_MOVES_H
