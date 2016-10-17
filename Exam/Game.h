//
// Created by ubuntuudvikling on 10/17/16.
//

#ifndef EXAM_GAME_H
#define EXAM_GAME_H

#include "pokemonState.h"
#include "Element.h"

namespace pokemonGame {

    typedef std::map<const std::string, std::shared_ptr<Element> > myElementMap;
    class Game : sc::state_machine<Game, NotPlaying> {
    public:

        void startGame();

    private:
        void populateWorldWithPokemons();
        void initializeElements();
        void initializeMoves();
        void initializeStateMachine();

    private:
        //Element *lightningPtr
        std::map<std::shared_ptr<Element>, Elements > elements_{};
    };
}

#endif //EXAM_GAME_H
