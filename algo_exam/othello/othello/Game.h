#pragma once



#include"Grid.h"
#include "Defs.h"

class Game
{
public:
    Game();
    void Start();
    void ChoiceName();

private:
    Grid* grid;
    void Restart();
    void PlayerTurn();
    void OtherTurn();
    bool HandleWin();


};
