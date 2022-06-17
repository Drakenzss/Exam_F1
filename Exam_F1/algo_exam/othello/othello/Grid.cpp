#include "Grid.h"




/***********************************************************
* BUT : lancer l'instance de jeu
* 
* ENTREE : /
* 
* SORTIE : /
* 
* DESCRIPTION : Sert à initialisé l'instance du tableau
***********************************************************/
Grid::Grid()
{
	// push_back permet d'ajouter un élément dans le tableau (vector)
	for (int i = 0; i < 64; i++) // On boucle sur 64 car il y à 64 cases sur le plateau 
		_grid.push_back(m_symbol.m_neutral);
}

/************************************************************************
* BUT : Nettoie le plateau
* 
* ENTREE : /
* 
* SORTIE : /
* 
* DESCRIPTION : Quand la partie est fini, on nettoie tout le tableau
************************************************************************/
void Grid::ClearGrid()
{
	for (int i = 0; i < (int)_grid.size(); i++)
		_grid[i] = m_symbol.m_neutral;
}

/**************************************************************************
* BUT : Check si on peut encore jouer
* 
* ENTREE : /
* 
* SORTIE : /
* 
* DESCRIPTION : On check si il y à encore des cases ou l'on peut jouer
**************************************************************************/
bool Grid::HasCaseToPlay()
{
	for (int i = 0; i < _grid.size(); i++)
	{
		if (_grid[i] == m_symbol.m_neutral)
			return true;
	}
}

/**********************************************************************
* BUT : Placer les symbôles
*
* ENTREE : /
*
* SORTIE : /
*
* DESCRIPTION : Permet de placer le symbôle ( pion ) du joueur
**********************************************************************/
bool Grid::PlaceSymbol(char currentSymbol, int index)
{
	//Permet que aucun des deux joueurs puissent mettre de pion en dehors du tableau
	if (index < 0 || index >= (int)_grid.size())
	{
		std::cout << "Saisie incorrect. Veuilliez recommencer !"; // = printf en console
		return false;
	}
	// Ajouter le symbole du joueur
	if (_grid[index] == m_symbol.m_neutral)
	{
		_grid[index] = currentSymbol;
		_numberN++;
		return true;
	}
	//La case est déjà prise par l'autre joueur
	else
	{
		std::cout << "Cette case est deja prise";
		return false;
	}
}

/**********************************************************************
* BUT : L'ordi place un symbôle
*
* ENTREE : /
*
* SORTIE : /
*
* DESCRIPTION : L'ordi place un symbole sur le plateau
**********************************************************************/
void Grid::PlaceOpponentBot()
{
	if (!HasCaseToPlay())
		return;

	int randIndex;
	do
	{
		randIndex = rand() % 64;
	} while (_grid[randIndex] != m_symbol.m_neutral);
	{
		_grid[randIndex] = m_symbol.m_opponent;
		_numberN++;
	}
}

/**********************************************************************
* BUT : Check si un joueur à gagner
*
* ENTREE : /
*
* SORTIE : /
*
* DESCRIPTION : Sert à check si un joueur à gagner la partie
**********************************************************************/
//std::pair est une fonction qui return 2 types de valeur
std::pair<bool, char> Grid::DidSomeoneWin()
{
	//Le joueur à gagner
	if (HasWon(m_symbol.m_player))
	{
		return { true, m_symbol.m_player };
	}
	//L'adversaire à gagner
	else if (HasWon(m_symbol.m_opponent))
	{
		return { true, m_symbol.m_opponent };
	}
	//Personne n'a gagner
	else
	{
		return { false, m_symbol.m_neutral };
	}
}

/**********************************************************************
* BUT : Afficher la victoire
*
* ENTREE : /
*
* SORTIE : ON sait qui à gagner
*
* DESCRIPTION : Condition de victoire et affichage à l'écran
**********************************************************************/
bool Grid::HasWon(char currentSymbol)
{

	for (int i = 0; i < (int)_grid.size(); i++)
	{
		if (_numberB > _numberN && _grid[i] == currentSymbol)
		{
			std::cout << "Les Blancs ont gagné";
			return true;
		}

		else if (_numberN > _numberB && _grid[i] == currentSymbol)
		{
			std::cout << "Les Noirs ont gagné";
			return true;
		}

		std::cout << "Personne ne gagne";
		return false;


	}
}

/**********************************************************************
* BUT : Dessiner le tableau
*
* ENTREE : /
*
* SORTIE : /
*
* DESCRIPTION : Permet de dessiner le tableau 
**********************************************************************/
void Grid::DrawGrid()
{
	std::cout << std::endl;
	for (int i = 0; i < (int)_grid.size(); i++)
	{
		if (i % 8 == 0 && i != 0)
		{
			std::cout << "\n---------\n";
		}
		if (i % 8 == 1)
		{
			std::cout << "|" << _grid[i] << "|";
		}
		else
		{
			std::cout << _grid[i];
		}
	}

	std::cout << std::endl;
}