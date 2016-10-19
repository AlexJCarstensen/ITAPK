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
        for (auto &&item :items_) {
            delete item;
        }
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
        //TODO check up on this

        std::cout << "You have the following items: " << std::endl;

        for (auto &&item : items_) {


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
        getIntBetween(choice, 1, numberOfMoves, "Please select a move: ", "Not a valid move");

        //Our pokemon attacks
        favoritePokemon_->doMove(wildPokemon.get(), choice - 1);

        int wildNumberOfMoves = wildPokemon->getMoves().size() - 1;

        int randomChoice = rand() % wildNumberOfMoves;

        //Wild pokemon attacks
        wildPokemon->doMove(favoritePokemon_.get(), randomChoice);
    }

    //Taken from: http://stackoverflow.com/questions/15467412/c-cin-only-accept-numeric-values
    void Player::getIntBetween(int &d, int min, int max, std::string prompt, std::string fail) {

        while (1) {
            getInt(d, prompt, fail);
            if (d > max || d < min) {
                std::cout << "Sorry, your choice is out of range.\n";
                continue;
            }
            break;
        }


    }

    //Taken from: http://stackoverflow.com/questions/15467412/c-cin-only-accept-numeric-values
    void Player::getInt(int &d, std::string prompt, std::string fail) {

        while (1) {

            std::cout << prompt;
            std::string str;
            std::cin >> str;

            std::istringstream ss(str);
            int val1;
            ss >> val1;

            if (!ss.eof()) {
                std::cout << fail;
                continue;
            } else {
                d = val1;
                break;
            }
        }

    }

    bool Player::hasFavoritePokemon() {
        return hasFavoritePokemon_;
    }
}
