//
// Created by ubuntuudvikling on 10/17/16.
//

#ifndef EXAM_GAME_H
#define EXAM_GAME_H
#include <iostream>
#include <memory>
#include <map>
#include "Element.h"
#include "Pokemon.h"
#include "Player.h"
#include "pokemonState.h"

namespace pokemonGame {

    class Game  {
    public:
        Game() = default;
        Game(GameState* gameState);
        void startGame();
        void enterWorld(Player& player);
        std::vector<IPokemon*> seePokemons(); //debug
        std::map<Elements, std::shared_ptr<Element>> seeElements();//debug
    private:
        void populateWorldWithPokemons();
        void initializeElements();
        void initializeMoves();
        void initializeStateMachine();
        int randomLvl();


    private:
        std::map<Elements, std::shared_ptr<Element> > elements_{};
        std::vector<IPokemon*> pokemons_{};
        GameState* gameState_;


    };
}

#endif //EXAM_GAME_H
