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

//TODO make .cpp file
    class AttackMove : public IMove {
    public:
        AttackMove(std::shared_ptr<Element> e, std::string name, size_t power) : IMove(e), power_(power), name_(name) {isAttack_ = true;}

        ~AttackMove() {};

        void doMove(IPokemon* pokemon) {

            Element *someElement = pokemon->getElement();

            int someElementInt = (int)someElement->getElement();

            int thisElementInt = (int)this->element_.get()->getElement();

            if (this->element_.get()->isSuperEffective(pokemon->getElement())) {
                //Reduce opposing pokemon health significantly
                std::cout << name_ << " was super effective!" << std::endl;
                pokemon->setCurrentHealth((pokemon->getHealth() - (power_ * 1.5)));
            } else if (this->element_.get()->isNotEffective(pokemon->getElement())) {
                //Reduce opposing pokemon health slightly
                std::cout << name_ <<" is not very effective.." << std::endl;
                pokemon->setCurrentHealth((pokemon->getHealth() - (power_ * 0.5)));
            } else {
                //Reduce opposing pokemon health normally
                std::cout << name_ << " is normally effective" << std::endl;
                pokemon->setCurrentHealth((pokemon->getHealth() - power_));
            }

        }

        std::string getMoveName() { return name_; }

    private:
        size_t power_;
        std::string name_;

    };







}


#endif //EXAM_MOVES_H
