//
// Created by plex on 10/9/16.
//

#ifndef EXAM_POKEMON_H
#define EXAM_POKEMON_H

#include <iostream>
#include <vector>

namespace pokemonGame
{

    //TODO Metaprogrammering som binary måske????
    enum Element
    {
        Fire,
        Lightning,
        Grass,
        Water,
        Ground

    };

    template<size_t N>
    class Pokemon
    {
    public:
        Pokemon(std::string name, Element element) : name_(name), element_(element), lvl_(N)
        {

        }

    private:
        std::string name_;
        Element element_;
        size_t lvl_;
        std::vector<int> moves_{};
    };

}

#endif //EXAM_POKEMON_H
