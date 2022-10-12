#include "../header/proto.h"
 
 
SDL_Window *screen;
SDL_Renderer *renderer;
 
 
SDL_Renderer *getrenderer(void)
{
    return renderer;
}
 
 
void init(char *title)
{
    screen = SDL_CreateWindow(title,
                                  SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED,
                                  SCREEN_WIDTH, SCREEN_HEIGHT,
                                  SDL_WINDOW_SHOWN);
 
    //VSYNC
    renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_PRESENTVSYNC);
 
    // Init écran avec erreur
    if (screen == NULL || renderer == NULL)
    {
        printf("Impossible d'initialiser le mode écran à %d x %d: %s\n", SCREEN_WIDTH,
                                                                    SCREEN_HEIGHT, SDL_GetError());
        exit(1);
    }
    
    //Initialisation du chargement des images png avec SDL_Image 2
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        printf( "SDL_image n'a pu être initialisée! SDL_image Error: %s\n", IMG_GetError() );
        exit(1);
    }
 
    //curseur souris en -
    SDL_ShowCursor(SDL_DISABLE);


    //A voir si on utilise
    /*//On initialise SDL_TTF 2 qui gérera l'écriture de texte
    if (TTF_Init() < 0)
    {
        printf("Impossible d'initialiser SDL TTF: %s\n", TTF_GetError());
        exit(1);
    }*/

 
}
 
 
 
void cleanup()
{
    //On fait le ménage et on remet les pointeurs à NULL
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    SDL_DestroyWindow(screen);
    screen = NULL;
    
    //A voir si utile
    //On quitte SDL_TTF 2
    //TTF_Quit();

    //Nettoie les sprites de la map
    cleanMaps();
 
    //On quitte la SDL
    SDL_Quit();
}

void loadGame(void)
{
 
//On charge les données pour la map
initMaps();
 
//On commence au premier niveau
SetValeurDuNiveau(1);
changeLevel();
 
}
