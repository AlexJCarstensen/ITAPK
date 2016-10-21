
#include "Game/States/pokemonState.h"


using namespace pokemonGame;


int main() {


//TODO Bubble was normally effective on Arcanine ???? Even though pokemon is fainted it can still attack!!!
    std::shared_ptr<GameState> gameStatePtr = std::make_shared<GameState>();
    std::shared_ptr<Shop> shopPtr = std::make_shared<Shop>();
    std::shared_ptr<Player> playerPtr = std::make_shared<Player>();
    Game::getInstance()->setGameState(gameStatePtr);
    Game::getInstance()->setShop(shopPtr);
    Game::getInstance()->startGame();
    Game::getInstance()->setPlayer(playerPtr);
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