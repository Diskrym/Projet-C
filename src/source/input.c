#include "../header/proto.h"

//Gestion des inputs clavier et souris
void Get_Input(Input *input)
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                exit(0);
            break;
            //Cas dans lequel on appuie sur une touche
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        input->echap = 1;
                    break;
 
                    case SDLK_z:
                        input->shield = 1;
                    break;

                    case SDLK_e :
                        input->dague = 1;
                    break;
 
                    case SDLK_SPACE:
                        input->attack = 1;
                    break;
 
                    case SDLK_LEFT:
                        input->left = 1;
                    break;
 
                    case SDLK_RIGHT:
                        input->right = 1;
                    break;
 
                    case SDLK_DOWN:
                        input->down = 1;
                    break;
 
                    case SDLK_UP:
                        input->up = 1;
                    break;
 
 
                    case SDLK_RETURN:
                        input->enter = 1;
                    break;

                    //#A enlever#
                    case SDLK_o:
                        input->Bypass = 1;
                    break;
 
 
                    default:
                    break;
                }
            break;

            //Cas dans lequel la touche est levée
            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        input->echap = 0;
                    break;
                    
                    case SDLK_z:
                        input->shield = 0;
                    break;

                    case SDLK_e :
                        input->dague = 0;
                    break;
 
                    case SDLK_LEFT:
                        input->left = 0;
                    break;
 
                    case SDLK_RIGHT:
                        input->right = 0;
                    break;
 
                    case SDLK_DOWN:
                        input->down = 0;
                    break;
 
                    case SDLK_UP:
                        input->up = 0;
                    break;
 
                    case SDLK_RETURN:
                        input->enter = 0;
                    break;

                    case SDLK_SPACE:
                        input->attack = 0;
                    break;

                    //#A enlever#
                    case SDLK_o:
                        input->Bypass = 0;
                    break;
 
                    default:
                    break;
                }
            break;
            //Gestion déplacement souris//boutton
            case SDL_MOUSEBUTTONDOWN :
                switch (event.button.button)
                {
                    case SDL_BUTTON_LEFT:
                        input->PosMouseX = event.motion.x ;
                        input->PosMouseY = event.motion.y ;
                    break;
                    
                    default:
                    break;
                }
            break;

            case SDL_MOUSEBUTTONUP :
                switch (event.button.button)
                {
                    case SDL_BUTTON_LEFT:
                        input->PosMouseX = 315   ;
                        input->PosMouseY = 190 ;
                    break;
                    
                    default:
                    break;
                }
            break;
        }
    }
}

//Gestion déplacement du chevalier
void Deplacement_Chevalier (Input *input, Joueur *joueur, Entité *entité, EffetSon *son,Lvl *lvl)
{  
    //si pas dans la cinématique du niv 11
    if(!(lvl->cin == 1 && lvl->Num == 11))
    {
        //Si on a pas le bouclier, on se déplace
        if (!(joueur->Eshield==1 && joueur->TimingBouclier<45) && input->shield==0)
        {
            if (input->left==1)
            {
                //si on est pas dans la rivière, on change l'image à afficher avec le NumSprite/changement de la direction du sprit entre gauche et droite et changement de la position du joueur sur le fenetre sdl
                if(lvl->Num!=10 || (lvl->Avancement10 == 13 && lvl->Num == 10))
                {
                    joueur->inposx-=3;
                    joueur->NumSprite+=1;
                    joueur->Direction =1;

                }
                else if( lvl->Avancement10 != 13)
                {
                    joueur->inposx-=4;
                }
            }
            if (input->right==1)
            {
                if (lvl->Num != 10 || (lvl->Avancement10 == 13 && lvl->Num == 10))
                {
                    joueur->inposx+=3;
                    joueur->NumSprite+=1;
                    joueur->Direction =0;
                }
                else if ( lvl->Avancement10 != 13)
                {
                    joueur->inposx+=2;
                } 
            }
            if (input->up==1)
            {
                if (lvl->Num !=10 || (lvl->Avancement10 == 13 && lvl->Num == 10))
                {
                    joueur->NumSprite+=1;  
                } 
                joueur->inposy-=3;
            }
            if (input->down==1)
            {
                if (lvl->Num != 10 || (lvl->Avancement10 == 13 && lvl->Num == 10))
                {
                    joueur->NumSprite+=1;
                }
                joueur->inposy+=3;
            }
        }
        if (input->dague == 1 && joueur->Edague == 0 && joueur->nbDague>0)
        {
            joueur->Edague = 1;
            joueur->xdague=joueur->inposx;
            joueur->ydague=joueur->inposy+32;
            joueur->DirDague=joueur->Direction;
        }
        if (input->attack==1)
        {
            joueur->NumSprite=0;
            joueur->Eattack=1;
        }
        if (input->shield==1)
        {
            joueur->NumSprite=0;
            joueur->Eshield=1;
        }
        if (input->shield==0)
        {
            joueur->Eshield=0;
            joueur->TimingBouclier=0;
        }
    }
    //Appel de la fonction chargée de la sélection du sprit à afficher
    Sprite_Chevalier(joueur, input, son, entité, lvl);
}

