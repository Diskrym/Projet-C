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

    Mix_VolumeChunk(son->gameoverson, MIX_MAX_VOLUME);
    Mix_PlayChannel(10, son->gameoverson, 2);
    SDL_Delay(2000);
}

//ecran fin
void Win (void)
{
    SDL_Texture *GameOver=loadImage("src/graphics/lvl/Win.png");
    Draw_Image(GameOver,0,0);
    SDL_RenderPresent(getrenderer());
    SDL_Delay(3000);
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
    if (lvl->Vie != NULL)
    {
        SDL_DestroyTexture(lvl->Vie);
        lvl->Vie=NULL;
    }
    int i=1;

    if (lvl->Num >= 0)
    {
        while (i<=joueur->life)
        {
            lvl->Vie=loadImage("src/graphics/lvl/Vie.png");
            Draw_Image(lvl->Vie,SCREEN_WIDTH-(i*34),0);
            i+=1;
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
    
    if (lvl->Num >= 0 && lvl->Num != 4)
    {
        lvl->SpritMotLVL=loadImage("src/graphics/lvl/Level.png");
        Draw_Image(lvl->SpritMotLVL,0,0);
    }

    if (lvl->Num==0)
    {
        lvl->SpritLvl=loadImage("src/graphics/lvl/1.png");
        Draw_Image(lvl->SpritLvl,139,0);
    }
    if (lvl->Num==1)
    {
        lvl->SpritLvl=loadImage("src/graphics/lvl/2.png");
        Draw_Image(lvl->SpritLvl,139,0);
    }
    if (lvl->Num==2)
    {
        lvl->SpritLvl=loadImage("src/graphics/lvl/3.png");
        Draw_Image(lvl->SpritLvl,139,0);
    }
    if (lvl->Num==3)
    {
        lvl->SpritLvl=loadImage("src/graphics/lvl/4.png");
        Draw_Image(lvl->SpritLvl,139,0);
    }
    if (lvl->Num==4)
    {
        lvl->SpritLvl=loadImage("src/graphics/lvl/shop.png");
        Draw_Image(lvl->SpritLvl,5,5);
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
    
}

void Menu (Lvl *lvl)
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

void Statistiques(Stats * stats, Joueur *joueur, Lvl*lvl)
{
    // Gestion total pièce
    if (joueur->NbPiece>stats->Temp_pièce)
    {
        stats->Total_pièce+=(joueur->NbPiece-stats->Temp_pièce);
        stats->Temp_pièce=joueur->NbPiece;
    }
    if (stats->Temp_pièce>joueur->NbPiece)
    {
        stats->Temp_pièce=joueur->NbPiece;
    }
    //Gestion total tués
    if (lvl->MortMonstre>stats->Temp_Tués)
    {
        stats->Total_Tués+=(lvl->MortMonstre-stats->Temp_Tués);
        stats->Temp_Tués=lvl->MortMonstre;
    }
    if (stats->Temp_Tués>lvl->MortMonstre)
    {
        stats->Temp_Tués=lvl->MortMonstre;
    }
    //Gestion Nombre dague lancées !!! A diviser par 2 pour affichage
    if (joueur->Edague>stats->Temp_Dague_Lancées)
    {
        stats->Dague_Lancées+=(joueur->Edague-stats->Temp_Dague_Lancées);
        stats->Temp_Dague_Lancées=joueur->Edague;
    }
    if (stats->Temp_Dague_Lancées>joueur->Edague)
    {
        stats->Temp_Dague_Lancées=joueur->Edague;
    }    
    //Gestion Total mort
    if (lvl->reset == 1)
    {
        stats->Total_Mort+=1;
        
    }
    //Ratio
    if (stats->Total_Mort !=0)
    {
        stats->DIVI_Mort=stats->Total_Mort;
        stats->DIVI_Tués=stats->Total_Tués;
        stats->KDA=(stats->DIVI_Tués/stats->DIVI_Mort);
        sprintf(stats->affichage_kda,"%.2f",stats->KDA);
    }
    else
    {
        strcpy(stats->affichage_kda,"0.00");
    }
}

void Score_(Stats *stats,clock_t temps)
{
    printf("%f\n", (double)temps/CLOCKS_PER_SEC);
}   