//
// Created by stud on 10/20/16.
//

#include <memory>
#include "Pokemon.h"

namespace pokemonGame {

    Pokemon::Pokemon(std::string name, std::shared_ptr<IElement> element, int lvl,
                     std::vector<std::shared_ptr<IMove>> moves) : name_(name), element_(element), lvl_(lvl),
                                                                  moves_(moves) {
        if (lvl_ > 1)
            maxHealth_ = maxHealth_ + lvl_ * 1.5;
        currentHealth_ = maxHealth_;
    }

    IElement *Pokemon::getElement() const { return element_.get(); }

    int Pokemon::DisplayMoves() {
        int number = 0;
        for (auto &&move : moves_) {
            std::cout << ++number << ". " << move.get()->getMoveName() << std::endl;
        }
        return number;
    }

    bool Pokemon::doMove(IPokemon *pokemon, int index) {

        bool killingBlow = false;

        if (moves_[index]->isAttack()) {
            killingBlow = moves_[index]->doMove(pokemon);
        } else {
            //TODO: make ultility moves and utility attacks like sleep
            moves_[index]->doMove(this);
        }

        return killingBlow;

    }

    int Pokemon::getCurrentHealth() const { return currentHealth_; }

    int Pokemon::getMaxHealth() const { return maxHealth_; }

    size_t Pokemon::getLvl() const { return lvl_; }

    std::vector<std::string> Pokemon::getMoves() {
        std::vector<std::string> moveNames;
        for (int i = 0; i < moves_.size(); ++i) {

            std::string move = moves_[i].get()->getMoveName();
            moveNames.push_back(move);

        }

        return moveNames;
    }

    std::string Pokemon::getName() const { return name_; }

    bool Pokemon::isCaught() { return caught; }

    bool Pokemon::isFainted() { return fainted_; }

    void Pokemon::printPokemon() {
        std::cout << getName() << "\t" << "Lvl: " << getLvl() << std::endl;
        std::cout << getName() << " has " << getCurrentHealth() << " hp out of " << getMaxHealth() << "hp";
    }

    void Pokemon::setCaught(bool isCaught) { caught = isCaught; }

    bool Pokemon::reduceCurrentHealth(size_t amount) {
        currentHealth_ = currentHealth_- amount;

        if (currentHealth_ <= 0) {
            currentHealth_ = 0;
            fainted_ = true;

        } else {
            fainted_ = false;
        }

        return fainted_;
    }

    void Pokemon::respawn() {

        currentHealth_ = maxHealth_;

    }

    void Pokemon::revive() {

        currentHealth_ = maxHealth_/2;

    }


}

