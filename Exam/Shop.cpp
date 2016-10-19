//
// Created by ubuntuudvikling on 10/19/16.
//

#include "Shop.h"

pokemonGame::Shop::Shop() {

    std::vector<IItem*> potions;
    std::vector<IItem*> pokeballs;
    std::vector<IItem*> revives;

    for (int i = 0; i < 20 ; ++i) {
        potions.push_back(new Potion());
        pokeballs.push_back(new Pokeball());
        revives.push_back(new Revive());
    }
    items_ = {std::make_pair("Potions", potions), std::make_pair("Pokeballs", pokeballs), std::make_pair("Revives", revives)};
}

pokemonGame::Shop::~Shop() {

}

void pokemonGame::Shop::listItems() {
    for (auto &&item : items_) {
        for (auto &&items_2 : item.second) {
            std::cout << items_2->getItemName() << ": " << item.second.size() << std::endl;

        }
    }
}

pokemonGame::IItem *pokemonGame::Shop::buyItem(int number) {

    switch (number)
    {
        case 1:
        {
            if(items_.find("Potions")->second.empty())
            {
                std::cout << "We are all out of Potions" << std::endl;
                return nullptr;
            } else
            {
                return items_.find("Potions")->second.front();
            }
        }
    }
}
