//
// Created by plex on 10/17/16.
//

#ifndef EXAM_ITEMS_H
#define EXAM_ITEMS_H

#include <glob.h>
namespace pokemonGame
{
    class Item
    {
    public:
        Item();

        virtual ~Item();

    private:
        unsigned char itemsCount_{};
    };
}

#endif //EXAM_ITEMS_H
