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
                                  SDL_WINDOW_SHOWN );
 
    //On crée un renderer pour la SDL et on active la synchro verticale : VSYNC
    renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_PRESENTVSYNC);
 
    // revoie erreur
    if (screen == NULL || renderer == NULL)
    {
        printf("Impossible d'initialiser le mode écran à %d x %d: %s\n", SCREEN_WIDTH,SCREEN_HEIGHT, SDL_GetError());
        exit(1);
    }
 
    //Initialisation du Load_Game des images png avec SDL_Image 2
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
    son->musiquebossyeti = Mix_LoadMUS("src/musique/m_BossYeti.mp3");
    son->musiquelvl = Mix_LoadMUS("src/musique/MusiqueLvl.mp3");
    son ->musiqueMapG = Mix_LoadMUS("src/musique/MapGlobal.mp3"); 
    son->musiqueshop= Mix_LoadMUS("src/musique/m_Shop.mp3");
    son->musiqueriviere= Mix_LoadMUS("src/musique/m_riviere.mp3");
    son->musiqueyeti= Mix_LoadMUS("src/musique/m_yeti.mp3");
    son->musiquebossjermy= Mix_LoadMUS("src/musique/m_BossJerem.mp3");
    son->win= Mix_LoadMUS("src/musique/win.mp3");
    Mix_VolumeMusic(40);
    Mix_PlayMusic(son ->musiquemenu, -1); //Jouer infiniment la musique
    son->epee = Mix_LoadWAV("src/musique/attackChe2.WAV"); //Charger un wav dans un pointeur
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
    son->attaquebossyeti= Mix_LoadWAV("src/musique/AttaqueBossYeti.WAV");
    son->caisse= Mix_LoadWAV("src/musique/Caisse.WAV");
    son->cranemur= Mix_LoadWAV("src/musique/Cranemur.WAV");
    son->degatbossyeti= Mix_LoadWAV("src/musique/DegatBossYeti.WAV");
    son->solbossyeti= Mix_LoadWAV("src/musique/BossYetiSol.WAV");
    son->fissure= Mix_LoadWAV("src/musique/fissure.WAV");
    son->mortbossyeti= Mix_LoadWAV("src/musique/mortbossyeti.WAV");
    son->etourdissement= Mix_LoadWAV("src/musique/Etourdissements.WAV");
    son->jeff= Mix_LoadWAV("src/musique/Jeff.WAV");
    son->karine= Mix_LoadWAV("src/musique/Karine.WAV");
    son->tanguy= Mix_LoadWAV("src/musique/Tanguy.WAV");
    son->degatsquelette= Mix_LoadWAV("src/musique/degatsq.WAV");
    son->mortsquelette= Mix_LoadWAV("src/musique/MortSquelette.WAV");
    son->attaquesquelette= Mix_LoadWAV("src/musique/attackSq.WAV");
    son->rebond= Mix_LoadWAV("src/musique/rebond.WAV");
    son->bullesq= Mix_LoadWAV("src/musique/voixsq.WAV");
    son->attackJerem= Mix_LoadWAV("src/musique/attackJerem.WAV");
    son->degatjerem= Mix_LoadWAV("src/musique/degatjerem.WAV");
    son->sautjerem= Mix_LoadWAV("src/musique/saut.WAV");
    son->haltere= Mix_LoadWAV("src/musique/haltere.WAV");
    }

void Texte(ParamTexte *paramtexte)
{
    paramtexte->Font = TTF_OpenFont("src/font/Pixel.ttf", 25);
    paramtexte->Fontpetite = TTF_OpenFont("src/font/Pixel.ttf", 15);
}

