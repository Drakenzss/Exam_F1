#include "Game.h"


/*********************************************************
* BUT : Lancer l'instance de jeu
* 
* ENTREE : /
* 
* SORTIE : /
* 
* DESCRIPTION : Sert à initialisé l'instance du jeu
*********************************************************/
Game::Game()
{
    grid = new Grid(); //Permet de créer une nouvelle instance de Grid (en gros ca va créer un nouveau tableau à chaque début de partie)
}

/*********************************************************
* BUT : Relancer le jeu
*
* ENTREE :/
*
* SORTIE : /
*
* DESCRIPTION : Permet de relancer le jeu
*********************************************************/
void Game::Restart()
{
    grid->ClearGrid();
    Start();
}

/*********************************************************
* BUT : Tour joueur
*
* ENTREE : /
*
* SORTIE : /
*
* DESCRIPTION : Permet de définir le tour du j1
*********************************************************/
void Game::PlayerTurn()
{
    std::cout << "c'est le tour de  \n";
    int index;
    do {
        std::cout << "Ou voulez vous jouer ?\n";
        std::cin >> index;
    } while (!grid->PlaceSymbol(grid->m_symbol.m_player, index));
}

/**************************************************************
* BUT : Tour joueur
*
* ENTREE : /
*
* SORTIE : /
*
* DESCRIPTION : Permet de définir le tour du joueur adverse
**************************************************************/
void Game::OtherTurn()
{
    std::cout << "c'est le tour du joueur 2, son symbole est" << grid->m_symbol.m_opponent << std::endl;
    grid->PlaceOpponentBot();
}

/******************************************************************
* BUT : Victoire
*
* ENTREE : /
*
* SORTIE : /
*
* DESCRIPTION : Permet d'afficher si vous avez gagner ou non
******************************************************************/
bool Game::HandleWin()
{
    //permet de récupérer la fonction DidSomeoneWin()
    std::pair<bool, char> winner = grid->DidSomeoneWin();

    //second permet de récupérer le 2ème type de valeur (char en l'occurence)
    if (winner.second == grid->m_symbol.m_player)
    {
        std::cout << "Bravo, vous avez gagner !\n";
    }
    else if (winner.second == grid->m_symbol.m_opponent)
    {
        std::cout << "Vous avez perdu, dommage !";
    }

    //first permet de récupérer le 1er type de valeur (bool en l'occurence)
    return winner.first;
}

/***************************************************************
* BUT : Faire le tour par tour
*
* ENTREE : /
*
* SORTIE : /
*
* DESCRIPTION : Permet de débuter le jeu en tour par tour
***************************************************************/
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
        std::cout << "Voulez-vous recommencer ?";
        std::cout << "Saisir o : oui \n";
        std::cout << "Saisir n : non \n";

        if (c == 'o')
            Restart();
        else if (c == 'n')
            EXIT_SUCCESS;
        else
        {
            std::cout << "Veuilliez choisir";
            EXIT_SUCCESS;
        }

    }
}

void OnCheck()
{

}