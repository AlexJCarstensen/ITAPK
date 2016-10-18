
#include "pokemonState.h"
#include <iostream>
#include "Element.h"
#include "Pokemon.h"
#include "Game.h"
#include "Move.h"


using namespace pokemonGame;




int main()
{

    std::unique_ptr<GameState> gameStatePtr (new GameState());
    Game game(gameStatePtr.get());
    game.startGame();
    Player player(gameStatePtr.get());
    game.enterWorld(player);



//    auto t = game.seePokemons();
//    auto s = game.seeElements();
////    for (auto &&item : t)
////    {
////        //std::cout <<  item->getHealth() << std::endl;
////        std::cout <<  item->getElement() << std::endl;
////
////
////    }
//
//    for (auto &&item : s)
//    {
//        //std::cout <<  item->getHealth() << std::endl;
//        std::cout <<  item.second.use_count() << std::endl;
//
//
//    }
//    GameState gameState;
//    gameState.initiate();
//    gameState.process_event(EvGameOn());
//    gameState.process_event(EvEncounter());
//    gameState.process_event(EvBallThrow());
//    gameState.process_event(EvBrokeFree());
//    gameState.process_event(EvBallThrow());
//    gameState.process_event(EvCatch());
//    gameState.process_event(EvEncounter());
//    gameState.process_event(EvFlee());
//    gameState.process_event(EvEncounter());
//    gameState.process_event(EvFaint());
//    gameState.process_event(EvGameOff());

    // SHARED Ptr i forhold til hvor mange pokemoner der har reference til et bestemt element

   // Water water;
  //  Fire fire;
   // Pokemon pikachu("pikachu", water, 2);
    //Pokemon pikachu1("pikachu1", fire, 2);




//   if(pikachu.getElement() == pikachu1.getElement())
//        std::cout << "hej" << std::endl;
//
//    AttackMove fireBlast(fire,"Fire Blast", 80);
//
//    AttackMove waterGun(water, "Water Gun", 80);
//
//    fireBlast.doMove(pikachu);
    

    return 0;
}