//
// Created by ubuntuudvikling on 10/19/16.
//

#include "Shop.h"

namespace pokemonGame {
    pokemonGame::Shop::Shop() {

        std::vector<IItem *> potions;
        std::vector<IItem *> pokeballs;
        std::vector<IItem *> revives;

        for (int i = 0; i < 20; ++i) {
            potions.push_back(new Potion());
            pokeballs.push_back(new Pokeball());
            revives.push_back(new Revive());
        }
        items_ = {std::make_pair("Potions", potions), std::make_pair("Pokeballs", pokeballs),
                  std::make_pair("Revives", revives)};
    }

    pokemonGame::Shop::~Shop() {
        //TODO destruct items
    }

    void pokemonGame::Shop::listItems() {
        std::cout << "Welcome to the shop! How may I assist you?" << std::endl;
        std::cout << "I have the following items for sale" << std::endl;

        std::cout << items_.find("Potions")->first << " x " << items_.find("Potions")->second.size() << std::endl;
        std::cout << items_.find("Pokeballs")->first << " x " << items_.find("Pokeballs")->second.size() << std::endl;
        std::cout << items_.find("Revives")->first << " x " << items_.find("Revives")->second.size() << std::endl;
    }

    pokemonGame::IItem *pokemonGame::Shop::buyItem(int number) {
//TODO how do we do this
        switch (number) {
            case 1: {
                if (items_.find("Potions")->second.empty()) {
                    std::cout << "We are all out of Potions" << std::endl;
                    return nullptr;
                } else {
                    return items_.find("Potions")->second.front();
                }
            }
        }
    }
}