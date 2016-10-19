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
        virtual unsigned int getItemsCount() = 0;
        virtual std::string getItemName() = 0;
        virtual void useItem(IPokemon* pokemon) = 0;

    };

    class Potion : public IItem
    {
    public:
        Potion();

        unsigned int getItemCount(){return count_;}
        std::string getItemName(){return name_;}
        void useItem(IPokemon* pokemon)
        {
            //pokemon.setHealth(pokemon.getHealth())
        }


    private:
        unsigned int count_;
        std::string name_;

    };
}

#endif //EXAM_ITEMS_H
