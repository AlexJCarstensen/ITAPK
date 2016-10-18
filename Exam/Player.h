//
// Created by plex on 10/17/16.
//

#ifndef EXAM_PLAYER_H
#define EXAM_PLAYER_H

#include <vector>
#include "Item.h"
#include "GameState.h"
#include "IPokemon.h"

namespace pokemonGame{
class Player
{
public:
    Player() = default;
    Player(GameState *gameState);
    virtual ~Player();
    void walkIntoTheWilderness();
    void goToTheShop();
    void lookInPokedex();
    void checkYourPokemons();
    void checkYourItems();

    void setPokemonsSeen(std::vector<IPokemon*> &pokemons);// TODO DEBUG
private:
    std::vector<Item> items_;
    std::vector<IPokemon*> caughtPokemons_;
    std::vector<IPokemon*> seenPokemons_;
    GameState* gameState_;

};
}


#endif //EXAM_PLAYER_H
