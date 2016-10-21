//
// Created by ubuntuudvikling on 10/21/16.
//

#ifndef EXAM_POKEBALL_H
#define EXAM_POKEBALL_H

#include "IItem.h"

namespace pokemonGame
{

    class Pokeball : public IItem
    {
    public:
        Pokeball();

        std::string getItemName();

        bool useItem(IPokemon *pokemon);

    private:
        std::string name_;

    };
}

#endif //EXAM_POKEBALL_H