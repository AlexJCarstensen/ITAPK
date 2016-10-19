//
// Created by ubuntuudvikling on 10/17/16.
//


#include "Game.h"
#include "pokemonState.h"
#include "MoveChoosers.h"


using namespace std;

namespace pokemonGame {
    Game *Game::instance_ = nullptr;


    void Game::startGame()
    {

        initializeElements();
        initializeMoves();
        populateWorldWithPokemons();
        initializeStateMachine();
//        for (auto &&item : this->elements_)
//        {
//            cout << item.second.use_count() << endl;
//        }
    }

    void Game::populateWorldWithPokemons()
    {
        //To satisfy compiler..... for now
        std:vector<std::shared_ptr<IMove>> emptyMoves;
        /******************
        *  Fire Pokemons  *
        ******************/

        MoveChooser<(int)Elements::FIRE> fireMoveChooser;
        std::vector<std::shared_ptr<IMove>> fireMoves = fireMoveChooser.getMoves();

        Pokemon *charmander = new Pokemon("Charmander", elements_.find(Elements::FIRE)->second, randomLvl(1,100), fireMoves);
        Pokemon *moltres = new Pokemon("Moltres", elements_.find(Elements::FIRE)->second, randomLvl(1,100),fireMoves);
        Pokemon *charizard = new Pokemon("Charizard", elements_.find(Elements::FIRE)->second, randomLvl(1,100), fireMoves);
        Pokemon *arcanine = new Pokemon("Arcanine", elements_.find(Elements::FIRE)->second, randomLvl(1,100), fireMoves);
        Pokemon *magmar = new Pokemon("Magmar", elements_.find(Elements::FIRE)->second, randomLvl(1,100), fireMoves);
        Pokemon *flareon = new Pokemon("Flareon", elements_.find(Elements::FIRE)->second, randomLvl(1,100), fireMoves);

        /***********************
        *  Lightning Pokemons  *
        ***********************/
        MoveChooser<(int)Elements::LIGHTNING> lightningMoveChooser;
        std::vector<std::shared_ptr<IMove>> lightningMoves = lightningMoveChooser.getMoves();
        Pokemon *pickachu = new Pokemon("Pickachu", elements_.find(Elements::LIGHTNING)->second, randomLvl(1,100), lightningMoves);
        Pokemon *electrabuzz = new Pokemon("Electrabuzz", elements_.find(Elements::LIGHTNING)->second, randomLvl(1,100),lightningMoves);
        Pokemon *magneton = new Pokemon("Magneton", elements_.find(Elements::LIGHTNING)->second, randomLvl(1,100), lightningMoves);
        Pokemon *electrode = new Pokemon("Electrode", elements_.find(Elements::LIGHTNING)->second, randomLvl(1,100), lightningMoves);
        Pokemon *jolteon = new Pokemon("Jolteon", elements_.find(Elements::LIGHTNING)->second, randomLvl(1,100), lightningMoves);
        Pokemon *zapdos = new Pokemon("Zapdos", elements_.find(Elements::LIGHTNING)->second, randomLvl(1,100), lightningMoves);

        /*******************
        *  Water Pokemons  *
        *******************/

        Pokemon *squirtle = new Pokemon("Squirtle", elements_.find(Elements::WATER)->second, randomLvl(1,100),emptyMoves);
        Pokemon *blastoise = new Pokemon("Blastoise", elements_.find(Elements::WATER)->second, randomLvl(1,100), emptyMoves);
        Pokemon *vaporeon = new Pokemon("Vaporeon", elements_.find(Elements::WATER)->second, randomLvl(1,100), emptyMoves);
        Pokemon *lapras = new Pokemon("Lapras", elements_.find(Elements::WATER)->second, randomLvl(1,100), emptyMoves);
        Pokemon *magikarp = new Pokemon("Magikarp", elements_.find(Elements::WATER)->second, randomLvl(1,100), emptyMoves);
        Pokemon *omastar = new Pokemon("Omastar", elements_.find(Elements::WATER)->second, randomLvl(1,100),emptyMoves);

        /*******************
        *  Grass Pokemons  *
        *******************/

        Pokemon *bulbasaur = new Pokemon("Bulbasaur", elements_.find(Elements::GRASS)->second,randomLvl(1,100), emptyMoves);
        Pokemon *venosaur = new Pokemon("Venosaur", elements_.find(Elements::GRASS)->second, randomLvl(1,100), emptyMoves);
        Pokemon *butterfree = new Pokemon("Butterfree", elements_.find(Elements::GRASS)->second, randomLvl(1,100), emptyMoves);
        Pokemon *victreebel = new Pokemon("Victreebel", elements_.find(Elements::GRASS)->second, randomLvl(1,100),emptyMoves);
        Pokemon *exeggutor = new Pokemon("Exeggutor", elements_.find(Elements::GRASS)->second, randomLvl(1,100), emptyMoves);
        Pokemon *scyther = new Pokemon("Scyther", elements_.find(Elements::GRASS)->second, randomLvl(1,100),emptyMoves);

        /********************
        *  Ground Pokemons  *
        ********************/

        Pokemon *diglett = new Pokemon("Diglett", elements_.find(Elements::GROUND)->second, randomLvl(1,100), emptyMoves);
        Pokemon *golem = new Pokemon("Golem", elements_.find(Elements::GROUND)->second, randomLvl(1,100), emptyMoves);
        Pokemon *machoke = new Pokemon("Machoke", elements_.find(Elements::GROUND)->second, randomLvl(1,100), emptyMoves);
        Pokemon *kabutops = new Pokemon("Kabutops", elements_.find(Elements::GROUND)->second, randomLvl(1,100), emptyMoves);
        Pokemon *sandslash = new Pokemon("Sandslash", elements_.find(Elements::GROUND)->second, randomLvl(1,100), emptyMoves);
        Pokemon *machamp = new Pokemon("Machamp", elements_.find(Elements::GROUND)->second, randomLvl(1,100),emptyMoves);


        IPokemon *debugMon = pickachu;

        cout << debugMon->getName() << " moves: " << endl;

        debugMon->DisplayMoves();


        std::vector<IPokemon*> pokemons = {charmander, moltres, charizard, arcanine, magmar, flareon,
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


    void Game::initializeElements()
    {
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

    void Game::initializeMoves()
    {

    }

    void Game::initializeStateMachine()
    {
        gameState_->initiate();
    }

    int Game::randomLvl(int min, int max)
    {
        random_device rd;
        mt19937 eng(rd());
        uniform_int_distribution<> distr(min, max);
        return distr(eng);
    }



    map<Elements, shared_ptr<Element>> Game::seeElements()
    {
        return elements_;
    }

    void Game::enterWorld()
    {
        //player.setPokemonsSeen(pokemons_); //TODO DEBUG
        cout << "Welcome to the world of Pokemons" << endl;
        gameState_->process_event(EvGameOn());
        bool playing = true;
        while (playing)
        {
            char choice;

            cout << "What would you like to do?" << endl;
            cout << "'1' Walk in the wilderness" << endl;
            cout << "'2' Go to the shop" << endl;
            cout << "'3' Take a loot in the pokedex" << endl;
            cout << "'4' Check your Pokemons" << endl;
            cout << "'5' Check your items" << endl;
            cout << "'6' Go home" << endl;

            cout << "Your choice: " << flush;
            cin >> choice;

            switch (choice)
            {
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

                case '5':
                    player_->checkYourItems();
                    break;

                case '6':
                    playing = false;
                    break;


            }
        }
    }



    std::vector<IPokemon *> Game::getPokemons() {
        return pokemons_;
    }

    void Game::setPokemons(std::vector<IPokemon*> pokemons) {
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

        gameState_->process_event(EvEncounter());
        IPokemon* PokemonPtr;

        auto getRandomPokemon = [&PokemonPtr, this]{
            PokemonPtr = pokemons_[randomLvl(0,pokemons_.size()-1)];

            while(PokemonPtr->isCaught())
                PokemonPtr = pokemons_[randomLvl(0,pokemons_.size()-1)];

            return PokemonPtr;
        };

        std::cout << "Wild " << getRandomPokemon()->getName() << " encountered" << std::endl;

    }

    void Game::setPlayer(Player *player) {
        player_ = player;
    }


}