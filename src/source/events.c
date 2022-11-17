#include "../header/proto.h"

//collision entre le joueur et les murs // haut ,bas ,gauche, droite
void collisionmur (Joueur *joueur, int x, int y, int z, int u)
{
    //mur du haut
    if (joueur->inposy <= x)
    {
        joueur->inposy+=3;
    }
    //mur du bas
    if (joueur->inposy >= SCREEN_HEIGHT-SPRITE_SIZE-y)
    {
        joueur->inposy-=3;
    }
    //mur de gauche
    if (joueur->inposx <= z)
    {
        joueur->inposx+=3;
    }
    //mur de droite
     if (joueur->inposx >= SCREEN_WIDTH-SPRITE_SIZE-u)
    {
        joueur->inposx-=3;
    }
}

 //collision entre les meduse et joueur
void collision (Joueur *joueur, Meduse *meduse, Input *input, Lvl *lvl)
{
   //collision haut joueur
    if (meduse->Life!=0)
    {
        if (((joueur->inposy <= meduse->posmonsy + SPRITE_SIZE)&&(joueur->inposy >= meduse->posmonsy )) && (((meduse->posmonsx >= joueur->inposx) && (meduse->posmonsx <= joueur->inposx+SPRITE_SIZE)) || ((meduse->posmonsx + SPRITE_SIZE >= joueur->inposx) && (meduse->posmonsx + SPRITE_SIZE <= joueur->inposx+SPRITE_SIZE))))
        {
            meduse->posmonsy-=1;
            if (input->up == 1)
            {
                joueur->inposy+=3;  
            }
        }
        
        //collision bas joueur
        if (((joueur->inposy + SPRITE_SIZE >= meduse->posmonsy) && (joueur->inposy <= meduse->posmonsy)) && (((meduse->posmonsx >= joueur->inposx) && (meduse->posmonsx <= joueur->inposx+SPRITE_SIZE)) || ((meduse->posmonsx + SPRITE_SIZE >= joueur->inposx) && (meduse->posmonsx + SPRITE_SIZE <= joueur->inposx+SPRITE_SIZE))))
        {
            meduse->posmonsy+=1;
            if (input->down == 1)
            {
                joueur->inposy-=3;  
            }   
        }
    
        // //coter droit joueur
        if (joueur->inposx <= meduse->posmonsx)
        {
            if (joueur->inposx + SPRITE_SIZE >= meduse->posmonsx-3)
            {
                ("condition 2 \n");
                if ((meduse->posmonsy >= joueur->inposy) && (meduse->posmonsy <= joueur->inposy+SPRITE_SIZE))
                {
                    meduse->posmonsx+=1;
                    if (input->right == 1)
                    {
                        joueur->inposx-=3;  
                    }   
                }

                if ((meduse->posmonsy + SPRITE_SIZE >= joueur->inposy) && (meduse->posmonsy + SPRITE_SIZE <= joueur->inposy + SPRITE_SIZE))
                {
                    meduse->posmonsx+=1;
                    if (input->right == 1)
                    {
                        joueur->inposx-=3;  
                    }  
                }
            }  
        }
        
        //coter gauche joueur
        if (joueur->inposx + SPRITE_SIZE >= meduse->posmonsx)
        {

            if (joueur->inposx <= meduse->posmonsx + SPRITE_SIZE)
            {

                if (meduse->posmonsy >= joueur->inposy && meduse->posmonsy <= joueur->inposy+SPRITE_SIZE)
                {

                    meduse->posmonsx-=1;
                    if (input->left == 1)
                    {
                        joueur->inposx+=3;  
                    }
                }
                if (meduse->posmonsy + SPRITE_SIZE >= joueur->inposy && meduse->posmonsy + SPRITE_SIZE <= joueur->inposy + SPRITE_SIZE)
                {

                    meduse->posmonsx-=1;
                    if (input->left == 1)
                    {
                        joueur->inposx+=3;  
                    }
                }
            }
        }
    }
}

