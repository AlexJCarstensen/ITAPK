//
// Created by plex on 10/21/16.
//

#include "GroundMoveSet.h"
#include "../../Elements/Ground.h"
#include "../Move.h"

namespace pokemonGame
{
    pokemonGame::GroundMoveSet::GroundMoveSet()
    {
        //Creating moves to put in container
        std::shared_ptr<IElement> ground = std::make_shared<Ground>();
        std::shared_ptr<IMove> earthquake = std::make_shared<AttackMove>(ground, "Earthquake", 100);
        std::shared_ptr<IMove> dig = std::make_shared<AttackMove>(ground, "Dig", 50);
        std::shared_ptr<IMove> mudShot = std::make_shared<AttackMove>(ground, "Mud shot", 35);
        std::shared_ptr<IMove> bullDoze = std::make_shared<AttackMove>(ground, "Bulldoze", 25);
        std::shared_ptr<IMove> mudSlap = std::make_shared<AttackMove>(ground, "Mud slap", 15);
        std::shared_ptr<IMove> fissure = std::make_shared<AttackMove>(ground, "Fissure", 40);

        //Inserting moves to container
        moves_ = {earthquake, dig, mudShot, bullDoze, mudSlap, fissure};
    }

    std::shared_ptr<pokemonGame::IMove> pokemonGame::GroundMoveSet::getNewMove(int index)
    {
        if (index >= 0 && index < moves_.size())
            return moves_[index];
        else
            return basicMove_;
    }
}