#ifndef DEF_STRUCTS
#define DEF_STRUCTS
 
#include "defs.h"
 
 
// variable clavier
typedef struct Input
{
 
    int left, right, up, down, jump, attack, enter, erase, pause;
 
} Input;


typedef struct Meduse
{
 
    int attack, NumSprit, Direction, posmonsx, posmonsy, coup, Life, CompteurSpriteDegat, compteur, CompteurSpriteMort;
 
} Meduse;


typedef struct Map
{
 
SDL_Texture *background;
 
} Map;

typedef struct Joueur
{
    int inposx, inposy, Eattack, life, Direction, NumSprit, Numattack, coup;
} Joueur;

typedef struct Lvl
{
    int Num, changement, MortMonstre;
} Lvl;

 /*
 static const int level [5][5][10]={ 
                                        { 
                                            {NumLvl, NbMonstre, Xjoueur, yjoueur }
                                            {TypeMonstre, xMonstre, yMonstre, Vitesse monstre, DegatsMoinstre, VieMonstre}
                                            {TypeMonstre, xMonstre, yMonstre, Vitesse monstre, DegatsMoinstre, VieMonstre}
                                            {TypeMonstre, xMonstre, yMonstre, Vitesse monstre, DegatsMoinstre, VieMonstre}
                                            {TypeMonstre, xMonstre, yMonstre, Vitesse monstre, DegatsMoinstre, VieMonstre}
                                        }
                                    }
 */
static const int level [2][4][6] = {
                                        {
                                            {1,1,288,160,0,0},
                                            {1,70,70,2,1,3},
                                            {1,300,300,2,1,3}
                                        },
                                        {
                                            {2,3,298,384,0,0},
                                            {1,100,20,2,1,3},
                                            {1,300,20,2,1,3},
                                            {1,500,20,2,1,3}
                                        }
                                    };

#endif