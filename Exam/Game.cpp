//
// Created by ubuntuudvikling on 10/17/16.
//


#include <sstream>
#include "Game.h"
#include "pokemonState.h"
#include "MoveChoosers.h"
#include "Elements/Fire.h"
#include "Elements/Water.h"
#include "Elements/Lightning.h"
#include "Elements/Grass.h"
#include "Elements/Ground.h"
#include "Elements/Water.h"
#include "Elements/Lightning.h"
#include "Elements/Ground.h"
#include "Elements/Grass.h"
#include "Elements/Elements.h"


using namespace std;

namespace pokemonGame {
    Game *Game::instance_ = nullptr;


    void Game::startGame() {

        initializeElements();
        populateWorldWithPokemons();
        initializeStateMachine();
    }

    void Game::populateWorldWithPokemons() {

        /******************
        *  Fire Pokemons  *
        ******************/

        MoveChooser<(int) Elements::FIRE> fireMoveChooser;
        shared_ptr<IPokemon> charmander = make_shared<Pokemon>("Charmander", elements_.find(Elements::FIRE)->second,
                                                               randomNumber(1, 100),
                                                               fireMoveChooser.getMoves());

        shared_ptr<IPokemon> moltres = make_shared<Pokemon>("Moltres", elements_.find(Elements::FIRE)->second,
                                                            randomNumber(1, 100),
                                                            fireMoveChooser.getMoves());
        shared_ptr<IPokemon> charizard = make_shared<Pokemon>("Charizard", elements_.find(Elements::FIRE)->second,
                                                              randomNumber(1, 100),
                                                              fireMoveChooser.getMoves());
        shared_ptr<IPokemon> arcanine = make_shared<Pokemon>("Arcanine", elements_.find(Elements::FIRE)->second,
                                                             randomNumber(1, 100),
                                                             fireMoveChooser.getMoves());
        shared_ptr<IPokemon> magmar = make_shared<Pokemon>("Magmar", elements_.find(Elements::FIRE)->second,
                                                           randomNumber(1, 100),
                                                           fireMoveChooser.getMoves());
        shared_ptr<IPokemon> flareon = make_shared<Pokemon>("Flareon", elements_.find(Elements::FIRE)->second,
                                                            randomNumber(1, 100),
                                                            fireMoveChooser.getMoves());

        /***********************
        *  Lightning Pokemons  *
        ***********************/
        MoveChooser<(int) Elements::LIGHTNING> lightningMoveChooser;

        shared_ptr<IPokemon> pickachu = make_shared<Pokemon>("Pikachu", elements_.find(Elements::LIGHTNING)->second,
                                                             randomNumber(1, 100),
                                                             lightningMoveChooser.getMoves());
        shared_ptr<IPokemon> electrabuzz = make_shared<Pokemon>("Electrabuzz",
                                                                elements_.find(Elements::LIGHTNING)->second,
                                                                randomNumber(1, 100), lightningMoveChooser.getMoves());
        shared_ptr<IPokemon> magneton = make_shared<Pokemon>("Magneton", elements_.find(Elements::LIGHTNING)->second,
                                                             randomNumber(1, 100),
                                                             lightningMoveChooser.getMoves());
        shared_ptr<IPokemon> electrode = make_shared<Pokemon>("Electrode", elements_.find(Elements::LIGHTNING)->second,
                                                              randomNumber(1, 100),
                                                              lightningMoveChooser.getMoves());
        shared_ptr<IPokemon> jolteon = make_shared<Pokemon>("Jolteon", elements_.find(Elements::LIGHTNING)->second,
                                                            randomNumber(1, 100),
                                                            lightningMoveChooser.getMoves());
        shared_ptr<IPokemon> zapdos = make_shared<Pokemon>("Zapdos", elements_.find(Elements::LIGHTNING)->second,
                                                           randomNumber(1, 100),
                                                           lightningMoveChooser.getMoves());

        /*******************
        *  Water Pokemons  *
        *******************/
        MoveChooser<(int) Elements::WATER> waterMoveChooser;

        shared_ptr<IPokemon> squirtle = make_shared<Pokemon>("Squirtle", elements_.find(Elements::WATER)->second,
                                                             randomNumber(1, 100),
                                                             waterMoveChooser.getMoves());
        shared_ptr<IPokemon> blastoise = make_shared<Pokemon>("Blastoise", elements_.find(Elements::WATER)->second,
                                                              randomNumber(1, 100),
                                                              waterMoveChooser.getMoves());
        shared_ptr<IPokemon> vaporeon = make_shared<Pokemon>("Vaporeon", elements_.find(Elements::WATER)->second,
                                                             randomNumber(1, 100),
                                                             waterMoveChooser.getMoves());
        shared_ptr<IPokemon> lapras = make_shared<Pokemon>("Lapras", elements_.find(Elements::WATER)->second,
                                                           randomNumber(1, 100),
                                                           waterMoveChooser.getMoves());
        shared_ptr<IPokemon> magikarp = make_shared<Pokemon>("Magikarp", elements_.find(Elements::WATER)->second,
                                                             randomNumber(1, 100),
                                                             waterMoveChooser.getMoves());
        shared_ptr<IPokemon> omastar = make_shared<Pokemon>("Omastar", elements_.find(Elements::WATER)->second,
                                                            randomNumber(1, 100),
                                                            waterMoveChooser.getMoves());

        /*******************
        *  Grass Pokemons  *
        *******************/

        MoveChooser<(int) Elements::GRASS> grassMoveChooser;

        shared_ptr<IPokemon> bulbasaur = make_shared<Pokemon>("Bulbasaur", elements_.find(Elements::GRASS)->second,
                                                              randomNumber(1, 100),
                                                              grassMoveChooser.getMoves());
        shared_ptr<IPokemon> venosaur = make_shared<Pokemon>("Venosaur", elements_.find(Elements::GRASS)->second,
                                                             randomNumber(1, 100),
                                                             grassMoveChooser.getMoves());
        shared_ptr<IPokemon> butterfree = make_shared<Pokemon>("Butterfree", elements_.find(Elements::GRASS)->second,
                                                               randomNumber(1, 100),
                                                               grassMoveChooser.getMoves());
        shared_ptr<IPokemon> victreebel = make_shared<Pokemon>("Victreebel", elements_.find(Elements::GRASS)->second,
                                                               randomNumber(1, 100),
                                                               grassMoveChooser.getMoves());
        shared_ptr<IPokemon> exeggutor = make_shared<Pokemon>("Exeggutor", elements_.find(Elements::GRASS)->second,
                                                              randomNumber(1, 100),
                                                              grassMoveChooser.getMoves());
        shared_ptr<IPokemon> scyther = make_shared<Pokemon>("Scyther", elements_.find(Elements::GRASS)->second,
                                                            randomNumber(1, 100),
                                                            grassMoveChooser.getMoves());

        /********************
        *  Ground Pokemons  *
        ********************/
        MoveChooser<(int) Elements::GROUND> groundMoveChooser;


        shared_ptr<IPokemon> diglett = make_shared<Pokemon>("Diglett", elements_.find(Elements::GROUND)->second,
                                                            randomNumber(1, 100),
                                                            groundMoveChooser.getMoves());
        shared_ptr<IPokemon> golem = make_shared<Pokemon>("Golem", elements_.find(Elements::GROUND)->second,
                                                          randomNumber(1, 100),
                                                          groundMoveChooser.getMoves());
        shared_ptr<IPokemon> machoke = make_shared<Pokemon>("Machoke", elements_.find(Elements::GROUND)->second,
                                                            randomNumber(1, 100),
                                                            groundMoveChooser.getMoves());
        shared_ptr<IPokemon> kabutops = make_shared<Pokemon>("Kabutops", elements_.find(Elements::GROUND)->second,
                                                             randomNumber(1, 100),
                                                             groundMoveChooser.getMoves());
        shared_ptr<IPokemon> sandslash = make_shared<Pokemon>("Sandslash", elements_.find(Elements::GROUND)->second,
                                                              randomNumber(1, 100),
                                                              groundMoveChooser.getMoves());
        shared_ptr<IPokemon> machamp = make_shared<Pokemon>("Machamp", elements_.find(Elements::GROUND)->second,
                                                            randomNumber(1, 100),
                                                            groundMoveChooser.getMoves());

        std::vector<shared_ptr<IPokemon>> pokemons = {charmander, moltres, charizard, arcanine, magmar, flareon,
                                                      pickachu, electrabuzz, magneton, electrode, jolteon, zapdos,
                                                      squirtle, blastoise, vaporeon, lapras, magikarp, omastar,
                                                      bulbasaur, venosaur, butterfree, victreebel, exeggutor, scyther,
                                                      diglett, golem, machoke, kabutops, sandslash, machamp};

        setPokemons(pokemons);
    }


