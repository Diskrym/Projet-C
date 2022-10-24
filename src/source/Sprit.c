#include "../header/proto.h" 
void SpritHeros(Joueur *joueur, Meduse *meduse, Input *input)
{
    //Mouvement joueur de base avec direction 0 pour droite et 1 gauche
    if(joueur->Eattack==0)
    {
        if (joueur->Direction ==0)
        {
            if( meduse->coup == 0)
            {
                if (joueur->NumSprit==0 || joueur->NumSprit ==1 || joueur->NumSprit==4 || joueur->NumSprit ==5)
                {
                    SDL_Texture *chevalier=loadImage("src/graphics/Chevalier/neutreD.png");
                    drawImage(chevalier,joueur->inposx,joueur->inposy);
                }
                if (joueur->NumSprit==2 || joueur->NumSprit==3  )
                {
                    SDL_Texture *chevalier=loadImage("src/graphics/Chevalier/marche1D.png");
                    drawImage(chevalier,joueur->inposx,joueur->inposy);
                }
                if (joueur->NumSprit >=7 || joueur->NumSprit ==6 )
                {
                    SDL_Texture *chevalier=loadImage("src/graphics/Chevalier/marche2D.png");
                    drawImage(chevalier,joueur->inposx,joueur->inposy);
                    joueur->NumSprit =0;
                }
            }
            else
            {
                SDL_Texture *chevalier=loadImage("src/graphics/Chevalier/DégatD.png");
                drawImage(chevalier,joueur->inposx,joueur->inposy);
            }
        }
        if (joueur->Direction ==1)
        {
            if (meduse->coup == 0)
            {
                if (joueur->NumSprit==0 || joueur->NumSprit ==1 || joueur->NumSprit==4 || joueur->NumSprit ==5)
                {
                    SDL_Texture *chevalier=loadImage("src/graphics/Chevalier/neutreG.png");
                    drawImage(chevalier,joueur->inposx,joueur->inposy);
                }
                if (joueur->NumSprit==2 || joueur->NumSprit==3  )
                {
                    SDL_Texture *chevalier=loadImage("src/graphics/Chevalier/marche1G.png");
                    drawImage(chevalier,joueur->inposx,joueur->inposy);
                }
                if (joueur->NumSprit >=7 || joueur->NumSprit ==6 )
                {
                    SDL_Texture *chevalier=loadImage("src/graphics/Chevalier/marche2G.png");
                    drawImage(chevalier,joueur->inposx,joueur->inposy);
                    joueur->NumSprit =0;
                }   
            }
            else
            {
                SDL_Texture *chevalier=loadImage("src/graphics/Chevalier/DégatG.png");
                drawImage(chevalier,joueur->inposx,joueur->inposy);
            }
        }
    }

    //Mouvement attaque 
    if (joueur->Eattack==1)
    {
        joueur->Numattack+=1;
        if (joueur->Direction==1)
        {   
            if (joueur->Numattack==0 || joueur->Numattack==1 || joueur->Numattack==2 || joueur->Numattack==3 )
            {
                SDL_Texture *Spritechevalier=loadImage("src/graphics/Chevalier/Epee2G.png");
                drawImage(Spritechevalier,joueur->inposx,joueur->inposy);
            }
            if (joueur->Numattack==4 || joueur->Numattack==5 || joueur->Numattack==6 || joueur->Numattack==7 || joueur->Numattack==20 || joueur->Numattack==21 || joueur->Numattack==22 || joueur->Numattack==23 )
            {
                SDL_Texture *Spritechevalier=loadImage("src/graphics/Chevalier/Epee3G.png");
                drawImage(Spritechevalier,joueur->inposx,joueur->inposy);
            }
            if (joueur->Numattack==8 || joueur->Numattack==9 || joueur->Numattack==10 || joueur->Numattack==11|| joueur->Numattack==16 || joueur->Numattack==17 || joueur->Numattack==18 || joueur->Numattack==19)
            {
                SDL_Texture *Spritechevalier=loadImage("src/graphics/Chevalier/Epee4G.png");
                drawImage(Spritechevalier,joueur->inposx,joueur->inposy);
            }
            if (joueur->Numattack==12 || joueur->Numattack==13 || joueur->Numattack==14 || joueur->Numattack==15 )
            {
                SDL_Texture *Spritechevalier=loadImage("src/graphics/Chevalier/Epee5G.png");
                drawImage(Spritechevalier,joueur->inposx,joueur->inposy);
                SDL_Texture *Spriteattaque=loadImage("src/graphics/Chevalier/attaqueG.png");
                drawImage(Spriteattaque,joueur->inposx-21,joueur->inposy+32);
            }
        }
        if (joueur->Direction==0)
        {
            if (joueur->Numattack==0 || joueur->Numattack==1 || joueur->Numattack==2 || joueur->Numattack==3 )
            {
                SDL_Texture *Spritechevalier=loadImage("src/graphics/Chevalier/Epee2D.png");
                drawImage(Spritechevalier,joueur->inposx,joueur->inposy);
            }
            if (joueur->Numattack==4 || joueur->Numattack==5 || joueur->Numattack==6 || joueur->Numattack==7 || joueur->Numattack==20 || joueur->Numattack==21 || joueur->Numattack==22 || joueur->Numattack==23 )
            {
                SDL_Texture *Spritechevalier=loadImage("src/graphics/Chevalier/Epee3D.png");
                drawImage(Spritechevalier,joueur->inposx,joueur->inposy);
            }
            if (joueur->Numattack==8 || joueur->Numattack==9 || joueur->Numattack==10 || joueur->Numattack==11|| joueur->Numattack==16 || joueur->Numattack==17 || joueur->Numattack==18 || joueur->Numattack==19)
            {
                SDL_Texture *Spritechevalier=loadImage("src/graphics/Chevalier/Epee4D.png");
                drawImage(Spritechevalier,joueur->inposx,joueur->inposy);
            }
            if (joueur->Numattack==12 || joueur->Numattack==13 || joueur->Numattack==14 || joueur->Numattack==15 )
            {
                SDL_Texture *Spritechevalier=loadImage("src/graphics/Chevalier/Epee5D.png");
                drawImage(Spritechevalier,joueur->inposx,joueur->inposy);
                SDL_Texture *Spriteattaque=loadImage("src/graphics/Chevalier/attaqueD.png");
                drawImage(Spriteattaque,joueur->inposx+SPRITE_SIZE ,joueur->inposy +32);
            }
        }

        //reset des compteur pour sprite et attaque
        if(joueur->Numattack >= 23)
        {
            joueur->Numattack=0;
            joueur->Eattack = 0;
        }
    }
}

