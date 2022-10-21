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
 
    int attack, NumSprit, Direction, posmonsx, posmonsy, coup, Life;
 
} Meduse;


// Structure pour gérer la map à afficher (à compléter plus tard)
typedef struct Map
{
 
SDL_Texture *background;
 
} Map;

typedef struct Joueur
{
    int inposx, inposy, compteur, Eattack, life, Direction, NumSprit, Numattack;
} Joueur;

typedef struct Lvl
{
    int Num;
} Lvl;
// level [1.Numlvl]
static const int level[10][5]={{1,1}};

 
#endif