//collision entre le boss et joueur
void collisionboss (Joueur *joueur, Boss *boss, Input *input, Lvl *lvl)
{  
    if (boss->Life!=0)
    {   //collision haut joueur
        if((joueur->inposx>=boss->posmonsx && joueur->inposx<=boss->posmonsx+128 )||(joueur->inposx+SPRITE_SIZE>=boss->posmonsx && joueur->inposx+SPRITE_SIZE<=boss->posmonsx+128 )||((joueur->inposx>=boss->posmonsx && joueur->inposx<=boss->posmonsx+128 )&&(joueur->inposx+SPRITE_SIZE>=boss->posmonsx && joueur->inposx+SPRITE_SIZE<=boss->posmonsx+128 )))
        {
            if ((joueur->inposy <= boss->posmonsy + 128)&&(joueur->inposy >= boss->posmonsy ))
            {
                boss->posmonsy-=1;
                if (input->up == 1)
                {
                    joueur->inposy+=3;  
                }
            }
        }
        
        //collision bas joueur
        if((joueur->inposx>=boss->posmonsx && joueur->inposx<=boss->posmonsx+128 )||(joueur->inposx+SPRITE_SIZE>=boss->posmonsx && joueur->inposx+SPRITE_SIZE<=boss->posmonsx+128 )||((joueur->inposx>=boss->posmonsx && joueur->inposx<=boss->posmonsx+128 )&&(joueur->inposx+SPRITE_SIZE>=boss->posmonsx && joueur->inposx+SPRITE_SIZE<=boss->posmonsx+128 )))
        {
            if ((joueur->inposy+SPRITE_SIZE <= boss->posmonsy + 128)&&(joueur->inposy+SPRITE_SIZE >= boss->posmonsy ))        
            {
                boss->posmonsy+=1;
                if (input->down == 1)
                {
                    joueur->inposy-=3;  
                }   
            }
        }
    
        // //coter droit joueur
        if((joueur->inposy>=boss->posmonsy && joueur->inposy<=boss->posmonsy+128 )||(joueur->inposy+SPRITE_SIZE>=boss->posmonsy && joueur->inposy+SPRITE_SIZE<=boss->posmonsy+128 )||((joueur->inposy>=boss->posmonsy && joueur->inposy<=boss->posmonsy+128 )&&(joueur->inposy+SPRITE_SIZE>=boss->posmonsy && joueur->inposy+SPRITE_SIZE<=boss->posmonsy+128 )))
        {
            if ((joueur->inposx+SPRITE_SIZE <= boss->posmonsx + 128)&&(joueur->inposx+SPRITE_SIZE >= boss->posmonsx ))
            {
                boss->posmonsx+=1;
                if (input->right == 1)
                {
                    joueur->inposx-=3;  
                }   
            }
        }
        
        // //coter gauche joueur
        if((joueur->inposy>=boss->posmonsy && joueur->inposy<=boss->posmonsy+128 )||(joueur->inposy+SPRITE_SIZE>=boss->posmonsy && joueur->inposy+SPRITE_SIZE<=boss->posmonsy+128 )||((joueur->inposy>=boss->posmonsy && joueur->inposy<=boss->posmonsy+128 )&&(joueur->inposy+SPRITE_SIZE>=boss->posmonsy && joueur->inposy+SPRITE_SIZE<=boss->posmonsy+128 )))
        {
            if ((joueur->inposx <= boss->posmonsx + 128)&&(joueur->inposx >= boss->posmonsx ))
            {
                boss->posmonsx-=1;
                if (input->left == 1)
                {
                    joueur->inposx+=3;  
                }
            }
        }
    } 
}