void Deplacement_Meduse (Joueur *joueur, Meduse *meduse, Lvl *lvl, EffetSon *son)
{
    //Compteur qui permet de choisir l'action à effectuer par la méduse (attaque/déplacement)
    meduse->compteur += 1;
    meduse->NumSprite+=1;
    //Compteur mort méduse
    if  (meduse->Life==0 && meduse->CompteurSpriteDegat<19)
    {
        meduse->CompteurSpriteDegat+=1;
    }
    //Compteur mort pour passage de niveau
    if (meduse->CompteurSpriteDegat==18)
    {
        lvl->MortMonstre+=1;
    }
    //Déplacement méduse
    if (meduse->compteur <= 100 && meduse->Life >=1)
    {
        if (joueur->inposx<meduse->posmonsx)
        {
            meduse->posmonsx-=1;
        }
        if (joueur->inposx>meduse->posmonsx)
        {
            meduse->posmonsx+=1;   
        }
        if (joueur->inposy<meduse->posmonsy)
        {
            meduse->posmonsy-=1;
        }
        if (joueur->inposy>meduse->posmonsy)
        {
            meduse->posmonsy+=1;
        }
    }
    Sprite_Meduse (meduse, joueur, lvl, son);
}

void Deplacement_Chauvesouris (Joueur *joueur, Chauvesouris *chauvesouris, Lvl *lvl, EffetSon *son)
{
    chauvesouris->NumSprite+=1;
    if  (chauvesouris->Life==0 && chauvesouris->CompteurSpriteDegat<19)
    {
        chauvesouris->CompteurSpriteDegat+=1;
    }
   
    if (chauvesouris->Life >=1)
    {
        if (joueur->inposx<chauvesouris->posmonsx)
        {
            chauvesouris->posmonsx-=2;
            chauvesouris->Direction=1;   
        }
        if (joueur->inposx>chauvesouris->posmonsx)
        {
            chauvesouris->posmonsx+=2;
            chauvesouris->Direction=0;
        }
        if (joueur->inposy+32<chauvesouris->posmonsy)
        {
            chauvesouris->posmonsy-=2;
        }
        if (joueur->inposy+32>chauvesouris->posmonsy)
        {
            chauvesouris->posmonsy+=2;
        }
    }
    Sprite_Chauvesouris (chauvesouris, joueur, lvl, son);
}

void Deplacement_Yeti (Joueur *joueur, Yeti *yeti, Lvl *lvl, EffetSon *son)
{   
    yeti->compteur+=1;
    yeti->NumSprite+=1;
    if  (yeti->Life==0 && yeti->CompteurSpriteDegat<19)
    {
        yeti->CompteurSpriteDegat+=1;
    }
   
    if (yeti->Life >=1 && yeti->compteur<100)
    {
        if (joueur->inposx<yeti->posmonsx)
        {
            yeti->posmonsx-=1;
            yeti->Direction=1; 
        }
        if (joueur->inposx>yeti->posmonsx)
        {
            yeti->posmonsx+=1;
            yeti->Direction=0;
        }
        if (joueur->inposy<yeti->posmonsy+15)
        {
            yeti->posmonsy-=1;
        }
        if (joueur->inposy>yeti->posmonsy+15)
        {
            yeti->posmonsy+=1;
        }
    }
    Sprite_Yeti (yeti, joueur, lvl, son);
}

void Deplacement_Boss_Yeti (Joueur *joueur, BossYeti *bossyeti, Lvl *lvl, EffetSon *son)
{  
    bossyeti->compteur+=1;
    bossyeti->NumSprite+=1;
    if  (bossyeti->Life==0 && bossyeti->CompteurSpriteDegat<19)
    {
        bossyeti->CompteurSpriteDegat+=1;
    }
   
    if (bossyeti->Life >=1 && bossyeti->compteur<100)
    {
        if (joueur->inposx<bossyeti->posmonsx)
        {
            bossyeti->posmonsx-=1;
            bossyeti->Direction=1;
           
        }
        if (joueur->inposx>bossyeti->posmonsx)
        {
            bossyeti->posmonsx+=1;
            bossyeti->Direction=0;
        }
        if (joueur->inposy<bossyeti->posmonsy+15)
        {
            bossyeti->posmonsy-=1;
        }
        if (joueur->inposy>bossyeti->posmonsy+15)
        {
            bossyeti->posmonsy+=1;
        }
 
    }
    Sprite_Boss_Yeti (bossyeti, joueur, lvl, son);
}

