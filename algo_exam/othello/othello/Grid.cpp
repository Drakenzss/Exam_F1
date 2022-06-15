#include "Grid.h"




//Initialisation de l'instance du tableau
Grid::Grid()
{
	//push_back permet d'ajouter un élément dans le tableau (vector)
	for (int i = 0; i < 64; i++)
		_grid.push_back(m_symbol.m_neutral);
}

//Quand la partie se termine on nettoie tous ce qu'il ya dans le tableau
void Grid::ClearGrid()
{
	for (int i = 0; i < (int)_grid.size(); i++)
		_grid[i] = m_symbol.m_neutral;
}


//Check si il ya encore des case à jouer dans le tableau
bool Grid::HasCaseToPlay()
{
	for (int i = 0; i < _grid.size(); i++)
	{
		if (_grid[i] == m_symbol.m_neutral)
			return true;
	}
}

//Permet de placer le symbole du joueur
bool Grid::PlaceSymbol(char currentSymbol, int index)
{
	//Permet que aucun des deux joueurs puissent mettre de pion out of range
	if (index < 0 || index >= (int)_grid.size())
	{
		std::cout << "Saisie incorrect you're out on the bounds"; // = printf en console
		return false;
	}
	// Aajouter le symbole du joueur
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

//Placer le sybole de l'ordinateur
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

//Sert à check si l'un des deux joueurs à gagner std::pair est une fonction qui return 2 types de valeur
std::pair<bool, char> Grid::DidSomeoneWin()
{
	//Le joueur à gagner
	if (HasWon(m_symbol.m_player))
	{
		return { true, m_symbol.m_player };
	}
	//L'adversaire à gagner (fdp)
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

//Condition de victoire
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

		std::cout << "Ta mère";
		return false;


	}
}

//Pemet de dessiner le tableau
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