//
// Created by stud on 10/20/16.
//

#include <memory>
#include "Move.h"

namespace pokemonGame {

    AttackMove::AttackMove(std::shared_ptr<Element> e, std::string name, size_t power): IMove(e), power_(power), name_(name) {isAttack_ = true;}

    void AttackMove::doMove(IPokemon *pokemon)
    {
        Element *someElement = pokemon->getElement();

        int someElementInt = (int)someElement->getElement();

        int thisElementInt = (int)this->element_.get()->getElement();

        if (this->element_.get()->isSuperEffective(pokemon->getElement())) {
            //Reduce opposing pokemon health significantly
            std::cout << name_ << " was super effective!" << std::endl;
            pokemon->setCurrentHealth((pokemon->getMaxHealth() - (power_ * 1.5)));
        } else if (this->element_.get()->isNotEffective(pokemon->getElement())) {
            //Reduce opposing pokemon health slightly
            std::cout << name_ <<" is not very effective.." << std::endl;
            pokemon->setCurrentHealth((pokemon->getMaxHealth() - (power_ * 0.5)));
        } else {
            //Reduce opposing pokemon health normally
            std::cout << name_ << " is normally effective" << std::endl;
            pokemon->setCurrentHealth((pokemon->getMaxHealth() - power_));
        }

    }

    std::string AttackMove::getMoveName() { return name_;}
}
