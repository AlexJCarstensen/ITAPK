//
// Created by ubuntuudvikling on 10/21/16.
//

#include "Potion.h"
#include "ItemNames.h"

namespace pokemonGame
{

    Potion::Potion()
    {
        name_ = itemNames::POTION;
    }

    std::string Potion::getItemName()
    {
        return name_;
    }

    bool Potion::useItem(std::shared_ptr<IPokemon> pokemon)
    {
        if (pokemon->getCurrentHealth() == pokemon->getMaxHealth() || pokemon->isFainted())
        { return false; }
        else
        {
            unsigned int healthDif = pokemon->getMaxHealth() - pokemon->getCurrentHealth();

            if (healthDif < 20)
            { pokemon->reduceCurrentHealth(pokemon->getCurrentHealth() + healthDif); }
            else
            { pokemon->reduceCurrentHealth(pokemon->getCurrentHealth() + 20); }

            return true;
        }
    }
}