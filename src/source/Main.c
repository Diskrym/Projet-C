//gcc ./src/source/* -o bin/Dungeon_Fate.exe -Dmain=SDL_main -IC:/msys64/mingw64/include -IC:/msys64/mingw64/include/SDL2 -IC:/msys64/mingw64/include -IC:/msys64/mingw64/include/SDL2 -IC:/msys64/mingw64/include/freetype2 -IC:/msys64/mingw64/include/libpng16 -IC:/msys64/mingw64/include -IC:/msys64/mingw64/include/harfbuzz -IC:/msys64/mingw64/include -IC:/msys64/mingw64/include/glib-2.0 -IC:/msys64/mingw64/l-Dmain=SDL_main -IC:/msys64/mingw64/include -IC:/msys64/mingw64/include/SDL2 -IC:/msys64/mingw64/include -IC:/msys64/mingw64/include/SDL2 -IC:/msys64/mingw64/include/freetype2 -IC:/msys64/mingw64/include/libpng16 -IC:/msys64/mingw64/include -IC:/msys64/mingw64/include/harfbuzz -IC:/msys64/mingw64/include -IC:/msys64/mingw64/include/glib-2.0 -IC:/msys64/mingw64/lib/glib-2.0/include -IC:/msys64/mingw64/include -IC:/msys64/mingw64/include/SDL2 -IC:/msys64/mingw64/include -IC:/msys64/mingw64/include/opus -IC:/msys64/mingw64/include -IC:/msys64/mingw64/include/opus -IC:/msys64/mingw64/include -IC:/msys64/mingw64/include/SDL2 -LC:/msys64/mingw64/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lmingw32 -lSDL2main -lSDL2
//.\bin\Dungeon_Fate.exe
/*
Historique version :
    V0 : Lancement projet ✓ 03/10/22
        V0.1 : Map + Joueur + Deplacement ✓ 17/10/22
    V1 : Meduse seul + degat ✓ 21/10//22
        V1.1 : Plusieurs mêmes types de monstre + changement de salle ✓ 23/10/22
    V2 : Donjon 1 + Son ✓ 29/10/22
        V2.1 : Optimisation ressource jeu + gestion coeur/ ✓ 03/11/22
    V3 : Donjon multiple + map 
    V4 : Niveaux spéciaux
        V4.1 : Marchand
        V4.2 : Rivière
        V4.3 : Menu, sauvegarde, score, stats
    V5 : Boss final/Victoire/Crédits
*/

/*
    !!! INFO !!!
    CoupDague en attente mais pret si double coup sur monstre
    Son attaque chevalier pret mais commenter
    BYPASS A ENLEVER SUR LE MAIN ET DANS INPUT
    Finir donjon bleu, lvl deja prep dans struct + faire retour map global a la fin du donjon bleu.
*/

#include "../header/proto.h"
 
/* Déclaration des variables / structures utilisées par le jeu */
Input input;
Joueur joueur;
Chauvesouris chauvesouris, chauvesouris1;
Meduse meduse, meduse1, meduse2;
Yeti yeti, yeti1, yeti2;
BossYeti bossyeti;
Lvl lvl;
Entité entité;
EffetSon son;
Boss boss;
Marchand marchand;
ParamTexte paramtexte;
Obstacle Petit_rocher,Gros_rocher, tronc, tanguy;
Stats stats;
clock_t temps;
Squelette squelette, squelette1, squelette2;
Jerem_Boss jerem;


int main(int argc, char *argv[])
{
//extern void delay(unsigned int frameLimit);
unsigned int frameLimit = SDL_GetTicks() + 16;
int go;
lvl.Num=-1;
lvl.Load=0;
// Initialisation de la SDL
init("Dungeon Fate");
    //init son
    Son(&son);
    //init texte
    Texte(&paramtexte);
    //Menu
    while(input.enter==0)
    {
        
    //gestionInputs(&input);
    Draw_Menu(&lvl);
    Get_Input(&input);
    //Affiche tout ce qui a été chargé
    SDL_RenderPresent(getrenderer());
    }
    go = 1; 
    Mix_PlayMusic(son.musiqueMapG, -1 /10);
    // Boucle infinie, principale, du jeu
    while (go == 1)
    {    
        if (lvl.Load == 0)
        {
            Load_Game(&joueur,&lvl,&stats);
            lvl.Load=1;
        }
        //On dessine tout
        if (joueur.life<=0)
        {   
            Mix_PauseMusic();
            Game_Over (&son);
            lvl.Num = -1;
            lvl.reset=1;
            lvl.save = 1;
        }
        if (lvl.WinDonjon == 5)
        {
            Score_(&stats,temps);
            lvl.WinDonjon = 6 ;
        }
        temps=clock()-stats.Diff_reset;


        Statistiques(&stats,&joueur,&lvl);

        Save(&joueur,&lvl,&input,&entité,&son,&stats,temps);
        
        Draw_Game(&joueur, &lvl, &paramtexte,&son);
                                
        Gestion_Map(&joueur, &lvl, &entité, &son, &input, &stats, &paramtexte);

        //Gestion des inputs clavier
        //gestionInputs(&input);
        Get_Input(&input);
        

        if(lvl.Num != -1 && lvl.Num != -2 && lvl.Num != -3 && lvl.Num != -4 && lvl.Num != -5)
        {
            //IA monstre
            Gestion_Entité(&entité, &lvl, &input ,&joueur, &son);
            //Gestion des inputs et des déplacements
                Deplacement_Chevalier(&input,&joueur,&entité, &son, &lvl);
        }

        //Rendu des images dans le buffer
        SDL_RenderPresent(getrenderer());
        // Gestion des 60 fps (1000ms/60 = 16.6 -> 16
        delay(frameLimit);
        frameLimit = SDL_GetTicks() + 4;

        //#A enlver#
        if (input.Bypass==1)
        {
            SDL_Delay(250);

            
                lvl.MortMonstre=level[lvl.Num][0][1];
                joueur.inposy=28;
                joueur.inposx=300;
                if (lvl.Num == 10)
                {
                    lvl.Avancement10 = 13;
                }
                
           
        }
        
    }
    // On quitte
    exit(0); 
}