#include "../header/proto.h" 
void SpritHeros(Joueur *joueur, Meduse *meduse, Input *input, Chauvesouris *chauvesouris)
{
    //Mouvement joueur de base avec direction 0 pour droite et 1 gauche
    if(joueur->Eattack==0 && joueur->Eshield==0)
    {
        if (joueur->Direction ==0)
        {
            if( meduse->coup == 0 && chauvesouris->coup==0)
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
            if (meduse->coup == 0 && chauvesouris->coup==0)
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

    //Mouvement attaque 
    if (joueur->Eattack==1)
    {
        joueur->Numattack+=1;
        if (joueur->Direction==1)
        {   
            if (joueur->Numattack==0 || joueur->Numattack==1 || joueur->Numattack==2 || joueur->Numattack==3 )
            {
                SDL_Texture *Spritechevalier=loadImage("src/graphics/Epee2G.png");
                drawImage(Spritechevalier,joueur->inposx,joueur->inposy);
            }
            if (joueur->Numattack==4 || joueur->Numattack==5 || joueur->Numattack==6 || joueur->Numattack==7 || joueur->Numattack==20 || joueur->Numattack==21 || joueur->Numattack==22 || joueur->Numattack==23 )
            {
                SDL_Texture *Spritechevalier=loadImage("src/graphics/Epee3G.png");
                drawImage(Spritechevalier,joueur->inposx,joueur->inposy);
            }
            if (joueur->Numattack==8 || joueur->Numattack==9 || joueur->Numattack==10 || joueur->Numattack==11|| joueur->Numattack==16 || joueur->Numattack==17 || joueur->Numattack==18 || joueur->Numattack==19)
            {
                SDL_Texture *Spritechevalier=loadImage("src/graphics/Epee4G.png");
                drawImage(Spritechevalier,joueur->inposx,joueur->inposy);
            }
            if (joueur->Numattack==12 || joueur->Numattack==13 || joueur->Numattack==14 || joueur->Numattack==15 )
            {
                SDL_Texture *Spritechevalier=loadImage("src/graphics/Epee5G.png");
                drawImage(Spritechevalier,joueur->inposx,joueur->inposy);
                SDL_Texture *Spriteattaque=loadImage("src/graphics/attaqueG.png");
                drawImage(Spriteattaque,joueur->inposx-21,joueur->inposy+32);
            }
        }
        if (joueur->Direction==0)
        {
            if (joueur->Numattack==0 || joueur->Numattack==1 || joueur->Numattack==2 || joueur->Numattack==3 )
            {
                SDL_Texture *Spritechevalier=loadImage("src/graphics/Epee2D.png");
                drawImage(Spritechevalier,joueur->inposx,joueur->inposy);
            }
            if (joueur->Numattack==4 || joueur->Numattack==5 || joueur->Numattack==6 || joueur->Numattack==7 || joueur->Numattack==20 || joueur->Numattack==21 || joueur->Numattack==22 || joueur->Numattack==23 )
            {
                SDL_Texture *Spritechevalier=loadImage("src/graphics/Epee3D.png");
                drawImage(Spritechevalier,joueur->inposx,joueur->inposy);
            }
            if (joueur->Numattack==8 || joueur->Numattack==9 || joueur->Numattack==10 || joueur->Numattack==11|| joueur->Numattack==16 || joueur->Numattack==17 || joueur->Numattack==18 || joueur->Numattack==19)
            {
                SDL_Texture *Spritechevalier=loadImage("src/graphics/Epee4D.png");
                drawImage(Spritechevalier,joueur->inposx,joueur->inposy);
            }
            if (joueur->Numattack==12 || joueur->Numattack==13 || joueur->Numattack==14 || joueur->Numattack==15 )
            {
                SDL_Texture *Spritechevalier=loadImage("src/graphics/Epee5D.png");
                drawImage(Spritechevalier,joueur->inposx,joueur->inposy);
                SDL_Texture *Spriteattaque=loadImage("src/graphics/attaqueD.png");
                drawImage(Spriteattaque,joueur->inposx+SPRITE_SIZE ,joueur->inposy +32);
            }
        }}


        //mouvement defense
        if (joueur->Eshield==1)
        {
            if (joueur->Direction==0)
            {
                if (joueur->NumSprit==0 )
            {
                SDL_Texture *Spritechevalier=loadImage("src/graphics/ChevaliershieldD.png");
                drawImage(Spritechevalier,joueur->inposx,joueur->inposy);
            }
            }
             if (joueur->Direction==1)
            {
                if (joueur->NumSprit==0     )
            {
                SDL_Texture *Spritechevalier=loadImage("src/graphics/ChevaliershieldG.png");
                drawImage(Spritechevalier,joueur->inposx,joueur->inposy);
            }
            }}

        
    
        //reset des compteur pour sprite et attaque
        if(joueur->Numattack >= 23)
        {
            joueur->Numattack=0;
            joueur->Eattack = 0;
        }
    
}

void SpritMeduse (Meduse *meduse, Joueur *joueur, Chauvesouris *chauvesouris)
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
                    SDL_Texture *Spritemonstre=loadImage("src/graphics/Meduseneutre.png");
                    drawImage(Spritemonstre,meduse->posmonsx,meduse->posmonsy);
                }
                if (meduse->NumSprit==4 || meduse->NumSprit==5 || meduse->NumSprit==6 || meduse->NumSprit==7 || meduse->NumSprit==29 || meduse->NumSprit==30 || meduse->NumSprit==32 || meduse->NumSprit==31 )
                {
                    SDL_Texture *Spritemonstre=loadImage("src/graphics/Medusemarche1.png");
                    drawImage(Spritemonstre,meduse->posmonsx,meduse->posmonsy);
                }
                if (meduse->NumSprit==8 || meduse->NumSprit==9 || meduse->NumSprit==10 || meduse->NumSprit==11|| meduse->NumSprit==24 || meduse->NumSprit==25 || meduse->NumSprit==26 || meduse->NumSprit==27 || meduse->NumSprit==28 )
                {
                    SDL_Texture *Spritemonstre=loadImage("src/graphics/Medusemarche2.png");
                    drawImage(Spritemonstre,meduse->posmonsx,meduse->posmonsy);
                }
                if (meduse->NumSprit==12 || meduse->NumSprit==13 || meduse->NumSprit==14 || meduse->NumSprit==19 || meduse->NumSprit==20 || meduse->NumSprit==21 || meduse->NumSprit==22 || meduse->NumSprit==23 )                   
                {
                    SDL_Texture *Spritemonstre=loadImage("src/graphics/Medusemarche3.png");
                    drawImage(Spritemonstre,meduse->posmonsx,meduse->posmonsy);
                }
                if (meduse->NumSprit==15 || meduse->NumSprit==16 || meduse->NumSprit==17 || meduse->NumSprit==18 )
                {
                    SDL_Texture *Spritemonstre=loadImage("src/graphics/Medusemarche4.png");
                    drawImage(Spritemonstre,meduse->posmonsx,meduse->posmonsy);    
                }
                if (meduse->NumSprit>=33 )
                {
                    SDL_Texture *Spritemonstre=loadImage("src/graphics/Medusemarche1.png");
                    drawImage(Spritemonstre,meduse->posmonsx,meduse->posmonsy);
                    meduse->attack+=1;
                }
                if(insidechevalier(joueur, meduse, chauvesouris)==1 && joueur->Numattack==15)
                {           
                    meduse->CompteurSpriteDegat=1; 
                    meduse->Life--; 
                }
            }

            else 
            {
                meduse->CompteurSpriteDegat+=1;
                SDL_Texture *Spritemonstre=loadImage("src/graphics/Medusedegat.png");
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
                SDL_Texture *Spritemonstre=loadImage("src/graphics/medusecoup1.png");
                drawImage(Spritemonstre,meduse->posmonsx,meduse->posmonsy);
            }
            if (meduse->NumSprit==4 || meduse->NumSprit==5 || meduse->NumSprit==6 || meduse->NumSprit==7 || meduse->NumSprit==29 || meduse->NumSprit==30 || meduse->NumSprit==31 || meduse->NumSprit==32 )
            {
                SDL_Texture *Spritemonstre=loadImage("src/graphics/medusecoup2.png");
                drawImage(Spritemonstre,meduse->posmonsx,meduse->posmonsy);
            }
            if (meduse->NumSprit==8 || meduse->NumSprit==9 || meduse->NumSprit==10 || meduse->NumSprit==11|| meduse->NumSprit==24 || meduse->NumSprit==25 || meduse->NumSprit==26 || meduse->NumSprit==27 || meduse->NumSprit==28 )
            {
                SDL_Texture *Spritemonstre=loadImage("src/graphics/medusecoup3.png");
                drawImage(Spritemonstre,meduse->posmonsx,meduse->posmonsy);
            }
            if (meduse->NumSprit==12 || meduse->NumSprit==13 || meduse->NumSprit==14 || meduse->NumSprit==19 || meduse->NumSprit==20 || meduse->NumSprit==21 || meduse->NumSprit==22 || meduse->NumSprit==23 )
            {
                SDL_Texture *Spritemonstre=loadImage("src/graphics/medusecoup4.png");                    
                drawImage(Spritemonstre,meduse->posmonsx,meduse->posmonsy);
                SDL_Texture *Spriteattaque=loadImage("src/graphics/AttaqueMeduse.png");
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
                    SDL_Texture *Spritemonstre=loadImage("src/graphics/medusecoup2.png");
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
            SDL_Texture *Spritemonstre=loadImage("src/graphics/Medusemort1.png");
            drawImage(Spritemonstre,meduse->posmonsx,meduse->posmonsy);
        }
        if (meduse->CompteurSpriteDegat==4 || meduse->CompteurSpriteDegat==5 || meduse->CompteurSpriteDegat==6 || meduse->CompteurSpriteDegat==7 )
        {
            SDL_Texture *Spritemonstre=loadImage("src/graphics/Medusemort2.png");
            drawImage(Spritemonstre,meduse->posmonsx,meduse->posmonsy);
        }
        if (meduse->CompteurSpriteDegat==8 || meduse->CompteurSpriteDegat==9 || meduse->CompteurSpriteDegat==10 || meduse->CompteurSpriteDegat==11)
        {
            SDL_Texture *Spritemonstre=loadImage("src/graphics/Medusemort3.png");
            drawImage(Spritemonstre,meduse->posmonsx,meduse->posmonsy);
        }
        if (meduse->CompteurSpriteDegat==12 || meduse->CompteurSpriteDegat==13 || meduse->CompteurSpriteDegat==14 || meduse->CompteurSpriteDegat==15 )
        {
            SDL_Texture *Spritemonstre=loadImage("src/graphics/Medusemort4.png");
            drawImage(Spritemonstre,meduse->posmonsx,meduse->posmonsy);
        }
        if (meduse->CompteurSpriteDegat==16 || meduse->CompteurSpriteDegat==17 || meduse->CompteurSpriteDegat==18 || meduse->CompteurSpriteDegat==19 )
        {
            SDL_Texture *Spritemonstre=loadImage("src/graphics/Medusemort5.png");
            drawImage(Spritemonstre,meduse->posmonsx,meduse->posmonsy);
        }
    }

    //reset compteur pour sprite
    if (meduse->NumSprit>=33)
    {
        meduse->NumSprit=0;
    }
}





