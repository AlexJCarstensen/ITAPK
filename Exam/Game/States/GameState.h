//
// Created by ubuntuudvikling on 10/18/16.
//

#ifndef EXAM_GAMESTATE_H
#define EXAM_GAMESTATE_H


#include <boost/statechart/state_machine.hpp>

namespace pokemonGame{

    namespace sc = boost::statechart;
    struct NotPlaying;

    struct GameState : sc::state_machine<GameState, NotPlaying>
    {

    };
}
#endif //EXAM_GAMESTATE_H
