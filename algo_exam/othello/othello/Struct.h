#pragma once



// Include.h
#include "defs.h"



// Structure
typedef struct Pion
{
	char* blanc;
	char* noir;
}Pion;

typedef struct jeu
{
	char* plateau[8][8];
	int nbPion[2];
}jeu;

enum joueur
{
	joueur1,
	joueur2
};