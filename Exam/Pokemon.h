//
// Created by plex on 10/9/16.
//

#ifndef EXAM_POKEMON_H
#define EXAM_POKEMON_H

#include <iostream>
#include <vector>
#include "Element.h"
#include "IMove.h"

namespace pokemonGame
{


    class Pokemon
    {
    public:
        Pokemon(std::string name, Element& element, size_t lvl) : name_(name), element_(element), lvl_(lvl)
        {
            if(lvl_ > 1)
                health_ = health_ + lvl_ * 1.5;


        }
        int getHealth(){return health_;}
        int setHealth(size_t newHealth){health_ = newHealth;}

        bool operator==(Pokemon& other)const {
            if (this->element_ == other.element_)
                return true;
            return false;
        }
    private:
        std::string name_;
        Element& element_;
        size_t lvl_;
        size_t health_{30};
        std::vector<IMove> moves_;
    };

}

#endif //EXAM_POKEMON_H
