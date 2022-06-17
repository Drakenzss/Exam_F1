
#include "Defs.h"
#include "Game.h"
#include "prot.h"


// Include struct
Game game;

/***********************************************************************
* BUT : Afficher un menu
* 
* ENTREE :/
* 
* SORTIE : On lance le jeu ou on quitte le programme
* 
* DESCRIPTION : Le menu du jeu s'affiche ainsi que le règle du jeu.
* L'utilisateur choisi ensuite ce qu'il veut faire
************************************************************************/
void Menu()
{
	int menu = 0;
	int goMenu = 0;
	char c = 's';

	std::cout << " _____________________________________________________________________\n";
	std::cout << "|    _____   _______              ____                       _____    |\n";
	std::cout << "|   |     |     |     |      |   |        |        |        |     |   |\n";
	std::cout << "|   |     |     |     |______|   |        |        |        |     |   |\n";
	std::cout << "|   |     |     |     |      |   |____    |        |        |     |   |\n";
	std::cout << "|   |     |     |     |      |   |        |        |        |     |   |\n";
	std::cout << "|   |_____|     |     |      |   |____    |_____   |_____   |_____|   |\n";
	std::cout << "|_____________________________________________________________________|\n";

	std::cout << "Nous voici dans le jeu l'othello, appuyez sur s pour passer a la suite\n";

	std::cin >> c;
	fflush(stdin);
	system("cls");
	std::cout << "Regle du jeu :\n";
	std::cout << "\n";
	std::cout << " Votre but va etre d'avoir le plus de territoire de votre couleur sur le plateau, la partie se termine quand plus aucun joueur ne peut poser de pion\n";
	std::cin >> c;
	fflush(stdin);
	system("cls");
	std::cout << "Selectionnez votre mode de jeu\n";

	std::cout << " 0: Affronter un ami\n";
	std::cout << " 1: Affronter l'ordinateur\n";
	std::cout << " 2: Quittez\n";
	std::cin >> goMenu;

	switch (goMenu)
	{
	case 0: 
		std::cout << " 0: Affronter un ami\n";
		std::cout << "Cette partie est en construction";
		break;
	case 1: 
		std::cout << " 1: Affronter l'ordinateur\n";
		game.ChoiceName();
		game.Start();
		break;
	case 2:
		std::cout << (" 2: Quittez");
		EXIT_SUCCESS;
		break;
	default:
		printf("Erreur !"); break;
	}
}

void Game::ChoiceName()
{
	char c = ' ';
	std::cout << "saisir la première lettre de votre prénom \n";
	std::cin >> c;
	std::cout << "c'est le tour de\n", c;
}