void Select_Level (Joueur *joueur, Lvl *lvl, Entité *entité, EffetSon *son)
{
    if (lvl->Map != NULL)
    {
        SDL_DestroyTexture(lvl->Map);
        lvl->Map = NULL;
    }
    if (lvl->MapSlide != NULL)
    {
        SDL_DestroyTexture(lvl->MapSlide);
        lvl->MapSlide = NULL;
    }

    if(lvl->Num == 0)
    {   
        Load_Level_1_1(&entité->meduse, lvl, joueur);
        Mix_PlayMusic(son ->musiquelvl, -1);
    }
    if(lvl->Num == 1)
    {   
        joueur->AttPiece+=1;
        Load_Level_1_2(&entité->meduse, &entité->meduse1, &entité->meduse2, lvl, joueur);
    }
    if(lvl->Num == 2)
    {   
        joueur->AttPiece+=1;
        Load_Level_1_3(&entité->meduse, &entité->meduse1, &entité->chauvesouris , &entité->chauvesouris1, lvl, joueur);
    }
    if(lvl->Num == 3)
    {   
        joueur->AttPiece+=1;
        Load_Level_1_4 (joueur, &entité->boss, lvl);
        Mix_PlayMusic(son ->musiqueboss, -1);
    }
    if (lvl->Num == 4)
    {
        Load_Level_2_1(joueur, lvl);
        Mix_PlayMusic(son ->musiqueshop, -1);
    }
    if (lvl->Num == 5)
    {
        Load_Level_3_1(joueur, &entité->yeti, lvl);
        Mix_PlayMusic(son->musiqueyeti,-1);
    }
    if  (lvl->Num == 6)
    {
        joueur->AttPiece+=1;
        Load_Level_3_2(joueur, &entité->yeti, &entité->yeti1, &entité->yeti2, lvl);
    }
    if (lvl->Num == 7)
    {
        joueur->AttPiece+=1;
        Load_Level_3_3(joueur,&entité->yeti,&entité->yeti1,lvl,&entité->chauvesouris,&entité->chauvesouris1);
    }

    if (lvl->Num == 8)
    {
        joueur->AttPiece+=1;
        Load_Level_3_4(joueur,&entité->bossyeti,lvl);
        Mix_PlayMusic(son ->musiquebossyeti, -1);
    }
    
    if (lvl->Num == 9)
    {
        Load_Level_4_1(joueur,lvl);
        Mix_PlayMusic(son->musiqueriviere,-1);
    }
    if (lvl->Num == 10)
    {
        Load_Level_4_2(joueur,&entité->Petit_rocher, &entité->Gros_rocher,&entité->tronc,&entité->tanguy,lvl);
    }
    if (lvl->Num == 11)
    {
        joueur->AttPiece+=1;
        Load_Level_5_1(joueur,lvl,&entité->squelette1,&entité->squelette);
        Mix_PlayMusic(son->musiquelvl,-1);
    }
    if (lvl->Num == 12)
    {
        joueur->AttPiece+=1;
        Load_Level_5_2(joueur,&entité->squelette,&entité->squelette1,&entité->chauvesouris,&entité->chauvesouris1,lvl); 
    }
    if (lvl->Num == 13)
    {
        Load_Level_5_3(joueur,&entité->jerem,lvl);
        Mix_PlayMusic(son->musiquebossjermy,-1);
    }
    if (joueur->Edague==2)
    {
        joueur->nbDague=0;
    }
    
    
    
    lvl->MortMonstre=0;
}

