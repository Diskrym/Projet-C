#include "../header/proto.h" 
 
Map map;

 
void initMaps(Lvl *lvl)
{
    // Charge l'image du fond (background)
    if (lvl->Num==0 || lvl->Num==1 || lvl->Num==2)
    {
        map.background = loadImage("src/graphics/lvl/background.png");
    }
    if (lvl ->Num==3)
    {
        map.background = loadImage("src/graphics/lvl/mapboss.png");
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

void GestionMap(Joueur *joueur, Lvl *lvl, Monstre *monstre,EffetSon *son)
{  
    if (lvl->MortMonstre==level[lvl->Num][0][1] && joueur->inposy<=28 && joueur->inposx >= 298 && joueur->inposx <= 320)
        {   
            lvl->Num+=1;
            SelectNiv(joueur, lvl, monstre, son);
        }
}