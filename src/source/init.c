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
    son->musiquemenu = Mix_LoadMUS("src/musique/m_menu.mp3"); //Chargement de la musique
    son->musiqueboss = Mix_LoadMUS("src/musique/m_Boss.mp3");
    son->musiquelvl = Mix_LoadMUS("src/musique/MusiqueLvl.mp3");
    son ->musiqueMapG = Mix_LoadMUS("src/musique/MapGlobal.mp3"); 
    son->musiqueshop= Mix_LoadMUS("src/musique/m_Shop.mp3");
    son->musiqueriviere= Mix_LoadMUS("src/musique/m_riviere.mp3");
    son->musiqueyeti= Mix_LoadMUS("src/musique/m_yeti.mp3");
    Mix_VolumeMusic(40);
    Mix_PlayMusic(son ->musiquemenu, -1); //Jouer infiniment la musique
    son->epee = Mix_LoadWAV("src/musique/attackChe.WAV"); //Charger un wav dans un pointeur
    son->bouclier= Mix_LoadWAV("src/musique/BouclierChe.WAV");
    son->depchevalier= Mix_LoadWAV("src/musique/deplacementchevalier.WAV");
    son->degatchevalier= Mix_LoadWAV("src/musique/degatChe.WAV");
    son->mortchevalier= Mix_LoadWAV("src/musique/mortChe.WAV");
    son->lowlifechevalier= Mix_LoadWAV("src/musique/onelifeChe.WAV");
    son->attaquemeduse= Mix_LoadWAV("src/musique/Attakmeduz.WAV");
    son->depmeduse= Mix_LoadWAV("src/musique/depMeduz.WAV");
    son->degatmeduse= Mix_LoadWAV("src/musique/degatMeduz.WAV");
    son->mortmeduse= Mix_LoadWAV("src/musique/MortMeduz.WAV");
    son->mortchauvesouris= Mix_LoadWAV("src/musique/MortChS.WAV");
    son->attaqueboss= Mix_LoadWAV("src/musique/attakBossM.WAV");
    son->mortboss= Mix_LoadWAV("src/musique/Mortboss.WAV");
    son->degatboss= Mix_LoadWAV("src/musique/degatBoss.WAV");
    son->porte= Mix_LoadWAV("src/musique/porte.WAV");
    son->gameoverson= Mix_LoadWAV("src/musique/GameOver.WAV");
    son->coffre= Mix_LoadWAV("src/musique/OuvertureCoffre.WAV");
    son->attaqueyeti= Mix_LoadWAV("src/musique/AttaqueYeti.WAV");
    son->mortyeti= Mix_LoadWAV("src/musique/MortYeti.WAV");
    son->degatyeti= Mix_LoadWAV("src/musique/DegatYeti.WAV");
    son->bouledeneige= Mix_LoadWAV("src/musique/BouleDeNeige.WAV");
    son->dague= Mix_LoadWAV("src/musique/Dague.WAV");
    son->Jerem= Mix_LoadWAV("src/musique/Jerem.wav");
    son->JeremDamm= Mix_LoadWAV("src/musique/damm.wav");
    son->dagueLancer = Mix_LoadWAV("src/musique/Dague_lancer.wav");
    son->collisionR = Mix_LoadWAV("src/musique/CollisionR.WAV");
    }

void Texte(ParamTexte *paramtexte)
{
    paramtexte->Font = TTF_OpenFont("src/font/Pixel.ttf", 25);
}

void SelectNiv (Joueur *joueur, Lvl *lvl, Entité *entité, EffetSon *son)
{
    if(lvl->Num == 0)
    {   
        LoadNiv11(&entité->meduse, lvl, joueur);
        Mix_PlayMusic(son ->musiquelvl, -1);
    }
    if(lvl->Num == 1)
    {   
        joueur->AttPiece+=1;
        LoadNiv12(&entité->meduse, &entité->meduse1, &entité->meduse2, lvl, joueur);
    }
    if(lvl->Num == 2)
    {   
        joueur->AttPiece+=1;
        LoadNiv13(&entité->meduse, &entité->meduse1, &entité->chauvesouris , &entité->chauvesouris1, lvl, joueur);
    }
    if(lvl->Num == 3)
    {   
        joueur->AttPiece+=1;
        loadNiv14 (joueur, &entité->boss, lvl);
        Mix_PlayMusic(son ->musiqueboss, -1);
    }
    if (lvl->Num == 4)
    {
        loadNiv21(joueur, lvl);
        Mix_PlayMusic(son ->musiqueshop, -1);
    }
    if (lvl->Num == 5)
    {
        loadNiv31(joueur, &entité->yeti, lvl);
        Mix_PlayMusic(son->musiqueyeti,-1);
    }
    if  (lvl->Num == 6)
    {
        loadNiv32(joueur, &entité->yeti, &entité->yeti1, &entité->yeti2, lvl);
    }
    if (lvl->Num == 7)
    {
        loadNiv33(joueur,&entité->yeti,&entité->yeti1,lvl,&entité->chauvesouris,&entité->chauvesouris1);
    }

    if (lvl->Num == 8)
    {
        loadNiv34(joueur,&entité->bossyeti,lvl);
    }
    
    if (lvl->Num == 9)
    {
        loadNiv41(joueur,lvl);
        Mix_PlayMusic(son->musiqueriviere,-1);
    }
    if (lvl->Num == 10)
    {
        loadNiv42(joueur,&entité->Petit_rocher, &entité->Gros_rocher,&entité->tronc,&entité->tanguy,lvl);
    }
    if (joueur->Edague==2)
    {
        joueur->nbDague=0;
    }
    
    lvl->MortMonstre=0;
}

