//
// Created by ubuntuudvikling on 10/19/16.
//

#ifndef EXAM_SHOP_H
#define EXAM_SHOP_H

#include <vector>
#include <map>
#include "IItem.h"
#include "Player.h"

namespace pokemonGame{

    class Shop {

    public:
        Shop();
        virtual ~Shop();

        void listItems();

        int buyItem(std::string item, int quantity, Player *player);

    private:
        std::map<std::string, std::vector<std::shared_ptr<IItem>>> items_;
    };

}



#endif //EXAM_SHOP_H
