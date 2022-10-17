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
drawImage(chevalier,pos.inposx,pos.inposy);
SDL_RenderPresent(getrenderer());
//Gestion des déplacements joueurs
if (input.left==1)
{
    pos.inposx-=5;
}
if (input.right==1)
{
    pos.inposx+=5;
}
if (input.up==1)
{
    pos.inposy-=5;
}
if (input.down==1)
{
    pos.inposy+=5;
}

//mouvement(&input, &pos);
getInput(&input);

// Gestion des 60 fps (1000ms/60 = 16.6 -> 16
delay(frameLimit);
frameLimit = SDL_GetTicks() + 16;
}
 
// On quitte
exit(0);
 
}