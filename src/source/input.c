#include "../header/proto.h"
 

void gestionInputs(Input *input)
{
    //On gère le clavier (on rajoutera plus tard la gestion
    //des joysticks)
    getInput(input);
}
 
void getInput(Input *input)
{
    SDL_Event event;
 
    /* Keymapping : gère les appuis sur les touches et les enregistre
    dans la structure input */
 
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                exit(0);
            break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        exit(0);
                    break;
 
                    case SDLK_DELETE:
                        input->erase = 1;
                    break;
 
                    case SDLK_z:
                        input->shield = 1;
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
 
 
                    default:
                    break;
                }
            break;
 
            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {
                    case SDLK_DELETE:
                        input->erase = 0;
                    break;
 
                    case SDLK_z:
                        input->shield = 0;
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
 
                    default:
                    break;
                }
            break;
 
        }
 
    }
}

void deplacement (Input *input, Joueur *joueur, Meduse *meduse,  Chauvesouris *chauvesouris, EffetSon *son, Boss *boss)
{  
    
    if (input->left==1)
    {
        joueur->inposx-=3;
        joueur->NumSprit+=1;
        joueur->Direction =1;
    }
    if (input->right==1)
    {
        joueur->inposx+=3;
        joueur->NumSprit+=1;
        joueur->Direction =0;
    }
    if (input->up==1)
    {
        joueur->inposy-=3;
        joueur->NumSprit+=1;   
    }
    if (input->down==1)
    {
        joueur->inposy+=3;
        joueur->NumSprit+=1;
    }
    if (input->attack==1)
    {
        joueur->NumSprit=0;
        joueur->Eattack=1;
    }
    if (input->shield==1)
    {
        joueur->NumSprit=0;
        joueur->Eshield=1;
    }
    if (input->shield==0)
    {
        joueur->Eshield=0;
    }
    SpritHeros(joueur, meduse, input, chauvesouris, son, boss);
}



void deplacementMeduse (Joueur *joueur, Meduse *meduse, Lvl *lvl, EffetSon *son)
{
    meduse->compteur += 1;
    meduse->NumSprit+=1;
    if  (meduse->Life==0 && meduse->CompteurSpriteDegat<19)
    {
        meduse->CompteurSpriteDegat+=1;
    }
    if (meduse->CompteurSpriteDegat==18)
    {
        lvl->MortMonstre+=1;
    }
    
    
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
    SpritMeduse (meduse, joueur, lvl, son);
}


void deplacementChauvesouris (Joueur *joueur, Chauvesouris *chauvesouris, Lvl *lvl, EffetSon *son)
{
    chauvesouris->NumSprit+=1;
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
    SpritChauvesouris (chauvesouris, joueur, lvl, son);
}

void deplacementBoss (Joueur *joueur, Boss *boss, Lvl *lvl, Input *input, EffetSon *son)
{
    boss->compteur += 1;
    boss->NumSprit+=1;
    //gestion compteur mort
    if (boss->CompteurSpriteDegat==21 && insideBoss(joueur, boss)==1 && input->enter == 1)
    {
        boss->CompteurSpriteDegat=22;
    }
    if  (boss->Life==0 && boss->CompteurSpriteDegat<21)
    {
        boss->CompteurSpriteDegat+=1;
    }
    if (boss->CompteurSpriteDegat==18)
    {
        lvl->MortMonstre+=1;
    }
    if (boss->compteur > 200 && boss->compteur < 280)
    {
        boss->CompteurSpriteEclair+=1;
    }
    
    
    if (boss->compteur <= 400 && boss->Life >=1 && boss->compteur%2==0)
    {
        if (joueur->inposx<boss->posmonsx)
        {
            boss->posmonsx-=1;
        }
        if (joueur->inposx>boss->posmonsx)
        {
            boss->posmonsx+=1;   
        }
        if (joueur->inposy<boss->posmonsy)
        {
            boss->posmonsy-=1;
        }
        if (joueur->inposy>boss->posmonsy)
        {
            boss->posmonsy+=1;
        }

    }
    SpritBoss (boss, joueur, lvl, son);
}