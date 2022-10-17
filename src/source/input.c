#include "../header/proto.h"
 

Pos pos;

void gestionInputs(Input *input)
{
    //On gère le clavier (on rajoutera plus tard la gestion
    //des joysticks)
    getInput(input);
}
 
 
void getInput(Input *input )
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
 
                    case SDLK_v:
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
 
                    default:
                    break;
                }
            break;
 
        }
 
    }
}

void deplacement (Input *input, Pos *pos){
if (input->left==1)
{
    pos->inposx-=5;
    input->NumSprit+=1;

}
if (input->right==1)
{
    pos->inposx+=5;
    input->NumSprit+=1;
}
if (input->up==1)
{
    pos->inposy-=5;
    input->NumSprit+=1;
}
if (input->down==1)
{
    pos->inposy+=5;
    input->NumSprit+=1;
}

if (input->Direction ==0)
{
if (input->NumSprit==0 || input->NumSprit ==2 )
{SDL_Texture *chevalier=loadImage("src/graphics/neutreD.png");
drawImage(chevalier,pos->inposx,pos->inposy);}
if (input->NumSprit ==1 )
{SDL_Texture *chevalier=loadImage("src/graphics/marche1D.png");
drawImage(chevalier,pos->inposx,pos->inposy);}
if (input->NumSprit ==3 )
{SDL_Texture *chevalier=loadImage("src/graphics/marche2D.png");
drawImage(chevalier,pos->inposx,pos->inposy);
input->NumSprit =0;}
}

if (input->Direction ==1)
{if (input->NumSprit ==0 || input->NumSprit ==2 )
{SDL_Texture *chevalier=loadImage("src/graphics/neutreG.png");
drawImage(chevalier,pos->inposx,pos->inposy);}
if (input->NumSprit ==1 )
{SDL_Texture *chevalier=loadImage("src/graphics/marche1G.png");
drawImage(chevalier,pos->inposx,pos->inposy);}
if (input->NumSprit ==3 )
{SDL_Texture *chevalier=loadImage("src/graphics/marche2G.png");
drawImage(chevalier,pos->inposx,pos->inposy);
input->NumSprit =0;}
}
}
