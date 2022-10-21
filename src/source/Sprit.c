#include "../header/proto.h" 
void SpritHeros(Joueur *joueur, Meduse *meduse, Input *input)
{
    if(joueur->Eattack==0)
    {
        if (joueur->Direction ==0)
        {
            if( meduse->coup == 0)
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
            if (meduse->coup == 0)
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
                if(insidechevalier(joueur, meduse, input)==1 && joueur->Numattack==15)
                {   
                meduse->Life--;
                  
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

                if(insidechevalier(joueur, meduse, input)==1 && joueur->Numattack==15)
                {
                meduse->Life--;

                }
            }
        }
        if(joueur->Numattack > 24)
        {
            joueur->Numattack=0;
            joueur->Eattack = 0;
        }
    }
}

void SpritMeduse (Meduse *meduse, Joueur *joueur)
{
    if (joueur ->compteur <= 100)
    {
    if (meduse->NumSprit==0 || meduse->NumSprit==1 || meduse->NumSprit==3 || meduse->NumSprit==4 )
        {
            SDL_Texture *Spritemonstre=loadImage("src/graphics/Meduseneutre.png");
            drawImage(Spritemonstre,meduse->posmonsx,meduse->posmonsy);
        }
        if (meduse->NumSprit==5 || meduse->NumSprit==6 || meduse->NumSprit==7 || meduse->NumSprit==8 || meduse->NumSprit==31 || meduse->NumSprit==32 || meduse->NumSprit==33 || meduse->NumSprit==34 )
        {
            SDL_Texture *Spritemonstre=loadImage("src/graphics/Medusemarche1.png");
            drawImage(Spritemonstre,meduse->posmonsx,meduse->posmonsy);
        }
        if (meduse->NumSprit==9 || meduse->NumSprit==10 || meduse->NumSprit==11 || meduse->NumSprit==12|| meduse->NumSprit==26 || meduse->NumSprit==27 || meduse->NumSprit==28 || meduse->NumSprit==29 || meduse->NumSprit==30 )
        {
            SDL_Texture *Spritemonstre=loadImage("src/graphics/Medusemarche2.png");
            drawImage(Spritemonstre,meduse->posmonsx,meduse->posmonsy);
        }
        if (meduse->NumSprit==13 || meduse->NumSprit==14 || meduse->NumSprit==15 || meduse->NumSprit==21 || meduse->NumSprit==22 || meduse->NumSprit==23 || meduse->NumSprit==24 || meduse->NumSprit==25 )
        {
            SDL_Texture *Spritemonstre=loadImage("src/graphics/Medusemarche3.png");
            drawImage(Spritemonstre,meduse->posmonsx,meduse->posmonsy);
        }
        if (meduse->NumSprit==17 || meduse->NumSprit==18 || meduse->NumSprit==19 || meduse->NumSprit==20 )
        {
            SDL_Texture *Spritemonstre=loadImage("src/graphics/Medusemarche4.png");
            drawImage(Spritemonstre,meduse->posmonsx,meduse->posmonsy);    
        }
        if (meduse->NumSprit>=35 )
        {
        SDL_Texture *Spritemonstre=loadImage("src/graphics/Medusemarche1.png");
        drawImage(Spritemonstre,meduse->posmonsx,meduse->posmonsy);
        //meduse->attack+=1;
        }
    
    if (meduse->NumSprit>=35)
    {
        meduse->NumSprit =0;
    }
    }
    if  (joueur->compteur>100)
    {
        printf("%d \n", meduse->NumSprit);
        if (meduse->NumSprit==0 || meduse->NumSprit==1 || meduse->NumSprit==3 || meduse->NumSprit==4 )
        {
            SDL_Texture *Spritemonstre=loadImage("src/graphics/medusecoup1.png");
            drawImage(Spritemonstre,meduse->posmonsx,meduse->posmonsy);
        }
        if (meduse->NumSprit==5 || meduse->NumSprit==6 || meduse->NumSprit==7 || meduse->NumSprit==8 || meduse->NumSprit==31 || meduse->NumSprit==32 || meduse->NumSprit==33 || meduse->NumSprit==34 )
        {
            SDL_Texture *Spritemonstre=loadImage("src/graphics/medusecoup2.png");
            drawImage(Spritemonstre,meduse->posmonsx,meduse->posmonsy);
        }
        if (meduse->NumSprit==9 || meduse->NumSprit==10 || meduse->NumSprit==11 || meduse->NumSprit==12|| meduse->NumSprit==26 || meduse->NumSprit==27 || meduse->NumSprit==28 || meduse->NumSprit==29 || meduse->NumSprit==30 )
        {
            SDL_Texture *Spritemonstre=loadImage("src/graphics/medusecoup3.png");
            drawImage(Spritemonstre,meduse->posmonsx,meduse->posmonsy);
        }
        if (meduse->NumSprit==13 || meduse->NumSprit==14 || meduse->NumSprit==15 || meduse->NumSprit==21 || meduse->NumSprit==22 || meduse->NumSprit==23 || meduse->NumSprit==24 || meduse->NumSprit==25 )
        {
            SDL_Texture *Spritemonstre=loadImage("src/graphics/medusecoup4.png");
            drawImage(Spritemonstre,meduse->posmonsx,meduse->posmonsy);
            SDL_Texture *Spriteattaque=loadImage("src/graphics/AttaqueMeduse.png");
            drawImage(Spriteattaque,meduse->posmonsx -23 ,meduse->posmonsy - 23);

            if(inside(joueur, meduse)==1 && (meduse->NumSprit==25 || meduse->NumSprit==15))
            {
                if (meduse->coup == 0)
                {
                    joueur->life--;
                    meduse->coup =1 ;
                }
            }
        }
        if (meduse->NumSprit==17 || meduse->NumSprit==18 || meduse->NumSprit==19 || meduse->NumSprit==20 )
        {
            SDL_Texture *Spritemonstre=loadImage("src/graphics/medusecoup2.png");
            drawImage(Spritemonstre,meduse->posmonsx,meduse->posmonsy);
        }
        if (joueur->compteur>140)
        {
            joueur->compteur=0;
            meduse->coup = 0;
        }
        if (meduse->NumSprit>=35)
        {
            meduse->NumSprit =0;
        }
    }
}