#include "Grid.h"


//Initialisation de l'instance du tableau
Grid::Grid()
{
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
	if (index < 0 || index >= (int)_grid.size())
	{
		std::cout << "Saisie incorrect you're out on the bounds";
		return false;
	}
	if (_grid[index] == m_symbol.m_neutral)
	{
		_grid[index] = currentSymbol;
		_numberN++;
		return true;
	}
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

std::pair<bool, char> Grid::DidSomeoneWin()
{
	if (HasWon(m_symbol.m_player))
	{
		return { true, m_symbol.m_player };
	}

	else if (HasWon(m_symbol.m_opponent))
	{
		return { true, m_symbol.m_opponent };
	}
	else
	{
		return { false, m_symbol.m_neutral };
	}
}

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