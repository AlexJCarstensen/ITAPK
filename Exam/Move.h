//
// Created by ubuntuudvikling on 10/10/16.
//

#ifndef EXAM_MOVES_H
#define EXAM_MOVES_H

#include <iostream>"
#include "Element.h"
#include "IMove.h"
#include "Pokemon.h"

namespace pokemonGame {

    template<Element E>
    class AttackMove : public IMove<E>{
    public:
        AttackMove(size_t power) :  power_(power) {}
        virtual ~AttackMove(){};

        void doMove(Pokemon& pokemon) {
            pokemon.setHealth((pokemon.getHealth() - power_));
        }

    private:
        Element element_;
        size_t power_;

    };
};


#endif //EXAM_MOVES_H
