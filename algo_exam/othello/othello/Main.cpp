#include <iostream>
#include "Game.h"

int main()
{
    clock_t start, end;
    srand(time(NULL));
    Game game = Game();
    game.Start();
}