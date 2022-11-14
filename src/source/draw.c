#include "../header/proto.h"

void drawGame(Joueur *joueur, Lvl *lvl,ParamTexte *paramtexte)
{
    // Affiche le fond (background) aux coordonnées (0,0)
    drawImage(lvl->Map, 0, 0);
    AffichageVie (joueur,lvl);
    AffichagePiece(joueur,lvl,paramtexte);
    AffichageLevel(lvl);
    porte (lvl);
    // Affiche l'écran
    
    // Délai
    SDL_Delay(1);
}

//ecran fin 
void GameOver (EffetSon *son)
{   
    // Mix_PauseMusic();
    SDL_Texture *GameOver=loadImage("src/graphics/lvl/GameOver.png");
    drawImage(GameOver,0,0);
    SDL_RenderPresent(getrenderer());

    Mix_VolumeChunk(son->gameoverson, MIX_MAX_VOLUME);
    Mix_PlayChannel(10, son->gameoverson, 2);
    SDL_Delay(3000);
}

//ecran fin
void Win (void)
{
    SDL_Texture *GameOver=loadImage("src/graphics/lvl/Win.png");
    drawImage(GameOver,0,0);
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
 
void drawImage(SDL_Texture *image, int x, int y)
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

void AffichageVie (Joueur *joueur,Lvl *lvl)
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
            drawImage(lvl->Vie,SCREEN_WIDTH-(i*34),0);
            i+=1;
        }
    }
}

void AffichagePiece (Joueur *joueur,Lvl *lvl, ParamTexte *paramtexte)
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
        drawImage(lvl->Piece, 405 ,4);
        SDL_Color color = { 0, 0, 0 };
        SDL_itoa(joueur->NbPiece, paramtexte->StrPiece,10); 
        paramtexte->SurfacePiece = TTF_RenderText_Solid(paramtexte->Font, paramtexte->StrPiece, color);
        paramtexte->TexturePiece = SDL_CreateTextureFromSurface(getrenderer(), paramtexte->SurfacePiece);
        drawImage(paramtexte->TexturePiece,470,4); 
    }
}

void AffichageLevel (Lvl *lvl)
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
        drawImage(lvl->SpritMotLVL,0,0);
    }

    if (lvl->Num==0)
    {
        lvl->SpritLvl=loadImage("src/graphics/lvl/1.png");
        drawImage(lvl->SpritLvl,139,0);
    }
    if (lvl->Num==1)
    {
        lvl->SpritLvl=loadImage("src/graphics/lvl/2.png");
        drawImage(lvl->SpritLvl,139,0);
    }
    if (lvl->Num==2)
    {
        lvl->SpritLvl=loadImage("src/graphics/lvl/3.png");
        drawImage(lvl->SpritLvl,139,0);
    }
    if (lvl->Num==3)
    {
        lvl->SpritLvl=loadImage("src/graphics/lvl/4.png");
        drawImage(lvl->SpritLvl,139,0);
    }
    if (lvl->Num==4)
    {
        lvl->SpritLvl=loadImage("src/graphics/lvl/shop.png");
        drawImage(lvl->SpritLvl,5,5);
    }
}

void porte (Lvl *lvl)
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
            drawImage(lvl->PorteHaut,SCREEN_WIDTH/2-22,0);

            if (lvl->Num != 0)
            {
                lvl->PorteBas=loadImage("src/graphics/lvl/Portefermebas.png");
                drawImage(lvl->PorteBas,SCREEN_WIDTH/2-22,345);
            }
        }
        else
        {
            lvl->PorteHaut=loadImage("src/graphics/lvl/Porteferme.png");
            drawImage(lvl->PorteHaut,SCREEN_WIDTH/2-22,0);
            if (lvl->Num != 0)
            {
                lvl->PorteBas=loadImage("src/graphics/lvl/Portefermebas.png");
                drawImage(lvl->PorteBas,SCREEN_WIDTH/2-22,345);
            }    
        }
    }
    if (lvl->Num==2)
    {
        lvl->PorteBas=loadImage("src/graphics/lvl/Portefermebas.png");
        drawImage(lvl->PorteBas,SCREEN_WIDTH/2-22,345);
         if (lvl->MortMonstre==level[lvl->Num][0][1])
        {
            lvl->PorteHaut=loadImage("src/graphics/lvl/PorteBossOuverte.png");
            drawImage(lvl->PorteHaut,SCREEN_WIDTH/2-22,0);
            
        }
        else
        {
            lvl->PorteHaut=loadImage("src/graphics/lvl/PorteBossFerme.png");
            drawImage(lvl->PorteHaut,SCREEN_WIDTH/2-22,0);
              
        }
    }
    if (lvl->Num==3)
    {
        lvl->PorteBas=loadImage("src/graphics/lvl/PorteBossFermeBas.png");
        drawImage(lvl->PorteBas,SCREEN_WIDTH/2-22,345);
         if (lvl->MortMonstre==level[lvl->Num][0][1])
        {
            lvl->PorteHaut=loadImage("src/graphics/lvl/PorteRougeOuverte.png");
            drawImage(lvl->PorteHaut,SCREEN_WIDTH/2-22,0);
            
        }
        else
        {
            lvl->PorteHaut=loadImage("src/graphics/lvl/PorteRougeFerme.png");
            drawImage(lvl->PorteHaut,SCREEN_WIDTH/2-22,0);
              
        }
    }
    if (lvl->Num == 5 || lvl->Num == 6)
    {
        if (lvl->Num != 5)
        {
            lvl->PorteBas=loadImage("src/graphics/lvl/PorteFermeBleuBas.png");
            drawImage(lvl->PorteBas,SCREEN_WIDTH/2-22,345); 
        }
         if (lvl->MortMonstre==level[lvl->Num][0][1])
        {
            lvl->PorteHaut=loadImage("src/graphics/lvl/PorteOuverteBleu.png");
            drawImage(lvl->PorteHaut,SCREEN_WIDTH/2-22,0);
            
        }
        else
        {
            lvl->PorteHaut=loadImage("src/graphics/lvl/PorteFermeBleu.png");
            drawImage(lvl->PorteHaut,SCREEN_WIDTH/2-22,0);
              
        }
        
    }
    
}

void menu (Lvl *lvl)
{   
    if (lvl->Menu!=NULL)
    {
        SDL_DestroyTexture(lvl->Menu);
        lvl->Menu=NULL;
    }
    lvl->Menu=loadImage("src/graphics/lvl/Menu.png");
    drawImage(lvl->Menu,0,0);   
}