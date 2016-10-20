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
#include "Shop.h"

namespace pokemonGame {


    class Game {
    public:
        Game(Game const &) = delete;             // Copy construct
        Game(Game &&) = delete;                  // Move construct
        Game &operator=(Game const &) = delete;  // Copy assign
        Game &operator=(Game &&) = delete;      // Move assign
        static Game *getInstance();

        virtual ~Game();

        void startGame();

        void enterWorld();

        void setGameState(GameState *gameState);

        void setPlayer(Player *player);

        void setShop(Shop *shop);

        void setPokemons(std::vector<std::shared_ptr<IPokemon>> pokemons);

        static void getIntBetween(int &choice, int min, int max, std::string prompt, std::string fail);

        static void getInt(int &choice, std::string prompt, std::string fail);

        std::vector<std::shared_ptr<IPokemon>> getPokemons(); //TODO debug
        std::map<Elements, std::shared_ptr<Element>> seeElements();//TODO debug

    public:
        //Slots
        void enteredShop();

        void encounterPokemon();

    protected:
        Game() = default;


    private:
        void populateWorldWithPokemons();

        void initializeElements();

        void initializeStateMachine();

        int randomNumber(int min, int max);


    private:
        std::map<Elements, std::shared_ptr<Element> > elements_{};
        std::vector<std::shared_ptr<IPokemon>> pokemons_;
        GameState *gameState_;
        Player *player_;
        Shop *shop_;
        static Game *instance_;


    };
}

#endif //EXAM_GAME_H
