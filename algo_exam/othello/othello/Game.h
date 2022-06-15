#pragma once



#include<iostream>
#include"Grid.h"
#include<string>

class Game
{
public:
    Game();
    void Start();

private:
    Grid* grid;
    void Restart();
    void PlayerTurn();
    void OtherTurn();
    bool HandleWin();


};