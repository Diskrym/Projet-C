#ifndef PROTO 
#define PROTO
 
#include "structs.h" 

//draw.c
extern void Draw_Game(Joueur *joueur, Lvl *lvl, ParamTexte *paramtexte, EffetSon *son);
extern void Game_Over (EffetSon *son);
extern void Win (void);
extern SDL_Texture *loadImage(char *name);
extern void Draw_Image(SDL_Texture *, int, int);
extern void delay(unsigned int frameLimit);
extern void Render_Life(Joueur *joueur, Lvl *lvl, EffetSon *son);
extern void Render_Coin (Joueur *joueur,Lvl *lvl,ParamTexte *paramtexte);
extern void Render_Level (Lvl *lvl);
extern void Render_Door (Lvl *lvl);
extern void Menu (Lvl *lvl);
extern void Break_Menu (Lvl *lvl);
extern void Stats_Menu(Lvl *lvl,Stats*stats, ParamTexte *paramtexte);
extern void Statistiques(Stats *stats,Joueur *joueur, Lvl *lvl);
extern void Score_(Stats *stats,clock_t temps);
extern void Draw_Score (Lvl* lvl, Stats *stats, ParamTexte *paramtexte);



//events.c
extern void Collision_Mur (Joueur *joueur, int x, int y, int z, int u);
extern void Collision_Boss_Meduse (Joueur *joueur, Boss *boss, Input *input, Lvl *lvl);
extern void Collision_Meduse (Joueur *joueur, Meduse *meduse, Input *input, Lvl *lvl);
extern void Collision_Decor (Joueur *joueur, Input *input, int x1, int x2, int y1, int y2);
extern void Collision_Yeti (Joueur *joueur, Yeti *yeti, Input *input, Lvl *lvl);
extern void Collision_Boss_Yeti (Joueur *joueur, BossYeti *bossyeti, Input *input, Lvl *lvl);
extern void Collision_Squelette (Joueur *joueur, Squelette *squelette, Input *input, Lvl *lvl);
extern int Inside_Meduse_Chevalier (Joueur *joueur, Meduse *meduse);
extern int Inside_Chevalier_Meduse (Joueur *joueur, Meduse *meduse);
extern int Inside_Chauvesouris_Chevalier (Joueur *joueur, Chauvesouris *chauvesouris);
extern int Inside_Chevalier_Boss (Joueur *joueur, Boss *boss);
extern int Inside_Chevalier_Yeti (Joueur *joueur, Yeti *yeti);
extern int Inside_Boss_Meduse_Chevalier (Joueur *joueur, Boss *boss);
extern int Inside_fissure (Joueur *joueur, BossYeti *bossyeti, int etape);
extern int Inside_Eclair_Chevalier(Joueur *joueur,int Eclairx, int Eclairy);
extern int Degat_Chevalier(Meduse *meduse, Meduse *meduse1 , Meduse *meduse2, Chauvesouris *chauvesouris , Chauvesouris *chauvesouris1, Boss *boss, Yeti *yeti,Yeti *yeti1,Yeti *yeti2, BossYeti *bossyeti,Squelette *squelette, Squelette *squelette1);
extern int Degat_Bateau (Obstacle *tronc, Obstacle *Petit_rocher, Obstacle *Gros_rocher);
extern int Inside_Item (Joueur *joueur, Boss *boss);
extern int Inside_Vol (int xobj, int yobj, int x, int y, int Margex, int Margey, int tailleObjx, int tailleObjy);
extern int Inside_Chevalier_Boss_Yeti (Joueur *joueur, BossYeti *bossyeti);
extern int Inside_Squelette_Chevalier(Joueur *joueur, Squelette*squelette);



