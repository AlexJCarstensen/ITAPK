
#include "pokemonState.h"


using namespace pokemonGame;


int main() {



    std::unique_ptr<GameState> gameStatePtr(new GameState());
    Game::getInstance()->setGameState(gameStatePtr.get());
    std::unique_ptr<Shop> shopPtr(new Shop());
    Game::getInstance()->setShop(shopPtr.get());
    Game::getInstance()->startGame();
    std::unique_ptr<Player> playerPtr(new Player());
    Game::getInstance()->setPlayer(playerPtr.get());
    Game::getInstance()->enterWorld();






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




    return 0;
}