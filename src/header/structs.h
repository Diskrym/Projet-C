#ifndef DEF_STRUCTS
#define DEF_STRUCTS
 
#include "defs.h"
 
/* Structures qui seront utilisées pour gérer le jeu */
 
// Structure pour gérer l'input (clavier puis joystick)
typedef struct Input
{
 
    int left, right, up, down, jump, attack, enter, erase, pause, NumSprit, Direction, Life;
 
} Input;

typedef struct Monstre
{
 
    int attack, NumSprit, Direction, posmonsx, posmonsy;
 
} Monstre;


// Structure pour gérer la map à afficher (à compléter plus tard)
typedef struct Map
{
 
SDL_Texture *background;
 
} Map;

typedef struct Pos
{
    int inposx, inposy;
} Pos;

typedef struct Lvl
{
    int Num;
} Lvl;
 
 
#endif