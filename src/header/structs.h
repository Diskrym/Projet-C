#ifndef DEF_STRUCTS
#define DEF_STRUCTS
 
#include "defs.h"
 
/* Structures qui seront utilisées pour gérer le jeu */
 
// Structure pour gérer l'input (clavier puis joystick)
typedef struct Input
{
 
    int left, right, up, down, jump, attack, enter, erase, pause;
 
} Input;

typedef struct Meduse
{
 
    int attack, NumSprit, Direction, posmonsx, posmonsy, coup, Life, CompteurSpriteDegat, compteur, CompteurSpriteMort;
 
} Meduse;


// Structure pour gérer la map à afficher (à compléter plus tard)
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
    int Num;
} Lvl;
// level [1.Numlvl]
//{NumLvl,Méduse,Squelette,Chauvesouris,NbMonstre,0,0,0,0,0}
static const int level [5][10] =   {{1,0,0,0,0,0,0,0,0,0},
                                    {2,0,0,0,0,0,0,0,0,0},
                                    {3,0,0,0,0,0,0,0,0,0},
                                    {4,0,0,0,0,0,0,0,0,0},
                                    {5,0,0,0,0,0,0,0,0,0}};
 
#endif