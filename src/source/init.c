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
                                  SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
 
    //On crée un renderer pour la SDL et on active la synchro verticale : VSYNC
    renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_PRESENTVSYNC);
 
    // revoie erreur
    if (screen == NULL || renderer == NULL)
    {
        printf("Impossible d'initialiser le mode écran à %d x %d: %s\n", SCREEN_WIDTH,SCREEN_HEIGHT, SDL_GetError());
        exit(1);
    }
 
    //Initialisation du chargement des images png avec SDL_Image 2
    // int imgFlags = IMG_INIT_PNG;
    // if( !( IMG_Init( imgFlags ) & imgFlags ) )
    // {
    //     printf( "SDL_image n'a pu être initialisée! SDL_image Error: %s\n", IMG_GetError() );
    //     exit(1);
    // }
 
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
    son ->musiqueMapG = Mix_LoadMUS("src/Sik/MapGlobal.mp3");
    son->musiqueshop= Mix_LoadMUS("src/Sik/m_Shop.mp3");

    Mix_PlayMusic(son ->musiquemenu, -1); //Jouer infiniment la musique
    Mix_Volume(1, MIX_MAX_VOLUME/4); //Mettre à mi-volume le post 1
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
    son->coffre= Mix_LoadWAV("src/Sik/OuvertureCoffre.WAV");
}

void Texte(ParamTexte *paramtexte)
{
    paramtexte->Font = TTF_OpenFont("src/font/Pixel.ttf", 25);
}

void SelectNiv (Joueur *joueur, Lvl *lvl, Monstre *monstre, EffetSon *son)
{
    if(lvl->Num == 0)
    {   
        LoadNiv11(&monstre->meduse, lvl, joueur);
        Mix_PlayMusic(son ->musiquelvl, -1);
    }
    if(lvl->Num == 1)
    {   
        joueur->AttPiece+=1;
        LoadNiv12(&monstre->meduse, &monstre->meduse1, &monstre->meduse2, lvl, joueur);
    }
    if(lvl->Num == 2)
    {   
        joueur->AttPiece+=1;
        LoadNiv13(&monstre->meduse, &monstre->meduse1, &monstre->chauvesouris , &monstre->chauvesouris1, lvl, joueur);
    }
    if(lvl->Num == 3)
    {   
        joueur->AttPiece+=1;
        loadNiv14 (joueur, &monstre->boss, lvl);
        Mix_PlayMusic(son ->musiqueboss, -1);
    }
    if (lvl->Num == 4)
    {
        loadNiv21(joueur, lvl);
        Mix_PlayMusic(son ->musiqueshop, -1);
    }
    if (lvl->Num == 5)
    {
        loadNiv31(joueur, &monstre->yeti, lvl);
    }
    if  (lvl->Num == 6)
    {
        loadNiv32(joueur, &monstre->yeti, &monstre->yeti1, &monstre->yeti2, lvl);
    }
    if (lvl->Num == 9)
    {
        loadNiv41(joueur,lvl);
    }
    
    lvl->MortMonstre=0;
}

void GestionMonstre (Monstre* monstre, Lvl *lvl, Input *input, Joueur *joueur, EffetSon *son)
{
    if(lvl->Num==0)
    {
        deplacementMeduse(joueur, &monstre->meduse, lvl, son);
        collisionmur (joueur,20,20,20,20);
        collision(joueur, &monstre->meduse, input, lvl);
    }
    if(lvl->Num==1)
    {   
        collisionmur (joueur,20,20,20,20);
        deplacementMeduse(joueur, &monstre->meduse, lvl, son);
        deplacementMeduse(joueur, &monstre->meduse1, lvl, son);
        deplacementMeduse(joueur, &monstre->meduse2, lvl, son);
        collision(joueur, &monstre->meduse, input,lvl);
        collision(joueur, &monstre->meduse1, input, lvl);
        collision(joueur, &monstre->meduse2, input, lvl);
    }
    if(lvl->Num==2)
    {   
        collisionmur (joueur,20,20,20,20);
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
        collisionmur (joueur,20,20,20,20);
        collisionboss(joueur, &monstre->boss, input, lvl);
        deplacementBoss(joueur, &monstre->boss, lvl, input,son);
    }
    if (lvl->Num==4)
    {
        collisionmur(joueur,20,20,20,20);
        //Table
        collisionDecor(joueur, input,223,415,120,55);
        //jermy
        collisionDecor(joueur, input,465,530,283,210);
        //Bec
        collisionDecor(joueur, input,80,220,320,240);
        GestionMarchands(joueur, input, &monstre->marchand, lvl);
    }   
    if (lvl -> Num == 5)
    {
        collisionmur(joueur,20,20,20,20);
        collisionyeti (joueur, &monstre->yeti, input, lvl);
        deplacementyeti(joueur,&monstre->yeti, lvl, son);
        if (lvl->MortMonstre==level[5][0][1] && lvl->WinDonjon<=2)
        {
            printf("aaa");
            GestionMarchands(joueur, input, &monstre->marchand, lvl);
            //jermy
            collisionDecor(joueur, input,465,530,283,210);
        }
        
    }
    if (lvl->Num == 6)
    {
        collisionmur(joueur,20,20,20,20);
        collisionyeti (joueur, &monstre->yeti, input, lvl);
        deplacementyeti(joueur,&monstre->yeti, lvl, son);
        collisionyeti (joueur, &monstre->yeti1, input, lvl);
        collisionyeti (joueur, &monstre->yeti2, input, lvl);
        deplacementyeti(joueur,&monstre->yeti1, lvl, son);
        deplacementyeti(joueur,&monstre->yeti2, lvl, son);
    }
    if (lvl->Num == 9)
    {
        collisionmur(joueur,0,110,30,400);
        GestionMarchands(joueur,input,&monstre->marchand,lvl);
    }
    
    
    
}

