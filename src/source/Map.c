#include "../header/proto.h" 
 
 
void Init_Maps(Lvl *lvl)
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
    if (lvl-> Num == 4)
    {
        lvl->Map = loadImage("src/graphics/lvl/backgroundmarchand.png");
    }
    if  (lvl->Num == 5 || lvl->Num == 6 || lvl->Num ==7)
    {
        lvl->Map = loadImage("src/graphics/lvl/backgroundDonjon2.png");
    }
    if (lvl->Num == 9)
    {
        lvl->Map = loadImage("src/graphics/Rivière/PontonDépart.png");
    }
    if (lvl->Num == 10)
    {
       lvl->Map = lvl->MapSlide = loadImage("src/graphics/Rivière/Riviere.png");
    }
    if (lvl->Num == 11 || lvl->Num == 12 )
    {
        lvl->Map = loadImage("src/graphics/lvl/backgroundDonjon4.png");
    }
    if (lvl->Num == 13)
    {
    lvl->Map = loadImage("src/graphics/lvl/backgroundBossJerem.png");   
    }
}
  
void Gestion_Map(Joueur *joueur, Lvl *lvl, Entité *entité,EffetSon *son, Input *input,Stats*stats, ParamTexte *paramtexte)
{  
    //Map global
    if (lvl->Num == -1)
    {
        Gestion_Map_Global(joueur, lvl, entité, son, input);
    }
    else if (lvl->Num == -2)
    {
        Break_Menu(lvl);
    }

    else if (lvl->Num == -3)
    {
        Stats_Menu(lvl,stats,paramtexte);
    }

    else if (lvl->Num == -4)
    {
        Draw_Score(lvl,stats,paramtexte);
    }

    else if (lvl->Num == -5)
    {

        Render_Win(lvl, stats, paramtexte);
    }
    
    else
    {
        //Pour marchand
        if (lvl->Num == 4)
        {
            if (joueur->inposy >=298  && joueur->inposx >= 264 && joueur->inposx <= 300)
            {
                if (lvl->WinDonjon == 1)
                {
                    lvl->WinDonjon = 2;
                    lvl->save = 1;
                }
                lvl->Num = -1;
                Mix_PlayMusic(son ->musiqueMapG, -1);
            }
        }
        else if (lvl->Num == 9)
        {
            if (joueur->inposy <=5)
            {
                lvl->Num= -1;
            }
            if (joueur->inposx >= 570)
            {
                lvl->Num+=1;
                Select_Level(joueur, lvl, entité, son);
            }
        }
        else if (lvl->Num == 10 && lvl->Avancement10 ==13)
        {
            if (joueur->inposy < 20)
            {
                lvl->Num = -1;
                lvl->Avancement10 = 0;
                if (lvl->WinDonjon == 3)
                {
                    lvl->WinDonjon = 4;
                    lvl->save=1;
                }
                
            }
            
        }
        //tout les autres niv avec sortie haut
        else if (lvl->MortMonstre == level[lvl->Num][0][1] && joueur->inposy <= 28 && joueur->inposx >= 298 && joueur->inposx <= 320 && lvl->Num != -1)
        {   
             //Variable pour bouger sur map global
            if (lvl->Num == 3 && lvl->NumDonjon == 0 && lvl->WinDonjon == 0)
            {
                lvl->WinDonjon = 1;
                lvl->save = 1;
            }
            if (lvl->Num == 8 && lvl->NumDonjon == 2 && lvl->WinDonjon == 2)
            {
                lvl->WinDonjon = 3;
            }
            if (lvl->Num == 13 && lvl->NumDonjon == 4 && lvl->WinDonjon == 4)
            {
                lvl->WinDonjon = 5;
            }
            
            //retour map global
            if (lvl->NumDonjon == 0 && lvl->Num == 3)
            {
                lvl->Num = -1;
                Mix_PlayMusic(son ->musiqueMapG, -1);
            }
            else if(lvl->NumDonjon == 2 && lvl->Num == 8)
            {
                lvl->Num = -1;
                Mix_PlayMusic(son ->musiqueMapG, -1);
            }
            else if (lvl->NumDonjon == 4 && lvl->Num == 13)
            {
                lvl->Num = -5;
                Mix_PlayMusic(son ->musiqueMapG, -1);
            }
            else if (lvl->Num != -1)
            {
                lvl->Num += 1;
                Select_Level(joueur, lvl, entité, son);
            }

        }
    }
}