void Deplacement_Boss_Meduse (Joueur *joueur, Boss *boss, Lvl *lvl, Input *input, EffetSon *son)
{
    boss->compteur += 1;
    boss->NumSprite+=1;
    //gestion mort + ouverture coffre
    if (boss->CompteurSpriteDegat==21 && Inside_Boss_Meduse_Chevalier(joueur, boss)==1 && input->enter == 1)
    {
        boss->CompteurSpriteDegat=22;
        Mix_VolumeChunk(son->coffre, MIX_MAX_VOLUME);
        Mix_PlayChannel(6, son->coffre, 0);
    }
    //compteur mort
    if  (boss->Life==0 && boss->CompteurSpriteDegat<21)
    {
        boss->CompteurSpriteDegat+=1;
    }
    
    //Compteur pour item coffre
    if (boss->Life == 0 && boss->CompteurSpriteDegat>=22)
    {
        boss->CompteurSpriteDegat+=1;
    }

    //ajout mort pour passage de niveau
    if (boss->CompteurSpriteDegat==18)
    {
        lvl->MortMonstre+=1;
    }
    //Gestion compteur éclair
    if (boss->compteur > 200 && boss->compteur < 530)
    {
        boss->CompteurSpriteEclair+=1;
    }
    //Déplacement de base
    if (boss->compteur <= 400 && boss->Life >=1 && boss->compteur%2==0)
    {
        if (joueur->inposx-32<boss->posmonsx)
        {
            boss->posmonsx-=1;
        }
        if (joueur->inposx-32>boss->posmonsx)
        {
            boss->posmonsx+=1;   
        }
        if (joueur->inposy - 35<boss->posmonsy)
        {
            boss->posmonsy-=1;
        }
        if (joueur->inposy - 35>boss->posmonsy)
        {
            boss->posmonsy+=1;
        }
    }
    Sprite_Boss (boss, joueur, lvl, son);
}

void Deplacement_Squelette(Joueur *joueur, Squelette *squelette ,Lvl *lvl ,EffetSon *son)
{
    if (lvl->cin == 0)
    {
        if (squelette->Life >=1 && squelette->Eattaque == 0 && squelette->CompteurSpriteDegat == 0)
        {
            if (joueur->inposx<squelette->posmonsx)
            {
                squelette->posmonsx-=1;
                squelette->Direction = 1;
            }
            if (joueur->inposx>squelette->posmonsx)
            {
                squelette->posmonsx+=1; 
                squelette->Direction = 0;  
            }
            if (joueur->inposy<squelette->posmonsy)
            {
                squelette->posmonsy-=1;
            }
            if (joueur->inposy>squelette->posmonsy)
            {
                squelette->posmonsy+=1;
            }
        }
        squelette->NumSprite+=1;
    }
    Sprite_Squelette(lvl,squelette,joueur, son);
}

void Deplacement_Boss_Jerem (Joueur *joueur, Jerem_Boss *jerem, Lvl *lvl, EffetSon *son)
{
    if (jerem->Life >=1 && jerem->Eattaque == 0 && jerem->cin == 0)
    {
        if (joueur->inposx<jerem->posmonsx)
        {
            jerem->posmonsx-=1;
            jerem->Direction = 1;
        }
        if (joueur->inposx>jerem->posmonsx)
        {
            jerem->posmonsx+=1; 
            jerem->Direction = 0;  
        }
        if (joueur->inposy-20<jerem->posmonsy)
        {
            jerem->posmonsy-=1;
        }
        if (joueur->inposy-20>jerem->posmonsy)
        {
            jerem->posmonsy+=1;
        }
    }
    if (jerem->Eattaque != 3)
    {
        jerem->NumSprite+=1;
    }
    else
    {
        jerem->NumSprite-=1;
    }
    jerem->compteur+=1;

    //gestion compteur
    if (jerem->Transformation == 0)
    {
        if (jerem->compteur >= 100 && jerem->compteur <=145)
        {
            jerem->Eattaque = 1;
        }
        else if (jerem->compteur >145)
        {
            jerem->Eattaque = 0;
            jerem->compteur = 0;
        }
    }
    if (jerem->Transformation == 1)
    {
        if (jerem->compteur>=0 && jerem->compteur < 100)
        {
            jerem->Eattaque = 0;
        }
        else if (jerem->compteur >= 100 && jerem->compteur <=145)
        {
            jerem->Eattaque = 1;
        }
        else if (jerem->compteur > 145 && jerem->compteur < 245)
        {
            jerem->Eattaque = 0;
        }
        else if (jerem->compteur >= 245 && jerem->Eattaque !=3)
        {
            if (jerem->compteur == 245)
            {
                jerem->NumSprite = 0;
            }            
            jerem->Eattaque = 2;
        }
    }
    if (jerem->Transformation == 2)
    {
        if (jerem->compteur>=0 && jerem->compteur < 100)
        {
            jerem->Eattaque = 0;
        }
        else if (jerem->compteur >= 100 && jerem->compteur <=145)
        {
            jerem->Eattaque = 1;
        }
        else if (jerem->compteur > 145 && jerem->compteur < 245)
        {
            jerem->Eattaque = 0;
        }
        else if (jerem->compteur >= 245 && jerem->Eattaque !=3 && jerem->compteur<473)
        {
            if (jerem->compteur == 245)
            {
                jerem->NumSprite = 0;
            }
            jerem->Eattaque = 2;
        }
        else if (jerem->compteur == 600)
        {
            jerem->Eattaque = 4;
        }
    }
    Sprite_Boss_Jerem(joueur,jerem,lvl, son);
}