    void Game::initializeElements() {
        shared_ptr<Element> firePtr = make_shared<Fire>();
        shared_ptr<Element> GrassPtr = make_shared<Grass>();
        shared_ptr<Element> lightningPtr = make_shared<Lightning>();
        shared_ptr<Element> groundPtr = make_shared<Ground>();
        shared_ptr<Element> waterPtr = make_shared<Water>();

        elements_ =
                {make_pair(Elements::FIRE, firePtr), make_pair(Elements::GRASS, GrassPtr),
                 make_pair(Elements::LIGHTNING, lightningPtr), make_pair(Elements::GROUND, groundPtr),
                 make_pair(Elements::WATER, waterPtr)};

    }

    void Game::initializeStateMachine() {
        gameState_->initiate();
    }

    int Game::randomNumber(int min, int max) {
        random_device rd;
        mt19937 eng(rd());
        uniform_int_distribution<> distr(min, max);
        return distr(eng);
    }


    map<Elements, shared_ptr<Element>> Game::seeElements() {
        return elements_;
    }

    void Game::enterWorld() {
        //player_->setPokemonsSeen(pokemons_); //TODO debug get all pokemons to player
        cout << "Welcome to the world of Pokemons" << endl;
        gameState_->process_event(EvGameOn());
        bool playing = true;
        while (playing) {
            char choice;

            cout << "What would you like to do?" << endl;
            cout << "'1' Walk in the wilderness" << endl;
            cout << "'2' Go to the shop" << endl;
            cout << "'3' Take a loot in the pokedex" << endl;
            cout << "'4' Check your Pokemons" << endl;
            cout << "'5' Choose your favorite Pokemon" << endl;
            cout << "'6' Show your favorite Pokemon" << endl;
            cout << "'7' Check your items" << endl;
            cout << "'8' Go home" << endl;

            cout << "Your choice: " << flush;
            cin >> choice;

            switch (choice) {
                case '1':
                    player_->walkIntoTheWilderness();
                    break;

                case '2':
                    player_->goToTheShop();
                    break;

                case '3':
                    player_->lookInPokedex();
                    break;

                case '4':
                    player_->checkYourPokemons();
                    break;
                case '5': {
                    cout << "Enter your Pokemons name: " << flush;
                    std::string choice;
                    cin >> choice;
                    player_->setFavoritePokemon(choice);
                    break;
                }
                case '6':
                    player_->getFavoritePokemon();
                    break;

                case '7':
                    player_->checkYourItems();
                    break;

                case '8':
                    playing = false;
                    break;
            }
        }
    }