void Gestion_Entité (Entité* entité, Lvl *lvl, Input *input, Joueur *joueur, EffetSon *son)
{
    if(lvl->Num==0)
    {
        Deplacement_Meduse(joueur, &entité->meduse, lvl, son);
        Collision_Mur (joueur,20,20,20,20, lvl);
        Collision_Meduse(joueur, &entité->meduse, input, lvl);
    }
    if(lvl->Num==1)
    {   
        Collision_Mur (joueur,20,20,20,20, lvl);
        Deplacement_Meduse(joueur, &entité->meduse, lvl, son);
        Deplacement_Meduse(joueur, &entité->meduse1, lvl, son);
        Deplacement_Meduse(joueur, &entité->meduse2, lvl, son);
        Collision_Meduse(joueur, &entité->meduse, input,lvl);
        Collision_Meduse(joueur, &entité->meduse1, input, lvl);
        Collision_Meduse(joueur, &entité->meduse2, input, lvl);
    }
    if(lvl->Num==2)
    {   
        Collision_Mur (joueur,20,20,20,20,lvl);
        Deplacement_Meduse(joueur, &entité->meduse, lvl, son);
        Deplacement_Meduse(joueur, &entité->meduse1, lvl, son);
        Deplacement_Chauvesouris(joueur,&entité->chauvesouris, lvl, son);
        Deplacement_Chauvesouris(joueur, &entité->chauvesouris1, lvl, son);
        Collision_Meduse(joueur, &entité->meduse, input, lvl);
        Collision_Meduse(joueur, &entité->meduse1, input, lvl);
    }
    if (lvl->Num==3)
    {   
        Collision_Mur (joueur,20,20,20,20,lvl);
        Collision_Boss_Meduse(joueur, &entité->boss, input, lvl);
        Deplacement_Boss_Meduse(joueur, &entité->boss, lvl, input,son);
    }
    if (lvl->Num==4)
    {
        Collision_Mur(joueur,20,20,20,20,lvl);
        //Table
        Collision_Decor(joueur, input,223,415,120,55);
        //jermy
        Collision_Decor(joueur, input,465,530,283,210);
        //Bec
        Collision_Decor(joueur, input,80,220,320,240);
        Gestion_Marchands(joueur, input, &entité->marchand, lvl,son);
    }   
    if (lvl -> Num == 5)
    {
        Collision_Mur(joueur,20,20,20,20,lvl);
        Collision_Yeti (joueur, &entité->yeti, input, lvl);
        Deplacement_Yeti(joueur,&entité->yeti, lvl, son);
        if (lvl->MortMonstre==level[5][0][1] && lvl->WinDonjon<=2)
        {
            Gestion_Marchands(joueur, input, &entité->marchand, lvl,son);
            //jermy
            Collision_Decor(joueur, input,465,530,283,210);
        }
        
    }
    if (lvl->Num == 6)
    {
        Collision_Mur(joueur,20,20,20,20,lvl);
        Collision_Yeti (joueur, &entité->yeti, input, lvl);
        Deplacement_Yeti(joueur,&entité->yeti, lvl, son);
        Collision_Yeti (joueur, &entité->yeti1, input, lvl);
        Collision_Yeti (joueur, &entité->yeti2, input, lvl);
        Deplacement_Yeti(joueur,&entité->yeti1, lvl, son);
        Deplacement_Yeti(joueur,&entité->yeti2, lvl, son);
    }
    if (lvl->Num == 7)
    {
        Collision_Mur (joueur,20,20,20,20, lvl);
        Deplacement_Yeti(joueur, &entité->yeti, lvl, son);
        Deplacement_Yeti(joueur, &entité->yeti1, lvl, son);
        Deplacement_Chauvesouris(joueur,&entité->chauvesouris, lvl, son);
        Deplacement_Chauvesouris(joueur, &entité->chauvesouris1, lvl, son);
        Collision_Yeti(joueur, &entité->yeti, input, lvl);
        Collision_Yeti(joueur, &entité->yeti1, input, lvl);
    }

    if (lvl->Num == 8)
    {
        Collision_Mur (joueur,20,20,20,20,lvl);
        Deplacement_Boss_Yeti(joueur, &entité->bossyeti,lvl,son);
        Collision_Boss_Yeti(joueur,&entité->bossyeti,input,lvl);
    }
    
    if (lvl->Num == 9)
    {
        if (joueur->Ebateau<2)
        {
            Collision_Mur(joueur,0,110,30,400,lvl);
        }
        else
        {
            Collision_Mur(joueur,267,35,0,0,lvl);
        }
        Gestion_Marchands(joueur,input,&entité->marchand,lvl,son);
    }
    if (lvl->Num ==10)
    {   
        if (lvl->Avancement10<13)
        {
            Collision_Mur(joueur,30,40,0,10,lvl);
        }
        else if(lvl->Avancement10==13 && joueur->Ebateau ==2)
        {
            Collision_Mur(joueur,267,35,0,0,lvl);
        }
        else if(lvl->Avancement10==13 && joueur->Ebateau!=2)
        {
            Collision_Mur(joueur,0,114,400,60,lvl);
        }
        Gestion_Obstacle(joueur,&entité->marchand,&entité->Petit_rocher,&entité->Gros_rocher,&entité->tronc,&entité->tanguy, lvl, son);
    }
    if (lvl->Num == 11)
    {
        Collision_Mur(joueur,20,20,20,20,lvl);
        Deplacement_Squelette(joueur,&entité->squelette,lvl,son);
        Deplacement_Squelette(joueur,&entité->squelette1,lvl,son);
        Collision_Squelette(joueur,&entité->squelette,input,lvl);
        Collision_Squelette(joueur,&entité->squelette1,input,lvl);
        
    }
    if (lvl->Num == 12)
    {
        Collision_Mur(joueur,20,20,20,20,lvl);
        Deplacement_Squelette(joueur,&entité->squelette,lvl,son);
        Deplacement_Squelette(joueur,&entité->squelette1,lvl,son);
        Collision_Squelette(joueur,&entité->squelette,input,lvl);
        Collision_Squelette(joueur,&entité->squelette1,input,lvl);
        Deplacement_Chauvesouris(joueur,&entité->chauvesouris, lvl, son);
        Deplacement_Chauvesouris(joueur, &entité->chauvesouris1, lvl, son);
    }
    if (lvl->Num == 13)
    {
        Collision_Mur(joueur,20,20,20,20,lvl);
        Deplacement_Boss_Jerem(joueur,&entité->jerem,lvl,son);
        Collision_Jerem_Boss (joueur, &entité->jerem, input, lvl);

    }
    
    
}

