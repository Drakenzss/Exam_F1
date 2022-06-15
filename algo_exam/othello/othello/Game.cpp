#include "Game.h"

Game::Game()
{
    grid = new Grid();
}

void Game::Restart()
{
    grid->ClearGrid();
    Start();
}

void Game::PlayerTurn()
{
    std::cout << "c\'est le tour du J1 \n";
    int index;
    do {
        std::cout << "Ou voulez vous jouer ?\n";
        std::cin >> index;
    } while (!grid->PlaceSymbol(grid->m_symbol.m_player, index));
}

void Game::OtherTurn()
{
    std::cout << "c'est le tour du mec à déglinguer, son symbole est" << grid->m_symbol.m_opponent << std::endl;
    grid->PlaceOpponentBot();
}

bool Game::HandleWin()
{
    std::pair<bool, char> winner = grid->DidSomeoneWin();
    if (winner.second == grid->m_symbol.m_player)
    {
        std::cout << "GG MAGGLE\n";
    }
    else if (winner.second == grid->m_symbol.m_opponent)
    {
        std::cout << "T'es une grosse merde dégage de ma plouze";
    }
    return winner.first;
}

void Game::Start()
{
    do {
        PlayerTurn();
        grid->DrawGrid();
        OtherTurn();
        grid->DrawGrid();
        std::cout << std::endl;
        std::cout << "Le tour est fini";
        std::cout << std::endl;
    } while (!HandleWin());
    {
        char c;
        std::cin >> c;
        std::cout << "Do you want restart ?";
        std::cout << "Press y : yes \n";
        std::cout << "Press n : no \n";

        if (c == 'y')
            Restart();
        else if (c == 'n')
            EXIT_SUCCESS;
        else
        {
            std::cout << "Ta mère";
            EXIT_SUCCESS;
        }

    }
}