    std::vector<std::shared_ptr<IPokemon>> Game::getPokemons() {
        return pokemons_;
    }

    void Game::setPokemons(std::vector<shared_ptr<IPokemon>> pokemons) {
        pokemons_ = pokemons;
    }

    void Game::setGameState(GameState *gameState) {
        gameState_ = gameState;

    }

    Game *Game::getInstance() {
        if (!instance_)
            instance_ = new Game();
        return instance_;
    }

    Game::~Game() {
        delete instance_;
    }

    void Game::encounterPokemon() {

        if (randomNumber(0, 100) > 50) {
            gameState_->process_event(EvEncounter());
            shared_ptr<IPokemon> wildPokemon;

            auto getRandomPokemon = [&wildPokemon, this] {
                wildPokemon = pokemons_[randomNumber(0, pokemons_.size() - 1)];

                while (wildPokemon->isCaught())
                    wildPokemon = pokemons_[randomNumber(0, pokemons_.size() - 1)];

                return wildPokemon;
            };

            std::cout << "Wild " << getRandomPokemon()->getName() << " appeared" << std::endl << std::endl;
            bool battling = true;
            while (battling) {
                int choice;

                wildPokemon.get()->printPokemon();
                cout << endl << endl;
                if (player_->hasFavoritePokemon()) {
                    cout << "Your " << flush;
                    player_->getFavoritePokemon();
                    cout << endl << endl;
                } else
                    cout << "You dont have any Pokemons try and catch this wild one" << endl << endl;


                cout << "'1' Fight\t" << flush;
                cout << "'2' Bag" << endl;
                cout << "'3' Pokemon\t" << flush;
                cout << "'4' Run" << endl;


                Game::getIntBetween(choice, 1, 4, "What do you want to do? ", "Please select a number from 1-4");
                cout << endl;
                switch (choice) {
                    case 1: {
                        if (player_->hasFavoritePokemon())
                            if(player_->fight(wildPokemon))
                            {
                                std::cout << "Wild " << wildPokemon->getName() << " fainted" << std::endl;
                                battling = false;
                                gameState_->process_event(EvFaint());
                                wildPokemon.get()->respawn();
                                break;
                            }
                            wildPokemonAttacks(wildPokemon, player_->getFavoritePokemon());
                        break;
                    }

                    case 2: {
                        player_->checkYourItems();
                        Game::getIntBetween(choice, 1, 3, "Choose an item: ", "Please select a number from 1-3");
                        bool couldUsePotionOrRevive = false;

                        switch (choice) {
                            case 1: {
                                //Pokeball
                                gameState_->process_event(EvBallThrow());

                                if (player_->useItem("Pokeballs", wildPokemon)) {
                                    player_->addPokemon(wildPokemon);
                                    gameState_->process_event(EvCatch());
                                    battling = false;
                                } else
                                    gameState_->process_event(EvBrokeFree());

                                break;
                            }
                            case 2: {
                                //Potion

                                player_->checkYourPokemons();
                                Game::getIntBetween(choice, 1, player_->getNumberOfPokemons(), "Choose a pokemon: ",
                                                    "Enter a number between 1 and " +
                                                    player_->getNumberOfPokemons());
                                if (!player_->useItem("Potions", player_->getPokemon(choice - 1))) {
                                    cout << "Your potion didnt have any effect on "
                                         << player_->getPokemon(choice - 1)->getName() << endl;
                                } else
                                    couldUsePotionOrRevive = true;

                                break;
                            }
                            case 3: {
                                player_->checkYourPokemons();
                                Game::getIntBetween(choice, 1, player_->getNumberOfPokemons(), "Choose a pokemon: ",
                                                    "Enter a number between 1 and " + player_->getNumberOfPokemons());
                                if (!player_->useItem("Revives", player_->getPokemon(choice - 1))) {
                                    cout << "Your revive didnt have any effect on "
                                         << player_->getPokemon(choice - 1)->getName() << endl;

                                } else
                                    couldUsePotionOrRevive = true;
                                break;
                            }
                        }
                        if (couldUsePotionOrRevive)
                            wildPokemonAttacks(wildPokemon, player_->getFavoritePokemon());
                        break;

                    }
                    case 3: {
                        if (player_->checkYourPokemons()) {
                            cout << "Enter the Pokemon you wish to use: " << flush;
                            std::string choice;
                            cin >> choice;
                            player_->setFavoritePokemon(choice);
                        }
                        break;
                    }

                    case 4: {
                        gameState_->process_event(EvFlee(false));
                        battling = false;
                        break;
                    }
                }

            }
        } else {
            std::cout << "Sadly you didn't find any Pokemons" <<
                      std::endl;
        }
    }
    //TODO put these somewhere else.
    //gameState_->process_event(EvBallThrow());

