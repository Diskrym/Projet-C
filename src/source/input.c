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
        pos->inposx-=3;
        input->NumSprit+=1;
        input->Direction =1;
    }
    if (input->right==1)
    {
        pos->inposx+=3;
        input->NumSprit+=1;
        input->Direction =0;
    }
    if (input->up==1)
    {
        pos->inposy-=3;
        input->NumSprit+=1;   
    }
    if (input->down==1)
    {
        pos->inposy+=3;
        input->NumSprit+=1;
    }
    if (input->Direction ==0)
    {
        if( pos->coup == 0)
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
        else
        {
            SDL_Texture *chevalier=loadImage("src/graphics/DégatD.png");
            drawImage(chevalier,pos->inposx,pos->inposy);
            
        }
    }

    if (input->Direction ==1)
    {
        if (pos->coup == 0)
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
        else
        {
            SDL_Texture *chevalier=loadImage("src/graphics/DégatG.png");
            drawImage(chevalier,pos->inposx,pos->inposy);
        }
    }
}


void deplacementMonstre (Pos *pos, Monstre *monstre, Input *input)
{
    pos->compteur += 1;
    monstre->NumSprit+=1;
    
    if (pos ->compteur <= 100)
    {
        if (pos->inposx<monstre->posmonsx)
        {
            monstre->posmonsx-=1;
            monstre->Direction=0;
        }
        if (pos->inposx>monstre->posmonsx)
        {
            monstre->posmonsx+=1;
            monstre->Direction=0;    
        }
        if (pos->inposy<monstre->posmonsy)
        {
            monstre->posmonsy-=1;
            monstre->Direction=0;  
        }
        if (pos->inposy>monstre->posmonsy)
        {
            monstre->posmonsy+=1;
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
        {
        SDL_Texture *Spritemonstre=loadImage("src/graphics/Medusemarche1.png");
        drawImage(Spritemonstre,monstre->posmonsx,monstre->posmonsy);
        //monstre->attack+=1;
        }
    }
    if (monstre->NumSprit>=35)
    {
        monstre->NumSprit =0;
    }
    if  (pos->compteur>100)
    {
        if (monstre->NumSprit==0 || monstre->NumSprit==1 || monstre->NumSprit==3 || monstre->NumSprit==4 )
        {
            SDL_Texture *Spritemonstre=loadImage("src/graphics/medusecoup1.png");
            drawImage(Spritemonstre,monstre->posmonsx,monstre->posmonsy);
        }
        if (monstre->NumSprit==5 || monstre->NumSprit==6 || monstre->NumSprit==7 || monstre->NumSprit==8 || monstre->NumSprit==31 || monstre->NumSprit==32 || monstre->NumSprit==33 || monstre->NumSprit==34 )
        {
            SDL_Texture *Spritemonstre=loadImage("src/graphics/medusecoup2.png");
            drawImage(Spritemonstre,monstre->posmonsx,monstre->posmonsy);
        }
        if (monstre->NumSprit==9 || monstre->NumSprit==10 || monstre->NumSprit==11 || monstre->NumSprit==12|| monstre->NumSprit==26 || monstre->NumSprit==27 || monstre->NumSprit==28 || monstre->NumSprit==29 || monstre->NumSprit==30 )
        {
            SDL_Texture *Spritemonstre=loadImage("src/graphics/medusecoup3.png");
            drawImage(Spritemonstre,monstre->posmonsx,monstre->posmonsy);
        }
        if (monstre->NumSprit==13 || monstre->NumSprit==14 || monstre->NumSprit==15 || monstre->NumSprit==21 || monstre->NumSprit==22 || monstre->NumSprit==23 || monstre->NumSprit==24 || monstre->NumSprit==25 )
        {
            SDL_Texture *Spritemonstre=loadImage("src/graphics/medusecoup4.png");
            drawImage(Spritemonstre,monstre->posmonsx,monstre->posmonsy);
            SDL_Texture *Spriteattaque=loadImage("src/graphics/AttaqueMeduse.png");
            drawImage(Spriteattaque,monstre->posmonsx -23 ,monstre->posmonsy - 23);

            if(inside(pos, monstre)==1 && (monstre->NumSprit==25 || monstre->NumSprit==15))
            {
                if (pos->coup == 0)
                {
                    input->Life--;
                    pos->coup =1 ;
                }
            }
        }
        if (monstre->NumSprit==17 || monstre->NumSprit==18 || monstre->NumSprit==19 || monstre->NumSprit==20 )
        {
            SDL_Texture *Spritemonstre=loadImage("src/graphics/medusecoup2.png");
            drawImage(Spritemonstre,monstre->posmonsx,monstre->posmonsy);
        }
        if (pos->compteur>140)
        {
            pos->compteur=0;
            pos->coup = 0;
        }
    }
}


void attaque (Input *input , Pos *pos)
{
if (input->Direction==1)
{
if (input->NumSprit==0 || input->NumSprit==1 || input->NumSprit==3 || input->NumSprit==4 )
        {
            SDL_Texture *Spritechevalier=loadImage("src/graphics/Epee2G.png");
            drawImage(Spritechevalier,pos->inposx,pos->inposy);
        }
        if (input->NumSprit==5 || input->NumSprit==6 || input->NumSprit==7 || input->NumSprit==8 || input->NumSprit==31 || input->NumSprit==32 || input->NumSprit==33 || input->NumSprit==34 )
       {
            SDL_Texture *Spritechevalier=loadImage("src/graphics/Epee3G.png");
            drawImage(Spritechevalier,pos->inposx,pos->inposy);
        }
        if (input->NumSprit==9 || input->NumSprit==10 || input->NumSprit==11 || input->NumSprit==12|| input->NumSprit==26 || input->NumSprit==27 || input->NumSprit==28 || input->NumSprit==29 || input->NumSprit==30 )
        {
            SDL_Texture *Spritechevalier=loadImage("src/graphics/Epee4G.png");
            drawImage(Spritechevalier,pos->inposx,pos->inposy);
        }
        if (input->NumSprit==13 || input->NumSprit==14 || input->NumSprit==15 || input->NumSprit==21 || input->NumSprit==22 || input->NumSprit==23 || input->NumSprit==24 || input->NumSprit==25 )
        {
            SDL_Texture *Spritechevalier=loadImage("src/graphics/Epee5G.png");
            drawImage(Spritechevalier,pos->inposx,pos->inposy);
            SDL_Texture *Spriteattaque=loadImage("src/graphics/attaqueG.png");
            drawImage(Spriteattaque,pos->inposx -23 ,pos->inposy - 23);

            if(inside(pos, &monstre)==1 && (input->NumSprit==25 || input->NumSprit==15))
            {
                if (pos->coup == 0)
                {
                    input->Life--;
                    pos->coup =1 ;
                }
            }
        }
        if (input->NumSprit==17 || input->NumSprit==18 || input->NumSprit==19 || input->NumSprit==20 )
        {
            SDL_Texture *Spritechevalier=loadImage("src/graphics/Epee2G.png");
            drawImage(Spritechevalier,pos->inposx,pos->inposy);

}
if (input->Direction==0)
{
if (input->NumSprit==0 || input->NumSprit==1 || input->NumSprit==3 || input->NumSprit==4 )
        {
            SDL_Texture *Spritechevalier=loadImage("src/graphics/Epee2D.png");
            drawImage(Spritechevalier,pos->inposx,pos->inposy);
        }
        if (input->NumSprit==5 || input->NumSprit==6 || input->NumSprit==7 || input->NumSprit==8 || input->NumSprit==31 || input->NumSprit==32 || input->NumSprit==33 || input->NumSprit==34 )
       {
            SDL_Texture *Spritechevalier=loadImage("src/graphics/Epee3D.png");
            drawImage(Spritechevalier,pos->inposx,pos->inposy);
        }
        if (input->NumSprit==9 || input->NumSprit==10 || input->NumSprit==11 || input->NumSprit==12|| input->NumSprit==26 || input->NumSprit==27 || input->NumSprit==28 || input->NumSprit==29 || input->NumSprit==30 )
        {
            SDL_Texture *Spritechevalier=loadImage("src/graphics/Epee4D.png");
            drawImage(Spritechevalier,pos->inposx,pos->inposy);
        }
        if (input->NumSprit==13 || input->NumSprit==14 || input->NumSprit==15 || input->NumSprit==21 || input->NumSprit==22 || input->NumSprit==23 || input->NumSprit==24 || input->NumSprit==25 )
        {
            SDL_Texture *Spritechevalier=loadImage("src/graphics/Epee5D.png");
            drawImage(Spritechevalier,pos->inposx,pos->inposy);
            SDL_Texture *Spriteattaque=loadImage("src/graphics/attaqueD.png");
            drawImage(Spriteattaque,pos->inposx -23 ,pos->inposy - 23);

            if(inside(pos, &monstre)==1 && (input->NumSprit==25 || input->NumSprit==15))
            {
                if (pos->coup == 0)
                {
                    input->Life--;
                    pos->coup =1 ;
                }
            }
        }
        if (input->NumSprit==17 || input->NumSprit==18 || input->NumSprit==19 || input->NumSprit==20 )
        {
            SDL_Texture *Spritechevalier=loadImage("src/graphics/Epee2D.png");
            drawImage(Spritechevalier,pos->inposx,pos->inposy);

}
}
}