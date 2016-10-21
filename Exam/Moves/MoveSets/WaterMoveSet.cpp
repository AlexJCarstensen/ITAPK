//
// Created by plex on 10/21/16.
//

#include "WaterMoveSet.h"
#include "../../Elements/Water.h"
#include "../Move.h"

namespace pokemonGame
{
    WaterMoveSet::WaterMoveSet()
    {
        //Creating moves to put in container
        std::shared_ptr<IElement> water = std::make_shared<Water>();
        std::shared_ptr<IMove> watergun = std::make_shared<AttackMove>(water, "Water gun", 15);
        std::shared_ptr<IMove> hydroPump = std::make_shared<AttackMove>(water, "Hydro pump", 80);
        std::shared_ptr<IMove> bubbleBeam = std::make_shared<AttackMove>(water, "Bubble beam", 40);
        std::shared_ptr<IMove> bubble = std::make_shared<AttackMove>(water, "Bubble", 25);
        std::shared_ptr<IMove> aquaTail = std::make_shared<AttackMove>(water, "Aqua tail", 30);
        std::shared_ptr<IMove> surf = std::make_shared<AttackMove>(water, "Surf", 50);

        //Inserting moves to container
        moves_ = {watergun, hydroPump, bubbleBeam, bubble, aquaTail, surf};
    }

    std::shared_ptr<IMove> WaterMoveSet::getNewMove(int index)
    {
        if (index >= 0 && index < moves_.size())
            return moves_[index];
        else
            return basicMove_;
    }
}