void Gestion_Map_Global (Joueur *joueur, Lvl *lvl, Entité *entité,EffetSon *son, Input *input)
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
    if (lvl->Cadenas1 != NULL)
    {
        SDL_DestroyTexture(lvl->Cadenas1);
        lvl->Cadenas1 = NULL;
    }
    if (lvl->Cadenas2 != NULL)
    {
        SDL_DestroyTexture(lvl->Cadenas2);
        lvl->Cadenas2 = NULL;
    }
    if (lvl->Cadenas3 != NULL)
    {
        SDL_DestroyTexture(lvl->Cadenas3);
        lvl->Cadenas3 = NULL;
    }
    if (lvl->Cadenas4 != NULL)
    {
        SDL_DestroyTexture(lvl->Cadenas4);
        lvl->Cadenas4 = NULL;
    }

    lvl->Map=loadImage("src/graphics/lvl/mapglobal.png");
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
        Draw_Image(lvl->Icone,313,313);
        if (input->attack == 1)
        {
            lvl->Num = 0;
            Select_Level(joueur, lvl, entité, son);
        }
    }
    if (lvl->NumDonjon == 1)
    {
        if (lvl->WinDonjon >=1)
        {
            lvl->Icone=loadImage("src/graphics/lvl/TeteChevalier.png");
            Draw_Image(lvl->Icone,354,253);
            if (input->attack == 1)
            {
                lvl->Num = 4;
                Select_Level(joueur, lvl, entité, son);
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
            Draw_Image(lvl->Icone,260,195);
            if (input->attack == 1)
            {
                lvl->Num = 5;
                Select_Level(joueur, lvl, entité, son);
            }
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
            Draw_Image(lvl->Icone,228,125);
            if (input->attack == 1)
            {
                lvl->Num = 9;
                Select_Level(joueur, lvl, entité, son);
            }
        }
        else
        {
            lvl->NumDonjon -= 1;
        }
    }
    if (lvl->NumDonjon == 4)
    {
        if (lvl->WinDonjon >=4)
        {
            lvl->Icone=loadImage("src/graphics/lvl/TeteChevalier.png");
            Draw_Image(lvl->Icone,293,68);
            if (input->attack == 1)
            {
                lvl->Num = 11;
                Select_Level(joueur,lvl,entité,son);
            }   
        }
        else
        {
            lvl->NumDonjon -= 1;
        }
    }

    if (lvl->WinDonjon == 0)
    {
        lvl->Cadenas1=loadImage("src/graphics/lvl/Cadenas.png");
        Draw_Image(lvl->Cadenas1,354,253);

        lvl->Cadenas2=loadImage("src/graphics/lvl/Cadenas.png");
        Draw_Image(lvl->Cadenas2,260,190);

        lvl->Cadenas3=loadImage("src/graphics/lvl/Cadenas.png");
        Draw_Image(lvl->Cadenas3,225,120);

        lvl->Cadenas4=loadImage("src/graphics/lvl/Cadenas.png");
        Draw_Image(lvl->Cadenas4,293,68);
    }

    if (lvl->WinDonjon == 1)
    {

        lvl->Cadenas2=loadImage("src/graphics/lvl/Cadenas.png");
        Draw_Image(lvl->Cadenas2,260,190);

        lvl->Cadenas3=loadImage("src/graphics/lvl/Cadenas.png");
        Draw_Image(lvl->Cadenas3,225,120);

        lvl->Cadenas4=loadImage("src/graphics/lvl/Cadenas.png");
        Draw_Image(lvl->Cadenas4,293,68);
    }
    if (lvl->WinDonjon == 2)
    {
        lvl->Cadenas3=loadImage("src/graphics/lvl/Cadenas.png");
        Draw_Image(lvl->Cadenas3,225,120);

        lvl->Cadenas4=loadImage("src/graphics/lvl/Cadenas.png");
        Draw_Image(lvl->Cadenas4,293,68);
    }
    if (lvl->WinDonjon == 3)
    {
        lvl->Cadenas4=loadImage("src/graphics/lvl/Cadenas.png");
        Draw_Image(lvl->Cadenas4,293,68);
    }
    
}