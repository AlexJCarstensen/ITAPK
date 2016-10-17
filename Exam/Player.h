//
// Created by plex on 10/17/16.
//

#ifndef EXAM_PLAYER_H
#define EXAM_PLAYER_H

#include <vector>
#include "Item.h"

namespace pokemonGame{
class Player
{
public:
    Player();
    virtual ~Player();

private:
    std::vector<Item> items_;

};
}


#endif //EXAM_PLAYER_H
