//
// Created by plex on 10/17/16.
//

#include <sstream>
#include "Player.h"
#include "../States/pokemonState.h"
#include "../Exception/NoFavoritePokemonException.h"
#include "../Items/Potion.h"
#include "../Items/Pokeball.h"
#include "../Items/Revive.h"
#include "../Items/ItemNames.h"
#include "../Exception/NoNamePokemonException.h"

using namespace std;
namespace pokemonGame
{
    Player::Player()
    {
        std::vector<std::shared_ptr<IItem>> potions;
        std::vector<std::shared_ptr<IItem>> pokeballs;
        std::vector<std::shared_ptr<IItem>> revives;

        for (int i = 0; i < 5; ++i)
        {
            potions.push_back(std::make_shared<Potion>());

            pokeballs.push_back(std::make_shared<Pokeball>());
            revives.push_back(std::make_shared<Revive>());
        }
        //TODO SHOULD IT BE MOVE??
        items_ = {std::make_pair(itemNames::POTION, std::move(potions)),
                  std::make_pair(itemNames::POKEBALL, std::move(pokeballs)),
                  std::make_pair(itemNames::REVIVE, std::move(revives))};
    }

    Player::~Player()
    {
        //TODO Check
//        for (auto &&item :items_) {
//            delete item;
//        }
    }

    void Player::walkIntoTheWilderness()
    {
        boost::signals2::signal<void()> sig;
        sig.connect(std::bind(&Game::encounterPokemon, Game::getInstance()));
        sig();
    }

    void Player::goToTheShop()
    {
        boost::signals2::signal<void()> sig;
        sig.connect(std::bind(&Game::enteredShop, Game::getInstance()));
        sig();
    }

    void Player::lookInPokedex()
    {
        //TODO Check up on this
        std::cout << "You have in the world of Pokemon seen these Pokemons: " << std::endl;
        for (auto &&pokemon : seenPokemons_)
        {
            if (pokemon->isCaught())
                std::cout << pokemon->getName() << " Caught" << std::endl;
            else
                std::cout << pokemon->getName() << " Seen" << std::endl;
        }
    }

    void Player::checkYourItems()
    {
        std::cout << "You have the following items: " << std::endl;

        int index = 1;
        for (auto &&item : items_)
        {
            cout << index++ << ". " << item.first << " x " << item.second.size() << endl;

        }
    }

    void Player::addPokemon(std::shared_ptr<IPokemon> pokemon)
    {
        caughtPokemons_.push_back(pokemon);
    }

    void Player::setFavoritePokemon(std::string nameOfPokemon)
    {
        //TODO check up on this
        if (caughtPokemons_.empty())
        {
            cout << "You dont have any Pokemons" << endl;
            return;
        }

        auto result = std::find_if(caughtPokemons_.begin(), caughtPokemons_.end(),
                                   [nameOfPokemon](const shared_ptr<IPokemon> pokemon)
                                   {
                                       return pokemon.get()->getName() == nameOfPokemon;
                                   });

        try
        {
            if (result == caughtPokemons_.end())
                throw NoNamePokemonException("You don't have any pokemon with that name");
            favoritePokemon_ = *result;
            hasFavoritePokemon_ = true;
            cout << favoritePokemon_->getName() << " is now your favorite pokemon" << endl;

        } catch (std::exception &ex)
        {
            std::cout << ex.what() << std::endl;
        }

    }

    void Player::addItem(std::string itemName, std::shared_ptr<IItem> item)
    {
        items_.find(itemName)->second.push_back(item);
    }

    bool Player::checkYourPokemons()
    {
        //TODO check up on this
        if (caughtPokemons_.empty())
        {
            cout << "You dont have any Pokemons" << endl << endl;
            return false;
        }
        cout << "You have the following Pokemons: " << endl;

        int index = 1;

        for (auto &&caughtPokemon : caughtPokemons_)
        {
            cout << index++ << ". "<< flush;
            caughtPokemon->printPokemon();
            cout << endl;
        }
        return true;
    }

    bool Player::useItem(std::string item, std::shared_ptr<IPokemon> pokemon)
    {

        if (!items_.find(item)->second.empty())
        {
            auto it = std::prev(items_.find(item)->second.end());
            bool success = it->get()->useItem(pokemon.get());

            //If item is a pokeball, destroy after use
            if (it->get()->getItemName() == itemNames::POKEBALL)
            {
                it->reset();
                items_.find(item)->second.pop_back();
            }
                //if another item check success
            else
            {
                if (success)
                {
                    it->reset();
                    items_.find(item)->second.pop_back();
                }
            }
            return success;
        }
    }

    bool Player::hasFavoritePokemon()
    {
        return hasFavoritePokemon_;
    }

    bool Player::fight(shared_ptr<IPokemon> wildPokemon)
    {
        //TODO should it be in game?
        int numberOfMoves = favoritePokemon_->DisplayMoves();
        int choice = 0;
        Game::getIntBetween(choice, 1, numberOfMoves, "Please select a move: ", "Not a valid move");

        //Our pokemon attacks
        return favoritePokemon_->doMove(wildPokemon.get(), choice - 1);
    }

    int Player::getNumberOfPokemons()
    {
        return caughtPokemons_.size();
    }

    shared_ptr<IPokemon> Player::getFavoritePokemon() const
    {
        //TODO check up on this
        try
        {
            if (favoritePokemon_ == nullptr)
                throw NoFavoritePokemonException(
                        "Either you dont have any pokemons or you havn't chosen you favorite pokemon");
            else
            {
                favoritePokemon_->printPokemon();
                cout << endl;
                return favoritePokemon_;
            }

        } catch (NoFavoritePokemonException &ex)
        {
            //TODO remove cout when final
            cout << ex.what() << endl << endl;
        }

    }

    std::shared_ptr<IPokemon> Player::getPokemon(int number)
    {
        return caughtPokemons_.at(number);
    }
}
