#ifndef PROTO 
#define PROTO
 
#include "structs.h" 

//draw.c
extern void drawGame(Joueur *joueur, Lvl *lvl, ParamTexte *paramtexte, EffetSon *son);
extern void GameOver (EffetSon *son);
extern void Win (void);
extern SDL_Texture *loadImage(char *name);
extern void drawImage(SDL_Texture *, int, int);
extern void delay(unsigned int frameLimit);
extern void AffichageVie(Joueur *joueur, Lvl *lvl, EffetSon *son);
extern void AffichagePiece (Joueur *joueur,Lvl *lvl,ParamTexte *paramtexte);
extern void AffichageLevel (Lvl *lvl);
extern void porte (Lvl *lvl);
extern void menu (Lvl *lvl);
extern void pause (Lvl *lvl);


//events.c
extern void collisionmur (Joueur *joueur, int x, int y, int z, int u);
extern void collisionboss (Joueur *joueur, Boss *boss, Input *input, Lvl *lvl);
extern void collision (Joueur *joueur, Meduse *meduse, Input *input, Lvl *lvl);
extern void collisionDecor (Joueur *joueur, Input *input, int x1, int x2, int y1, int y2);
extern void collisionyeti (Joueur *joueur, Yeti *yeti, Input *input, Lvl *lvl);
extern void collisionbossyeti (Joueur *joueur, BossYeti *bossyeti, Input *input, Lvl *lvl);
extern int inside (Joueur *joueur, Meduse *meduse);
extern int insidechevalier (Joueur *joueur, Meduse *meduse);
extern int insidechauvesouris (Joueur *joueur, Chauvesouris *chauvesouris);
extern int insidechevalierBoss (Joueur *joueur, Boss *boss);
extern int insidechevalieryeti (Joueur *joueur, Yeti *yeti);
extern int insideBoss (Joueur *joueur, Boss *boss);
extern int insideEclair(Joueur *joueur,int Eclairx, int Eclairy);
extern int DegatChevalier(Meduse *meduse, Meduse *meduse1 , Meduse *meduse2, Chauvesouris *chauvesouris , Chauvesouris *chauvesouris1, Boss *boss, Yeti *yeti,Yeti *yeti1,Yeti *yeti2, BossYeti *bossyeti);
extern int DegatBateau (Obstacle *tronc, Obstacle *Petit_rocher, Obstacle *Gros_rocher);
extern int insideItem (Joueur *joueur, Boss *boss);
extern int insideVol (int xobj, int yobj, int x, int y, int Margex, int Margey, int tailleObjx, int tailleObjy);
extern int insidechevalierbossyeti (Joueur *joueur, BossYeti *bossyeti);


//init.c
extern SDL_Renderer *getrenderer(void);
extern void init(char *);
extern void LoadJoueur(Joueur *joueur);
extern void LoadNiv11(Meduse *meduse, Lvl *lvl, Joueur *joueur);
extern void LoadNiv12(Meduse *meduse, Meduse *meduse1,Meduse *meduse2, Lvl *lvl, Joueur *joueur);
extern void GestionMonstre (Entité* entité, Lvl *lvl, Input *input, Joueur *joueur, EffetSon *son);
extern void LoadNiv13(Meduse *meduse, Meduse *meduse1, Chauvesouris *chauvesouris, Chauvesouris *chauvesouris1, Lvl *lvl, Joueur *joueur);
extern void Son (EffetSon *son);
extern void Texte(ParamTexte *paramtexte);
extern void loadNiv14 (Joueur *joueur, Boss *boss, Lvl *lvl);
extern void loadNiv21 (Joueur *jouer, Lvl* lvl);
extern void cleanup(EffetSon *son);
extern void SelectNiv (Joueur *joueur, Lvl *lvl, Entité *entité, EffetSon *son);
extern void initEclair(Boss *boss);
extern void loadNiv31(Joueur *joueur,Yeti *yeti, Lvl *lvl);
extern void loadNiv32 (Joueur *joueur, Yeti *yeti, Yeti *yeti1, Yeti *yeti2, Lvl *lvl);
extern void loadNiv41(Joueur *joueur,Lvl *lvl);
extern void loadNiv42(Joueur *joueur,Obstacle *Petit_rocher,Obstacle *Gros_rocher,Obstacle *tronc,Obstacle *tanguy, Lvl *lvl);
extern void loadNiv33 (Joueur *joueur, Yeti *yeti, Yeti *yeti1, Lvl *lvl, Chauvesouris *chauvesouris, Chauvesouris *chauvesouris1);
extern void loadNiv34 (Joueur *joueur, BossYeti *bossyeti,Lvl *lvl);
extern void Save (Joueur*joueur,Lvl *lvl,Input *input, Entité *entité, EffetSon *son);

//input.c
extern void gestionInputs(Input *input);
extern void getInput(Input *input);
extern void deplacement (Input *input, Joueur *joueur, Entité *entité,EffetSon *son, Lvl *lvl);
extern void deplacementMeduse (Joueur *joueur, Meduse *meduse, Lvl *lvl, EffetSon *son);
extern void deplacementChauvesouris (Joueur *joueur, Chauvesouris *chauvesouris,  Lvl *lvl, EffetSon *son);
extern void deplacementyeti (Joueur *joueur, Yeti *yeti, Lvl *lvl, EffetSon *son);
extern void deplacementbossyeti (Joueur *joueur, BossYeti *bossyeti, Lvl *lvl, EffetSon *son);
extern void deplacementBoss (Joueur *joueur, Boss *boss, Lvl *lvl, Input *input, EffetSon *son);

//map.c
extern void initMaps(Lvl *lvl);
extern SDL_Texture *getBackground(void);
extern void GestionMap(Joueur *joueur, Lvl *lvl, Entité *entité, EffetSon *son, Input *input);
extern void MapGlobal (Joueur *joueur, Lvl *lvl, Entité *entité,EffetSon *son, Input *input);

//Sprit.c
extern void SpritHeros(Joueur *joueur, Input *input, EffetSon *son, Entité *entité);
extern void SpritMeduse (Meduse *meduse, Joueur *joueur, Lvl *lvl, EffetSon *son);
extern void SpritChauvesouris (Chauvesouris *chauvesouris, Joueur *joueur, Lvl *lvl, EffetSon *son);
extern void SpritBoss (Boss *boss, Joueur *joueur, Lvl *lvl, EffetSon *son );
extern void Sprityeti (Yeti *yeti, Joueur *joueur,Lvl *lvl, EffetSon *son);
extern void Spritbossyeti (BossYeti *bossyeti, Joueur *joueur,Lvl *lvl, EffetSon *son);
extern void GestionMarchands (Joueur *joueur, Input *input, Marchand *marchand,Lvl *lvl, EffetSon *son);
extern void Gestion_Obstacle(Joueur *joueur,Marchand *marchand,Obstacle *Petit_rocher,Obstacle *Gros_rocher, Obstacle *tronc,Obstacle* tanguy, Lvl *lvl, EffetSon *son);
//extern void drawMap(int);
#endif