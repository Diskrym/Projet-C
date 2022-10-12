#ifndef PROTO
#define PROTO
 
#include "action.h"
 
/* Catalogue des prototypes des fonctions utilisées.
   On le complétera au fur et à mesure. */
 
extern void changeLevel(void);
extern void cleanMaps(void);
extern void cleanup(void);
extern void delay(unsigned int frameLimit);
extern void drawGame(void);
extern void drawImage(SDL_Texture *, int, int);
extern void drawMap(int);
extern void drawTile(SDL_Texture *image, int destx, int desty, int srcx, int srcy);
extern void gestionInputs(Input *input);
extern SDL_Texture *getBackground(void);
extern void getInput(Input *input);
extern int getLevel(void);
extern SDL_Renderer *getrenderer(void);
extern void init(char *);
extern void initMaps(void);
extern void loadGame(void);
extern SDL_Texture *loadImage(char *name);
extern void loadMap(char *name);
extern void SetValeurDuNiveau(int valeur);
 
 
#endif