void Load_Level_1_1(Meduse *meduse, Lvl *lvl, Joueur *joueur)
{  
    Init_Maps(lvl);
    joueur->inposx = level[0][0][2];
    joueur->inposy = level[0][0][3];
    meduse->posmonsx =level[0][1][1];
    meduse->posmonsy =level[0][1][2];
    meduse->Life=level[0][1][5];
}

void Load_Level_1_2(Meduse *meduse,Meduse *meduse1,Meduse *meduse2 , Lvl *lvl, Joueur *joueur)
{       
    // SDL_RenderClear(renderer);
    // SDL_RenderPresent(renderer);
    Init_Maps(lvl);
    joueur->inposx = level[1][0][2];
    joueur->inposy = level[1][0][3];
    meduse->posmonsx =level[1][1][1];
    meduse->posmonsy =level[1][1][2];
    meduse->Life=level[1][1][5];
    meduse->compteur=level [1][1][3];
    meduse1->posmonsx =level[1][2][1];
    meduse1->posmonsy =level[1][2][2];
    meduse1->Life=level[1][2][5];
    meduse1->compteur=level[1][2][3];
    meduse2->posmonsx =level[1][3][1];
    meduse2->posmonsy =level[1][3][2];
    meduse2->Life=level[1][3][5];
    meduse2->compteur=level[1][3][3];

}

