//gcc ./src/source/* -o bin/main2.exe -Dmain=SDL_main -IC:/msys64/mingw64/include -IC:/msys64/mingw64/include/SDL2 -IC:/msys64/mingw64/include -IC:/msys64/mingw64/include/SDL2 -IC:/msys64/mingw64/include/freetype2 -IC:/msys64/mingw64/include/libpng16 -IC:/msys64/mingw64/include -IC:/msys64/mingw64/include/harfbuzz -IC:/msys64/mingw64/include -IC:/msys64/mingw64/include/glib-2.0 -IC:/msys64/mingw64/l-Dmain=SDL_main -IC:/msys64/mingw64/include -IC:/msys64/mingw64/include/SDL2 -IC:/msys64/mingw64/include -IC:/msys64/mingw64/include/SDL2 -IC:/msys64/mingw64/include/freetype2 -IC:/msys64/mingw64/include/libpng16 -IC:/msys64/mingw64/include -IC:/msys64/mingw64/include/harfbuzz -IC:/msys64/mingw64/include -IC:/msys64/mingw64/include/glib-2.0 -IC:/msys64/mingw64/lib/glib-2.0/include -IC:/msys64/mingw64/include -IC:/msys64/mingw64/include/SDL2 -IC:/msys64/mingw64/include -IC:/msys64/mingw64/include/opus -IC:/msys64/mingw64/include -IC:/msys64/mingw64/include/opus -IC:/msys64/mingw64/include -IC:/msys64/mingw64/include/SDL2 -LC:/msys64/mingw64/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lmingw32 -lSDL2main -lSDL2
//.\bin\Main2.exe
/*
Historique version :
    V1 : Map + Joueur + Deplacement
    V2 : Meduse seul + degat
    V3 : Plusieurs mêmes types de monstre + changement de salle
    V4 : Donjon 1 + Son
    V5 : Optimisation ressource jeu
*/

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