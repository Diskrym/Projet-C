#include "../header/proto.h" 
 
 
void initMaps(Lvl *lvl)
{
    // Charge l'image du fond (background)
    if (lvl->Num==0 || lvl->Num==1 || lvl->Num==2)
    {
        lvl->Map = loadImage("src/graphics/lvl/background.png");
    }
    if (lvl ->Num==3)
    {
        lvl->Map = loadImage("src/graphics/lvl/mapboss.png");
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