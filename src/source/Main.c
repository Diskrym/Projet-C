//gcc ./src/source/* -o bin/main2.exe -Dmain=SDL_main -IC:/msys64/mingw64/include -IC:/msys64/mingw64/include/SDL2 -IC:/msys64/mingw64/include -IC:/msys64/mingw64/include/SDL2 -IC:/msys64/mingw64/include/freetype2 -IC:/msys64/mingw64/include/libpng16 -IC:/msys64/mingw64/include -IC:/msys64/mingw64/include/harfbuzz -IC:/msys64/mingw64/include -IC:/msys64/mingw64/include/glib-2.0 -IC:/msys64/mingw64/l-Dmain=SDL_main -IC:/msys64/mingw64/include -IC:/msys64/mingw64/include/SDL2 -IC:/msys64/mingw64/include -IC:/msys64/mingw64/include/SDL2 -IC:/msys64/mingw64/include/freetype2 -IC:/msys64/mingw64/include/libpng16 -IC:/msys64/mingw64/include -IC:/msys64/mingw64/include/harfbuzz -IC:/msys64/mingw64/include -IC:/msys64/mingw64/include/glib-2.0 -IC:/msys64/mingw64/lib/glib-2.0/include -IC:/msys64/mingw64/include -IC:/msys64/mingw64/include/SDL2 -IC:/msys64/mingw64/include -IC:/msys64/mingw64/include/opus -IC:/msys64/mingw64/include -IC:/msys64/mingw64/include/opus -IC:/msys64/mingw64/include -IC:/msys64/mingw64/include/SDL2 -LC:/msys64/mingw64/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lmingw32 -lSDL2main -lSDL2
//.\bin\Main2.exe
/*
Historique version :
    V0 : Lancement projet ✓ 03/10/22
    V0.1 : Map + Joueur + Deplacement ✓ 17/10/22
    V1 : Meduse seul + degat ✓ 21/10//22
    V1.1 : Plusieurs mêmes types de monstre + changement de salle ✓ 23/10/22
    V2 : Donjon 1 + Son ✓ 29/10/22
    V2.1 : Optimisation ressource jeu + gestion coeur/ ✓ 03/11/22
    V3 : Donjon multiple + map 
*/

/*
    !!! INFO !!!
    CoupDague en attente mais pret si double coup sur monstre
    Son attaque chevalier pret mais commenter
    BYPASS A ENLEVER SUR LE MAIN ET DANS INPUT
*/

#include "../header/proto.h"
 
/* Déclaration des variables / structures utilisées par le jeu */
Input input;
Joueur joueur;
Chauvesouris chauvesouris, chauvesouris1;
Meduse meduse, meduse1, meduse2;
Yeti yeti, yeti1, yeti2;
Lvl lvl;
Monstre monstre;
EffetSon son;
Boss boss;
Marchand marchand;
ParamTexte paramtexte;

int main(int argc, char *argv[])
{
//extern void delay(unsigned int frameLimit);
unsigned int frameLimit = SDL_GetTicks() + 16;
int go;
joueur.nbDague=1;
lvl.Num=-1;
joueur.life=3;
joueur.NbPiece=0;
// Initialisation de la SDL
init("Dungeon Fate");
    Son(&son);
    Texte(&paramtexte);
    //Menu
    while(input.enter==0)
    {
    gestionInputs(&input);
    menu(&lvl);
    SDL_RenderPresent(getrenderer());
    }
    // Mix_PauseMusic();
    //atexit(cleanup);
    //LoadNiv11(&monstre.meduse, &lvl, &joueur);
    go = 1; 
    // Boucle infinie, principale, du jeu
    Mix_PlayMusic(son.musiqueMapG, -1 /10);
    while (go == 1)
    {    
        
        //On dessine tout
        drawGame(&joueur, &lvl, &paramtexte);
        GestionMap(&joueur, &lvl, &monstre, &son, &input);
        //Gestion des inputs clavier
        gestionInputs(&input);
        if(lvl.Num != -1)
        {
            //IA monstre
            GestionMonstre(&monstre, &lvl, &input ,&joueur, &son);
            //Gestion des inputs et des déplacements
            deplacement(&input,&joueur,&monstre, &son);
        }

        //Rendu des images dans le buffer
        SDL_RenderPresent(getrenderer());
        //Acquisition des inputs du joueur
        getInput(&input);
        // Gestion des 60 fps (1000ms/60 = 16.6 -> 16
        delay(frameLimit);
        frameLimit = SDL_GetTicks() + 4;
        //Test defaite
        if (joueur.life<=0)
        {   Mix_PauseMusic();
            GameOver (&son);
            exit(0);
        }
        //Test victoire
        // if (meduse.Life<=0)
        // {
        // Win ();
        // exit(0);
        // }

        //#A enlver#
        if (input.Bypass==1)
        {
            SDL_Delay(250);
            lvl.MortMonstre=level[lvl.Num][0][1];
            joueur.inposy=28;
            joueur.inposx=300;
        }
        
    }
    // On quitte
    exit(0); 
}