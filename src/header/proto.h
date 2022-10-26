#ifndef PROTO 
#define PROTO
 
#include "structs.h" 

//draw.c
extern void drawGame(Joueur *joueur, Lvl *lvl);
extern void GameOver (void);
extern void Win (void);
extern SDL_Texture *loadImage(char *name);
extern void drawImage(SDL_Texture *, int, int);
extern void delay(unsigned int frameLimit);
extern void AffichageVie(Joueur *joueur);
extern void AffichageLevel (Lvl *lvl);
extern void porte (Lvl *lvl);

//events.c
extern void collision (Joueur *joueur, Meduse *meduse, Input *input, Lvl *lvl);
extern int inside (Joueur *joueur, Meduse *meduse);
extern int insidechevalier (Joueur *joueur, Meduse *meduse);
extern int insidechauvesouris (Joueur *joueur, Chauvesouris *chauvesouris);


//init.c
extern SDL_Renderer *getrenderer(void);
extern void init(char *);
extern void LoadJoueur(Joueur *joueur);
extern void LoadNiv1(Meduse *meduse, Lvl *lvl, Joueur *joueur);
void LoadNiv2(Meduse *meduse, Meduse *meduse1,Meduse *meduse2, Lvl *lvl, Joueur *joueur);
void GestionMonstre (Monstre* monstre, Lvl *lvl, Input *input, Joueur *joueur);
extern void LoadNiv3(Meduse *meduse, Meduse *meduse1, Chauvesouris *chauvesouris, Chauvesouris *chauvesouris1, Lvl *lvl, Joueur *joueur);
extern void Son (EffetSon *son);
extern void loadNiv4 (Joueur *joueur, Boss *boss, Lvl *lvl);

extern void cleanup(EffetSon *son);
extern void SelectNiv (Joueur *joueur, Lvl *lvl, Monstre *monstre);

//input.c
extern void gestionInputs(Input *input);
extern void getInput(Input *input);
extern void deplacement (Input *input, Joueur *joueur, Meduse *meduse,  Chauvesouris *chauvesouris , EffetSon *son);
extern void deplacementMeduse (Joueur *joueur, Meduse *meduse, Lvl *lvl);
extern void deplacementChauvesouris (Joueur *joueur, Chauvesouris *chauvesouris,  Lvl *lvl);
extern void deplacementBoss (Joueur *joueur, Boss *boss, Lvl *lvl);



//map.c
extern void initMaps(Lvl *lvl);
extern SDL_Texture *getBackground(void);
extern void cleanMaps(void);
extern void GestionMap(Joueur *joueur, Lvl *lvl, Monstre *monstre);

//Sprit.c
extern void SpritHeros(Joueur *joueur, Meduse *meduse, Input *input, Chauvesouris *chauvesouris, EffetSon *son);
extern void SpritMeduse (Meduse *meduse, Joueur *joueur, Lvl *lvl);
extern void SpritChauvesouris (Chauvesouris *chauvesouris, Joueur *joueur, Lvl *lvl);
extern void SpritBoss (Boss *boss, Joueur *joueur, Lvl *lvl);


//extern void drawMap(int);
#endif