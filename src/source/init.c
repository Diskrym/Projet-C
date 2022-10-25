#include "../header/proto.h"
 
SDL_Window *screen;
SDL_Renderer *renderer;


SDL_Renderer *getrenderer(void)
{
    return renderer;
}
 

void init(char *title)
{
    /* On crée la fenêtre, représentée par le pointeur jeu.window en utilisant la largeur et la
    hauteur définies dans les defines (defs.h).
    Nouveautés SDL2 : on peut centrer la fenêtre avec SDL_WINDOWPOS_CENTERED, et choisir la taille
    de la fenêtre, pour que la carte graphique l'agrandisse automatiquement. Notez aussi qu'on peut
    maintenant créer plusieurs fenêtres. */
 
    screen = SDL_CreateWindow(title,
                                  SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED,
                                  SCREEN_WIDTH, SCREEN_HEIGHT,
                                  SDL_WINDOW_SHOWN);
 
    //On crée un renderer pour la SDL et on active la synchro verticale : VSYNC
    renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_PRESENTVSYNC);
 
    // Si on n'y arrive pas, on quitte en enregistrant l'erreur dans stdout.txt
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
 
    //On cache le curseur de la souris
    SDL_ShowCursor(SDL_DISABLE);
 
    //On initialise SDL_TTF 2 qui gérera l'écriture de texte
    if (TTF_Init() < 0)
    {
        printf("Impossible d'initialiser SDL TTF: %s\n", TTF_GetError());
        exit(1);
    }
 
    /*On initialise SDL_Mixer 2, qui gérera la musique et les effets sonores
    int flags = MIX_INIT_MP3;
    int initted = Mix_Init(flags);
    if ((initted & flags) != flags)
    {
        printf("Mix_Init: Failed to init SDL_Mixer\n");
        printf("Mix_Init: %s\n", Mix_GetError());
        exit(1);
    }
 
     Open 44.1KHz, signed 16bit, system byte order,
    stereo audio, using 1024 byte chunks (voir la doc pour plus d'infos) 
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
        printf("Mix_OpenAudio: %s\n", Mix_GetError());
        exit(1);
    }
 
    // Définit le nombre de pistes audio (channels) à mixer
    Mix_AllocateChannels(32);*/
 
}

void SelectNiv (Joueur *joueur, Lvl *lvl, Meduse *meduse, Meduse *meduse1, Meduse *meduse2, Chauvesouris *chauvesouris)
{
    if(lvl->Num==0)
    {
        LoadNiv1(meduse, lvl, joueur);
    }
    if(lvl->Num==1)
    {
        LoadNiv2(meduse, meduse1, meduse2, lvl, joueur);
    }
    lvl->MortMonstre=0;
}

void GestionMonstre (Meduse* meduse, Meduse *meduse1, Meduse *meduse2, Lvl *lvl, Input *input, Joueur *joueur, Chauvesouris *chauvesouris)
{
    if(lvl->Num==0)
    {
        deplacementMeduse(joueur, meduse, lvl, chauvesouris);
        collision(joueur, meduse, input);
    }
    if(lvl->Num==1)
    {
        deplacementMeduse(joueur, meduse, lvl, chauvesouris);
        deplacementMeduse(joueur, meduse1, lvl, chauvesouris);
        deplacementMeduse(joueur, meduse2, lvl ,chauvesouris);
        collision(joueur, meduse, input);
        collision(joueur, meduse1, input);
        collision(joueur, meduse2, input);
    }
}


void LoadNiv1(Meduse *meduse, Lvl *lvl, Joueur *joueur)
{  
        initMaps(lvl);
        joueur->inposx = level[0][0][2];
        joueur->inposy = level[0][0][3];
        meduse->posmonsx =level[0][1][1];
        meduse->posmonsy =level[0][1][2];
        meduse->Life=level[0][1][5];
}

void LoadNiv2(Meduse *meduse,Meduse *meduse1,Meduse *meduse2 , Lvl *lvl, Joueur *joueur)
{  
        initMaps(lvl);
        joueur->inposx = level[1][0][2];
        joueur->inposy = level[1][0][3];
        meduse->posmonsx =level[1][1][1];
        meduse->posmonsy =level[1][1][2];
        meduse->Life=level[1][1][5];
        meduse1->posmonsx =level[1][2][1];
        meduse1->posmonsy =level[1][2][2];
        meduse1->Life=level[1][2][5];
        meduse2->posmonsx =level[1][3][1];
        meduse2->posmonsy =level[1][3][2];
        meduse2->Life=level[1][3][5];
}

void cleanup()
{
    //On quitte SDL_Mixer 2 et on décharge la mémoire
    //Mix_CloseAudio();
    //Mix_Quit();
 
    //On fait le ménage et on remet les pointeurs à NULL
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    SDL_DestroyWindow(screen);
    screen = NULL;
    
    //Nettoie les sprites de la map
    cleanMaps();

    //On quitte SDL_TTF 2
    TTF_Quit();
 
    //On quitte la SDL
    SDL_Quit();
}