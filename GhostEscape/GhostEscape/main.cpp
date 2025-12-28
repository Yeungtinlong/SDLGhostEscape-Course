#include <GhostEscape/core/game.h>

int main(int, char**)
{
    Game& game = Game::GetInstance();
    game.init("Ghost Escape", 1280, 720);
    game.run();

    return 0;
}