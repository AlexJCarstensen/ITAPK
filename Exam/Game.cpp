//
// Created by ubuntuudvikling on 10/17/16.
//


#include "Game.h"
#include "pokemonState.h"

using namespace std;

namespace pokemonGame {

//    void Game::startGame() {
//
//        initializeElements();
//        initializeMoves();
//        populateWorldWithPokemons();
//        initializeStateMachine();
//    }

    void Game::populateWorldWithPokemons() {

    }
    void Game::initializeElements() {
//        std::shared_ptr<Element> firePtr = std::make_shared<Fire>();
//        std::shared_ptr<Element> GrassPtr = std::make_shared<Grass>();
//        std::shared_ptr<Element> lightningPtr = std::make_shared<Lightning>();
//        std::shared_ptr<Element> groundPtr = std::make_shared<Ground>();
//        std::shared_ptr<Element> waterPtr = std::make_shared<Water>();
//        elements_.insert(std::make_pair(firePtr, Elements::FIRE));
//        elements_.insert(std::make_pair(GrassPtr, Elements::GRASS));
//        elements_.insert(std::make_pair(lightningPtr, Elements::LIGHTNING));
//        elements_.insert(std::make_pair(groundPtr, Elements::GROUND));
//        elements_.insert(std::make_pair(waterPtr, Elements::WATER));

        //auto t = elements_.find(Elements::FIRE);
    }

    void Game::initializeMoves() {

    }

    void Game::initializeStateMachine() {
        GameState GameState;
        GameState.initiate();

    }


}