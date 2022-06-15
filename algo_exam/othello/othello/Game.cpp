#include "Game.h"

//Instance du jeu
Game::Game()
{
    grid = new Grid(); //Permet de créer une nouvelle instance de Grid (en gros ca va créer un nouveau tableau à chaque début de partie)
}

//Relance le jeu
void Game::Restart()
{
    grid->ClearGrid();
    Start();
}

//Gère le tour du joueur
void Game::PlayerTurn()
{
    std::cout << "c'est le tour du J1 \n";
    int index;
    do {
        std::cout << "Ou voulez vous jouer ?\n";
        std::cin >> index;
    } while (!grid->PlaceSymbol(grid->m_symbol.m_player, index));
}

//Joue le tour d'un autre joueur
void Game::OtherTurn()
{
    std::cout << "c'est le tour du mec à déglinguer, son symbole est" << grid->m_symbol.m_opponent << std::endl;
    grid->PlaceOpponentBot();
}

//Gestionnaire de victoire
bool Game::HandleWin()
{
    //permet de récupérer la fonction DidSomeoneWin()
    std::pair<bool, char> winner = grid->DidSomeoneWin();
    //second permet de récupérer le 2ème type de valeur (char en l'occurence)
    if (winner.second == grid->m_symbol.m_player)
    {
        std::cout << "GG MAGGLE\n";
    }
    else if (winner.second == grid->m_symbol.m_opponent)
    {
        std::cout << "T'es une grosse merde dégage de ma plouze";
    }
    //first permet de récupérer le 1er type de valeur (bool en l'occurence)
    return winner.first;
}

//permet de débuter le jeu en "tour par tour"
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