//
// Created by ubuntuudvikling on 10/17/16.
//

#ifndef EXAM_GAME_H
#define EXAM_GAME_H
#include <iostream>
#include <memory>
#include <map>
#include "Element.h"

namespace pokemonGame {

    class Game  {
    public:

        void startGame();

    private:
        void populateWorldWithPokemons();
        void initializeElements();
        void initializeMoves();
        void initializeStateMachine();

    private:
        //std::map<std::shared_ptr<Element>, Elements > elements_{};
    };
}

#endif //EXAM_GAME_H
