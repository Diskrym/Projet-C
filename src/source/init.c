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
    son->musiquemenu = Mix_LoadMUS("src/Sik/m_menu.mp3"); //Chargement de la musique
    son->musiqueboss = Mix_LoadMUS("src/Sik/m_Boss.mp3");
    son->musiquelvl = Mix_LoadMUS("src/Sik/MusiqueLvl.mp3");

    Mix_PlayMusic(son ->musiquemenu, -1); //Jouer infiniment la musique
    Mix_Volume(1, MIX_MAX_VOLUME/2); //Mettre à mi-volume le post 1
    son->epee = Mix_LoadWAV("src/Sik/attackChe.WAV"); //Charger un wav dans un pointeur
    son->bouclier= Mix_LoadWAV("src/Sik/BouclierChe.WAV");
    son->depchevalier= Mix_LoadWAV("src/Sik/deplacementchevalier.WAV");
    son->degatchevalier= Mix_LoadWAV("src/Sik/degatChe.WAV");
    son->mortchevalier= Mix_LoadWAV("src/Sik/mortChe.WAV");
    son->lowlifechevalier= Mix_LoadWAV("src/Sik/Chelowlife.WAV");
    son->attaquemeduse= Mix_LoadWAV("src/Sik/Attakmeduz.WAV");
    son->depmeduse= Mix_LoadWAV("src/Sik/depMeduz.WAV");
    son->degatmeduse= Mix_LoadWAV("src/Sik/degatMeduz.WAV");
    son->mortmeduse= Mix_LoadWAV("src/Sik/MortMeduz.WAV");
    son->mortchauvesouris= Mix_LoadWAV("src/Sik/MortChS.WAV");
    son->attaqueboss= Mix_LoadWAV("src/Sik/attakBossM.WAV");
    son->mortboss= Mix_LoadWAV("src/Sik/Mortboss.WAV");
    son->degatboss= Mix_LoadWAV("src/Sik/degatBoss.WAV");
    son->porte= Mix_LoadWAV("src/Sik/porte.WAV");
    son->gameoverson= Mix_LoadWAV("src/Sik/GameOver.WAV");
}

void SelectNiv (Joueur *joueur, Lvl *lvl, Monstre *monstre, EffetSon *son)
{
    if(lvl->Num==0)
    {   
        Mix_PauseMusic();
        LoadNiv1(&monstre->meduse, lvl, joueur);
        Mix_PlayMusic(son ->musiquelvl, -1);
    }
    if(lvl->Num==1)
    {
        LoadNiv2(&monstre->meduse, &monstre->meduse1, &monstre->meduse2, lvl, joueur);
    }
    if(lvl->Num==2)
    {
         LoadNiv3(&monstre->meduse, &monstre->meduse1, &monstre->chauvesouris , &monstre->chauvesouris1, lvl, joueur);
    }
    if(lvl->Num==3)
    {   Mix_PauseMusic();
        loadNiv4 (joueur, &monstre->boss, lvl);
        Mix_PlayMusic(son ->musiqueboss, -1);
    }
    lvl->MortMonstre=0;
}

void GestionMonstre (Monstre* monstre, Lvl *lvl, Input *input, Joueur *joueur, EffetSon *son)
{
    if(lvl->Num==0)
    {
        deplacementMeduse(joueur, &monstre->meduse, lvl, son);
        collision(joueur, &monstre->meduse, input, lvl);
        collisionmur (joueur);
    }
    if(lvl->Num==1)
    {   
        collisionmur (joueur);
        deplacementMeduse(joueur, &monstre->meduse, lvl, son);
        deplacementMeduse(joueur, &monstre->meduse1, lvl, son);
        deplacementMeduse(joueur, &monstre->meduse2, lvl, son);
        collision(joueur, &monstre->meduse, input,lvl);
        collision(joueur, &monstre->meduse1, input, lvl);
        collision(joueur, &monstre->meduse2, input, lvl
        );
    }
    if(lvl->Num==2)
    {   
        collisionmur (joueur);
        deplacementMeduse(joueur, &monstre->meduse, lvl, son);
        deplacementMeduse(joueur, &monstre->meduse1, lvl, son);
        deplacementChauvesouris(joueur,&monstre->chauvesouris, lvl, son);
        deplacementChauvesouris(joueur, &monstre->chauvesouris1, lvl, son);
        collision(joueur, &monstre->meduse, input, lvl);
        collision(joueur, &monstre->meduse1, input, lvl);
        collision(joueur, &monstre->meduse2, input, lvl);
    }
    if (lvl->Num==3)
    {   
        collisionmur (joueur);
        collisionboss(joueur, &monstre->boss, input, lvl);
        deplacementBoss(joueur, &monstre->boss, lvl, input,son);
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

void loadNiv4 (Joueur *joueur,Boss *boss, Lvl *lvl)
{
    initMaps(lvl);
    joueur->inposx = level[3][0][2];
    joueur->inposy = level[3][0][3];
    boss->posmonsx =level[3][1][1];
    boss->posmonsy =level[3][1][2];
    boss->Life=level [3][1][5];
}

void cleanup(EffetSon *son)
{
    Mix_FreeMusic(son->musiquemenu); //Libération de la musique
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

void initEclair(Boss *boss)
{
    boss->Ex1= rand() % (SCREEN_WIDTH-50)+25;
    boss->Ey1= rand() % (SCREEN_HEIGHT-50)+25;
    boss->Ex2= rand() % (SCREEN_WIDTH-50)+25;
    boss->Ey2= rand() % (SCREEN_HEIGHT-50)+25;
    boss->Ex3= rand() % (SCREEN_WIDTH-50)+25;
    boss->Ey3= rand() % (SCREEN_HEIGHT-50)+25;
    boss->Ex4= rand() % (SCREEN_WIDTH-50)+25;
    boss->Ey4= rand() % (SCREEN_HEIGHT-50)+25;
}