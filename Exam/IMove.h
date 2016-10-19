//
// Created by ubuntuudvikling on 10/10/16.
//

#ifndef EXAM_IMOVE_H
#define EXAM_IMOVE_H

#include "Element.h"
#include "IPokemon.h"

namespace pokemonGame {
    class IMove {
    public:
        IMove() = default;
        IMove(Element& element) : element_(element){}

        virtual ~IMove(){};

        virtual void doMove(IPokemon *pokemon) = 0;
        virtual std::string getMoveName() = 0;


        bool isAttack(){return isAttack_;}



    protected:

        bool isAttack_;
        Element& element_;
    };
}
#endif //EXAM_IMOVE_H
