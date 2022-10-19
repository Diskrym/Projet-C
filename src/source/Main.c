#include "../header/proto.h"
 
/* Déclaration des variables / structures utilisées par le jeu */
Input input;
Pos pos;
Monstre monstre;
Monstre monstre1;

int main(int argc, char *argv[])
{
    
// extern void delay(unsigned int frameLimit);
unsigned int frameLimit = SDL_GetTicks() + 16;
int go;
int lvl=0;
input.Life=6;
 
// Initialisation de la SDL
init("SDL 2");
 
    // Chargement des ressources (graphismes, sons)
    LoadJoueur(&pos);
    if (lvl=0)
    {
    LoadMonstre(&monstre, 64,64);
    }
    
    //  if (lvl=1)
    //  {LoadMonstre(&monstre, 64,64);
    //  LoadMonstre(&monstre1,300,300);}
 
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
        
        //Gestion des inputs et des déplacements
        deplacement(&input,&pos);
        deplacementMonstre(&pos, &monstre);
        //deplacementMonstre(&pos, &monstre1);
        SDL_RenderPresent(getrenderer());
        getInput(&input);
        //collision
        collision(&pos, &monstre, &input);

        
        // Gestion des 60 fps (1000ms/60 = 16.6 -> 16
        delay(frameLimit);
        frameLimit = SDL_GetTicks() + 4;
        if (input.Life<=0)
        {

        exit(0);
        }

    }
 
    // On quitte
    exit(0); 
}