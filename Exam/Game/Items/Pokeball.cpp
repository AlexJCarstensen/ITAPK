//
// Created by ubuntuudvikling on 10/21/16.
//

#include "Pokeball.h"
#include "ItemNames.h"

namespace pokemonGame
{

    Pokeball::Pokeball()
    {
        name_ = itemNames::POKEBALL;
    }

    std::string Pokeball::getItemName()
    {
        return name_;
    }

    bool Pokeball::useItem(IPokemon *pokemon)
    {
        //Making a random number based on level and current hp

        unsigned int chanceHealth = 35 - (pokemon->getMaxHealth() / pokemon->getCurrentHealth());
        unsigned int chanceLevel = pokemon->getLvl() - (pokemon->getLvl() / 5);

        unsigned int catchChange = rand() % 99 + 1;

        if (catchChange >= (chanceHealth + chanceLevel))
        {
            std::cout << pokemon->getName() << " was caught!" << std::endl;
            pokemon->setCaught(true);
        } else
        {
            std::cout << pokemon->getName() << " broke free!" << std::endl;
        }

        return pokemon->isCaught();
    }
}