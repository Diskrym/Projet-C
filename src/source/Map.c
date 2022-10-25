#include "../header/proto.h" 
 
Map map;

 
void initMaps(Lvl *lvl)
{
    // Charge l'image du fond (background)
    if (lvl->Num==0)
    {
        map.background = loadImage("src/graphics/lvl/background.png");
    }
    
}
  
SDL_Texture *getBackground(void)
{
    return map.background;
}
  
void cleanMaps(void)
{
    // Libère la texture du background
    if (map.background != NULL)
    {
        SDL_DestroyTexture(map.background);
        map.background = NULL;
    }
}

void GestionMap(Joueur *joueur, Lvl *lvl, Meduse *meduse, Meduse *meduse1, Meduse *meduse2, Chauvesouris *chauvesouris, Chauvesouris *chauvesouris1)
{  

    if ( joueur->inposy==28 && joueur->inposx >= 298 && joueur->inposx <= 320)
    {
        printf("ok2");
    }
    if (lvl->MortMonstre==level[lvl->Num][0][1] && joueur->inposy<=28 && joueur->inposx >= 298 && joueur->inposx <= 320)
        {   printf("boucle");
            lvl->Num+=1;
            SelectNiv(joueur, lvl, meduse, meduse1, meduse2, chauvesouris, chauvesouris1);
        }
}