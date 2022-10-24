#ifndef PROTO 
#define PROTO
 
#include "structs.h" 

//draw.c
extern void drawGame(void);
extern void GameOver (void);
extern void Win (void);
extern SDL_Texture *loadImage(char *name);
extern void drawImage(SDL_Texture *, int, int);
extern void delay(unsigned int frameLimit);
extern void AffichageVie(Joueur *joueur);
extern void AffichageLevel (Lvl *lvl);
extern void porte (int NbMonstre);

//events.c
extern void collision (Joueur *joueur, Meduse *meduse, Input *input);
extern int inside (Joueur *joueur, Meduse *meduse);
extern int insidechevalier (Joueur *joueur, Meduse *meduse);

//init.c
extern SDL_Renderer *getrenderer(void);
extern void init(char *);
extern void LoadJoueur(Joueur *joueur);
extern void LoadNiv1(Meduse *meduse, Lvl *lvl, Joueur *joueur);
extern void cleanup(void);

//input.c
extern void gestionInputs(Input *input);
extern void getInput(Input *input);
extern void deplacement (Input *input, Joueur *joueur);
extern void deplacementMeduse (Joueur *joueur, Meduse *meduse);

//map.c
extern void initMaps(void);
extern SDL_Texture *getBackground(void);
extern void cleanMaps(void);

//Sprit.c
extern void SpritHeros(Joueur *joueur, Meduse *meduse, Input *input);
extern void SpritMeduse (Meduse *meduse, Joueur *joueur);

//extern void drawMap(int);
#endif