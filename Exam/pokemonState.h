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

namespace pokemonGame
{

    namespace sc = boost::statechart;

    /*****************
     * For debugging *
     *****************/

    void print(unsigned int lvl, const std::string &name)
    {
        for (unsigned int i = 0; i < lvl; i++)
            std::cout << "*" << std::flush;
        std::cout << " " << name << std::endl;
    }

#define PRINT_ENTRY_EXIT(lvl, name)     \
    name() { print(lvl ,#name"()"); }   \
    ~name() { print(lvl ,"~"#name"()"); }

    /*****************
     *     Events    *
     *****************/

    struct EvEncounter : sc::event<EvEncounter>
    {
    };
    struct EvFlee : sc::event<EvFlee>
    {
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

    struct Game : sc::state_machine<Game, NotPlaying>
    {

    };

    struct NotPlaying : sc::simple_state<NotPlaying, Game>
    {
        typedef sc::transition<EvGameOn, Playing> reactions;
        PRINT_ENTRY_EXIT(0, NotPlaying)
    };

    struct Playing : sc::simple_state<Playing, Game, Roaming>
    {
        typedef sc::transition<EvGameOff, NotPlaying> reactions;
        PRINT_ENTRY_EXIT(0, Playing)
    };

    struct Roaming : sc::simple_state<Roaming, Playing>
    {
        typedef sc::transition<EvEncounter, Encountering> reactions;
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
