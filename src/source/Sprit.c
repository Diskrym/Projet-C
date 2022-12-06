#include "../header/proto.h" 

void Sprit_Chevalier(Joueur *joueur, Input *input, EffetSon *son, Entité *entité, Lvl *lvl)
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
        if (joueur->Direction ==0 && joueur->Eattack==0 && (joueur->Eshield==0 || (joueur->Eshield==1 && joueur->TimingBouclier>45)))
        {
            //se deplace si ne prend pas de dégat sinon sprit degat
            if (Degat_Chevalier(&entité->meduse, &entité->meduse1 , &entité->meduse2, &entité->chauvesouris , &entité->chauvesouris1, &entité->boss, &entité->yeti, &entité->yeti1, &entité->yeti2, &entité->bossyeti,&entité->squelette,&entité->squelette1, &entité->jerem)==1)
            {
                son->sondegat=0;
                if (joueur->NumSprit==0 || joueur->NumSprit ==1 || joueur->NumSprit==4 || joueur->NumSprit ==5)
                {
                    joueur->chevalier=loadImage("src/graphics/Chevalier/neutreD.png");
                    Draw_Image(joueur->chevalier,joueur->inposx,joueur->inposy);
                }
                if (joueur->NumSprit==2 || joueur->NumSprit==3  )
                {
                    joueur->chevalier=loadImage("src/graphics/Chevalier/marche1D.png");
                    Draw_Image(joueur->chevalier,joueur->inposx,joueur->inposy);
                    // if (joueur->NumSprit==2)
                    // {Mix_VolumeChunk(son->depchevalier, MIX_MAX_VOLUME);
                    // Mix_PlayChannel(3, son->depchevalier, 0);}   
                }
                if (joueur->NumSprit >=7 || joueur->NumSprit ==6 )
                {
                    joueur->chevalier=loadImage("src/graphics/Chevalier/marche2D.png");
                    Draw_Image(joueur->chevalier,joueur->inposx,joueur->inposy);
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
        if((joueur->Direction ==0 && (joueur->Eattack==1 || joueur->Eshield==1) && Degat_Chevalier(&entité->meduse, &entité->meduse1 , &entité->meduse2, &entité->chauvesouris , &entité->chauvesouris1, &entité->boss, &entité->yeti, &entité->yeti1, &entité->yeti2, &entité->bossyeti,&entité->squelette,&entité->squelette1,&entité->jerem)==0) || (Degat_Chevalier(&entité->meduse, &entité->meduse1 , &entité->meduse2, &entité->chauvesouris , &entité->chauvesouris1, &entité->boss, &entité->yeti, &entité->yeti1, &entité->yeti2 , &entité->bossyeti,&entité->squelette,&entité->squelette1,&entité->jerem)==0) && joueur->Direction==0)
        {
            joueur->chevalier=loadImage("src/graphics/Chevalier/DégatD.png");
            Draw_Image(joueur->chevalier,joueur->inposx,joueur->inposy);
            son->sondegat++;
            if(son->sondegat==1)
            {
            Mix_VolumeChunk(son->degatchevalier, MIX_MAX_VOLUME);
            Mix_PlayChannel(1, son->degatchevalier, 0);
            }
        }
        
        //cf fonction gauche
        if (joueur->Direction ==1 && joueur->Eattack==0 && (joueur->Eshield==0 || (joueur->Eshield==1 && joueur->TimingBouclier>45)))
        {
            if(Degat_Chevalier(&entité->meduse, &entité->meduse1 , &entité->meduse2, &entité->chauvesouris , &entité->chauvesouris1, &entité->boss, &entité->yeti, &entité->yeti1, &entité->yeti2 , &entité->bossyeti,&entité->squelette,&entité->squelette1,&entité->jerem)==1)
            {
                son->sondegat=0;
                if (joueur->NumSprit==0 || joueur->NumSprit ==1 || joueur->NumSprit==4 || joueur->NumSprit ==5)
                {
                    joueur->chevalier=loadImage("src/graphics/Chevalier/neutreG.png");
                    Draw_Image(joueur->chevalier,joueur->inposx,joueur->inposy);
                }
                if (joueur->NumSprit==2 || joueur->NumSprit==3  )
                {
                    joueur->chevalier=loadImage("src/graphics/Chevalier/marche1G.png");
                    Draw_Image(joueur->chevalier,joueur->inposx,joueur->inposy);
                    // if (joueur->NumSprit==2)
                    // {
                    // Mix_VolumeChunk(son->depchevalier, MIX_MAX_VOLUME);
                    // Mix_PlayChannel(3, son->depchevalier, 0);
                    // }
                }
                if (joueur->NumSprit >=6)
                {
                    joueur->chevalier=loadImage("src/graphics/Chevalier/marche2G.png");
                    Draw_Image(joueur->chevalier,joueur->inposx,joueur->inposy);
                    // if (joueur->NumSprit==7)
                    // {
                    // Mix_VolumeChunk(son->depchevalier, MIX_MAX_VOLUME);
                    // Mix_PlayChannel(3, son->depchevalier, 0);
                    // }
                    joueur->NumSprit =0;
                }   
            }
        }
        if ((joueur->Direction ==1 && (joueur->Eattack==1 || joueur->Eshield==1) && Degat_Chevalier(&entité->meduse, &entité->meduse1 , &entité->meduse2, &entité->chauvesouris , &entité->chauvesouris1, &entité->boss, &entité->yeti, &entité->yeti1, &entité->yeti2 , &entité->bossyeti,&entité->squelette,&entité->squelette1,&entité->jerem)==0) || (Degat_Chevalier(&entité->meduse, &entité->meduse1 , &entité->meduse2, &entité->chauvesouris , &entité->chauvesouris1, &entité->boss, &entité->yeti, &entité->yeti1, &entité->yeti2, &entité->bossyeti,&entité->squelette,&entité->squelette1,&entité->jerem)==0) && joueur->Direction==1 )
        {
            joueur->chevalier=loadImage("src/graphics/Chevalier/DégatG.png");
            Draw_Image(joueur->chevalier,joueur->inposx,joueur->inposy);
            son->sondegat++;
            if(son->sondegat==1)
            {
            Mix_VolumeChunk(son->degatchevalier, MIX_MAX_VOLUME);
            Mix_PlayChannel(1, son->degatchevalier, 0);
            }
        }
        
        //Mouvement attaque si Eattack = 1 et si on ne prend pas de dégat
        if (joueur->Eattack==1 && Degat_Chevalier(&entité->meduse, &entité->meduse1, &entité->meduse2, &entité->chauvesouris, &entité->chauvesouris1,&entité->boss, &entité->yeti, &entité->yeti1, &entité->yeti2, &entité->bossyeti,&entité->squelette,&entité->squelette1,&entité->jerem)==1)
        {
            joueur->Numattack+=1;
            if (joueur->Direction==1)
            {   
                if (joueur->Numattack==0 || joueur->Numattack==1 || joueur->Numattack==2 || joueur->Numattack==3 )
                {
                    joueur->chevalier=loadImage("src/graphics/Chevalier/Epee2G.png");
                    Draw_Image(joueur->chevalier,joueur->inposx,joueur->inposy);
                }
                if (joueur->Numattack==4 || joueur->Numattack==5 || joueur->Numattack==6 || joueur->Numattack==7 || joueur->Numattack==20 || joueur->Numattack==21 || joueur->Numattack==22 || joueur->Numattack==23 )
                {
                    joueur->chevalier=loadImage("src/graphics/Chevalier/Epee3G.png");
                    Draw_Image(joueur->chevalier,joueur->inposx,joueur->inposy);
                }
                if (joueur->Numattack==8 || joueur->Numattack==9 || joueur->Numattack==10 || joueur->Numattack==11|| joueur->Numattack==16 || joueur->Numattack==17 || joueur->Numattack==18 || joueur->Numattack==19)
                {
                    joueur->chevalier=loadImage("src/graphics/Chevalier/Epee4G.png");
                    Draw_Image(joueur->chevalier,joueur->inposx,joueur->inposy);
                }
                if (joueur->Numattack==12 || joueur->Numattack==13 || joueur->Numattack==14 || joueur->Numattack==15 )
                {
                    joueur->chevalier=loadImage("src/graphics/Chevalier/Epee5G.png");
                    Draw_Image(joueur->chevalier,joueur->inposx,joueur->inposy);
                    joueur->attaque=loadImage("src/graphics/Chevalier/attaqueG.png");
                    Draw_Image(joueur->attaque,joueur->inposx-21,joueur->inposy+32);
                    if(joueur->Numattack==13)
                    {
                        //Son
                        Mix_VolumeChunk(son->epee, MIX_MAX_VOLUME/2);
                        Mix_PlayChannel(1, son->epee, 0);//Joue le son 1 sur le canal 1 ; le joue une fois (0 + 1)
                    }
                }
            }
            if (joueur->Direction==0)
            {
                if (joueur->Numattack==0 || joueur->Numattack==1 || joueur->Numattack==2 || joueur->Numattack==3 )
                {
                    joueur->chevalier=loadImage("src/graphics/Chevalier/Epee2D.png");
                    Draw_Image(joueur->chevalier,joueur->inposx,joueur->inposy);
                }
                if (joueur->Numattack==4 || joueur->Numattack==5 || joueur->Numattack==6 || joueur->Numattack==7 || joueur->Numattack==20 || joueur->Numattack==21 || joueur->Numattack==22 || joueur->Numattack==23 )
                {
                    joueur->chevalier=loadImage("src/graphics/Chevalier/Epee3D.png");
                    Draw_Image(joueur->chevalier,joueur->inposx,joueur->inposy);
                }
                if (joueur->Numattack==8 || joueur->Numattack==9 || joueur->Numattack==10 || joueur->Numattack==11|| joueur->Numattack==16 || joueur->Numattack==17 || joueur->Numattack==18 || joueur->Numattack==19)
                {
                    joueur->chevalier=loadImage("src/graphics/Chevalier/Epee4D.png");
                    Draw_Image(joueur->chevalier,joueur->inposx,joueur->inposy);
                }
                if (joueur->Numattack==12 || joueur->Numattack==13 || joueur->Numattack==14 || joueur->Numattack==15 )
                {
                    joueur->chevalier=loadImage("src/graphics/Chevalier/Epee5D.png");
                    Draw_Image(joueur->chevalier,joueur->inposx,joueur->inposy);
                    joueur->attaque=loadImage("src/graphics/Chevalier/attaqueD.png");
                    Draw_Image(joueur->attaque,joueur->inposx+SPRITE_SIZE ,joueur->inposy +32);
                    if(joueur->Numattack==13)
                    {
                        //Son
                        Mix_VolumeChunk(son->epee, MIX_MAX_VOLUME);
                        Mix_PlayChannel(1, son->epee, 0);//Joue le son 1 sur le canal 1 ; le joue une fois (0 + 1)
                    }
                }
            }
        }

        //mouvement defense si etat shield a 1
        if (joueur->Eshield==1)
        {
            //timer shield
            if (joueur->TimingBouclier<=45)
            {
                if (joueur->Direction==0)
                {
                    if (joueur->NumSprit==0 )
                    {
                        joueur->chevalier=loadImage("src/graphics/Chevalier/ChevaliershieldD.png");
                        Draw_Image(joueur->chevalier,joueur->inposx,joueur->inposy);
                        //Mix_VolumeChunk(son->bouclier, MIX_MAX_VOLUME);
                        //Mix_PlayChannel(2, son->bouclier, 0);
                    }
                }
                if (joueur->Direction==1)
                {
                    if (joueur->NumSprit==0)
                    {
                        joueur->chevalier=loadImage("src/graphics/Chevalier/ChevaliershieldG.png");
                        Draw_Image(joueur->chevalier,joueur->inposx,joueur->inposy);
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
        if (joueur->Edague >= 1 && joueur->nbDague>0 && joueur->DirDague==1 && lvl->Num !=4 && lvl->Num !=9)
        {
            if (joueur->xdague>=20 && joueur->xdague<=600 && joueur->ydague>= 20 && joueur->ydague<=384)
            {
                son->sondague++;
                joueur->dague=loadImage("src/graphics/Chevalier/DagueG.png");
                Draw_Image(joueur->dague,joueur->xdague,joueur->ydague);
                joueur->xdague-=10;
                son->sondagueM=0;
                if (son->sondague==1)
                {
                    Mix_VolumeChunk(son->dagueLancer, MIX_MAX_VOLUME/2);
                    Mix_PlayChannel(4, son->dagueLancer, 0);
                }

            }
            else
            {   
                
                joueur->dagueMur=loadImage("src/graphics/Chevalier/DagueMurG.png");
                Draw_Image(joueur->dagueMur,joueur->xdague,joueur->ydague);
                joueur->Edague=2;
                son->sondagueM++;
                if (son->sondagueM==1)
                {
                    Mix_VolumeChunk(son->dague, MIX_MAX_VOLUME/2);
                    Mix_PlayChannel(4, son->dague, 0);
                }
            
                //recup dague Gauchemap
                if (joueur->inposx <= joueur->xdague+20 && (joueur->inposy+SPRITE_SIZE>=joueur->ydague && joueur->inposy<=joueur->ydague))
                {
                    SDL_DestroyTexture(joueur->dagueMur);
                    joueur->dagueMur = NULL;
                    joueur->Edague=0;
                    son->sondague=0;
                    //joueur->CoupDague=0;
                }
            }
        }
        //dague
        if (joueur->Edague >= 1 && joueur->nbDague>0 && joueur->DirDague == 0)
        {
            if (joueur->xdague>=20 && joueur->xdague<=600 && joueur->ydague>= 20 && joueur->ydague<=384)
            { 
                son->sondague++;
                joueur->dague=loadImage("src/graphics/Chevalier/DagueD.png");
                Draw_Image(joueur->dague,joueur->xdague,joueur->ydague);
                joueur->xdague+=10;
                son->sondagueM=0;
                if (son->sondague==1)
                {
                    Mix_VolumeChunk(son->dagueLancer, MIX_MAX_VOLUME/2);
                    Mix_PlayChannel(4, son->dagueLancer, 0);
                }
            }
            else
            {
                joueur->dagueMur=loadImage("src/graphics/Chevalier/DagueMurD.png");
                Draw_Image(joueur->dagueMur,joueur->xdague,joueur->ydague);
                joueur->Edague=2;
                son->sondagueM++;
                if (son->sondagueM==1)
                {
                    Mix_VolumeChunk(son->dague, MIX_MAX_VOLUME/2);
                    Mix_PlayChannel(4, son->dague, 0);
                }
                //recup dague Droite map
                if (joueur->inposx >= joueur->xdague-60 && (joueur->inposy+SPRITE_SIZE>=joueur->ydague && joueur->inposy<=joueur->ydague))
                {
                    SDL_DestroyTexture(joueur->dagueMur);
                    joueur->dagueMur = NULL;
                    joueur->Edague=0;
                    son->sondague=0;
                    //joueur->CoupDague=0;
                }
            }
        }
    }
    else if (Degat_Bateau(&entité->tronc, &entité->Petit_rocher ,&entité->Gros_rocher) == 1)
    {
        joueur->NumSprit+=1;
        if(joueur->NumSprit<10 || joueur->NumSprit>=40)
        {
            joueur->chevalier=loadImage("src/graphics/Chevalier/ChevalierBateau.png");
            Draw_Image(joueur->chevalier,joueur->inposx,joueur->inposy+1);  
        }
        if((joueur->NumSprit>=10 && joueur->NumSprit<20) || (joueur->NumSprit>=30 && joueur->NumSprit<40))
        {
            joueur->chevalier=loadImage("src/graphics/Chevalier/ChevalierBateau.png");
            Draw_Image(joueur->chevalier,joueur->inposx,joueur->inposy);  
        }
        if(joueur->NumSprit>=20 && joueur->NumSprit<30)
        {
            joueur->chevalier=loadImage("src/graphics/Chevalier/ChevalierBateau.png");
            Draw_Image(joueur->chevalier,joueur->inposx,joueur->inposy-1);  
        }
        if (joueur->NumSprit >=39)
        {
            joueur->NumSprit=0;
        }
        
    }
    else
    {
        joueur->chevalier=loadImage("src/graphics/Chevalier/ChevalierBateauDegat.png");
        Draw_Image(joueur->chevalier,joueur->inposx,joueur->inposy);
    }
}

void Sprit_Meduse (Meduse *meduse, Joueur *joueur,Lvl *lvl, EffetSon *son)
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
                    Draw_Image(meduse->meduse,meduse->posmonsx,meduse->posmonsy);
                }
                if (meduse->NumSprit==4 || meduse->NumSprit==5 || meduse->NumSprit==6 || meduse->NumSprit==7 || meduse->NumSprit==29 || meduse->NumSprit==30 || meduse->NumSprit==32 || meduse->NumSprit==31 )
                {
                    meduse->meduse=loadImage("src/graphics/Meduse/Medusemarche1.png");
                    Draw_Image(meduse->meduse,meduse->posmonsx,meduse->posmonsy);
                }
                if (meduse->NumSprit==8 || meduse->NumSprit==9 || meduse->NumSprit==10 || meduse->NumSprit==11|| meduse->NumSprit==24 || meduse->NumSprit==25 || meduse->NumSprit==26 || meduse->NumSprit==27 || meduse->NumSprit==28 )
                {
                    meduse->meduse=loadImage("src/graphics/Meduse/Medusemarche2.png");
                    Draw_Image(meduse->meduse,meduse->posmonsx,meduse->posmonsy);
                }
                if (meduse->NumSprit==12 || meduse->NumSprit==13 || meduse->NumSprit==14 || meduse->NumSprit==19 || meduse->NumSprit==20 || meduse->NumSprit==21 || meduse->NumSprit==22 || meduse->NumSprit==23 )                   
                {
                    meduse->meduse=loadImage("src/graphics/Meduse/Medusemarche3.png");
                    Draw_Image(meduse->meduse,meduse->posmonsx,meduse->posmonsy);
                }
                if (meduse->NumSprit==15 || meduse->NumSprit==16 || meduse->NumSprit==17 || meduse->NumSprit==18 )
                {
                    meduse->meduse=loadImage("src/graphics/Meduse/Medusemarche4.png");
                    Draw_Image(meduse->meduse,meduse->posmonsx,meduse->posmonsy);    
                }
                if (meduse->NumSprit>=33 )
                {
                    meduse->meduse=loadImage("src/graphics/Meduse/Medusemarche1.png");
                    Draw_Image(meduse->meduse,meduse->posmonsx,meduse->posmonsy);
                }
                //degat epee
                if(Inside_Chevalier_Meduse(joueur, meduse)==1 && joueur->Numattack==15)
                {           
                    meduse->CompteurSpriteDegat=1; 
                    meduse->Life--; 
                }
                //degat dague
                if (Inside_Vol(joueur->xdague,joueur->ydague, meduse->posmonsx, meduse->posmonsy,64,64,30,15)==1)
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
                Draw_Image(meduse->meduse,meduse->posmonsx,meduse->posmonsy);
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
                Draw_Image(meduse->meduse,meduse->posmonsx,meduse->posmonsy);
            }
            if (meduse->NumSprit==4 || meduse->NumSprit==5 || meduse->NumSprit==6 || meduse->NumSprit==7 || meduse->NumSprit==29 || meduse->NumSprit==30 || meduse->NumSprit==31 || meduse->NumSprit==32 )
            {
                meduse->meduse=loadImage("src/graphics/Meduse/medusecoup2.png");
                Draw_Image(meduse->meduse,meduse->posmonsx,meduse->posmonsy);
            }
            if (meduse->NumSprit==8 || meduse->NumSprit==9 || meduse->NumSprit==10 || meduse->NumSprit==11|| meduse->NumSprit==24 || meduse->NumSprit==25 || meduse->NumSprit==26 || meduse->NumSprit==27 || meduse->NumSprit==28 )
            {
                meduse->meduse=loadImage("src/graphics/Meduse/medusecoup3.png");
                Draw_Image(meduse->meduse,meduse->posmonsx,meduse->posmonsy);
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
                Draw_Image(meduse->meduse,meduse->posmonsx,meduse->posmonsy);
                meduse->attaque=loadImage("src/graphics/Meduse/AttaqueMeduse.png");
                Draw_Image(meduse->attaque,meduse->posmonsx -23 ,meduse->posmonsy - 23);
                
                // Si joueur dans la range de la meduse durant les éclaires
                if(Inside_Meduse_Chevalier(joueur, meduse)==1 && (meduse->NumSprit==23 || meduse->NumSprit==14))                    
                {
                    if (meduse->coup == 0)
                    {
                        joueur->life--;
                        if (joueur->life !=0)
                        {
                            meduse->coup =1 ;
                        }
                    }
                }
                if (meduse->NumSprit==15 || meduse->NumSprit==16 || meduse->NumSprit==17 || meduse->NumSprit==18 )
                {
                    meduse->meduse=loadImage("src/graphics/Meduse/medusecoup2.png");
                    Draw_Image(meduse->meduse,meduse->posmonsx,meduse->posmonsy);
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
            Draw_Image(meduse->meduse,meduse->posmonsx,meduse->posmonsy);
            if (meduse->CompteurSpriteDegat==1)
            {
                Mix_VolumeChunk(son->mortmeduse, MIX_MAX_VOLUME);
                Mix_PlayChannel(9, son->mortmeduse, 0);
            }
        }
        if (meduse->CompteurSpriteDegat==4 || meduse->CompteurSpriteDegat==5 || meduse->CompteurSpriteDegat==6 || meduse->CompteurSpriteDegat==7 )
        {
            meduse->meduse=loadImage("src/graphics/Meduse/Medusemort2.png");
            Draw_Image(meduse->meduse,meduse->posmonsx,meduse->posmonsy);
        }
        if (meduse->CompteurSpriteDegat==8 || meduse->CompteurSpriteDegat==9 || meduse->CompteurSpriteDegat==10 || meduse->CompteurSpriteDegat==11)
        {
            meduse->meduse=loadImage("src/graphics/Meduse/Medusemort3.png");
            Draw_Image(meduse->meduse,meduse->posmonsx,meduse->posmonsy);
        }
        if (meduse->CompteurSpriteDegat==12 || meduse->CompteurSpriteDegat==13 || meduse->CompteurSpriteDegat==14 || meduse->CompteurSpriteDegat==15 )
        {
            meduse->meduse=loadImage("src/graphics/Meduse/Medusemort4.png");
            Draw_Image(meduse->meduse,meduse->posmonsx,meduse->posmonsy);
        }
        if (meduse->CompteurSpriteDegat==16 || meduse->CompteurSpriteDegat==17 || meduse->CompteurSpriteDegat==18 || meduse->CompteurSpriteDegat==19 )
        {
            meduse->meduse=loadImage("src/graphics/Meduse/Medusemort5.png");
            Draw_Image(meduse->meduse,meduse->posmonsx,meduse->posmonsy);
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

void Sprit_Yeti (Yeti *yeti, Joueur *joueur,Lvl *lvl, EffetSon *son)
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
                        Draw_Image(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
                    }
                    if (yeti->NumSprit==4 || yeti->NumSprit==5 || yeti->NumSprit==6 || yeti->NumSprit==7)
                    {
                        yeti->yeti=loadImage("src/graphics/yeti/YetiMarche1G.png");
                        Draw_Image(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
                    }
                    if (yeti->NumSprit==12 || yeti->NumSprit==13 || yeti->NumSprit==14 || yeti->NumSprit==15)
                    {
                        yeti->yeti=loadImage("src/graphics/yeti/YetiMarche2G.png");
                        Draw_Image(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
                    }
                    if (yeti->NumSprit>=16 )
                    {
                        yeti->yeti=loadImage("src/graphics/yeti/YetiNeutreG.png");
                        Draw_Image(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
                    }
                    if(Inside_Chevalier_Yeti(joueur, yeti)==1 && joueur->Numattack==15)
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
                        Draw_Image(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
                    }
                    if (yeti->NumSprit==4 || yeti->NumSprit==5 || yeti->NumSprit==6 || yeti->NumSprit==7)
                    {
                        yeti->yeti=loadImage("src/graphics/yeti/YetiMarche1D.png");
                        Draw_Image(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
                    }
                    if (yeti->NumSprit==12 || yeti->NumSprit==13 || yeti->NumSprit==14 || yeti->NumSprit==15)
                    {
                        yeti->yeti=loadImage("src/graphics/yeti/YetiMarche2D.png");
                        Draw_Image(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
                    }
                    if (yeti->NumSprit>=16 )
                    {
                        yeti->yeti=loadImage("src/graphics/yeti/YetiNeutreD.png");
                        Draw_Image(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
                    }
                    if(Inside_Chevalier_Yeti(joueur, yeti)==1 && joueur->Numattack==15)
                    {          
                        yeti->CompteurSpriteDegat=1;
                        yeti->Life--;
                    }
                }
                //degat dague
                if (Inside_Vol(joueur->xdague,joueur->ydague, yeti->posmonsx+10, yeti->posmonsy+15,45,60,30,15)==1)
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
                    Draw_Image(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
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

                if (yeti->Direction==0)
                {
                    //si la yeti prend un coup
                    yeti->CompteurSpriteDegat+=1;
                    yeti->yeti=loadImage("src/graphics/yeti/YetiDegatD.png");
                    Draw_Image(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
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
                    Draw_Image(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
                }
                if (yeti->NumSprit>=10 && yeti->NumSprit<20 || yeti->NumSprit>=70 && yeti->NumSprit<80)
                {
                    yeti->yeti=loadImage("src/graphics/yeti/YetiAttaque2G.png");
                    Draw_Image(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
                }
                if (yeti->NumSprit>=20 && yeti->NumSprit<30 || yeti->NumSprit>=60 && yeti->NumSprit<70)
                {   
                    if (yeti->NumSprit==60)
                    {
                    Mix_VolumeChunk(son->attaqueyeti, MIX_MAX_VOLUME);
                    Mix_PlayChannel(16, son->attaqueyeti, 0);
                    }
                    yeti->yeti=loadImage("src/graphics/yeti/YetiAttaque3G.png");
                    Draw_Image(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
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
                    Draw_Image(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
                }
                if (yeti->NumSprit>=40 && yeti->NumSprit<50 )
                {                
                    yeti->yeti=loadImage("src/graphics/yeti/YetiAttaque5G.png");                    
                    Draw_Image(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
                }
                
            }

            if (yeti->Direction==0)
            {             
                if (yeti->NumSprit>=0 && yeti->NumSprit<10 || yeti->NumSprit>=80 )
                {  
                    
                
                    yeti->yeti=loadImage("src/graphics/yeti/YetiAttaque1D.png");
                    Draw_Image(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
                }
                if (yeti->NumSprit>=10 && yeti->NumSprit<20 || yeti->NumSprit>=70 && yeti->NumSprit<80)
                {
                    yeti->yeti=loadImage("src/graphics/yeti/YetiAttaque2D.png");
                    Draw_Image(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
                }
                if (yeti->NumSprit>=20 && yeti->NumSprit<30 || yeti->NumSprit>=60 && yeti->NumSprit<70)
                {   
                    if (yeti->NumSprit==60)
                    {
                    Mix_VolumeChunk(son->attaqueyeti, MIX_MAX_VOLUME);
                    Mix_PlayChannel(16, son->attaqueyeti, 0);
                    }
                    yeti->yeti=loadImage("src/graphics/yeti/YetiAttaque3D.png");
                    Draw_Image(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
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
                    Draw_Image(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
                }
                if (yeti->NumSprit>=40 && yeti->NumSprit<50 )
                {                
                    yeti->yeti=loadImage("src/graphics/yeti/YetiAttaque5D.png");                    
                    Draw_Image(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
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
                Draw_Image(yeti->boule,yeti->xboule,yeti->yboule);
                
                if (Inside_Vol(yeti->xboule,yeti->yboule,joueur->inposx,joueur->inposy,64,64,21,17)==1 && yeti->coup == 0)
                {
                    joueur->life--;
                    if (joueur->life != 0)
                    {
                        yeti->coup=1;
                    }
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
                    Draw_Image(yeti->boule,yeti->xboule,yeti->yboule);
                }
                if (yeti->CompteurBoule>=5 && yeti->CompteurBoule<10)
                {  
                    yeti->boule=loadImage("src/graphics/yeti/BouleDeMur2G.png");
                    Draw_Image(yeti->boule,yeti->xboule,yeti->yboule);
                }
                if (yeti->CompteurBoule>=15 && yeti->CompteurBoule<20)
                {  
                    yeti->boule=loadImage("src/graphics/yeti/BouleDeMur3G.png");
                    Draw_Image(yeti->boule,yeti->xboule,yeti->yboule);
                }
                if (yeti->CompteurBoule>=20 && yeti->CompteurBoule<25)
                {  
                    yeti->boule=loadImage("src/graphics/yeti/BouleDeMur4G.png");
                    Draw_Image(yeti->boule,yeti->xboule,yeti->yboule);
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
                Draw_Image(yeti->boule,yeti->xboule,yeti->yboule);
                if (Inside_Vol(yeti->xboule,yeti->yboule,joueur->inposx,joueur->inposy,64,64,21,17)==1 && yeti->coup == 0)
                {
                    joueur->life--;
                    if (joueur->life != 0)
                    {
                        yeti->coup=1;
                    }
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
                    Draw_Image(yeti->boule,yeti->xboule,yeti->yboule);
                }
                if (yeti->CompteurBoule>=5 && yeti->CompteurBoule<10)
                {  
                    yeti->boule=loadImage("src/graphics/yeti/BouleDeMur2D.png");
                    Draw_Image(yeti->boule,yeti->xboule,yeti->yboule);
                }
                if (yeti->CompteurBoule>=15 && yeti->CompteurBoule<20)
                {  
                    yeti->boule=loadImage("src/graphics/yeti/BouleDeMur3D.png");
                    Draw_Image(yeti->boule,yeti->xboule,yeti->yboule);
                }
                if (yeti->CompteurBoule>=20 && yeti->CompteurBoule<25)
                {  
                    yeti->boule=loadImage("src/graphics/yeti/BouleDeMur4D.png");
                    Draw_Image(yeti->boule,yeti->xboule,yeti->yboule);
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
                Draw_Image(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
                if (yeti->CompteurSpriteDegat==1)
                {
                    Mix_VolumeChunk(son->mortyeti, MIX_MAX_VOLUME);
                    Mix_PlayChannel(9, son->mortyeti, 0);
                }
            }
            if (yeti->CompteurSpriteDegat==4 || yeti->CompteurSpriteDegat==5 || yeti->CompteurSpriteDegat==6 || yeti->CompteurSpriteDegat==7 )
            {
                yeti->yeti=loadImage("src/graphics/yeti/YetiMort2G.png");
                Draw_Image(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
            }
            if (yeti->CompteurSpriteDegat==8 || yeti->CompteurSpriteDegat==9 || yeti->CompteurSpriteDegat==10 || yeti->CompteurSpriteDegat==11)
            {
                yeti->yeti=loadImage("src/graphics/yeti/YetiMort3G.png");
                Draw_Image(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
            }
            if (yeti->CompteurSpriteDegat==12 || yeti->CompteurSpriteDegat==13 || yeti->CompteurSpriteDegat==14 || yeti->CompteurSpriteDegat==15 )
            {
                yeti->yeti=loadImage("src/graphics/yeti/YetiMort4G.png");
                Draw_Image(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
            }
            if (yeti->CompteurSpriteDegat==16 || yeti->CompteurSpriteDegat==17 || yeti->CompteurSpriteDegat==18 || yeti->CompteurSpriteDegat==19 )
            {
                yeti->yeti=loadImage("src/graphics/yeti/YetiMort5G.png");
                Draw_Image(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
            }
        }

        if (yeti->Direction==0)
        {  
            if (yeti->CompteurSpriteDegat==0 || yeti->CompteurSpriteDegat==1 || yeti->CompteurSpriteDegat==2 || yeti->CompteurSpriteDegat==3 )
            {
                yeti->yeti=loadImage("src/graphics/yeti/YetiMort1D.png");
                Draw_Image(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
                if (yeti->CompteurSpriteDegat==1)
                {
                Mix_VolumeChunk(son->mortyeti, MIX_MAX_VOLUME);
                Mix_PlayChannel(9, son->mortyeti, 0);
                }
            }
            if (yeti->CompteurSpriteDegat==4 || yeti->CompteurSpriteDegat==5 || yeti->CompteurSpriteDegat==6 || yeti->CompteurSpriteDegat==7 )
            {
                yeti->yeti=loadImage("src/graphics/yeti/YetiMort2D.png");
                Draw_Image(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
            }
            if (yeti->CompteurSpriteDegat==8 || yeti->CompteurSpriteDegat==9 || yeti->CompteurSpriteDegat==10 || yeti->CompteurSpriteDegat==11)
            {
                yeti->yeti=loadImage("src/graphics/yeti/YetiMort3D.png");
                Draw_Image(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
            }
            if (yeti->CompteurSpriteDegat==12 || yeti->CompteurSpriteDegat==13 || yeti->CompteurSpriteDegat==14 || yeti->CompteurSpriteDegat==15 )
            {
                yeti->yeti=loadImage("src/graphics/yeti/YetiMort4D.png");
                Draw_Image(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
            }
            if (yeti->CompteurSpriteDegat==16 || yeti->CompteurSpriteDegat==17 || yeti->CompteurSpriteDegat==18 || yeti->CompteurSpriteDegat==19 )
            {
                yeti->yeti=loadImage("src/graphics/yeti/YetiMort5D.png");
                Draw_Image(yeti->yeti,yeti->posmonsx,yeti->posmonsy);
            }
        }
        if (yeti->CompteurSpriteDegat==15)
        {
            lvl->MortMonstre+=1;
        }  
    }
   
}

void Sprit_Boss_Yeti (BossYeti *bossyeti, Joueur *joueur,Lvl *lvl, EffetSon *son)
{  
    //reset pointeur bossyeti
    if (bossyeti->bossyeti!=NULL)
    {
        SDL_DestroyTexture(bossyeti->bossyeti);
        bossyeti->bossyeti=NULL;
    }
    if (bossyeti->fissure!=NULL)
    {
        SDL_DestroyTexture(bossyeti->fissure);
        bossyeti->fissure=NULL;
    }
    if (bossyeti->crane!=NULL)
    {
        SDL_DestroyTexture(bossyeti->crane);
        bossyeti->crane=NULL;
    }
    if (bossyeti->cachemisere!=NULL)
    {
        SDL_DestroyTexture(bossyeti->cachemisere);
        bossyeti->cachemisere=NULL;
    }


      //sprit fissure
    if (bossyeti->tempsfissure==1)
    {
        bossyeti->spritfissure+=1;
        if (bossyeti->directionfissure==1)
        {
            if (bossyeti->spritfissure>=0 && bossyeti->spritfissure<10)
                {
                    bossyeti->fissure=loadImage("src/graphics/BossYeti/Fissure1G.png");                    
                    Draw_Image(bossyeti->fissure,bossyeti->xfissure,bossyeti->yfissure);
                    bossyeti->cachemisere=loadImage("src/graphics/BossYeti/cachemisere.png");                    
                    Draw_Image(bossyeti->cachemisere,0,0);
                    if (Inside_fissure (joueur, bossyeti, 5)==1)
                    {
                        if (bossyeti->coupfissure == 0)
                    {
                        joueur->life--;
                        if (joueur->life != 0)
                        {
                            bossyeti->coupfissure =1 ;
                        }
                        
                        bossyeti->ticfissure=bossyeti->spritfissure;

                    }

                    }
                    else 
                    {
                        bossyeti->coupfissure =0;
                    }

                }
                if (bossyeti->spritfissure>=10 && bossyeti->spritfissure<20)
                {
                    bossyeti->fissure=loadImage("src/graphics/BossYeti/Fissure2G.png");                    
                    Draw_Image(bossyeti->fissure,bossyeti->xfissure,bossyeti->yfissure);
                    bossyeti->cachemisere=loadImage("src/graphics/BossYeti/cachemisere.png");                    
                    Draw_Image(bossyeti->cachemisere,0,0);
                    if (bossyeti->spritfissure==15)
                    {
                    Mix_VolumeChunk(son->fissure, MIX_MAX_VOLUME);
                    Mix_PlayChannel(10, son->fissure, 0); 
                    }
                    if (Inside_fissure (joueur, bossyeti, 4)==1)
                    {
                        if (bossyeti->coupfissure == 0)
                    {
                        joueur->life--;
                        if (joueur->life != 0)
                        {
                            bossyeti->coupfissure =1 ;
                        }
                        bossyeti->ticfissure=bossyeti->spritfissure;

                    }

                    }
                     else 
                    {
                        bossyeti->coupfissure =0;
                    }
                }
                if (bossyeti->spritfissure>=20 && bossyeti->spritfissure<30)
                {
                    bossyeti->fissure=loadImage("src/graphics/BossYeti/Fissure3G.png");                    
                    Draw_Image(bossyeti->fissure,bossyeti->xfissure,bossyeti->yfissure);
                    bossyeti->cachemisere=loadImage("src/graphics/BossYeti/cachemisere.png");                    
                    Draw_Image(bossyeti->cachemisere,0,0);
                    if (Inside_fissure (joueur, bossyeti, 3)==1)
                    {
                        if (bossyeti->coupfissure == 0)
                    {
                        joueur->life--;
                        if (joueur->life != 0)
                        {
                            bossyeti->coupfissure =1 ;
                        }
                        bossyeti->ticfissure=bossyeti->spritfissure;
                    }

                    }
                     else 
                    {
                        bossyeti->coupfissure =0;
                    }
                }
                if (bossyeti->spritfissure>=30 && bossyeti->spritfissure<40)
                {
                    bossyeti->fissure=loadImage("src/graphics/BossYeti/Fissure4G.png");                    
                    Draw_Image(bossyeti->fissure,bossyeti->xfissure,bossyeti->yfissure);
                    bossyeti->cachemisere=loadImage("src/graphics/BossYeti/cachemisere.png");                    
                    Draw_Image(bossyeti->cachemisere,0,0);
                    if (Inside_fissure (joueur, bossyeti, 2)==1)
                    {
                        if (bossyeti->coupfissure == 0)
                    {
                        joueur->life--;
                        if (joueur->life != 0)
                        {
                            bossyeti->coupfissure =1 ;
                        }
                        bossyeti->ticfissure=bossyeti->spritfissure;

                    }

                    }
                     else 
                    {
                        bossyeti->coupfissure =0;
                    }
                }
                if (bossyeti->spritfissure>=40)
                {
                    bossyeti->fissure=loadImage("src/graphics/BossYeti/Fissure5G.png");                    
                    Draw_Image(bossyeti->fissure,bossyeti->xfissure,bossyeti->yfissure);
                    bossyeti->cachemisere=loadImage("src/graphics/BossYeti/cachemisere.png");                    
                    Draw_Image(bossyeti->cachemisere,0,0);
                    if (Inside_fissure (joueur, bossyeti, 1)==1)
                    {
                        if (bossyeti->coupfissure == 0)
                    {
                        joueur->life--;
                        if (joueur->life != 0)
                        {
                            bossyeti->coupfissure =1 ;
                        }
                        bossyeti->ticfissure=bossyeti->spritfissure;

                    }

                    }
                     else 
                    {
                        bossyeti->coupfissure =0;
                    }
                }
        }
        if (bossyeti->directionfissure==0)
        {
            if (bossyeti->spritfissure>=0 && bossyeti->spritfissure<10)
                {
                    bossyeti->fissure=loadImage("src/graphics/BossYeti/Fissure1D.png");                    
                    Draw_Image(bossyeti->fissure,bossyeti->xfissure,bossyeti->yfissure);
                    bossyeti->cachemisere=loadImage("src/graphics/BossYeti/cachemisere.png");                    
                    Draw_Image(bossyeti->cachemisere,0,0);
                    if (Inside_fissure (joueur, bossyeti, 5)==1)
                    {
                        if (bossyeti->coupfissure == 0)
                    {
                        joueur->life--;
                        if (joueur->life != 0)
                        {
                            bossyeti->coupfissure =1 ;
                        }
                        bossyeti->ticfissure=bossyeti->spritfissure;

                    }

                    }
                     else 
                    {
                        bossyeti->coupfissure =0;
                    }
                                       

                }
                if (bossyeti->spritfissure>=10 && bossyeti->spritfissure<20)
                {
                    bossyeti->fissure=loadImage("src/graphics/BossYeti/Fissure2D.png");                    
                    Draw_Image(bossyeti->fissure,bossyeti->xfissure,bossyeti->yfissure);
                    bossyeti->cachemisere=loadImage("src/graphics/BossYeti/cachemisere.png");                    
                    Draw_Image(bossyeti->cachemisere,0,0);
                    if (bossyeti->spritfissure==15)
                    {
                    Mix_VolumeChunk(son->fissure, MIX_MAX_VOLUME);
                    Mix_PlayChannel(10, son->fissure, 0); 
                    }
                    if (Inside_fissure (joueur, bossyeti, 4)==1)
                    {
                        if (bossyeti->coupfissure == 0)
                    {
                        joueur->life--;
                        if (joueur->life != 0)
                        {
                            bossyeti->coupfissure =1 ;
                        }
                        
                        
                        bossyeti->ticfissure=bossyeti->spritfissure;
                    }

                    }
                     else 
                    {
                        bossyeti->coupfissure =0;
                    }
                                        

                }
                if (bossyeti->spritfissure>=20 && bossyeti->spritfissure<30)
                {
                    bossyeti->fissure=loadImage("src/graphics/BossYeti/Fissure3D.png");                    
                    Draw_Image(bossyeti->fissure,bossyeti->xfissure,bossyeti->yfissure);
                    bossyeti->cachemisere=loadImage("src/graphics/BossYeti/cachemisere.png");                    
                    Draw_Image(bossyeti->cachemisere,0,0);
                    if (Inside_fissure (joueur, bossyeti, 3)==1)
                    {
                        if (bossyeti->coupfissure == 0)
                    {
                        joueur->life--;
                        if (joueur->life != 0)
                        {
                        bossyeti->coupfissure =1 ;
                        }
                        
                        bossyeti->ticfissure=bossyeti->spritfissure;

                    }

                    }
                     else 
                    {
                        bossyeti->coupfissure =0;
                    }
                                        

                }
                if (bossyeti->spritfissure>=30 && bossyeti->spritfissure<40)
                {
                    bossyeti->fissure=loadImage("src/graphics/BossYeti/Fissure4D.png");                    
                    Draw_Image(bossyeti->fissure,bossyeti->xfissure,bossyeti->yfissure);
                    bossyeti->cachemisere=loadImage("src/graphics/BossYeti/cachemisere.png");                    
                    Draw_Image(bossyeti->cachemisere,0,0);
                    if (Inside_fissure (joueur, bossyeti, 2)==1)
                    {
                        if (bossyeti->coupfissure == 0)
                    {
                        joueur->life--;
                        if (joueur->life != 0)
                        {
                            bossyeti->coupfissure =1 ;
                        }
                        
                        bossyeti->ticfissure=bossyeti->spritfissure;

                    }

                    }
                     else 
                    {
                        bossyeti->coupfissure =0;
                    }

                }
                if (bossyeti->spritfissure>=40)
                {
                    bossyeti->fissure=loadImage("src/graphics/BossYeti/Fissure5D.png");                    
                    Draw_Image(bossyeti->fissure,bossyeti->xfissure,bossyeti->yfissure);
                    bossyeti->cachemisere=loadImage("src/graphics/BossYeti/cachemisere.png");                    
                    Draw_Image(bossyeti->cachemisere,0,0);
                    if (Inside_fissure (joueur, bossyeti, 1)==1)
                    {
                        if (bossyeti->coupfissure == 0)
                    {
                        joueur->life--;
                        if (joueur->life != 0)
                        {
                        bossyeti->coupfissure =1 ;
                        }
                        
                        bossyeti->ticfissure=bossyeti->spritfissure;

                    }

                    }
                     else 
                    {
                        bossyeti->coupfissure =0;
                    }      
               }
        
        
        if (bossyeti->spritfissure==bossyeti->ticfissure+40)
        {
            bossyeti->coupfissure=0;
        }
        
        }


    }
 
    
    //Mouvement  bossyeti quand en vie
    if (bossyeti->Life >=1)
    {
        //compteur < 100 pour déplacement normal
        if (bossyeti->compteur < 100)
        {  
            //si la bossyeti n'a pas prit de coup
            if (bossyeti->CompteurSpriteDegat==0)
            {
                if (bossyeti->Direction==1)
                {
                    if (bossyeti->NumSprit==0 || bossyeti->NumSprit==1 || bossyeti->NumSprit==2 || bossyeti->NumSprit==3 || bossyeti->NumSprit==8 || bossyeti->NumSprit==9 || bossyeti->NumSprit==10 || bossyeti->NumSprit==11)
                    {
                        bossyeti->bossyeti=loadImage("src/graphics/BossYeti/BossYetiNeutreG.png");
                        Draw_Image(bossyeti->bossyeti,bossyeti->posmonsx,bossyeti->posmonsy);
                    }
                    if (bossyeti->NumSprit==4 || bossyeti->NumSprit==5 || bossyeti->NumSprit==6 || bossyeti->NumSprit==7)
                    {
                        bossyeti->bossyeti=loadImage("src/graphics/BossYeti/BossYetiMarche1G.png");
                        Draw_Image(bossyeti->bossyeti,bossyeti->posmonsx,bossyeti->posmonsy);
                    }
                    if (bossyeti->NumSprit==12 || bossyeti->NumSprit==13 || bossyeti->NumSprit==14 || bossyeti->NumSprit==15)
                    {
                        bossyeti->bossyeti=loadImage("src/graphics/BossYeti/BossYetiMarche2G.png");
                        Draw_Image(bossyeti->bossyeti,bossyeti->posmonsx,bossyeti->posmonsy);
                    }
                    if (bossyeti->NumSprit>=16 )
                    {
                        bossyeti->bossyeti=loadImage("src/graphics/BossYeti/BossYetiNeutreG.png");
                        Draw_Image(bossyeti->bossyeti,bossyeti->posmonsx,bossyeti->posmonsy);
                    }
                    if(Inside_Chevalier_Boss_Yeti(joueur, bossyeti)==1 && joueur->Numattack==15)
                    {          
                        bossyeti->CompteurSpriteDegat=1;
                        bossyeti->Life--;
                    }
                }
 
                 if (bossyeti->Direction==0)
                {
                    if (bossyeti->NumSprit==0 || bossyeti->NumSprit==1 || bossyeti->NumSprit==2 || bossyeti->NumSprit==3 || bossyeti->NumSprit==8 || bossyeti->NumSprit==9 || bossyeti->NumSprit==10 || bossyeti->NumSprit==11)
                    {
                        bossyeti->bossyeti=loadImage("src/graphics/BossYeti/BossYetiNeutreD.png");
                        Draw_Image(bossyeti->bossyeti,bossyeti->posmonsx,bossyeti->posmonsy);
                    }
                    if (bossyeti->NumSprit==4 || bossyeti->NumSprit==5 || bossyeti->NumSprit==6 || bossyeti->NumSprit==7)
                    {
                        bossyeti->bossyeti=loadImage("src/graphics/BossYeti/BossYetiMarche1D.png");
                        Draw_Image(bossyeti->bossyeti,bossyeti->posmonsx,bossyeti->posmonsy);
                    }
                    if (bossyeti->NumSprit==12 || bossyeti->NumSprit==13 || bossyeti->NumSprit==14 || bossyeti->NumSprit==15)
                    {
                        bossyeti->bossyeti=loadImage("src/graphics/BossYeti/BossYetiMarche2D.png");
                        Draw_Image(bossyeti->bossyeti,bossyeti->posmonsx,bossyeti->posmonsy);
                    }
                    if (bossyeti->NumSprit>=16 )
                    {
                        bossyeti->bossyeti=loadImage("src/graphics/BossYeti/BossYetiNeutreD.png");
                        Draw_Image(bossyeti->bossyeti,bossyeti->posmonsx,bossyeti->posmonsy);
                    }
                    if(Inside_Chevalier_Boss_Yeti(joueur, bossyeti)==1 && joueur->Numattack==15)
                    {          
                        bossyeti->CompteurSpriteDegat=1;
                        bossyeti->Life--;
                    }
                }
                //degat dague
                if (Inside_Vol(joueur->xdague,joueur->ydague, bossyeti->posmonsx+10, bossyeti->posmonsy+15,45,60,30,15)==1)
                {
                    bossyeti->CompteurSpriteDegat=1;
                    bossyeti->Life--;
                    //joueur->CoupDague=1;
                }
            }
 
            else
            {  
                if (bossyeti->Direction==1)
                {
                    //si la bossyeti prend un coup
                    bossyeti->CompteurSpriteDegat+=1;
                    bossyeti->bossyeti=loadImage("src/graphics/BossYeti/BossYetiDegatG.png");
                    Draw_Image(bossyeti->bossyeti,bossyeti->posmonsx,bossyeti->posmonsy);
                    if (bossyeti->CompteurSpriteDegat==2)
                    {
                    Mix_VolumeChunk(son->degatbossyeti, MIX_MAX_VOLUME);
                    Mix_PlayChannel(4, son->degatbossyeti, 0);
                    }
                   
                    //compteur duree affichage degat bossyeti
                    if (bossyeti->CompteurSpriteDegat > 15)
                    {
                        bossyeti->CompteurSpriteDegat=0;
                    }
                }
 
                if (bossyeti->Direction==0)
                {
                    //si la bossyeti prend un coup
                    bossyeti->CompteurSpriteDegat+=1;
                    bossyeti->bossyeti=loadImage("src/graphics/BossYeti/BossYetiDegatD.png");
                    Draw_Image(bossyeti->bossyeti,bossyeti->posmonsx,bossyeti->posmonsy);
                    if (bossyeti->CompteurSpriteDegat==2)
                    {
                    Mix_VolumeChunk(son->degatbossyeti, MIX_MAX_VOLUME);
                     Mix_PlayChannel(14, son->degatbossyeti, 0);
                    }          
                    //compteur duree affichage degat bossyeti
                    if (bossyeti->CompteurSpriteDegat > 15)
                    {
                        bossyeti->CompteurSpriteDegat=0;
                    }
                }
            }
             if (bossyeti->NumSprit>=16)
            {
                 bossyeti->NumSprit=0;
            }
        }
        //attaquebossyeti bossyeti quand compteur > 100
        if  (bossyeti->compteur>=100)
        {   
        if (bossyeti->compteurfissure==0 )
            {
            if (bossyeti->Direction==1)
            {            
                if (bossyeti->NumSprit>=0 && bossyeti->NumSprit<10 || bossyeti->NumSprit>=80  )
                {  
                    bossyeti->bossyeti=loadImage("src/graphics/BossYeti/BossYetiAttaque1G.png");
                    Draw_Image(bossyeti->bossyeti,bossyeti->posmonsx,bossyeti->posmonsy);
                }
                if (bossyeti->NumSprit>=10 && bossyeti->NumSprit<20 || bossyeti->NumSprit>=70 && bossyeti->NumSprit<80)
                {
                    bossyeti->bossyeti=loadImage("src/graphics/BossYeti/BossYetiAttaque2G.png");
                    Draw_Image(bossyeti->bossyeti,bossyeti->posmonsx,bossyeti->posmonsy);
                }
                if (bossyeti->NumSprit>=20 && bossyeti->NumSprit<30 || bossyeti->NumSprit>=60 && bossyeti->NumSprit<70)
                {  
                    if (bossyeti->NumSprit==60)
                    {
                    Mix_VolumeChunk(son->attaquebossyeti, MIX_MAX_VOLUME);
                    Mix_PlayChannel(16, son->attaquebossyeti, 0);
                    }
                    bossyeti->bossyeti=loadImage("src/graphics/BossYeti/BossYetiAttaque3G.png");
                    Draw_Image(bossyeti->bossyeti,bossyeti->posmonsx,bossyeti->posmonsy);
                    if (bossyeti->NumSprit == 65)
                    {
                        bossyeti->Eattaque = 1;
                        bossyeti->directioncrane=bossyeti->Direction;
                        bossyeti->xcrane=bossyeti->posmonsx+33;
                        bossyeti->ycrane=bossyeti->posmonsy+7;
                    }
                   
                }
                if (bossyeti->NumSprit>=30 && bossyeti->NumSprit<40 || bossyeti->NumSprit>=50 && bossyeti->NumSprit<60)
                {                
                    bossyeti->bossyeti=loadImage("src/graphics/BossYeti/BossYetiAttaque4G.png");                    
                    Draw_Image(bossyeti->bossyeti,bossyeti->posmonsx,bossyeti->posmonsy);
                }
                if (bossyeti->NumSprit>=40 && bossyeti->NumSprit<50 )
                {                
                    bossyeti->bossyeti=loadImage("src/graphics/BossYeti/BossYetiAttaque5G.png");                    
                    Draw_Image(bossyeti->bossyeti,bossyeti->posmonsx,bossyeti->posmonsy);
                    

                }
               
            }
 
            if (bossyeti->Direction==0)
            {            
                if (bossyeti->NumSprit>=0 && bossyeti->NumSprit<10 || bossyeti->NumSprit>=80 )
                {  
                   
               
                    bossyeti->bossyeti=loadImage("src/graphics/BossYeti/BossYetiAttaque1D.png");
                    Draw_Image(bossyeti->bossyeti,bossyeti->posmonsx,bossyeti->posmonsy);
                }
                if (bossyeti->NumSprit>=10 && bossyeti->NumSprit<20 || bossyeti->NumSprit>=70 && bossyeti->NumSprit<80)
                {
                    bossyeti->bossyeti=loadImage("src/graphics/BossYeti/BossYetiAttaque2D.png");
                    Draw_Image(bossyeti->bossyeti,bossyeti->posmonsx,bossyeti->posmonsy);
                }
                if (bossyeti->NumSprit>=20 && bossyeti->NumSprit<30 || bossyeti->NumSprit>=60 && bossyeti->NumSprit<70)
                {  
                    if (bossyeti->NumSprit==60)
                    {
                    Mix_VolumeChunk(son->attaquebossyeti, MIX_MAX_VOLUME);
                    Mix_PlayChannel(16, son->attaquebossyeti, 0);
                    }
                    bossyeti->bossyeti=loadImage("src/graphics/BossYeti/BossYetiAttaque3D.png");
                    Draw_Image(bossyeti->bossyeti,bossyeti->posmonsx,bossyeti->posmonsy);
                    if (bossyeti->NumSprit == 65)
                    {
                        bossyeti->Eattaque = 1;
                        bossyeti->directioncrane=bossyeti->Direction;
                        bossyeti->xcrane=bossyeti->posmonsx+33;
                        bossyeti->ycrane=bossyeti->posmonsy+9;
                    }
                }
                if (bossyeti->NumSprit>=30 && bossyeti->NumSprit<40 || bossyeti->NumSprit>=50 && bossyeti->NumSprit<60)
                {                
                    bossyeti->bossyeti=loadImage("src/graphics/BossYeti/BossYetiAttaque4D.png");                    
                    Draw_Image(bossyeti->bossyeti,bossyeti->posmonsx,bossyeti->posmonsy);
                }
                if (bossyeti->NumSprit>=40 && bossyeti->NumSprit<50 )
                {                
                    bossyeti->bossyeti=loadImage("src/graphics/BossYeti/BossYetiAttaque5D.png");                    
                    Draw_Image(bossyeti->bossyeti,bossyeti->posmonsx,bossyeti->posmonsy);
                    
                }
                //reset compteur bossyeti
            }
            if (bossyeti->NumSprit>90)
            {
                bossyeti->NumSprit=0;
                bossyeti->compteurfissure+=1;
            }
        }
        if (bossyeti->compteurfissure==1)
        {
            if (bossyeti->Direction==1)
            {            
                if (bossyeti->NumSprit>=0 && bossyeti->NumSprit<10 || bossyeti->NumSprit>=80 && bossyeti->NumSprit<90 )
                {  
                    bossyeti->bossyeti=loadImage("src/graphics/BossYeti/BossYetiFissure2G.png");
                    Draw_Image(bossyeti->bossyeti,bossyeti->posmonsx,bossyeti->posmonsy);
                    if (bossyeti->NumSprit==9 && bossyeti->tempsfissure!=0)
                    {
                    bossyeti->tempsfissure=0;;
                    }
                }
                if (bossyeti->NumSprit>=10 && bossyeti->NumSprit<20 || bossyeti->NumSprit>=70 && bossyeti->NumSprit<80)
                {
                    bossyeti->bossyeti=loadImage("src/graphics/BossYeti/BossYetiFissure3G.png");
                    Draw_Image(bossyeti->bossyeti,bossyeti->posmonsx,bossyeti->posmonsy);
                }
                if (bossyeti->NumSprit>=20 && bossyeti->NumSprit<30 || bossyeti->NumSprit>=60 && bossyeti->NumSprit<70)
                {  
                 
                    bossyeti->bossyeti=loadImage("src/graphics/BossYeti/BossYetiFissure4G.png");
                    Draw_Image(bossyeti->bossyeti,bossyeti->posmonsx,bossyeti->posmonsy);
                    if (bossyeti->NumSprit==68)
                    {
                    Mix_VolumeChunk(son->solbossyeti, MIX_MAX_VOLUME);
                    Mix_PlayChannel(16, son->solbossyeti, 0);
                    }
                    
                }
                if (bossyeti->NumSprit>=30 && bossyeti->NumSprit<40 || bossyeti->NumSprit>=50 && bossyeti->NumSprit<60)
                {                
                    bossyeti->bossyeti=loadImage("src/graphics/BossYeti/BossYetiFissure5G.png");                    
                    Draw_Image(bossyeti->bossyeti,bossyeti->posmonsx,bossyeti->posmonsy);
                }
                if (bossyeti->NumSprit>=40 && bossyeti->NumSprit<50 )
                {                
                    bossyeti->bossyeti=loadImage("src/graphics/BossYeti/BossYetiFissure6G.png");                    
                    Draw_Image(bossyeti->bossyeti,bossyeti->posmonsx,bossyeti->posmonsy);
                    

                }
                if (bossyeti->NumSprit>=90  )
                {                
                    bossyeti->bossyeti=loadImage("src/graphics/BossYeti/BossYetiFissure1G.png");                    
                    Draw_Image(bossyeti->bossyeti,bossyeti->posmonsx,bossyeti->posmonsy);
                    if (bossyeti->NumSprit==90)
                    {
                    bossyeti->tempsfissure=1;
                    bossyeti->xfissure=bossyeti->posmonsx-300;
                    bossyeti->yfissure=bossyeti->posmonsy+100;
                    bossyeti->directionfissure=bossyeti->Direction;
                    bossyeti->spritfissure=0;
                    }
                    

                }
                
               
            }
 
            if (bossyeti->Direction==0)
            {            
                if (bossyeti->NumSprit>=0 && bossyeti->NumSprit<10 || bossyeti->NumSprit>=80 && bossyeti->NumSprit<90 )
                {  
                    bossyeti->bossyeti=loadImage("src/graphics/BossYeti/BossYetiFissure2D.png");
                    Draw_Image(bossyeti->bossyeti,bossyeti->posmonsx,bossyeti->posmonsy);
                    if (bossyeti->NumSprit==9 && bossyeti->tempsfissure!=0)
                    {
                    bossyeti->tempsfissure=0;
                    }
                }
                if (bossyeti->NumSprit>=10 && bossyeti->NumSprit<20 || bossyeti->NumSprit>=70 && bossyeti->NumSprit<80)
                {
                    bossyeti->bossyeti=loadImage("src/graphics/BossYeti/BossYetiFissure3D.png");
                    Draw_Image(bossyeti->bossyeti,bossyeti->posmonsx,bossyeti->posmonsy);
                }
                if (bossyeti->NumSprit>=20 && bossyeti->NumSprit<30 || bossyeti->NumSprit>=60 && bossyeti->NumSprit<70)
                {  
                 
                    bossyeti->bossyeti=loadImage("src/graphics/BossYeti/BossYetiFissure4D.png");
                    Draw_Image(bossyeti->bossyeti,bossyeti->posmonsx,bossyeti->posmonsy);
                    if (bossyeti->NumSprit==68)
                    {
                    Mix_VolumeChunk(son->solbossyeti, MIX_MAX_VOLUME);
                    Mix_PlayChannel(16, son->solbossyeti, 0);
                    }
                    
                }
                if (bossyeti->NumSprit>=30 && bossyeti->NumSprit<40 || bossyeti->NumSprit>=50 && bossyeti->NumSprit<60)
                {                
                    bossyeti->bossyeti=loadImage("src/graphics/BossYeti/BossYetiFissure5D.png");                    
                    Draw_Image(bossyeti->bossyeti,bossyeti->posmonsx,bossyeti->posmonsy);
                }
                if (bossyeti->NumSprit>=40 && bossyeti->NumSprit<50 )
                {                
                    bossyeti->bossyeti=loadImage("src/graphics/BossYeti/BossYetiFissure6D.png");                    
                    Draw_Image(bossyeti->bossyeti,bossyeti->posmonsx,bossyeti->posmonsy);
                    

                }
                if (bossyeti->NumSprit>=90  )
                {                
                    bossyeti->bossyeti=loadImage("src/graphics/BossYeti/BossYetiFissure1D.png");                    
                    Draw_Image(bossyeti->bossyeti,bossyeti->posmonsx,bossyeti->posmonsy);
                    if (bossyeti->NumSprit==90)
                    {
                    bossyeti->tempsfissure=1;
                    bossyeti->xfissure=bossyeti->posmonsx+100;
                    bossyeti->yfissure=bossyeti->posmonsy+100;
                    bossyeti->directionfissure=bossyeti->Direction;
                    bossyeti->spritfissure=0;
                    }
                    

                }
                
            }
            if (bossyeti->NumSprit>95)
            {
                bossyeti->NumSprit=0;
                bossyeti->compteurfissure=0;
                
            }
        }
        }
    }

  
   
    //Sprit crane
    if (bossyeti->Eattaque == 1)
    {
        if (bossyeti->directioncrane==1)
        {
            if (bossyeti->xcrane>=20 && bossyeti->xcrane<=600 && bossyeti->ycrane>= 20 && bossyeti->ycrane<=384)
            {
                bossyeti->crane=loadImage("src/graphics/BossYeti/CraneG.png");                    
                Draw_Image(bossyeti->crane,bossyeti->xcrane,bossyeti->ycrane);
               
                if (Inside_Vol(bossyeti->xcrane,bossyeti->ycrane,joueur->inposx,joueur->inposy,64,64,35,26)==1 && bossyeti->coup == 0)
                {
                    joueur->life--;
                    if (joueur->life != 0)
                    {
                    bossyeti->coup=1;
                    }
                    
                }
                bossyeti->xcrane-=7;
            }
            else
            {
                bossyeti->Compteurcrane+=1;
                if (bossyeti->Compteurcrane>=0 && bossyeti->Compteurcrane<5)
                {  
                     if (bossyeti->Compteurcrane==1)
                    {
                    Mix_VolumeChunk(son->cranemur, MIX_MAX_VOLUME);
                    Mix_PlayChannel(7, son->cranemur, 0);
                    }
                   
                    bossyeti->crane=loadImage("src/graphics/BossYeti/CraneMur1G.png");
                    Draw_Image(bossyeti->crane,bossyeti->xcrane,bossyeti->ycrane);
                }
                if (bossyeti->Compteurcrane>=5 && bossyeti->Compteurcrane<10)
                {  
                    bossyeti->crane=loadImage("src/graphics/BossYeti/CraneMur2G.png");
                    Draw_Image(bossyeti->crane,bossyeti->xcrane,bossyeti->ycrane);
                }
                if (bossyeti->Compteurcrane>=15 && bossyeti->Compteurcrane<20)
                {  
                    bossyeti->crane=loadImage("src/graphics/BossYeti/CraneMur3G.png");
                    Draw_Image(bossyeti->crane,bossyeti->xcrane,bossyeti->ycrane);
                }
                if (bossyeti->Compteurcrane>=20 && bossyeti->Compteurcrane<25)
                {  
                    bossyeti->crane=loadImage("src/graphics/BossYeti/CraneMur4G.png");
                    Draw_Image(bossyeti->crane,bossyeti->xcrane,bossyeti->ycrane);
                }
                if (bossyeti->Compteurcrane>=25)
                {
                    SDL_DestroyTexture(bossyeti->crane);
                    bossyeti->crane=NULL;
                    bossyeti->Eattaque=0;
                    bossyeti->Compteurcrane=0;
                }
            }
        }
        if (bossyeti->directioncrane==0)
        {
            if (bossyeti->xcrane>=20 && bossyeti->xcrane<=585 && bossyeti->ycrane>= 20 && bossyeti->ycrane<=384)
            {
                bossyeti->crane=loadImage("src/graphics/BossYeti/CraneD.png");                    
                Draw_Image(bossyeti->crane,bossyeti->xcrane,bossyeti->ycrane);
                if (Inside_Vol(bossyeti->xcrane,bossyeti->ycrane,joueur->inposx,joueur->inposy,64,64,35,26)==1 && bossyeti->coup == 0)
                {
                    joueur->life--;
                    if (joueur->life != 0)
                    {
                    bossyeti->coup=1;
                    }
                    
                }
                bossyeti->xcrane+=7;
            }
            else
            {
                bossyeti->Compteurcrane+=1;
                if (bossyeti->Compteurcrane>=0 && bossyeti->Compteurcrane<5)
                {  
                    if (bossyeti->Compteurcrane==1)
                    {
                    Mix_VolumeChunk(son->cranemur, MIX_MAX_VOLUME);
                    Mix_PlayChannel(7, son->cranemur, 0);
                    }
                    bossyeti->crane=loadImage("src/graphics/BossYeti/CraneMur1D.png");
                    Draw_Image(bossyeti->crane,bossyeti->xcrane,bossyeti->ycrane);
                }
                if (bossyeti->Compteurcrane>=5 && bossyeti->Compteurcrane<10)
                {  
                    bossyeti->crane=loadImage("src/graphics/BossYeti/CraneMur2D.png");
                    Draw_Image(bossyeti->crane,bossyeti->xcrane,bossyeti->ycrane);
                }
                if (bossyeti->Compteurcrane>=15 && bossyeti->Compteurcrane<20)
                {  
                    bossyeti->crane=loadImage("src/graphics/BossYeti/CraneMur3D.png");
                    Draw_Image(bossyeti->crane,bossyeti->xcrane,bossyeti->ycrane);
                }
                if (bossyeti->Compteurcrane>=20 && bossyeti->Compteurcrane<25)
                {  
                    bossyeti->crane=loadImage("src/graphics/BossYeti/CraneMur4D.png");
                    Draw_Image(bossyeti->crane,bossyeti->xcrane,bossyeti->ycrane);
                }
                if (bossyeti->Compteurcrane>=25)
                {
                    SDL_DestroyTexture(bossyeti->crane);
                    bossyeti->crane=NULL;
                    bossyeti->Eattaque=0;
                    bossyeti->Compteurcrane=0;
                }
            }
        }
    }
    // timing degat chevalier
    if (bossyeti->coup>0)
    {
        bossyeti->coup+=1;
        if (bossyeti->coup >25)
        {
            bossyeti->coup=0;
        }
    }
    if (bossyeti->compteur>=190)
    {
        bossyeti->compteur=0;
    }
    //Mort bossyeti
    if (bossyeti->Life==0)
    {
        if (bossyeti->Direction==1)
        {  
            if (bossyeti->CompteurSpriteDegat==0 || bossyeti->CompteurSpriteDegat==1 || bossyeti->CompteurSpriteDegat==2 || bossyeti->CompteurSpriteDegat==3 )
            {
                bossyeti->bossyeti=loadImage("src/graphics/BossYeti/MortBossYeti1G.png");
                Draw_Image(bossyeti->bossyeti,bossyeti->posmonsx,bossyeti->posmonsy);
                if (bossyeti->CompteurSpriteDegat==1)
                {
                    Mix_VolumeChunk(son->mortbossyeti, MIX_MAX_VOLUME);
                     Mix_PlayChannel(9, son->mortbossyeti, 0);
                }
            }
            if (bossyeti->CompteurSpriteDegat==4 || bossyeti->CompteurSpriteDegat==5 || bossyeti->CompteurSpriteDegat==6 || bossyeti->CompteurSpriteDegat==7 )
            {
                bossyeti->bossyeti=loadImage("src/graphics/BossYeti/MortBossYeti2G.png");
                Draw_Image(bossyeti->bossyeti,bossyeti->posmonsx,bossyeti->posmonsy);
            }
            if (bossyeti->CompteurSpriteDegat==8 || bossyeti->CompteurSpriteDegat==9 || bossyeti->CompteurSpriteDegat==10 || bossyeti->CompteurSpriteDegat==11)
            {
                bossyeti->bossyeti=loadImage("src/graphics/BossYeti/MortBossYeti3G.png");
                Draw_Image(bossyeti->bossyeti,bossyeti->posmonsx,bossyeti->posmonsy);
            }
            if (bossyeti->CompteurSpriteDegat==12 || bossyeti->CompteurSpriteDegat==13 || bossyeti->CompteurSpriteDegat==14 || bossyeti->CompteurSpriteDegat==15 )
            {
                bossyeti->bossyeti=loadImage("src/graphics/BossYeti/MortBossYeti4G.png");
                Draw_Image(bossyeti->bossyeti,bossyeti->posmonsx,bossyeti->posmonsy);
            }
            if (bossyeti->CompteurSpriteDegat==16 || bossyeti->CompteurSpriteDegat==17 || bossyeti->CompteurSpriteDegat==18 || bossyeti->CompteurSpriteDegat==19 )
            {
                bossyeti->bossyeti=loadImage("src/graphics/BossYeti/MortBossYeti5G.png");
                Draw_Image(bossyeti->bossyeti,bossyeti->posmonsx,bossyeti->posmonsy);
            }
        }
 
        if (bossyeti->Direction==0)
        {  
            if (bossyeti->CompteurSpriteDegat==0 || bossyeti->CompteurSpriteDegat==1 || bossyeti->CompteurSpriteDegat==2 || bossyeti->CompteurSpriteDegat==3 )
            {
                bossyeti->bossyeti=loadImage("src/graphics/BossYeti/MortBossYeti1D.png");
                Draw_Image(bossyeti->bossyeti,bossyeti->posmonsx,bossyeti->posmonsy);
                // if (bossyeti->CompteurSpriteDegat==1)
                // {
                // Mix_VolumeChunk(son->mortbossyeti, MIX_MAX_VOLUME);
                // Mix_PlayChannel(9, son->mortbossyeti, 0);
                // }
            }
            if (bossyeti->CompteurSpriteDegat==4 || bossyeti->CompteurSpriteDegat==5 || bossyeti->CompteurSpriteDegat==6 || bossyeti->CompteurSpriteDegat==7 )
            {
                bossyeti->bossyeti=loadImage("src/graphics/BossYeti/MortBossYeti2D.png");
                Draw_Image(bossyeti->bossyeti,bossyeti->posmonsx,bossyeti->posmonsy);
            }
            if (bossyeti->CompteurSpriteDegat==8 || bossyeti->CompteurSpriteDegat==9 || bossyeti->CompteurSpriteDegat==10 || bossyeti->CompteurSpriteDegat==11)
            {
                bossyeti->bossyeti=loadImage("src/graphics/BossYeti/MortBossYeti3D.png");
                Draw_Image(bossyeti->bossyeti,bossyeti->posmonsx,bossyeti->posmonsy);
            }
            if (bossyeti->CompteurSpriteDegat==12 || bossyeti->CompteurSpriteDegat==13 || bossyeti->CompteurSpriteDegat==14 || bossyeti->CompteurSpriteDegat==15 )
            {
                bossyeti->bossyeti=loadImage("src/graphics/BossYeti/MortBossYeti4D.png");
                Draw_Image(bossyeti->bossyeti,bossyeti->posmonsx,bossyeti->posmonsy);
            }
            if (bossyeti->CompteurSpriteDegat==16 || bossyeti->CompteurSpriteDegat==17 || bossyeti->CompteurSpriteDegat==18 || bossyeti->CompteurSpriteDegat==19 )
            {
                bossyeti->bossyeti=loadImage("src/graphics/BossYeti/MortBossYeti5D.png");
                Draw_Image(bossyeti->bossyeti,bossyeti->posmonsx,bossyeti->posmonsy);
            }
        }
        if (bossyeti->CompteurSpriteDegat==15)
        {
            lvl->MortMonstre+=1;
        }  
    }
   
}

void Sprit_Chauvesouris (Chauvesouris *chauvesouris, Joueur *joueur, Lvl *lvl, EffetSon *son)
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
                    Draw_Image(chauvesouris->chauvesouris,chauvesouris->posmonsx,chauvesouris->posmonsy);
                }
                if (chauvesouris->NumSprit==4 || chauvesouris->NumSprit==5 || chauvesouris->NumSprit==6 || chauvesouris->NumSprit==7  )
                {
                    chauvesouris->chauvesouris=loadImage("src/graphics/Chauvesouris/chauvesourismarche1D.png");
                    Draw_Image(chauvesouris->chauvesouris,chauvesouris->posmonsx,chauvesouris->posmonsy);
                }
                if (chauvesouris->NumSprit==12 || chauvesouris->NumSprit==13 || chauvesouris->NumSprit==14 || chauvesouris->NumSprit==15 )
                {
                    chauvesouris->chauvesouris=loadImage("src/graphics/Chauvesouris/chauvesourismarche2D.png");
                    Draw_Image(chauvesouris->chauvesouris,chauvesouris->posmonsx,chauvesouris->posmonsy);
                }  
            }

            if (chauvesouris->Direction==1){
                if (chauvesouris->NumSprit==0 || chauvesouris->NumSprit==1 || chauvesouris->NumSprit==2 || chauvesouris->NumSprit==3 ||chauvesouris->NumSprit==8 || chauvesouris->NumSprit==9 || chauvesouris->NumSprit==10 || chauvesouris->NumSprit==11 )
                {
                    
                    chauvesouris->chauvesouris=loadImage("src/graphics/Chauvesouris/chauvesourisneutreG.png");
                    Draw_Image(chauvesouris->chauvesouris,chauvesouris->posmonsx,chauvesouris->posmonsy);
                }
                if (chauvesouris->NumSprit==4 || chauvesouris->NumSprit==5 || chauvesouris->NumSprit==6 || chauvesouris->NumSprit==7  )
                {
                    chauvesouris->chauvesouris=loadImage("src/graphics/Chauvesouris/chauvesourismarche1G.png");
                    Draw_Image(chauvesouris->chauvesouris,chauvesouris->posmonsx,chauvesouris->posmonsy);
                }
                if (chauvesouris->NumSprit==12 || chauvesouris->NumSprit==13 || chauvesouris->NumSprit==14 || chauvesouris->NumSprit==15 )
                {
                    chauvesouris->chauvesouris=loadImage("src/graphics/Chauvesouris/chauvesourismarche2G.png");
                    Draw_Image(chauvesouris->chauvesouris,chauvesouris->posmonsx,chauvesouris->posmonsy);
                }
            } 
 
            //Attaque chauvesouris sans compt
            //si non bouclier
            if (Inside_Chauvesouris_Chevalier(joueur,chauvesouris)==1 && joueur->Eshield==0)
            {
                joueur->life--;
                chauvesouris->Life--;
                if (joueur->life != 0)
                {
                    chauvesouris->coup =1 ;
                }
                
                lvl->MortMonstre+=1;
            }
            //si bouclier
            if (Inside_Chauvesouris_Chevalier(joueur,chauvesouris)==1 && joueur->Eshield==1)
            {
                chauvesouris->Life--;
                lvl ->MortMonstre+=1;
                //si bouclier boucle active
                if (joueur->TimingBouclier>45)
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
            Draw_Image(chauvesouris->chauvesouris,chauvesouris->posmonsx,chauvesouris->posmonsy);
            if (chauvesouris->CompteurSpriteDegat==0)
            {
            Mix_VolumeChunk(son->mortchauvesouris, MIX_MAX_VOLUME);
            Mix_PlayChannel(6, son->mortchauvesouris, 0);
            }
        }
        if (chauvesouris->CompteurSpriteDegat==4 || chauvesouris->CompteurSpriteDegat==5 || chauvesouris->CompteurSpriteDegat==6 || chauvesouris->CompteurSpriteDegat==7 )
        {
            chauvesouris->chauvesouris=loadImage("src/graphics/Chauvesouris/chauvesourismort2D.png");
            Draw_Image(chauvesouris->chauvesouris,chauvesouris->posmonsx,chauvesouris->posmonsy);
        }
        if (chauvesouris->CompteurSpriteDegat==8 || chauvesouris->CompteurSpriteDegat==9 || chauvesouris->CompteurSpriteDegat==10 || chauvesouris->CompteurSpriteDegat==11)
        {
            chauvesouris->chauvesouris=loadImage("src/graphics/Chauvesouris/chauvesourismort3D.png");
            Draw_Image(chauvesouris->chauvesouris,chauvesouris->posmonsx,chauvesouris->posmonsy);
        }
        if (chauvesouris->CompteurSpriteDegat==12 || chauvesouris->CompteurSpriteDegat==13 || chauvesouris->CompteurSpriteDegat==14 || chauvesouris->CompteurSpriteDegat==15 )
        {
            chauvesouris->chauvesouris=loadImage("src/graphics/Chauvesouris/chauvesourismort4D.png");
            Draw_Image(chauvesouris->chauvesouris,chauvesouris->posmonsx,chauvesouris->posmonsy);
        }
        if (chauvesouris->CompteurSpriteDegat==16 || chauvesouris->CompteurSpriteDegat==17 || chauvesouris->CompteurSpriteDegat==18 || chauvesouris->CompteurSpriteDegat==19 )
        {
            chauvesouris->chauvesouris=loadImage("src/graphics/Chauvesouris/chauvesourismort5D.png");
            Draw_Image(chauvesouris->chauvesouris,chauvesouris->posmonsx,chauvesouris->posmonsy);
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
                    Draw_Image(boss->Boss,boss->posmonsx,boss->posmonsy);
                }
                if (boss->NumSprit==4 || boss->NumSprit==5 || boss->NumSprit==6 || boss->NumSprit==7 || boss->NumSprit==29 || boss->NumSprit==30 || boss->NumSprit==31  || boss->NumSprit==32)
                {
                    boss->Boss=loadImage("src/graphics/Boss/BossMarche1.png");
                    Draw_Image(boss->Boss,boss->posmonsx,boss->posmonsy);
                }
                if (boss->NumSprit==8 || boss->NumSprit==9 || boss->NumSprit==10 || boss->NumSprit==11|| boss->NumSprit==24 || boss->NumSprit==25 || boss->NumSprit==26 || boss->NumSprit==27 || boss->NumSprit==28 )
                {
                    boss->Boss=loadImage("src/graphics/Boss/BossMarche2.png");
                    Draw_Image(boss->Boss,boss->posmonsx,boss->posmonsy);
                }
                if (boss->NumSprit==12 || boss->NumSprit==13 || boss->NumSprit==14 || boss->NumSprit==19 || boss->NumSprit==20 || boss->NumSprit==21 || boss->NumSprit==22 || boss->NumSprit==23 )                   
                {
                    boss->Boss=loadImage("src/graphics/Boss/BossMarche3.png");
                    Draw_Image(boss->Boss,boss->posmonsx,boss->posmonsy);
                }
                if (boss->NumSprit==15 || boss->NumSprit==16 || boss->NumSprit==17 || boss->NumSprit==18 )
                {
                    boss->Boss=loadImage("src/graphics/Boss/BossMarche4.png");
                    Draw_Image(boss->Boss,boss->posmonsx,boss->posmonsy);    
                } 
                //degat epee
                if(Inside_Chevalier_Boss(joueur, boss)==1 && joueur->Numattack==15)
                {           
                    boss->CompteurSpriteDegat=1; 
                    boss->Life--; 
                }
                //degat dague
                if (Inside_Vol(joueur->xdague,joueur->ydague,boss->posmonsx,boss->posmonsy,128,128,30,15)==1)
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
                Draw_Image(boss->Boss,boss->posmonsx,boss->posmonsy); 
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
            Init_Eclair(boss);
        }
        // lancement attaque eclair
        if (boss->compteur >= 200 && boss->compteur < 530)
        {   
            //Eclair 1
            if (boss->CompteurSpriteEclair>=0 && boss->CompteurSpriteEclair<=10 )
            {
                boss->Eclair1=loadImage("src/graphics/Boss/WarningBoss1.png");
                Draw_Image(boss->Eclair1,boss->Ex1+12,boss->Ey1-16);   
            }
            if (boss->CompteurSpriteEclair>=11 && boss->CompteurSpriteEclair<=20 )
            {
                boss->Eclair1=loadImage("src/graphics/Boss/WarningBoss2.png");
                Draw_Image(boss->Eclair1,boss->Ex1,boss->Ey1-26);
            }
            if (boss->CompteurSpriteEclair>=21 && boss->CompteurSpriteEclair<=30)
            {
                boss->Eclair1=loadImage("src/graphics/Boss/EclairBoss.png");
                Draw_Image(boss->Eclair1,boss->Ex1,boss->Ey1-405);
            }
            
            if ((boss->CompteurSpriteEclair==25 && Inside_Eclair_Chevalier(joueur, boss->Ex1, boss->Ey1-405)==1))
            {
                joueur->life--;
                if (joueur->life != 0)
                {
                    boss->coupE1=1;
                }
                
            }
            if (boss->coupE1==1 && boss->compteur>240)
            {
                boss->coupE1=0;
            }
        
            //Eclair 2
            if (boss->CompteurSpriteEclair>=31 && boss->CompteurSpriteEclair<=40 )
            {
                boss->Eclair2=loadImage("src/graphics/Boss/WarningBoss1.png");
                Draw_Image(boss->Eclair2,boss->Ex2+12,boss->Ey2-16);
            }
            if (boss->CompteurSpriteEclair>=41 && boss->CompteurSpriteEclair<=50 )
            {
                boss->Eclair2=loadImage("src/graphics/Boss/WarningBoss2.png");
                Draw_Image(boss->Eclair2,boss->Ex2,boss->Ey2-26);
            }
            if (boss->CompteurSpriteEclair>=51 && boss->CompteurSpriteEclair<=60 )
            {
                boss->Eclair2=loadImage("src/graphics/Boss/EclairBoss.png");
                Draw_Image(boss->Eclair2,boss->Ex2,boss->Ey2-405);
            }
            if ((boss->CompteurSpriteEclair==55 && Inside_Eclair_Chevalier(joueur, boss->Ex2, boss->Ey2-405)==1))
            {
                joueur->life--;
                if (joueur->life != 0)
                {
                    boss->coupE2=1;
                }
                
            }
            if (boss->compteur>270 && boss->coupE2==1)
            {
                boss->coupE2=0;
            }
            //Eclair 3
            if (boss->CompteurSpriteEclair>=61 && boss->CompteurSpriteEclair<=70 )
            {
                boss->Eclair3=loadImage("src/graphics/Boss/WarningBoss1.png");
                Draw_Image(boss->Eclair3,boss->Ex3+12,boss->Ey3-16);
            }
            if (boss->CompteurSpriteEclair>=71 && boss->CompteurSpriteEclair<=80 )
            {
                boss->Eclair3=loadImage("src/graphics/Boss/WarningBoss2.png");
                Draw_Image(boss->Eclair3,boss->Ex3,boss->Ey3-26);
            }
            if (boss->CompteurSpriteEclair>=81 && boss->CompteurSpriteEclair<=90 )
            {
                boss->Eclair3=loadImage("src/graphics/Boss/EclairBoss.png");
                Draw_Image(boss->Eclair3,boss->Ex3,boss->Ey3-405);
            }
            if ((boss->CompteurSpriteEclair==85 && Inside_Eclair_Chevalier(joueur, boss->Ex3, boss->Ey3-405)==1))
            {
                joueur->life--;
                if (joueur->life != 0)
                {
                    boss->coupE3=1;
                }
                
            }
            if (boss->coupE3==1 && boss->compteur==300)
            {
                boss->coupE3=0;
            }

            //Eclair 4
            if (boss->CompteurSpriteEclair>=91 && boss->CompteurSpriteEclair<=100 )
            {
                boss->Eclair4=loadImage("src/graphics/Boss/WarningBoss1.png");
                Draw_Image(boss->Eclair4,boss->Ex4+12,boss->Ey4-16);
            }
            if (boss->CompteurSpriteEclair>=101 && boss->CompteurSpriteEclair<=110 )
            {
                boss->Eclair4=loadImage("src/graphics/Boss/WarningBoss2.png");
                Draw_Image(boss->Eclair4,boss->Ex4,boss->Ey4-26);
            }
            if (boss->CompteurSpriteEclair>=111 && boss->CompteurSpriteEclair<=121 )
            {
                boss->Eclair4=loadImage("src/graphics/Boss/EclairBoss.png");
                Draw_Image(boss->Eclair4,boss->Ex4,boss->Ey4-405);
            }
            if ((boss->CompteurSpriteEclair==115 && Inside_Eclair_Chevalier(joueur, boss->Ex4, boss->Ey4-405)==1))
            {
                joueur->life--;
                if (joueur->life != 0)
                {
                    boss->coupE4=1;
                }
                
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
                Draw_Image(boss->Boss,boss->posmonsx,boss->posmonsy);
            }
            if (boss->NumSprit==4 || boss->NumSprit==5 || boss->NumSprit==6 || boss->NumSprit==7 || boss->NumSprit==29 || boss->NumSprit==30 || boss->NumSprit==31 || boss->NumSprit==32 )
            {
                boss->Boss=loadImage("src/graphics/Boss/Bossattaque2.png");
                Draw_Image(boss->Boss,boss->posmonsx,boss->posmonsy);
            }
            if (boss->NumSprit==8 || boss->NumSprit==9 || boss->NumSprit==10 || boss->NumSprit==11|| boss->NumSprit==24 || boss->NumSprit==25 || boss->NumSprit==26 || boss->NumSprit==27 || boss->NumSprit==28 )
            {
                boss->Boss=loadImage("src/graphics/Boss/Bossattaque3.png");
                Draw_Image(boss->Boss,boss->posmonsx,boss->posmonsy);
            }
            if (boss->NumSprit==12 || boss->NumSprit==13 || boss->NumSprit==14 || boss->NumSprit==19 || boss->NumSprit==20 || boss->NumSprit==21 || boss->NumSprit==22 || boss->NumSprit==23 )
            {
                boss->Boss=loadImage("src/graphics/Boss/Bossattaque4.png");                    
                Draw_Image(boss->Boss,boss->posmonsx,boss->posmonsy);
            }
            if (boss->NumSprit==15 || boss->NumSprit==16 || boss->NumSprit==17 || boss->NumSprit==18 )
            {   if (boss->NumSprit==15)
                {
                Mix_VolumeChunk(son->attaqueboss, MIX_MAX_VOLUME);
                Mix_PlayChannel(7, son->attaqueboss, 0);
                }
                boss->Boss=loadImage("src/graphics/Boss/Bossattaque5.png");
                Draw_Image(boss->Boss,boss->posmonsx,boss->posmonsy);
                boss->Bossattaque=loadImage("src/graphics/Boss/AttaqueBoss.png");
                Draw_Image(boss->Bossattaque,boss->posmonsx -46 ,boss->posmonsy - 46);
                //fonction inside
                if(Inside_Boss_Meduse_Chevalier(joueur, boss)==1 && (boss->NumSprit==15 || boss->NumSprit==18))                    
                {
                    if (boss->coup == 0)
                    {
                        joueur->life--;
                        
                        if (joueur->life != 0)
                        {
                            boss->coup =1;
                        }
                        
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
            Draw_Image(boss->Boss,boss->posmonsx,boss->posmonsy);
            Mix_VolumeChunk(son->mortboss, MIX_MAX_VOLUME);
            Mix_PlayChannel(6, son->mortboss, 0);
        }
        if (boss->CompteurSpriteDegat>= 6 && boss->CompteurSpriteDegat<=10 )
        {
            boss->Boss=loadImage("src/graphics/Boss/Bossmort2.png");
            Draw_Image(boss->Boss,boss->posmonsx,boss->posmonsy);
        }
        if (boss->CompteurSpriteDegat>=11 && boss->CompteurSpriteDegat<=15)
        {
            boss->Boss=loadImage("src/graphics/Boss/Bossmort3.png");
            Draw_Image(boss->Boss,boss->posmonsx,boss->posmonsy);
        }
        if (boss->CompteurSpriteDegat>=16 && boss->CompteurSpriteDegat<=20 )
        {
            boss->Boss=loadImage("src/graphics/Boss/Bossmort4.png");
            Draw_Image(boss->Boss,boss->posmonsx,boss->posmonsy);
        }
        if (boss->CompteurSpriteDegat==21)
        {
            boss->Boss=loadImage("src/graphics/Boss/Bossmort5.png");
            Draw_Image(boss->Boss,boss->posmonsx,boss->posmonsy);
        }
        //Coffre ouvert
        if (boss->CompteurSpriteDegat>=22 )
        {
            boss->Boss=loadImage("src/graphics/Boss/Bossmort6.png");
            Draw_Image(boss->Boss,boss->posmonsx,boss->posmonsy);
        }
        if (boss->CompteurSpriteDegat>22 && boss->CompteurSpriteDegat<27)
        {
            boss->Coeur=loadImage("src/graphics/lvl/Coeur1.png");
            Draw_Image(boss->Coeur,boss->posmonsx,boss->posmonsy+78);
        }
        if (boss->CompteurSpriteDegat>=27 && boss->CompteurSpriteDegat<32)
        {
            boss->Coeur=loadImage("src/graphics/lvl/Coeur1.png");
            Draw_Image(boss->Coeur,boss->posmonsx-5,boss->posmonsy+73);
        }
        if (boss->CompteurSpriteDegat>=32 && boss->CompteurSpriteDegat<37)
        {
            boss->Coeur=loadImage("src/graphics/lvl/Coeur1.png");
            Draw_Image(boss->Coeur,boss->posmonsx-10,boss->posmonsy+68);
        }
        if (boss->CompteurSpriteDegat>=37 && boss->CompteurSpriteDegat<42)
        {
            boss->Coeur=loadImage("src/graphics/lvl/Coeur1.png");
            Draw_Image(boss->Coeur,boss->posmonsx-15,boss->posmonsy+73);
        }
        if (boss->CompteurSpriteDegat>=42)
        {
            if (boss->RecupCoeur==0)
            {
                if (boss->CompteurSpriteDegat % 50 == 0)
                {
                    boss->Coeur=loadImage("src/graphics/lvl/Coeur1.png");
                    Draw_Image(boss->Coeur,boss->posmonsx-20,boss->posmonsy+78);
                }
                else
                {
                    boss->Coeur=loadImage("src/graphics/lvl/Coeur2.png");
                    Draw_Image(boss->Coeur,boss->posmonsx-20,boss->posmonsy+78);
                }
                if (Inside_Item(joueur,boss)==1)
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

void Gestion_Marchands (Joueur *joueur, Input *input, Marchand *marchand,Lvl *lvl, EffetSon *son)
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
    if (marchand->Table != NULL)
    {
        SDL_DestroyTexture(marchand->Table);
        marchand->Table = NULL;
    }
    
    
    
    
    if (lvl->Num == 4)
    {
        //Affichage de la table 
        marchand->Table=loadImage("src/graphics/Marchand/Table.png");
        Draw_Image(marchand->Table,220,55);
    }
    //Compteur des sprites
    marchand->Compteur1 +=1 ;

    //Sprite Jermy
    //affichage jerem dans le marché 
    if (lvl->Num == 4 || (lvl->Num == 5 && lvl->WinDonjon<=2))
    {
        marchand->Enter=loadImage("src/graphics/Marchand/Enter.png");
        Draw_Image(marchand->Enter,463,300);
        if ((marchand->Compteur1>=0 && marchand->Compteur1<10) || (marchand->Compteur1>=50 && marchand->Compteur1<=60))
        {
            marchand->Jerem=loadImage("src/graphics/Marchand/Jarmy1.png");
            Draw_Image(marchand->Jerem,450,210);
        }
        if ((marchand->Compteur1>=10 && marchand->Compteur1<20) || (marchand->Compteur1>=40 && marchand->Compteur1<50))
        {
            marchand->Jerem=loadImage("src/graphics/Marchand/Jarmy2.png");
            Draw_Image(marchand->Jerem,448,210);
        }
        if ((marchand->Compteur1>=20 && marchand->Compteur1<40))
        { 
            marchand->Jerem=loadImage("src/graphics/Marchand/Jarmy3.png");
            Draw_Image(marchand->Jerem,450,210);
        }
    }
    
    //Bulle donjon bleu avec dague
    if (lvl->Num == 5 && lvl->WinDonjon<=20)
    {
        if (joueur->inposx >= 350 && joueur->inposx <= 539 && joueur->inposy >= 210 && joueur->inposy<270)
        {
            if (input->enter == 1)
            {
                SDL_Delay(200);
                marchand->CompteurMess1 += 1;
                son->CompteurJerm=0;
            }
            if (marchand->CompteurMess1==1)
            {
                marchand->bulle=loadImage("src/graphics/Marchand/BulleCouteau1.png");
                Draw_Image(marchand->bulle,210,130);
                son->CompteurJerm++;
                if (son->CompteurJerm==1)
                {
                Mix_VolumeChunk(son->JeremDamm, MIX_MAX_VOLUME);
                Mix_PlayChannel(2, son->JeremDamm, 0);
                }
            }
            if (marchand->CompteurMess1==2)
            {
                marchand->bulle=loadImage("src/graphics/Marchand/BulleCouteau2.png");
                Draw_Image(marchand->bulle,210,130);
                                son->CompteurJerm++;
                if (son->CompteurJerm==1)
                {
                Mix_VolumeChunk(son->Jerem, MIX_MAX_VOLUME);
                Mix_PlayChannel(2, son->Jerem, 0);
                }
            }
            if (marchand->CompteurMess1==3)
            {
                marchand->bulle=loadImage("src/graphics/Marchand/BulleCouteau3.png");
                Draw_Image(marchand->bulle,210,95);
                son->CompteurJerm++;
                if (son->CompteurJerm==1)
                {
                Mix_VolumeChunk(son->Jerem, MIX_MAX_VOLUME);
                Mix_PlayChannel(2, son->Jerem, 0);
                }
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
                son->CompteurJerm=0;
            }
            if (marchand->CompteurMess1==1)
            {
                marchand->bulle=loadImage("src/graphics/Marchand/BulleJermy1.png");
                Draw_Image(marchand->bulle,210,130);
                son->CompteurJerm++;
                if (son->CompteurJerm==1)
                {
                Mix_VolumeChunk(son->JeremDamm, MIX_MAX_VOLUME);
                Mix_PlayChannel(2, son->JeremDamm, 0);
                }
            }
            if (marchand->CompteurMess1==2)
            {
                marchand->bulle=loadImage("src/graphics/Marchand/BulleJermy2.png");
                Draw_Image(marchand->bulle,210,130);
                son->CompteurJerm++;
                if (son->CompteurJerm==1)
                {
                Mix_VolumeChunk(son->Jerem, MIX_MAX_VOLUME);
                Mix_PlayChannel(2, son->Jerem, 0);
                }
            }
            if (marchand->CompteurMess1==3)
            {
                marchand->bulle=loadImage("src/graphics/Marchand/BulleJermy3.png");
                Draw_Image(marchand->bulle,210,95);
                son->CompteurJerm++;
                if (son->CompteurJerm==1)
                {
                Mix_VolumeChunk(son->Jerem, MIX_MAX_VOLUME);
                Mix_PlayChannel(2, son->Jerem, 0);
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


        //Sprite Karine 
        marchand->Enter=loadImage("src/graphics/Marchand/Enter.png");
        Draw_Image(marchand->Enter,138,120);
        if ((marchand->Compteur1>=0 && marchand->Compteur1<10) || (marchand->Compteur1>=50 && marchand->Compteur1<=60))
        {
            marchand->Marchand=loadImage("src/graphics/Marchand/Karine1.png");
            Draw_Image(marchand->Marchand,160,50);
        }
        if ((marchand->Compteur1>=10 && marchand->Compteur1<20) || (marchand->Compteur1>=40 && marchand->Compteur1<50))
        {
            marchand->Marchand=loadImage("src/graphics/Marchand/Karine2.png");
            Draw_Image(marchand->Marchand,160,50);
        }
        if ((marchand->Compteur1>=20 && marchand->Compteur1<40))
        { 
            marchand->Marchand=loadImage("src/graphics/Marchand/Karine3.png");
            Draw_Image(marchand->Marchand,160,50);
        }
        

        //Sprite Bulle Karine
        if (joueur->inposx >= 170 && joueur->inposx <= 420 && joueur->inposy >= 48 && joueur->inposy<160)
        {
            if (input->enter == 1)
            {
                SDL_Delay(200);
                marchand->CompteurMess2 += 1;
                son->CompteurKarine=0;
            }
            if (marchand->CompteurMess2==1)
            {
                marchand->bulle=loadImage("src/graphics/Marchand/BulleKarine1.png");
                Draw_Image(marchand->bulle,10,115);
                son->CompteurKarine++;
                if (son->CompteurKarine==1)
                {
                Mix_VolumeChunk(son->karine, MIX_MAX_VOLUME);
                Mix_PlayChannel(10, son->karine, 0);
                }
            }
            if (marchand->CompteurMess2==2)
            {
                marchand->bulle=loadImage("src/graphics/Marchand/BulleKarine2.png");
                Draw_Image(marchand->bulle,10,115);
                son->CompteurKarine++;
                if (son->CompteurKarine==1)
                {
                Mix_VolumeChunk(son->karine, MIX_MAX_VOLUME);
                Mix_PlayChannel(10, son->karine, 0);
                }
            }
            if (marchand->CompteurMess2==3)
            {
                marchand->bulle=loadImage("src/graphics/Marchand/BulleKarine3.png");
                Draw_Image(marchand->bulle,10,115);
                son->CompteurKarine++;
                if (son->CompteurKarine==1)
                {
                Mix_VolumeChunk(son->karine, MIX_MAX_VOLUME);
                Mix_PlayChannel(10, son->karine, 0);
                }

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
        Draw_Image(marchand->Enter, 95,310);
        if ((marchand->Compteur1>=0 && marchand->Compteur1<10) || (marchand->Compteur1>=50 && marchand->Compteur1<=60))
        {
            marchand->Bec=loadImage("src/graphics/Marchand/Bec1.png");
            Draw_Image(marchand->Bec,60,220); 
        }
        if ((marchand->Compteur1>=10 && marchand->Compteur1<20) || (marchand->Compteur1>=40 && marchand->Compteur1<50))
        {
            marchand->Bec=loadImage("src/graphics/Marchand/Bec2.png");
            Draw_Image(marchand->Bec,60,220);
        }
        if ((marchand->Compteur1>=20 && marchand->Compteur1<40))
        { 
            marchand->Bec=loadImage("src/graphics/Marchand/Bec3.png");
            Draw_Image(marchand->Bec,60,220);
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
                son->CompteurJeff=0;

            }
            if (marchand->CompteurMess3==1)
            {
                marchand->bulle=loadImage("src/graphics/Marchand/BulleBec1.png");
                Draw_Image(marchand->bulle,55,170);
                son->CompteurJeff++;
                if (son->CompteurJeff==1)
                {
                Mix_VolumeChunk(son->jeff, MIX_MAX_VOLUME);
                Mix_PlayChannel(10, son->jeff, 0);
                }
            }
            if (marchand->CompteurMess3==2)
            {
                marchand->bulle=loadImage("src/graphics/Marchand/BulleBec2.png");
                Draw_Image(marchand->bulle,55,170);
                son->CompteurJeff++;
                if (son->CompteurJeff==1)
                {
                Mix_VolumeChunk(son->jeff, MIX_MAX_VOLUME);
                Mix_PlayChannel(10, son->jeff, 0);
                }
                
            }
            if (marchand->CompteurMess3==3)
            {
                marchand->bulle=loadImage("src/graphics/Marchand/BulleBec3.png");
                Draw_Image(marchand->bulle,55,170);
                son->CompteurJeff++;
                if (son->CompteurJeff==1)
                {
                Mix_VolumeChunk(son->jeff, MIX_MAX_VOLUME);
                Mix_PlayChannel(10, son->jeff, 0);
                }
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
            Draw_Image(marchand->Tanguy,255,198);
        }
        if ((marchand->Compteur1>=10 && marchand->Compteur1 < 20) ||( marchand->Compteur1>=30 && marchand->Compteur1<40))
        {
            marchand->Tanguy=loadImage("src/graphics/Rivière/TurboTangui.png");
            Draw_Image(marchand->Tanguy,255,195);
        }
        if (marchand->Compteur1>=20 && marchand->Compteur1<30)
        {
            marchand->Tanguy=loadImage("src/graphics/Rivière/TurboTangui.png");
            Draw_Image(marchand->Tanguy,255,192);
        }
        //Bateau joueur
        if (joueur->Ebateau == 1)
        {
            marchand->Bateau=loadImage("src/graphics/Rivière/Bateau.png");
            Draw_Image(marchand->Bateau,95,297);
        }
        if (joueur->inposx >= 100 && joueur->inposx <= 220 && joueur->inposy >= 135 && joueur->inposy<200)
        {
            if (input->enter == 1)
            {
                SDL_Delay(200);
                marchand->CompteurMess1 += 1;
                son->CompteurTanguy=0;
            }
             if (marchand->CompteurMess1==1)
            {
                marchand->bulle=loadImage("src/graphics/Rivière/BulleTanguy1.png");
                Draw_Image(marchand->bulle,255,62);
                son->CompteurTanguy++;
                if (son->CompteurTanguy==1)
                {
                Mix_VolumeChunk(son->tanguy, MIX_MAX_VOLUME);
                Mix_PlayChannel(10, son->tanguy, 0);
                }
            }
            if (marchand->CompteurMess1==2)
            {
                marchand->bulle=loadImage("src/graphics/Rivière/BulleTanguy2.png");
                Draw_Image(marchand->bulle,255,62);
                son->CompteurTanguy++;
                if (son->CompteurTanguy==1)
                {
                Mix_VolumeChunk(son->tanguy, MIX_MAX_VOLUME);
                Mix_PlayChannel(10, son->tanguy, 0);
                }
            }
            if (marchand->CompteurMess1==3)
            {
                marchand->bulle=loadImage("src/graphics/Rivière/BulleTanguy3.png");
                Draw_Image(marchand->bulle,255,62);
                son->CompteurTanguy++;
                if (son->CompteurTanguy==1)
                {
                Mix_VolumeChunk(son->tanguy, MIX_MAX_VOLUME);
                Mix_PlayChannel(10, son->tanguy, 0);
                }
                joueur->Ebateau=1;
            }
        }
        else
        {
            marchand->CompteurMess1 = 0;
        }
        //reset message
        if (marchand->CompteurMess1 == 4)
        {
            marchand ->CompteurMess1=0;
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

void Gestion_Obstacle(Joueur *joueur,Marchand *marchand,Obstacle *Petit_rocher,Obstacle *Gros_rocher, Obstacle *tronc,Obstacle* tanguy, Lvl *lvl, EffetSon *son)
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

    if (lvl->Avancement10 == 0 && (Petit_rocher->Etat != 0 || Gros_rocher->Etat != 0 || tronc->Etat != 0 || tanguy->Etat != 0))
    {
        Petit_rocher->Etat = 0;
        Gros_rocher->Etat = 0;
        tronc->Etat = 0;
        tanguy->Etat = 0;
    }
    
    
    

    
    if (lvl->Avancement10>0 && lvl->Avancement10 <=2)
    {
        if(Gros_rocher->Etat==0)
        {
            Gros_rocher->Image=loadImage("src/graphics/Rivière/Grosrocher.png");
            Draw_Image(Gros_rocher->Image,Gros_rocher->x,Gros_rocher->y);
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
            Draw_Image(Petit_rocher->Image,Petit_rocher->x,Petit_rocher->y);
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
            Draw_Image(tronc->Image,tronc->x,tronc->y);
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
            Draw_Image(Gros_rocher->Image,Gros_rocher->x,Gros_rocher->y);
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
            Draw_Image(Petit_rocher->Image,Petit_rocher->x,Petit_rocher->y);
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
            Draw_Image(tronc->Image,tronc->x,tronc->y);
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
            Draw_Image(Gros_rocher->Image,Gros_rocher->x,Gros_rocher->y);
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
            Draw_Image(tronc->Image,tronc->x,tronc->y);
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
            Draw_Image(Petit_rocher->Image,Petit_rocher->x,Petit_rocher->y);
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
            Draw_Image(Gros_rocher->Image,Gros_rocher->x,Gros_rocher->y);
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
    if (Inside_Vol(tronc->x,tronc->y, joueur->inposx, joueur->inposy,60,60,80,40)==1)
    {
        if (tronc->coup == 0 && Petit_rocher->coup == 0 && Gros_rocher->coup == 0)
        {
            joueur->life--; 
            if (joueur->life != 0)
            {
                tronc->coup = 1;
            }
            
        }
    }
    if (tronc->coup >=1)
    {
        tronc->coup+=1;
    }
    if (Inside_Vol(Petit_rocher->x,Petit_rocher->y, joueur->inposx, joueur->inposy,60,60,60,60)==1)
    {
        if (tronc->coup == 0 && Petit_rocher->coup == 0 && Gros_rocher->coup == 0)
        {
            joueur->life--; 
            
            if (joueur->life != 0)
            {
                Petit_rocher->coup = 1;
            }
            
        }   
    }
    if (Petit_rocher->coup >=1)
    {
        Petit_rocher->coup+=1;
    }
                                                                                    //x
    if (Inside_Vol(Gros_rocher->x,Gros_rocher->y, joueur->inposx, joueur->inposy,60,60,90,85)==1)
    {
        if (tronc->coup == 0 && Petit_rocher->coup == 0 && Gros_rocher->coup == 0)
        {
            joueur->life--;
            if (joueur->life != 0)
            {
                Gros_rocher->coup = 1; 
            }    
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
            Draw_Image(tanguy->Image,tanguy->x,tanguy->y);
            tanguy->x+=5;
        }
        else
        {

            tanguy->Etat=1;
            son->soncoule+=1;
            tanguy->Image=loadImage("src/graphics/Rivière/TanguiCoule.png");
            Draw_Image(tanguy->Image,tanguy->x,tanguy->y);
            if (son->soncoule==1)
            {
            Mix_VolumeChunk(son->collisionR, MIX_MAX_VOLUME/2);
            Mix_PlayChannel(3, son->collisionR, 0);
            }
            tanguy->x-=10;

        }       
    }

    if (joueur->inposx>420 && lvl->Avancement10>12 && joueur->Ebateau==2)
    {
        joueur->Ebateau= 1;
        joueur->inposx = 475;
        joueur->inposy = 180;
        marchand->Bateau=loadImage("src/graphics/Rivière/Bateau.png");
        Draw_Image(marchand->Bateau,450,300);
    }

    //dessin bateau
    if (joueur->Ebateau==1)
    {
        marchand->Bateau=loadImage("src/graphics/Rivière/Bateau.png");
        Draw_Image(marchand->Bateau,460,300);
    }   

    if (tronc->coup >= 30 || Gros_rocher->coup >= 30 || Petit_rocher->coup >= 30)
    {
        Gros_rocher->coup = 0;
        Petit_rocher->coup = 0;
        tronc->coup = 0;
    } 

}

void Sprit_Squelette(Lvl *lvl,Squelette *squelette,Joueur *joueur, EffetSon *son)
{

    if (squelette->squelette != NULL)
    {
        SDL_DestroyTexture(squelette->squelette);
        squelette->squelette = NULL;
    }
    if (squelette->bulle != NULL)
    {
        SDL_DestroyTexture(squelette->bulle);
        squelette->squelette = NULL;
    }
    if (squelette->Jerem_Cin != NULL)
    {
        SDL_DestroyTexture(squelette->Jerem_Cin);
        squelette->Jerem_Cin = NULL;
    }
    if (squelette->Porte != NULL)
    {
        SDL_DestroyTexture(squelette->Porte);
        squelette->Porte = NULL;
    }
    if (squelette->étoiles != NULL)
    {
        SDL_DestroyTexture(squelette->étoiles);
        squelette->étoiles = NULL;
    }
    
    
    if (lvl->Num == 11 && lvl->cin == 1)
    {
        //sprite squelette
        
        if (squelette->Direction == 0 && squelette->Parle_S == 0)
        {
            squelette->squelette= loadImage("src/Graphics/Squelette/SqueletteneutreD.png");
            Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
        }
        else if (squelette->Direction == 0 && squelette->Parle_S == 1)
        { 
            if (squelette->NumSprit>=0 && squelette->NumSprit<10)
            {
                squelette->squelette= loadImage("src/Graphics/Squelette/SqueletteneutreD.png");
                Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy-2);
            }
            else if (squelette->NumSprit>=10 && squelette->NumSprit<20)
            {
                squelette->squelette= loadImage("src/Graphics/Squelette/SqueletteneutreD.png");
                Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy+2);
            }
        }
        if (squelette->Direction == 1 && squelette->Parle_S == 0)
        {
            squelette->squelette= loadImage("src/Graphics/Squelette/SqueletteneutreG.png");
            Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
        }
        else if (squelette->Direction == 1 && squelette->Parle_S == 1)
        { 
            
            if (squelette->NumSprit>=0 && squelette->NumSprit<10)
            {
                squelette->squelette= loadImage("src/Graphics/Squelette/SqueletteneutreG.png");
                Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy-2);
            }
            else if (squelette->NumSprit>=10 && squelette->NumSprit<20)
            {
                squelette->squelette= loadImage("src/Graphics/Squelette/SqueletteneutreG.png");
                Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy+2);
            } 
        }
        squelette->NumSprit+=1;
        if (squelette->NumSprit == 20)
        {
            squelette->NumSprit = 0;
        }


        if (squelette->compteur_cin < 1800)
        {   
            squelette->pos_jerem = 70;
            //jerem
            if ((squelette->compte_jerem >=0 && squelette->compte_jerem <10) || (squelette->compte_jerem>=50 && squelette->compte_jerem<=60))
            {
                squelette->Jerem_Cin=loadImage("src/graphics/Marchand/JeremSquelette1.png");
                Draw_Image(squelette->Jerem_Cin,270,squelette->pos_jerem);
                
            }
            if ((squelette->compte_jerem>=10 && squelette->compte_jerem<20) || (squelette->compte_jerem>=40 && squelette->compte_jerem<50))
            {
                squelette->Jerem_Cin=loadImage("src/graphics/Marchand/JeremSquelette2.png");
                Draw_Image(squelette->Jerem_Cin,270,squelette->pos_jerem);
            }
            if ((squelette->compte_jerem >=20 && squelette->compte_jerem <40))
            { 
                squelette->Jerem_Cin=loadImage("src/graphics/Marchand/JeremSquelette3.png");
                Draw_Image(squelette->Jerem_Cin,270,squelette->pos_jerem);
            }
            squelette->compte_jerem+=1;
            if (squelette->compte_jerem >60)
            {
                squelette->compte_jerem=0;
            }
            
            if (squelette->compteur_cin>20 && squelette->compteur_cin<500)
            {
                squelette->bulle = loadImage ("src/Graphics/Marchand/BulleJeremSquelette1.png");
                Draw_Image(squelette->bulle,122,175);
                if (squelette->compteur_cin==25)
                {
                    Mix_VolumeChunk(son->Jerem, MIX_MAX_VOLUME/2);
                    Mix_PlayChannel(3, son->Jerem, 0);
                }
            }
            if (squelette->compteur_cin>520 && squelette->compteur_cin<1000)
            {
                squelette->bulle = loadImage ("src/Graphics/Marchand/BulleJeremSquelette2.png");
                Draw_Image(squelette->bulle,122,180);
                if (squelette->Parle_S == 0)
                {
                    squelette->Parle_S=1;
                }
                if (squelette->compteur_cin==525)
                {
                    Mix_VolumeChunk(son->bullesq, MIX_MAX_VOLUME/2);
                    Mix_PlayChannel(3, son->bullesq, 0);
                }
            }
            if (squelette->compteur_cin>1020 && squelette->compteur_cin<1500)
            {
                squelette->bulle = loadImage ("src/Graphics/Marchand/BulleJeremSquelette3.png");
                Draw_Image(squelette->bulle,122,180);
                squelette->Parle_S=0;
                if (squelette->compteur_cin==1025)
                {
                    Mix_VolumeChunk(son->Jerem, MIX_MAX_VOLUME/2);
                    Mix_PlayChannel(3, son->Jerem, 0);
                }
            }
            if (squelette->compteur_cin>1520 && squelette->compteur_cin<1700)
            {
                squelette->bulle = loadImage ("src/Graphics/Marchand/BulleJeremSquelette4.png");
                Draw_Image(squelette->bulle,122,180);
            }
        }
        else
        {   if (squelette->pos_jerem>5 && squelette->pos_jerem<=50)
            {
            squelette->Porte=loadImage("src/graphics/lvl/PorteNoirOuverteHaut.png");
            Draw_Image(squelette->Porte,SCREEN_WIDTH/2-22,0);
            }
            squelette->Jerem_Cin=loadImage("src/graphics/Marchand/JeremSquelette3.png");
            Draw_Image(squelette->Jerem_Cin,270,squelette->pos_jerem);
            squelette->pos_jerem-=5;
            if (squelette->pos_jerem<5)
            {
                lvl->cin = 0;
            }
            
        }
        squelette->compteur_cin+=1;
    }
    else 
    {
        //Mouvement  squelette quand en vie et quand il ne prend pas de degat
        if (squelette->Life >=1 && squelette->CompteurSpriteDegat == 0)
        {
            //Dague
            if (Inside_Vol(joueur->xdague,joueur->ydague,squelette->posmonsx,squelette->posmonsy,58,64,30,15)==1 && (squelette->Eattaque == 2 ||squelette->Eattaque == 0))
            {
                squelette->Life--;
                squelette->CompteurSpriteDegat +=1;
            }
            
            
            
            
            if (Inside_Squelette_Chevalier(joueur, squelette)==1 && squelette->Eattaque == 0)
            {
                squelette->Eattaque = 1;
                squelette->NumSprit =0 ;
            }
            if (squelette->Eattaque == 1 )
            {   
                if(squelette->Direction == 0)
                {
                    if (squelette->NumSprit>=0 && squelette->NumSprit <5 || squelette->NumSprit>=30)
                    {
                        squelette->squelette=loadImage("src/graphics/squelette/Squelettecoup1D.png");
                        Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                        if(squelette->NumSprit==1)
                        {
                            Mix_VolumeChunk(son->attaquesquelette, MIX_MAX_VOLUME/2);
                            Mix_PlayChannel(3, son->attaquesquelette, 0); 
                        }
                    }
                    if (squelette->NumSprit>=5 && squelette->NumSprit <10 || squelette->NumSprit>=25 && squelette->NumSprit <30)
                    {
                        squelette->squelette=loadImage("src/graphics/squelette/Squelettecoup2D.png");
                        Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                    }
                    if (squelette->NumSprit>=10 && squelette->NumSprit <15 || squelette->NumSprit>=20 && squelette->NumSprit <25)
                    {
                        squelette->squelette=loadImage("src/graphics/squelette/Squelettecoup3D.png");
                        Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                    }
                    if (squelette->NumSprit>=15 && squelette->NumSprit <20)
                    {
                        squelette->squelette=loadImage("src/graphics/squelette/Squelettecoup4D.png");
                        Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                    }
                }
                if (squelette->Direction == 1)
                {
                    if (squelette->NumSprit>=0 && squelette->NumSprit <5 || squelette->NumSprit>=30)
                    {
                        squelette->squelette=loadImage("src/graphics/squelette/Squelettecoup1G.png");
                        Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                        if(squelette->NumSprit==1)
                        {
                            Mix_VolumeChunk(son->attaquesquelette, MIX_MAX_VOLUME/2);
                            Mix_PlayChannel(3, son->attaquesquelette, 0); 
                        }
                    }
                    if (squelette->NumSprit>=5 && squelette->NumSprit <10 || squelette->NumSprit>=25 && squelette->NumSprit <30)
                    {
                        squelette->squelette=loadImage("src/graphics/squelette/Squelettecoup2G.png");
                        Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                    }
                    if (squelette->NumSprit>=10 && squelette->NumSprit <15 || squelette->NumSprit>=20 && squelette->NumSprit <25)
                    {
                        squelette->squelette=loadImage("src/graphics/squelette/Squelettecoup3G.png");
                        Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                    }
                    if (squelette->NumSprit>=15 && squelette->NumSprit <20)
                    {
                        squelette->squelette=loadImage("src/graphics/squelette/Squelettecoup4G.png");
                        Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                        
                        
                    }
                }

                //attaque
                if (Inside_Squelette_Chevalier(joueur, squelette)==1 && squelette->NumSprit == 16)
                {
                    if (joueur->Eshield == 0 || joueur->TimingBouclier >45)
                    {
                        //joueur->life--;
                        if (joueur->life != 0)
                        {
                            squelette->coup = 1;
                        }
                    }
                    if (joueur->Eshield == 1 && joueur->TimingBouclier<=45)
                    {
                        squelette->Eattaque = 2;
                        squelette->NumSprit = 0;
                    }
                }

                if (squelette->NumSprit >= 35)
                {
                    squelette->NumSprit = 0;
                    squelette->Eattaque = 0;
                }
            }
            else if (squelette->Eattaque == 2)
            {
            son->sondegatsq=0;
                if (squelette->Direction == 0)
                {
                    squelette->squelette=loadImage("src/graphics/squelette/squeletteneutreD.png");
                    Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                    
                    if (squelette->NumSprit >= 0 && squelette->NumSprit <25 || squelette->NumSprit>=50 && squelette->NumSprit<75 || squelette->NumSprit>=100 && squelette->NumSprit<125)
                    {
                        squelette->squelette=loadImage("src/graphics/squelette/Etourdis1.png");
                        Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy+5);
                        if (squelette->NumSprit==1)
                        {
                            Mix_VolumeChunk(son->etourdissement, MIX_MAX_VOLUME);
                            Mix_PlayChannel(3, son->etourdissement, 0);
                        }
                        
                    }
                    if (squelette->NumSprit >= 25 && squelette->NumSprit <50 || squelette->NumSprit>=75 && squelette->NumSprit<100 || squelette->NumSprit>=125 && squelette->NumSprit<150)
                    {
                        squelette->squelette=loadImage("src/graphics/squelette/Etourdis2.png");
                        Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy+5);
                    }
                }
                else
                {
                    squelette->squelette=loadImage("src/graphics/squelette/squeletteneutreG.png");
                    Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);

                    if (squelette->NumSprit >= 0 && squelette->NumSprit <25 || squelette->NumSprit>=50 && squelette->NumSprit<75 || squelette->NumSprit>=100 && squelette->NumSprit<125)
                    {
                        squelette->squelette=loadImage("src/graphics/squelette/Etourdis1.png");
                        Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy+5);
                        if (squelette->NumSprit==1)
                        {
                            Mix_VolumeChunk(son->etourdissement, MIX_MAX_VOLUME);
                            Mix_PlayChannel(3, son->etourdissement, 0);
                        }
                    }
                    if (squelette->NumSprit >= 25 && squelette->NumSprit <50 || squelette->NumSprit>=75 && squelette->NumSprit<100 || squelette->NumSprit>=125 && squelette->NumSprit<150)
                    {
                        squelette->squelette=loadImage("src/graphics/squelette/Etourdis2.png");
                        Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy+5);
                    }
                }
                if (Inside_Chevalier_Squelette(joueur,squelette)==1 && joueur->Numattack == 15)
                {
                    squelette->Life--;
                    squelette->CompteurSpriteDegat+=1;
                    squelette->Eattaque = 0;
                }
                squelette->NumSprit+=1;
                if (squelette->NumSprit>=150)
                {
                    squelette->NumSprit=0 ;
                    squelette->Eattaque = 0;
                }
                
            }
            else 
            {
                if (squelette->CompteurSpriteDegat==0)
                {
                    if (squelette->Direction==0)
                    {
                        if (squelette->NumSprit==0 || squelette->NumSprit==1 || squelette->NumSprit==2 || squelette->NumSprit==3 ||squelette->NumSprit==8 || squelette->NumSprit==9 || squelette->NumSprit==10 || squelette->NumSprit==11 )
                        {
                            squelette->squelette=loadImage("src/graphics/squelette/squeletteneutreD.png");
                            Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                        }
                        if (squelette->NumSprit==4 || squelette->NumSprit==5 || squelette->NumSprit==6 || squelette->NumSprit==7  )
                        {
                            squelette->squelette=loadImage("src/graphics/squelette/squelettemarche1D.png");
                            Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                        }
                        if (squelette->NumSprit==12 || squelette->NumSprit==13 || squelette->NumSprit==14 || squelette->NumSprit==15 )
                        {
                            squelette->squelette=loadImage("src/graphics/squelette/squelettemarche2D.png");
                            Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                        }  
                    }
        
                    if (squelette->Direction==1)
                    {
                        if (squelette->NumSprit==0 || squelette->NumSprit==1 || squelette->NumSprit==2 || squelette->NumSprit==3 ||squelette->NumSprit==8 || squelette->NumSprit==9 || squelette->NumSprit==10 || squelette->NumSprit==11 )
                        {
                        
                            squelette->squelette=loadImage("src/graphics/squelette/squeletteneutreG.png");
                            Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                        }
                        if (squelette->NumSprit==4 || squelette->NumSprit==5 || squelette->NumSprit==6 || squelette->NumSprit==7  )
                        {
                            squelette->squelette=loadImage("src/graphics/squelette/squelettemarche1G.png");
                            Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                        }
                        if (squelette->NumSprit==12 || squelette->NumSprit==13 || squelette->NumSprit==14 || squelette->NumSprit==15 )
                        {
                            squelette->squelette=loadImage("src/graphics/squelette/squelettemarche2G.png");
                            Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                        }
                    }
                    if (squelette->NumSprit>=15)
                    {
                        squelette->NumSprit = 0;
                    }
                }
            } 
        } 
        else if(squelette->Life>=1 && squelette->CompteurSpriteDegat != 0)
        {
            if (squelette->Direction == 0)
            {
                son->sondegatsq++;
                squelette->squelette=loadImage("src/graphics/squelette/SqueletteDegatD.png");
                Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                if(son->sondegatsq==1)
                {
                Mix_VolumeChunk(son->degatsquelette, MIX_MAX_VOLUME/2);
                Mix_PlayChannel(3, son->degatsquelette, 0);
                }
            }
            if (squelette->Direction == 1)
            {
                son->sondegatsq++;
                squelette->squelette=loadImage("src/graphics/squelette/SqueletteDegatG.png");
                Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                if(son->sondegatsq==1)
                {
                Mix_VolumeChunk(son->degatsquelette, MIX_MAX_VOLUME/2);
                Mix_PlayChannel(3, son->degatsquelette, 0);
                }
            }
            
            squelette->CompteurSpriteDegat+=1;
            if (squelette->CompteurSpriteDegat >15)
            {
                squelette->CompteurSpriteDegat = 0;
            }
        }
        // si mort et pas de gestion tete (juste anim mort)
        else if (squelette->Life == 0 && squelette->Eattaque != 3 && squelette->Eattaque !=4)
        {
            if (squelette->Direction == 0)
            {
                if (squelette->CompteurSpriteDegat >= 0 && squelette->CompteurSpriteDegat <10)
                {
                    squelette->squelette=loadImage("src/graphics/squelette/SqueletteMort1D.png");
                    Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                }
                if (squelette->CompteurSpriteDegat >= 10 && squelette->CompteurSpriteDegat <20)
                {
                    squelette->squelette=loadImage("src/graphics/squelette/SqueletteMort2D.png");
                    Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                }
                if (squelette->CompteurSpriteDegat >= 20 && squelette->CompteurSpriteDegat <30)
                {
                    squelette->squelette=loadImage("src/graphics/squelette/SqueletteMort3D.png");
                    Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                }
                if (squelette->CompteurSpriteDegat >=30 && squelette->CompteurSpriteDegat <40)
                {
                    squelette->squelette=loadImage("src/graphics/squelette/SqueletteMort4D.png");
                    Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                }
                if (squelette->CompteurSpriteDegat >= 40 && squelette->CompteurSpriteDegat <=50)
                {
                    squelette->squelette=loadImage("src/graphics/squelette/SqueletteMort5D.png");
                    Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                }
            }
            if (squelette->Direction == 1)
            {
                if (squelette->CompteurSpriteDegat >= 0 && squelette->CompteurSpriteDegat <10)
                {
                    squelette->squelette=loadImage("src/graphics/squelette/SqueletteMort1G.png");
                    Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                }
                if (squelette->CompteurSpriteDegat >= 10 && squelette->CompteurSpriteDegat <20)
                {
                    squelette->squelette=loadImage("src/graphics/squelette/SqueletteMort2G.png");
                    Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                }
                if (squelette->CompteurSpriteDegat >=20 && squelette->CompteurSpriteDegat <30)
                {
                    squelette->squelette=loadImage("src/graphics/squelette/SqueletteMort3G.png");
                    Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                }
                if (squelette->CompteurSpriteDegat >= 30 && squelette->CompteurSpriteDegat <40)
                {
                    squelette->squelette=loadImage("src/graphics/squelette/SqueletteMort4G.png");
                    Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                }
                if (squelette->CompteurSpriteDegat >= 40 && squelette-> CompteurSpriteDegat <=50)
                {
                    squelette->squelette=loadImage("src/graphics/squelette/SqueletteMort5G.png");
                    Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                }
            }
            if (squelette->CompteurSpriteDegat < 50)
            {
            squelette->CompteurSpriteDegat+=1;
            }
            else
            {
                squelette->Eattaque = 3 ;
                squelette->CompteurSpriteDegat = 0 ;
            }
        }
        else if (squelette->Eattaque == 3 && squelette->rebond <=4)
        {
                if (squelette->Direction == 0)
                {
                    //boucle une fois et demi
                    if (squelette->CompteurSpriteDegat >= 0 && squelette-> CompteurSpriteDegat < 5|| (squelette->CompteurSpriteDegat >= 20 && squelette->rebond <=3))
                    {
                        squelette->squelette=loadImage("src/graphics/squelette/TeteSquelette1G.png");
                        Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                    }
                    if (squelette->CompteurSpriteDegat >= 5 && squelette-> CompteurSpriteDegat < 10 || (squelette->CompteurSpriteDegat >= 15 && squelette-> CompteurSpriteDegat < 20 && squelette->rebond <=3))
                    {
                        squelette->squelette=loadImage("src/graphics/squelette/TeteSquelette2G.png");
                        Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                    }
                    if (squelette->CompteurSpriteDegat >= 10 && squelette-> CompteurSpriteDegat < 15)
                    {
                        squelette->squelette=loadImage("src/graphics/squelette/TeteSquelette3G.png");
                        Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                        if (squelette->CompteurSpriteDegat==12)
                    {
                        Mix_VolumeChunk(son->rebond, MIX_MAX_VOLUME);
                        Mix_PlayChannel(5, son->rebond, 0);  
                    }
                    }
                    if (squelette->posmonsx >= 13)
                    {
                        squelette->posmonsx-=1;
                    } 
                }
                if (squelette->Direction == 1)
                {
                    if (squelette->CompteurSpriteDegat >= 0 && squelette-> CompteurSpriteDegat < 5|| (squelette->CompteurSpriteDegat >= 20 && squelette->rebond <=3))
                    {
                        squelette->squelette=loadImage("src/graphics/squelette/TeteSquelette1D.png");
                        Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                    }
                    if (squelette->CompteurSpriteDegat >= 5 && squelette-> CompteurSpriteDegat < 10 || (squelette->CompteurSpriteDegat >= 15 && squelette-> CompteurSpriteDegat < 20 && squelette->rebond <=3))
                    {
                        squelette->squelette=loadImage("src/graphics/squelette/TeteSquelette2D.png");
                        Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                    }
                    if (squelette->CompteurSpriteDegat >= 10 && squelette-> CompteurSpriteDegat < 15)
                    {
                        squelette->squelette=loadImage("src/graphics/squelette/TeteSquelette3D.png");
                        Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                        if (squelette->CompteurSpriteDegat==12)
                    {
                        Mix_VolumeChunk(son->rebond, MIX_MAX_VOLUME);
                        Mix_PlayChannel(5, son->rebond, 0);  
                    }
                    }
                    if (squelette->posmonsx <= 620)
                    {
                        squelette->posmonsx+=1;
                    } 
                }
                //pour demi boucle
                if (squelette->rebond == 4 && squelette->CompteurSpriteDegat == 14)
                {
                    squelette->rebond = 5;
                    squelette->CompteurSpriteDegat = 0;
                }
                else if (squelette->CompteurSpriteDegat == 25 )
                {
                    squelette->CompteurSpriteDegat = 0;
                    squelette->rebond+=1;
                }
                squelette->CompteurSpriteDegat+=1;

                if (Inside_Chevalier_Squelette(joueur,squelette)==1 && joueur->Numattack == 15)
                {
                    squelette->Eattaque = 4;
                    squelette->CompteurSpriteDegat = 0;
                    
                }
                if (Inside_Vol(joueur->xdague,joueur->ydague,squelette->posmonsx+25,squelette->posmonsy+25,43,65,30,15)==1)
                {
                    squelette->Eattaque = 4;
                    squelette->CompteurSpriteDegat = 0;
                }
                
                

        }
        else if (squelette->Eattaque == 3 && squelette->rebond >4)
        {
            if (squelette->Direction == 0)
            {
                if (squelette->CompteurSpriteDegat >= 0 && squelette->CompteurSpriteDegat <10)
                {
                    squelette->squelette=loadImage("src/graphics/squelette/SqueletteMort5G.png");
                    Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                }
                if (squelette->CompteurSpriteDegat >= 10 && squelette->CompteurSpriteDegat <20)
                {
                    squelette->squelette=loadImage("src/graphics/squelette/SqueletteMort4G.png");
                    Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                }
                if (squelette->CompteurSpriteDegat >= 20 && squelette->CompteurSpriteDegat <30)
                {
                    squelette->squelette=loadImage("src/graphics/squelette/SqueletteMort3G.png");
                    Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                }
                if (squelette->CompteurSpriteDegat >=30 && squelette->CompteurSpriteDegat <40)
                {
                    squelette->squelette=loadImage("src/graphics/squelette/SqueletteMort2G.png");
                    Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                }
                if (squelette->CompteurSpriteDegat >= 40 && squelette->CompteurSpriteDegat <=50)
                {
                    squelette->squelette=loadImage("src/graphics/squelette/SqueletteMort1G.png");
                    Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                }
            }
            if (squelette->Direction == 1)
            {
                if (squelette->CompteurSpriteDegat >= 0 && squelette->CompteurSpriteDegat <10)
                {
                    squelette->squelette=loadImage("src/graphics/squelette/SqueletteMort5D.png");
                    Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                }
                if (squelette->CompteurSpriteDegat >= 10 && squelette->CompteurSpriteDegat <20)
                {
                    squelette->squelette=loadImage("src/graphics/squelette/SqueletteMort4D.png");
                    Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                }
                if (squelette->CompteurSpriteDegat >=20 && squelette->CompteurSpriteDegat <30)
                {
                    squelette->squelette=loadImage("src/graphics/squelette/SqueletteMort3D.png");
                    Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                }
                if (squelette->CompteurSpriteDegat >= 30 && squelette->CompteurSpriteDegat <40)
                {
                    squelette->squelette=loadImage("src/graphics/squelette/SqueletteMort2D.png");
                    Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                }
                if (squelette->CompteurSpriteDegat >= 40 && squelette-> CompteurSpriteDegat <=50)
                {
                    squelette->squelette=loadImage("src/graphics/squelette/SqueletteMort1D.png");
                    Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                }
            }
            if (squelette->CompteurSpriteDegat < 50)
            {
            squelette->CompteurSpriteDegat+=1;
            }
            else
            {
                squelette->CompteurSpriteDegat = 0 ;
                squelette->Life = 3;
                squelette->Eattaque = 0;
                squelette->rebond = 0;
            }
        }
        else if (squelette->Eattaque == 4)
        {
            if (squelette->Direction == 0)
            {
                if (squelette->CompteurSpriteDegat >= 0 && squelette->CompteurSpriteDegat <10)
                {
                    squelette->squelette=loadImage("src/graphics/squelette/SqueletteCraneMort1G.png");
                    Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                }
                if (squelette->CompteurSpriteDegat >= 10 && squelette->CompteurSpriteDegat <20)
                {
                    squelette->squelette=loadImage("src/graphics/squelette/SqueletteCraneMort2G.png");
                    Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                }
                if (squelette->CompteurSpriteDegat >= 20 && squelette->CompteurSpriteDegat <=30)
                {
                    squelette->squelette=loadImage("src/graphics/squelette/SqueletteCraneMort3G.png");
                    Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                }
            }
            if (squelette->Direction == 1)
            {
                if (squelette->CompteurSpriteDegat >= 0 && squelette->CompteurSpriteDegat <10)
                {
                    squelette->squelette=loadImage("src/graphics/squelette/SqueletteCraneMort1D.png");
                    Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                }
                if (squelette->CompteurSpriteDegat >= 10 && squelette->CompteurSpriteDegat <20)
                {
                    squelette->squelette=loadImage("src/graphics/squelette/SqueletteCraneMort2D.png");
                    Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                }
                if (squelette->CompteurSpriteDegat >= 20 && squelette->CompteurSpriteDegat <=30)
                {
                    squelette->squelette=loadImage("src/graphics/squelette/SqueletteCraneMort3D.png");
                    Draw_Image(squelette->squelette,squelette->posmonsx,squelette->posmonsy);
                }
            }
            if (squelette->CompteurSpriteDegat <30)
            {
                squelette->CompteurSpriteDegat +=1;
            } 
            if (squelette->CompteurSpriteDegat == 29)
            {
                lvl->MortMonstre+=1;
            }
            
        }
        //coup joueur
        if (squelette->coup!=0)
        {
            squelette->coup+=1;
        }
        if (squelette->coup>15)
        {
            squelette->coup = 0;
        }   
    }
}

void Sprite_Boss_Jerem(Joueur *joueur, Jerem_Boss *jerem, Lvl *lvl)
{
    if (jerem->jeremy != NULL)
    {
        SDL_DestroyTexture(jerem->jeremy);
        jerem->jeremy = NULL;
    }
    if (jerem->haltère != NULL)
    {
        SDL_DestroyTexture(jerem->haltère);
        jerem->haltère = NULL;
    }
    if (jerem->ombre != NULL)
    {
        SDL_DestroyTexture(jerem->ombre);
        jerem->ombre = NULL;
    }
    if (jerem->fissure != NULL)
    {
        SDL_DestroyTexture(jerem->fissure);
        jerem->fissure = NULL;
    }
    //Degats sur jerem
    if (jerem->Life != 0 && jerem->Eattaque == 0 && jerem->CompteurSprite2 == 0)
    {
        if (Inside_Chevalier_Boss_Jerem(joueur,jerem) == 1 && joueur->Numattack == 15)
        {
            jerem->Life--;
            jerem->CompteurSprite2+=1;
        }
        if (Inside_Vol(joueur->xdague,joueur->ydague,jerem->posmonsx,jerem->posmonsy,84,91,30,15)==1 && jerem->Transformation == 0)
        {
            jerem->Life--;
            jerem->CompteurSprite2+=1;
        }
        if (Inside_Vol(joueur->xdague,joueur->ydague,jerem->posmonsx,jerem->posmonsy,93,105,30,15)==1&& jerem->Transformation == 1)
        {
            jerem->Life--;
            jerem->CompteurSprite2+=1;
        }
        if (Inside_Vol(joueur->xdague,joueur->ydague,jerem->posmonsx,jerem->posmonsy,107,120,30,15)==1&& jerem->Transformation == 2)
        {
            jerem->Life--;
            jerem->CompteurSprite2+=1;
        }
        
        
        
        
    }
    //reset degats jerem
    if (jerem->CompteurSprite2 != 0 && !(jerem->Life <=20 && jerem->Transformation == 0) && !(jerem->Life <=10 && jerem->Transformation == 1) && jerem->Life != 0)
    {
        jerem->CompteurSprite2+=1;
        if (jerem->CompteurSprite2 >=20)
        {
            jerem->CompteurSprite2=0;
        }
    }

    if (jerem->Life >20 )
    {
        if(jerem->Eattaque == 0)
        {
            if (jerem->CompteurSprite2==0)
            {
                if (jerem->Direction==0)
                {
                    if (jerem->NumSprit>=0 && jerem->NumSprit<5 || jerem->NumSprit>=10 && jerem->NumSprit<15)
                    {
                        jerem->jeremy=loadImage("src/graphics/BossJermy/JeremNeutreD.png");
                        Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                    }
                    if (jerem->NumSprit>=5 && jerem->NumSprit<10)
                    {
                        jerem->jeremy=loadImage("src/graphics/BossJermy/JeremMarche1D.png");
                        Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                    }
                    if (jerem->NumSprit>=15)
                    {
                        jerem->jeremy=loadImage("src/graphics/BossJermy/JeremMarche2D.png");
                        Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                    }  
                }

                if (jerem->Direction==1)
                {
                    if (jerem->NumSprit>=0 && jerem->NumSprit<5 || jerem->NumSprit>=10 && jerem->NumSprit<15)
                    {
                    
                        jerem->jeremy=loadImage("src/graphics/BossJermy/JeremNeutreG.png");
                        Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                    }
                    if (jerem->NumSprit>=5 && jerem->NumSprit<10)
                    {
                        jerem->jeremy=loadImage("src/graphics/BossJermy/JeremMarche1G.png");
                        Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                    }
                    if (jerem->NumSprit>=15)
                    {
                        jerem->jeremy=loadImage("src/graphics/BossJermy/JeremMarche2G.png");
                        Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                    }
                }
                if (jerem->NumSprit>20)
                {
                    jerem->NumSprit = 0;
                }
            } 
            else if (jerem->Direction == 0)
            {
                jerem->jeremy=loadImage("src/graphics/BossJermy/JeremDegatD.png");
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
            else
            {
                jerem->jeremy=loadImage("src/graphics/BossJermy/JeremDegatG.png");
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
            
        }
        //attaque haltère phase 1
        if (jerem->Eattaque == 1 && jerem->CompteurSprite2 == 0)
        {
            if (jerem->Direction==1)
            {            
                if (jerem->NumSprit>=0 && jerem->NumSprit<5)
                {   
                    jerem->jeremy=loadImage("src/graphics/BossJermy/JeremHaltere1G.png");
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }
                if (jerem->NumSprit>=5 && jerem->NumSprit<10)
                {
                    jerem->jeremy=loadImage("src/graphics/BossJermy/JeremHaltere2G.png");
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }
                if (jerem->NumSprit>=10 && jerem->NumSprit<20)
                {   
                    jerem->jeremy=loadImage("src/graphics/BossJermy/JeremHaltere3G.png");
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);    
                }
                if (jerem->NumSprit>=20 && jerem->NumSprit<30)
                {                
                    jerem->jeremy=loadImage("src/graphics/BossJermy/JeremHaltere4G.png");                    
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }
                if (jerem->NumSprit>=30 && jerem->NumSprit<35)
                {                
                    jerem->jeremy=loadImage("src/graphics/BossJermy/JeremHaltere5G.png");                    
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                    if (jerem->NumSprit == 32)
                    {
                        jerem->Ehaltère = 1;
                        jerem->Direction_haltère=jerem->Direction;
                        jerem->xhaltère=jerem->posmonsx;
                        jerem->yhaltère=jerem->posmonsy;
                    }
                }
                if (jerem->NumSprit>=35 && jerem->NumSprit<40)
                {                
                    jerem->jeremy=loadImage("src/graphics/BossJermy/JeremHaltere6G.png");                    
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }
                if (jerem->NumSprit>=40)
                {                
                    jerem->jeremy=loadImage("src/graphics/BossJermy/JeremHaltere7G.png");                    
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }
                
            }

            if (jerem->Direction==0)
            {             
                if (jerem->NumSprit>=0 && jerem->NumSprit<5)
                {   
                    jerem->jeremy=loadImage("src/graphics/BossJermy/JeremHaltere1D.png");
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }
                if (jerem->NumSprit>=5 && jerem->NumSprit<10)
                {
                    jerem->jeremy=loadImage("src/graphics/BossJermy/JeremHaltere2D.png");
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }
                if (jerem->NumSprit>=10 && jerem->NumSprit<20)
                {   
                    jerem->jeremy=loadImage("src/graphics/BossJermy/JeremHaltere3D.png");
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);    
                }
                if (jerem->NumSprit>=20 && jerem->NumSprit<30)
                {                
                    jerem->jeremy=loadImage("src/graphics/BossJermy/JeremHaltere4D.png");                    
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }
                if (jerem->NumSprit>=30 && jerem->NumSprit<35)
                {                
                    jerem->jeremy=loadImage("src/graphics/BossJermy/JeremHaltere5D.png");                    
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                    if (jerem->NumSprit == 32)
                    {
                        jerem->Ehaltère = 1;
                        jerem->Direction_haltère=jerem->Direction;
                        jerem->xhaltère=jerem->posmonsx;
                        jerem->yhaltère=jerem->posmonsy;
                    }
                }
                if (jerem->NumSprit>=35 && jerem->NumSprit<40)
                {                
                    jerem->jeremy=loadImage("src/graphics/BossJermy/JeremHaltere6D.png");                    
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }
                if (jerem->NumSprit>=40)
                {                
                    jerem->jeremy=loadImage("src/graphics/BossJermy/JeremHaltere7D.png");                    
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }
            }
        }
        
        
    } 
    //trasnformation 1
    else if (jerem->Life <=20 && jerem->Transformation == 0 && jerem->Life != 0)
    {
        jerem->cin = 1;
        if (jerem->Direction == 0)
        {
            if (jerem->CompteurSprite2<10)
            {                
                jerem->jeremy=loadImage("src/graphics/BossJermy/JeremTransfo1D.png");                    
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
            if (jerem->CompteurSprite2>=10 && jerem->CompteurSprite2<20)
            {                
                jerem->jeremy=loadImage("src/graphics/BossJermy/JeremTransfo2D.png");                    
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
            if (jerem->CompteurSprite2>=20 && jerem->CompteurSprite2<40)
            {                
                jerem->jeremy=loadImage("src/graphics/BossJermy/JeremTransfo3D.png");                    
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
            if (jerem->CompteurSprite2>=40 && jerem->CompteurSprite2<50)
            {                
                jerem->jeremy=loadImage("src/graphics/BossJermy/JeremTransfo4D.png");                    
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
            if (jerem->CompteurSprite2>=50)
            {                
                jerem->jeremy=loadImage("src/graphics/BossJermy/JeremTransfo5D.png");                    
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
        }
        if (jerem->Direction == 1)
        {
            if (jerem->CompteurSprite2>=0 && jerem->CompteurSprite2<10)
            {                
                jerem->jeremy=loadImage("src/graphics/BossJermy/JeremTransfo1G.png");                    
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
            if (jerem->CompteurSprite2>=10 && jerem->CompteurSprite2<20)
            {                
                jerem->jeremy=loadImage("src/graphics/BossJermy/JeremTransfo2G.png");                    
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
            if (jerem->CompteurSprite2>=20 &&jerem->CompteurSprite2<40)
            {                
                jerem->jeremy=loadImage("src/graphics/BossJermy/JeremTransfo3G.png");                    
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
            if (jerem->CompteurSprite2>=40 && jerem->CompteurSprite2<50)
            {                
                jerem->jeremy=loadImage("src/graphics/BossJermy/JeremTransfo4G.png");                    
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
            if (jerem->CompteurSprite2>=50)
            {                
                jerem->jeremy=loadImage("src/graphics/BossJermy/JeremTransfo5G.png");                    
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
        }
        jerem->CompteurSprite2+=1;
        if (jerem->CompteurSprite2 >= 60)
        {
            jerem->Transformation = 1;
            jerem->NumSprit = 0;
            jerem->CompteurSprite2 = 0;
            jerem->cin = 0;
        }
        
    }
    else if (jerem->Life >10 && jerem->Transformation == 1 && jerem->Life != 0)
    {
        //marche phase 2
        if(jerem->Eattaque == 0)
        {
            if (jerem->CompteurSprite2==0)
            {
                if (jerem->Direction==0)
                {
                    if (jerem->NumSprit>=0 && jerem->NumSprit<5 || jerem->NumSprit>=10 && jerem->NumSprit<15)
                    {
                        jerem->jeremy=loadImage("src/graphics/BossJermy/2JeremNeutreD.png");
                        Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                    }
                    if (jerem->NumSprit>=5 && jerem->NumSprit<10)
                    {
                        jerem->jeremy=loadImage("src/graphics/BossJermy/2JeremMarche1D.png");
                        Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                    }
                    if (jerem->NumSprit>=15)
                    {
                        jerem->jeremy=loadImage("src/graphics/BossJermy/2JeremMarche2D.png");
                        Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                    }  
                }

                if (jerem->Direction==1)
                {
                    if (jerem->NumSprit>=0 && jerem->NumSprit<5 || jerem->NumSprit>=10 && jerem->NumSprit<15)
                    {
                    
                        jerem->jeremy=loadImage("src/graphics/BossJermy/2JeremNeutreG.png");
                        Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                    }
                    if (jerem->NumSprit>=5 && jerem->NumSprit<10)
                    {
                        jerem->jeremy=loadImage("src/graphics/BossJermy/2JeremMarche1G.png");
                        Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                    }
                    if (jerem->NumSprit>=15)
                    {
                        jerem->jeremy=loadImage("src/graphics/BossJermy/2JeremMarche2G.png");
                        Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                    }
                }
                if (jerem->NumSprit>20)
                {
                    jerem->NumSprit = 0;
                }
            } 
            else if (jerem->Direction == 0)
            {
                jerem->jeremy=loadImage("src/graphics/BossJermy/2JeremDegatD.png");
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
            else
            {
                jerem->jeremy=loadImage("src/graphics/BossJermy/2JeremDegatG.png");
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
        }
        //attaque haltère phase 2
        if (jerem->Eattaque == 1)
        {
            if (jerem->Direction==1)
            {            
                if (jerem->NumSprit>=0 && jerem->NumSprit<5)
                {   
                    jerem->jeremy=loadImage("src/graphics/BossJermy/2JeremHaltere1G.png");
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }
                if (jerem->NumSprit>=5 && jerem->NumSprit<10)
                {
                    jerem->jeremy=loadImage("src/graphics/BossJermy/2JeremHaltere2G.png");
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }
                if (jerem->NumSprit>=10 && jerem->NumSprit<20)
                {   
                    jerem->jeremy=loadImage("src/graphics/BossJermy/2JeremHaltere3G.png");
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);    
                }
                if (jerem->NumSprit>=20 && jerem->NumSprit<30)
                {                
                    jerem->jeremy=loadImage("src/graphics/BossJermy/2JeremHaltere4G.png");                    
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }
                if (jerem->NumSprit>=30 && jerem->NumSprit<35)
                {                
                    jerem->jeremy=loadImage("src/graphics/BossJermy/2JeremHaltere5G.png");                    
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                    if (jerem->NumSprit == 32)
                    {
                        jerem->Ehaltère = 1;
                        jerem->Direction_haltère=jerem->Direction;
                        jerem->xhaltère=jerem->posmonsx;
                        jerem->yhaltère=jerem->posmonsy;
                    }
                }
                if (jerem->NumSprit>=35 && jerem->NumSprit<40)
                {                
                    jerem->jeremy=loadImage("src/graphics/BossJermy/2JeremHaltere6G.png");                    
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }
                if (jerem->NumSprit>=40)
                {                
                    jerem->jeremy=loadImage("src/graphics/BossJermy/2JeremHaltere7G.png");                    
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }
                
            }

            if (jerem->Direction==0)
            {             
                if (jerem->NumSprit>=0 && jerem->NumSprit<5)
                {   
                    jerem->jeremy=loadImage("src/graphics/BossJermy/2JeremHaltere1D.png");
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }
                if (jerem->NumSprit>=5 && jerem->NumSprit<10)
                {
                    jerem->jeremy=loadImage("src/graphics/BossJermy/2JeremHaltere2D.png");
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }
                if (jerem->NumSprit>=10 && jerem->NumSprit<20)
                {   
                    jerem->jeremy=loadImage("src/graphics/BossJermy/2JeremHaltere3D.png");
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);    
                }
                if (jerem->NumSprit>=20 && jerem->NumSprit<30)
                {                
                    jerem->jeremy=loadImage("src/graphics/BossJermy/2JeremHaltere4D.png");                    
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }
                if (jerem->NumSprit>=30 && jerem->NumSprit<35)
                {                
                    jerem->jeremy=loadImage("src/graphics/BossJermy/2JeremHaltere5D.png");                    
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                    if (jerem->NumSprit == 32)
                    {
                        jerem->Ehaltère = 1;
                        jerem->Direction_haltère=jerem->Direction;
                        jerem->xhaltère=jerem->posmonsx;
                        jerem->yhaltère=jerem->posmonsy;
                    }
                }
                if (jerem->NumSprit>=35 && jerem->NumSprit<40)
                {                
                    jerem->jeremy=loadImage("src/graphics/BossJermy/2JeremHaltere6D.png");                    
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }
                if (jerem->NumSprit>=40)
                {                
                    jerem->jeremy=loadImage("src/graphics/BossJermy/2JeremHaltere7D.png");                    
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }
            }
        }
        //saut et atterissage
        if (jerem->Eattaque == 2 || jerem->Eattaque == 3)
        {
            //init ombre
            if (jerem->NumSprit == 1 && jerem->Eattaque == 2)
            {
                jerem->pos_ombre_x = jerem->posmonsx+5;
                jerem->pos_ombre_y = jerem->posmonsy+93;
            }
            
            //ombre
            if (jerem->NumSprit>=0 && jerem->NumSprit<10 || jerem->NumSprit>=90 && jerem->NumSprit < 110)
            {
                jerem->ombre=loadImage("src/graphics/BossJermy/Ombre1.png");
                Draw_Image(jerem->ombre,jerem->pos_ombre_x,jerem->pos_ombre_y);
            }
            if (jerem->NumSprit>=10 && jerem->NumSprit<20 || jerem->NumSprit >= 70 && jerem->NumSprit < 90)
            {
                jerem->ombre=loadImage("src/graphics/BossJermy/Ombre2.png");
                Draw_Image(jerem->ombre,jerem->pos_ombre_x,jerem->pos_ombre_y);
            }
            if (jerem->NumSprit>=20 && jerem->NumSprit < 30 || jerem->NumSprit >=50 && jerem->NumSprit < 70)
            {
                jerem->ombre=loadImage("src/graphics/BossJermy/Ombre3.png");
                Draw_Image(jerem->ombre,jerem->pos_ombre_x,jerem->pos_ombre_y);
            }  
            if (jerem->NumSprit>=30 && jerem->NumSprit < 50)
            {
                jerem->ombre=loadImage("src/graphics/BossJermy/Ombre4.png");
                Draw_Image(jerem->ombre,jerem->pos_ombre_x,jerem->pos_ombre_y);
            }
            //onde de choc
            if (jerem->NumSprit >= 45 && jerem->NumSprit < 50 && jerem->Eattaque == 3)
            {
                jerem->fissure=loadImage("src/graphics/BossJermy/OndeDeChoc1.png");
                Draw_Image(jerem->fissure,jerem->posmonsx-78,jerem->posmonsy+80);
                if (jerem->NumSprit == 47 && Inside_Vol(jerem->posmonsx-78+63,jerem->posmonsy+80,joueur->inposx,joueur->inposy,64,64,214,58)==1 && jerem->coup == 0)
                {
                    joueur->life--;
                    if (joueur->life != 0)
                    {
                        jerem->coup = 1;
                    }
                }
                
            }
            if (jerem->NumSprit >= 40 && jerem->NumSprit < 45 && jerem->Eattaque == 3)
            {
                jerem->fissure=loadImage("src/graphics/BossJermy/OndeDeChoc2.png");
                Draw_Image(jerem->fissure,jerem->posmonsx-78,jerem->posmonsy+80);
            }
            if (jerem->NumSprit >= 30 && jerem->NumSprit < 40 && jerem->Eattaque == 3)
            {
                jerem->fissure=loadImage("src/graphics/BossJermy/OndeDeChoc3.png");
                Draw_Image(jerem->fissure,jerem->posmonsx-78,jerem->posmonsy+80);   
            }
            //pour 2 et 3
            if ((jerem->NumSprit == 35 || jerem->NumSprit == 42) && jerem->Eattaque == 3 && jerem->coup == 0)
            {
                if (Inside_Vol(jerem->posmonsx-78,jerem->posmonsy+80,joueur->inposx,joueur->inposy,64,64,250,58)==1 && jerem->coup == 0)
                {
                    joueur->life--;
                    if (joueur->life != 0)
                    {
                        jerem->coup = 1;
                    }
                }
                
            }

            if (jerem->Direction==0)
            {
                //jerem
                if (jerem->NumSprit>=0 && jerem->NumSprit<10 || jerem->NumSprit>=50)
                {
                    jerem->jeremy=loadImage("src/graphics/BossJermy/2JeremSaut1D.png");
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }
                if (jerem->NumSprit>=10 && jerem->NumSprit<20 || jerem->NumSprit >= 45 && jerem->NumSprit < 50)
                {
                    jerem->jeremy=loadImage("src/graphics/BossJermy/2JeremSaut2D.png");
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }
                if (jerem->NumSprit>=20 && jerem->NumSprit < 30 || jerem->NumSprit >=40 && jerem->NumSprit < 45)
                {
                    jerem->jeremy=loadImage("src/graphics/BossJermy/2JeremSaut3D.png");
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                    
                }  
                if (jerem->NumSprit>=30 && jerem->NumSprit < 40)
                {
                    jerem->jeremy=loadImage("src/graphics/BossJermy/2JeremSaut4D.png");
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                } 
                

                
            }

            if (jerem->Direction==1)
            {
                if (jerem->NumSprit>=0 && jerem->NumSprit<10 || jerem->NumSprit>=50)
                {
                    jerem->jeremy=loadImage("src/graphics/BossJermy/2JeremSaut1G.png");
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }
                if (jerem->NumSprit>=10 && jerem->NumSprit<20 || jerem->NumSprit >= 45 && jerem->NumSprit < 50)
                {
                    jerem->jeremy=loadImage("src/graphics/BossJermy/2JeremSaut2G.png");
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }
                if (jerem->NumSprit>=20 && jerem->NumSprit < 30 || jerem->NumSprit >=40 && jerem->NumSprit < 45)
                {
                    jerem->jeremy=loadImage("src/graphics/BossJermy/2JeremSaut3G.png");
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }  
                if (jerem->NumSprit>=30 && jerem->NumSprit < 40)
                {
                    jerem->jeremy=loadImage("src/graphics/BossJermy/2JeremSaut4G.png");
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                } 
            }
            



            if (jerem->Eattaque == 2)
            {
                
                if (jerem->NumSprit >= 50)
                {
                    jerem->posmonsy-=25;
                }
                if (jerem->posmonsy+105< 0 && jerem->NumSprit >=130)
                {
                    jerem->Eattaque = 3;
                    jerem->posmonsx = joueur->inposx-15;
                    jerem->posmonsy = joueur->inposy -2066;
                    jerem->pos_ombre_x = jerem->posmonsx;
                    jerem->pos_ombre_y =  joueur->inposy+52;
                }
            }
            else if (jerem->Eattaque == 3)
            {
                if (jerem->NumSprit > 48)
                {
                    jerem->posmonsy+=25;
                }
                if (jerem->NumSprit == 0)
                {
                    jerem->Eattaque =0 ;
                    jerem->compteur =0;
                }
                
            }
        }
    
    }
    //transformation 3
    else if (jerem->Life <=10 && jerem->Transformation == 1 && jerem->Life != 0)
    {
        jerem->cin = 1;
        if (jerem->Direction == 0)
        {
            if (jerem->CompteurSprite2<10)
            {                
                jerem->jeremy=loadImage("src/graphics/BossJermy/2JeremTransfo1D.png");                    
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
            if (jerem->CompteurSprite2>=10 && jerem->CompteurSprite2<20)
            {                
                jerem->jeremy=loadImage("src/graphics/BossJermy/2JeremTransfo2D.png");                    
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
            if (jerem->CompteurSprite2>=20 && jerem->CompteurSprite2<40)
            {                
                jerem->jeremy=loadImage("src/graphics/BossJermy/2JeremTransfo3D.png");                    
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
            if (jerem->CompteurSprite2>=40 && jerem->CompteurSprite2<50)
            {                
                jerem->jeremy=loadImage("src/graphics/BossJermy/2JeremTransfo4D.png");                    
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
            if (jerem->CompteurSprite2>=50)
            {                
                jerem->jeremy=loadImage("src/graphics/BossJermy/2JeremTransfo5D.png");                    
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
        }
        if (jerem->Direction == 1)
        {
            if (jerem->CompteurSprite2>=0 && jerem->CompteurSprite2<10)
            {                
                jerem->jeremy=loadImage("src/graphics/BossJermy/2JeremTransfo1G.png");                    
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
            if (jerem->CompteurSprite2>=10 && jerem->CompteurSprite2<20)
            {                
                jerem->jeremy=loadImage("src/graphics/BossJermy/2JeremTransfo2G.png");                    
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
            if (jerem->CompteurSprite2>=20 &&jerem->CompteurSprite2<40)
            {                
                jerem->jeremy=loadImage("src/graphics/BossJermy/2JeremTransfo3G.png");                    
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
            if (jerem->CompteurSprite2>=40 && jerem->CompteurSprite2<50)
            {                
                jerem->jeremy=loadImage("src/graphics/BossJermy/2JeremTransfo4G.png");                    
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
            if (jerem->CompteurSprite2>=50)
            {                
                jerem->jeremy=loadImage("src/graphics/BossJermy/2JeremTransfo5G.png");                    
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
        }
        jerem->CompteurSprite2+=1;
        if (jerem->CompteurSprite2 >= 60)
        {
            jerem->Transformation = 2;
            jerem->NumSprit = 0;
            jerem->CompteurSprite2 = 0;
            jerem->cin = 0;
            lvl->Avancement10 =0;
        }
    }
    //phase 2
    else if (jerem->Life <= 10 && jerem->Transformation == 2 && jerem->Life != 0)
    {
        if(jerem->Eattaque == 0 || jerem->Eattaque == 5)
        {
            if (jerem->CompteurSprite2==0)
            {
                if (jerem->Direction==0)
                {
                    if (jerem->NumSprit>=0 && jerem->NumSprit<5 || jerem->NumSprit>=10 && jerem->NumSprit<15)
                    {
                        jerem->jeremy=loadImage("src/graphics/BossJermy/3JeremNeutreD.png");
                        Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                    }
                    if (jerem->NumSprit>=5 && jerem->NumSprit<10)
                    {
                        jerem->jeremy=loadImage("src/graphics/BossJermy/3JeremMarche1D.png");
                        Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                    }
                    if (jerem->NumSprit>=15)
                    {
                        jerem->jeremy=loadImage("src/graphics/BossJermy/3JeremMarche2D.png");
                        Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                    }  
                }

                if (jerem->Direction==1)
                {
                    if (jerem->NumSprit>=0 && jerem->NumSprit<5 || jerem->NumSprit>=10 && jerem->NumSprit<15)
                    {
                    
                        jerem->jeremy=loadImage("src/graphics/BossJermy/3JeremNeutreG.png");
                        Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                    }
                    if (jerem->NumSprit>=5 && jerem->NumSprit<10)
                    {
                        jerem->jeremy=loadImage("src/graphics/BossJermy/3JeremMarche1G.png");
                        Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                    }
                    if (jerem->NumSprit>=15)
                    {
                        jerem->jeremy=loadImage("src/graphics/BossJermy/3JeremMarche2G.png");
                        Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                    }
                }
                if (jerem->NumSprit>20)
                {
                    jerem->NumSprit = 0;
                }
            } 
            else if (jerem->Direction == 0)
            {
                jerem->jeremy=loadImage("src/graphics/BossJermy/3JeremDegatD.png");
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
            else
            {
                jerem->jeremy=loadImage("src/graphics/BossJermy/3JeremDegatG.png");
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }



            //pousse joueur
            if (jerem->Eattaque == 5)
            {
                if (jerem->Direction_haltère == 0)
                {
                    if (joueur->inposx>=556)
                    {
                        jerem->Eattaque =0;
                        jerem->NumSprit =0;
                        jerem->compteur =0;
                    }
                    else
                    {
                        joueur->inposx +=10;
                    }
                }
                else
                {
                    if (joueur->inposx<=20)
                    {
                        jerem->Eattaque =0;
                        jerem->NumSprit =0;
                        jerem->compteur =0;
                    }
                    else
                    {
                        joueur->inposx -=10;
                    }
                }
            }
            
        }
        //haltère
        if (jerem->Eattaque == 1 && jerem->CompteurSprite2 == 0)
        {
            if (jerem->Direction==1)
            {            
                if (jerem->NumSprit>=0 && jerem->NumSprit<5)
                {   
                    jerem->jeremy=loadImage("src/graphics/BossJermy/3JeremHaltere1G.png");
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }
                if (jerem->NumSprit>=5 && jerem->NumSprit<10)
                {
                    jerem->jeremy=loadImage("src/graphics/BossJermy/3JeremHaltere2G.png");
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }
                if (jerem->NumSprit>=10 && jerem->NumSprit<20)
                {   
                    jerem->jeremy=loadImage("src/graphics/BossJermy/3JeremHaltere3G.png");
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);    
                }
                if (jerem->NumSprit>=20 && jerem->NumSprit<30)
                {                
                    jerem->jeremy=loadImage("src/graphics/BossJermy/3JeremHaltere4G.png");                    
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }
                if (jerem->NumSprit>=30 && jerem->NumSprit<35)
                {                
                    jerem->jeremy=loadImage("src/graphics/BossJermy/3JeremHaltere5G.png");                    
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                    if (jerem->NumSprit == 32)
                    {
                        jerem->Ehaltère = 1;
                        jerem->Direction_haltère=jerem->Direction;
                        jerem->xhaltère=jerem->posmonsx;
                        jerem->yhaltère=jerem->posmonsy;
                    }
                }
                if (jerem->NumSprit>=35 && jerem->NumSprit<40)
                {                
                    jerem->jeremy=loadImage("src/graphics/BossJermy/3JeremHaltere6G.png");                    
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }
                if (jerem->NumSprit>=40)
                {                
                    jerem->jeremy=loadImage("src/graphics/BossJermy/3JeremHaltere7G.png");                    
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }
                
            }

            if (jerem->Direction==0)
            {             
                if (jerem->NumSprit>=0 && jerem->NumSprit<5)
                {   
                    jerem->jeremy=loadImage("src/graphics/BossJermy/3JeremHaltere1D.png");
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }
                if (jerem->NumSprit>=5 && jerem->NumSprit<10)
                {
                    jerem->jeremy=loadImage("src/graphics/BossJermy/3JeremHaltere2D.png");
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }
                if (jerem->NumSprit>=10 && jerem->NumSprit<20)
                {   
                    jerem->jeremy=loadImage("src/graphics/BossJermy/3JeremHaltere3D.png");
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);    
                }
                if (jerem->NumSprit>=20 && jerem->NumSprit<30)
                {                
                    jerem->jeremy=loadImage("src/graphics/BossJermy/3JeremHaltere4D.png");                    
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }
                if (jerem->NumSprit>=30 && jerem->NumSprit<35)
                {                
                    jerem->jeremy=loadImage("src/graphics/BossJermy/3JeremHaltere5D.png");                    
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                    if (jerem->NumSprit == 32)
                    {
                        jerem->Ehaltère = 1;
                        jerem->Direction_haltère=jerem->Direction;
                        jerem->xhaltère=jerem->posmonsx;
                        jerem->yhaltère=jerem->posmonsy;
                    }
                }
                if (jerem->NumSprit>=35 && jerem->NumSprit<40)
                {                
                    jerem->jeremy=loadImage("src/graphics/BossJermy/3JeremHaltere6D.png");                    
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }
                if (jerem->NumSprit>=40)
                {                
                    jerem->jeremy=loadImage("src/graphics/BossJermy/3JeremHaltere7D.png");                    
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }
            }
        }

        //saut et atterissage
        if (jerem->Eattaque == 2 || jerem->Eattaque == 3)
        {
            //init ombre
            if (jerem->NumSprit == 1 && jerem->Eattaque == 2)
            {
                jerem->pos_ombre_x = jerem->posmonsx+5;
                jerem->pos_ombre_y = jerem->posmonsy+107;
            }
            
            //ombre
            if (jerem->NumSprit>=0 && jerem->NumSprit<10 || jerem->NumSprit>=90 && jerem->NumSprit < 110)
            {
                jerem->ombre=loadImage("src/graphics/BossJermy/3Ombre1.png");
                Draw_Image(jerem->ombre,jerem->pos_ombre_x,jerem->pos_ombre_y);
            }
            if (jerem->NumSprit>=10 && jerem->NumSprit<20 || jerem->NumSprit >= 70 && jerem->NumSprit < 90)
            {
                jerem->ombre=loadImage("src/graphics/BossJermy/3Ombre2.png");
                Draw_Image(jerem->ombre,jerem->pos_ombre_x,jerem->pos_ombre_y);
            }
            if (jerem->NumSprit>=20 && jerem->NumSprit < 30 || jerem->NumSprit >=50 && jerem->NumSprit < 70)
            {
                jerem->ombre=loadImage("src/graphics/BossJermy/3Ombre3.png");
                Draw_Image(jerem->ombre,jerem->pos_ombre_x,jerem->pos_ombre_y);
            }  
            if (jerem->NumSprit>=30 && jerem->NumSprit < 50)
            {
                jerem->ombre=loadImage("src/graphics/BossJermy/3Ombre4.png");
                Draw_Image(jerem->ombre,jerem->pos_ombre_x,jerem->pos_ombre_y);
            }
            //onde de choc
            if (jerem->NumSprit >= 45 && jerem->NumSprit < 50 && jerem->Eattaque == 3)
            {
                jerem->fissure=loadImage("src/graphics/BossJermy/3OndeDeChoc1.png");
                Draw_Image(jerem->fissure,jerem->posmonsx-85,jerem->posmonsy+87);
                if (jerem->NumSprit == 47 && Inside_Vol(jerem->posmonsx-85+67,jerem->posmonsy+87,joueur->inposx,joueur->inposy,64,64,250,54)==1)
                    {
                        joueur->life--;
                        if (joueur->life != 0)
                        {
                            jerem->coup = 1;
                        }
                    }
            }
            if (jerem->NumSprit >= 40 && jerem->NumSprit < 45 && jerem->Eattaque == 3)
            {
                jerem->fissure=loadImage("src/graphics/BossJermy/3OndeDeChoc2.png");
                Draw_Image(jerem->fissure,jerem->posmonsx-85,jerem->posmonsy+87);
            }
            if (jerem->NumSprit >= 30 && jerem->NumSprit < 40 && jerem->Eattaque == 3)
            {
                jerem->fissure=loadImage("src/graphics/BossJermy/3OndeDeChoc3.png");
                Draw_Image(jerem->fissure,jerem->posmonsx-85,jerem->posmonsy+87);
            }
            //pour 2 et 3
            if ((jerem->NumSprit == 35 || jerem->NumSprit == 42) && jerem->Eattaque == 3 && jerem->coup == 0)
            {
                if (Inside_Vol(jerem->posmonsx-85+67,jerem->posmonsy+87,joueur->inposx,joueur->inposy,64,64,290,67)==1 && jerem->coup == 0)
                {
                    joueur->life--;
                    if (joueur->life != 0)
                    {
                        jerem->coup = 1;
                    }
                }
                
            }

            if (jerem->Direction==0)
            {
                //jerem
                if (jerem->NumSprit>=0 && jerem->NumSprit<10 || jerem->NumSprit>=50)
                {
                    jerem->jeremy=loadImage("src/graphics/BossJermy/3JeremSaut1D.png");
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }
                if (jerem->NumSprit>=10 && jerem->NumSprit<20 || jerem->NumSprit >= 45 && jerem->NumSprit < 50)
                {
                    jerem->jeremy=loadImage("src/graphics/BossJermy/3JeremSaut2D.png");
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }
                if (jerem->NumSprit>=20 && jerem->NumSprit < 30 || jerem->NumSprit >=40 && jerem->NumSprit < 45)
                {
                    jerem->jeremy=loadImage("src/graphics/BossJermy/3JeremSaut3D.png");
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                    
                }  
                if (jerem->NumSprit>=30 && jerem->NumSprit < 40)
                {
                    jerem->jeremy=loadImage("src/graphics/BossJermy/3JeremSaut4D.png");
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                } 
                

                
            }

            if (jerem->Direction==1)
            {
                if (jerem->NumSprit>=0 && jerem->NumSprit<10 || jerem->NumSprit>=50)
                {
                    jerem->jeremy=loadImage("src/graphics/BossJermy/3JeremSaut1G.png");
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }
                if (jerem->NumSprit>=10 && jerem->NumSprit<20 || jerem->NumSprit >= 45 && jerem->NumSprit < 50)
                {
                    jerem->jeremy=loadImage("src/graphics/BossJermy/3JeremSaut2G.png");
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }
                if (jerem->NumSprit>=20 && jerem->NumSprit < 30 || jerem->NumSprit >=40 && jerem->NumSprit < 45)
                {
                    jerem->jeremy=loadImage("src/graphics/BossJermy/3JeremSaut3G.png");
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }  
                if (jerem->NumSprit>=30 && jerem->NumSprit < 40)
                {
                    jerem->jeremy=loadImage("src/graphics/BossJermy/3JeremSaut4G.png");
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                } 
            }

            if (jerem->Eattaque == 2)
            {
                
                if (jerem->NumSprit >= 50)
                {
                    jerem->posmonsy-=25;
                }
                if (jerem->posmonsy+105< 0 && jerem->NumSprit >=130)
                {
                    jerem->Eattaque = 3;
                    jerem->posmonsx = joueur->inposx-15;
                    jerem->posmonsy = joueur->inposy -2066;
                    jerem->pos_ombre_x = jerem->posmonsx;
                    jerem->pos_ombre_y =  joueur->inposy+64;
                }
            }
            else if (jerem->Eattaque == 3)
            {
                if (jerem->NumSprit > 48)
                {
                    jerem->posmonsy+=25;
                }
                if (jerem->NumSprit == 0)
                {
                    jerem->Eattaque = 0;
                }
                
            }
        }
        else if (jerem->Eattaque == 4)
        {
            if(jerem->Direction == 0)
            {
                if (jerem->NumSprit>=0 && jerem->NumSprit<15)
                {
                    jerem->jeremy=loadImage("src/graphics/BossJermy/3JeremDash1D.png");
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }
                if (jerem->NumSprit>=15 && jerem->NumSprit<30)
                {
                    jerem->jeremy=loadImage("src/graphics/BossJermy/3JeremDash2D.png");
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }
                if (jerem->NumSprit>=30)
                {
                    if (jerem->NumSprit == 30)
                    {
                        //enregistremnt pou effet
                        jerem->xhaltère = jerem->posmonsx;
                        jerem->yhaltère = jerem->posmonsy;
                    }
                    
                    jerem->jeremy=loadImage("src/graphics/BossJermy/3JeremDash3D.png");
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                    if (Inside_Vol(jerem->posmonsx,jerem->posmonsy,joueur->inposx,joueur->inposy,64,64,107,120)==1)
                    {
                        jerem->Eattaque = 5;
                        jerem->Direction_haltère=jerem->Direction;
                        joueur->life --;
                        if (joueur->life != 0)
                        {
                            jerem->coup =1;
                        }
                        
                    }
                    
                    if (jerem->posmonsx<=513)
                    {
                        jerem->posmonsx +=10;
                    }
                    else 
                    {
                        jerem->Eattaque = 0;
                        jerem->compteur = 0;
                    }
                }  
            }
            if (jerem->Direction == 1)
            {
                if (jerem->NumSprit>=0 && jerem->NumSprit<15)
                {
                    jerem->jeremy=loadImage("src/graphics/BossJermy/3JeremDash1G.png");
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }
                if (jerem->NumSprit>=15 && jerem->NumSprit<30)
                {
                    jerem->jeremy=loadImage("src/graphics/BossJermy/3JeremDash2G.png");
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                }
                if (jerem->NumSprit>=30)
                {   
                     if (jerem->NumSprit == 30)
                    {
                        //enregistremnt pou effet
                        jerem->xhaltère = jerem->posmonsx+120;
                        jerem->yhaltère = jerem->posmonsy;
                    }
                    jerem->jeremy=loadImage("src/graphics/BossJermy/3JeremDash3G.png");
                    Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
                    if (Inside_Vol(jerem->posmonsx,jerem->posmonsy,joueur->inposx,joueur->inposy,64,64,107,120)==1)
                    {
                        jerem->Eattaque = 5;
                        jerem->Direction_haltère=jerem->Direction;
                        joueur->life --;
                        if (joueur->life != 0)
                        {
                            jerem->coup =1;
                        }
                        
                    }
                    
                    if (jerem->posmonsx>=20)
                    {
                        jerem->posmonsx -=10;
                    }
                    else 
                    {
                        jerem->Eattaque = 0;
                        jerem->compteur = 0;
                    }
                }
            }
        }
        
        if (jerem->Eattaque == 4 || jerem->Eattaque == 5)
        {
            if(jerem->Direction == 0)
            {
                if (jerem->NumSprit>=30 && jerem->NumSprit<35)
                {
                    jerem->fissure=loadImage("src/graphics/BossJermy/3JeremDashEffet1D.png");
                    Draw_Image(jerem->fissure,jerem->xhaltère-49,jerem->yhaltère);
                }
                if (jerem->NumSprit>=35 && jerem->NumSprit<40)
                {
                    jerem->fissure=loadImage("src/graphics/BossJermy/3JeremDashEffet2D.png");
                    Draw_Image(jerem->fissure,jerem->xhaltère-49,jerem->yhaltère);
                }
                if (jerem->NumSprit>=40 && jerem->NumSprit<45)
                {
                    jerem->fissure=loadImage("src/graphics/BossJermy/3JeremDashEffet3D.png");
                    Draw_Image(jerem->fissure,jerem->xhaltère-49,jerem->yhaltère);
                }
            }
            if(jerem->Direction == 1)
            {
                if (jerem->NumSprit>=30 && jerem->NumSprit<35)
                {
                    jerem->fissure=loadImage("src/graphics/BossJermy/3JeremDashEffet1G.png");
                    Draw_Image(jerem->fissure,jerem->xhaltère+107,jerem->yhaltère);
                }
                if (jerem->NumSprit>=35 && jerem->NumSprit<40)
                {
                    jerem->fissure=loadImage("src/graphics/BossJermy/3JeremDashEffet2G.png");
                    Draw_Image(jerem->fissure,jerem->xhaltère+107,jerem->yhaltère);
                }
                if (jerem->NumSprit>=40 && jerem->NumSprit<45)
                {
                    jerem->fissure=loadImage("src/graphics/BossJermy/3JeremDashEffet3G.png");
                    Draw_Image(jerem->fissure,jerem->xhaltère+107,jerem->yhaltère);
                }
            }
        }

        
    }
    else if (jerem->Life == 0)
    {
        if (jerem->CompteurSprite2 < 100)
        {
            jerem->CompteurSprite2+=1;
        }
        if (jerem->Direction == 0)
        {
            if (jerem->CompteurSprite2>=0 && jerem->CompteurSprite2<10)
            {
                jerem->jeremy=loadImage("src/graphics/BossJermy/JeremMort1D.png");   
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
            if (jerem->CompteurSprite2>=10 && jerem->CompteurSprite2<20)
            {
                jerem->jeremy=loadImage("src/graphics/BossJermy/JeremMort2D.png");   
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
            if (jerem->CompteurSprite2>=20 && jerem->CompteurSprite2<30)
            {
                jerem->jeremy=loadImage("src/graphics/BossJermy/JeremMort3D.png");   
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
            if (jerem->CompteurSprite2>=30 && jerem->CompteurSprite2<40)
            {
                jerem->jeremy=loadImage("src/graphics/BossJermy/JeremMort4D.png");   
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
            if (jerem->CompteurSprite2>=40 && jerem->CompteurSprite2<50)
            {
                jerem->jeremy=loadImage("src/graphics/BossJermy/JeremMort5D.png");   
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
            if (jerem->CompteurSprite2>=50 && jerem->CompteurSprite2<60)
            {
                jerem->jeremy=loadImage("src/graphics/BossJermy/JeremMort6D.png");   
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
            if (jerem->CompteurSprite2>=60 && jerem->CompteurSprite2<70)
            {
                jerem->jeremy=loadImage("src/graphics/BossJermy/JeremMort7D.png");   
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
            if (jerem->CompteurSprite2>=70 && jerem->CompteurSprite2<80)
            {
                jerem->jeremy=loadImage("src/graphics/BossJermy/JeremMort8D.png");   
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
            if (jerem->CompteurSprite2>=80 && jerem->CompteurSprite2<90)
            {
                jerem->jeremy=loadImage("src/graphics/BossJermy/JeremMort9D.png");   
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
            if (jerem->CompteurSprite2>=90 && jerem->CompteurSprite2<=100)
            {
                jerem->jeremy=loadImage("src/graphics/BossJermy/JeremMort10D.png");   
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
        }
        if (jerem->Direction == 1)
        {
            if (jerem->CompteurSprite2>=0 && jerem->CompteurSprite2<10)
            {
                jerem->jeremy=loadImage("src/graphics/BossJermy/JeremMort1G.png");   
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
            if (jerem->CompteurSprite2>=10 && jerem->CompteurSprite2<20)
            {
                jerem->jeremy=loadImage("src/graphics/BossJermy/JeremMort2G.png");   
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
            if (jerem->CompteurSprite2>=20 && jerem->CompteurSprite2<30)
            {
                jerem->jeremy=loadImage("src/graphics/BossJermy/JeremMort3G.png");   
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
            if (jerem->CompteurSprite2>=30 && jerem->CompteurSprite2<40)
            {
                jerem->jeremy=loadImage("src/graphics/BossJermy/JeremMort4G.png");   
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
            if (jerem->CompteurSprite2>=40 && jerem->CompteurSprite2<50)
            {
                jerem->jeremy=loadImage("src/graphics/BossJermy/JeremMort5G.png");   
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
            if (jerem->CompteurSprite2>=50 && jerem->CompteurSprite2<60)
            {
                jerem->jeremy=loadImage("src/graphics/BossJermy/JeremMort6G.png");   
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
            if (jerem->CompteurSprite2>=60 && jerem->CompteurSprite2<70)
            {
                jerem->jeremy=loadImage("src/graphics/BossJermy/JeremMort7G.png");   
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
            if (jerem->CompteurSprite2>=70 && jerem->CompteurSprite2<80)
            {
                jerem->jeremy=loadImage("src/graphics/BossJermy/JeremMort8G.png");   
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
            if (jerem->CompteurSprite2>=80 && jerem->CompteurSprite2<90)
            {
                jerem->jeremy=loadImage("src/graphics/BossJermy/JeremMort9G.png");   
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
            if (jerem->CompteurSprite2>=90 && jerem->CompteurSprite2<=100)
            {
                jerem->jeremy=loadImage("src/graphics/BossJermy/JeremMort10G.png");   
                Draw_Image(jerem->jeremy,jerem->posmonsx,jerem->posmonsy);
            }
        } 
        if (jerem->CompteurSprite2 == 99)
        {
            lvl->MortMonstre+=1;
        }
        
    }

    //gestion haltère
    if (jerem->Ehaltère == 1)
    {
        if (jerem->xhaltère>=20 && jerem->xhaltère<=600 && jerem->yhaltère>= 20 && jerem->yhaltère<=384)
        {
            if(jerem->Transformation == 2)
            {
                jerem->haltère=loadImage("src/graphics/BossJermy/3Haltere.png");   
                Draw_Image(jerem->haltère,jerem->xhaltère,jerem->yhaltère);
                if (Inside_Vol(jerem->xhaltère, jerem->yhaltère,joueur->inposx,joueur->inposy,64,64,16,45)==1 && jerem->coup == 0)
                {
                    joueur->life--;
                    if (joueur->life != 0)
                    {
                        jerem->coup=1;
                    }
                }    
            }
            else
            {
                jerem->haltère=loadImage("src/graphics/BossJermy/Haltere.png");   
                Draw_Image(jerem->haltère,jerem->xhaltère,jerem->yhaltère);
                if (Inside_Vol(jerem->xhaltère, jerem->yhaltère,joueur->inposx,joueur->inposy,64,64,12,34)==1 && jerem->coup == 0)
                {
                    joueur->life--;
                    if (joueur->life != 0)
                    {
                        jerem->coup=1;
                    }
                }
            }

            if (jerem->Direction_haltère == 1)
            {
                jerem->xhaltère-=9;
            }
            if (jerem->Direction_haltère == 0)
            {
                jerem->xhaltère+=9;
            }
        }
        else 
        {
            jerem->Ehaltère = 0;
        }
    }
    
    if (jerem->coup != 0)
    {
        jerem->coup+=1;
    }
    if (jerem->coup > 15)
    {
        jerem->coup = 0;
    }

}
