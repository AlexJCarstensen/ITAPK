//
// Created by ubuntuudvikling on 10/10/16.
//

#ifndef EXAM_IMOVE_H
#define EXAM_IMOVE_H

#include "../Elements/IElement.h"
#include "../IPokemon.h"

namespace pokemonGame
{
    class IMove
    {
    public:
        IMove(std::shared_ptr<IElement> element) : element_(element) {}

        virtual ~IMove() {};

        virtual bool doMove(int lvl ,IPokemon *pokemon) = 0;

        virtual std::string getMoveName() = 0;

        bool isAttack() { return isAttack_; }

    protected:
        bool isAttack_;
        std::shared_ptr<IElement> element_;
    };
}
#endif //EXAM_IMOVE_H
