//
// Created by plex on 10/17/16.
//

#include "Item.h"
namespace pokemonGame
{


    Item::Item()
    {

    }

    Item::~Item()
    {

    }

    unsigned char Item::getItemsCount()
    {
        return itemsCount_;
    }

    std::string Item::getItemName()
    {
        return itemName_;
    }
}