    //gameState_->process_event(EvCatch());
    void Game::setPlayer(Player *player) {
        player_ = player;
    }

    void Game::setShop(Shop *shop) {
        shop_ = shop;
    }

    void Game::enteredShop() {
        bool buying = true;

        while (buying) {
            shop_->listItems();


            cout << "What would you like to do: " << endl;
            cout << "'1' Buy a Potion\t" << flush;
            cout << "'2' Buy a Pokeball" << endl;
            cout << "'3' Buy a Revive\t" << flush;
            cout << "'4' Leave" << endl;

            int choice;
            getIntBetween(choice, 1, 4, "Please choose an action: ", "Please select a number from 1 to 4");
            cout << endl;
            switch (choice) {
                case 1: {
                    cout << "How many items do you want to buy? " << flush;
                    cin >> choice;
                    shop_->buyItem("Potions", choice, player_);
                    break;
                }

                case 2:
                    cout << "How many items do you want to buy? " << flush;
                    cin >> choice;
                    shop_->buyItem("Potions", choice, player_);
                    break;

                case 3: {
                    cout << "How many items do you want to buy? " << flush;
                    cin >> choice;
                    shop_->buyItem("Potions", choice, player_);
                    break;
                }

                case 4: {
                    buying = false;
                    break;
                }


            }
        }


    }

//Taken from: http://stackoverflow.com/questions/15467412/c-cin-only-accept-numeric-values
    void Game::getIntBetween(int &choice, int min, int max, std::string prompt, std::string fail) {

        while (1) {
            Game::getInt(choice, prompt, fail);
            if (choice > max || choice < min) {
                std::cout << "Sorry, your choice is out of range.\n";
                continue;
            }
            break;
        }


    }

//Taken from: http://stackoverflow.com/questions/15467412/c-cin-only-accept-numeric-values
    void Game::getInt(int &choice, std::string prompt, std::string fail) {

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
                choice = val1;
                break;
            }
        }

    }

    void Game::wildPokemonAttacks(std::shared_ptr<IPokemon> wildPokemon, std::shared_ptr<IPokemon> ourPokemon) {

        int wildNumberOfMoves = wildPokemon->getMoves().size();

        int randomChoice = rand() % wildNumberOfMoves + 1;

        //Wild ourPokemon attacks
        wildPokemon->doMove(ourPokemon.get(), randomChoice - 1);

    }


}






