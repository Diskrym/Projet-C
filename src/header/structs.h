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
 
    int attack, NumSprit, Direction, posmonsx, posmonsy, coup, Life, CompteurSpriteDegat, compteur, CompteurSpriteMort;
    SDL_Texture *chauvesouris;
} Chauvesouris;

typedef struct  Boss
{
        int attack, NumSprit, posmonsx, posmonsy, coup, Life, CompteurSpriteDegat, CompteurSpriteMort, compteur;
        SDL_Texture *Boss;
        SDL_Texture *Bossattaque;
}Boss;

typedef struct Monstre
{
    Meduse meduse;
    Meduse meduse1;
    Meduse meduse2;
    Chauvesouris chauvesouris;
    Chauvesouris chauvesouris1;
    Boss boss;
} Monstre;


typedef struct Map
{
 
SDL_Texture *background;
 
} Map;

typedef struct Joueur
{
    int inposx, inposy, Eattack,Eshield, life, Direction, NumSprit, Numattack, coup;
    SDL_Texture *chevalier;
    SDL_Texture *attaque;
} Joueur;

typedef struct EffetSon
{
    Mix_Music *musique;
    Mix_Chunk *epee;
}EffetSon;

typedef struct Lvl
{
    int Num, changement, MortMonstre;
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
                                            {3,288,110,128,1,1}
                                        }
                                    };


#endif