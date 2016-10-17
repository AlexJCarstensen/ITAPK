//
// Created by stud on 10/17/16.
//

#ifndef EXAM_IPOKEMON_H
#define EXAM_IPOKEMON_H

#include "Element.h"

namespace pokemonGame {

    class IPokemon {

    public:
        IPokemon() = default;
        virtual ~IPokemon(){};
        virtual int getHealth() = 0;
        virtual int setHealth(size_t newHealth) = 0;
        virtual Element* getElement() = 0;
    };
}

#endif //EXAM_IPOKEMON_H
