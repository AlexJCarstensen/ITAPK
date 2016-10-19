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
        initializeMoves();
        populateWorldWithPokemons();
        initializeStateMachine();
//        for (auto &&item : this->elements_)
//        {
//            cout << item.second.use_count() << endl;
//        }
    }

    void Game::populateWorldWithPokemons() {
        //To satisfy compiler..... for now
        std:
        vector<std::shared_ptr<IMove>> emptyMoves;
        /******************
        *  Fire Pokemons  *
        ******************/

        MoveChooser<(int) Elements::FIRE> fireMoveChooser;

        Pokemon *charmander = new Pokemon("Charmander", elements_.find(Elements::FIRE)->second, randomNumber(1, 100),
                                          fireMoveChooser.getMoves());
        Pokemon *moltres = new Pokemon("Moltres", elements_.find(Elements::FIRE)->second, randomNumber(1, 100),
                                       fireMoveChooser.getMoves());
        Pokemon *charizard = new Pokemon("Charizard", elements_.find(Elements::FIRE)->second, randomNumber(1, 100),
                                         fireMoveChooser.getMoves());
        Pokemon *arcanine = new Pokemon("Arcanine", elements_.find(Elements::FIRE)->second, randomNumber(1, 100),
                                        fireMoveChooser.getMoves());
        Pokemon *magmar = new Pokemon("Magmar", elements_.find(Elements::FIRE)->second, randomNumber(1, 100),
                                      fireMoveChooser.getMoves());
        Pokemon *flareon = new Pokemon("Flareon", elements_.find(Elements::FIRE)->second, randomNumber(1, 100),
                                       fireMoveChooser.getMoves());

        /***********************
        *  Lightning Pokemons  *
        ***********************/
        MoveChooser<(int) Elements::LIGHTNING> lightningMoveChooser;

        Pokemon *pickachu = new Pokemon("Pickachu", elements_.find(Elements::LIGHTNING)->second, randomNumber(1, 100),
                                        lightningMoveChooser.getMoves());
        Pokemon *electrabuzz = new Pokemon("Electrabuzz", elements_.find(Elements::LIGHTNING)->second,
                                           randomNumber(1, 100), lightningMoveChooser.getMoves());
        Pokemon *magneton = new Pokemon("Magneton", elements_.find(Elements::LIGHTNING)->second, randomNumber(1, 100),
                                        lightningMoveChooser.getMoves());
        Pokemon *electrode = new Pokemon("Electrode", elements_.find(Elements::LIGHTNING)->second, randomNumber(1, 100),
                                         lightningMoveChooser.getMoves());
        Pokemon *jolteon = new Pokemon("Jolteon", elements_.find(Elements::LIGHTNING)->second, randomNumber(1, 100),
                                       lightningMoveChooser.getMoves());
        Pokemon *zapdos = new Pokemon("Zapdos", elements_.find(Elements::LIGHTNING)->second, randomNumber(1, 100),
                                      lightningMoveChooser.getMoves());

        /*******************
        *  Water Pokemons  *
        *******************/
        MoveChooser<(int) Elements::WATER> waterMoveChooser;

        Pokemon *squirtle = new Pokemon("Squirtle", elements_.find(Elements::WATER)->second, randomNumber(1, 100),
                                        waterMoveChooser.getMoves());
        Pokemon *blastoise = new Pokemon("Blastoise", elements_.find(Elements::WATER)->second, randomNumber(1, 100),
                                         waterMoveChooser.getMoves());
        Pokemon *vaporeon = new Pokemon("Vaporeon", elements_.find(Elements::WATER)->second, randomNumber(1, 100),
                                        waterMoveChooser.getMoves());
        Pokemon *lapras = new Pokemon("Lapras", elements_.find(Elements::WATER)->second, randomNumber(1, 100),
                                      waterMoveChooser.getMoves());
        Pokemon *magikarp = new Pokemon("Magikarp", elements_.find(Elements::WATER)->second, randomNumber(1, 100),
                                        waterMoveChooser.getMoves());
        Pokemon *omastar = new Pokemon("Omastar", elements_.find(Elements::WATER)->second, randomNumber(1, 100),
                                       waterMoveChooser.getMoves());

        /*******************
        *  Grass Pokemons  *
        *******************/

        MoveChooser<(int) Elements::GRASS> grassMoveChooser;

        Pokemon *bulbasaur = new Pokemon("Bulbasaur", elements_.find(Elements::GRASS)->second, randomNumber(1, 100),
                                         grassMoveChooser.getMoves());
        Pokemon *venosaur = new Pokemon("Venosaur", elements_.find(Elements::GRASS)->second, randomNumber(1, 100),
                                        grassMoveChooser.getMoves());
        Pokemon *butterfree = new Pokemon("Butterfree", elements_.find(Elements::GRASS)->second, randomNumber(1, 100),
                                          grassMoveChooser.getMoves());
        Pokemon *victreebel = new Pokemon("Victreebel", elements_.find(Elements::GRASS)->second, randomNumber(1, 100),
                                          grassMoveChooser.getMoves());
        Pokemon *exeggutor = new Pokemon("Exeggutor", elements_.find(Elements::GRASS)->second, randomNumber(1, 100),
                                         grassMoveChooser.getMoves());
        Pokemon *scyther = new Pokemon("Scyther", elements_.find(Elements::GRASS)->second, randomNumber(1, 100),
                                       grassMoveChooser.getMoves());

        /********************
        *  Ground Pokemons  *
        ********************/
        MoveChooser<(int) Elements::GROUND> groundMoveChooser;


        Pokemon *diglett = new Pokemon("Diglett", elements_.find(Elements::GROUND)->second, randomNumber(1, 100),
                                       groundMoveChooser.getMoves());
        Pokemon *golem = new Pokemon("Golem", elements_.find(Elements::GROUND)->second, randomNumber(1, 100),
                                     groundMoveChooser.getMoves());
        Pokemon *machoke = new Pokemon("Machoke", elements_.find(Elements::GROUND)->second, randomNumber(1, 100),
                                       groundMoveChooser.getMoves());
        Pokemon *kabutops = new Pokemon("Kabutops", elements_.find(Elements::GROUND)->second, randomNumber(1, 100),
                                        groundMoveChooser.getMoves());
        Pokemon *sandslash = new Pokemon("Sandslash", elements_.find(Elements::GROUND)->second, randomNumber(1, 100),
                                         groundMoveChooser.getMoves());
        Pokemon *machamp = new Pokemon("Machamp", elements_.find(Elements::GROUND)->second, randomNumber(1, 100),
                                       groundMoveChooser.getMoves());


        IPokemon *debugMon = bulbasaur;

        cout << debugMon->getName() << " moves: " << endl;

        debugMon->DisplayMoves();

        cout << butterfree->getName() << " moves: " << endl;

        butterfree->DisplayMoves();


        std::vector<IPokemon *> pokemons = {charmander, moltres, charizard, arcanine, magmar, flareon,
                                            pickachu, electrabuzz, magneton, electrode, jolteon, zapdos,
                                            squirtle, blastoise, vaporeon, lapras, magikarp, omastar,
                                            bulbasaur, venosaur, butterfree, victreebel, exeggutor, scyther,
                                            diglett, golem, machoke, kabutops, sandslash, machamp};

        setPokemons(pokemons);
//        pokemons_ = {
//                };

//        for (auto && poke : pokemons_) {
//            cout << poke->getHealth() << endl;
//}
//        for (auto && item : this->elements_) {
//            cout <<item.second.use_count()<< endl;
//        }

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
//        for (auto && item : this->elements_) {
//            cout <<item.second.use_count()<< endl;
//        }
    }

    void Game::initializeMoves() {

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
        player_->setPokemonsSeen(pokemons_); //TODO DEBUG
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


    std::vector<IPokemon *> Game::getPokemons() {
        return pokemons_;
    }

    void Game::setPokemons(std::vector<IPokemon *> pokemons) {
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
        for (auto &&pokemon : pokemons_) {
            delete pokemon;
        }
        delete instance_;
    }


    void Game::encounterPokemon() {


        if (randomNumber(0, 100) > 50) {
            gameState_->process_event(EvEncounter());
            IPokemon *PokemonPtr;

            auto getRandomPokemon = [&PokemonPtr, this] {
                PokemonPtr = pokemons_[randomNumber(0, pokemons_.size() - 1)];

                while (PokemonPtr->isCaught())
                    PokemonPtr = pokemons_[randomNumber(0, pokemons_.size() - 1)];

                return PokemonPtr;
            };

            std::cout << "Wild " << getRandomPokemon()->getName() << " encountered" << std::endl;
            bool battling = true;
            while (battling) {
                char choice;

                cout << "The Wild Pokemon "  << flush;
                PokemonPtr->printPokemon();
                cout << endl << endl;
                if (!player_->getFavoritePokemon()) {
                    cout << "Your " << flush;
                    player_->getFavoritePokemon()->printPokemon();
                    cout << endl << endl;
                }
                else
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
                      if (!player_->getFavoritePokemon())
                            player_->fight(PokemonPtr);
                        break;
                    }

                    case '2':
                        player_->checkYourItems();
                        break;

                    case '3': {
                       if( player_->checkYourPokemons())
                       {
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

            PokemonPtr = nullptr;


            //TODO put these somewhere else.
            gameState_->

                    process_event(EvBallThrow());

            gameState_->

                    process_event(EvCatch());
        } else {
            std::cout << "Sadly you didn't find any Pokemons" <<
                      std::endl;
        }

    }

    void Game::setPlayer(Player *player) {
        player_ = player;
    }


}