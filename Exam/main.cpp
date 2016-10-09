
#include "pokemonState.h"
#include "Pokemon.h"


using namespace pokemonGame;

int main()
{

    Game game;
    game.initiate();

    game.process_event(EvGameOn());
    game.process_event(EvEncounter());
    game.process_event(EvBallThrow());
    game.process_event(EvBrokeFree());
    game.process_event(EvBallThrow());
    game.process_event(EvCatch());
    game.process_event(EvEncounter());
    game.process_event(EvFlee());
    game.process_event(EvEncounter());
    game.process_event(EvFaint());
    game.process_event(EvGameOff());

    Pokemon<23> pikachu("pikachu", pokemonGame::Element::Lightning);

    return 0;
}