void SpritChauvesouris (Chauvesouris *chauvesouris, Joueur *joueur, Meduse *meduse)
{  
    //Mouvement  chauvesouris
    if (chauvesouris->Life <=0)
    {
     chauvesouris->coup =0 ;
    }
    if (chauvesouris->Life >=1)
    {
         if (chauvesouris->CompteurSpriteDegat==0)
            {
            if (chauvesouris->Direction==0){
                if (chauvesouris->NumSprit==0 || chauvesouris->NumSprit==1 || chauvesouris->NumSprit==2 || chauvesouris->NumSprit==3 ||chauvesouris->NumSprit==8 || chauvesouris->NumSprit==9 || chauvesouris->NumSprit==10 || chauvesouris->NumSprit==11 )
                {
                    SDL_Texture *Spritemonstre=loadImage("src/graphics/chauvesourisneutreD.png");
                    drawImage(Spritemonstre,chauvesouris->posmonsx,chauvesouris->posmonsy);
                }
                if (chauvesouris->NumSprit==4 || chauvesouris->NumSprit==5 || chauvesouris->NumSprit==6 || chauvesouris->NumSprit==7  )
                {
                    SDL_Texture *Spritemonstre=loadImage("src/graphics/chauvesourismarche1D.png");
                    drawImage(Spritemonstre,chauvesouris->posmonsx,chauvesouris->posmonsy);
                }
                if (chauvesouris->NumSprit==12 || chauvesouris->NumSprit==13 || chauvesouris->NumSprit==14 || chauvesouris->NumSprit==15 )
                {
                    SDL_Texture *Spritemonstre=loadImage("src/graphics/chauvesourismarche2D.png");
                    drawImage(Spritemonstre,chauvesouris->posmonsx,chauvesouris->posmonsy);
                }
                 
                


            if (chauvesouris->Direction==1){
                if (chauvesouris->NumSprit==0 || chauvesouris->NumSprit==1 || chauvesouris->NumSprit==2 || chauvesouris->NumSprit==3 ||chauvesouris->NumSprit==8 || chauvesouris->NumSprit==9 || chauvesouris->NumSprit==10 || chauvesouris->NumSprit==11 )
                {
                    SDL_Texture *Spritemonstre=loadImage("src/graphics/chauvesourisneutreG.png");
                    drawImage(Spritemonstre,chauvesouris->posmonsx,chauvesouris->posmonsy);
                }
                if (chauvesouris->NumSprit==4 || chauvesouris->NumSprit==5 || chauvesouris->NumSprit==6 || chauvesouris->NumSprit==7  )
                {
                    SDL_Texture *Spritemonstre=loadImage("src/graphics/chauvesourismarche1G.png");
                    drawImage(Spritemonstre,chauvesouris->posmonsx,chauvesouris->posmonsy);
                }
                if (chauvesouris->NumSprit==12 || chauvesouris->NumSprit==13 || chauvesouris->NumSprit==14 || chauvesouris->NumSprit==15 )
                {
                    SDL_Texture *Spritemonstre=loadImage("src/graphics/chauvesourismarche2G.png");
                    drawImage(Spritemonstre,chauvesouris->posmonsx,chauvesouris->posmonsy);
                }
                    
                
            } }
        
 
    //     Attaque chauvesouris
        
                  if (insidechauvesouris(joueur,chauvesouris)==1 && joueur->Eshield==0)
                     {
                          joueur->life--;
                          chauvesouris->Life--;
                          chauvesouris->coup =1 ;
                        }
                   if (insidechauvesouris(joueur,chauvesouris)==1 && joueur->Eshield==1)
                     {
                          chauvesouris->Life--;
                          chauvesouris->coup =1 ;
                        }}     
                        
                        }
          
 
    //Mort chauvesouris
    if (chauvesouris->Life==0)
    {
        if (chauvesouris->CompteurSpriteDegat==0 || chauvesouris->CompteurSpriteDegat==1 || chauvesouris->CompteurSpriteDegat==2 || chauvesouris->CompteurSpriteDegat==3 )
        {
            SDL_Texture *Spritemonstre=loadImage("src/graphics/chauvesourismort1D.png");
            drawImage(Spritemonstre,chauvesouris->posmonsx,chauvesouris->posmonsy);
        }
        if (chauvesouris->CompteurSpriteDegat==4 || chauvesouris->CompteurSpriteDegat==5 || chauvesouris->CompteurSpriteDegat==6 || chauvesouris->CompteurSpriteDegat==7 )
        {
            SDL_Texture *Spritemonstre=loadImage("src/graphics/chauvesourismort2D.png");
            drawImage(Spritemonstre,chauvesouris->posmonsx,chauvesouris->posmonsy);
        }
        if (chauvesouris->CompteurSpriteDegat==8 || chauvesouris->CompteurSpriteDegat==9 || chauvesouris->CompteurSpriteDegat==10 || chauvesouris->CompteurSpriteDegat==11)
        {
            SDL_Texture *Spritemonstre=loadImage("src/graphics/chauvesourismort3D.png");
            drawImage(Spritemonstre,chauvesouris->posmonsx,chauvesouris->posmonsy);
        }
        if (chauvesouris->CompteurSpriteDegat==12 || chauvesouris->CompteurSpriteDegat==13 || chauvesouris->CompteurSpriteDegat==14 || chauvesouris->CompteurSpriteDegat==15 )
        {
            SDL_Texture *Spritemonstre=loadImage("src/graphics/chauvesourismort4D.png");
            drawImage(Spritemonstre,chauvesouris->posmonsx,chauvesouris->posmonsy);
        }
        if (chauvesouris->CompteurSpriteDegat==16 || chauvesouris->CompteurSpriteDegat==17 || chauvesouris->CompteurSpriteDegat==18 || chauvesouris->CompteurSpriteDegat==19 )
        {
            SDL_Texture *Spritemonstre=loadImage("src/graphics/chauvesourismort5D.png");
            drawImage(Spritemonstre,chauvesouris->posmonsx,chauvesouris->posmonsy);
         }
     }
 
    //reset compteur pour sprite
    if (chauvesouris->NumSprit>=15)
    {
        chauvesouris->NumSprit=0;
    }
    }
    