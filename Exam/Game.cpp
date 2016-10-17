//
// Created by ubuntuudvikling on 10/17/16.
//


#include "Game.h"
#include "Element.h"

using namespace std;

namespace pokemonGame {
    void Game::startGame() {

        initializeElements();
        initializeMoves();
        populateWorldWithPokemons();
        initializeStateMachine();
    }

    void Game::populateWorldWithPokemons() {

    }
    void Game::initializeElements() {
        std::shared_ptr<const Element> ptr = std::make_shared<Fire>();
        elements_.insert(ptr, Elements::FIRE);
    }

    void Game::initializeMoves() {

    }

    void Game::initializeStateMachine() {
        GameState GameState;
        GameState.initiate();
    }


}