//collision entre le yeti et joueur
void collisionyeti (Joueur *joueur, Yeti *yeti, Input *input, Lvl *lvl)
{  
    if (yeti->Life!=0)
    {   //collision haut joueur
        if((joueur->inposx>=yeti->posmonsx && joueur->inposx<=yeti->posmonsy+80 )||(joueur->inposx+SPRITE_SIZE>=yeti->posmonsx && joueur->inposx+SPRITE_SIZE<=yeti->posmonsy+80 )||((joueur->inposx>=yeti->posmonsx && joueur->inposx<=yeti->posmonsy+80 )&&(joueur->inposx+SPRITE_SIZE>=yeti->posmonsx && joueur->inposx+SPRITE_SIZE<=yeti->posmonsy+80 )))
        {
            if ((joueur->inposy <= yeti->posmonsy+80)&&(joueur->inposy >= yeti->posmonsy+20 ))
            {
                yeti->posmonsy-=1;
                if (input->up == 1)
                {
                    joueur->inposy+=3;  
                }
            }
        }
       
        //collision bas joueur
        if((joueur->inposx>=yeti->posmonsx && joueur->inposx<=yeti->posmonsy+80 )||(joueur->inposx+SPRITE_SIZE>=yeti->posmonsx && joueur->inposx+SPRITE_SIZE<=yeti->posmonsy+80 )||((joueur->inposx>=yeti->posmonsx && joueur->inposx<=yeti->posmonsy+80 )&&(joueur->inposx+SPRITE_SIZE>=yeti->posmonsx && joueur->inposx+SPRITE_SIZE<=yeti->posmonsy+80 )))
        {
            if ((joueur->inposy+SPRITE_SIZE <= yeti->posmonsy+80)&&(joueur->inposy+SPRITE_SIZE >= yeti->posmonsy+20 ))        
            {
                yeti->posmonsy+=1;
                if (input->down == 1)
                {
                    joueur->inposy-=3;  
                }  
            }
        }
   
        // //coter droit joueur
        if((joueur->inposy>=yeti->posmonsy+20&& joueur->inposy<=yeti->posmonsy+80 )||(joueur->inposy+SPRITE_SIZE>=yeti->posmonsy+20&& joueur->inposy+SPRITE_SIZE<=yeti->posmonsy+80 )||((joueur->inposy>=yeti->posmonsy+20&& joueur->inposy<=yeti->posmonsy+80 )&&(joueur->inposy+SPRITE_SIZE>=yeti->posmonsy+20&& joueur->inposy+SPRITE_SIZE<=yeti->posmonsy+80 )))
        {
            if ((joueur->inposx+SPRITE_SIZE <= yeti->posmonsx + 65)&&(joueur->inposx+SPRITE_SIZE >= yeti->posmonsx ))
            {
                yeti->posmonsx+=1;
                if (input->right == 1)
                {
                    joueur->inposx-=3;  
                }  
            }
        }
       
        // //coter gauche joueur
        if((joueur->inposy>=yeti->posmonsy+20&& joueur->inposy<=yeti->posmonsy+80 )||(joueur->inposy+SPRITE_SIZE>=yeti->posmonsy+20&& joueur->inposy+SPRITE_SIZE<=yeti->posmonsy+80 )||((joueur->inposy>=yeti->posmonsy+20&& joueur->inposy<=yeti->posmonsy+80 )&&(joueur->inposy+SPRITE_SIZE>=yeti->posmonsy+20&& joueur->inposy+SPRITE_SIZE<=yeti->posmonsy+80 )))
        {
            if ((joueur->inposx <= yeti->posmonsx + 65)&&(joueur->inposx >= yeti->posmonsx ))
            {
                yeti->posmonsx-=1;
                if (input->left == 1)
                {
                    joueur->inposx+=3;  
                }
            }
        }
    }
}