void Load_Level_1_3(Meduse *meduse, Meduse *meduse1, Chauvesouris *chauvesouris, Chauvesouris *chauvesouris1, Lvl *lvl, Joueur *joueur)
{  
    Init_Maps(lvl);
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

void Load_Level_1_4 (Joueur *joueur,Boss *boss, Lvl *lvl)
{
    Init_Maps(lvl);
    joueur->inposx = level[3][0][2];
    joueur->inposy = level[3][0][3];
    boss->posmonsx =level[3][1][1];
    boss->posmonsy =level[3][1][2];
    boss->Life=level [3][1][5];
    boss->RecupCoeur = 0;
}

void Load_Level_2_1 (Joueur *joueur, Lvl* lvl)
{
    Init_Maps(lvl);
    joueur->inposx = level[4][0][2];
    joueur->inposy = level[4][0][3];
}

void Load_Level_3_1 (Joueur *joueur,Yeti *yeti, Lvl *lvl)
{
    Init_Maps(lvl);
    joueur->inposx = level[5][0][2];
    joueur->inposy = level[5][0][3];
    yeti->posmonsx =level[5][1][1];
    yeti->posmonsy =level[5][1][2];
    yeti->Life=level [5][1][5];
}

void Load_Level_3_2 (Joueur *joueur, Yeti *yeti, Yeti *yeti1, Yeti *yeti2, Lvl *lvl)
{
    Init_Maps(lvl);
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

void Load_Level_3_3 (Joueur *joueur, Yeti *yeti, Yeti *yeti1, Lvl *lvl, Chauvesouris *chauvesouris, Chauvesouris *chauvesouris1)
{
    Init_Maps(lvl);
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

void Load_Level_3_4 (Joueur *joueur, BossYeti *bossyeti,Lvl *lvl)
{
    Init_Maps(lvl);
    joueur->inposx= level [8][0][2];
    joueur->inposy= level [8][0][3];
    bossyeti->posmonsx =level[8][1][1];
    bossyeti->posmonsy =level[8][1][2];
    bossyeti->Life=level [8][1][5];
  
}

void Load_Level_4_1(Joueur *Joueur, Lvl *lvl)
{
    Init_Maps(lvl);
    Joueur->inposx = level[9][0][2];
    Joueur->inposy = level[9][0][3];
}

void Load_Level_4_2(Joueur *joueur,Obstacle *Petit_rocher,Obstacle *Gros_rocher,Obstacle *tronc,Obstacle *tanguy, Lvl *lvl)
{
    printf("rest");
    Init_Maps(lvl);
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

    Petit_rocher->Etat = 0;
    Gros_rocher->Etat = 0;
    tronc->Etat =0;
    tanguy->Etat = 0;
    lvl->Avancement10 = 0;
}

void Load_Level_5_1(Joueur *joueur,Lvl *lvl, Squelette *squelette1,Squelette *squelette)
{
    Init_Maps(lvl);
    joueur->inposx = level[11][0][2];
    joueur->inposy = level[11][0][3];

    squelette->posmonsx = level[11][1][1];
    squelette->posmonsy = level[11][1][2];
    squelette->Direction = 0;
    squelette->Life = level[11][1][5];
    squelette->Eattaque = 0;

    squelette1->posmonsx = level[11][2][1];
    squelette1->posmonsy = level[11][2][2];
    squelette1->Direction = 1;
    squelette1->Life = level[11][2][5];
    squelette1->Eattaque = 0;

    lvl->cin = 1;
}

void Load_Level_5_2(Joueur *joueur, Squelette *squelette, Squelette *squelette1,Chauvesouris *chauvesouris, Chauvesouris *chauvesouris1, Lvl *lvl)
{
    lvl->cin =0;
    
    Init_Maps(lvl);
    joueur->inposx = level[12][0][2];
    joueur->inposy = level[12][0][3];

    squelette->posmonsx = level[12][1][1];
    squelette->posmonsy = level[12][1][2];
    squelette->Life = level[12][1][5];
    squelette->Eattaque = 0;
    squelette1->posmonsx = level[12][2][1];
    squelette1->posmonsy = level[12][2][2];
    squelette1->Life = level[12][2][5];
    squelette1->Eattaque = 0;
    chauvesouris->posmonsx =level[12][3][1];
    chauvesouris->posmonsy =level[12][3][2];
    chauvesouris->Life=level[12][3][5];
    chauvesouris->CompteurSpriteDegat=0;
    chauvesouris1->posmonsx =level[12][4][1];
    chauvesouris1->posmonsy =level[12][4][2];
    chauvesouris1->Life=level[12][4][5];
    chauvesouris1->CompteurSpriteDegat=0;
}

void Load_Level_5_3(Joueur *joueur, Jerem_Boss *jerem,Lvl *lvl)
{
    Init_Maps(lvl);
    joueur->inposx = level[13][0][2];
    joueur->inposy = level[13][0][3];
    jerem->posmonsx = level[13][1][1];
    jerem->posmonsy = level[13][1][2];
    jerem->Life = level[13][1][5];
    jerem->Transformation = 0;
    
}

void Clean_Up(EffetSon *son)
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

void Init_Eclair(Boss *boss)
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


void Load_Game (Joueur *joueur, Lvl *lvl, Stats *stats)
{
    srand(time(NULL));
    char* nomFichier = "src/Save/Game.txt";
    char* nomFichier1 = "src/Save/Stats.txt";
    FILE* fichier = fopen ( nomFichier , "r+" );
    if ( fichier )
    {
        fscanf(fichier,"life=%d AttPice=%d NbPiece=%d nbDague=%d WinDonjon=%d",&joueur->life,&joueur->AttPiece,&joueur->NbPiece,&joueur->nbDague,&lvl->WinDonjon);
        fclose (fichier);
    }
    FILE* fichier1 = fopen ( nomFichier1 , "r+" );
    if ( fichier1 )
    {
        fscanf(fichier1,"Total_pièce=%d Total_Tués=%d Total_Mort=%d Dague_Lancées=%d KDA=%f TEMPS_GENE=%f temps=%s S1=%f S2=%f S3=%f S4=%f S5=%f %s %s %s %s %s",&stats->Total_pièce,&stats->Total_Tués,&stats->Total_Mort,&stats->Dague_Lancées,&stats->KDA,&stats->TEMPS_GENE,stats->Score_act,&stats->Score_Board[0],&stats->Score_Board[1],&stats->Score_Board[2],&stats->Score_Board[3],&stats->Score_Board[4],&stats->Convert_Score[0],&stats->Convert_Score[1],&stats->Convert_Score[2],&stats->Convert_Score[3],&stats->Convert_Score[4]);
        fclose (fichier1);
    }
}