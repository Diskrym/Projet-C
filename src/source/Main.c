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
init("JELOMA²");
 
    // Chargement des ressources (graphismes, sons)
    LoadNiv1(&monstre.meduse, &lvl, &joueur);
    //LoadMonstre(&meduse1, &lvl, &joueur);
    
    Son(&son);
    
     
 
    // Appelle la fonction cleanup à la fin du programme
    //atexit(cleanup);
 
    go = 1; 
    // Boucle infinie, principale, du jeu
    while (go == 1)
    {    
        
        GestionMap(&joueur, &lvl, &monstre);
        //Gestion des inputs clavier
        gestionInputs(&input);
        //On dessine tout
        drawGame(&joueur, &lvl);
        //IA monstre
        
        
        //deplacementChauvesouris(&joueur, &chauvesouris, &meduse);
        
        GestionMonstre(&monstre, &lvl, &input ,&joueur);
        
        //meduse 2
        //deplacementMeduse(&joueur, &meduse1);
        //collision(&joueur, &meduse1, &input);

        //Gestion des inputs et des déplacements
        deplacement(&input,&joueur,&meduse, &chauvesouris, &son);

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
            GameOver ();
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