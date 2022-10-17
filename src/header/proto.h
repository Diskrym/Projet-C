#ifndef PROTO 
#define PROTO
 
#include "structs.h" 
/* Catalogue des prototypes des fonctions utilisées.
On le complétera au fur et à mesure. */
 
extern void delay2(void);
extern void cleanMaps(void);
extern void cleanup(void);
extern void delay(unsigned int frameLimit);
extern void drawGame(void);
extern void drawImage(SDL_Texture *, int, int);
extern void drawMap(int);
extern void gestionInputs(Input *input);
extern SDL_Texture *getBackground(void);
extern void getInput(Input *input);
extern SDL_Renderer *getrenderer(void);
extern void init(char *);
extern void initMaps(void);
extern void loadGame(Pos *pos);
extern SDL_Texture *loadImage(char *name);
extern void deplacement(Input *intput, Pos *pos); 

#endif