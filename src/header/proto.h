#ifndef PROTO 
#define PROTO
 
#include "structs.h" 
/* Catalogue des prototypes des fonctions utilisées.
On le complétera au fur et à mesure. */
 
//extern void delay2(void);
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
extern void LoadJoueur(Joueur *joueur);
extern void LoadMonstre(Meduse *meduse,int x, int y);
extern SDL_Texture *loadImage(char *name);
extern void deplacement (Input *input, Joueur *joueur);
extern void deplacementMonstre (Joueur *joueur, Meduse *meduse);
extern void collision (Joueur *joueur, Meduse *meduse, Input *input);
//extern void s_sleep(void);
extern void AffichageVie(Joueur *joueur);
extern void GameOver (void);
extern void AffichageLevel (Lvl *lvl);
extern int inside (Joueur *joueur, Meduse *meduse);
extern int insidechevalier (Joueur *joueur, Meduse *meduse, Input *input);
extern void Win (void);
extern void SpritHeros(Joueur *joueur, Meduse *meduse, Input *input);
extern void SpritMeduse (Meduse *meduse, Joueur *joueur);
#endif