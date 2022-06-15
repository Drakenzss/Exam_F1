#pragma once

#include <iostream>
#include <string>
#include <vector>

class Grid
{
    //public est le domaine qui permet de réutiliser les fonctions et variables partout
public:
    Grid();
    void ClearGrid();
    bool PlaceSymbol(char currentSymbol, int index);
    std::pair<bool, char> DidSomeoneWin();
    void DrawGrid();
    void PlaceOpponentBot();
    bool HasCaseToPlay();

    //structure qui permet de prendre tous les caractères
    struct Symbols {
    public:
        char m_player = 'B';
        char m_opponent = 'N';
        char m_neutral = ' ';

    };

    Symbols m_symbol;

    //privé est le domaine qui permet d'utiler les fonctions et variables uniquement dans grid.cpp
private:
    std::vector<char> _grid; //créer un tableau
    int _numberB = 0;
    int _numberN = 0;

    bool HasWon(char m_symbol);


};