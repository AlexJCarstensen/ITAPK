//
// Created by ubuntuudvikling on 10/10/16.
//

#ifndef EXAM_MOVES_H
#define EXAM_MOVES_H

#include <iostream>
#include "Element.h"
#include "IMove.h"
#include "Pokemon.h"

namespace pokemonGame {

    template<Element* E>
    class AttackMove : public IMove{
    public:
        AttackMove(std::string name, size_t power) :  IMove(E), power_(power), name_(name) {}
        virtual ~AttackMove(){};

        void doMove(Pokemon& pokemon) {
            //TODO: Attack should do damage acording to type and power
            pokemon.setHealth((pokemon.getHealth() - power_));

            if(element_.isSuperEffective(pokemon.getElement()))
            {
                //TODO: Reduce opposing pokemon health much
            }
            else if(element_.isNotEffective(pokemon.getElement()))
            {
                //TODO: Reduce opposing pokemon health not much
            }
            else
            {
                //TODO: Reduce opposing pokemon health normally
            }

        }

    private:
        Element& element_;
        size_t power_;
        std::string name_;

    };
};


#endif //EXAM_MOVES_H
