#include <stdio.h>
#include <iostream>
#include "Game.h"


// Include struct 

void Menu()
{
	int menu = 0;
	int goMenu = 0;
	char c = 's';

	printf_s(" _____________________________________________________________________\n");
	printf_s("|    _____   _______              ____                       _____    |\n");
	printf_s("|   |     |     |     |      |   |        |        |        |     |   |\n");
	printf_s("|   |     |     |     |______|   |        |        |        |     |   |\n");
	printf_s("|   |     |     |     |      |   |____    |        |        |     |   |\n");
	printf_s("|   |     |     |     |      |   |        |        |        |     |   |\n");
	printf_s("|   |_____|     |     |      |   |____    |_____   |_____   |_____|   |\n");
	printf_s("|_____________________________________________________________________|\n");

	printf_s("Nous voici dans le jeu l'othello, appuyez sur s pour passer a la suite\n");

	std::cin >> c;
	fflush(stdin);
	system("cls");
	printf_s("Regle du jeu :\n");
	printf_s("\n");
	printf_s(" Votre but va etre d'avoir le plus de territoire de votre couleur sur le plateau, la partie se termine quand plus aucun joueur ne peut poser de pion\n");
	std::cin >> c;
	fflush(stdin);
	system("cls");
	printf_s("Selectionnez votre mode de jeu\n");

	printf_s(" 0: Affronter un ami\n");
	printf_s(" 1: Affronter l'ordinateur\n");
	printf_s(" 2: Quittez\n");
	std::cin >> goMenu;

	switch (goMenu)
	{
		case 0: printf_s(" 0: Affronter un ami"); break;
		case 1: 
			printf_s(" 1: Affronter l'ordinateur");
			//lancementjeu();
			break;
		case 2: 
			printf_s(" 2: Quittez");
			exit(0);
			break;
		default:
			printf("Erreur !"); break;
	}
}