void collisionDecor (Joueur *joueur, Input *input, int x1, int x2, int y1, int y2)
{  
    
    //collision haut joueur
    if((joueur->inposx>=x1 && joueur->inposx<=x2 )||(joueur->inposx+SPRITE_SIZE>=x1 && joueur->inposx+SPRITE_SIZE<=x2 )||((joueur->inposx>=x1 && joueur->inposx<=x2 )&&(joueur->inposx+SPRITE_SIZE>=x1 && joueur->inposx+SPRITE_SIZE<=x2 )))
    {
        if ((joueur->inposy <= y1)&&(joueur->inposy >= y2 ))
        {
            if (input->up == 1)
            {
                joueur->inposy+=3;  
            }
        }
    }
    
    //collision bas joueur
    if((joueur->inposx>=x1 && joueur->inposx<=x2 )||(joueur->inposx+SPRITE_SIZE>=x1 && joueur->inposx+SPRITE_SIZE<=x2 )||((joueur->inposx>=x1 && joueur->inposx<=x2 )&&(joueur->inposx+SPRITE_SIZE>=x1 && joueur->inposx+SPRITE_SIZE<=x2 )))
    {
        if ((joueur->inposy+SPRITE_SIZE <= y1)&&(joueur->inposy+SPRITE_SIZE >= y2 ))        
        {
            if (input->down == 1)
            {
                joueur->inposy-=3;  
            }   
        }
    }

    // //coter droit joueur
    if((joueur->inposy>=y2 && joueur->inposy<=y1 )||(joueur->inposy+SPRITE_SIZE>=y2 && joueur->inposy+SPRITE_SIZE<=y1 )||((joueur->inposy>=y2 && joueur->inposy<=y1 )&&(joueur->inposy+SPRITE_SIZE>=y2 && joueur->inposy+SPRITE_SIZE<=y1 )))
    {
        if ((joueur->inposx+SPRITE_SIZE <= x2)&&(joueur->inposx+SPRITE_SIZE >= x1 ))
        {
            if (input->right == 1)
            {
                joueur->inposx-=3;  
            }   
        }
    }
    
    // //coter gauche joueur
    if((joueur->inposy>=y2 && joueur->inposy<=y1 )||(joueur->inposy+SPRITE_SIZE>=y2 && joueur->inposy+SPRITE_SIZE<=y1)||((joueur->inposy>=y2 && joueur->inposy<=y1 )&&(joueur->inposy+SPRITE_SIZE>=y2 && joueur->inposy+SPRITE_SIZE<=y1)))
    {
        if ((joueur->inposx <= x2)&&(joueur->inposx >= x1 ))
        {
            if (input->left == 1)
            {
                joueur->inposx+=3;  
            }
        }
    }
} 

    
//test si l'attaque du joueur touche la méduse
int insidechevalier (Joueur *joueur, Meduse *meduse)
{
    int x=0;
    int y=0;
    if (joueur->Direction==1)
    {
        if ((meduse->posmonsx>=joueur->inposx-21 || meduse->posmonsx+SPRITE_SIZE>=joueur->inposx-21) && (meduse->posmonsx<=joueur->inposx || meduse->posmonsx+SPRITE_SIZE<=joueur->inposx))
        {
            x=1;
        }
        if ((meduse->posmonsy>=joueur->inposy+32 || meduse->posmonsy+SPRITE_SIZE>=joueur->inposy+32) && (meduse->posmonsy<=joueur->inposy+SPRITE_SIZE || meduse->posmonsy+SPRITE_SIZE<=joueur->inposy+SPRITE_SIZE))
        {
            y=1;
        }
        if (x==1 && y==1)
        {return 1;}
        else 
        {return 0;}
    }
    if (joueur->Direction==0)
    {
        if ((meduse->posmonsx>=joueur->inposx+SPRITE_SIZE || meduse->posmonsx+SPRITE_SIZE>=joueur->inposx+SPRITE_SIZE) && (meduse->posmonsx<=joueur->inposx+SPRITE_SIZE+21|| meduse->posmonsx+SPRITE_SIZE<=joueur->inposx+SPRITE_SIZE+21))
        {
            x=1;
        }
        if ((meduse->posmonsy>=joueur->inposy+32 || meduse->posmonsy+SPRITE_SIZE>=joueur->inposy+32) && (meduse->posmonsy<=joueur->inposy+SPRITE_SIZE || meduse->posmonsy+SPRITE_SIZE<=joueur->inposy+SPRITE_SIZE))
        {
            y=1;
        }
        
        if (x==1 && y==1)
        {return 1;}
        else 
        {return 0;}
    }
}