//init.c
extern SDL_Renderer *getrenderer(void);
extern void init(char *);
extern void LoadJoueur(Joueur *joueur);
extern void Load_Level_1_1(Meduse *meduse, Lvl *lvl, Joueur *joueur);
extern void Load_Level_1_2(Meduse *meduse, Meduse *meduse1,Meduse *meduse2, Lvl *lvl, Joueur *joueur);
extern void Gestion_Entité (Entité* entité, Lvl *lvl, Input *input, Joueur *joueur, EffetSon *son);
extern void Load_Level_1_3(Meduse *meduse, Meduse *meduse1, Chauvesouris *chauvesouris, Chauvesouris *chauvesouris1, Lvl *lvl, Joueur *joueur);
extern void Son (EffetSon *son);
extern void Texte(ParamTexte *paramtexte);
extern void Load_Level_1_4 (Joueur *joueur, Boss *boss, Lvl *lvl);
extern void Load_Level_2_1 (Joueur *jouer, Lvl* lvl);
extern void Clean_Up(EffetSon *son);
extern void Select_Level (Joueur *joueur, Lvl *lvl, Entité *entité, EffetSon *son);
extern void Init_Eclair(Boss *boss);
extern void Load_Level_3_1(Joueur *joueur,Yeti *yeti, Lvl *lvl);
extern void Load_Level_3_2 (Joueur *joueur, Yeti *yeti, Yeti *yeti1, Yeti *yeti2, Lvl *lvl);
extern void Load_Level_4_1(Joueur *joueur,Lvl *lvl);
extern void Load_Level_4_2(Joueur *joueur,Obstacle *Petit_rocher,Obstacle *Gros_rocher,Obstacle *tronc,Obstacle *tanguy, Lvl *lvl);
extern void Load_Level_3_3 (Joueur *joueur, Yeti *yeti, Yeti *yeti1, Lvl *lvl, Chauvesouris *chauvesouris, Chauvesouris *chauvesouris1);
extern void Load_Level_3_4 (Joueur *joueur, BossYeti *bossyeti,Lvl *lvl);
extern void Save (Joueur*joueur,Lvl *lvl,Input *input, Entité *entité, EffetSon *son,Stats *stats,clock_t temps);
extern void Load_Game (Joueur *joueur, Lvl *lvl, Stats *stats);
extern void Load_Level_5_1(Joueur *joueur,Lvl *lvl, Squelette *squelette1,Squelette *squelette);

//input.c
//extern void gestionInputs(Input *input);
extern void Get_Input(Input *input);
extern void Deplacement_Chevalier (Input *input, Joueur *joueur, Entité *entité,EffetSon *son, Lvl *lvl);
extern void Deplacement_Meduse (Joueur *joueur, Meduse *meduse, Lvl *lvl, EffetSon *son);
extern void Deplacement_Chauvesouris (Joueur *joueur, Chauvesouris *chauvesouris,  Lvl *lvl, EffetSon *son);
extern void Deplacement_Yeti (Joueur *joueur, Yeti *yeti, Lvl *lvl, EffetSon *son);
extern void Deplacement_Boss_Yeti (Joueur *joueur, BossYeti *bossyeti, Lvl *lvl, EffetSon *son);
extern void Deplacement_Boss_Meduse (Joueur *joueur, Boss *boss, Lvl *lvl, Input *input, EffetSon *son);
extern void Deplacement_Squelette(Joueur *joueur, Squelette *squelette ,Lvl *lvl ,EffetSon *son);

//map.c
extern void Init_Maps(Lvl *lvl);
extern SDL_Texture *getBackground(void);
extern void Gestion_Map(Joueur *joueur, Lvl *lvl, Entité *entité, EffetSon *son, Input *input,Stats*stats, ParamTexte *paramtexte);
extern void Gestion_Map_Global (Joueur *joueur, Lvl *lvl, Entité *entité,EffetSon *son, Input *input);

//Sprit.c
extern void Sprit_Chevalier(Joueur *joueur, Input *input, EffetSon *son, Entité *entité, Lvl *lvl);
extern void Sprit_Meduse (Meduse *meduse, Joueur *joueur, Lvl *lvl, EffetSon *son);
extern void Sprit_Chauvesouris (Chauvesouris *chauvesouris, Joueur *joueur, Lvl *lvl, EffetSon *son);
extern void SpritBoss (Boss *boss, Joueur *joueur, Lvl *lvl, EffetSon *son );
extern void Sprit_Yeti (Yeti *yeti, Joueur *joueur,Lvl *lvl, EffetSon *son);
extern void Sprit_Boss_Yeti (BossYeti *bossyeti, Joueur *joueur,Lvl *lvl, EffetSon *son);
extern void Gestion_Marchands (Joueur *joueur, Input *input, Marchand *marchand,Lvl *lvl, EffetSon *son);
extern void Gestion_Obstacle(Joueur *joueur,Marchand *marchand,Obstacle *Petit_rocher,Obstacle *Gros_rocher, Obstacle *tronc,Obstacle* tanguy, Lvl *lvl, EffetSon *son);
extern void Sprit_Squelette(Lvl *lvl,Squelette *squelette,Joueur *joueur);

//extern void drawMap(int);
#endif