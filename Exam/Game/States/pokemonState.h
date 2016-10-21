//
// Created by plex on 10/9/16.
//

#ifndef EXAM_POKEMONSTATE_H
#define EXAM_POKEMONSTATE_H



#include <iostream>

#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/transition.hpp>
#include <boost/statechart/custom_reaction.hpp>
#include <boost/signals2/signal.hpp>
#include "../macro.h"
#include "../Game.h"
#include "GameState.h"

namespace pokemonGame
{
    //TODO make if debug and the print out

    namespace sc = boost::statechart;
    /*****************
    * For debugging *
    *****************/


#define PRINT_ENTRY_EXIT(lvl, name)     \
    name() { macro::print(lvl ,#name"()"); }   \
    ~name() { macro::print(lvl ,"~"#name"()"); }

    /*****************
     *     Events    *
     *****************/

    struct EvEncounter : sc::event<EvEncounter>
    {
    };
    struct EvFlee : sc::event<EvFlee>
    {
        bool didPokemonFlee_;

        EvFlee(const bool didPokemonFlee) : didPokemonFlee_(didPokemonFlee) {
            if(didPokemonFlee)
                std::cout << "Pokemon fled" << std::endl;
            else
                std::cout << "Safely got away" << std::endl;

        }
    };
    struct EvCatch : sc::event<EvCatch>
    {
    };
    struct EvFaint : sc::event<EvFaint>
    {
    };
    struct EvBrokeFree : sc::event<EvBrokeFree>
    {
    };
    struct EvBallThrow : sc::event<EvBallThrow>
    {
    };
    struct EvGameOn : sc::event<EvGameOn>
    {
    };
    struct EvGameOff : sc::event<EvGameOff>
    {
    };


    /************************
     * Forward declarations *
     ************************/
    struct Playing;
    struct NotPlaying;
    struct Roaming;
    struct Encountering;
    struct Battling;
    struct Catching;

    /**********
     * States *
     **********/

    struct NotPlaying : sc::simple_state<NotPlaying, GameState>
    {
        typedef sc::transition<EvGameOn, Playing> reactions;
        PRINT_ENTRY_EXIT(0, NotPlaying)
    };

    struct Playing : sc::simple_state<Playing, GameState, Roaming>
    {
        typedef sc::transition<EvGameOff, NotPlaying> reactions;
        PRINT_ENTRY_EXIT(0, Playing)
    };

    struct Roaming : sc::simple_state<Roaming, Playing>
    {
        typedef sc::transition<EvEncounter, Encountering>  reactions;
        PRINT_ENTRY_EXIT(1, Roaming)
    };


    struct Encountering : sc::simple_state<Encountering, Playing, Battling>
    {
        typedef boost::mpl::list<sc::transition<EvFlee, Roaming>,
                sc::transition<EvCatch, Roaming>,
                sc::transition<EvFaint, Roaming>
        > reactions;

        PRINT_ENTRY_EXIT(1, Encountering)
    };

    struct Battling : sc::simple_state<Battling, Encountering>
    {
        typedef sc::transition<EvBallThrow, Catching> reactions;
        PRINT_ENTRY_EXIT(2, Battling);
    };

    struct Catching : sc::simple_state<Catching, Encountering>
    {
        typedef sc::transition<EvBrokeFree, Battling> reactions;
        PRINT_ENTRY_EXIT(2, Catching);

    };


}


#endif //EXAM_POKEMONSTATE_H