//test si l'attaque du joueur touche le boss
int insidechevalierBoss (Joueur *joueur, Boss *boss)
{       
    int x=0;
    int y=0;
    if (joueur->Direction==1)
    {
        if ((boss->posmonsx>=joueur->inposx-21 || boss->posmonsx+128>=joueur->inposx-21) && (boss->posmonsx<=joueur->inposx || boss->posmonsx+128<=joueur->inposx))
        {
            x=1;
        }
        if ((boss->posmonsy>=joueur->inposy+32 || boss->posmonsy+128>=joueur->inposy+32) && (boss->posmonsy<=joueur->inposy+SPRITE_SIZE || boss->posmonsy+128<=joueur->inposy+SPRITE_SIZE))
        {
            y=1;
        }
        if (x==1 && y==1)
        {return 1;}
        else 
        {return 0;}
    }
    if (joueur->Direction==0)
    {
        if ((boss->posmonsx>=joueur->inposx+SPRITE_SIZE || boss->posmonsx+128>=joueur->inposx+SPRITE_SIZE) && (boss->posmonsx<=joueur->inposx+SPRITE_SIZE+21|| boss->posmonsx+128<=joueur->inposx+SPRITE_SIZE+21))
        {
            x=1;
        }
        if ((boss->posmonsy>=joueur->inposy+32 || boss->posmonsy+128>=joueur->inposy+32) && (boss->posmonsy<=joueur->inposy+SPRITE_SIZE || boss->posmonsy+128<=joueur->inposy+SPRITE_SIZE))
        {
            y=1;
        }
        
        if (x==1 && y==1)
        {return 1;}
        else 
        {return 0;}
    }
}

//test si l'attaque du joueur touche le yeti
int insidechevalieryeti (Joueur *joueur, Yeti *yeti)
{       
    int x=0;
    int y=0;
    if (joueur->Direction==1)
    {
        if ((yeti->posmonsx>=joueur->inposx-21 || yeti->posmonsx+80>=joueur->inposx-21) && (yeti->posmonsx<=joueur->inposx || yeti->posmonsx+80<=joueur->inposx))
        {
            x=1;
        }
        if ((yeti->posmonsy>=joueur->inposy+32 || yeti->posmonsy+80>=joueur->inposy+32) && (yeti->posmonsy<=joueur->inposy+SPRITE_SIZE || yeti->posmonsy+80<=joueur->inposy+SPRITE_SIZE))
        {
            y=1;
        }
        if (x==1 && y==1)
        {return 1;}
        else
        {return 0;}
    }
    if (joueur->Direction==0)
    {
        if ((yeti->posmonsx>=joueur->inposx+SPRITE_SIZE || yeti->posmonsx+80>=joueur->inposx+SPRITE_SIZE) && (yeti->posmonsx<=joueur->inposx+SPRITE_SIZE+21|| yeti->posmonsx+80<=joueur->inposx+SPRITE_SIZE+21))
        {
            x=1;
        }
        if ((yeti->posmonsy>=joueur->inposy+32 || yeti->posmonsy+80>=joueur->inposy+32) && (yeti->posmonsy<=joueur->inposy+SPRITE_SIZE || yeti->posmonsy+80<=joueur->inposy+SPRITE_SIZE))
        {
            y=1;
        }
       
        if (x==1 && y==1)
        {return 1;}
        else
        {return 0;}
    }
}


