#include "../header/proto.h" 
 
 
void initMaps(Lvl *lvl)
{
    // Charge l'image du fond (background)
    if (lvl->Num == 0 || lvl->Num == 1 || lvl->Num == 2)
    {
        lvl->Map = loadImage("src/graphics/lvl/background.png");
    }
    if (lvl ->Num == 3)
    {
        lvl->Map = loadImage("src/graphics/lvl/mapboss.png");
    }
}
  


void GestionMap(Joueur *joueur, Lvl *lvl, Monstre *monstre,EffetSon *son, Input *input)
{  
    if (lvl->Num == -1)
    {
        MapGlobal(joueur, lvl, monstre, son, input);
    }
    else
    {
        if (lvl->MortMonstre == level[lvl->Num][0][1] && joueur->inposy <= 28 && joueur->inposx >= 298 && joueur->inposx <= 320)
        {   
            lvl->Num += 1;
            SelectNiv(joueur, lvl, monstre, son);
        }
    }
}

void MapGlobal (Joueur *joueur, Lvl *lvl, Monstre *monstre,EffetSon *son, Input *input)
{
    if (lvl->MapGlobal != NULL)
    {
        SDL_DestroyTexture(lvl->MapGlobal);
        lvl->MapGlobal = NULL;
    }
    if  (lvl->Icone !=NULL)
    {
        SDL_DestroyTexture(lvl->Icone);
        lvl->Icone = NULL;
    }
    
    lvl->MapGlobal=loadImage("src/graphics/lvl/mapglobal.png");
    drawImage(lvl->MapGlobal,0,0);

    if (input->up == 1 && lvl->NumDonjon < 4)
    {
        SDL_Delay(200);
        lvl->NumDonjon +=1;
    }
    if (input->down == 1 && lvl->NumDonjon > 0)
    {
        SDL_Delay(200);
        lvl->NumDonjon -= 1;
    }
    
    if (lvl->NumDonjon == 0)
    {
        lvl->Icone=loadImage("src/graphics/lvl/5.png");
        drawImage(lvl->Icone,313,313);
        if (input->attack == 1)
        {
            lvl->Num = 0;
            SelectNiv(joueur, lvl, monstre, son);
        }
        
    }
    if (lvl->NumDonjon == 1)
    {
        lvl->Icone=loadImage("src/graphics/lvl/5.png");
        drawImage(lvl->Icone,354,253);
    }
    if (lvl->NumDonjon == 2)
    {
        lvl->Icone=loadImage("src/graphics/lvl/5.png");
        drawImage(lvl->Icone,260,195);
    }
    if (lvl->NumDonjon == 3)
    {
        lvl->Icone=loadImage("src/graphics/lvl/5.png");
        drawImage(lvl->Icone,228,125);
    }
    if (lvl->NumDonjon == 4)
    {
        lvl->Icone=loadImage("src/graphics/lvl/5.png");
        drawImage(lvl->Icone,293,68);
    }
}