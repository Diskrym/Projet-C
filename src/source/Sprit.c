#include "../header/proto.h" 

void SpritHeros(Joueur *joueur, Input *input, EffetSon *son, Entité *entité)
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
    if (joueur->dague != NULL)
    {
        SDL_DestroyTexture(joueur->dague);
        joueur->dague = NULL;
    }
    if (joueur->dagueMur != NULL)
    {
        SDL_DestroyTexture(joueur->dagueMur);
        joueur->dagueMur = NULL;
    }
    
    if(joueur->Ebateau<2)
    {
        //Mouvement du joueur droite si bouclier baisser ou si timing bouclier dépassé
        if (joueur->Direction ==0 && joueur->Eattack==0 && (joueur->Eshield==0 || (joueur->Eshield==1 && joueur->TimingBouclier>15)))
        {
            //se deplace si ne prend pas de dégat sinon sprit degat
            if (DegatChevalier(&entité->meduse, &entité->meduse1 , &entité->meduse2, &entité->chauvesouris , &entité->chauvesouris1, &entité->boss, &entité->yeti, &entité->yeti1, &entité->yeti2)==1)
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
                    // {Mix_VolumeChunk(son->depchevalier, MIX_MAX_VOLUME);
                    // Mix_PlayChannel(3, son->depchevalier, 0);}   
                }
                if (joueur->NumSprit >=7 || joueur->NumSprit ==6 )
                {
                    joueur->chevalier=loadImage("src/graphics/Chevalier/marche2D.png");
                    drawImage(joueur->chevalier,joueur->inposx,joueur->inposy);
                    joueur->NumSprit =0;
                    // if (joueur->NumSprit==7)
                    // {
                    // Mix_VolumeChunk(son->depchevalier, MIX_MAX_VOLUME);
                    // Mix_PlayChannel(3, son->depchevalier, 0);
                    // }
                }
            }
            
        }
        //affiche sprite degat si degat de la part du entité et si degat de la part du entité lors de notre attack/defense pour la droite
        if((joueur->Direction ==0 && (joueur->Eattack==1 || joueur->Eshield==1) && DegatChevalier(&entité->meduse, &entité->meduse1 , &entité->meduse2, &entité->chauvesouris , &entité->chauvesouris1, &entité->boss, &entité->yeti, &entité->yeti1, &entité->yeti2)==0) || (DegatChevalier(&entité->meduse, &entité->meduse1 , &entité->meduse2, &entité->chauvesouris , &entité->chauvesouris1, &entité->boss, &entité->yeti, &entité->yeti1, &entité->yeti2)==0) && joueur->Direction==0)
        {
            joueur->chevalier=loadImage("src/graphics/Chevalier/DégatD.png");
            drawImage(joueur->chevalier,joueur->inposx,joueur->inposy);
            Mix_VolumeChunk(son->degatchevalier, MIX_MAX_VOLUME);
            Mix_PlayChannel(1, son->degatchevalier, 0);
        }
        
        //cf fonction gauche
        if (joueur->Direction ==1 && joueur->Eattack==0 && (joueur->Eshield==0 || (joueur->Eshield==1 && joueur->TimingBouclier>15)))
        {
            if(DegatChevalier(&entité->meduse, &entité->meduse1 , &entité->meduse2, &entité->chauvesouris , &entité->chauvesouris1, &entité->boss, &entité->yeti, &entité->yeti1, &entité->yeti2)==1)
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
                    // Mix_VolumeChunk(son->depchevalier, MIX_MAX_VOLUME);
                    // Mix_PlayChannel(3, son->depchevalier, 0);
                    // }
                }
                if (joueur->NumSprit >=6)
                {
                    joueur->chevalier=loadImage("src/graphics/Chevalier/marche2G.png");
                    drawImage(joueur->chevalier,joueur->inposx,joueur->inposy);
                    // if (joueur->NumSprit==7)
                    // {
                    // Mix_VolumeChunk(son->depchevalier, MIX_MAX_VOLUME);
                    // Mix_PlayChannel(3, son->depchevalier, 0);
                    // }
                    joueur->NumSprit =0;
                }   
            }
        }
        if ((joueur->Direction ==1 && (joueur->Eattack==1 || joueur->Eshield==1) && DegatChevalier(&entité->meduse, &entité->meduse1 , &entité->meduse2, &entité->chauvesouris , &entité->chauvesouris1, &entité->boss, &entité->yeti, &entité->yeti1, &entité->yeti2)==0) || (DegatChevalier(&entité->meduse, &entité->meduse1 , &entité->meduse2, &entité->chauvesouris , &entité->chauvesouris1, &entité->boss, &entité->yeti, &entité->yeti1, &entité->yeti2)==0) && joueur->Direction==1 )
        {
            joueur->chevalier=loadImage("src/graphics/Chevalier/DégatG.png");
            drawImage(joueur->chevalier,joueur->inposx,joueur->inposy);
            Mix_VolumeChunk(son->degatchevalier, MIX_MAX_VOLUME);
            Mix_PlayChannel(1, son->degatchevalier, 0);
        }
        
        //Mouvement attaque si Eattack = 1 et si on ne prend pas de dégat
        if (joueur->Eattack==1 && DegatChevalier(&entité->meduse, &entité->meduse1, &entité->meduse2, &entité->chauvesouris, &entité->chauvesouris1,&entité->boss, &entité->yeti, &entité->yeti1, &entité->yeti2)==1)
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
                        Mix_VolumeChunk(son->epee, MIX_MAX_VOLUME);
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
                        Mix_VolumeChunk(son->epee, MIX_MAX_VOLUME);
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
                        //Mix_VolumeChunk(son->bouclier, MIX_MAX_VOLUME);
                        //Mix_PlayChannel(2, son->bouclier, 0);
                    }
                }
                if (joueur->Direction==1)
                {
                    if (joueur->NumSprit==0)
                    {
                        joueur->chevalier=loadImage("src/graphics/Chevalier/ChevaliershieldG.png");
                        drawImage(joueur->chevalier,joueur->inposx,joueur->inposy);
                        //Mix_VolumeChunk(son->bouclier, MIX_MAX_VOLUME);
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

        //Dague
        if (joueur->Edague == 1 && joueur->nbDague>0 && joueur->DirDague==1)
        {
            if (joueur->xdague>=20 && joueur->xdague<=600 && joueur->ydague>= 20 && joueur->ydague<=384)
            {
                joueur->dague=loadImage("src/graphics/Chevalier/DagueG.png");
                drawImage(joueur->dague,joueur->xdague,joueur->ydague);
                joueur->xdague-=10;
            }
            else
            {   
                
                joueur->dagueMur=loadImage("src/graphics/Chevalier/DagueMurG.png");
                drawImage(joueur->dagueMur,joueur->xdague,joueur->ydague);
                
                Mix_VolumeChunk(son->dague, MIX_MAX_VOLUME);
                Mix_PlayChannel(15, son->dague, 0);
            
                //recup dague Gauchemap
                if (joueur->inposx <= joueur->xdague+20 && (joueur->inposy+SPRITE_SIZE>=joueur->ydague && joueur->inposy<=joueur->ydague))
                {
                    SDL_DestroyTexture(joueur->dagueMur);
                    joueur->dagueMur = NULL;
                    joueur->Edague=0;
                    //joueur->CoupDague=0;
                }
            }
        }
        //dague
        if (joueur->Edague == 1 && joueur->nbDague>0 && joueur->DirDague == 0)
        {
            if (joueur->xdague>=20 && joueur->xdague<=600 && joueur->ydague>= 20 && joueur->ydague<=384)
            { 
                joueur->dague=loadImage("src/graphics/Chevalier/DagueD.png");
                drawImage(joueur->dague,joueur->xdague,joueur->ydague);
                joueur->xdague+=10;
            }
            else
            {
                joueur->dagueMur=loadImage("src/graphics/Chevalier/DagueMurD.png");
                drawImage(joueur->dagueMur,joueur->xdague,joueur->ydague);
                Mix_VolumeChunk(son->dague, MIX_MAX_VOLUME);
                Mix_PlayChannel(15, son->dague, 0);
                //recup dague Droite map
                if (joueur->inposx >= joueur->xdague-60 && (joueur->inposy+SPRITE_SIZE>=joueur->ydague && joueur->inposy<=joueur->ydague))
                {
                    SDL_DestroyTexture(joueur->dagueMur);
                    joueur->dagueMur = NULL;
                    joueur->Edague=0;
                    //joueur->CoupDague=0;
                }
            }
        }
    }
    else if (DegatBateau(&entité->tronc, &entité->Petit_rocher ,&entité->Gros_rocher) == 1)
    {
        joueur->NumSprit+=1;
        if(joueur->NumSprit<10 || joueur->NumSprit>=40)
        {
            joueur->chevalier=loadImage("src/graphics/Chevalier/ChevalierBateau.png");
            drawImage(joueur->chevalier,joueur->inposx,joueur->inposy+1);  
        }
        if((joueur->NumSprit>=10 && joueur->NumSprit<20) || (joueur->NumSprit>=30 && joueur->NumSprit<40))
        {
            joueur->chevalier=loadImage("src/graphics/Chevalier/ChevalierBateau.png");
            drawImage(joueur->chevalier,joueur->inposx,joueur->inposy);  
        }
        if(joueur->NumSprit>=20 && joueur->NumSprit<30)
        {
            joueur->chevalier=loadImage("src/graphics/Chevalier/ChevalierBateau.png");
            drawImage(joueur->chevalier,joueur->inposx,joueur->inposy-1);  
        }
        if (joueur->NumSprit >=39)
        {
            joueur->NumSprit=0;
        }
        
    }
    else
    {
        joueur->chevalier=loadImage("src/graphics/Chevalier/ChevalierBateauDegat.png");
        drawImage(joueur->chevalier,joueur->inposx,joueur->inposy);
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
                }
                //degat epee
                if(insidechevalier(joueur, meduse)==1 && joueur->Numattack==15)
                {           
                    meduse->CompteurSpriteDegat=1; 
                    meduse->Life--; 
                }
                //degat dague
                if (insideVol(joueur->xdague,joueur->ydague, meduse->posmonsx, meduse->posmonsy,64,64,30,15)==1)
                {
                    meduse->CompteurSpriteDegat=1; 
                    meduse->Life--; 
                    //joueur->CoupDague=1;
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
                    Mix_VolumeChunk(son->degatmeduse, MIX_MAX_VOLUME);
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
                    Mix_VolumeChunk(son->attaquemeduse, MIX_MAX_VOLUME);
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
                        joueur->life--;
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
                Mix_VolumeChunk(son->mortmeduse, MIX_MAX_VOLUME);
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

void Sprityeti (Yeti *yeti, Joueur *joueur,Lvl *lvl, EffetSon *son)
{  
    //reset pointeur yeti
    if (yeti->yeti!=NULL)
    {
        SDL_DestroyTexture(yeti->yeti);
        yeti->yeti=NULL;
    }
    if (yeti->attaqueyeti!=NULL)
    {
        SDL_DestroyTexture(yeti->attaqueyeti);
        yeti->attaqueyeti=NULL;
    }
    if (yeti->boule!=NULL)
    {
        SDL_DestroyTexture(yeti->boule);
        yeti->boule=NULL;
    }

 
    //Mouvement  yeti quand en vie
    if (yeti->Life >=1)
    {
        //compteur < 100 pour déplacement normal
        if (yeti->compteur < 100)
        {  
            //si la yeti n'a pas prit de coup
            if (yeti->CompteurSpriteDegat==0)
            {
                if (yeti->Direction==1)
                {
                    if (yeti->NumSprit==0 || yeti->NumSprit==1 || yeti->NumSprit==2 || yeti->NumSprit==3 || yeti->NumSprit==8 || yeti->NumSprit==9 || yeti->NumSprit==10 || yeti->NumSprit==11)
                    {
                        yeti->yeti=loadImage("src/graphics/yeti/YetiNeutreG.png");
                        drawImage(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
                    }
                    if (yeti->NumSprit==4 || yeti->NumSprit==5 || yeti->NumSprit==6 || yeti->NumSprit==7)
                    {
                        yeti->yeti=loadImage("src/graphics/yeti/YetiMarche1G.png");
                        drawImage(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
                    }
                    if (yeti->NumSprit==12 || yeti->NumSprit==13 || yeti->NumSprit==14 || yeti->NumSprit==15)
                    {
                        yeti->yeti=loadImage("src/graphics/yeti/YetiMarche2G.png");
                        drawImage(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
                    }
                    if (yeti->NumSprit>=16 )
                    {
                        yeti->yeti=loadImage("src/graphics/yeti/YetiNeutreG.png");
                        drawImage(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
                    }
                    if(insidechevalieryeti(joueur, yeti)==1 && joueur->Numattack==15)
                    {          
                        yeti->CompteurSpriteDegat=1;
                        yeti->Life--;
                    }
                }

                 if (yeti->Direction==0)
                {
                    if (yeti->NumSprit==0 || yeti->NumSprit==1 || yeti->NumSprit==2 || yeti->NumSprit==3 || yeti->NumSprit==8 || yeti->NumSprit==9 || yeti->NumSprit==10 || yeti->NumSprit==11)
                    {
                        yeti->yeti=loadImage("src/graphics/yeti/YetiNeutreD.png");
                        drawImage(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
                    }
                    if (yeti->NumSprit==4 || yeti->NumSprit==5 || yeti->NumSprit==6 || yeti->NumSprit==7)
                    {
                        yeti->yeti=loadImage("src/graphics/yeti/YetiMarche1D.png");
                        drawImage(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
                    }
                    if (yeti->NumSprit==12 || yeti->NumSprit==13 || yeti->NumSprit==14 || yeti->NumSprit==15)
                    {
                        yeti->yeti=loadImage("src/graphics/yeti/YetiMarche2D.png");
                        drawImage(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
                    }
                    if (yeti->NumSprit>=16 )
                    {
                        yeti->yeti=loadImage("src/graphics/yeti/YetiNeutreD.png");
                        drawImage(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
                    }
                    if(insidechevalieryeti(joueur, yeti)==1 && joueur->Numattack==15)
                    {          
                        yeti->CompteurSpriteDegat=1;
                        yeti->Life--;
                    }
                }
                //degat dague
                if (insideVol(joueur->xdague,joueur->ydague, yeti->posmonsx+10, yeti->posmonsy+15,45,60,30,15)==1)
                {
                    yeti->CompteurSpriteDegat=1; 
                    yeti->Life--; 
                    //joueur->CoupDague=1;
                }
            }
 
            else
            {   
                if (yeti->Direction==1)
                {
                    //si la yeti prend un coup
                    yeti->CompteurSpriteDegat+=1;
                    yeti->yeti=loadImage("src/graphics/yeti/YetiDegatG.png");
                    drawImage(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
                    Mix_VolumeChunk(son->degatyeti, MIX_MAX_VOLUME);
                    Mix_PlayChannel(4, son->degatyeti, 0);
                   
                    //compteur duree affichage degat yeti
                    if (yeti->CompteurSpriteDegat > 15)
                    {
                        yeti->CompteurSpriteDegat=0;
                    }
                }

                if (yeti->Direction==0)
                {
                    //si la yeti prend un coup
                    yeti->CompteurSpriteDegat+=1;
                    yeti->yeti=loadImage("src/graphics/yeti/YetiDegatD.png");
                    drawImage(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
                    if (yeti->CompteurSpriteDegat==2)
                    {
                    Mix_VolumeChunk(son->degatyeti, MIX_MAX_VOLUME);
                     Mix_PlayChannel(14, son->degatyeti, 0);
                    }          
                    //compteur duree affichage degat yeti
                    if (yeti->CompteurSpriteDegat > 15)
                    {
                        yeti->CompteurSpriteDegat=0;
                    }
                }
            } 
             if (yeti->NumSprit>=16)
            {
                 yeti->NumSprit=0;
            } 
        }
        //attaqueyeti yeti quand compteur > 100
        if  (yeti->compteur>=100)
        {
            if (yeti->Direction==1)
            {             
                if (yeti->NumSprit>=0 && yeti->NumSprit<10 || yeti->NumSprit>=80  )
                {   
                    yeti->yeti=loadImage("src/graphics/yeti/YetiAttaque1G.png");
                    drawImage(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
                }
                if (yeti->NumSprit>=10 && yeti->NumSprit<20 || yeti->NumSprit>=70 && yeti->NumSprit<80)
                {
                    yeti->yeti=loadImage("src/graphics/yeti/YetiAttaque2G.png");
                    drawImage(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
                }
                if (yeti->NumSprit>=20 && yeti->NumSprit<30 || yeti->NumSprit>=60 && yeti->NumSprit<70)
                {   
                    if (yeti->NumSprit==60)
                    {
                    Mix_VolumeChunk(son->attaqueyeti, MIX_MAX_VOLUME);
                    Mix_PlayChannel(16, son->attaqueyeti, 0);
                    }
                    yeti->yeti=loadImage("src/graphics/yeti/YetiAttaque3G.png");
                    drawImage(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
                    if (yeti->NumSprit == 65)
                    {
                        yeti->Eattaque = 1;
                        yeti->directionboule=yeti->Direction;
                        yeti->xboule=yeti->posmonsx+33;
                        yeti->yboule=yeti->posmonsy+7;
                    }
                    
                }
                if (yeti->NumSprit>=30 && yeti->NumSprit<40 || yeti->NumSprit>=50 && yeti->NumSprit<60)
                {                
                    yeti->yeti=loadImage("src/graphics/yeti/YetiAttaque4G.png");                    
                    drawImage(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
                }
                if (yeti->NumSprit>=40 && yeti->NumSprit<50 )
                {                
                    yeti->yeti=loadImage("src/graphics/yeti/YetiAttaque5G.png");                    
                    drawImage(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
                }
                
            }

            if (yeti->Direction==0)
            {             
                if (yeti->NumSprit>=0 && yeti->NumSprit<10 || yeti->NumSprit>=80 )
                {  
                    
                
                    yeti->yeti=loadImage("src/graphics/yeti/YetiAttaque1D.png");
                    drawImage(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
                }
                if (yeti->NumSprit>=10 && yeti->NumSprit<20 || yeti->NumSprit>=70 && yeti->NumSprit<80)
                {
                    yeti->yeti=loadImage("src/graphics/yeti/YetiAttaque2D.png");
                    drawImage(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
                }
                if (yeti->NumSprit>=20 && yeti->NumSprit<30 || yeti->NumSprit>=60 && yeti->NumSprit<70)
                {   
                    if (yeti->NumSprit==60)
                    {
                    Mix_VolumeChunk(son->attaqueyeti, MIX_MAX_VOLUME);
                    Mix_PlayChannel(16, son->attaqueyeti, 0);
                    }
                    yeti->yeti=loadImage("src/graphics/yeti/YetiAttaque3D.png");
                    drawImage(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
                    if (yeti->NumSprit == 65)
                    {
                        yeti->Eattaque = 1;
                        yeti->directionboule=yeti->Direction;
                        yeti->xboule=yeti->posmonsx+33;
                        yeti->yboule=yeti->posmonsy+9;
                    }
                }
                if (yeti->NumSprit>=30 && yeti->NumSprit<40 || yeti->NumSprit>=50 && yeti->NumSprit<60)
                {                
                    yeti->yeti=loadImage("src/graphics/yeti/YetiAttaque4D.png");                    
                    drawImage(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
                }
                if (yeti->NumSprit>=40 && yeti->NumSprit<50 )
                {                
                    yeti->yeti=loadImage("src/graphics/yeti/YetiAttaque5D.png");                    
                    drawImage(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
                }
                //reset compteur yeti
            }
            if (yeti->NumSprit>90)
            {
                yeti->NumSprit=0;
            } 
        }
    }
    
    //Sprit boule
    if (yeti->Eattaque == 1)
    {
        if (yeti->directionboule==1)
        {
            if (yeti->xboule>=20 && yeti->xboule<=600 && yeti->yboule>= 20 && yeti->yboule<=384)
            { 
                yeti->boule=loadImage("src/graphics/yeti/BouleDeNeige.png");                    
                drawImage(yeti->boule,yeti->xboule,yeti->yboule);
                
                if (insideVol(yeti->xboule,yeti->yboule,joueur->inposx,joueur->inposy,64,64,21,17)==1 && yeti->coup == 0)
                {
                    joueur->life--;
                    yeti->coup=1;
                }
                yeti->xboule-=7;
            }
            else
            {
                yeti->CompteurBoule+=1;
                if (yeti->CompteurBoule>=0 && yeti->CompteurBoule<5)
                {  
                     if (yeti->CompteurBoule==1)
                    {
                    Mix_VolumeChunk(son->bouledeneige, MIX_MAX_VOLUME);
                    Mix_PlayChannel(7, son->bouledeneige, 0);
                    }
                    
                    yeti->boule=loadImage("src/graphics/yeti/BouleDeMur1G.png");
                    drawImage(yeti->boule,yeti->xboule,yeti->yboule);
                }
                if (yeti->CompteurBoule>=5 && yeti->CompteurBoule<10)
                {  
                    yeti->boule=loadImage("src/graphics/yeti/BouleDeMur2G.png");
                    drawImage(yeti->boule,yeti->xboule,yeti->yboule);
                }
                if (yeti->CompteurBoule>=15 && yeti->CompteurBoule<20)
                {  
                    yeti->boule=loadImage("src/graphics/yeti/BouleDeMur3G.png");
                    drawImage(yeti->boule,yeti->xboule,yeti->yboule);
                }
                if (yeti->CompteurBoule>=20 && yeti->CompteurBoule<25)
                {  
                    yeti->boule=loadImage("src/graphics/yeti/BouleDeMur4G.png");
                    drawImage(yeti->boule,yeti->xboule,yeti->yboule);
                }
                if (yeti->CompteurBoule>=25)
                {
                    SDL_DestroyTexture(yeti->boule);
                    yeti->boule=NULL;
                    yeti->Eattaque=0;
                    yeti->CompteurBoule=0;
                }
            }
        }
        if (yeti->directionboule==0)
        {
            if (yeti->xboule>=20 && yeti->xboule<=600 && yeti->yboule>= 20 && yeti->yboule<=384)
            { 
                yeti->boule=loadImage("src/graphics/yeti/BouleDeNeige.png");                    
                drawImage(yeti->boule,yeti->xboule,yeti->yboule);
                if (insideVol(yeti->xboule,yeti->yboule,joueur->inposx,joueur->inposy,64,64,21,17)==1 && yeti->coup == 0)
                {
                    joueur->life--;
                    yeti->coup=1;
                }
                yeti->xboule+=7; 
            }
            else
            {
                yeti->CompteurBoule+=1;
                if (yeti->CompteurBoule>=0 && yeti->CompteurBoule<5)
                {  
                    if (yeti->CompteurBoule==1)
                    {
                    Mix_VolumeChunk(son->bouledeneige, MIX_MAX_VOLUME);
                    Mix_PlayChannel(7, son->bouledeneige, 0);
                    }
                    yeti->boule=loadImage("src/graphics/yeti/BouleDeMur1D.png");
                    drawImage(yeti->boule,yeti->xboule,yeti->yboule);
                }
                if (yeti->CompteurBoule>=5 && yeti->CompteurBoule<10)
                {  
                    yeti->boule=loadImage("src/graphics/yeti/BouleDeMur2D.png");
                    drawImage(yeti->boule,yeti->xboule,yeti->yboule);
                }
                if (yeti->CompteurBoule>=15 && yeti->CompteurBoule<20)
                {  
                    yeti->boule=loadImage("src/graphics/yeti/BouleDeMur3D.png");
                    drawImage(yeti->boule,yeti->xboule,yeti->yboule);
                }
                if (yeti->CompteurBoule>=20 && yeti->CompteurBoule<25)
                {  
                    yeti->boule=loadImage("src/graphics/yeti/BouleDeMur4D.png");
                    drawImage(yeti->boule,yeti->xboule,yeti->yboule);
                }
                if (yeti->CompteurBoule>=25)
                {
                    SDL_DestroyTexture(yeti->boule);
                    yeti->boule=NULL;
                    yeti->Eattaque=0;
                    yeti->CompteurBoule=0;
                }
            }
        }
    }
    // timing degat chevalier
    if (yeti->coup>0)
    {
        yeti->coup+=1;
        if (yeti->coup >25)
        {
            yeti->coup=0;
        }
    }
    if (yeti->compteur>=190)
    {
        yeti->compteur=0;
    }
    //Mort yeti
    if (yeti->Life==0)
    {
        if (yeti->Direction==1)
        {  
            if (yeti->CompteurSpriteDegat==0 || yeti->CompteurSpriteDegat==1 || yeti->CompteurSpriteDegat==2 || yeti->CompteurSpriteDegat==3 )
            {
                yeti->yeti=loadImage("src/graphics/yeti/YetiMort1G.png");
                drawImage(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
                if (yeti->CompteurSpriteDegat==1)
                {
                    Mix_VolumeChunk(son->mortyeti, MIX_MAX_VOLUME);
                    Mix_PlayChannel(9, son->mortyeti, 0);
                }
            }
            if (yeti->CompteurSpriteDegat==4 || yeti->CompteurSpriteDegat==5 || yeti->CompteurSpriteDegat==6 || yeti->CompteurSpriteDegat==7 )
            {
                yeti->yeti=loadImage("src/graphics/yeti/YetiMort2G.png");
                drawImage(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
            }
            if (yeti->CompteurSpriteDegat==8 || yeti->CompteurSpriteDegat==9 || yeti->CompteurSpriteDegat==10 || yeti->CompteurSpriteDegat==11)
            {
                yeti->yeti=loadImage("src/graphics/yeti/YetiMort3G.png");
                drawImage(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
            }
            if (yeti->CompteurSpriteDegat==12 || yeti->CompteurSpriteDegat==13 || yeti->CompteurSpriteDegat==14 || yeti->CompteurSpriteDegat==15 )
            {
                yeti->yeti=loadImage("src/graphics/yeti/YetiMort4G.png");
                drawImage(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
            }
            if (yeti->CompteurSpriteDegat==16 || yeti->CompteurSpriteDegat==17 || yeti->CompteurSpriteDegat==18 || yeti->CompteurSpriteDegat==19 )
            {
                yeti->yeti=loadImage("src/graphics/yeti/YetiMort5G.png");
                drawImage(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
            }
        }

        if (yeti->Direction==0)
        {  
            if (yeti->CompteurSpriteDegat==0 || yeti->CompteurSpriteDegat==1 || yeti->CompteurSpriteDegat==2 || yeti->CompteurSpriteDegat==3 )
            {
                yeti->yeti=loadImage("src/graphics/yeti/YetiMort1D.png");
                drawImage(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
                if (yeti->CompteurSpriteDegat==1)
                {
                Mix_VolumeChunk(son->mortyeti, MIX_MAX_VOLUME);
                Mix_PlayChannel(9, son->mortyeti, 0);
                }
            }
            if (yeti->CompteurSpriteDegat==4 || yeti->CompteurSpriteDegat==5 || yeti->CompteurSpriteDegat==6 || yeti->CompteurSpriteDegat==7 )
            {
                yeti->yeti=loadImage("src/graphics/yeti/YetiMort2D.png");
                drawImage(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
            }
            if (yeti->CompteurSpriteDegat==8 || yeti->CompteurSpriteDegat==9 || yeti->CompteurSpriteDegat==10 || yeti->CompteurSpriteDegat==11)
            {
                yeti->yeti=loadImage("src/graphics/yeti/YetiMort3D.png");
                drawImage(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
            }
            if (yeti->CompteurSpriteDegat==12 || yeti->CompteurSpriteDegat==13 || yeti->CompteurSpriteDegat==14 || yeti->CompteurSpriteDegat==15 )
            {
                yeti->yeti=loadImage("src/graphics/yeti/YetiMort4D.png");
                drawImage(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
            }
            if (yeti->CompteurSpriteDegat==16 || yeti->CompteurSpriteDegat==17 || yeti->CompteurSpriteDegat==18 || yeti->CompteurSpriteDegat==19 )
            {
                yeti->yeti=loadImage("src/graphics/yeti/YetiMort5D.png");
                drawImage(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
            }
        }
        if (yeti->CompteurSpriteDegat==15)
        {
            lvl->MortMonstre+=1;
        }  
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
                joueur->life--;
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
                    joueur->life--;
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
            Mix_VolumeChunk(son->mortchauvesouris, MIX_MAX_VOLUME);
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
                //degat epee
                if(insidechevalierBoss(joueur, boss)==1 && joueur->Numattack==15)
                {           
                    boss->CompteurSpriteDegat=1; 
                    boss->Life--; 
                }
                //degat dague
                if (insideVol(joueur->xdague,joueur->ydague,boss->posmonsx,boss->posmonsy,128,128,30,15)==1)
                {
                    boss->CompteurSpriteDegat=1; 
                    boss->Life--; 
                    //joueur->CoupDague=1;
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
                Mix_VolumeChunk(son->degatboss, MIX_MAX_VOLUME);
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
                joueur->life--;
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
                joueur->life--;
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
                joueur->life--;
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
                joueur->life--;
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
                Mix_VolumeChunk(son->attaqueboss, MIX_MAX_VOLUME);
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
                        joueur->life--;
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

    //mort boss
    if (boss->Life==0)
    {   
        Mix_PauseMusic();
        if (boss->CompteurSpriteDegat>=0 && boss->CompteurSpriteDegat <= 5 )
        {
            boss->Boss=loadImage("src/graphics/Boss/Bossmort1.png");
            drawImage(boss->Boss,boss->posmonsx,boss->posmonsy);
            Mix_VolumeChunk(son->mortboss, MIX_MAX_VOLUME);
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

void GestionMarchands (Joueur *joueur, Input *input, Marchand *marchand,Lvl *lvl)
{   //Verification pointeur pour memoire
    if (marchand->Jerem !=NULL)
    {
        SDL_DestroyTexture(marchand->Jerem);
        marchand->Jerem = NULL;
    }
    if (marchand->Marchand !=NULL)
    {
        SDL_DestroyTexture(marchand->Marchand);
        marchand->Marchand = NULL;
    }
    if (marchand->bulle != NULL)
    {
        SDL_DestroyTexture(marchand->bulle);
        marchand->bulle = NULL;
    }
    if (marchand->Enter !=NULL)
    {
        SDL_DestroyTexture(marchand->Enter);
        marchand->Enter = NULL;
    }
    if (marchand->Bec != NULL)
    {
        SDL_DestroyTexture(marchand->Bec);
        marchand->Bec = NULL;
    }
    if (marchand->Tanguy !=NULL)
    {
        SDL_DestroyTexture(marchand->Tanguy);
        marchand->Tanguy = NULL;
    }
    if (marchand->Bateau != NULL)
    {
        SDL_DestroyTexture(marchand->Bateau);
        marchand->Bateau = NULL;
    }
    
    
    
    if (lvl->Num == 4)
    {
        //Affichage de la table 
        marchand->Table=loadImage("src/graphics/Marchand/Table.png");
        drawImage(marchand->Table,220,55);
    }
    //Compteur des sprites
    marchand->Compteur1 +=1 ;

    //Sprite Jermy
    //affichage jerem dans le marché + dans le donjon bleu une fois
    if (lvl->Num == 4 || (lvl->Num == 5 && lvl->WinDonjon<=2))
    {
        marchand->Enter=loadImage("src/graphics/Marchand/Enter.png");
        drawImage(marchand->Enter,463,300);
        if ((marchand->Compteur1>=0 && marchand->Compteur1<10) || (marchand->Compteur1>=50 && marchand->Compteur1<=60))
        {
            marchand->Jerem=loadImage("src/graphics/Marchand/Jarmy1.png");
            drawImage(marchand->Jerem,450,210);
        }
        if ((marchand->Compteur1>=10 && marchand->Compteur1<20) || (marchand->Compteur1>=40 && marchand->Compteur1<50))
        {
            marchand->Jerem=loadImage("src/graphics/Marchand/Jarmy2.png");
            drawImage(marchand->Jerem,448,210);
        }
        if ((marchand->Compteur1>=20 && marchand->Compteur1<40))
        { 
            marchand->Jerem=loadImage("src/graphics/Marchand/Jarmy3.png");
            drawImage(marchand->Jerem,450,210);
        }
    }
    //Bule donjon bleu avec dague
    if (lvl->Num == 5 && lvl->WinDonjon<=2)
    {
        if (joueur->inposx >= 350 && joueur->inposx <= 539 && joueur->inposy >= 210 && joueur->inposy<270)
        {
            if (input->enter == 1)
            {
                SDL_Delay(200);
                marchand->CompteurMess1 += 1;
            }
            if (marchand->CompteurMess1==1)
            {
                marchand->bulle=loadImage("src/graphics/Marchand/BulleCouteau1.png");
                drawImage(marchand->bulle,210,130);
            }
            if (marchand->CompteurMess1==2)
            {
                marchand->bulle=loadImage("src/graphics/Marchand/BulleCouteau2.png");
                drawImage(marchand->bulle,210,130);
            }
            if (marchand->CompteurMess1==3)
            {
                marchand->bulle=loadImage("src/graphics/Marchand/BulleCouteau3.png");
                drawImage(marchand->bulle,210,95);
                if (joueur->nbDague == 0)
                {
                    joueur->nbDague=1;
                }
                
            }
        }
        //remise a zero du compteur
        else
        {
            marchand->CompteurMess1 = 0;
        }
        if (marchand->CompteurMess1 == 4)
        {
            marchand->CompteurMess1 = 0;
        }
    }
    
    // bulle marché
    if(lvl->Num == 4)
    {
        //Sprite Bulles Jermy en fonction de la position et de entree
        if (joueur->inposx >= 350 && joueur->inposx <= 539 && joueur->inposy >= 210 && joueur->inposy<270)
        {
            if (input->enter == 1)
            {
                SDL_Delay(200);
                marchand->CompteurMess1 += 1;
            }
            if (marchand->CompteurMess1==1)
            {
                marchand->bulle=loadImage("src/graphics/Marchand/BulleJermy1.png");
                drawImage(marchand->bulle,210,130);
            }
            if (marchand->CompteurMess1==2)
            {
                marchand->bulle=loadImage("src/graphics/Marchand/BulleJermy2.png");
                drawImage(marchand->bulle,210,130);
            }
            if (marchand->CompteurMess1==3)
            {
                marchand->bulle=loadImage("src/graphics/Marchand/BulleJermy3.png");
                drawImage(marchand->bulle,210,95);
            }
        }
        //remise a zero du compteur
        else
        {
            marchand->CompteurMess1 = 0;
        }
        if (marchand->CompteurMess1 == 4)
        {
            marchand->CompteurMess1 = 0;
        }


        //Sprite Karine 
        marchand->Enter=loadImage("src/graphics/Marchand/Enter.png");
        drawImage(marchand->Enter,138,120);
        if ((marchand->Compteur1>=0 && marchand->Compteur1<10) || (marchand->Compteur1>=50 && marchand->Compteur1<=60))
        {
            marchand->Marchand=loadImage("src/graphics/Marchand/Karine1.png");
            drawImage(marchand->Marchand,160,50);
        }
        if ((marchand->Compteur1>=10 && marchand->Compteur1<20) || (marchand->Compteur1>=40 && marchand->Compteur1<50))
        {
            marchand->Marchand=loadImage("src/graphics/Marchand/Karine2.png");
            drawImage(marchand->Marchand,160,50);
        }
        if ((marchand->Compteur1>=20 && marchand->Compteur1<40))
        { 
            marchand->Marchand=loadImage("src/graphics/Marchand/Karine3.png");
            drawImage(marchand->Marchand,160,50);
        }
        

        //Sprite Bulle Karine
        if (joueur->inposx >= 170 && joueur->inposx <= 420 && joueur->inposy >= 48 && joueur->inposy<160)
        {
            if (input->enter == 1)
            {
                SDL_Delay(200);
                marchand->CompteurMess2 += 1;
            }
            if (marchand->CompteurMess2==1)
            {
                marchand->bulle=loadImage("src/graphics/Marchand/BulleKarine1.png");
                drawImage(marchand->bulle,10,115);
            }
            if (marchand->CompteurMess2==2)
            {
                marchand->bulle=loadImage("src/graphics/Marchand/BulleKarine2.png");
                drawImage(marchand->bulle,10,115);
            }
            if (marchand->CompteurMess2==3)
            {
                marchand->bulle=loadImage("src/graphics/Marchand/BulleKarine3.png");
                drawImage(marchand->bulle,10,115);

                //Achat de coeur
                if (input->attack == 1)
                {   
                    if (joueur->NbPiece-2>=0 && joueur->life<4)
                    {
                        joueur->life+=1;
                        joueur->NbPiece-=2;
                    }
                }
            }
        }
        else
        {
            marchand->CompteurMess2 = 0;
        }
        
        if (marchand->CompteurMess2 == 4)
        {
            marchand->CompteurMess2 = 0;
        }

        //Sprite bec
        marchand->Enter=loadImage("src/graphics/Marchand/Enter.png");
        drawImage(marchand->Enter, 95,310);
        if ((marchand->Compteur1>=0 && marchand->Compteur1<10) || (marchand->Compteur1>=50 && marchand->Compteur1<=60))
        {
            marchand->Bec=loadImage("src/graphics/Marchand/Bec1.png");
            drawImage(marchand->Bec,60,220); 
        }
        if ((marchand->Compteur1>=10 && marchand->Compteur1<20) || (marchand->Compteur1>=40 && marchand->Compteur1<50))
        {
            marchand->Bec=loadImage("src/graphics/Marchand/Bec2.png");
            drawImage(marchand->Bec,60,220);
        }
        if ((marchand->Compteur1>=20 && marchand->Compteur1<40))
        { 
            marchand->Bec=loadImage("src/graphics/Marchand/Bec3.png");
            drawImage(marchand->Bec,60,220);
        }
        //bulle Bec
        if (joueur->inposx >= 180 && joueur->inposx <= 240 && joueur->inposy >= 185 && joueur->inposy<280)
        {
            if (input->enter == 1)
            {
                joueur->NbPiece+=joueur->AttPiece;
                joueur->AttPiece = 0;
                SDL_Delay(200);
                marchand->CompteurMess3 += 1;
            }
            if (marchand->CompteurMess3==1)
            {
                marchand->bulle=loadImage("src/graphics/Marchand/BulleBec1.png");
                drawImage(marchand->bulle,55,170);
            }
            if (marchand->CompteurMess3==2)
            {
                marchand->bulle=loadImage("src/graphics/Marchand/BulleBec2.png");
                drawImage(marchand->bulle,55,170);
            }
            if (marchand->CompteurMess3==3)
            {
                marchand->bulle=loadImage("src/graphics/Marchand/BulleBec3.png");
                drawImage(marchand->bulle,55,170);
            }
        }
        //remise a zero du compteur
        else
        {
            marchand->CompteurMess3 = 0;
        }
        if (marchand->CompteurMess3 == 4)
        {
            marchand->CompteurMess3 = 0;
        }
    }
    //Bateau
    if (lvl->Num==9)
    {
        if (marchand->Compteur1<10 || marchand->Compteur1>=40)
        {
            marchand->Tanguy=loadImage("src/graphics/Rivière/TurboTangui.png");
            drawImage(marchand->Tanguy,255,198);
        }
        if ((marchand->Compteur1>=10 && marchand->Compteur1 < 20) ||( marchand->Compteur1>=30 && marchand->Compteur1<40))
        {
            marchand->Tanguy=loadImage("src/graphics/Rivière/TurboTangui.png");
            drawImage(marchand->Tanguy,255,195);
        }
        if (marchand->Compteur1>=20 && marchand->Compteur1<30)
        {
            marchand->Tanguy=loadImage("src/graphics/Rivière/TurboTangui.png");
            drawImage(marchand->Tanguy,255,192);
        }
        //Bateau joueur
        if (joueur->Ebateau == 1)
        {
            marchand->Bateau=loadImage("src/graphics/Rivière/Bateau.png");
            drawImage(marchand->Bateau,95,297);
        }
        if (joueur->inposx >= 100 && joueur->inposx <= 220 && joueur->inposy >= 135 && joueur->inposy<200)
        {
            if (input->enter == 1)
            {
                SDL_Delay(200);
                marchand->CompteurMess1 += 1;
            }
             if (marchand->CompteurMess1==1)
            {
                marchand->bulle=loadImage("src/graphics/Rivière/BulleTanguy1.png");
                drawImage(marchand->bulle,255,62);
            }
            if (marchand->CompteurMess1==2)
            {
                marchand->bulle=loadImage("src/graphics/Rivière/BulleTanguy2.png");
                drawImage(marchand->bulle,255,62);
            }
            if (marchand->CompteurMess1==3)
            {
                marchand->bulle=loadImage("src/graphics/Rivière/BulleTanguy3.png");
                drawImage(marchand->bulle,255,62);
                joueur->Ebateau=1;
            }
        }

        //entree joueur dans bateau
        if (joueur->inposx >= 80 && joueur->inposx <= 131 && joueur->inposy >= 205 && joueur->Ebateau == 1)
        {
            joueur->inposx = 95;
            joueur->inposy = 275;
            joueur->Ebateau = 2;
        }
    }

    //reset compteur gene sprite
    if (marchand->Compteur1 >= 60)
    {
        marchand->Compteur1 = 0;
    }
}

void Gestion_Obstacle(Joueur *joueur,Marchand *marchand,Obstacle *Petit_rocher,Obstacle *Gros_rocher, Obstacle *tronc,Obstacle* tanguy, Lvl *lvl)
{   
    if (tronc->Image !=NULL)
    {
        SDL_DestroyTexture(tronc->Image);
        tronc->Image = NULL;
    }
    if (Petit_rocher->Image !=NULL)
    {
        SDL_DestroyTexture(Petit_rocher->Image);
        Petit_rocher->Image = NULL;
    }
    if (Gros_rocher->Image !=NULL)
    {
        SDL_DestroyTexture(Gros_rocher->Image);
        Gros_rocher->Image = NULL;
    }
    
    

    
    if (lvl->Avancement10>0 && lvl->Avancement10 <=2)
    {
        if(Gros_rocher->Etat==0)
        {
            Gros_rocher->Image=loadImage("src/graphics/Rivière/Grosrocher.png");
            drawImage(Gros_rocher->Image,Gros_rocher->x,Gros_rocher->y);
            Gros_rocher->x-=10;
            if (Gros_rocher->x==-140)
            {
                Gros_rocher->Etat=1;
                Gros_rocher->x=670;
                Gros_rocher->y=65;
            } 
        }
        if(Petit_rocher->Etat ==0)
        { 
            Petit_rocher->Image=loadImage("src/graphics/Rivière/Petitrocher.png");
            drawImage(Petit_rocher->Image,Petit_rocher->x,Petit_rocher->y);
            Petit_rocher->x-=10;
            if (Petit_rocher->x <= -110)
            {
                Petit_rocher->Etat=1;
                Petit_rocher->x = 1050;
                Petit_rocher->y = 150;
                Gros_rocher->Etat=0;
            }
        }
    }
    if (lvl->Avancement10>2 && lvl->Avancement10<=4)
    {  
        if(tronc->Etat==0)
        {
            tronc->Image=loadImage("src/graphics/Rivière/tronc.png");
            drawImage(tronc->Image,tronc->x,tronc->y);
            tronc->x-=10;
            if (tronc->x==-150)
            {
                tronc->Etat=1;
                Petit_rocher->Etat=0;
                tronc->x=640;
                tronc->y=75;
            } 
        }

        if(Gros_rocher->Etat ==0)
        { 
            Gros_rocher->Image=loadImage("src/graphics/Rivière/Grosrocher.png");
            drawImage(Gros_rocher->Image,Gros_rocher->x,Gros_rocher->y);
            Gros_rocher->x-=10;
            if (Gros_rocher->x <= -180)
            {
                Gros_rocher->Etat=1;
                tronc->Etat=0;
            }
        }
    }
    
    if (lvl->Avancement10>4 && lvl->Avancement10<=6)
    {
        if(Petit_rocher->Etat==0)
        {
            Petit_rocher->Image=loadImage("src/graphics/Rivière/Petitrocher.png");
            drawImage(Petit_rocher->Image,Petit_rocher->x,Petit_rocher->y);
            Petit_rocher->x-=10;
            if (Petit_rocher->x <= -110)
            {
                Petit_rocher->Etat=1;
                tronc->Etat=0;
                tronc->x=1200;
                tronc->y=75;
            }
        }
        if(tronc->Etat==0)
        {
            tronc->Image=loadImage("src/graphics/Rivière/Tronc.png");
            drawImage(tronc->Image,tronc->x,tronc->y);
            tronc->x-=10;
            if (tronc->x<=-150)
            {
                tronc->Etat=1;
                Gros_rocher->Etat=0;
                Gros_rocher->x=640;
                Gros_rocher->y=160;
            }
        }
    }

    if(lvl->Avancement10>6&&lvl->Avancement10<=8)
    {
        if(Gros_rocher->Etat ==0)
        { 
            Gros_rocher->Image=loadImage("src/graphics/Rivière/Grosrocher.png");
            drawImage(Gros_rocher->Image,Gros_rocher->x,Gros_rocher->y);
            Gros_rocher->x-=10;
            if (Gros_rocher->x <= -180)
            {
                Gros_rocher->Etat=1;
                Petit_rocher->Etat=0;
                Petit_rocher->x=640;
                Petit_rocher->y=250;
                tronc->Etat=0;
            }
        }

        if(tronc->Etat==0)
        {
            tronc->Image=loadImage("src/graphics/Rivière/Tronc.png");
            drawImage(tronc->Image,tronc->x,tronc->y);
            tronc->x-=10;
            if (tronc->x<=-150)
            {
                tronc->Etat=1;
                Gros_rocher->Etat=0;
                Gros_rocher->x=1170;
                Gros_rocher->y=150;
            }
        }
    }

    if (lvl->Avancement10>8 && lvl->Avancement10<=10)
    {
        if (Petit_rocher->Etat==0)
        {
            Petit_rocher->Image=loadImage("src/graphics/Rivière/Petitrocher.png");
            drawImage(Petit_rocher->Image,Petit_rocher->x,Petit_rocher->y);
            Petit_rocher->x-=10;
            if (Petit_rocher->x <= -110)
            {
                Petit_rocher->Etat=1;
                tronc->Etat=0;
                tronc->x = 700;
                tronc->y = 80;
            }
        }

        if(Gros_rocher->Etat ==0)
        { 
            Gros_rocher->Image=loadImage("src/graphics/Rivière/Grosrocher.png");
            drawImage(Gros_rocher->Image,Gros_rocher->x,Gros_rocher->y);
            Gros_rocher->x-=10;
            if (Gros_rocher->x <= -180)
            {
                Gros_rocher->Etat=1;
                Petit_rocher=0;
            }
        }
    }
if (lvl->Avancement10<=11)
{
    if (insideVol(tronc->x,tronc->y, joueur->inposx, joueur->inposy,79,70,150,52)==1)
    {
        if (tronc->coup == 0 && Petit_rocher->coup == 0 && Gros_rocher->coup == 0)
        {
            joueur->life--; 
            tronc->coup = 1;
        }
    }
    if (tronc->coup >=1)
    {
        tronc->coup+=1;
    }
    if (insideVol(Petit_rocher->x,Petit_rocher->y, joueur->inposx, joueur->inposy,79,70,110,80)==1)
    {
        if (tronc->coup == 0 && Petit_rocher->coup == 0 && Gros_rocher->coup == 0)
        {
            joueur->life--; 
            Petit_rocher->coup = 1;
        }   
    }
    if (Petit_rocher->coup >=1)
    {
        Petit_rocher->coup+=1;
    }
    
    if (insideVol(Gros_rocher->x,Gros_rocher->y, joueur->inposx, joueur->inposy,79,70,110,105)==1)
    {
        if (tronc->coup == 0 && Petit_rocher->coup == 0 && Gros_rocher->coup == 0)
        {
            joueur->life--;
            Gros_rocher->coup = 1; 
        }
    }
    if (Gros_rocher->coup >= 1)
    {
        Gros_rocher->coup +=1;
    }
}
    //Gestion tanguy
    if (lvl->Avancement10>=4 &&lvl->Avancement10<=6)
    {
        if(tanguy->x<500 && tanguy->Etat==0)
        { 
            tanguy->Image=loadImage("src/graphics/Rivière/TurboTanguiCourse.png");
            drawImage(tanguy->Image,tanguy->x,tanguy->y);
            tanguy->x+=5;
        }
        else
        {
            tanguy->Etat=1;
            tanguy->Image=loadImage("src/graphics/Rivière/TanguiCoule.png");
            drawImage(tanguy->Image,tanguy->x,tanguy->y);
            tanguy->x-=10;
        }       
    }

    if (joueur->inposx>420 && lvl->Avancement10>12 && joueur->Ebateau==2)
    {
        joueur->Ebateau= 1;
        joueur->inposx = 475;
        joueur->inposy = 180;
        marchand->Bateau=loadImage("src/graphics/Rivière/Bateau.png");
        drawImage(marchand->Bateau,450,300);
    }

    //dessin bateau
    if (joueur->Ebateau==1)
    {
        marchand->Bateau=loadImage("src/graphics/Rivière/Bateau.png");
        drawImage(marchand->Bateau,460,300);
    }   

    if (tronc->coup >= 30 || Gros_rocher->coup >= 30 || Petit_rocher->coup >= 30)
    {
        Gros_rocher->coup = 0;
        Petit_rocher->coup = 0;
        tronc->coup = 0;
    } 

}