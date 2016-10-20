//
// Created by plex on 10/9/16.
//

#ifndef EXAM_POKEMON_H
#define EXAM_POKEMON_H

#include <iostream>
#include <vector>
#include "Element.h"
#include "IMove.h"
#include "IPokemon.h"
#include "Move.h"

namespace pokemonGame {

//TODO make .cpp file
    class Pokemon : public IPokemon {
    public:
        Pokemon(std::string name, std::shared_ptr<Element> element, int lvl, std::vector<std::shared_ptr<IMove>> moves);

        ~Pokemon() {};

        int getCurrentHealth() const;

        int getMaxHealth() const;

        bool reduceCurrentHealth(size_t amount);

        void revive();

        size_t getLvl() const;

        std::string getName() const;

        Element *getElement() const;

        std::vector <std::string> getMoves();

        int DisplayMoves();

        bool isCaught();

        void setCaught(bool isCaught);

        bool doMove(IPokemon *pokemon, int index);

        bool operator==(Pokemon &other) const {
            if (this->element_ == other.element_)
                return true;
            return false;
        }

        bool isFainted();

        void printPokemon();

        void respawn();


    private:
        std::string name_;
        std::shared_ptr<Element> element_;
        size_t lvl_;
        size_t maxHealth_{30};
        int currentHealth_{};
        std::vector<std::shared_ptr<IMove>> moves_;
        bool caught;
        bool fainted_{false};
    };


}

#endif //EXAM_POKEMON_H
