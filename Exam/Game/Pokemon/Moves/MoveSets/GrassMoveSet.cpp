//
// Created by plex on 10/21/16.
//

#include "GrassMoveSet.h"
#include "../../Elements/Grass.h"
#include "../Move.h"

namespace pokemonGame
{

    GrassMoveSet::GrassMoveSet()
    {
        //Creating moves to put in container
        std::shared_ptr<IElement> grass = std::make_shared<Grass>();
        std::shared_ptr<IMove> razorLeafs = std::make_shared<AttackMove>(grass, "Razor Leafs", 25);
        std::shared_ptr<IMove> megaDrain = std::make_shared<AttackMove>(grass, "Mega drain", 30);
        std::shared_ptr<IMove> absorb = std::make_shared<AttackMove>(grass, "Absorb", 15);
        std::shared_ptr<IMove> solarBeam = std::make_shared<AttackMove>(grass, "Solar Beam", 80);
        std::shared_ptr<IMove> vineWhip = std::make_shared<AttackMove>(grass, "Vine Whip", 45);
        std::shared_ptr<IMove> leafBlade = std::make_shared<AttackMove>(grass, "Leaf Blade", 50);

        //Inserting moves to container
        moves_ = {razorLeafs, megaDrain, absorb, solarBeam, vineWhip, leafBlade};
    }

    std::shared_ptr<IMove> GrassMoveSet::getNewMove(int index)
    {
        if (index >= 0 && index < moves_.size())
            return moves_[index];
        else
            return basicMove_;
    }
}
