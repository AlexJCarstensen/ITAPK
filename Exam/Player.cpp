//
// Created by plex on 10/17/16.
//

#include "Player.h"
#include "pokemonState.h"
namespace pokemonGame
{

    Player::Player(GameState *gameState) : gameState_(gameState)
    {

    }
    Player::~Player()
    {

    }

    void Player::walkIntoTheWilderness()
    {
        //TODO do some randomizing  with encountering

        auto encounter = [](){
            std::random_device rd;
            std::mt19937 eng(rd());
            std::uniform_int_distribution<> distr(1, 100);
            return distr(eng);
        };
        if(encounter() > 50)
        {
            gameState_->process_event(EvEncounter());
        }


    }

    void Player::goToTheShop()
    {
        std::cout << "Welcome to the shop! How may I assist you?" << std::endl;

    }

    void Player::lookInPokedex()
    {
        std::cout << "You have in the world of Pokemon seen these Pokemons: " << std::endl;
        for (auto &&pokemon : seenPokemons_)
        {
            if(pokemon->isCaught())
                std::cout << pokemon->getName() << " Caught" <<std::endl;
            else
                std::cout << pokemon->getName() << " Seen" <<std::endl;
        }

    }

    void Player::checkYourPokemons()
    {

    }

    void Player::checkYourItems()
    {
        std::cout << "You have the following items: " << std::endl;

        for (auto &&item : items_)
        {
            std::cout << item.getItemName() <<": "<< item.getItemsCount() << std::endl;

        }
    }
    // TODO DEBUG
    void Player::setPokemonsSeen(std::vector<IPokemon*> &pokemons)
    {
        seenPokemons_ = pokemons;
    }


}
