#ifndef DEF_STRUCTS
#define DEF_STRUCTS
 
#include "defs.h"
 
 
// variable clavier
typedef struct Input
{
 
    int left, right, up, down, shield, attack, enter, erase, pause;
 
} Input;


typedef struct Meduse
{
 
    int attack, NumSprit, Direction, posmonsx, posmonsy, coup, Life, CompteurSpriteDegat, compteur, CompteurSpriteMort;
    SDL_Texture *attaque;
    SDL_Texture *meduse;
    
 
} Meduse;

typedef struct Chauvesouris
{
 
    int attack, NumSprit, Direction, posmonsx, posmonsy, coup, Life, CompteurSpriteDegat, compteur, CompteurSpriteDegatChevalier;
    SDL_Texture *chauvesouris;
} Chauvesouris;

typedef struct  Boss
{
        int NumSprit, posmonsx, posmonsy, coup, Life, CompteurSpriteDegat, CompteurSpriteEclair, compteur, Ex1, Ey1, Ex2, Ey2, Ex3, Ey3, Ex4, Ey4, coupE1 , coupE2 ,coupE3, coupE4;
        SDL_Texture *Boss;
        SDL_Texture *Bossattaque;
        SDL_Texture *Eclair1;
        SDL_Texture *Eclair2;
        SDL_Texture *Eclair3;
        SDL_Texture *Eclair4;
}Boss;


typedef struct Joueur
{
    int inposx, inposy, Eattack,Eshield, life, Direction, NumSprit, Numattack, coup, TimingBouclier;
    SDL_Texture *chevalier;
    SDL_Texture *attaque;
} Joueur;

typedef struct Monstre
{
    Meduse meduse;
    Meduse meduse1;
    Meduse meduse2;
    Chauvesouris chauvesouris;
    Chauvesouris chauvesouris1;
    Boss boss;
} Monstre;




typedef struct EffetSon
{
    Mix_Music *musiquemenu;
    Mix_Music *musiqueboss;
    Mix_Music *musiquelvl;
    Mix_Chunk *epee;
    Mix_Chunk *bouclier;
    Mix_Chunk *depchevalier;
    Mix_Chunk *degatchevalier;
    Mix_Chunk *mortchevalier;
    Mix_Chunk *lowlifechevalier;
    Mix_Chunk *attaquemeduse;
    Mix_Chunk *depmeduse;
    Mix_Chunk *degatmeduse;
    Mix_Chunk *mortmeduse;
    Mix_Chunk *mortchauvesouris;
    Mix_Chunk *attaqueboss;
    Mix_Chunk *mortboss;
    Mix_Chunk *boss;
    Mix_Chunk *degatboss;
    Mix_Chunk *porte;
    Mix_Chunk *gameoverson;
    Mix_Chunk *coffre;


}EffetSon;

typedef struct Lvl
{
    int Num, changement, MortMonstre;
    SDL_Texture *PorteHaut;
    SDL_Texture *PorteBas;
    SDL_Texture *Vie;
    SDL_Texture *Map;
    SDL_Texture *SpritLvl;
    SDL_Texture *SpritMotLVL;
} Lvl;

 /*
 static const int level [5][5][10]={ 
                                        { 
                                            {NumLvl, NbMonstre, Xjoueur, yjoueur, Range }
                                            {TypeMonstre, xMonstre, yMonstre, Range monstre, DegatsMoinstre, VieMonstre}
                                            {TypeMonstre, xMonstre, yMonstre, Range monstre, DegatsMoinstre, VieMonstre}
                                            {TypeMonstre, xMonstre, yMonstre, Range monstre, DegatsMoinstre, VieMonstre}
                                            {TypeMonstre, xMonstre, yMonstre, Range monstre, DegatsMoinstre, VieMonstre}
                                        }
                                    }
 */
static const int level [4][5][6] = {
                                        {
                                            {1,1,288,160,64,0},
                                            {1,70,70,64,1,3},
                                            {1,300,300,64,1,3}
                                        },
                                        {
                                            {2,3,298,384,64,0},
                                            {1,100,20,64,1,3},
                                            {1,300,20,64,1,3},
                                            {1,500,20,64,1,3}
                                        },
                                        {
                                            {3,4,298,384,0,0},
                                            {1,100,20,64,1,3},
                                            {1,500,200,64,1,3},
                                            {2,500,20,2,1,1},
                                            {2,100,200,2,1,1}
                                        },
                                        {
                                            {4,4,298,384,0,0},
                                            {3,288,80,128,1,10}
                                        }
                                    };


#endif