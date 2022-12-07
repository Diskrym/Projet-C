#include "../header/proto.h"

void Draw_Game(Joueur *joueur, Lvl *lvl,ParamTexte *paramtexte,EffetSon *son)
{
    
    // Affiche le fond (background) aux coordonnées (0,0) si on a pas de map qui défile !=NULL
    if (lvl->Num !=10)
    {
        
        Draw_Image(lvl->Map, 0, 0);
    }
    else
    {
        if(lvl->Avancement10 <12)
        {
            lvl->PosMap10-=10;
            Draw_Image(lvl->Map,lvl->PosMap10,0);
            Draw_Image(lvl->MapSlide,lvl->PosMap10+640,0);
        }
        if (lvl->Avancement10==12)
        {
            lvl->PosMap10-=5;
            lvl->Map = loadImage("src/graphics/Rivière/PontonArrivé.png");
            Draw_Image(lvl->MapSlide,lvl->PosMap10,0);
            Draw_Image(lvl->Map,lvl->PosMap10+640,0);
        }
        if (lvl->Avancement10>12)
        {
            Draw_Image(lvl->Map,lvl->PosMap10,0);
            Draw_Image(lvl->MapSlide,lvl->PosMap10+640,0);
        }
        
        if (lvl->PosMap10 <= -640)
        {
            lvl->PosMap10 = 0;
            lvl->Avancement10+=1;
        }        
    }
    Render_Life (joueur,lvl,son);
    Render_Coin(joueur,lvl,paramtexte);
    Render_Level(lvl);
    Render_Door (lvl);
    // Affiche l'écran
    
    // Délai
    SDL_Delay(1);
    
}

//ecran fin 
void Game_Over (EffetSon *son)
{   
    
    
    // Mix_PauseMusic();
    SDL_Texture *GameOver=loadImage("src/graphics/lvl/GameOver.png");  
    Draw_Image(GameOver,0,0); 
    SDL_RenderPresent(getrenderer());

    if (GameOver != NULL)
    {
        SDL_DestroyTexture(GameOver);
        GameOver =NULL;
    }

    Mix_VolumeChunk(son->gameoverson, MIX_MAX_VOLUME);
    Mix_PlayChannel(10, son->gameoverson, 0);
    SDL_Delay(5000);
}


SDL_Texture *loadImage(char *name)
{ 
    /* Charge les images avec SDL Image dans une SDL_Surface */
    SDL_Surface *loadedImage = NULL;
    SDL_Texture *texture = NULL;
    loadedImage = IMG_Load(name);
    if (loadedImage != NULL)
    {
        // Conversion de l'image en texture
        texture = SDL_CreateTextureFromSurface(getrenderer(), loadedImage);
        // On se débarrasse du pointeur vers une surface
        SDL_FreeSurface(loadedImage);
        loadedImage = NULL;
    }
    else
    {
        printf("L'image n'a pas pu être chargée! SDL_Error : %s\n", SDL_GetError());
    }
    return texture;
}
 
