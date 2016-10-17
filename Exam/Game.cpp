//
// Created by ubuntuudvikling on 10/17/16.
//


#include "Game.h"
#include "pokemonState.h"
#include "Pokemon.h"
#include "Move.h"

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
        std::shared_ptr<Element> firePtr = std::make_shared<Fire>();
        std::shared_ptr<Element> GrassPtr = std::make_shared<Grass>();
        std::shared_ptr<Element> lightningPtr = std::make_shared<Lightning>();
        std::shared_ptr<Element> groundPtr = std::make_shared<Ground>();
        std::shared_ptr<Element> waterPtr = std::make_shared<Water>();
        //elements_.insert(std::make_pair(Elements::FIRE, firePtr));
        elements_.insert(std::make_pair(Elements::GRASS, GrassPtr));
        elements_.insert(std::make_pair(Elements::LIGHTNING, lightningPtr));
        elements_.insert(std::make_pair(Elements::GROUND, groundPtr));
        elements_.insert(std::make_pair(Elements::WATER, waterPtr));

        Pokemon Chamander("Charmander", (shared_ptr<Element> &&) firePtr, 50);
        Pokemon Charizard("Charizard", (shared_ptr<Element> &&) firePtr, 100);
        IMove *quick = new AttackMove(*firePtr, "Quick", 40);
        quick->doMove(Chamander);
        //Pokemon Charizard1("Charizard1", (shared_ptr<Element> &&) firePtr, 100);
        auto t = firePtr.use_count();
        std::cout << t << std::endl;

    }

    void Game::initializeMoves() {

    }

    void Game::initializeStateMachine() {
        GameState GameState;
        GameState.initiate();

    }


}