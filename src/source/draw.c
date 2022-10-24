#include "../header/proto.h"
Input input;
Lvl lvl;
Joueur joueur;

void drawGame(void)
{
    // Affiche le fond (background) aux coordonnées (0,0)
    drawImage(getBackground(), 0, 0);
    AffichageVie (&joueur);
    AffichageLevel(&lvl);
    porte (0);
    // Affiche l'écran
    
    // Délai
    SDL_Delay(1);
}




void GameOver (void)
{
    SDL_Texture *GameOver=loadImage("src/graphics/GameOver.png");
    drawImage(GameOver,0,0);
    SDL_RenderPresent(getrenderer());
    SDL_Delay(3000);
}

void Win (void)
{
    SDL_Texture *GameOver=loadImage("src/graphics/Win.png");
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




void AffichageVie (Joueur *joueur)
{
    int i=1;
    while (i<=joueur->life)
    {
        SDL_Texture *Vie=loadImage("src/graphics/Vie.png");
        drawImage(Vie,SCREEN_WIDTH-(i*34),0);
        i+=1;
    }
}

void AffichageLevel (Lvl *lvl)
{
    SDL_Texture *Level=loadImage("src/graphics/Level.png");
    drawImage(Level,0,0);
    SDL_Texture *niv=loadImage("src/graphics/1.png");
    drawImage(niv,139,0);
    if (lvl->Num==1)
    {
        SDL_Texture *Level=loadImage("src/graphics/1.png");
        drawImage(Level,139,0);
    }
}

void porte (int NbMonstre)
{
if (NbMonstre>=1)
{
SDL_Texture *Porte=loadImage("src/graphics/Porteferme.png");
drawImage(Porte,SCREEN_WIDTH/2-22,0);
}
else
{
SDL_Texture *Porte=loadImage("src/graphics/Porteouverte.png");
drawImage(Porte,SCREEN_WIDTH/2-22,0);
}

}