#include "../header/proto.h"
 
Input input;
Joueur joueur;
Meduse meduse;

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
 
                    case SDLK_c:
                        input->jump = 1;
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
 
                    case SDLK_c:
                        input->jump = 0;
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

void deplacement (Input *input, Joueur *joueur)
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
    SpritHeros(joueur, &meduse, input);
}



void deplacementMeduse (Joueur *joueur, Meduse *meduse)
{
    meduse->compteur += 1;
    meduse->NumSprit+=1;
    if  (meduse->Life==0 && meduse->CompteurSpriteDegat<19)
    {
        meduse->CompteurSpriteDegat+=1;
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
    SpritMeduse (meduse, joueur);
}

