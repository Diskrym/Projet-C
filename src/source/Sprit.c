#include "../header/proto.h" 


void SpritHeros(Joueur *joueur, Input *input, EffetSon *son, Monstre *monstre)
{   
    //reset des pointeurs des sprites
    if (joueur->chevalier!=NULL)
    {  
        SDL_DestroyTexture(joueur->chevalier);
        joueur->chevalier=NULL;
    }
    if (joueur->attaque!=NULL)
    {
        SDL_DestroyTexture(joueur->attaque);
        joueur->attaque=NULL;
    }

    //Mouvement du joueur droite si bouclier baisser ou si timing bouclier dépassé
    if (joueur->Direction ==0 && joueur->Eattack==0 && (joueur->Eshield==0 || (joueur->Eshield==1 && joueur->TimingBouclier>15)))
    {
        //se deplace si ne prend pas de dégat sinon sprit degat
        if (DegatChevalier(&monstre->meduse, &monstre->meduse1 , &monstre->meduse2, &monstre->chauvesouris , &monstre->chauvesouris1, &monstre->boss)==1)
        {
            if (joueur->NumSprit==0 || joueur->NumSprit ==1 || joueur->NumSprit==4 || joueur->NumSprit ==5)
            {
                joueur->chevalier=loadImage("src/graphics/Chevalier/neutreD.png");
                drawImage(joueur->chevalier,joueur->inposx,joueur->inposy);
            }
            if (joueur->NumSprit==2 || joueur->NumSprit==3  )
            {
                joueur->chevalier=loadImage("src/graphics/Chevalier/marche1D.png");
                drawImage(joueur->chevalier,joueur->inposx,joueur->inposy);
                // if (joueur->NumSprit==2)
                // {Mix_VolumeChunk(son->depchevalier, MIX_MAX_VOLUME/2);
                // Mix_PlayChannel(3, son->depchevalier, 0);}   
            }
            if (joueur->NumSprit >=7 || joueur->NumSprit ==6 )
            {
                joueur->chevalier=loadImage("src/graphics/Chevalier/marche2D.png");
                drawImage(joueur->chevalier,joueur->inposx,joueur->inposy);
                joueur->NumSprit =0;
                // if (joueur->NumSprit==7)
                // {
                // Mix_VolumeChunk(son->depchevalier, MIX_MAX_VOLUME/2);
                // Mix_PlayChannel(3, son->depchevalier, 0);
                // }
            }
        }
    }
    //affiche sprite degat si degat de la part du monstre et si degat de la part du monstre lors de notre attack/defense pour la droite
    if((joueur->Direction ==0 && (joueur->Eattack==1 || joueur->Eshield==1) && DegatChevalier(&monstre->meduse, &monstre->meduse1 , &monstre->meduse2, &monstre->chauvesouris , &monstre->chauvesouris1, &monstre->boss)==0) || (DegatChevalier(&monstre->meduse, &monstre->meduse1 , &monstre->meduse2, &monstre->chauvesouris , &monstre->chauvesouris1, &monstre->boss)==0) && joueur->Direction==0)
    {
        joueur->chevalier=loadImage("src/graphics/Chevalier/DégatD.png");
        drawImage(joueur->chevalier,joueur->inposx,joueur->inposy);
        Mix_VolumeChunk(son->degatchevalier, MIX_MAX_VOLUME/2);
        Mix_PlayChannel(1, son->degatchevalier, 0);
    }
    
    //cf fonction gauche
    if (joueur->Direction ==1 && joueur->Eattack==0 && (joueur->Eshield==0 || (joueur->Eshield==1 && joueur->TimingBouclier>15)))
    {
        if(DegatChevalier(&monstre->meduse, &monstre->meduse1 , &monstre->meduse2, &monstre->chauvesouris , &monstre->chauvesouris1, &monstre->boss)==1)
        {
            if (joueur->NumSprit==0 || joueur->NumSprit ==1 || joueur->NumSprit==4 || joueur->NumSprit ==5)
            {
                joueur->chevalier=loadImage("src/graphics/Chevalier/neutreG.png");
                drawImage(joueur->chevalier,joueur->inposx,joueur->inposy);
            }
            if (joueur->NumSprit==2 || joueur->NumSprit==3  )
            {
                joueur->chevalier=loadImage("src/graphics/Chevalier/marche1G.png");
                drawImage(joueur->chevalier,joueur->inposx,joueur->inposy);
                // if (joueur->NumSprit==2)
                // {
                // Mix_VolumeChunk(son->depchevalier, MIX_MAX_VOLUME/2);
                // Mix_PlayChannel(3, son->depchevalier, 0);
                // }
            }
            if (joueur->NumSprit >=7 || joueur->NumSprit ==6 )
            {
                joueur->chevalier=loadImage("src/graphics/Chevalier/marche2G.png");
                drawImage(joueur->chevalier,joueur->inposx,joueur->inposy);
                // if (joueur->NumSprit==7)
                // {
                // Mix_VolumeChunk(son->depchevalier, MIX_MAX_VOLUME/2);
                // Mix_PlayChannel(3, son->depchevalier, 0);
                // }
                joueur->NumSprit =0;
            }   
        }
    }
    if ((joueur->Direction ==1 && (joueur->Eattack==1 || joueur->Eshield==1) && DegatChevalier(&monstre->meduse, &monstre->meduse1 , &monstre->meduse2, &monstre->chauvesouris , &monstre->chauvesouris1, &monstre->boss)==0) || (DegatChevalier(&monstre->meduse, &monstre->meduse1 , &monstre->meduse2, &monstre->chauvesouris , &monstre->chauvesouris1, &monstre->boss)==0) && joueur->Direction==1 )
    {
        joueur->chevalier=loadImage("src/graphics/Chevalier/DégatG.png");
        drawImage(joueur->chevalier,joueur->inposx,joueur->inposy);
        Mix_VolumeChunk(son->degatchevalier, MIX_MAX_VOLUME/2);
        Mix_PlayChannel(1, son->degatchevalier, 0);
    }
        
    

    //Mouvement attaque si Eattack = 1 et si on ne prend pas de dégat
    if (joueur->Eattack==1 && DegatChevalier(&monstre->meduse, &monstre->meduse1, &monstre->meduse2, &monstre->chauvesouris, &monstre->chauvesouris1,&monstre->boss)==1)
    {
        joueur->Numattack+=1;
        if (joueur->Direction==1)
        {   
            if (joueur->Numattack==0 || joueur->Numattack==1 || joueur->Numattack==2 || joueur->Numattack==3 )
            {
                joueur->chevalier=loadImage("src/graphics/Chevalier/Epee2G.png");
                drawImage(joueur->chevalier,joueur->inposx,joueur->inposy);
            }
            if (joueur->Numattack==4 || joueur->Numattack==5 || joueur->Numattack==6 || joueur->Numattack==7 || joueur->Numattack==20 || joueur->Numattack==21 || joueur->Numattack==22 || joueur->Numattack==23 )
            {
                joueur->chevalier=loadImage("src/graphics/Chevalier/Epee3G.png");
                drawImage(joueur->chevalier,joueur->inposx,joueur->inposy);
            }
            if (joueur->Numattack==8 || joueur->Numattack==9 || joueur->Numattack==10 || joueur->Numattack==11|| joueur->Numattack==16 || joueur->Numattack==17 || joueur->Numattack==18 || joueur->Numattack==19)
            {
                joueur->chevalier=loadImage("src/graphics/Chevalier/Epee4G.png");
                drawImage(joueur->chevalier,joueur->inposx,joueur->inposy);
            }
            if (joueur->Numattack==12 || joueur->Numattack==13 || joueur->Numattack==14 || joueur->Numattack==15 )
            {
                joueur->chevalier=loadImage("src/graphics/Chevalier/Epee5G.png");
                drawImage(joueur->chevalier,joueur->inposx,joueur->inposy);
                joueur->attaque=loadImage("src/graphics/Chevalier/attaqueG.png");
                drawImage(joueur->attaque,joueur->inposx-21,joueur->inposy+32);
                if(joueur->Numattack==13)
                {
                    //Son
                    Mix_VolumeChunk(son->epee, MIX_MAX_VOLUME/2);
                    //Mix_PlayChannel(1, son->epee, 0);//Joue le son 1 sur le canal 1 ; le joue une fois (0 + 1)
                }
            }
        }
        if (joueur->Direction==0)
        {
            if (joueur->Numattack==0 || joueur->Numattack==1 || joueur->Numattack==2 || joueur->Numattack==3 )
            {
                joueur->chevalier=loadImage("src/graphics/Chevalier/Epee2D.png");
                drawImage(joueur->chevalier,joueur->inposx,joueur->inposy);
            }
            if (joueur->Numattack==4 || joueur->Numattack==5 || joueur->Numattack==6 || joueur->Numattack==7 || joueur->Numattack==20 || joueur->Numattack==21 || joueur->Numattack==22 || joueur->Numattack==23 )
            {
                joueur->chevalier=loadImage("src/graphics/Chevalier/Epee3D.png");
                drawImage(joueur->chevalier,joueur->inposx,joueur->inposy);
            }
            if (joueur->Numattack==8 || joueur->Numattack==9 || joueur->Numattack==10 || joueur->Numattack==11|| joueur->Numattack==16 || joueur->Numattack==17 || joueur->Numattack==18 || joueur->Numattack==19)
            {
                joueur->chevalier=loadImage("src/graphics/Chevalier/Epee4D.png");
                drawImage(joueur->chevalier,joueur->inposx,joueur->inposy);
            }
            if (joueur->Numattack==12 || joueur->Numattack==13 || joueur->Numattack==14 || joueur->Numattack==15 )
            {
                joueur->chevalier=loadImage("src/graphics/Chevalier/Epee5D.png");
                drawImage(joueur->chevalier,joueur->inposx,joueur->inposy);
                joueur->attaque=loadImage("src/graphics/Chevalier/attaqueD.png");
                drawImage(joueur->attaque,joueur->inposx+SPRITE_SIZE ,joueur->inposy +32);
                if(joueur->Numattack==13)
                {
                    //Son
                    Mix_VolumeChunk(son->epee, MIX_MAX_VOLUME/2);
                    //Mix_PlayChannel(1, son->epee, 0);//Joue le son 1 sur le canal 1 ; le joue une fois (0 + 1)
                }
            }
        }
    }


    //mouvement defense si etat shield a 1
    if (joueur->Eshield==1)
    {
        //timer shield
        if (joueur->TimingBouclier<=15)
        {
            if (joueur->Direction==0)
            {
                if (joueur->NumSprit==0 )
                {
                    joueur->chevalier=loadImage("src/graphics/Chevalier/ChevaliershieldD.png");
                    drawImage(joueur->chevalier,joueur->inposx,joueur->inposy);
                    //Mix_VolumeChunk(son->bouclier, MIX_MAX_VOLUME/2);
                    //Mix_PlayChannel(2, son->bouclier, 0);
                }
            }
            if (joueur->Direction==1)
            {
                if (joueur->NumSprit==0)
                {
                    joueur->chevalier=loadImage("src/graphics/Chevalier/ChevaliershieldG.png");
                    drawImage(joueur->chevalier,joueur->inposx,joueur->inposy);
                    //Mix_VolumeChunk(son->bouclier, MIX_MAX_VOLUME/2);
                    //Mix_PlayChannel(2, son->bouclier, 0);
                }
            }
            //incrémentation de timer shield jusqu'a 15
            joueur->TimingBouclier+=1;
        }
    }

        
    
    //reset des compteur pour sprite et attaque (attaque pour les sprit)
    if(joueur->Numattack >= 23)
    {
        joueur->Numattack=0;
        joueur->Eattack = 0;
    }
    
}

