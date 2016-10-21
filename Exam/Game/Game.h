//
// Created by ubuntuudvikling on 10/17/16.
//

#ifndef EXAM_GAME_H
#define EXAM_GAME_H

#include <iostream>
#include <memory>
#include <map>
#include "Pokemon/Elements/IElement.h"
#include "Pokemon/Pokemon.h"
#include "Player/Player.h"
#include "Shop/Shop.h"

namespace pokemonGame
{

    class Game
    {
    public:
        Game(Game const &) = delete;             // Copy construct
        Game(Game &&) = delete;                  // Move construct
        Game &operator=(Game const &) = delete;  // Copy assign
        Game &operator=(Game &&) = delete;      // Move assign
        static Game *getInstance();

        virtual ~Game();

        void startGame();

        void enterWorld();

        void setGameState(std::shared_ptr<GameState> gameState);

        void setPlayer(std::shared_ptr<Player> player);

        void setShop(std::shared_ptr<Shop> shop);

        void setPokemons(std::vector<std::shared_ptr<IPokemon>> pokemons);

        static void getIntBetween(int &choice, int min, int max, std::string prompt, std::string fail);

        static void getInt(int &choice, std::string prompt, std::string fail);

    public:
        //Slots
        void enteredShop();

        void encounterPokemon();

    private:
        Game() = default;

        void populateWorldWithPokemons();

        void initializeElements();

        void initializeStateMachine();

        bool wildPokemonAttacks(std::shared_ptr<IPokemon> wildPokemon, std::shared_ptr<IPokemon> ourPokemon);

        int randomNumber(int min, int max);


    private:
        std::map<Elements, std::shared_ptr<IElement> > elements_{};
        std::vector<std::shared_ptr<IPokemon>> pokemons_;
        std::shared_ptr<GameState> gameState_;
        std::shared_ptr<Player> player_;
        std::shared_ptr<Shop> shop_;
        static Game *instance_;


    };
}

#endif //EXAM_GAME_H
