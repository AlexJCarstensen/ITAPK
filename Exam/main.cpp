
#include "pokemonState.h"
#include <iostream>
#include "Element.h"
#include "Pokemon.h"


using namespace pokemonGame;

int main()
{
//
//    Game game;
//    game.initiate();
//
//    game.process_event(EvGameOn());
//    game.process_event(EvEncounter());
//    game.process_event(EvBallThrow());
//    game.process_event(EvBrokeFree());
//    game.process_event(EvBallThrow());
//    game.process_event(EvCatch());
//    game.process_event(EvEncounter());
//    game.process_event(EvFlee());
//    game.process_event(EvEncounter());
//    game.process_event(EvFaint());
//    game.process_event(EvGameOff());

    //Lightning lightning;
    Fire fire;
    Pokemon pikachu("pikachu", fire, 2);
   // Pokemon pikachu1("pikachu1", fire, 2);

   //if(pikachu == pikachu1)
        std::cout << "hej" << std::endl;

    return 0;
}