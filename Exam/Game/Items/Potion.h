//
// Created by ubuntuudvikling on 10/21/16.
//

#ifndef EXAM_POTION_H
#define EXAM_POTION_H

#include "IItem.h"

namespace pokemonGame
{
    class Potion : public IItem
    {
    public:
        Potion();

        std::string getItemName();

        bool useItem(IPokemon *pokemon);

    private:
        std::string name_;
    };
}


#endif //EXAM_POTION_H