#include "../header/proto.h"
 
/* Déclaration des variables / structures utilisées par le jeu */
Input input;
Pos pos;
 
int main(int argc, char *argv[])
{
// extern void delay(unsigned int frameLimit);
unsigned int frameLimit = SDL_GetTicks() + 16;
int go;
int NumSprite=0;
 
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
if (NumSprite==0 )
{SDL_Texture *chevalier=loadImage("src/graphics/neutre.png");
drawImage(chevalier,pos.inposx,pos.inposy);}
if (NumSprite==1 )
{SDL_Texture *chevalier=loadImage("src/graphics/marche1.png");
drawImage(chevalier,pos.inposx,pos.inposy);}
if (NumSprite==2 )
{SDL_Texture *chevalier=loadImage("src/graphics/neutre.png");
drawImage(chevalier,pos.inposx,pos.inposy);}
if (NumSprite==3 )
{SDL_Texture *chevalier=loadImage("src/graphics/marche2.png");
drawImage(chevalier,pos.inposx,pos.inposy);
NumSprite=0;}



SDL_RenderPresent(getrenderer());
//Gestion des déplacements joueurs
if (input.left==1)
{
    pos.inposx-=5;
    NumSprite+=1;
}
if (input.right==1)
{
    pos.inposx+=5;
    NumSprite+=1;
}
if (input.up==1)
{
    pos.inposy-=5;
    NumSprite+=1;
}
if (input.down==1)
{
    pos.inposy+=5;
    NumSprite+=1;
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