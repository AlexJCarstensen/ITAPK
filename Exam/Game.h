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
        //Game& operator=(Game const&) = delete;  // Copy assign
        static Game* getInstance();
        virtual ~Game();
        void startGame();
        void enterWorld();
        void setGameState(GameState* gameState);
        void setPlayer(Player* player);
        void encounterPokemon();
        std::vector<IPokemon*> getPokemons(); //TODO debug
        void setPokemons(std::vector<IPokemon*> pokemons); //TODO debug
        std::map<Elements, std::shared_ptr<Element>> seeElements();//TODO debug
    protected:
        Game() = default;


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
        Player* player_;
        static Game* instance_;


    };
}

#endif //EXAM_GAME_H
