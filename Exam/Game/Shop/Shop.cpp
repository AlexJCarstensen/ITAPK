//
// Created by ubuntuudvikling on 10/19/16.
//

#include "Shop.h"
#include "../Items/Potion.h"
#include "../Items/Pokeball.h"
#include "../Items/Revive.h"
#include "../Items/ItemNames.h"

namespace pokemonGame
{
    pokemonGame::Shop::Shop()
    {
        std::vector<std::shared_ptr<IItem>> potions;
        std::vector<std::shared_ptr<IItem>> pokeballs;
        std::vector<std::shared_ptr<IItem>> revives;

        for (int i = 0; i < 20; ++i)
        {
            potions.push_back(std::make_shared<Potion>());

            pokeballs.push_back(std::make_shared<Pokeball>());
            revives.push_back(std::make_shared<Revive>());
        }

        items_ = {std::make_pair(itemNames::POTION, std::move(potions)),
                  std::make_pair(itemNames::POKEBALL, std::move(pokeballs)),
                  std::make_pair(itemNames::REVIVE, std::move(revives))};
    }


    void pokemonGame::Shop::listItems()
    {
        std::cout << "Welcome to the shop! How may I assist you?" << std::endl;
        std::cout << "I have the following items for sale" << std::endl;

        std::cout << items_.find(itemNames::POTION)->first << " x " << items_.find(itemNames::POTION)->second.size()
                  << std::endl;
        std::cout << items_.find(itemNames::POKEBALL)->first << " x " << items_.find(itemNames::POKEBALL)->second.size()
                  << std::endl;
        std::cout << items_.find(itemNames::REVIVE)->first << " x " << items_.find(itemNames::REVIVE)->second.size()
                  << std::endl;
    }

    void pokemonGame::Shop::buyItem(std::string item, int quantity, std::shared_ptr<Player> player)
    {
        if (items_.find(item)->second.empty())
            std::cout << "We are all out of " << item << "s" << std::endl << std::endl;
        else
        {
            if (quantity > items_.find(item)->second.size())
            {
                int sizeOfVector = items_.find(item)->second.size();
                for (int i = 0; i < sizeOfVector; i++)
                {
                    auto it = std::prev(items_.find(item)->second.end());
                    player->addItem(item, std::move(*it));
                    items_.find(item)->second.pop_back();
                }
            } else
            {
                for (int i = 0; i < quantity; i++)
                {
                    auto it = std::prev(items_.find(item)->second.end());
                    player->addItem(item, std::move(*it));
                    items_.find(item)->second.pop_back();

                }
            }
        }
    }
}