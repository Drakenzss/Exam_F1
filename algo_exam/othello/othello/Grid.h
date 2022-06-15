#pragma once

#include <iostream>
#include <string>
#include <vector>

class Grid
{
public:
    Grid();
    void ClearGrid();
    bool PlaceSymbol(char currentSymbol, int index);
    std::pair<bool, char> DidSomeoneWin();
    void DrawGrid();
    void PlaceOpponentBot();
    bool HasCaseToPlay();

    struct Symbols {
    public:
        char m_player = 'B';
        char m_opponent = 'N';
        char m_neutral = ' ';

    };

    Symbols m_symbol;

private:
    std::vector<char> _grid;
    int _numberB = 0;
    int _numberN = 0;

    bool HasWon(char m_symbol);


};