void SpritMeduse (Meduse *meduse, Joueur *joueur, Lvl *lvl)
{   

    //Mouvement  meduse
    if (meduse->Life >=1)
    {
        if (meduse->compteur < 100)
        {
            if (meduse->CompteurSpriteDegat==0)
            {
                if (meduse->NumSprit==0 || meduse->NumSprit==1 || meduse->NumSprit==2 || meduse->NumSprit==3 )
                {
                    SDL_Texture *Spritemonstre=loadImage("src/graphics/Meduse/Meduseneutre.png");
                    drawImage(Spritemonstre,meduse->posmonsx,meduse->posmonsy);
                }
                if (meduse->NumSprit==4 || meduse->NumSprit==5 || meduse->NumSprit==6 || meduse->NumSprit==7 || meduse->NumSprit==29 || meduse->NumSprit==30 || meduse->NumSprit==32 || meduse->NumSprit==31 )
                {
                    SDL_Texture *Spritemonstre=loadImage("src/graphics/Meduse/Medusemarche1.png");
                    drawImage(Spritemonstre,meduse->posmonsx,meduse->posmonsy);
                }
                if (meduse->NumSprit==8 || meduse->NumSprit==9 || meduse->NumSprit==10 || meduse->NumSprit==11|| meduse->NumSprit==24 || meduse->NumSprit==25 || meduse->NumSprit==26 || meduse->NumSprit==27 || meduse->NumSprit==28 )
                {
                    SDL_Texture *Spritemonstre=loadImage("src/graphics/Meduse/Medusemarche2.png");
                    drawImage(Spritemonstre,meduse->posmonsx,meduse->posmonsy);
                }
                if (meduse->NumSprit==12 || meduse->NumSprit==13 || meduse->NumSprit==14 || meduse->NumSprit==19 || meduse->NumSprit==20 || meduse->NumSprit==21 || meduse->NumSprit==22 || meduse->NumSprit==23 )                   
                {
                    SDL_Texture *Spritemonstre=loadImage("src/graphics/Meduse/Medusemarche3.png");
                    drawImage(Spritemonstre,meduse->posmonsx,meduse->posmonsy);
                }
                if (meduse->NumSprit==15 || meduse->NumSprit==16 || meduse->NumSprit==17 || meduse->NumSprit==18 )
                {
                    SDL_Texture *Spritemonstre=loadImage("src/graphics/Meduse/Medusemarche4.png");
                    drawImage(Spritemonstre,meduse->posmonsx,meduse->posmonsy);    
                }
                if (meduse->NumSprit>=33 )
                {
                    SDL_Texture *Spritemonstre=loadImage("src/graphics/Meduse/Medusemarche1.png");
                    drawImage(Spritemonstre,meduse->posmonsx,meduse->posmonsy);
                    meduse->attack+=1;
                }
                if(insidechevalier(joueur, meduse)==1 && joueur->Numattack==15)
                {           
                    meduse->CompteurSpriteDegat=1; 
                    meduse->Life--; 
                }
            }

            else 
            {
                meduse->CompteurSpriteDegat+=1;
                SDL_Texture *Spritemonstre=loadImage("src/graphics/Meduse/Medusedegat.png");
                drawImage(Spritemonstre,meduse->posmonsx,meduse->posmonsy);    
                if (meduse->CompteurSpriteDegat > 15)
                {
                    meduse->CompteurSpriteDegat=0;
                }
            }   
        }

        //Attaque meduse
        if  (meduse->compteur>=100)
        {
            if (meduse->NumSprit==0 || meduse->NumSprit==1 || meduse->NumSprit==2 || meduse->NumSprit==3 )
            {
                SDL_Texture *Spritemonstre=loadImage("src/graphics/Meduse/medusecoup1.png");
                drawImage(Spritemonstre,meduse->posmonsx,meduse->posmonsy);
            }
            if (meduse->NumSprit==4 || meduse->NumSprit==5 || meduse->NumSprit==6 || meduse->NumSprit==7 || meduse->NumSprit==29 || meduse->NumSprit==30 || meduse->NumSprit==31 || meduse->NumSprit==32 )
            {
                SDL_Texture *Spritemonstre=loadImage("src/graphics/Meduse/medusecoup2.png");
                drawImage(Spritemonstre,meduse->posmonsx,meduse->posmonsy);
            }
            if (meduse->NumSprit==8 || meduse->NumSprit==9 || meduse->NumSprit==10 || meduse->NumSprit==11|| meduse->NumSprit==24 || meduse->NumSprit==25 || meduse->NumSprit==26 || meduse->NumSprit==27 || meduse->NumSprit==28 )
            {
                SDL_Texture *Spritemonstre=loadImage("src/graphics/Meduse/medusecoup3.png");
                drawImage(Spritemonstre,meduse->posmonsx,meduse->posmonsy);
            }
            if (meduse->NumSprit==12 || meduse->NumSprit==13 || meduse->NumSprit==14 || meduse->NumSprit==19 || meduse->NumSprit==20 || meduse->NumSprit==21 || meduse->NumSprit==22 || meduse->NumSprit==23 )
            {
                SDL_Texture *Spritemonstre=loadImage("src/graphics/Meduse/medusecoup4.png");                    
                drawImage(Spritemonstre,meduse->posmonsx,meduse->posmonsy);
                SDL_Texture *Spriteattaque=loadImage("src/graphics/Meduse/AttaqueMeduse.png");
                drawImage(Spriteattaque,meduse->posmonsx -23 ,meduse->posmonsy - 23);
                if(inside(joueur, meduse)==1 && (meduse->NumSprit==23 || meduse->NumSprit==14))                    
                {
                    if (meduse->coup == 0)
                    {
                        joueur->life--;
                        meduse->coup =1 ;
                    }
                }
                if (meduse->NumSprit==15 || meduse->NumSprit==16 || meduse->NumSprit==17 || meduse->NumSprit==18 )
                {
                    SDL_Texture *Spritemonstre=loadImage("src/graphics/Meduse/medusecoup2.png");
                    drawImage(Spritemonstre,meduse->posmonsx,meduse->posmonsy);
                }
            }
            if (meduse->compteur>130)
            {
                meduse->compteur=0;
                meduse->coup = 0;
            }
        }
    }

    //Mort meduse
    if (meduse->Life==0)
    {
        if (meduse->CompteurSpriteDegat==0 || meduse->CompteurSpriteDegat==1 || meduse->CompteurSpriteDegat==2 || meduse->CompteurSpriteDegat==3 )
        {
            SDL_Texture *Spritemonstre=loadImage("src/graphics/Meduse/Medusemort1.png");
            drawImage(Spritemonstre,meduse->posmonsx,meduse->posmonsy);
        }
        if (meduse->CompteurSpriteDegat==4 || meduse->CompteurSpriteDegat==5 || meduse->CompteurSpriteDegat==6 || meduse->CompteurSpriteDegat==7 )
        {
            SDL_Texture *Spritemonstre=loadImage("src/graphics/Meduse/Medusemort2.png");
            drawImage(Spritemonstre,meduse->posmonsx,meduse->posmonsy);
        }
        if (meduse->CompteurSpriteDegat==8 || meduse->CompteurSpriteDegat==9 || meduse->CompteurSpriteDegat==10 || meduse->CompteurSpriteDegat==11)
        {
            SDL_Texture *Spritemonstre=loadImage("src/graphics/Meduse/Medusemort3.png");
            drawImage(Spritemonstre,meduse->posmonsx,meduse->posmonsy);
        }
        if (meduse->CompteurSpriteDegat==12 || meduse->CompteurSpriteDegat==13 || meduse->CompteurSpriteDegat==14 || meduse->CompteurSpriteDegat==15 )
        {
            SDL_Texture *Spritemonstre=loadImage("src/graphics/Meduse/Medusemort4.png");
            drawImage(Spritemonstre,meduse->posmonsx,meduse->posmonsy);
        }
        if (meduse->CompteurSpriteDegat==16 || meduse->CompteurSpriteDegat==17 || meduse->CompteurSpriteDegat==18 || meduse->CompteurSpriteDegat==19 )
        {
            SDL_Texture *Spritemonstre=loadImage("src/graphics/Meduse/Medusemort5.png");
            drawImage(Spritemonstre,meduse->posmonsx,meduse->posmonsy);
        }
        if (meduse->CompteurSpriteDegat==0)
        {
            lvl->MortMonstre+=1;
        }
        
    }

    //reset compteur pour sprite
    if (meduse->NumSprit>=33)
    {
        meduse->NumSprit=0;
    }
}