int insidechevalierbossyeti (Joueur *joueur, BossYeti *bossyeti)
{      
    int x=0;
    int y=0;
    if (joueur->Direction==1)
    {
        if ((bossyeti->posmonsx>=joueur->inposx-21 || bossyeti->posmonsx+108>=joueur->inposx-21) && (bossyeti->posmonsx<=joueur->inposx || bossyeti->posmonsx+108<=joueur->inposx))
        {
            x=1;
        }
        if ((bossyeti->posmonsy>=joueur->inposy+32 || bossyeti->posmonsy+108>=joueur->inposy+32) && (bossyeti->posmonsy<=joueur->inposy+SPRITE_SIZE || bossyeti->posmonsy+108<=joueur->inposy+SPRITE_SIZE))
        {
            y=1;
        }
        if (x==1 && y==1)
        {return 1;}
        else
        {return 0;}
    }
    if (joueur->Direction==0)
    {
        if ((bossyeti->posmonsx>=joueur->inposx+SPRITE_SIZE || bossyeti->posmonsx+108>=joueur->inposx+SPRITE_SIZE) && (bossyeti->posmonsx<=joueur->inposx+SPRITE_SIZE+21|| bossyeti->posmonsx+108<=joueur->inposx+SPRITE_SIZE+21))
        {
            x=1;
        }
        if ((bossyeti->posmonsy>=joueur->inposy+32 || bossyeti->posmonsy+108>=joueur->inposy+32) && (bossyeti->posmonsy<=joueur->inposy+SPRITE_SIZE || bossyeti->posmonsy+108<=joueur->inposy+SPRITE_SIZE))
        {
            y=1;
        }
       
        if (x==1 && y==1)
        {return 1;}
        else
        {return 0;}
    }
}



//test si l'attaque de la méduse touche le joueur
int inside (Joueur *joueur, Meduse *meduse)
{
    int x=0;
    int y=0;
    if ((joueur->inposx>=meduse->posmonsx-23 || joueur->inposx+SPRITE_SIZE>=meduse->posmonsx-23) && (joueur->inposx<=meduse->posmonsx+SPRITE_SIZE+23 || joueur->inposx + SPRITE_SIZE <=meduse->posmonsx+SPRITE_SIZE+23))
    {
        x=1;
    }
    if ((joueur->inposy>=meduse->posmonsy-23 || joueur->inposy+SPRITE_SIZE>=meduse->posmonsy-23) && (joueur->inposy<=meduse->posmonsy+SPRITE_SIZE+23 || joueur->inposy + SPRITE_SIZE <=meduse->posmonsy+SPRITE_SIZE+23))
    {
        y=1;
    }
    if (x==1 && y==1)
    {
        return 1;
    }
}

//test si l'attaque de la chauve-souris touche le joueur
int insidechauvesouris (Joueur *joueur, Chauvesouris *chauvesouris)
{
    int x=0;
    int y=0;

    if ((chauvesouris->posmonsx+10>=joueur->inposx || chauvesouris->posmonsx+40>=joueur->inposx) && (chauvesouris->posmonsx+10<=joueur->inposx+SPRITE_SIZE || chauvesouris->posmonsx+40<=joueur->inposx+SPRITE_SIZE))
    {
        x=1;
    }
    if ((chauvesouris->posmonsy+10>=joueur->inposy || chauvesouris->posmonsy+40>=joueur->inposy) && (chauvesouris->posmonsy+10<=joueur->inposy+SPRITE_SIZE || chauvesouris->posmonsy+40<=joueur->inposy+SPRITE_SIZE))
    {
        y=1;
    }
    if (x==1 && y==1)
    {return 1;}
    else
    {return 0;}
}
 
