//
// Created by plex on 10/17/16.
//

#ifndef EXAM_PLAYER_H
#define EXAM_PLAYER_H

#include <vector>
#include "../Items/IItem.h"
#include "../States/GameState.h"
#include "../Pokemon/IPokemon.h"

namespace pokemonGame
{
    class Player
    {
    public:
        Player();

        virtual ~Player();

        void walkIntoTheWilderness();

        void goToTheShop();

        void lookInPokedex();

        bool checkYourPokemons();

        void addPokemon(std::shared_ptr<IPokemon> pokemon);

        int getNumberOfPokemons();

        std::shared_ptr<IPokemon> getPokemon(int number);

        void checkYourItems();

        bool useItem(std::string item, std::shared_ptr<IPokemon> pokemon);

        void setFavoritePokemon(std::string nameOfPokemon);

        bool fight(std::shared_ptr<IPokemon> wildPokemon);

        std::shared_ptr<IPokemon> getFavoritePokemon() const;

        bool hasFavoritePokemon();

        void addItem(std::string itemName, std::shared_ptr<IItem> item);


        void setPokemonsSeen(std::vector<std::shared_ptr<IPokemon>> &pokemons);// TODO DEBUG


    private:
        std::map<std::string, std::vector<std::shared_ptr<IItem>>> items_;
        std::vector<std::shared_ptr<IPokemon>> caughtPokemons_{};
        std::vector<std::shared_ptr<IPokemon>> seenPokemons_{};
        std::shared_ptr<IPokemon> favoritePokemon_{nullptr};
        bool hasFavoritePokemon_{false};
    };
}


#endif //EXAM_PLAYER_H
