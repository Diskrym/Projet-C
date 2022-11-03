//gcc ./src/source/* -o bin/main2.exe -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
//.\bin\Main2.exe

#include "../header/proto.h"
 
/* Déclaration des variables / structures utilisées par le jeu */
Input input;
Joueur joueur;
Chauvesouris chauvesouris, chauvesouris1;
Meduse meduse, meduse1, meduse2;
Lvl lvl;
Monstre monstre;
EffetSon son;
Boss boss;
//Meduse nv1__tab_meduse[3];

int main(int argc, char *argv[])
{

// extern void delay(unsigned int frameLimit);
unsigned int frameLimit = SDL_GetTicks() + 16;
int go;

lvl.Num=0;
joueur.life=3;
//meduse1.Life=3;
 
// Initialisation de la SDL
init("Dungeon Fate");
 
    
    //LoadMonstre(&meduse1, &lvl, &joueur);
    
    Son(&son);
    
    
    while(input.enter==0)
    {
    gestionInputs(&input);
    menu(&lvl);
    SDL_RenderPresent(getrenderer());
    
    }
    Mix_PauseMusic();
    // Appelle la fonction cleanup à la fin du programme
    //atexit(cleanup);
    // Chargement des ressources (graphismes, sons)
    LoadNiv1(&monstre.meduse, &lvl, &joueur);

    go = 1; 
    // Boucle infinie, principale, du jeu
    while (go == 1)
    {    
        
        GestionMap(&joueur, &lvl, &monstre, &son);
        //Gestion des inputs clavier
        gestionInputs(&input);
        //On dessine tout
        drawGame(&joueur, &lvl);
        //IA monstre
        GestionMonstre(&monstre, &lvl, &input ,&joueur, &son);
        
        //meduse 2
        //Gestion des inputs et des déplacements
        deplacement(&input,&joueur,&monstre, &son);

        //deplacementMeduse(&joueur, &meduse1);
        //Rendu des images dans le buffer
        SDL_RenderPresent(getrenderer());
        //Acquisition des inputs du joueur
        getInput(&input);
        //collision

        

        
        // Gestion des 60 fps (1000ms/60 = 16.6 -> 16
        delay(frameLimit);
        frameLimit = SDL_GetTicks() + 4;
        //Test defaite
        if (joueur.life<=0)
        {
            GameOver (&son);
            exit(0);
        }
        //Test victoire
        // if (meduse.Life<=0)
        // {
        // Win ();
        // exit(0);
        // }

    }
 
    // On quitte
    exit(0); 
}