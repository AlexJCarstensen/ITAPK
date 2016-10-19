//
// Created by plex on 10/17/16.
//

#ifndef EXAM_ITEMS_H
#define EXAM_ITEMS_H

#include <glob.h>
#include <iostream>
#include "IPokemon.h"
namespace pokemonGame
{
    class IItem
    {
    public:
        IItem() = default;

        virtual ~IItem();
        virtual std::string getItemName() = 0;
        virtual bool useItem(IPokemon* pokemon) = 0;

    };

    class Potion : public IItem
    {
    public:
        Potion(){
         name_ = "Potion";
        }

        ~Potion(){}

        std::string getItemName(){return name_;}
        bool useItem(IPokemon* pokemon)
        {
            if(pokemon->getCurrentHealth() == pokemon->getHealth())
            {return false;}
            else
            {
                unsigned int healthDif = pokemon->getHealth() - pokemon->getCurrentHealth();

                if(healthDif < 20)
                {pokemon->setCurrentHealth(pokemon->getCurrentHealth() + healthDif);}
                else
                {pokemon->setCurrentHealth(pokemon->getCurrentHealth() + 20);}

                return true;
            }

        }


    private:
        std::string name_;

    };

    class Pokeball : public IItem
    {
    public:
        Pokeball(){
            name_ = "PokeBall";
        }
        ~Pokeball(){};

        std::string getItemName(){return name_;}
        bool useItem(IPokemon* pokemon)
        {
            //Making a random number based on level and current hp

            unsigned int chanceHealth = 35 - (pokemon->getHealth()/pokemon->getCurrentHealth());
            unsigned int chanceLevel = pokemon->getLvl() - (pokemon->getLvl()/5);

            unsigned int catchChange = rand() % 99 + 1;

            if(catchChange <= (chanceHealth + chanceLevel))
            {
                pokemon->setCaught(true);
            }


            return pokemon->isCaught();

        }

    private:
        std::string name_;

    };

    class Revive : public IItem
    {
    public:

        Revive()
        {
            name_ = "Revive";
        }

        ~Revive(){};

        std::string getItemName(){return name_;}
        bool useItem(IPokemon* pokemon)
        {
            if(pokemon->isFainted())
            {
                pokemon->setCurrentHealth(pokemon->getHealth()/2);
            }
        }
    private:
        std::string name_;
    };
}

#endif //EXAM_ITEMS_H
