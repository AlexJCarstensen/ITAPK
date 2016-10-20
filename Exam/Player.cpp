//
// Created by plex on 10/17/16.
//

#include <sstream>
#include "Player.h"
#include "pokemonState.h"
#include "NoFavoritePokemonException.h"

using namespace std;
namespace pokemonGame {


    Player::~Player() {
//        for (auto &&item :items_) {
//            delete item;
//        }
    }

    void Player::walkIntoTheWilderness() {
        boost::signals2::signal<void()> sig;
        sig.connect(std::bind(&Game::encounterPokemon, Game::getInstance()));
        sig();
    }

    void Player::goToTheShop() {
        boost::signals2::signal<void()> sig;
        sig.connect(std::bind(&Game::enteredShop, Game::getInstance()));
        sig();
    }

    void Player::lookInPokedex() {
        //TODO Check up on this
        std::cout << "You have in the world of Pokemon seen these Pokemons: " << std::endl;
        for (auto &&pokemon : seenPokemons_) {
            if (pokemon->isCaught())
                std::cout << pokemon->getName() << " Caught" << std::endl;
            else
                std::cout << pokemon->getName() << " Seen" << std::endl;
        }
    }

    bool Player::checkYourPokemons() {
        //TODO check up on this
        if (caughtPokemons_.empty()) {
            cout << "You dont have any Pokemons" << endl << endl;
            return false;
        }
        cout << "You have the following Pokemons: " << endl;

        for (auto &&caughtPokemon : caughtPokemons_) {
            caughtPokemon->printPokemon();
            cout << endl;
        }
        return true;

    }

    void Player::checkYourItems() {

        std::cout << "You have the following items: " << std::endl;

        for (auto &&item : items_) {
            cout << item.first << " x " << item.second.size() << endl;

        }
    }

    // TODO DEBUG
    void Player::setPokemonsSeen(std::vector<shared_ptr<IPokemon>> &pokemons) {
        caughtPokemons_ = pokemons;
    }

    void Player::setFavoritePokemon(std::string nameOfPokemon) {

        //TODO check up on this
        if (caughtPokemons_.empty()) {
            cout << "You dont have any Pokemons" << endl;
            return;
        }

        auto result = std::find_if(caughtPokemons_.begin(), caughtPokemons_.end(),
                                   [nameOfPokemon](const shared_ptr<IPokemon> pokemon) {
                                       return pokemon.get()->getName() == nameOfPokemon;
                                   });
        try {
            favoritePokemon_ = *result;
            hasFavoritePokemon_ = true;
        } catch (std::exception &ex) {
            ex.what();
        }

        cout << favoritePokemon_->getName() << endl;
    }

    shared_ptr<IPokemon> Player::getFavoritePokemon() const {
        //TODO check up on this
        try {
            if (favoritePokemon_ == nullptr)
                throw NoFavoritePokemonException(
                        "Either you dont have any pokemons or you havn't chosen you favorite pokemon");
            else {
                favoritePokemon_->printPokemon();
                cout << endl;
                return favoritePokemon_;
            }

        } catch (NoFavoritePokemonException &ex) {
            //TODO remove cout when final
            cout << ex.what() << endl << endl;

        }

    }

    void Player::fight(shared_ptr<IPokemon> wildPokemon) {
        //TODO should it be in game?
        int numberOfMoves = favoritePokemon_->DisplayMoves();
        int choice = 0;
        Game::getIntBetween(choice, 1, numberOfMoves, "Please select a move: ", "Not a valid move");

        //Our pokemon attacks
        favoritePokemon_->doMove(wildPokemon.get(), choice - 1);

        int wildNumberOfMoves = wildPokemon->getMoves().size() - 1;

        int randomChoice = rand() % wildNumberOfMoves;

        //Wild pokemon attacks
        wildPokemon->doMove(favoritePokemon_.get(), randomChoice);
    }



    bool Player::hasFavoritePokemon() {
        return hasFavoritePokemon_;
    }

    void Player::addItem(std::string itemName, std::shared_ptr<IItem> item) {
        items_.find(itemName)->second.push_back(item);
    }

    Player::Player() {


        std::vector<std::shared_ptr<IItem>> potions;
        std::vector<std::shared_ptr<IItem>> pokeballs;
        std::vector<std::shared_ptr<IItem>> revives;

        for (int i = 0; i < 5; ++i) {
            potions.push_back(std::make_shared<Potion>());

            pokeballs.push_back(std::make_shared<Pokeball>());
            revives.push_back(std::make_shared<Revive>());
        }

        items_ = {std::make_pair("Potions", std::move(potions)), std::make_pair("Pokeballs", std::move(pokeballs)),
                  std::make_pair("Revives", std::move(revives))};
    }
}