void Draw_Image(SDL_Texture *image, int x, int y)
{
    SDL_Rect dest;
    /* Règle le rectangle à dessiner selon la taille de l'image source */
    dest.x = x;
    dest.y = y;
 
    /* Dessine l'image entière sur l'écran aux coordonnées x et y */
    SDL_QueryTexture(image, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(getrenderer(), image, NULL, &dest);
}

void delay(unsigned int frameLimit)
{
    // Gestion des 60 fps (images/seconde)
    unsigned int ticks = SDL_GetTicks();
 
    if (frameLimit < ticks)
    {
        return;
    }
 
    if (frameLimit > ticks + 16)
    {
        SDL_Delay(16);
    }
 
    else
    {
        SDL_Delay(frameLimit - ticks);
    }
}

void Render_Life (Joueur *joueur,Lvl *lvl, EffetSon *son)
{   
    if (lvl->Vie1 != NULL)
    {
        SDL_DestroyTexture(lvl->Vie1);
        lvl->Vie1=NULL;
    }
    if (lvl->Vie2 != NULL)
    {
        SDL_DestroyTexture(lvl->Vie2);
        lvl->Vie2=NULL;
    }
    if (lvl->Vie3 != NULL)
    {
        SDL_DestroyTexture(lvl->Vie3);
        lvl->Vie3=NULL;
    }
    if (lvl->Vie4 != NULL)
    {
        SDL_DestroyTexture(lvl->Vie4);
        lvl->Vie4=NULL;
    }

    if (lvl->Num >= 0)
    {
        if (joueur->life>=4 )      
        {
            lvl->Vie4=loadImage("src/graphics/lvl/Vie.png");
            Draw_Image(lvl->Vie4,SCREEN_WIDTH-(4*34),0);
            
        }
        if (joueur->life==3 || joueur->life>=4)      
        {
            lvl->Vie3=loadImage("src/graphics/lvl/Vie.png");
            Draw_Image(lvl->Vie3,SCREEN_WIDTH-(3*34),0);
            
        }
        if (joueur->life==2 ||joueur->life==3 || joueur->life>=4)      
        {
            lvl->Vie2=loadImage("src/graphics/lvl/Vie.png");
            Draw_Image(lvl->Vie2,SCREEN_WIDTH-(2*34),0);
            
        }
        if (joueur->life==1 ||joueur->life==2 ||joueur->life==3 || joueur->life>=4)      
        {
            lvl->Vie1=loadImage("src/graphics/lvl/Vie.png");
            Draw_Image(lvl->Vie1,SCREEN_WIDTH-(1*34),0);
            
        }         
        
           
            if (joueur->life ==1)
            {
                son->sonLowLife++;
                if (son->sonLowLife==1)
                {
                    Mix_VolumeChunk(son->lowlifechevalier, MIX_MAX_VOLUME);
                    Mix_PlayChannel(2, son->lowlifechevalier, 0); 
                }
            }
            if (joueur->life>1)
            {
                son->sonLowLife=0;
            }
        }

    }

    


void Render_Coin (Joueur *joueur,Lvl *lvl, ParamTexte *paramtexte)
{   
    if (lvl->Piece != NULL)
    {
        SDL_DestroyTexture(lvl->Piece);
        lvl->Piece=NULL;
    }
    if (paramtexte->TexturePiece != NULL)
    {
        SDL_DestroyTexture(paramtexte->TexturePiece);
        paramtexte->TexturePiece=NULL;
    }
    if (paramtexte->SurfacePiece != NULL)
    {
        SDL_FreeSurface(paramtexte->SurfacePiece);
        paramtexte->SurfacePiece=NULL;
    }

    if (lvl->Num >= 0)
    {
        lvl->Piece=loadImage("src/graphics/lvl/Piece.png");
        Draw_Image(lvl->Piece, 405 ,4);
        SDL_Color color = { 0, 0, 0 };
        SDL_itoa(joueur->NbPiece, paramtexte->StrPiece,10); 
        paramtexte->SurfacePiece = TTF_RenderText_Solid(paramtexte->Font, paramtexte->StrPiece, color);
        paramtexte->TexturePiece = SDL_CreateTextureFromSurface(getrenderer(), paramtexte->SurfacePiece);
        Draw_Image(paramtexte->TexturePiece,470,4); 
    }
}

void Render_Level (Lvl *lvl)
{
    if (lvl->SpritMotLVL !=NULL)
    {
        SDL_DestroyTexture(lvl->SpritMotLVL);
        lvl->SpritMotLVL = NULL;
    }
    if (lvl->SpritLvl != NULL)
    {
        SDL_DestroyTexture(lvl->SpritLvl);
        lvl->SpritLvl = NULL;
    }
    if (lvl->SpritTiret != NULL)
    {
        SDL_DestroyTexture(lvl->SpritTiret);
        lvl->SpritTiret = NULL;
    }
    if (lvl->SpritDonjon != NULL)
    {
        SDL_DestroyTexture(lvl->SpritDonjon);
        lvl->SpritDonjon = NULL;
    }
    
    if (lvl->Num >= 0 && lvl->Num != 4 && lvl->Num !=9  && lvl->Num !=10)
    {
        lvl->SpritMotLVL=loadImage("src/graphics/lvl/Level.png");
        Draw_Image(lvl->SpritMotLVL,0,0);
    }

    if (lvl->Num==0)
    {
        lvl->SpritDonjon=loadImage("src/graphics/lvl/1.png");
        Draw_Image(lvl->SpritDonjon,139,0);
        lvl->SpritTiret=loadImage("src/graphics/lvl/Tiret.png");
        Draw_Image(lvl->SpritTiret,157,0);
        lvl->SpritLvl=loadImage("src/graphics/lvl/1.png");
        Draw_Image(lvl->SpritLvl,170,0);
    }
    if (lvl->Num==1)
    {
        lvl->SpritDonjon=loadImage("src/graphics/lvl/1.png");
        Draw_Image(lvl->SpritDonjon,139,0);
        lvl->SpritTiret=loadImage("src/graphics/lvl/Tiret.png");
        Draw_Image(lvl->SpritTiret,157,0);
        lvl->SpritLvl=loadImage("src/graphics/lvl/2.png");
        Draw_Image(lvl->SpritLvl,170,0);
    }
    if (lvl->Num==2)
    {   
        lvl->SpritDonjon=loadImage("src/graphics/lvl/1.png");
        Draw_Image(lvl->SpritDonjon,139,0);
        lvl->SpritTiret=loadImage("src/graphics/lvl/Tiret.png");
        Draw_Image(lvl->SpritTiret,157,0);
        lvl->SpritLvl=loadImage("src/graphics/lvl/3.png");
        Draw_Image(lvl->SpritLvl,170,0);
    }
    if (lvl->Num==3)
    {
        lvl->SpritDonjon=loadImage("src/graphics/lvl/1.png");
        Draw_Image(lvl->SpritDonjon,139,0);
        lvl->SpritTiret=loadImage("src/graphics/lvl/Tiret.png");
        Draw_Image(lvl->SpritTiret,157,0);
        lvl->SpritLvl=loadImage("src/graphics/lvl/4.png");
        Draw_Image(lvl->SpritLvl,170,0);
    }
    if (lvl->Num==4)
    {
        lvl->SpritLvl=loadImage("src/graphics/lvl/shop.png");
        Draw_Image(lvl->SpritLvl,5,5);
    }
    if (lvl->Num==5)
    {
        lvl->SpritDonjon=loadImage("src/graphics/lvl/2.png");
        Draw_Image(lvl->SpritDonjon,139,0);
        lvl->SpritTiret=loadImage("src/graphics/lvl/Tiret.png");
        Draw_Image(lvl->SpritTiret,170,0);
        lvl->SpritLvl=loadImage("src/graphics/lvl/1.png");
        Draw_Image(lvl->SpritLvl,183,0);
    }
    if (lvl->Num==6)
    {
        lvl->SpritDonjon=loadImage("src/graphics/lvl/2.png");
        Draw_Image(lvl->SpritDonjon,139,0);
        lvl->SpritTiret=loadImage("src/graphics/lvl/Tiret.png");
        Draw_Image(lvl->SpritTiret,170,0);
        lvl->SpritLvl=loadImage("src/graphics/lvl/2.png");
        Draw_Image(lvl->SpritLvl,183,0);
    }
    if (lvl->Num==7)
    {
        lvl->SpritDonjon=loadImage("src/graphics/lvl/2.png");
        Draw_Image(lvl->SpritDonjon,139,0);
        lvl->SpritTiret=loadImage("src/graphics/lvl/Tiret.png");
        Draw_Image(lvl->SpritTiret,170,0);
        lvl->SpritLvl=loadImage("src/graphics/lvl/3.png");
        Draw_Image(lvl->SpritLvl,183,0);
    }
    if (lvl->Num==8)
    {
        lvl->SpritDonjon=loadImage("src/graphics/lvl/2.png");
        Draw_Image(lvl->SpritDonjon,139,0);
        lvl->SpritTiret=loadImage("src/graphics/lvl/Tiret.png");
        Draw_Image(lvl->SpritTiret,170,0);
        lvl->SpritLvl=loadImage("src/graphics/lvl/4.png");
        Draw_Image(lvl->SpritLvl,183,0);
    }
    if (lvl->Num==9)
    {
        lvl->SpritLvl=loadImage("src/graphics/lvl/river.png");
        Draw_Image(lvl->SpritLvl,5,5);
    }
    if (lvl->Num==10)
    {
        lvl->SpritLvl=loadImage("src/graphics/lvl/river.png");
        Draw_Image(lvl->SpritLvl,5,5);
    }

    if (lvl->Num==11)
    {
        lvl->SpritDonjon=loadImage("src/graphics/lvl/3.png");
        Draw_Image(lvl->SpritDonjon,139,0);
        lvl->SpritTiret=loadImage("src/graphics/lvl/Tiret.png");
        Draw_Image(lvl->SpritTiret,184,0);
        lvl->SpritLvl=loadImage("src/graphics/lvl/1.png");
        Draw_Image(lvl->SpritLvl,197,0);
    }
    if (lvl->Num==12)
    {
        lvl->SpritDonjon=loadImage("src/graphics/lvl/3.png");
        Draw_Image(lvl->SpritDonjon,139,0);
        lvl->SpritTiret=loadImage("src/graphics/lvl/Tiret.png");
        Draw_Image(lvl->SpritTiret,184,0);
        lvl->SpritLvl=loadImage("src/graphics/lvl/2.png");
        Draw_Image(lvl->SpritLvl,197,0);
    }
    if (lvl->Num==13)
    {
        lvl->SpritDonjon=loadImage("src/graphics/lvl/3.png");
        Draw_Image(lvl->SpritDonjon,139,0);
        lvl->SpritTiret=loadImage("src/graphics/lvl/Tiret.png");
        Draw_Image(lvl->SpritTiret,184,0);
        lvl->SpritLvl=loadImage("src/graphics/lvl/3.png");
        Draw_Image(lvl->SpritLvl,197,0);
    }
}

void Render_Door (Lvl *lvl)
{
    if (lvl->PorteHaut !=NULL)
    {
        SDL_DestroyTexture(lvl->PorteHaut);
        lvl->PorteHaut=NULL;
    }
    if (lvl->PorteBas !=NULL)
    {
        SDL_DestroyTexture (lvl->PorteBas) ;
        lvl->PorteBas =NULL ;
    }
    if(lvl->Num==0 || lvl->Num==1)
    {
        if (lvl->MortMonstre==level[lvl->Num][0][1])
        {
            lvl->PorteHaut=loadImage("src/graphics/lvl/Porteouverte.png");
            Draw_Image(lvl->PorteHaut,SCREEN_WIDTH/2-22,0);

            if (lvl->Num != 0)
            {
                lvl->PorteBas=loadImage("src/graphics/lvl/Portefermebas.png");
                Draw_Image(lvl->PorteBas,SCREEN_WIDTH/2-22,345);
            }
        }
        else
        {
            lvl->PorteHaut=loadImage("src/graphics/lvl/Porteferme.png");
            Draw_Image(lvl->PorteHaut,SCREEN_WIDTH/2-22,0);
            if (lvl->Num != 0)
            {
                lvl->PorteBas=loadImage("src/graphics/lvl/Portefermebas.png");
                Draw_Image(lvl->PorteBas,SCREEN_WIDTH/2-22,345);
            }    
        }
    }
    if (lvl->Num==2)
    {
        lvl->PorteBas=loadImage("src/graphics/lvl/Portefermebas.png");
        Draw_Image(lvl->PorteBas,SCREEN_WIDTH/2-22,345);
         if (lvl->MortMonstre==level[lvl->Num][0][1])
        {
            lvl->PorteHaut=loadImage("src/graphics/lvl/PorteBossOuverte.png");
            Draw_Image(lvl->PorteHaut,SCREEN_WIDTH/2-22,0);
            
        }
        else
        {
            lvl->PorteHaut=loadImage("src/graphics/lvl/PorteBossFerme.png");
            Draw_Image(lvl->PorteHaut,SCREEN_WIDTH/2-22,0);
              
        }
    }
    if (lvl->Num==3)
    {
        lvl->PorteBas=loadImage("src/graphics/lvl/PorteBossFermeBas.png");
        Draw_Image(lvl->PorteBas,SCREEN_WIDTH/2-22,345);
         if (lvl->MortMonstre==level[lvl->Num][0][1])
        {
            lvl->PorteHaut=loadImage("src/graphics/lvl/PorteRougeOuverte.png");
            Draw_Image(lvl->PorteHaut,SCREEN_WIDTH/2-22,0);
            
        }
        else
        {
            lvl->PorteHaut=loadImage("src/graphics/lvl/PorteRougeFerme.png");
            Draw_Image(lvl->PorteHaut,SCREEN_WIDTH/2-22,0);
              
        }
    }
    if (lvl->Num == 5 || lvl->Num == 6 || lvl->Num == 7)
    {
        if (lvl->Num != 5)
        {
            lvl->PorteBas=loadImage("src/graphics/lvl/PorteFermeBleuBas.png");
            Draw_Image(lvl->PorteBas,SCREEN_WIDTH/2-22,345); 
        }
         if (lvl->MortMonstre==level[lvl->Num][0][1])
        {
            lvl->PorteHaut=loadImage("src/graphics/lvl/PorteOuverteBleu.png");
            Draw_Image(lvl->PorteHaut,SCREEN_WIDTH/2-22,0);
            
        }
        else
        {
            lvl->PorteHaut=loadImage("src/graphics/lvl/PorteFermeBleu.png");
            Draw_Image(lvl->PorteHaut,SCREEN_WIDTH/2-22,0);
              
        }
        
    }
    if (lvl->Num==8)
    {
        lvl->PorteBas=loadImage("src/graphics/lvl/PorteBossFermeBas.png");
        Draw_Image(lvl->PorteBas,SCREEN_WIDTH/2-22,345);
         if (lvl->MortMonstre==level[lvl->Num][0][1])
        {
            lvl->PorteHaut=loadImage("src/graphics/lvl/PorteNoirOuverteHaut.png");
            Draw_Image(lvl->PorteHaut,SCREEN_WIDTH/2-22,0);
            
        }
        else
        {
            lvl->PorteHaut=loadImage("src/graphics/lvl/PorteNoirFermeHaut.png");
            Draw_Image(lvl->PorteHaut,SCREEN_WIDTH/2-22,0);
              
        }
    }
    if (lvl->Num == 11 || lvl->Num == 12 || lvl->Num == 13)
    {
        if (lvl->Num != 11)
        {
            lvl->PorteBas=loadImage("src/graphics/lvl/PorteNoirFermeBas.png");
            Draw_Image(lvl->PorteBas,SCREEN_WIDTH/2-22,345); 
        }
         if (lvl->MortMonstre==level[lvl->Num][0][1])
        {
            lvl->PorteHaut=loadImage("src/graphics/lvl/PorteNoirOuverteHaut.png");
            Draw_Image(lvl->PorteHaut,SCREEN_WIDTH/2-22,0);
            
        }
        else
        {
            lvl->PorteHaut=loadImage("src/graphics/lvl/PorteNoirFermeHaut.png");
            Draw_Image(lvl->PorteHaut,SCREEN_WIDTH/2-22,0);
              
        }
        
    }
    
}

void Draw_Menu (Lvl *lvl)
{   
    if (lvl->Menu!=NULL)
    {
        SDL_DestroyTexture(lvl->Menu);
        lvl->Menu=NULL;
    }
    lvl->Menu=loadImage("src/graphics/lvl/Menu.png");
    Draw_Image(lvl->Menu,0,0);   
}

void Break_Menu (Lvl *lvl)
{
    if (lvl->Menu!=NULL)
    {
        SDL_DestroyTexture(lvl->Menu);
        lvl->Menu=NULL;
    }
    lvl->Menu=loadImage("src/graphics/lvl/Game_Menu.png");
    Draw_Image(lvl->Menu,0,0); 
}

void Stats_Menu(Lvl *lvl,Stats *stats, ParamTexte *paramtexte)
{
    if (lvl->Menu!=NULL)
    {
        SDL_DestroyTexture(lvl->Menu);
        lvl->Menu=NULL;
    }
    if (paramtexte->SurfaceGold != NULL)
    {
        SDL_DestroyTexture(paramtexte->TextureGold);
        SDL_FreeSurface(paramtexte->SurfaceGold);
        paramtexte->TextureGold = NULL;
        paramtexte->SurfaceGold = NULL;
    } 
    if (paramtexte->SurfaceKilled != NULL)
    {
        SDL_DestroyTexture(paramtexte->TextureKilled);
        SDL_FreeSurface(paramtexte->SurfaceKilled);
        paramtexte->TextureKilled = NULL;
        paramtexte->SurfaceKilled = NULL;
    }
    if (paramtexte->SurfaceDeath != NULL)
    {
        SDL_DestroyTexture(paramtexte->TextureDeath);
        SDL_FreeSurface(paramtexte->SurfaceDeath);
        paramtexte->TextureDeath = NULL;
        paramtexte->SurfaceDeath = NULL;
    }
    if (paramtexte->SurfaceDaggers != NULL)
    {
        SDL_DestroyTexture(paramtexte->TextureDaggers);
        SDL_FreeSurface(paramtexte->SurfaceDaggers);
        paramtexte->TextureDaggers = NULL;
        paramtexte->SurfaceDaggers = NULL;
    }
    if (paramtexte->SurfaceRatio != NULL)
    {
        SDL_DestroyTexture(paramtexte->TextureRatio);
        SDL_FreeSurface(paramtexte->SurfaceRatio);
        paramtexte->TextureRatio = NULL;
        paramtexte->SurfaceRatio = NULL;
    }
    

    lvl->Menu=loadImage("src/graphics/lvl/MenuStats.png");
    Draw_Image(lvl->Menu,0,0);

    SDL_Color color = { 255, 255, 255 };
    //pièce
    SDL_itoa(stats->Total_pièce, paramtexte->Gold_Won,10); 
    paramtexte->SurfaceGold = TTF_RenderText_Solid(paramtexte->Fontpetite, paramtexte->Gold_Won, color);
    paramtexte->TextureGold = SDL_CreateTextureFromSurface(getrenderer(), paramtexte->SurfaceGold);
    Draw_Image(paramtexte->TextureGold  ,422,135); 
    //Monstre tués
    SDL_itoa(stats->Total_Tués, paramtexte->Monsters_Killed,10); 
    paramtexte->SurfaceKilled = TTF_RenderText_Solid(paramtexte->Fontpetite, paramtexte->Monsters_Killed, color);
    paramtexte->TextureKilled = SDL_CreateTextureFromSurface(getrenderer(), paramtexte->SurfaceKilled);
    Draw_Image(paramtexte->TextureKilled  ,422,159); 
    //Total mort
    SDL_itoa(stats->Total_Mort, paramtexte->Total_Death,10); 
    paramtexte->SurfaceDeath = TTF_RenderText_Solid(paramtexte->Fontpetite, paramtexte->Total_Death, color);
    paramtexte->TextureDeath = SDL_CreateTextureFromSurface(getrenderer(), paramtexte->SurfaceDeath);
    Draw_Image(paramtexte->TextureDeath  ,422,183);
    //Total dagues
    SDL_itoa(stats->Dague_Lancées, paramtexte->Thrown_Daggers,10); 
    paramtexte->SurfaceDaggers = TTF_RenderText_Solid(paramtexte->Fontpetite, paramtexte->Thrown_Daggers, color);
    paramtexte->TextureDaggers = SDL_CreateTextureFromSurface(getrenderer(), paramtexte->SurfaceDaggers);
    Draw_Image(paramtexte->TextureDaggers,422,207); 
    //Ratio
    paramtexte->SurfaceRatio = TTF_RenderText_Solid(paramtexte->Fontpetite, stats->affichage_kda, color);
    paramtexte->TextureRatio = SDL_CreateTextureFromSurface(getrenderer(), paramtexte->SurfaceRatio);
    Draw_Image(paramtexte->TextureRatio,422,231);
}

void Draw_Score (Lvl* lvl, Stats *stats, ParamTexte *paramtexte)
{
    if (lvl->Menu!=NULL)
    {
        SDL_DestroyTexture(lvl->Menu);
        lvl->Menu=NULL;
    }
    if (stats->Surface_SCORE_1 != NULL || stats->Texture_SCORE_1 != NULL)
    {
        SDL_DestroyTexture(stats->Texture_SCORE_1);
        SDL_DestroyTexture(stats->Texture_SCORE_2);
        SDL_DestroyTexture(stats->Texture_SCORE_3);
        SDL_DestroyTexture(stats->Texture_SCORE_4);
        SDL_DestroyTexture(stats->Texture_SCORE_5);
        stats->Texture_SCORE_1 = NULL;
        stats->Texture_SCORE_2 = NULL;
        stats->Texture_SCORE_3 = NULL;
        stats->Texture_SCORE_4 = NULL;
        stats->Texture_SCORE_5 = NULL;
        SDL_FreeSurface(stats->Surface_SCORE_1);
        SDL_FreeSurface(stats->Surface_SCORE_2);
        SDL_FreeSurface(stats->Surface_SCORE_3);
        SDL_FreeSurface(stats->Surface_SCORE_4);
        SDL_FreeSurface(stats->Surface_SCORE_5);
        stats->Surface_SCORE_1 = NULL;
        stats->Surface_SCORE_2 = NULL;
        stats->Surface_SCORE_3 = NULL;
        stats->Surface_SCORE_4 = NULL;
        stats->Surface_SCORE_5 = NULL;
    }
    
    SDL_Color color = { 255, 255, 255 };

    lvl->Menu=loadImage("src/graphics/lvl/MenuScore.png");
    Draw_Image(lvl->Menu,0,0);

    stats->Surface_SCORE_1 = TTF_RenderText_Solid(paramtexte->Fontpetite, stats->Convert_Score[0], color);
    stats->Texture_SCORE_1 = SDL_CreateTextureFromSurface(getrenderer(), stats->Surface_SCORE_1);
    Draw_Image(stats->Texture_SCORE_1 ,330,133);

    stats->Surface_SCORE_2 = TTF_RenderText_Solid(paramtexte->Fontpetite, stats->Convert_Score[1], color);
    stats->Texture_SCORE_2 = SDL_CreateTextureFromSurface(getrenderer(), stats->Surface_SCORE_2);
    Draw_Image(stats->Texture_SCORE_2 ,330,158);

    stats->Surface_SCORE_3 = TTF_RenderText_Solid(paramtexte->Fontpetite, stats->Convert_Score[2], color);
    stats->Texture_SCORE_3 = SDL_CreateTextureFromSurface(getrenderer(), stats->Surface_SCORE_3);
    Draw_Image(stats->Texture_SCORE_3 ,330,181);

    stats->Surface_SCORE_4 = TTF_RenderText_Solid(paramtexte->Fontpetite, stats->Convert_Score[3], color);
    stats->Texture_SCORE_4 = SDL_CreateTextureFromSurface(getrenderer(), stats->Surface_SCORE_4);
    Draw_Image(stats->Texture_SCORE_4 ,330,208);

    stats->Surface_SCORE_5 = TTF_RenderText_Solid(paramtexte->Fontpetite, stats->Convert_Score[4], color);
    stats->Texture_SCORE_5 = SDL_CreateTextureFromSurface(getrenderer(), stats->Surface_SCORE_5);
    Draw_Image(stats->Texture_SCORE_5 ,330,234);
}

void Render_Win(Lvl *lvl, Stats *stats,ParamTexte *paramtexte)
{
    if (lvl->Map!=NULL)
    {
        SDL_DestroyTexture(lvl->Map);
        lvl->Map=NULL;
    }
    if (stats->Surface_Actuelle !=NULL || stats->Texture_Actuelle != NULL)
    {
        SDL_DestroyTexture(stats->Texture_Actuelle);
        stats->Texture_Actuelle=NULL;
        SDL_FreeSurface(stats->Surface_Actuelle);
        stats->Surface_Actuelle = NULL;
    }
    
    SDL_Color color = { 255, 255, 255 };

    
    if(lvl->PosMap10 >= -1700)
    {
        printf("%s\n",stats->Score_act);
        lvl->Map=loadImage("src/graphics/lvl/Win.png");
        Draw_Image(lvl->Map,0,0+lvl->PosMap10);
        stats->Surface_Actuelle = TTF_RenderText_Solid(paramtexte->Font, stats->Score_act, color);
        stats->Texture_Actuelle = SDL_CreateTextureFromSurface(getrenderer(), stats->Surface_Actuelle);
        Draw_Image(stats->Texture_Actuelle ,335,275+lvl->PosMap10);

        if (lvl->PosMap10 == 0)
        {
            SDL_RenderPresent(getrenderer());
            SDL_Delay(5000);
        }  
        lvl->PosMap10 -=1; 

    }
    else
    {
        lvl->PosMap10 = 0;
        lvl->Num = -1;
        lvl->save = 1;
    }
    
    
}