void SpritMeduse (Meduse *meduse, Joueur *joueur,Lvl *lvl, EffetSon *son)
{   
    //reset pointeur meduse
    if (meduse->meduse!=NULL)
    {
        SDL_DestroyTexture(meduse->meduse);
        meduse->meduse=NULL;
    }
    if (meduse->attaque!=NULL)
    {
        SDL_DestroyTexture(meduse->attaque);
        meduse->attaque=NULL;
    }

    //Mouvement  meduse quand en vie
    if (meduse->Life >=1)
    {
        //compteur < 100 pour déplacement normal
        if (meduse->compteur < 100)
        {
            //si la meduse n'a pas prit de coup
            if (meduse->CompteurSpriteDegat==0)
            {
                if (meduse->NumSprit==0 || meduse->NumSprit==1 || meduse->NumSprit==2 || meduse->NumSprit==3 )
                {
                    meduse->meduse=loadImage("src/graphics/Meduse/Meduseneutre.png");
                    drawImage(meduse->meduse,meduse->posmonsx,meduse->posmonsy);
                }
                if (meduse->NumSprit==4 || meduse->NumSprit==5 || meduse->NumSprit==6 || meduse->NumSprit==7 || meduse->NumSprit==29 || meduse->NumSprit==30 || meduse->NumSprit==32 || meduse->NumSprit==31 )
                {
                    meduse->meduse=loadImage("src/graphics/Meduse/Medusemarche1.png");
                    drawImage(meduse->meduse,meduse->posmonsx,meduse->posmonsy);
                }
                if (meduse->NumSprit==8 || meduse->NumSprit==9 || meduse->NumSprit==10 || meduse->NumSprit==11|| meduse->NumSprit==24 || meduse->NumSprit==25 || meduse->NumSprit==26 || meduse->NumSprit==27 || meduse->NumSprit==28 )
                {
                    meduse->meduse=loadImage("src/graphics/Meduse/Medusemarche2.png");
                    drawImage(meduse->meduse,meduse->posmonsx,meduse->posmonsy);
                }
                if (meduse->NumSprit==12 || meduse->NumSprit==13 || meduse->NumSprit==14 || meduse->NumSprit==19 || meduse->NumSprit==20 || meduse->NumSprit==21 || meduse->NumSprit==22 || meduse->NumSprit==23 )                   
                {
                    meduse->meduse=loadImage("src/graphics/Meduse/Medusemarche3.png");
                    drawImage(meduse->meduse,meduse->posmonsx,meduse->posmonsy);
                }
                if (meduse->NumSprit==15 || meduse->NumSprit==16 || meduse->NumSprit==17 || meduse->NumSprit==18 )
                {
                    meduse->meduse=loadImage("src/graphics/Meduse/Medusemarche4.png");
                    drawImage(meduse->meduse,meduse->posmonsx,meduse->posmonsy);    
                }
                if (meduse->NumSprit>=33 )
                {
                    meduse->meduse=loadImage("src/graphics/Meduse/Medusemarche1.png");
                    drawImage(meduse->meduse,meduse->posmonsx,meduse->posmonsy);
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
                //si la meduse prend un coup
                meduse->CompteurSpriteDegat+=1;
                meduse->meduse=loadImage("src/graphics/Meduse/Medusedegat.png");
                drawImage(meduse->meduse,meduse->posmonsx,meduse->posmonsy);
                if (meduse->CompteurSpriteDegat==2)
                {
                Mix_VolumeChunk(son->degatmeduse, MIX_MAX_VOLUME/2);
                Mix_PlayChannel(4, son->degatmeduse, 0); 
                }          
                //compteur duree affichage degat meduse
                if (meduse->CompteurSpriteDegat > 15)
                {
                    meduse->CompteurSpriteDegat=0;
                }
            }   
        }

        //Attaque meduse quand compteur > 100
        if  (meduse->compteur>=100)
        {
            if (meduse->NumSprit==0 || meduse->NumSprit==1 || meduse->NumSprit==2 || meduse->NumSprit==3 )
            {  
                
                meduse->meduse=loadImage("src/graphics/Meduse/medusecoup1.png");
                drawImage(meduse->meduse,meduse->posmonsx,meduse->posmonsy);
            }
            if (meduse->NumSprit==4 || meduse->NumSprit==5 || meduse->NumSprit==6 || meduse->NumSprit==7 || meduse->NumSprit==29 || meduse->NumSprit==30 || meduse->NumSprit==31 || meduse->NumSprit==32 )
            {
                meduse->meduse=loadImage("src/graphics/Meduse/medusecoup2.png");
                drawImage(meduse->meduse,meduse->posmonsx,meduse->posmonsy);
            }
            if (meduse->NumSprit==8 || meduse->NumSprit==9 || meduse->NumSprit==10 || meduse->NumSprit==11|| meduse->NumSprit==24 || meduse->NumSprit==25 || meduse->NumSprit==26 || meduse->NumSprit==27 || meduse->NumSprit==28 )
            {
                meduse->meduse=loadImage("src/graphics/Meduse/medusecoup3.png");
                drawImage(meduse->meduse,meduse->posmonsx,meduse->posmonsy);
            }
            if (meduse->NumSprit==12 || meduse->NumSprit==13 || meduse->NumSprit==14 || meduse->NumSprit==19 || meduse->NumSprit==20 || meduse->NumSprit==21 || meduse->NumSprit==22 || meduse->NumSprit==23 )
            {   
                //attaque meduse
                if (meduse->NumSprit==14 || meduse->NumSprit==14 )
                {
                    Mix_VolumeChunk(son->attaquemeduse, MIX_MAX_VOLUME/2);
                    Mix_PlayChannel(4, son->attaquemeduse, 0);
                }

                meduse->meduse=loadImage("src/graphics/Meduse/medusecoup4.png");                    
                drawImage(meduse->meduse,meduse->posmonsx,meduse->posmonsy);
                meduse->attaque=loadImage("src/graphics/Meduse/AttaqueMeduse.png");
                drawImage(meduse->attaque,meduse->posmonsx -23 ,meduse->posmonsy - 23);
                
                // Si joueur dans la range de la meduse durant les éclaires
                if(inside(joueur, meduse)==1 && (meduse->NumSprit==23 || meduse->NumSprit==14))                    
                {
                    if (meduse->coup == 0)
                    {
                        //joueur->life--;
                        meduse->coup =1 ;
                    }
                }
                if (meduse->NumSprit==15 || meduse->NumSprit==16 || meduse->NumSprit==17 || meduse->NumSprit==18 )
                {
                    meduse->meduse=loadImage("src/graphics/Meduse/medusecoup2.png");
                    drawImage(meduse->meduse,meduse->posmonsx,meduse->posmonsy);
                }
            }
            //reset compteur meduse
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
            meduse->meduse=loadImage("src/graphics/Meduse/Medusemort1.png");
            drawImage(meduse->meduse,meduse->posmonsx,meduse->posmonsy);
            if (meduse->CompteurSpriteDegat==1)
            {
            Mix_VolumeChunk(son->mortmeduse, MIX_MAX_VOLUME/2);
            Mix_PlayChannel(9, son->mortmeduse, 0);
            }
        }
        if (meduse->CompteurSpriteDegat==4 || meduse->CompteurSpriteDegat==5 || meduse->CompteurSpriteDegat==6 || meduse->CompteurSpriteDegat==7 )
        {
            meduse->meduse=loadImage("src/graphics/Meduse/Medusemort2.png");
            drawImage(meduse->meduse,meduse->posmonsx,meduse->posmonsy);
        }
        if (meduse->CompteurSpriteDegat==8 || meduse->CompteurSpriteDegat==9 || meduse->CompteurSpriteDegat==10 || meduse->CompteurSpriteDegat==11)
        {
            meduse->meduse=loadImage("src/graphics/Meduse/Medusemort3.png");
            drawImage(meduse->meduse,meduse->posmonsx,meduse->posmonsy);
        }
        if (meduse->CompteurSpriteDegat==12 || meduse->CompteurSpriteDegat==13 || meduse->CompteurSpriteDegat==14 || meduse->CompteurSpriteDegat==15 )
        {
            meduse->meduse=loadImage("src/graphics/Meduse/Medusemort4.png");
            drawImage(meduse->meduse,meduse->posmonsx,meduse->posmonsy);
        }
        if (meduse->CompteurSpriteDegat==16 || meduse->CompteurSpriteDegat==17 || meduse->CompteurSpriteDegat==18 || meduse->CompteurSpriteDegat==19 )
        {
            meduse->meduse=loadImage("src/graphics/Meduse/Medusemort5.png");
            drawImage(meduse->meduse,meduse->posmonsx,meduse->posmonsy);
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





void SpritChauvesouris (Chauvesouris *chauvesouris, Joueur *joueur, Lvl *lvl, EffetSon *son)
{  
    //reset pointeur sprite
    if (chauvesouris->chauvesouris!=NULL)
    {
        SDL_DestroyTexture(chauvesouris->chauvesouris);
        chauvesouris->chauvesouris=NULL;
    }
    //Qd en vie et quelle ne prend pas dégât
    if (chauvesouris->Life >=1)
    {
         if (chauvesouris->CompteurSpriteDegat==0)
            {
            if (chauvesouris->Direction==0){
                if (chauvesouris->NumSprit==0 || chauvesouris->NumSprit==1 || chauvesouris->NumSprit==2 || chauvesouris->NumSprit==3 ||chauvesouris->NumSprit==8 || chauvesouris->NumSprit==9 || chauvesouris->NumSprit==10 || chauvesouris->NumSprit==11 )
                {
                    chauvesouris->chauvesouris=loadImage("src/graphics/Chauvesouris/chauvesourisneutreD.png");
                    drawImage(chauvesouris->chauvesouris,chauvesouris->posmonsx,chauvesouris->posmonsy);
                }
                if (chauvesouris->NumSprit==4 || chauvesouris->NumSprit==5 || chauvesouris->NumSprit==6 || chauvesouris->NumSprit==7  )
                {
                    chauvesouris->chauvesouris=loadImage("src/graphics/Chauvesouris/chauvesourismarche1D.png");
                    drawImage(chauvesouris->chauvesouris,chauvesouris->posmonsx,chauvesouris->posmonsy);
                }
                if (chauvesouris->NumSprit==12 || chauvesouris->NumSprit==13 || chauvesouris->NumSprit==14 || chauvesouris->NumSprit==15 )
                {
                    chauvesouris->chauvesouris=loadImage("src/graphics/Chauvesouris/chauvesourismarche2D.png");
                    drawImage(chauvesouris->chauvesouris,chauvesouris->posmonsx,chauvesouris->posmonsy);
                }
                 
            }


            if (chauvesouris->Direction==1){
                if (chauvesouris->NumSprit==0 || chauvesouris->NumSprit==1 || chauvesouris->NumSprit==2 || chauvesouris->NumSprit==3 ||chauvesouris->NumSprit==8 || chauvesouris->NumSprit==9 || chauvesouris->NumSprit==10 || chauvesouris->NumSprit==11 )
                {
                    chauvesouris->chauvesouris=loadImage("src/graphics/Chauvesouris/chauvesourisneutreG.png");
                    drawImage(chauvesouris->chauvesouris,chauvesouris->posmonsx,chauvesouris->posmonsy);
                }
                if (chauvesouris->NumSprit==4 || chauvesouris->NumSprit==5 || chauvesouris->NumSprit==6 || chauvesouris->NumSprit==7  )
                {
                    chauvesouris->chauvesouris=loadImage("src/graphics/Chauvesouris/chauvesourismarche1G.png");
                    drawImage(chauvesouris->chauvesouris,chauvesouris->posmonsx,chauvesouris->posmonsy);
                }
                if (chauvesouris->NumSprit==12 || chauvesouris->NumSprit==13 || chauvesouris->NumSprit==14 || chauvesouris->NumSprit==15 )
                {
                    chauvesouris->chauvesouris=loadImage("src/graphics/Chauvesouris/chauvesourismarche2G.png");
                    drawImage(chauvesouris->chauvesouris,chauvesouris->posmonsx,chauvesouris->posmonsy);
                }
            } 
 
            //Attaque chauvesouris sans compt
            //si non bouclier
            if (insidechauvesouris(joueur,chauvesouris)==1 && joueur->Eshield==0)
            {
                //joueur->life--;
                chauvesouris->Life--;
                chauvesouris->coup =1 ;
                lvl->MortMonstre+=1;
            }
            //si bouclier
            if (insidechauvesouris(joueur,chauvesouris)==1 && joueur->Eshield==1)
            {
                chauvesouris->Life--;
                lvl ->MortMonstre+=1;
                //si bouclier boucle active
                if (joueur->TimingBouclier>15)
                {
                    //joueur->life--;
                }
            }
        }
    }
    //Mort chauvesouris
    if (chauvesouris->Life==0)
    {
        if (chauvesouris->CompteurSpriteDegat==0 || chauvesouris->CompteurSpriteDegat==1 || chauvesouris->CompteurSpriteDegat==2 || chauvesouris->CompteurSpriteDegat==3 )
        {
            chauvesouris->chauvesouris=loadImage("src/graphics/Chauvesouris/chauvesourismort1D.png");
            drawImage(chauvesouris->chauvesouris,chauvesouris->posmonsx,chauvesouris->posmonsy);
            if (chauvesouris->CompteurSpriteDegat==0)
            {
            Mix_VolumeChunk(son->mortchauvesouris, MIX_MAX_VOLUME/2);
            Mix_PlayChannel(6, son->mortchauvesouris, 0);
            }
        }
        if (chauvesouris->CompteurSpriteDegat==4 || chauvesouris->CompteurSpriteDegat==5 || chauvesouris->CompteurSpriteDegat==6 || chauvesouris->CompteurSpriteDegat==7 )
        {
            chauvesouris->chauvesouris=loadImage("src/graphics/Chauvesouris/chauvesourismort2D.png");
            drawImage(chauvesouris->chauvesouris,chauvesouris->posmonsx,chauvesouris->posmonsy);
        }
        if (chauvesouris->CompteurSpriteDegat==8 || chauvesouris->CompteurSpriteDegat==9 || chauvesouris->CompteurSpriteDegat==10 || chauvesouris->CompteurSpriteDegat==11)
        {
            chauvesouris->chauvesouris=loadImage("src/graphics/Chauvesouris/chauvesourismort3D.png");
            drawImage(chauvesouris->chauvesouris,chauvesouris->posmonsx,chauvesouris->posmonsy);
        }
        if (chauvesouris->CompteurSpriteDegat==12 || chauvesouris->CompteurSpriteDegat==13 || chauvesouris->CompteurSpriteDegat==14 || chauvesouris->CompteurSpriteDegat==15 )
        {
            chauvesouris->chauvesouris=loadImage("src/graphics/Chauvesouris/chauvesourismort4D.png");
            drawImage(chauvesouris->chauvesouris,chauvesouris->posmonsx,chauvesouris->posmonsy);
        }
        if (chauvesouris->CompteurSpriteDegat==16 || chauvesouris->CompteurSpriteDegat==17 || chauvesouris->CompteurSpriteDegat==18 || chauvesouris->CompteurSpriteDegat==19 )
        {
            chauvesouris->chauvesouris=loadImage("src/graphics/Chauvesouris/chauvesourismort5D.png");
            drawImage(chauvesouris->chauvesouris,chauvesouris->posmonsx,chauvesouris->posmonsy);
        }
    }
    //reset compteur pour sprite
    if (chauvesouris->NumSprit>=15)
    {
        chauvesouris->NumSprit=0;
    }
    //activation boucle dans event des degats chevalier
    if (chauvesouris->coup==1)
    {
        chauvesouris->CompteurSpriteDegatChevalier+=1;
    }
    //reset degat chevalier
    if  (chauvesouris->CompteurSpriteDegatChevalier==15)
    {
        chauvesouris->coup=0;
    }   
}

void SpritBoss (Boss *boss, Joueur *joueur, Lvl *lvl, EffetSon *son)
{
    //suppression pointeur des images
   if (boss->Boss!=NULL)
    {
        SDL_DestroyTexture(boss->Boss);
        boss->Boss=NULL;
    }
    if (boss->Bossattaque!=NULL)
    {
        SDL_DestroyTexture(boss->Bossattaque);
        boss->Bossattaque=NULL;
    }
    if (boss->Eclair4!=NULL)
    {
        SDL_DestroyTexture(boss->Eclair1);
        SDL_DestroyTexture(boss->Eclair2);
        SDL_DestroyTexture(boss->Eclair3);
        SDL_DestroyTexture(boss->Eclair4);
        boss->Eclair1=NULL;
        boss->Eclair2=NULL;
        boss->Eclair3=NULL;
        boss->Eclair4=NULL;
    }
    if (boss->Coeur!=NULL)
    {
        SDL_DestroyTexture(boss->Coeur);
        boss->Coeur=NULL;
    }
    

    //Mouvement  meduse qd en vie
    if (boss->Life >=1)
    {
        //compteur sans attaque boss
        if (boss->compteur <= 450)
        {   
            //si il ne prend pas de degat
            if (boss->CompteurSpriteDegat==0)
            {
                if (boss->NumSprit==0 || boss->NumSprit==1 || boss->NumSprit==2 || boss->NumSprit==3 )
                {
                    boss->Boss=loadImage("src/graphics/Boss/BossNeutre.png");
                    drawImage(boss->Boss,boss->posmonsx,boss->posmonsy);
                }
                if (boss->NumSprit==4 || boss->NumSprit==5 || boss->NumSprit==6 || boss->NumSprit==7 || boss->NumSprit==29 || boss->NumSprit==30 || boss->NumSprit==31  || boss->NumSprit==32)
                {
                    boss->Boss=loadImage("src/graphics/Boss/BossMarche1.png");
                    drawImage(boss->Boss,boss->posmonsx,boss->posmonsy);
                }
                if (boss->NumSprit==8 || boss->NumSprit==9 || boss->NumSprit==10 || boss->NumSprit==11|| boss->NumSprit==24 || boss->NumSprit==25 || boss->NumSprit==26 || boss->NumSprit==27 || boss->NumSprit==28 )
                {
                    boss->Boss=loadImage("src/graphics/Boss/BossMarche2.png");
                    drawImage(boss->Boss,boss->posmonsx,boss->posmonsy);
                }
                if (boss->NumSprit==12 || boss->NumSprit==13 || boss->NumSprit==14 || boss->NumSprit==19 || boss->NumSprit==20 || boss->NumSprit==21 || boss->NumSprit==22 || boss->NumSprit==23 )                   
                {
                    boss->Boss=loadImage("src/graphics/Boss/BossMarche3.png");
                    drawImage(boss->Boss,boss->posmonsx,boss->posmonsy);
                }
                if (boss->NumSprit==15 || boss->NumSprit==16 || boss->NumSprit==17 || boss->NumSprit==18 )
                {
                    boss->Boss=loadImage("src/graphics/Boss/BossMarche4.png");
                    drawImage(boss->Boss,boss->posmonsx,boss->posmonsy);    
                } 
                if(insidechevalierBoss(joueur, boss)==1 && joueur->Numattack==15)
                {           
                    boss->CompteurSpriteDegat=1; 
                    boss->Life--; 
                }
            } 
            //degat sur Boss
            else 
            {
                boss->CompteurSpriteDegat+=1;
                boss->Boss=loadImage("src/graphics/Boss/BossDegat.png");
                drawImage(boss->Boss,boss->posmonsx,boss->posmonsy); 
                if (boss->CompteurSpriteDegat==2)
                {
                Mix_VolumeChunk(son->degatboss, MIX_MAX_VOLUME/2);
                Mix_PlayChannel(2, son->degatboss, 0);   
                }
                if (boss->CompteurSpriteDegat > 15)
                {
                    boss->CompteurSpriteDegat=0;  
                }
            }   
        }
        //init eclair une fois par round
        if (boss->compteur == 200)
        {
            initEclair(boss);
        }
        // lancement attaque eclair
        if (boss->compteur >= 200 && boss->compteur < 530)
        {   
            //Eclair 1
            if (boss->CompteurSpriteEclair>=0 && boss->CompteurSpriteEclair<=10 )
            {
                boss->Eclair1=loadImage("src/graphics/Boss/WarningBoss1.png");
                drawImage(boss->Eclair1,boss->Ex1+12,boss->Ey1-16);   
            }
            if (boss->CompteurSpriteEclair>=11 && boss->CompteurSpriteEclair<=20 )
            {
                boss->Eclair1=loadImage("src/graphics/Boss/WarningBoss2.png");
                drawImage(boss->Eclair1,boss->Ex1,boss->Ey1-26);
            }
            if (boss->CompteurSpriteEclair>=21 && boss->CompteurSpriteEclair<=30)
            {
                boss->Eclair1=loadImage("src/graphics/Boss/EclairBoss.png");
                drawImage(boss->Eclair1,boss->Ex1,boss->Ey1-405);
            }
            
            if ((boss->CompteurSpriteEclair==25 && insideEclair(joueur, boss->Ex1, boss->Ey1-405)==1))
            {
                //joueur->life--;
                boss->coupE1=1;
            }
            if (boss->coupE1==1 && boss->compteur>240)
            {
                boss->coupE1=0;
            }
        
            //Eclair 2
            if (boss->CompteurSpriteEclair>=31 && boss->CompteurSpriteEclair<=40 )
            {
                boss->Eclair2=loadImage("src/graphics/Boss/WarningBoss1.png");
                drawImage(boss->Eclair2,boss->Ex2+12,boss->Ey2-16);
            }
            if (boss->CompteurSpriteEclair>=41 && boss->CompteurSpriteEclair<=50 )
            {
                boss->Eclair2=loadImage("src/graphics/Boss/WarningBoss2.png");
                drawImage(boss->Eclair2,boss->Ex2,boss->Ey2-26);
            }
            if (boss->CompteurSpriteEclair>=51 && boss->CompteurSpriteEclair<=60 )
            {
                boss->Eclair2=loadImage("src/graphics/Boss/EclairBoss.png");
                drawImage(boss->Eclair2,boss->Ex2,boss->Ey2-405);
            }
            if ((boss->CompteurSpriteEclair==55 && insideEclair(joueur, boss->Ex2, boss->Ey2-405)==1))
            {
                //joueur->life--;
                boss->coupE2=1;
            }
            if (boss->compteur>270 && boss->coupE2==1)
            {
                boss->coupE2=0;
            }
            //Eclair 3
            if (boss->CompteurSpriteEclair>=61 && boss->CompteurSpriteEclair<=70 )
            {
                boss->Eclair3=loadImage("src/graphics/Boss/WarningBoss1.png");
                drawImage(boss->Eclair3,boss->Ex3+12,boss->Ey3-16);
            }
            if (boss->CompteurSpriteEclair>=71 && boss->CompteurSpriteEclair<=80 )
            {
                boss->Eclair3=loadImage("src/graphics/Boss/WarningBoss2.png");
                drawImage(boss->Eclair3,boss->Ex3,boss->Ey3-26);
            }
            if (boss->CompteurSpriteEclair>=81 && boss->CompteurSpriteEclair<=90 )
            {
                boss->Eclair3=loadImage("src/graphics/Boss/EclairBoss.png");
                drawImage(boss->Eclair3,boss->Ex3,boss->Ey3-405);
            }
            if ((boss->CompteurSpriteEclair==85 && insideEclair(joueur, boss->Ex3, boss->Ey3-405)==1))
            {
                //joueur->life--;
                boss->coupE3=1;
            }
            if (boss->coupE3==1 && boss->compteur==300)
            {
                boss->coupE3=0;
            }

            //Eclair 4
            if (boss->CompteurSpriteEclair>=91 && boss->CompteurSpriteEclair<=100 )
            {
                boss->Eclair4=loadImage("src/graphics/Boss/WarningBoss1.png");
                drawImage(boss->Eclair4,boss->Ex4+12,boss->Ey4-16);
            }
            if (boss->CompteurSpriteEclair>=101 && boss->CompteurSpriteEclair<=110 )
            {
                boss->Eclair4=loadImage("src/graphics/Boss/WarningBoss2.png");
                drawImage(boss->Eclair4,boss->Ex4,boss->Ey4-26);
            }
            if (boss->CompteurSpriteEclair>=111 && boss->CompteurSpriteEclair<=121 )
            {
                boss->Eclair4=loadImage("src/graphics/Boss/EclairBoss.png");
                drawImage(boss->Eclair4,boss->Ex4,boss->Ey4-405);
            }
            if ((boss->CompteurSpriteEclair==115 && insideEclair(joueur, boss->Ex4, boss->Ey4-405)==1))
            {
                //joueur->life--;
                boss->coupE4=1;
            } 
            // inside eclair 4 hors boucle
            if (boss->compteur>330 && boss->coupE4==1)
            {
                boss->coupE4=0;
            }
        }
        //Attaque boss
        if  (boss->compteur>=450)
        {   
            if (boss->NumSprit==0 || boss->NumSprit==1 || boss->NumSprit==2 || boss->NumSprit==3 )
            {
                boss->Boss=loadImage("src/graphics/Boss/Bossattaque1.png");
                drawImage(boss->Boss,boss->posmonsx,boss->posmonsy);
            }
            if (boss->NumSprit==4 || boss->NumSprit==5 || boss->NumSprit==6 || boss->NumSprit==7 || boss->NumSprit==29 || boss->NumSprit==30 || boss->NumSprit==31 || boss->NumSprit==32 )
            {
                boss->Boss=loadImage("src/graphics/Boss/Bossattaque2.png");
                drawImage(boss->Boss,boss->posmonsx,boss->posmonsy);
            }
            if (boss->NumSprit==8 || boss->NumSprit==9 || boss->NumSprit==10 || boss->NumSprit==11|| boss->NumSprit==24 || boss->NumSprit==25 || boss->NumSprit==26 || boss->NumSprit==27 || boss->NumSprit==28 )
            {
                boss->Boss=loadImage("src/graphics/Boss/Bossattaque3.png");
                drawImage(boss->Boss,boss->posmonsx,boss->posmonsy);
            }
            if (boss->NumSprit==12 || boss->NumSprit==13 || boss->NumSprit==14 || boss->NumSprit==19 || boss->NumSprit==20 || boss->NumSprit==21 || boss->NumSprit==22 || boss->NumSprit==23 )
            {
                boss->Boss=loadImage("src/graphics/Boss/Bossattaque4.png");                    
                drawImage(boss->Boss,boss->posmonsx,boss->posmonsy);
            }
            if (boss->NumSprit==15 || boss->NumSprit==16 || boss->NumSprit==17 || boss->NumSprit==18 )
            {   if (boss->NumSprit==15)
                {
                Mix_VolumeChunk(son->attaqueboss, MIX_MAX_VOLUME/2);
                Mix_PlayChannel(7, son->attaqueboss, 0);
                }
                boss->Boss=loadImage("src/graphics/Boss/Bossattaque5.png");
                drawImage(boss->Boss,boss->posmonsx,boss->posmonsy);
                boss->Bossattaque=loadImage("src/graphics/Boss/AttaqueBoss.png");
                drawImage(boss->Bossattaque,boss->posmonsx -46 ,boss->posmonsy - 46);
                //fonction inside
                if(insideBoss(joueur, boss)==1 && (boss->NumSprit==15 || boss->NumSprit==18))                    
                {
                    if (boss->coup == 0)
                    {
                        //joueur->life--;
                        boss->coup =1;
                    }
                }
            }
            
            if (boss->compteur>530)
            {
                boss->compteur = 0;
                boss->coup = 0;
                boss->CompteurSpriteEclair= 0;
            }
        }
        if (boss->NumSprit>=32)
        {
            boss->NumSprit=0;
        }
        
    }

    //mort bosse
    if (boss->Life==0)
    {   
        Mix_PauseMusic();
        if (boss->CompteurSpriteDegat>=0 && boss->CompteurSpriteDegat <= 5 )
        {
            boss->Boss=loadImage("src/graphics/Boss/Bossmort1.png");
            drawImage(boss->Boss,boss->posmonsx,boss->posmonsy);
            Mix_VolumeChunk(son->mortboss, MIX_MAX_VOLUME/2);
            Mix_PlayChannel(6, son->mortboss, 0);
        }
        if (boss->CompteurSpriteDegat>= 6 && boss->CompteurSpriteDegat<=10 )
        {
            boss->Boss=loadImage("src/graphics/Boss/Bossmort2.png");
            drawImage(boss->Boss,boss->posmonsx,boss->posmonsy);
        }
        if (boss->CompteurSpriteDegat>=11 && boss->CompteurSpriteDegat<=15)
        {
            boss->Boss=loadImage("src/graphics/Boss/Bossmort3.png");
            drawImage(boss->Boss,boss->posmonsx,boss->posmonsy);
        }
        if (boss->CompteurSpriteDegat>=16 && boss->CompteurSpriteDegat<=20 )
        {
            boss->Boss=loadImage("src/graphics/Boss/Bossmort4.png");
            drawImage(boss->Boss,boss->posmonsx,boss->posmonsy);
        }
        if (boss->CompteurSpriteDegat==21)
        {
            boss->Boss=loadImage("src/graphics/Boss/Bossmort5.png");
            drawImage(boss->Boss,boss->posmonsx,boss->posmonsy);
        }
        //Coffre ouvert
        if (boss->CompteurSpriteDegat>=22 )
        {
            boss->Boss=loadImage("src/graphics/Boss/Bossmort6.png");
            drawImage(boss->Boss,boss->posmonsx,boss->posmonsy);
        }
        if (boss->CompteurSpriteDegat>22 && boss->CompteurSpriteDegat<27)
        {
            boss->Coeur=loadImage("src/graphics/lvl/Coeur1.png");
            drawImage(boss->Coeur,boss->posmonsx,boss->posmonsy+78);
        }
        if (boss->CompteurSpriteDegat>=27 && boss->CompteurSpriteDegat<32)
        {
            boss->Coeur=loadImage("src/graphics/lvl/Coeur1.png");
            drawImage(boss->Coeur,boss->posmonsx-5,boss->posmonsy+73);
        }
        if (boss->CompteurSpriteDegat>=32 && boss->CompteurSpriteDegat<37)
        {
            boss->Coeur=loadImage("src/graphics/lvl/Coeur1.png");
            drawImage(boss->Coeur,boss->posmonsx-10,boss->posmonsy+68);
        }
        if (boss->CompteurSpriteDegat>=37 && boss->CompteurSpriteDegat<42)
        {
            boss->Coeur=loadImage("src/graphics/lvl/Coeur1.png");
            drawImage(boss->Coeur,boss->posmonsx-15,boss->posmonsy+73);
        }
        if (boss->CompteurSpriteDegat>=42)
        {
            if (boss->RecupCoeur==0)
            {
                if (boss->CompteurSpriteDegat % 50 == 0)
                {
                    boss->Coeur=loadImage("src/graphics/lvl/Coeur1.png");
                    drawImage(boss->Coeur,boss->posmonsx-20,boss->posmonsy+78);
                }
                else
                {
                    boss->Coeur=loadImage("src/graphics/lvl/Coeur2.png");
                    drawImage(boss->Coeur,boss->posmonsx-20,boss->posmonsy+78);
                }
                if (insideItem(joueur,boss)==1)
                {
                    joueur->life++;
                    boss->RecupCoeur=1;
                }
            }
            else
            {
                SDL_DestroyTexture(boss->Coeur);
                boss->Coeur=NULL;
            }
        }
    } 
}