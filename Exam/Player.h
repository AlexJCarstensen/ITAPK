//
// Created by plex on 10/17/16.
//

#ifndef EXAM_PLAYER_H
#define EXAM_PLAYER_H

#include <vector>
#include "IItem.h"
#include "GameState.h"
#include "IPokemon.h"

namespace pokemonGame{
class Player
{
public:
    Player() = default;
    virtual ~Player();
    void walkIntoTheWilderness();
    void goToTheShop();
    void lookInPokedex();
    bool checkYourPokemons();
    void checkYourItems();
    void setFavoritePokemon(std::string nameOfPokemon);
    void fight(std::shared_ptr<IPokemon> wildPokemon);
    std::shared_ptr<IPokemon> getFavoritePokemon() const;
    bool hasFavoritePokemon();


    void setPokemonsSeen(std::vector<std::shared_ptr<IPokemon>> &pokemons);// TODO DEBUG

private:
    void getIntBetween(int& d, int min, int max, std::string prompt, std::string fail);
    void getInt(int& d, std::string prompt, std::string fail);
private:
    std::vector<IItem*> items_{};
    std::vector<std::shared_ptr<IPokemon>> caughtPokemons_{};
    std::vector<std::shared_ptr<IPokemon>> seenPokemons_{};
    std::shared_ptr<IPokemon> favoritePokemon_{nullptr};
    bool hasFavoritePokemon_;

};
}


#endif //EXAM_PLAYER_H
