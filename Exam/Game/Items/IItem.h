//
// Created by plex on 10/17/16.
//

#ifndef EXAM_ITEMS_H
#define EXAM_ITEMS_H

#include <glob.h>
#include <iostream>
#include "../Pokemon/IPokemon.h"

namespace pokemonGame {
    class IItem {
    public:
        IItem() = default;

        virtual ~IItem() {};

        virtual std::string getItemName() = 0;

        virtual bool useItem(std::shared_ptr<IPokemon> pokemon) = 0;
    };
}

#endif //EXAM_ITEMS_H