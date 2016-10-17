
#include "pokemonState.h"
#include <iostream>
#include "Element.h"
#include "Pokemon.h"
#include "Game.h"
#include "Move.h"


using namespace pokemonGame;

int main()
{


    Game game;
    game.startGame();
//    GameState.process_event(EvGameOn());
//    GameState.process_event(EvEncounter());
//    GameState.process_event(EvBallThrow());
//    GameState.process_event(EvBrokeFree());
//    GameState.process_event(EvBallThrow());
//    GameState.process_event(EvCatch());
//    GameState.process_event(EvEncounter());
//    GameState.process_event(EvFlee());
//    GameState.process_event(EvEncounter());
//    GameState.process_event(EvFaint());
//    GameState.process_event(EvGameOff());

    // SHARED Ptr i forhold til hvor mange pokemoner der har reference til et bestemt element

    Water water;
    Fire fire;
    Pokemon pikachu("pikachu", water, 2);
    Pokemon pikachu1("pikachu1", fire, 2);




   if(pikachu.getElement() == pikachu1.getElement())
        std::cout << "hej" << std::endl;

    AttackMove fireBlast(fire,"Fire Blast", 80);

    AttackMove waterGun(water, "Water Gun", 80);

    fireBlast.doMove(pikachu);
    

    return 0;
}