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


    class AttackMove : public IMove{
    public:
        AttackMove(Element& e,std::string name, size_t power) :  IMove(e), power_(power), name_(name) {}
        ~AttackMove(){};

        void doMove(IPokemon& pokemon) {
            //TODO: Attack should do damage acording to type and power
            pokemon.setHealth((pokemon.getHealth() - power_));

            if(this->element_.isSuperEffective(pokemon.getElement()))
            {
                //TODO: Reduce opposing pokemon health much
                std::cout << "Move is super effective" << std::endl;
            }
            else if(this->element_.isNotEffective(pokemon.getElement()))
            {
                //TODO: Reduce opposing pokemon health not much
            }
            else
            {
                //TODO: Reduce opposing pokemon health normally
            }

        }

    private:
       // Element& element_;
        size_t power_;
        std::string name_;

    };
};


#endif //EXAM_MOVES_H
