//gcc ./src/source/* -o bin/main2.exe -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
//.\bin\Main2.exe

#include "../header/proto.h"
 
/* Déclaration des variables / structures utilisées par le jeu */
Input input;
Joueur joueur;
Meduse meduse;
Meduse meduse1;
Lvl lvl;

int main(int argc, char *argv[])
{
    
// extern void delay(unsigned int frameLimit);
unsigned int frameLimit = SDL_GetTicks() + 16;
int go;
lvl.Num=1;
joueur.life=3;
meduse.Life=3;
 
// Initialisation de la SDL
init("SDL 2");
 
    // Chargement des ressources (graphismes, sons)
    LoadJoueur(&joueur);
    if (lvl.Num==1)
    {
    LoadMonstre(&meduse, 70,70);
    //LoadMonstre(&meduse1,300,300);
    }
    
    
     
 
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
        deplacement(&input,&joueur);

        deplacementMeduse(&joueur, &meduse);
        //deplacementMeduse(&joueur, &meduse1);
        SDL_RenderPresent(getrenderer());
        getInput(&input);
        //collision
        collision(&joueur, &meduse, &input);
        //collision(&joueur, &meduse1, &input);

        
        // Gestion des 60 fps (1000ms/60 = 16.6 -> 16
        delay(frameLimit);
        frameLimit = SDL_GetTicks() + 4;
        if (joueur.life<=0)
        {
        GameOver ();
        exit(0);
        }
        if (meduse.Life<=0)
        {
        Win ();
        exit(0);
        }

    }
 
    // On quitte
    exit(0); 
}