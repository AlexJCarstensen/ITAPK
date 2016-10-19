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

        virtual ~IPokemon() {};

        virtual int getCurrentHealth() const =0;

        virtual int getHealth() const = 0;

        virtual int setCurrentHealth(size_t newHealth) = 0;

        virtual size_t getLvl() const = 0;

        virtual std::string getName() const = 0;

        virtual Element *getElement() const = 0;

        virtual std::vector<std::string> getMoves()  = 0;

        virtual int DisplayMoves() = 0;

        virtual bool isCaught() = 0;

        virtual void setCaught(bool isCaught) = 0;

        virtual void printPokemon() = 0;

        virtual bool isFainted() = 0;

        virtual bool doMove(IPokemon* pokemon, int index) = 0;




    };
}

#endif //EXAM_IPOKEMON_H
