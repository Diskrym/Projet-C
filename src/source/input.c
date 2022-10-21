#include "../header/proto.h"
 
Input input;
Joueur joueur;
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

void deplacement (Input *input, Joueur *joueur, Monstre *monstre)
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
    if(joueur->Eattack==0)
    {
        if (joueur->Direction ==0)
        {
            if( monstre->coup == 0)
            {
                if (joueur->NumSprit==0 || joueur->NumSprit ==1 || joueur->NumSprit==4 || joueur->NumSprit ==5)
                {
                    SDL_Texture *chevalier=loadImage("src/graphics/neutreD.png");
                    drawImage(chevalier,joueur->inposx,joueur->inposy);
                }
                if (joueur->NumSprit==2 || joueur->NumSprit==3  )
                {
                    SDL_Texture *chevalier=loadImage("src/graphics/marche1D.png");
                    drawImage(chevalier,joueur->inposx,joueur->inposy);
                }
                if (joueur->NumSprit >=7 || joueur->NumSprit ==6 )
                {
                    SDL_Texture *chevalier=loadImage("src/graphics/marche2D.png");
                    drawImage(chevalier,joueur->inposx,joueur->inposy);
                    joueur->NumSprit =0;
                }
            }
            else
            {
                SDL_Texture *chevalier=loadImage("src/graphics/DégatD.png");
                drawImage(chevalier,joueur->inposx,joueur->inposy);
            }
        }
        if (joueur->Direction ==1)
        {
            if (monstre->coup == 0)
            {
                if (joueur->NumSprit==0 || joueur->NumSprit ==1 || joueur->NumSprit==4 || joueur->NumSprit ==5)
                {
                    SDL_Texture *chevalier=loadImage("src/graphics/neutreG.png");
                    drawImage(chevalier,joueur->inposx,joueur->inposy);
                }
                if (joueur->NumSprit==2 || joueur->NumSprit==3  )
                {
                    SDL_Texture *chevalier=loadImage("src/graphics/marche1G.png");
                    drawImage(chevalier,joueur->inposx,joueur->inposy);
                }
                if (joueur->NumSprit >=7 || joueur->NumSprit ==6 )
                {
                    SDL_Texture *chevalier=loadImage("src/graphics/marche2G.png");
                    drawImage(chevalier,joueur->inposx,joueur->inposy);
                    joueur->NumSprit =0;
                }   
            }
            else
            {
                SDL_Texture *chevalier=loadImage("src/graphics/DégatG.png");
                drawImage(chevalier,joueur->inposx,joueur->inposy);
            }
        }
    }
    if (joueur->Eattack==1)
    {
        joueur->Numattack+=1;
        if (joueur->Direction==1)
        {   
            if (joueur->Numattack==0 || joueur->Numattack==1 || joueur->Numattack==3 || joueur->Numattack==4 )
            {
                SDL_Texture *Spritechevalier=loadImage("src/graphics/Epee2G.png");
                drawImage(Spritechevalier,joueur->inposx,joueur->inposy);
            }
            if (joueur->Numattack==5 || joueur->Numattack==6 || joueur->Numattack==7 || joueur->Numattack==8 || joueur->Numattack==21 || joueur->Numattack==22 || joueur->Numattack==23 || joueur->Numattack==24 )
            {
                SDL_Texture *Spritechevalier=loadImage("src/graphics/Epee3G.png");
                drawImage(Spritechevalier,joueur->inposx,joueur->inposy);
            }
            if (joueur->Numattack==9 || joueur->Numattack==10 || joueur->Numattack==11 || joueur->Numattack==12|| joueur->Numattack==17 || joueur->Numattack==18 || joueur->Numattack==19 || joueur->Numattack==20 )
            {
                SDL_Texture *Spritechevalier=loadImage("src/graphics/Epee4G.png");
                drawImage(Spritechevalier,joueur->inposx,joueur->inposy);
            }
            if (joueur->Numattack==13 || joueur->Numattack==14 || joueur->Numattack==15 || joueur->Numattack==16 )
            {
                SDL_Texture *Spritechevalier=loadImage("src/graphics/Epee5G.png");
                drawImage(Spritechevalier,joueur->inposx,joueur->inposy);
                SDL_Texture *Spriteattaque=loadImage("src/graphics/attaqueG.png");
                drawImage(Spriteattaque,joueur->inposx-21,joueur->inposy+32);
                if(insidechevalier(joueur, monstre, input)==1 && joueur->Numattack==15)
                {   
                monstre->Life--;  
                }
            }
            if (joueur->Numattack==17 || joueur->Numattack==18 || joueur->Numattack==19 || joueur->Numattack==20 )
            {
                SDL_Texture *Spritechevalier=loadImage("src/graphics/Epee2G.png");
                drawImage(Spritechevalier,joueur->inposx,joueur->inposy);
            }
        }
        if (joueur->Direction==0)
        {
            if (joueur->Numattack==0 || joueur->Numattack==1 || joueur->Numattack==3 || joueur->Numattack==4 )
            {
                SDL_Texture *Spritechevalier=loadImage("src/graphics/Epee2D.png");
                drawImage(Spritechevalier,joueur->inposx,joueur->inposy);
            }
            if (joueur->Numattack==5 || joueur->Numattack==6 || joueur->Numattack==7 || joueur->Numattack==8 || joueur->Numattack==21 || joueur->Numattack==22 || joueur->Numattack==23 || joueur->Numattack==24 )
            {
                SDL_Texture *Spritechevalier=loadImage("src/graphics/Epee3D.png");
                drawImage(Spritechevalier,joueur->inposx,joueur->inposy);
            }
            if (joueur->Numattack==9 || joueur->Numattack==10 || joueur->Numattack==11 || joueur->Numattack==12|| joueur->Numattack==17 || joueur->Numattack==18 || joueur->Numattack==19 || joueur->Numattack==20 )
            {
                SDL_Texture *Spritechevalier=loadImage("src/graphics/Epee4D.png");
                drawImage(Spritechevalier,joueur->inposx,joueur->inposy);
            }
            if (joueur->Numattack==13 || joueur->Numattack==14 || joueur->Numattack==15 || joueur->Numattack==16 )
            {
                SDL_Texture *Spritechevalier=loadImage("src/graphics/Epee5D.png");
                drawImage(Spritechevalier,joueur->inposx,joueur->inposy);
                SDL_Texture *Spriteattaque=loadImage("src/graphics/attaqueD.png");
                drawImage(Spriteattaque,joueur->inposx+SPRITE_SIZE ,joueur->inposy +32);

                if(insidechevalier(joueur, monstre, input)==1 && joueur->Numattack==15)
                {
                monstre->Life--;
                }
            }
        }
        if(joueur->Numattack > 24)
        {
            joueur->Numattack=0;
            joueur->Eattack = 0;
            printf("%d\n",joueur->Numattack);
        }
    }
}



