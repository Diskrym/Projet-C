#include "../header/proto.h"
 
/* Déclaration des variables / structures utilisées par le jeu */
Input input;
Pos pos;
 
int main(int argc, char *argv[])
{
// extern void delay(unsigned int frameLimit);
unsigned int frameLimit = SDL_GetTicks() + 16;
int go;
 
// Initialisation de la SDL
init("SDL 2");
 
// Chargement des ressources (graphismes, sons)
loadGame(&pos);
 
// Appelle la fonction cleanup à la fin du programme
atexit(cleanup);
 
go = 1;
 
// Boucle infinie, principale, du jeu
while (go == 1)
{
//Gestion des inputs clavier
gestionInputs(&input);

//On dessine tout
drawGame();
SDL_Texture *chevalier=loadImage("src/graphics/epeev31.png");
drawImage(chevalier,SCREEN_WIDTH/2-SPRITE_SIZE/2,SCREEN_HEIGHT/2-SPRITE_SIZE/2);
SDL_RenderPresent(getrenderer());
//Gestion des déplacements joueurs


//mouvement(&input, &pos);
getInput(&input);

// Gestion des 60 fps (1000ms/60 = 16.6 -> 16
delay(frameLimit);
frameLimit = SDL_GetTicks() + 16;
}
 
// On quitte
exit(0);
 
}