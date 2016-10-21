//
// Created by plex on 10/21/16.
//

#include "LightningMoveSet.h"
#include "../../Elements/Lightning.h"
#include "../Move.h"

namespace pokemonGame{


    LightningMoveSet::LightningMoveSet()
    {
        //Creating moves to put in container
        std::shared_ptr<IElement> lightning = std::make_shared<Lightning>();
        std::shared_ptr<IMove> thunderbolt = std::make_shared<AttackMove>(lightning, "Thunderbolt", 80);
        std::shared_ptr<IMove> thunder = std::make_shared<AttackMove>(lightning, "Thunder", 15);
        std::shared_ptr<IMove> thundershock = std::make_shared<AttackMove>(lightning, "Thundershock", 50);
        std::shared_ptr<IMove> thunderpunch = std::make_shared<AttackMove>(lightning, "Thunder punch", 25);
        std::shared_ptr<IMove> charge = std::make_shared<AttackMove>(lightning, "Charge", 30);
        std::shared_ptr<IMove> voltTackle = std::make_shared<AttackMove>(lightning, "Volt tackle", 45);

        //Inserting moves to container
        moves_ = {thunderbolt, thunder, thundershock, thunderpunch, charge, voltTackle};
    }

    std::shared_ptr<IMove> LightningMoveSet::getNewMove(int index)
    {
        if (index >= 0 && index < moves_.size())
            return moves_[index];
        else
            return basicMove_;
    }
}

