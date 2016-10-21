//
// Created by stud on 10/20/16.
//

#include <memory>
#include "Move.h"

namespace pokemonGame
{

    AttackMove::AttackMove(std::shared_ptr<IElement> e, std::string name, size_t power)
            : IMove(e), power_(power), name_(name) { isAttack_ = true; }

    bool AttackMove::doMove(int lvl, IPokemon *pokemon)
    {
        bool killingBlow;

        double lvlDif = (double)lvl - (double)pokemon->getLvl();

        double powerFromLevelDif = lvlDif /30;

        if (this->element_.get()->isSuperEffective(pokemon->getElement()))
        {
            //Reduce opposing pokemon health significantly
            std::cout << "It was super effective!" << std::endl;
            killingBlow = pokemon->reduceCurrentHealth(power_ * (1.5 + powerFromLevelDif));
        } else if (this->element_.get()->isNotEffective(pokemon->getElement()))
        {
            //Reduce opposing pokemon health slightly
            std::cout <<" it was not very effective.." << std::endl;
            killingBlow = pokemon->reduceCurrentHealth(power_ * (0.5 + powerFromLevelDif));
        } else
        {
            //Reduce opposing pokemon health normally
            std::cout << "It was normally effective" << std::endl;
            killingBlow = pokemon->reduceCurrentHealth(power_ + (10 * powerFromLevelDif));
        }

        return killingBlow;
    }

    std::string AttackMove::getMoveName() { return name_; }
}
