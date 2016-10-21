//
// Created by plex on 10/21/16.
//

#include "FireMoveSet.h"
#include "../../Elements/Fire.h"
#include "../Move.h"

namespace pokemonGame
{
    FireMoveSet::FireMoveSet()
    {
        //Creating moves to put in container
        std::shared_ptr<IElement> fire = std::make_shared<Fire>();
        std::shared_ptr<IMove> fireBlast = std::make_shared<AttackMove>(fire, "Fire Blast", 80);
        std::shared_ptr<IMove> ember = std::make_shared<AttackMove>(fire, "Ember", 15);
        std::shared_ptr<IMove> flamethrower = std::make_shared<AttackMove>(fire, "Flamethrower", 50);
        std::shared_ptr<IMove> fireFang = std::make_shared<AttackMove>(fire, "Fire fang", 25);
        std::shared_ptr<IMove> fireSpin = std::make_shared<AttackMove>(fire, "Firespin", 30);
        std::shared_ptr<IMove> firePunch = std::make_shared<AttackMove>(fire, "Fire Punch", 45);

        //Inserting moves to container
        moves_ = {fireBlast, ember, flamethrower, fireFang, fireSpin, firePunch};
    }

    std::shared_ptr<IMove> FireMoveSet::getNewMove(int index)
    {
        if (index >= 0 && index < moves_.size())
            return moves_[index];
        else
            return basicMove_;
    }
}




