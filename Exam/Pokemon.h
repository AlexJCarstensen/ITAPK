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
        Pokemon(std::string name, std::shared_ptr<Element> element, int lvl, std::vector<std::shared_ptr<IMove>> moves)
                : name_(name), element_(element), lvl_(lvl), moves_(moves) {
            if (lvl_ > 1)
                health_ = health_ + lvl_ * 1.5;
            currentHealth_ = health_;
        }

        ~Pokemon() {};

        int getCurrentHealth() const { return currentHealth_; }

        int getHealth() const { return health_; }

        int setCurrentHealth(size_t newHealth) {
            currentHealth_ = newHealth;

            if (currentHealth_ <= 0) {
                currentHealth_ = 0;
                fainted_ = true;
            } else {
                fainted_ = false;
            }
        }

        size_t getLvl() const { return lvl_; }

        std::string getName() const { return name_; }

        Element *getElement() const { return element_.get(); }

        std::vector<std::string> getMoves() {
            std::vector<std::string> moveNames;
            for (int i = 0; i < moves_.size(); ++i) {

                std::string move = moves_[i].get()->getMoveName();
                moveNames.push_back(move);

            }

            return moveNames;
        }

        int DisplayMoves() {
            int number = 0;
            for (auto &&move : moves_) {
                std::cout << ++number << ". " << move.get()->getMoveName() << std::endl;
            }
            return number;
        }


        bool isCaught() { return caught; }

        void setCaught(bool isCaught) { caught = isCaught; }

        bool doMove(IPokemon *pokemon, int index) {
            if (moves_[index]->isAttack()) {
                moves_[index]->doMove(pokemon);
            } else {
                //TODO: make ultility moves and utility attacks like sleep
                moves_[index]->doMove(this);
            }

        }


        bool operator==(Pokemon &other) const {
            if (this->element_ == other.element_)
                return true;
            return false;
        }

        bool isFainted() { return fainted_; }

        void printPokemon() {
            std::cout << getName() << "\t" << "Lvl: " << getLvl() << std::endl;
            std::cout << getName() << " has " << getCurrentHealth() << " hp out of " << getHealth() << "hp";
        }


    private:
        std::string name_;
        std::shared_ptr<Element> element_;
        size_t lvl_;
        size_t health_{30};
        size_t currentHealth_{};
        std::vector<std::shared_ptr<IMove>> moves_;
        bool caught;
        bool fainted_{false};
    };


}

#endif //EXAM_POKEMON_H