void deplacementMonstre (Joueur *joueur, Monstre *monstre, Input *input)
{
    joueur->compteur += 1;
    monstre->NumSprit+=1;
    
    if (joueur ->compteur <= 100)
    {
        if (joueur->inposx<monstre->posmonsx)
        {
            monstre->posmonsx-=1;
            monstre->Direction=0;
        }
        if (joueur->inposx>monstre->posmonsx)
        {
            monstre->posmonsx+=1;
            monstre->Direction=0;    
        }
        if (joueur->inposy<monstre->posmonsy)
        {
            monstre->posmonsy-=1;
            monstre->Direction=0;  
        }
        if (joueur->inposy>monstre->posmonsy)
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
    if  (joueur->compteur>100)
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

            if(inside(joueur, monstre)==1 && (monstre->NumSprit==25 || monstre->NumSprit==15))
            {
                if (monstre->coup == 0)
                {
                    joueur->life--;
                    monstre->coup =1 ;
                }
            }
        }
        if (monstre->NumSprit==17 || monstre->NumSprit==18 || monstre->NumSprit==19 || monstre->NumSprit==20 )
        {
            SDL_Texture *Spritemonstre=loadImage("src/graphics/medusecoup2.png");
            drawImage(Spritemonstre,monstre->posmonsx,monstre->posmonsy);
        }
        if (joueur->compteur>140)
        {
            joueur->compteur=0;
            monstre->coup = 0;
        }
    }
}