void GestionMonstre (Entité* entité, Lvl *lvl, Input *input, Joueur *joueur, EffetSon *son)
{
    if(lvl->Num==0)
    {
        deplacementMeduse(joueur, &entité->meduse, lvl, son);
        collisionmur (joueur,20,20,20,20);
        collision(joueur, &entité->meduse, input, lvl);
    }
    if(lvl->Num==1)
    {   
        collisionmur (joueur,20,20,20,20);
        deplacementMeduse(joueur, &entité->meduse, lvl, son);
        deplacementMeduse(joueur, &entité->meduse1, lvl, son);
        deplacementMeduse(joueur, &entité->meduse2, lvl, son);
        collision(joueur, &entité->meduse, input,lvl);
        collision(joueur, &entité->meduse1, input, lvl);
        collision(joueur, &entité->meduse2, input, lvl);
    }
    if(lvl->Num==2)
    {   
        collisionmur (joueur,20,20,20,20);
        deplacementMeduse(joueur, &entité->meduse, lvl, son);
        deplacementMeduse(joueur, &entité->meduse1, lvl, son);
        deplacementChauvesouris(joueur,&entité->chauvesouris, lvl, son);
        deplacementChauvesouris(joueur, &entité->chauvesouris1, lvl, son);
        collision(joueur, &entité->meduse, input, lvl);
        collision(joueur, &entité->meduse1, input, lvl);
    }
    if (lvl->Num==3)
    {   
        collisionmur (joueur,20,20,20,20);
        collisionboss(joueur, &entité->boss, input, lvl);
        deplacementBoss(joueur, &entité->boss, lvl, input,son);
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
        GestionMarchands(joueur, input, &entité->marchand, lvl,son);
    }   
    if (lvl -> Num == 5)
    {
        collisionmur(joueur,20,20,20,20);
        collisionyeti (joueur, &entité->yeti, input, lvl);
        deplacementyeti(joueur,&entité->yeti, lvl, son);
        if (lvl->MortMonstre==level[5][0][1] && lvl->WinDonjon<=2)
        {
            GestionMarchands(joueur, input, &entité->marchand, lvl,son);
            //jermy
            collisionDecor(joueur, input,465,530,283,210);
        }
        
    }
    if (lvl->Num == 6)
    {
        collisionmur(joueur,20,20,20,20);
        collisionyeti (joueur, &entité->yeti, input, lvl);
        deplacementyeti(joueur,&entité->yeti, lvl, son);
        collisionyeti (joueur, &entité->yeti1, input, lvl);
        collisionyeti (joueur, &entité->yeti2, input, lvl);
        deplacementyeti(joueur,&entité->yeti1, lvl, son);
        deplacementyeti(joueur,&entité->yeti2, lvl, son);
    }
    if (lvl->Num == 7)
    {
        collisionmur (joueur,20,20,20,20);
        deplacementyeti(joueur, &entité->yeti, lvl, son);
        deplacementyeti(joueur, &entité->yeti1, lvl, son);
        deplacementChauvesouris(joueur,&entité->chauvesouris, lvl, son);
        deplacementChauvesouris(joueur, &entité->chauvesouris1, lvl, son);
        collisionyeti(joueur, &entité->yeti, input, lvl);
        collisionyeti(joueur, &entité->yeti1, input, lvl);
    }

    if (lvl->Num == 8)
    {
        collisionmur (joueur,20,20,20,20);
        deplacementbossyeti(joueur, &entité->bossyeti,lvl,son);
        collisionbossyeti(joueur,&entité->bossyeti,input,lvl);
    }
    
    if (lvl->Num == 9)
    {
        if (joueur->Ebateau<2)
        {
            collisionmur(joueur,0,110,30,400);
        }
        else
        {
            collisionmur(joueur,267,35,0,0);
        }
        GestionMarchands(joueur,input,&entité->marchand,lvl,son);
    }
    if (lvl->Num ==10)
    {   
        if (lvl->Avancement10<13)
        {
            collisionmur(joueur,20,40,0,10);
        }
        else if(lvl->Avancement10==13 && joueur->Ebateau!=2)
        {
            collisionmur(joueur,0,114,400,60);
        }
        Gestion_Obstacle(joueur,&entité->marchand,&entité->Petit_rocher,&entité->Gros_rocher,&entité->tronc,&entité->tanguy, lvl, son);
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

void loadNiv33 (Joueur *joueur, Yeti *yeti, Yeti *yeti1, Lvl *lvl, Chauvesouris *chauvesouris, Chauvesouris *chauvesouris1)
{
    initMaps(lvl);
    joueur->inposx= level [7][0][2];
    joueur->inposy= level [7][0][3];
    yeti->posmonsx =level[7][1][1];
    yeti->posmonsy =level[7][1][2];
    yeti->Life=level [7][1][5];
    yeti1->posmonsx =level[7][2][1];
    yeti1->posmonsy =level[7][2][2];
    yeti1->Life=level [7][2][5];
    yeti1->compteur= level [7][2][3];
    chauvesouris->posmonsx =level[7][3][1];
    chauvesouris->posmonsy =level[7][3][2];
    chauvesouris->Life=level[7][3][5];
    chauvesouris->CompteurSpriteDegat=0;
    chauvesouris1->posmonsx =level[7][4][1];
    chauvesouris1->posmonsy =level[7][4][2];
    chauvesouris1->Life=level[7][4][5];
    chauvesouris1->CompteurSpriteDegat=0;
}

void loadNiv34 (Joueur *joueur, BossYeti *bossyeti,Lvl *lvl)
{
    initMaps(lvl);
    joueur->inposx= level [8][0][2];
    joueur->inposy= level [8][0][3];
    bossyeti->posmonsx =level[8][1][1];
    bossyeti->posmonsy =level[8][1][2];
    bossyeti->Life=level [8][1][5];
  
}

void loadNiv41(Joueur *Joueur, Lvl *lvl)
{
    initMaps(lvl);
    Joueur->inposx = level[9][0][2];
    Joueur->inposy = level[9][0][3];
}

void loadNiv42(Joueur *joueur,Obstacle *Petit_rocher,Obstacle *Gros_rocher,Obstacle *tronc,Obstacle *tanguy, Lvl *lvl)
{
    initMaps(lvl);
    joueur->inposx = level[10][0][2];
    joueur->inposy = level[10][0][3];
    Petit_rocher->x = 1150;
    Petit_rocher->y = 72;
    Gros_rocher->x = 640;
    Gros_rocher->y = 160;
    tronc->x = 640;
    tronc->y = 270;
    tanguy->x = -70;
    tanguy->y = 180;
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

void Save(Joueur *joueur,Lvl *lvl, Input *input, Entité *entité, EffetSon *son)
{
    //entrer pause
    if (input->echap == 1 && lvl->Num != -2)
    {
        lvl->temp = lvl->Num;
        lvl->Num = -2;
    }
    //sortie pause
    if (input->enter == 1 && lvl->Num == -2)
    {
        lvl->Num = lvl->temp;
    }

    if (lvl->Num == -2)
    {
        char* nomFichier = "src/Save.txt";
        FILE* fichier = fopen ( nomFichier , "r+" );
        if ( fichier )
        {
            printf ("Le fichier %s a pu etre ouvert en ecriture.\n", nomFichier);
            if (input->yes == 1)
            {
                fprintf(fichier,"life=%d AttPice=%d NbPiece=%d WinDonjon=%d nbDague=%d",joueur->life,joueur->AttPiece,joueur->NbPiece,lvl->WinDonjon,joueur->nbDague);
                fclose(fichier);
                exit(0);
            }
            if (input->no == 1)
            {
                fclose(fichier);
                lvl->Num = lvl->temp;
            }
            
            
        }
    }   
}

void chargement (Joueur *joueur, Lvl *lvl)
{
    char* nomFichier = "src/Save.txt";
    FILE* fichier = fopen ( nomFichier , "r+" );
    if ( fichier )
    {
        printf ("Le fichier %s a pu etre ouvert en ecriture.\n", nomFichier);
        fscanf(fichier,"life=%d AttPice=%d NbPiece=%d WinDonjon=%d nbDague=%d",&joueur->life,&joueur->AttPiece,&joueur->NbPiece,&lvl->WinDonjon,&joueur->nbDague);
        fclose (fichier);
    }
    else
    {
        printf("ya r");
    }
}