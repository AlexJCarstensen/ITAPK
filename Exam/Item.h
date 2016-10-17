//
// Created by plex on 10/17/16.
//

#ifndef EXAM_ITEMS_H
#define EXAM_ITEMS_H

#include <glob.h>
#include <iostream>
namespace pokemonGame
{
    class Item
    {
    public:
        Item();

        virtual ~Item();
        unsigned char getItemsCount();
        std::string getItemName();

    private:
        unsigned char itemsCount_{};
        std::string itemName_{};
    };
}

#endif //EXAM_ITEMS_H
