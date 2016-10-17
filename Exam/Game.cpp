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
        ******************/

        Pokemon *charmander = new Pokemon("Charmander", elements_.find(Elements::FIRE)->second, randomLvl());
        Pokemon *moltres = new Pokemon("Moltres", elements_.find(Elements::FIRE)->second, randomLvl());
        Pokemon *charizard = new Pokemon("Charizard", elements_.find(Elements::FIRE)->second, randomLvl());
        Pokemon *arcanine = new Pokemon("Arcanine", elements_.find(Elements::FIRE)->second, randomLvl());
        Pokemon *magmar = new Pokemon("Magmar", elements_.find(Elements::FIRE)->second, randomLvl());
        Pokemon *flareon = new Pokemon("Flareon", elements_.find(Elements::FIRE)->second, randomLvl());

        /***********************
        *  Lightning Pokemons  *
        ***********************/

        Pokemon *pickachu = new Pokemon("Pickachu", elements_.find(Elements::LIGHTNING)->second, randomLvl());
        Pokemon *electrabuzz = new Pokemon("Electrabuzz", elements_.find(Elements::LIGHTNING)->second, randomLvl());
        Pokemon *magneton = new Pokemon("Magneton", elements_.find(Elements::LIGHTNING)->second, randomLvl());
        Pokemon *electrode = new Pokemon("Electrode", elements_.find(Elements::LIGHTNING)->second, randomLvl());
        Pokemon *jolteon = new Pokemon("Jolteon", elements_.find(Elements::LIGHTNING)->second, randomLvl());
        Pokemon *zapdos = new Pokemon("Zapdos", elements_.find(Elements::LIGHTNING)->second, randomLvl());

        /*******************
        *  Water Pokemons  *
        *******************/

        Pokemon *squirtle = new Pokemon("Squirtle", elements_.find(Elements::WATER)->second, randomLvl());
        Pokemon *blastoise = new Pokemon("Blastoise", elements_.find(Elements::WATER)->second, randomLvl());
        Pokemon *vaporeon = new Pokemon("Vaporeon", elements_.find(Elements::WATER)->second, randomLvl());
        Pokemon *lapras = new Pokemon("Lapras", elements_.find(Elements::WATER)->second, randomLvl());
        Pokemon *magikarp = new Pokemon("Magikarp", elements_.find(Elements::WATER)->second, randomLvl());
        Pokemon *omastar = new Pokemon("Omastar", elements_.find(Elements::WATER)->second, randomLvl());

        /*******************
        *  Grass Pokemons  *
        *******************/

        Pokemon *bulbasaur = new Pokemon("Bulbasaur", elements_.find(Elements::GRASS)->second, randomLvl());
        Pokemon *venosaur = new Pokemon("Venosaur", elements_.find(Elements::GRASS)->second, randomLvl());
        Pokemon *butterfree = new Pokemon("Butterfree", elements_.find(Elements::GRASS)->second, randomLvl());
        Pokemon *victreebel = new Pokemon("Victreebel", elements_.find(Elements::GRASS)->second, randomLvl());
        Pokemon *exeggutor = new Pokemon("Exeggutor", elements_.find(Elements::GRASS)->second, randomLvl());
        Pokemon *scyther = new Pokemon("Scyther", elements_.find(Elements::GRASS)->second, randomLvl());

        /********************
        *  Ground Pokemons  *
        ********************/

        Pokemon *diglett = new Pokemon("Diglett", elements_.find(Elements::GROUND)->second, randomLvl());
        Pokemon *golem = new Pokemon("Golem", elements_.find(Elements::GROUND)->second, randomLvl());
        Pokemon *machoke = new Pokemon("Machoke", elements_.find(Elements::GROUND)->second, randomLvl());
        Pokemon *kabutops = new Pokemon("Kabutops", elements_.find(Elements::GROUND)->second, randomLvl());
        Pokemon *sandslash = new Pokemon("Sandslash", elements_.find(Elements::GROUND)->second, randomLvl());
        Pokemon *machamp = new Pokemon("Machamp", elements_.find(Elements::GROUND)->second, randomLvl());


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
        std::shared_ptr<Element> firePtr = std::make_shared<Fire>();
        std::shared_ptr<Element> GrassPtr = std::make_shared<Grass>();
        std::shared_ptr<Element> lightningPtr = std::make_shared<Lightning>();
        std::shared_ptr<Element> groundPtr = std::make_shared<Ground>();
        std::shared_ptr<Element> waterPtr = std::make_shared<Water>();

        elements_ =
                {std::make_pair(Elements::FIRE, firePtr), std::make_pair(Elements::GRASS, GrassPtr),
                 std::make_pair(Elements::LIGHTNING, lightningPtr), std::make_pair(Elements::GROUND, groundPtr),
                 std::make_pair(Elements::WATER, waterPtr)};
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
        std::random_device rd;
        std::mt19937 eng(rd());
        std::uniform_int_distribution<> distr(1, 100);
        return distr(eng);
    }

    std::vector<IPokemon *> Game::seePokemons()
    {
        return pokemons_;
    }

    map<Elements, shared_ptr<Element>> Game::seeElements()
    {
        return elements_;
    }


}