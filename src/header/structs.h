#ifndef DEF_STRUCTS
#define DEF_STRUCTS
 
#include "defs.h"
 
// variable clavier
typedef struct Input
{
    int left, right, up, down, shield, attack, enter, Bypass, dague;
} Input;


typedef struct Meduse
{
    int NumSprit, posmonsx, posmonsy, coup, Life, CompteurSpriteDegat, compteur;
    SDL_Texture *attaque;
    SDL_Texture *meduse;
} Meduse;

typedef struct Yeti
{
    int NumSprit, Direction, posmonsx, posmonsy, coup, Life, CompteurSpriteDegat, compteur, Eattaque, xboule, yboule,directionboule, CompteurBoule;
    SDL_Texture *attaqueyeti;
    SDL_Texture *yeti;
    SDL_Texture *boule;
} Yeti;

typedef struct Chauvesouris
{
    int NumSprit, Direction, posmonsx, posmonsy, coup, Life, CompteurSpriteDegat, compteur, CompteurSpriteDegatChevalier;
    SDL_Texture *chauvesouris;
} Chauvesouris;

typedef struct  Boss
{
    int NumSprit, posmonsx, posmonsy, coup, Life, CompteurSpriteDegat, CompteurSpriteEclair, compteur, Ex1, Ey1, Ex2, Ey2, Ex3, Ey3, Ex4, Ey4, coupE1 , coupE2 ,coupE3, coupE4, RecupCoeur;
    SDL_Texture *Boss;
    SDL_Texture *Bossattaque;
    SDL_Texture *Eclair1;
    SDL_Texture *Eclair2;
    SDL_Texture *Eclair3;
    SDL_Texture *Eclair4;
    SDL_Texture *Coeur;
}Boss;


typedef struct Joueur
{
    int inposx, inposy, Eattack, Eshield, life, Direction, NumSprit, Numattack, coup, TimingBouclier, AttPiece ,NbPiece, nbDague , xdague, ydague, Edague, NumSpriteDague, DirDague, Ebateau, sondague;
    //int  CoupDague;
    SDL_Texture *chevalier;
    SDL_Texture *attaque;
    SDL_Texture *dague;
    SDL_Texture *dagueMur;
} Joueur;

typedef struct Marchand
{
    int CompteurMess1,CompteurMess2, CompteurMess3, Compteur1;
    SDL_Texture *Jerem;
    SDL_Texture *Enter;
    SDL_Texture *Marchand;
    SDL_Texture *Tanguy;
    SDL_Texture *bulle;
    SDL_Texture *Table;
    SDL_Texture *Bec;
    SDL_Texture *Bateau;
}Marchand;

typedef struct Obstacle
{
    int x, y, Etat, coup, soncoule;
    SDL_Texture *Image;
    
}Obstacle;

typedef struct Entité
{
    Meduse meduse, meduse1, meduse2;
    Chauvesouris chauvesouris, chauvesouris1;
    Boss boss;
    Marchand marchand;
    Yeti yeti, yeti1, yeti2;
    Obstacle Petit_rocher,Gros_rocher, tronc, tanguy;

} Entité;




typedef struct EffetSon
{
    Mix_Music *musiquemenu;
    Mix_Music *musiqueMapG;
    Mix_Music *musiqueboss;
    Mix_Music *musiquelvl;
    Mix_Music *musiqueshop;
    Mix_Music *musiqueriviere;
    Mix_Music *musiqueyeti;
    Mix_Chunk *epee;
    Mix_Chunk *bouclier;
    Mix_Chunk *depchevalier;
    Mix_Chunk *degatchevalier;
    Mix_Chunk *mortchevalier;
    Mix_Chunk *lowlifechevalier;
    Mix_Chunk *attaquemeduse;
    Mix_Chunk *depmeduse;
    Mix_Chunk *degatmeduse;
    Mix_Chunk *mortmeduse;
    Mix_Chunk *mortchauvesouris;
    Mix_Chunk *attaqueboss;
    Mix_Chunk *mortboss;
    Mix_Chunk *boss;
    Mix_Chunk *degatboss;
    Mix_Chunk *porte;
    Mix_Chunk *gameoverson;
    Mix_Chunk *coffre;
    Mix_Chunk *attaqueyeti;
    Mix_Chunk *mortyeti;
    Mix_Chunk *degatyeti;
    Mix_Chunk *bouledeneige;
    Mix_Chunk *dague;
    Mix_Chunk *collisionR;
    Mix_Chunk *Jerem;
    Mix_Chunk *dagueLancer;
    Mix_Chunk *JeremDamm;

}EffetSon;


typedef struct ParamTexte
{
    TTF_Font *Font;
    SDL_Surface *SurfacePiece;
    SDL_Texture *TexturePiece;
    char StrPiece[3];
}ParamTexte;


typedef struct Lvl
{
    int Num, MortMonstre, NumDonjon, WinDonjon, PosMap10,Avancement10;
    SDL_Texture *PorteHaut;
    SDL_Texture *PorteBas;
    SDL_Texture *Vie;
    SDL_Texture *Piece;
    SDL_Texture *Map;
    SDL_Texture *MapSlide;
    SDL_Texture *SpritLvl;
    SDL_Texture *SpritMotLVL;
    SDL_Texture *Menu;
    SDL_Texture *Icone;
    SDL_Texture *Cadenas1;
    SDL_Texture *Cadenas2;
    SDL_Texture *Cadenas3;
    SDL_Texture *Cadenas4;
} Lvl;

 /*
 static const int level [5][5][10]={ 
                                        { 
                                            {NumLvl, NbMonstre, Xjoueur, yjoueur, Range }
                                            {TypeMonstre, xMonstre, yMonstre, Num monstre, DegatsMoinstre, VieMonstre}
                                            {TypeMonstre, xMonstre, yMonstre, Num monstre, DegatsMoinstre, VieMonstre}
                                            {TypeMonstre, xMonstre, yMonstre, Num monstre, DegatsMoinstre, VieMonstre}
                                            {TypeMonstre, xMonstre, yMonstre, Num monstre, DegatsMoinstre, VieMonstre}
                                        }
                                    }
 */
static const int level [10][5][6] = {
                                        {
                                            {1,1,288,160,64,0},
                                            {1,70,70,64,1,3},
                                            {1,300,300,64,1,3}
                                        },
                                        {
                                            {2,3,298,384,64,0},
                                            {1,100,20,64,1,3},
                                            {1,300,20,64,1,3},
                                            {1,500,20,64,1,3}
                                        },
                                        {
                                            {3,4,298,384,0,0},
                                            {1,100,20,64,1,3},
                                            {1,500,200,64,1,3},
                                            {2,500,20,2,1,1},
                                            {2,100,200,2,1,1}
                                        },
                                        {
                                            {4,1,298,384,0,0},
                                            {3,288,80,128,1,10}
                                        },
                                        {
                                            {5,0,288,297,0}
                                        },
                                        {
                                            {6,1,288,290,0},
                                            {4,300,120,0,2,4}
                                            
                                        },
                                        {
                                            {7,3,288,290,0},
                                            {4,250,70,0,2,4},
                                            {4,80,270,63,2,4},
                                            {4,500,270,126,2,4}
                                        },
                                        {
                                            {8,0,288,297,0}
                                        },
                                        {
                                            {9,0,98,26,0}
                                        },
                                        {
                                            {9,0,5,290,0}
                                        }
                                    };


#endif