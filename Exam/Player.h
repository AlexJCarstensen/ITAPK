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
    void fight(IPokemon * wildPokemon);
    IPokemon* getFavoritePokemon() const;


    void setPokemonsSeen(std::vector<IPokemon*> &pokemons);// TODO DEBUG
private:
    std::vector<IItem*> items_{};
    std::vector<IPokemon*> caughtPokemons_{};
    std::vector<IPokemon*> seenPokemons_{};
    IPokemon* favoritePokemon_{nullptr};

};
}


#endif //EXAM_PLAYER_H
