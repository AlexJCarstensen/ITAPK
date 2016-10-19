//
// Created by ubuntuudvikling on 10/19/16.
//

#ifndef EXAM_SHOP_H
#define EXAM_SHOP_H

#include <vector>
#include <map>
#include "IItem.h"

namespace pokemonGame{

    class Shop {

    public:
        Shop();
        virtual ~Shop();
        void listItems();
        IItem* buyItem(int number);

    private:
        std::map<std::string, std::vector<IItem*> > items_;
    };

}



#endif //EXAM_SHOP_H
