#include "../header/proto.h"

#define SPRITE_SIZE     128
#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 384
#define DIR_RIGHT       0
#define DIR_LEFT        3


void drawGame(void)
{
 
// Affiche le fond (background) aux coordonnées (0,0)
drawImage(getBackground(), 0, 0);
 
// Affiche l'écran
SDL_RenderPresent(getrenderer());
 
// Délai pour laisser respirer le proc
SDL_Delay(1);
 
}

void Sprite (void)
{
    
    SDL_Surface *screen, *temp, *sprite;
    SDL_Rect spritePosition;
    int currentDirection = DIR_RIGHT;
    int animationFlip = 0;
    temp   = SDL_LoadBMP("sprite.bmp");
    sprite = SDL_DisplayFormat(temp);
    SDL_FreeSurface(temp);
    spritePosition.x = (SCREEN_WIDTH - SPRITE_SIZE) / 2;
    spritePosition.y = (SCREEN_HEIGHT - SPRITE_SIZE) / 2;
    SDL_Rect spriteImage;
            spriteImage.y = 0;
            spriteImage.w = SPRITE_SIZE;
            spriteImage.h = SPRITE_SIZE;
            /* choose image according to direction and animation flip: */
            spriteImage.x = SPRITE_SIZE*(2*currentDirection + animationFlip);

            SDL_BlitSurface(sprite, &spriteImage, screen, &spritePosition);
}
 
SDL_Texture *loadImage(char *name)
{
 
SDL_Surface *screen, *temp, *sprite, *grass;
int animationFlip = 0;
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
printf("L'image n'a pas pu être chargée! SDL_Error : %s\n", SDL_GetError());
 
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

