//
// Created by ubuntuudvikling on 10/19/16.
//

#include "Shop.h"

namespace pokemonGame {
    pokemonGame::Shop::Shop() {

        std::vector<std::shared_ptr<IItem>> potions;
        std::vector<std::shared_ptr<IItem>> pokeballs;
        std::vector<std::shared_ptr<IItem>> revives;

        for (int i = 0; i < 20; ++i) {
            potions.push_back(std::make_shared<Potion>());

            pokeballs.push_back(std::make_shared<Pokeball>());
            revives.push_back(std::make_shared<Revive>());
        }

        items_ = {std::make_pair("Potions", std::move(potions)), std::make_pair("Pokeballs", std::move(pokeballs)),
                  std::make_pair("Revives", std::move(revives))};
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

    int pokemonGame::Shop::buyItem(std::string item, int quantity, Player *player) {

        if (items_.find(item)->second.empty())
            std::cout << "We are all out of " << item << std::endl;
        else {

            if (quantity > items_.find(item)->second.size()) {
                int sizeOfVector = items_.find(item)->second.size();
                for (int i = 0; i < sizeOfVector; i++) {
                    auto it = std::prev(items_.find(item)->second.end());
                    player->addItem(item, std::move(*it));
                    it->reset();
                    items_.find(item)->second.pop_back();
                }
            } else {
                for (int i = 0; i < quantity; i++) {
                    auto it = std::prev(items_.find(item)->second.end());
                    player->addItem(item, std::move(*it));
                    it->reset();
                    items_.find(item)->second.pop_back();

                }
            }
        }
    }


}