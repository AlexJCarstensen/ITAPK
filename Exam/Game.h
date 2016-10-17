//
// Created by ubuntuudvikling on 10/17/16.
//

#ifndef EXAM_GAME_H
#define EXAM_GAME_H
#include <iostream>
#include <memory>
#include <map>
#include "Element.h"
#include "Pokemon.h"
#include "Player.h"

namespace pokemonGame {

    class Game  {
    public:

        void startGame();
        void enterWorld(Player& player);
        std::vector<IPokemon*> seePokemons(); //debug
        std::map<Elements, std::shared_ptr<Element>> seeElements();//debug
    private:
        void populateWorldWithPokemons();
        void initializeElements();
        void initializeMoves();
        void initializeStateMachine();
        int randomLvl();


    private:
        std::map<Elements, std::shared_ptr<Element> > elements_{};
        std::vector<IPokemon*> pokemons_{};

        void
    createFirePokemons(Pokemon *&charmander, Pokemon *&moltres, Pokemon *&charizard, Pokemon *&arcanine, Pokemon *&magmar,
                       Pokemon *&flareon);

        void createLightningPokemons(Pokemon *&pickachu, Pokemon *&electrabuzz, Pokemon *&magneton, Pokemon *&electrode,
                                 Pokemon *&jolteon, Pokemon *&zapdos);

        void
    createWaterPokemons(Pokemon *&squirtle, Pokemon *&blastoise, Pokemon *&vaporeon, Pokemon *&lapras, Pokemon *&magikarp,
                        Pokemon *&omastar);

        void createGrassPokemons(Pokemon *&bulbasaur, Pokemon *&venosaur, Pokemon *&butterfree, Pokemon *&victreebel,
                             Pokemon *&exeggutor, Pokemon *&scyther);

        void
    createGroundPokemons(Pokemon *&diglett, Pokemon *&golem, Pokemon *&machoke, Pokemon *&kabutops, Pokemon *&sandslash,
                         Pokemon *&machamp);
    };
}

#endif //EXAM_GAME_H
