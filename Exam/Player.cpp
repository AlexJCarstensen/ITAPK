//
// Created by plex on 10/17/16.
//

#include "Player.h"
#include "pokemonState.h"
#include "NoFavoritePokemonException.h"

namespace pokemonGame
{


    Player::~Player()
    {

    }

    void Player::walkIntoTheWilderness()
    {

        boost::signals2::signal<void ()> sig;
        sig.connect(std::bind(&Game::encounterPokemon, Game::getInstance()));
        sig();
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

    bool Player::checkYourPokemons()
    {
        if(caughtPokemons_.empty())
        {
            cout << "You dont have any Pokemons" << endl << endl;
            return false;
        }
        cout << "You have the following Pokemons: " << endl;

        for (auto && caughtPokemon : caughtPokemons_) {
            caughtPokemon->printPokemon();
                    cout << endl;
            return true;

}


    }

    void Player::checkYourItems()
    {
        std::cout << "You have the following items: " << std::endl;

        for (auto &&item : items_)
        {


        }
    }
    // TODO DEBUG
    void Player::setPokemonsSeen(std::vector<IPokemon*> &pokemons)
    {
        caughtPokemons_ = pokemons;
    }

    void Player::setFavoritePokemon(std::string nameOfPokemon) {
        if(caughtPokemons_.empty())
        {
            cout << "You dont have any Pokemons" << endl;
            return;
        }

        auto result = std::find_if(caughtPokemons_.begin(), caughtPokemons_.end(), [nameOfPokemon](const IPokemon* pokemon){
            return pokemon->getName() == nameOfPokemon;
        });
        try {
            favoritePokemon_ = *result;
        }catch (std::exception& ex)
        {
            ex.what();
        }




        cout << favoritePokemon_->getName() << endl;
    }

    IPokemon* Player::getFavoritePokemon() const {
        try {
            if(favoritePokemon_ == nullptr)
                throw NoFavoritePokemonException("Either you dont have any pokemons or you havn't chosen you favorite pokemon");
            else
            {
                favoritePokemon_->printPokemon();
                cout << endl;
                return favoritePokemon_;
            }

        }catch(NoFavoritePokemonException &ex)
        {
            //TODO remove cout when final
            cout << ex.what() << endl << endl;

        }

    }

    void Player::fight(IPokemon * wildPokemon) {
//        int numberOfMoves = favoritePokemon_->DisplayMoves();
//        cout << "Your choice: " << flush;
//        unsigned int choice;
//
//        if(choice > numberOfMoves)
//            cout << "Invalid input.  Try again: ";
//        else {
//             favoritePokemon_->doMove;
//        }
//        while(!(cin >> choice)){
//            cin.clear();
//            for (auto && moves :numberOfMoves ) {
//                if(cin != moves)
//
//}
//            cout << "Invalid input.  Try again: ";
//        }
//
//        cin >> choice;
//        cout << endl;
////        if(cin <)
////        favoritePokemon_->getMoves()[numberOfMoves];
////        switch (choice) {
////            case '1': {
////                if (!player_->getFavoritePokemon())
////                    player_->fight(PokemonPtr);
////                break;
////            }
////
////            case '2':
////                player_->checkYourItems();
////                break;
////
////            case '3': {
////                if( player_->checkYourPokemons())
////                {
////                    cout << "Enter the Pokemon you wish to use: " << flush;
////                    std::string choice;
////                    cin >> choice;
////                    player_->setFavoritePokemon(choice);
////                }
////                break;
////            }
////
////            case '4': {
////                //TODO signal
////                battling = false;
////                break;
////            }
//
    }


}
