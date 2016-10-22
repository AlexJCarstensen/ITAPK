//
// Created by ubuntuudvikling on 10/21/16.
//

#include "Revive.h"
#include "ItemNames.h"

namespace pokemonGame
{
    Revive::Revive()
    {
        name_ = itemNames::REVIVE;
    }

    std::string Revive::getItemName()
    {
        return name_;
    }

    bool Revive::useItem(std::shared_ptr<IPokemon> pokemon)
    {
        bool revived = false;

        if (pokemon->isFainted())
        {
            pokemon->revive();
            revived = true;
        }

        return revived;
    }
}