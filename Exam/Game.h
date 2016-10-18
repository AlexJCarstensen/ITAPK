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
namespace pokemonGame {


    class Game {
    public:
        Game(Game const&) = delete;             // Copy construct
        Game(Game&&) = delete;                  // Move construct
        Game& operator=(Game const&) = delete;  // Copy assign
        Game& operator=(Game &&) = delete;      // Move assign
        static Game& getInstance();

        void startGame();
        void enterWorld(Player& player);
        void operator()() const
        {
            std::cout << "Hello, World!" << std::endl;
        }
        void setGameState(GameState* gameState);
        std::vector<IPokemon*> getPokemons(); //TODO debug
        void setPokemons(std::vector<IPokemon*> pokemons); //TODO debug
        std::map<Elements, std::shared_ptr<Element>> seeElements();//TODO debug
    protected:
        Game();
        virtual ~Game();

    private:
        void populateWorldWithPokemons();
        void initializeElements();
        void initializeMoves();
        void initializeStateMachine();
        int randomLvl();


    private:
        std::map<Elements, std::shared_ptr<Element> > elements_{};
        std::vector<IPokemon*> pokemons_;
        GameState* gameState_;


    };
}

#endif //EXAM_GAME_H
