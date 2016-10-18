//
// Created by ubuntuudvikling on 10/17/16.
//


#include "Game.h"
#include "pokemonState.h"
#include "Pokemon.h"
#include "Move.h"

using namespace std;

namespace pokemonGame
{
    Game::Game(GameState *gameState) : gameState_(gameState)
    {

    }

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
        std:vector<IMove*> emptyMoves;
        /******************
        *  Fire Pokemons  *
        ******************/

        MoveChooser<(int)Elements::FIRE> fireMoveChooser;
        std::vector<IMove*> fireMoves = fireMoveChooser.getMoves();

        Pokemon *charmander = new Pokemon("Charmander", elements_.find(Elements::FIRE)->second, randomLvl(), fireMoves);
        Pokemon *moltres = new Pokemon("Moltres", elements_.find(Elements::FIRE)->second, randomLvl(),fireMoves);
        Pokemon *charizard = new Pokemon("Charizard", elements_.find(Elements::FIRE)->second, randomLvl(), fireMoves);
        Pokemon *arcanine = new Pokemon("Arcanine", elements_.find(Elements::FIRE)->second, randomLvl(), fireMoves);
        Pokemon *magmar = new Pokemon("Magmar", elements_.find(Elements::FIRE)->second, randomLvl(), fireMoves);
        Pokemon *flareon = new Pokemon("Flareon", elements_.find(Elements::FIRE)->second, randomLvl(), fireMoves);

        /***********************
        *  Lightning Pokemons  *
        ***********************/

        Pokemon *pickachu = new Pokemon("Pickachu", elements_.find(Elements::LIGHTNING)->second, randomLvl(), emptyMoves);
        Pokemon *electrabuzz = new Pokemon("Electrabuzz", elements_.find(Elements::LIGHTNING)->second, randomLvl(),emptyMoves);
        Pokemon *magneton = new Pokemon("Magneton", elements_.find(Elements::LIGHTNING)->second, randomLvl(), emptyMoves);
        Pokemon *electrode = new Pokemon("Electrode", elements_.find(Elements::LIGHTNING)->second, randomLvl(), emptyMoves);
        Pokemon *jolteon = new Pokemon("Jolteon", elements_.find(Elements::LIGHTNING)->second, randomLvl(), emptyMoves);
        Pokemon *zapdos = new Pokemon("Zapdos", elements_.find(Elements::LIGHTNING)->second, randomLvl(), emptyMoves);

        /*******************
        *  Water Pokemons  *
        *******************/

        Pokemon *squirtle = new Pokemon("Squirtle", elements_.find(Elements::WATER)->second, randomLvl(),emptyMoves);
        Pokemon *blastoise = new Pokemon("Blastoise", elements_.find(Elements::WATER)->second, randomLvl(), emptyMoves);
        Pokemon *vaporeon = new Pokemon("Vaporeon", elements_.find(Elements::WATER)->second, randomLvl(), emptyMoves);
        Pokemon *lapras = new Pokemon("Lapras", elements_.find(Elements::WATER)->second, randomLvl(), emptyMoves);
        Pokemon *magikarp = new Pokemon("Magikarp", elements_.find(Elements::WATER)->second, randomLvl(), emptyMoves);
        Pokemon *omastar = new Pokemon("Omastar", elements_.find(Elements::WATER)->second, randomLvl(),emptyMoves);

        /*******************
        *  Grass Pokemons  *
        *******************/

        Pokemon *bulbasaur = new Pokemon("Bulbasaur", elements_.find(Elements::GRASS)->second, randomLvl(), emptyMoves);
        Pokemon *venosaur = new Pokemon("Venosaur", elements_.find(Elements::GRASS)->second, randomLvl(), emptyMoves);
        Pokemon *butterfree = new Pokemon("Butterfree", elements_.find(Elements::GRASS)->second, randomLvl(), emptyMoves);
        Pokemon *victreebel = new Pokemon("Victreebel", elements_.find(Elements::GRASS)->second, randomLvl(),emptyMoves);
        Pokemon *exeggutor = new Pokemon("Exeggutor", elements_.find(Elements::GRASS)->second, randomLvl(), emptyMoves);
        Pokemon *scyther = new Pokemon("Scyther", elements_.find(Elements::GRASS)->second, randomLvl(),emptyMoves);

        /********************
        *  Ground Pokemons  *
        ********************/

        Pokemon *diglett = new Pokemon("Diglett", elements_.find(Elements::GROUND)->second, randomLvl(), emptyMoves);
        Pokemon *golem = new Pokemon("Golem", elements_.find(Elements::GROUND)->second, randomLvl(), emptyMoves);
        Pokemon *machoke = new Pokemon("Machoke", elements_.find(Elements::GROUND)->second, randomLvl(), emptyMoves);
        Pokemon *kabutops = new Pokemon("Kabutops", elements_.find(Elements::GROUND)->second, randomLvl(), emptyMoves);
        Pokemon *sandslash = new Pokemon("Sandslash", elements_.find(Elements::GROUND)->second, randomLvl(), emptyMoves);
        Pokemon *machamp = new Pokemon("Machamp", elements_.find(Elements::GROUND)->second, randomLvl(),emptyMoves);


        pokemons_ = {
                charmander, moltres, charizard, arcanine, magmar, flareon,
                pickachu, electrabuzz, magneton, electrode, jolteon, zapdos,
                squirtle, blastoise, vaporeon, lapras, magikarp, omastar,
                bulbasaur, venosaur, butterfree, victreebel, exeggutor, scyther,
                diglett, golem, machoke, kabutops, sandslash, machamp};

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

    int Game::randomLvl()
    {
        random_device rd;
        mt19937 eng(rd());
        uniform_int_distribution<> distr(1, 100);
        return distr(eng);
    }

    vector<IPokemon *> Game::seePokemons()
    {
        return pokemons_;
    }

    map<Elements, shared_ptr<Element>> Game::seeElements()
    {
        return elements_;
    }

    void Game::enterWorld(Player &player)
    {
        player.setPokemonsSeen(pokemons_); //TODO DEBUG
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
                    player.walkIntoTheWilderness();
                    break;

                case '2':
                    player.goToTheShop();
                    break;

                case '3':
                    player.lookInPokedex();
                    break;

                case '4':
                    player.checkYourPokemons();
                    break;

                case '5':
                    player.checkYourItems();
                    break;

                case '6':
                    playing = false;
                    break;


            }
        }
    }

    Game::~Game()
    {
        for (auto &&pokemon : pokemons_)
        {
            delete pokemon;
        }

    }


}