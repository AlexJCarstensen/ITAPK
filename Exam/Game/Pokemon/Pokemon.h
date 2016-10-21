//
// Created by plex on 10/9/16.
//

#ifndef EXAM_POKEMON_H
#define EXAM_POKEMON_H

#include <iostream>
#include <vector>
#include "Elements/IElement.h"
#include "Moves/IMove.h"
#include "IPokemon.h"
#include "Moves/Move.h"

namespace pokemonGame
{

//TODO make .cpp file
    class Pokemon : public IPokemon
    {
    public:
        Pokemon(std::string name, std::shared_ptr<IElement> element, int lvl,
                std::vector<std::shared_ptr<IMove>> moves);

        ~Pokemon() {};

        void setCaught(bool isCaught);

        void printPokemon();

        void revive();

        void respawn();

        int getCurrentHealth() const;

        int getMaxHealth() const;

        int DisplayMoves();

        bool isCaught();

        bool isFainted();

        bool doMove(IPokemon *pokemon, int index);

        bool reduceCurrentHealth(size_t amount);

        size_t getLvl() const;

        std::string getName() const;

//TODO return shared ptr instead??
        std::shared_ptr<IElement> getElement() const;

        std::vector<std::string> getMoves();

        bool operator==(Pokemon &other) const
        {
            if (this->element_ == other.element_)
                return true;
            return false;
        }
    private:
        std::string name_;
        std::shared_ptr<IElement> element_;
        size_t lvl_;
        size_t maxHealth_{30};
        int currentHealth_{};
        std::vector<std::shared_ptr<IMove>> moves_;
        bool caught{false};
        bool fainted_{false};
    };
}

#endif //EXAM_POKEMON_H
