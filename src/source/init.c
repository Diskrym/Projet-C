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
    SDL_Event event;

}

void Son (EffetSon *son)
{
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
   {
      printf("%s", Mix_GetError());
   }
    Mix_AllocateChannels(32); //Allouer 32 canaux
    son->musique = Mix_LoadMUS("src/Sik/musikdous.mp3"); //Chargement de la musique
    //Mix_PlayMusic(son ->musique, -1); //Jouer infiniment la musique
    Mix_Volume(1, MIX_MAX_VOLUME/2); //Mettre à mi-volume le post 1
    son->epee = Mix_LoadWAV("src/Sik/épée.wav"); //Charger un wav dans un pointeur
    
}

void SelectNiv (Joueur *joueur, Lvl *lvl, Monstre *monstre)
{
    if(lvl->Num==0)
    {
        LoadNiv1(&monstre->meduse, lvl, joueur);
    }
    if(lvl->Num==1)
    {
        LoadNiv2(&monstre->meduse, &monstre->meduse1, &monstre->meduse2, lvl, joueur);
    }
    if(lvl->Num==2)
    {
         LoadNiv3(&monstre->meduse, &monstre->meduse1, &monstre->chauvesouris , &monstre->chauvesouris1, lvl, joueur);
    }
    lvl->MortMonstre=0;
}

void GestionMonstre (Monstre* monstre, Lvl *lvl, Input *input, Joueur *joueur)
{
    if(lvl->Num==0)
    {
        deplacementMeduse(joueur, &monstre->meduse, lvl);
        collision(joueur, &monstre->meduse, input);
    }
    if(lvl->Num==1)
    {
        deplacementMeduse(joueur, &monstre->meduse, lvl);
        deplacementMeduse(joueur, &monstre->meduse1, lvl);
        deplacementMeduse(joueur, &monstre->meduse2, lvl);
        collision(joueur, &monstre->meduse, input);
        collision(joueur, &monstre->meduse1, input);
        collision(joueur, &monstre->meduse2, input);
    }
    if(lvl->Num==2)
    {
        deplacementMeduse(joueur, &monstre->meduse, lvl);
        deplacementMeduse(joueur, &monstre->meduse1, lvl);
        deplacementChauvesouris(joueur,&monstre->chauvesouris, &monstre->meduse);
        deplacementChauvesouris(joueur, &monstre->chauvesouris1, &monstre->meduse);
        collision(joueur, &monstre->meduse, input);
        collision(joueur, &monstre->meduse1, input);
        collision(joueur, &monstre->meduse2, input);
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

void LoadNiv3(Meduse *meduse, Meduse *meduse1, Chauvesouris *chauvesouris, Chauvesouris *chauvesouris1, Lvl *lvl, Joueur *joueur)
{  
        initMaps(lvl);
        joueur->inposx = level[2][0][2];
        joueur->inposy = level[2][0][3];
        meduse->posmonsx =level[2][1][1];
        meduse->posmonsy =level[2][1][2];
        meduse->Life=level[2][1][5];
        meduse1->posmonsx =level[2][2][1];
        meduse1->posmonsy =level[2][2][2];
        meduse1->Life=level[2][2][5];
        chauvesouris->posmonsx =level[2][3][1];
        chauvesouris->posmonsy =level[2][3][2];
        chauvesouris->Life=level[2][3][5];
        chauvesouris1->posmonsx =level[2][4][1];
        chauvesouris1->posmonsy =level[2][4][2];
        chauvesouris1->Life=level[2][4][5];
}

void cleanup(EffetSon *son)
{
    Mix_FreeMusic(son->musique); //Libération de la musique
    //Mix_FreeChunk(son);
    Mix_CloseAudio(); //Fermeture de l'API

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