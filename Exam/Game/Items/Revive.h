//
// Created by ubuntuudvikling on 10/21/16.
//

#ifndef EXAM_REVIVE_H
#define EXAM_REVIVE_H

#include "IItem.h"

namespace pokemonGame
{
    class Revive : public IItem
    {
    public:
        Revive();

        std::string getItemName();

        bool useItem(IPokemon *pokemon);

    private:
        std::string name_;
    };
}

#endif //EXAM_REVIVE_H