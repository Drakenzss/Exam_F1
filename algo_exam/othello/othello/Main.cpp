#include "Defs.h"
#include "Game.h"
#include "prot.h"


int main()
{
    clock_t start, end;
    srand(time(NULL));
    //Permet de lancer l'instance du jeu
    Game game = Game();
    Menu();
}