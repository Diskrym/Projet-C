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
             //Variable pour bouger sur map global
            if (lvl->Num == 3 && lvl->NumDonjon == 0 && lvl->WinDonjon == 0)
            {
                lvl->WinDonjon = 1;
            }
            if (lvl->NumDonjon == 0 && lvl->Num == 3)
            {
                lvl->Num = -1;
            }
            else
            {
                lvl->Num += 1;
                SelectNiv(joueur, lvl, monstre, son);
            }
        }
    }
}

void MapGlobal (Joueur *joueur, Lvl *lvl, Monstre *monstre,EffetSon *son, Input *input)
{
    if (lvl->Map != NULL)
    {
        SDL_DestroyTexture(lvl->Map);
        lvl->Map = NULL;
    }
    if  (lvl->Icone !=NULL)
    {
        SDL_DestroyTexture(lvl->Icone);
        lvl->Icone = NULL;
    }
    
    lvl->Map=loadImage("src/graphics/lvl/mapglobal.png");
    //drawImage(lvl->Map,0,0);

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
        lvl->Icone=loadImage("src/graphics/lvl/TeteChevalier.png");
        drawImage(lvl->Icone,313,313);
        if (input->attack == 1)
        {
            lvl->Num = 0;
            SelectNiv(joueur, lvl, monstre, son);
        }
        
    }
    if (lvl->NumDonjon == 1)
    {
        if (lvl->WinDonjon >=1)
        {
            lvl->Icone=loadImage("src/graphics/lvl/TeteChevalier.png");
            drawImage(lvl->Icone,354,253);
            if (input->attack == 1)
            {
                lvl->Num = 4;
                SelectNiv(joueur, lvl, monstre, son);
            }
            
        }
        else
        {
            lvl->NumDonjon -= 1;
        }
    }
    if (lvl->NumDonjon == 2)
    {
        if (lvl->WinDonjon >=2)
        {
            lvl->Icone=loadImage("src/graphics/lvl/TeteChevalier.png");
            drawImage(lvl->Icone,260,195);
        }
        else
        {
            lvl->NumDonjon -= 1;
        }
    }
    if (lvl->NumDonjon == 3)
    {
        if (lvl->WinDonjon >=3)
        {
            lvl->Icone=loadImage("src/graphics/lvl/TeteChevalier.png");
            drawImage(lvl->Icone,228,125);
        }
        else
        {
            lvl->NumDonjon -= 1;
        }
    }
    if (lvl->NumDonjon == 4)
    {
        if (lvl->WinDonjon >=3)
        {
            lvl->Icone=loadImage("src/graphics/lvl/TeteChevalier.png");
            drawImage(lvl->Icone,293,68);
        }
        else
        {
            lvl->NumDonjon -= 1;
        }
    }

    if (lvl->WinDonjon == 0)
    {
        lvl->Cadenas1=loadImage("src/graphics/lvl/Cadenas.png");
        drawImage(lvl->Cadenas1,354,253);

        lvl->Cadenas2=loadImage("src/graphics/lvl/Cadenas.png");
        drawImage(lvl->Cadenas2,260,195);

        lvl->Cadenas3=loadImage("src/graphics/lvl/Cadenas.png");
        drawImage(lvl->Cadenas3,228,125);

        lvl->Cadenas4=loadImage("src/graphics/lvl/Cadenas.png");
        drawImage(lvl->Cadenas4,293,68);
    }

    if (lvl->WinDonjon == 1)
    {

        lvl->Cadenas2=loadImage("src/graphics/lvl/Cadenas.png");
        drawImage(lvl->Cadenas2,260,195);

        lvl->Cadenas3=loadImage("src/graphics/lvl/Cadenas.png");
        drawImage(lvl->Cadenas3,228,125);

        lvl->Cadenas4=loadImage("src/graphics/lvl/Cadenas.png");
        drawImage(lvl->Cadenas4,293,68);
    }
    if (lvl->WinDonjon == 2)
    {
        lvl->Cadenas3=loadImage("src/graphics/lvl/Cadenas.png");
        drawImage(lvl->Cadenas3,228,125);

        lvl->Cadenas4=loadImage("src/graphics/lvl/Cadenas.png");
        drawImage(lvl->Cadenas4,293,68);
    }
    if (lvl->WinDonjon == 3)
    {
        lvl->Cadenas4=loadImage("src/graphics/lvl/Cadenas.png");
        drawImage(lvl->Cadenas4,293,68);
    }
    
}