#include "../header/proto.h"
 
Input input;
Pos pos;
Monstre monstre;

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

void deplacement (Input *input, Pos *pos)
{
    if (input->left==1)
    {
        pos->inposx-=5;
        input->NumSprit+=1;
        input->Direction =1;

        
    }

    if (input->right==1)
    {
        pos->inposx+=5;
        input->NumSprit+=1;
        input->Direction =0;
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
        if (input->NumSprit==0 || input->NumSprit ==1 || input->NumSprit==4 || input->NumSprit ==5)
        {
            SDL_Texture *chevalier=loadImage("src/graphics/neutreD.png");
            drawImage(chevalier,pos->inposx,pos->inposy);
        }
        if (input->NumSprit==2 || input->NumSprit==3  )
        {
            SDL_Texture *chevalier=loadImage("src/graphics/marche1D.png");
            drawImage(chevalier,pos->inposx,pos->inposy);
        }
        if (input->NumSprit >=7 || input->NumSprit ==6 )
        {
            SDL_Texture *chevalier=loadImage("src/graphics/marche2D.png");
            drawImage(chevalier,pos->inposx,pos->inposy);
            input->NumSprit =0;
        }
    }

    if (input->Direction ==1)
    {
        if (input->NumSprit==0 || input->NumSprit ==1 || input->NumSprit==4 || input->NumSprit ==5)
        {
            SDL_Texture *chevalier=loadImage("src/graphics/neutreG.png");
            drawImage(chevalier,pos->inposx,pos->inposy);
        }
        if (input->NumSprit==2 || input->NumSprit==3  )
        {
            SDL_Texture *chevalier=loadImage("src/graphics/marche1G.png");
            drawImage(chevalier,pos->inposx,pos->inposy);
        }
        if (input->NumSprit >=7 || input->NumSprit ==6 )
        {
            SDL_Texture *chevalier=loadImage("src/graphics/marche2G.png");
            drawImage(chevalier,pos->inposx,pos->inposy);
            input->NumSprit =0;
        }
    }
}


void deplacementMonstre (Pos *pos, Monstre *monstre)
{
    if (pos->inposx<monstre->posmonsx)
    {
        monstre->posmonsx-=2;
        monstre->NumSprit+=1;
        monstre->Direction=0;
    
        
    }

    if (pos->inposx>monstre->posmonsx)
    {
        monstre->posmonsx+=2;
        monstre->NumSprit+=1;
        monstre->Direction=0;
    
        
    }
    if (pos->inposy<monstre->posmonsy)
    {
        monstre->posmonsy-=2;
        monstre->NumSprit+=1;
        monstre->Direction=0;
        
        
    }
    if (pos->inposy>monstre->posmonsy)
    {
        monstre->posmonsy+=2;
        monstre->NumSprit+=1;
        monstre->Direction=1;
        
        
    }
    


        if (monstre->NumSprit==0 || monstre->NumSprit==1 || monstre->NumSprit==3 || monstre->NumSprit==4 )
        {
            SDL_Texture *Spritemonstre=loadImage("src/graphics/Meduseneutre.png");
            drawImage(Spritemonstre,monstre->posmonsx,monstre->posmonsy);
        }
        if (monstre->NumSprit==5 || monstre->NumSprit==6 || monstre->NumSprit==7 || monstre->NumSprit==8 || monstre->NumSprit==31 || monstre->NumSprit==32 || monstre->NumSprit==33 || monstre->NumSprit==34 )
        {
            SDL_Texture *Spritemonstre=loadImage("src/graphics/Medusemarche1.png");
            drawImage(Spritemonstre,monstre->posmonsx,monstre->posmonsy);
        }
        if (monstre->NumSprit==9 || monstre->NumSprit==10 || monstre->NumSprit==11 || monstre->NumSprit==12|| monstre->NumSprit==26 || monstre->NumSprit==27 || monstre->NumSprit==28 || monstre->NumSprit==29 || monstre->NumSprit==30 )
        {
            SDL_Texture *Spritemonstre=loadImage("src/graphics/Medusemarche2.png");
            drawImage(Spritemonstre,monstre->posmonsx,monstre->posmonsy);
        }
        if (monstre->NumSprit==13 || monstre->NumSprit==14 || monstre->NumSprit==15 || monstre->NumSprit==21 || monstre->NumSprit==22 || monstre->NumSprit==23 || monstre->NumSprit==24 || monstre->NumSprit==25 )
        {
            SDL_Texture *Spritemonstre=loadImage("src/graphics/Medusemarche3.png");
            drawImage(Spritemonstre,monstre->posmonsx,monstre->posmonsy);
        }
        if (monstre->NumSprit==17 || monstre->NumSprit==18 || monstre->NumSprit==19 || monstre->NumSprit==20 )
        {
            SDL_Texture *Spritemonstre=loadImage("src/graphics/Medusemarche4.png");
            drawImage(Spritemonstre,monstre->posmonsx,monstre->posmonsy);
            
        }

        if (monstre->NumSprit>=35 )

       {SDL_Texture *Spritemonstre=loadImage("src/graphics/Medusemarche1.png");
        drawImage(Spritemonstre,monstre->posmonsx,monstre->posmonsy);
        monstre->NumSprit =0;}

    //if (monstre->attack==2)

}