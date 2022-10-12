
#include "../header/proto.h"
 
/* Déclaration des variables / structures utilisées par le jeu */
Input input;
 
 
int main(int argc, char *argv[])
{
unsigned int frameLimit = SDL_GetTicks() + 16;
int go;
 
// Nom
init("SDL 2");
 
// Load game dans init soit la selection du niveau + creation de la fenetre
loadGame();
 
// Clean de la mémoire a la fin du programme + go = 1 pour fermer la boucle while et finir
atexit(cleanup);
 
go = 1;
 
// Boucle infinie, principale, du jeu
while (go == 1)
{
//input clavier
gestionInputs(&input);
 
//init de tous les tiles
drawGame();
 
// init fps a 60 fps (1000ms/60 = 16.6 -> 16
delay(frameLimit);
frameLimit = SDL_GetTicks() + 16;
}
 
// fin
exit(0);
 
}