//
// Created by ubuntuudvikling on 10/17/16.
//


#include "Game.h"
#include "pokemonState.h"
#include "MoveChoosers.h"


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
        player_->setPokemonsSeen(pokemons_); //TODO debug get all pokemons to player
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
            shared_ptr<IPokemon> PokemonPtr;

            auto getRandomPokemon = [&PokemonPtr, this] {
                PokemonPtr = pokemons_[randomNumber(0, pokemons_.size() - 1)];

                while (PokemonPtr->isCaught())
                    PokemonPtr = pokemons_[randomNumber(0, pokemons_.size() - 1)];

                return PokemonPtr;
            };

            std::cout << "Wild " << getRandomPokemon()->getName() << " appeared" << std::endl << std::endl;
            bool battling = true;
            while (battling) {
                char choice;

                PokemonPtr.get()->printPokemon();
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


                cout << "Your choice: " << flush;
                cin >> choice;
                cout << endl;
                switch (choice) {
                    case '1': {
                        if (player_->hasFavoritePokemon())
                            player_->fight(PokemonPtr);
                        break;
                    }

                    case '2':
                        player_->checkYourItems();
                        break;

                    case '3': {
                        if (player_->checkYourPokemons()) {
                            cout << "Enter the Pokemon you wish to use: " << flush;
                            std::string choice;
                            cin >> choice;
                            player_->setFavoritePokemon(choice);
                        }
                        break;
                    }

                    case '4': {
                        gameState_->process_event(EvFlee(false));
                        battling = false;
                        break;
                    }


                }
            }
            //TODO put these somewhere else.
            //gameState_->process_event(EvBallThrow());

            //gameState_->process_event(EvCatch());
        } else {
            std::cout << "Sadly you didn't find any Pokemons" << std::endl;
        }

    }

    void Game::setPlayer(Player *player) {
        player_ = player;
    }

    void Game::setShop(Shop *shop) {
        shop_ = shop;
    }

    void Game::enteredShop() {
        shop_->listItems();
        //TODO buy item...


    }


}