void LoadNiv11(Meduse *meduse, Lvl *lvl, Joueur *joueur)
{  
    initMaps(lvl);
    joueur->inposx = level[0][0][2];
    joueur->inposy = level[0][0][3];
    meduse->posmonsx =level[0][1][1];
    meduse->posmonsy =level[0][1][2];
    meduse->Life=level[0][1][5];
}

void LoadNiv12(Meduse *meduse,Meduse *meduse1,Meduse *meduse2 , Lvl *lvl, Joueur *joueur)
{       
    // SDL_RenderClear(renderer);
    // SDL_RenderPresent(renderer);
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

void LoadNiv13(Meduse *meduse, Meduse *meduse1, Chauvesouris *chauvesouris, Chauvesouris *chauvesouris1, Lvl *lvl, Joueur *joueur)
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
    chauvesouris->CompteurSpriteDegat=0;
    chauvesouris1->posmonsx =level[2][4][1];
    chauvesouris1->posmonsy =level[2][4][2];
    chauvesouris1->Life=level[2][4][5];
    chauvesouris1->CompteurSpriteDegat=0;
}

void loadNiv14 (Joueur *joueur,Boss *boss, Lvl *lvl)
{
    initMaps(lvl);
    joueur->inposx = level[3][0][2];
    joueur->inposy = level[3][0][3];
    boss->posmonsx =level[3][1][1];
    boss->posmonsy =level[3][1][2];
    boss->Life=level [3][1][5];
}

void loadNiv21 (Joueur *joueur, Lvl* lvl)
{
    initMaps(lvl);
    joueur->inposx = level[4][0][2];
    joueur->inposy = level[4][0][3];
}

void loadNiv31 (Joueur *joueur,Yeti *yeti, Lvl *lvl)
{
    initMaps(lvl);
    joueur->inposx = level[5][0][2];
    joueur->inposy = level[5][0][3];
    yeti->posmonsx =level[5][1][1];
    yeti->posmonsy =level[5][1][2];
    yeti->Life=level [5][1][5];
}

void loadNiv32 (Joueur *joueur, Yeti *yeti, Yeti *yeti1, Yeti *yeti2, Lvl *lvl)
{
    initMaps(lvl);
    joueur->inposx= level [6][0][2];
    joueur->inposy= level [6][0][3];
    yeti->posmonsx =level[6][1][1];
    yeti->posmonsy =level[6][1][2];
    yeti->Life=level [6][1][5];
    yeti1->posmonsx =level[6][2][1];
    yeti1->posmonsy =level[6][2][2];
    yeti1->Life=level [6][2][5];
    yeti1->compteur= level [6][2][3];
    yeti2->posmonsx =level[6][3][1];
    yeti2->posmonsy =level[6][3][2];
    yeti2->Life=level [6][3][5];
    yeti2->compteur = level [6][3][3];
}

void loadNiv41(Joueur *Joueur, Lvl *lvl)
{
    initMaps(lvl);
    Joueur->inposx = level[8][0][2];
    Joueur->inposy = level[8][0][3];
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
    //On quitte SDL_TTF 2
    //TTF_Quit();
 
    //On quitte la SDL
    SDL_Quit();
}

void initEclair(Boss *boss)
{
    boss->Ex1= rand() % (SCREEN_WIDTH-100)+50;
    boss->Ey1= rand() % (SCREEN_HEIGHT-100)+50;
    boss->Ex2= rand() % (SCREEN_WIDTH-100)+50;
    boss->Ey2= rand() % (SCREEN_HEIGHT-100)+50;
    boss->Ex3= rand() % (SCREEN_WIDTH-100)+50;
    boss->Ey3= rand() % (SCREEN_HEIGHT-100)+50;
    boss->Ex4= rand() % (SCREEN_WIDTH-100)+50;
    boss->Ey4= rand() % (SCREEN_HEIGHT-100)+50;
}