
#include "Game/States/pokemonState.h"


using namespace pokemonGame;


int main() {

    std::shared_ptr<GameState> gameStatePtr = std::make_shared<GameState>();
    std::shared_ptr<Shop> shopPtr = std::make_shared<Shop>();
    std::shared_ptr<Player> playerPtr = std::make_shared<Player>();
    Game::getInstance()->setGameState(gameStatePtr);
    Game::getInstance()->setShop(shopPtr);
    Game::getInstance()->startGame();
    Game::getInstance()->setPlayer(playerPtr);
    Game::getInstance()->enterWorld();

    return 0;
}