//test si l'attaque du boss touche le joueur
int insideBoss (Joueur *joueur, Boss *boss)
{
    int x=0;
    int y=0;
    if ((joueur->inposx>=boss->posmonsx-46 || joueur->inposx+SPRITE_SIZE>=boss->posmonsx-46) && (joueur->inposx<=boss->posmonsx+128+46 || joueur->inposx + SPRITE_SIZE <=boss->posmonsx+128+46))
    {
        x=1;
    }
    if ((joueur->inposy>=boss->posmonsy-46 || joueur->inposy+SPRITE_SIZE>=boss->posmonsy-46) && (joueur->inposy<=boss->posmonsy+128+46 || joueur->inposy + SPRITE_SIZE <=boss->posmonsy+128+46))
    {
        y=1;
    }
    if (x==1 && y==1)
    {
        return 1;
    }
}

//test si les éclairs touchent le joueur
int insideEclair(Joueur *joueur,int Eclairx, int Eclairy)
{
    int x=0;
    int y=0;
    if ((joueur->inposx>=Eclairx || joueur->inposx+SPRITE_SIZE>=Eclairx) && (joueur->inposx<=Eclairx+64 || joueur->inposx + SPRITE_SIZE <=Eclairx+64))
    {
        x=1;
    }
    if ((joueur->inposy>=Eclairy+405-28 || joueur->inposy+SPRITE_SIZE>=Eclairy+405-28) && (joueur->inposy<=Eclairy+405 || joueur->inposy + SPRITE_SIZE <=Eclairy+405))
    {
        y=1;
    }
    if (x==1 && y==1)
    {
        return 1;
    }
}

//recup item
int insideItem (Joueur *joueur, Boss *boss)
{
    int x=0;
    int y=0;
    if ((joueur->inposx>=boss->posmonsx || joueur->inposx+SPRITE_SIZE+20>=boss->posmonsx) && (joueur->inposx<=boss->posmonsx+SPRITE_SIZE-210 || joueur->inposx + SPRITE_SIZE <= boss->posmonsx+SPRITE_SIZE))
    {
        x=1;
    }
    if ((joueur->inposy>= boss->posmonsy || joueur->inposy+SPRITE_SIZE>=boss->posmonsy+100) && (joueur->inposy - 35 <=boss->posmonsy+SPRITE_SIZE || joueur->inposy-35 + SPRITE_SIZE <= boss->posmonsy+SPRITE_SIZE))
    {
        y=1;
    }
    if (x==1 && y==1)
    {
        return 1;
    }
}

//            pos objet vol x,y  pos cible    taille cible x,y         taille obj vol x,y 
int insideVol(int xobj, int yobj, int x, int y, int Margex, int Margey, int tailleObjx, int tailleObjy)
{
    int a=0;
    int b=0;
    //si joueur 
    if ((xobj>=x || xobj+tailleObjx>=x) && (xobj<=x+Margex || xobj + tailleObjx <=x+Margex))
    {
        a=1;
    }
    if ((yobj>=y || yobj+tailleObjy>=y) && (yobj<=y+Margey || yobj + tailleObjy <= y+Margey))
    {
        b=1;
    }
    if (a==1 && b==1)
    {
        return 1;
    }
}

//Indique au chevalier s'il prend des dégats
int DegatChevalier(Meduse *meduse, Meduse *meduse1 , Meduse *meduse2, Chauvesouris *chauvesouris , Chauvesouris *chauvesouris1, Boss *boss, Yeti *yeti, Yeti *yeti1, Yeti *yeti2)
{
    if  (meduse->coup==0 && meduse1->coup==0 && meduse2->coup==0 && chauvesouris->coup==0 && chauvesouris1->coup==0 && boss->coup==0 && boss->coupE1==0 && boss->coupE2==0 && boss->coupE3==0 && boss->coupE4==0 && yeti->coup==0 && yeti1->coup==0 && yeti2->coup==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int DegatBateau (Obstacle *tronc, Obstacle *Petit_rocher, Obstacle *Gros_rocher)
{
    if (tronc->coup == 0 && Gros_rocher->coup == 0 && Petit_rocher->coup == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}