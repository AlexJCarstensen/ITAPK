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

        /******************
        *  Fire Pokemons  *
        ******************/Pokemon *charmander;
        Pokemon *moltres;
        Pokemon *charizard;
        Pokemon *arcanine;
        Pokemon *magmar;
        Pokemon *flareon;
        createFirePokemons(charmander, moltres, charizard, arcanine, magmar, flareon);

        /***********************
        *  Lightning Pokemons  *
        ***********************/Pokemon *pickachu;
        Pokemon *electrabuzz;
        Pokemon *magneton;
        Pokemon *electrode;
        Pokemon *jolteon;
        Pokemon *zapdos;
        createLightningPokemons(pickachu, electrabuzz, magneton, electrode, jolteon,
                                zapdos);

        /*******************
        *  Water Pokemons  *
        *******************/Pokemon *squirtle;
        Pokemon *blastoise;
        Pokemon *vaporeon;
        Pokemon *lapras;
        Pokemon *magikarp;
        Pokemon *omastar;
        createWaterPokemons(squirtle, blastoise, vaporeon, lapras, magikarp,
                            omastar);

        /*******************
        *  Grass Pokemons  *
        *******************/Pokemon *bulbasaur;
        Pokemon *venosaur;
        Pokemon *butterfree;
        Pokemon *victreebel;
        Pokemon *exeggutor;
        Pokemon *scyther;
        createGrassPokemons(bulbasaur, venosaur, butterfree, victreebel, exeggutor,
                            scyther);

        /********************
        *  Ground Pokemons  *
        ********************/Pokemon *diglett;
        Pokemon *golem;
        Pokemon *machoke;
        Pokemon *kabutops;
        Pokemon *sandslash;
        Pokemon *machamp;
        createGroundPokemons(diglett, golem, machoke, kabutops, sandslash,
                             machamp);


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

    void Game::createGroundPokemons(Pokemon *&diglett, Pokemon *&golem, Pokemon *&machoke, Pokemon *&kabutops,
                                    Pokemon *&sandslash, Pokemon *&machamp)
    {
        diglett= new Pokemon("Diglett", elements_.find(Elements::GROUND)->second, randomLvl());
        golem= new Pokemon("Golem", elements_.find(Elements::GROUND)->second, randomLvl());
        machoke= new Pokemon("Machoke", elements_.find(Elements::GROUND)->second, randomLvl());
        kabutops= new Pokemon("Kabutops", elements_.find(Elements::GROUND)->second, randomLvl());
        sandslash= new Pokemon("Sandslash", elements_.find(Elements::GROUND)->second, randomLvl());
        machamp= new Pokemon("Machamp", elements_.find(Elements::GROUND)->second, randomLvl());
    }

    void Game::createGrassPokemons(Pokemon *&bulbasaur, Pokemon *&venosaur, Pokemon *&butterfree, Pokemon *&victreebel,
                                   Pokemon *&exeggutor, Pokemon *&scyther)
    {
        bulbasaur= new Pokemon("Bulbasaur", elements_.find(Elements::GRASS)->second, randomLvl());
        venosaur= new Pokemon("Venosaur", elements_.find(Elements::GRASS)->second, randomLvl());
        butterfree= new Pokemon("Butterfree", elements_.find(Elements::GRASS)->second, randomLvl());
        victreebel= new Pokemon("Victreebel", elements_.find(Elements::GRASS)->second, randomLvl());
        exeggutor= new Pokemon("Exeggutor", elements_.find(Elements::GRASS)->second, randomLvl());
        scyther= new Pokemon("Scyther", elements_.find(Elements::GRASS)->second, randomLvl());
    }

    void Game::createWaterPokemons(Pokemon *&squirtle, Pokemon *&blastoise, Pokemon *&vaporeon, Pokemon *&lapras,
                                   Pokemon *&magikarp, Pokemon *&omastar)
    {
        squirtle= new Pokemon("Squirtle", elements_.find(Elements::WATER)->second, randomLvl());
        blastoise= new Pokemon("Blastoise", elements_.find(Elements::WATER)->second, randomLvl());
        vaporeon= new Pokemon("Vaporeon", elements_.find(Elements::WATER)->second, randomLvl());
        lapras= new Pokemon("Lapras", elements_.find(Elements::WATER)->second, randomLvl());
        magikarp= new Pokemon("Magikarp", elements_.find(Elements::WATER)->second, randomLvl());
        omastar= new Pokemon("Omastar", elements_.find(Elements::WATER)->second, randomLvl());
    }

    void Game::createLightningPokemons(Pokemon *&pickachu, Pokemon *&electrabuzz, Pokemon *&magneton, Pokemon *&electrode,
                                       Pokemon *&jolteon, Pokemon *&zapdos)
    {
        pickachu= new Pokemon("Pickachu", elements_.find(Elements::LIGHTNING)->second, randomLvl());
        electrabuzz= new Pokemon("Electrabuzz", elements_.find(Elements::LIGHTNING)->second, randomLvl());
        magneton= new Pokemon("Magneton", elements_.find(Elements::LIGHTNING)->second, randomLvl());
        electrode= new Pokemon("Electrode", elements_.find(Elements::LIGHTNING)->second, randomLvl());
        jolteon= new Pokemon("Jolteon", elements_.find(Elements::LIGHTNING)->second, randomLvl());
        zapdos= new Pokemon("Zapdos", elements_.find(Elements::LIGHTNING)->second, randomLvl());
    }

    void Game::createFirePokemons(Pokemon *&charmander, Pokemon *&moltres, Pokemon *&charizard, Pokemon *&arcanine,
                                  Pokemon *&magmar, Pokemon *&flareon)
    {
        charmander= new Pokemon("Charmander", elements_.find(Elements::FIRE)->second, randomLvl());
        moltres= new Pokemon("Moltres", elements_.find(Elements::FIRE)->second, randomLvl());
        charizard= new Pokemon("Charizard", elements_.find(Elements::FIRE)->second, randomLvl());
        arcanine= new Pokemon("Arcanine", elements_.find(Elements::FIRE)->second, randomLvl());
        magmar= new Pokemon("Magmar", elements_.find(Elements::FIRE)->second, randomLvl());
        flareon= new Pokemon("Flareon", elements_.find(Elements::FIRE)->second, randomLvl());
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
        GameState GameState;
        GameState.initiate();

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

    void Game::enterWorld(Player& player)
    {
        cout << "Welcome to the world of Pokemons" << endl;
        bool playing = true;
        while(playing)
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

            switch(choice)
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


}