#include "../header/proto.h"

void collisionmur (Joueur *joueur)
{
    if (joueur->inposx <= 25)
        {
            joueur->inposx+=3;
        }
     if (joueur->inposx >= SCREEN_WIDTH-SPRITE_SIZE-25)
        {
            joueur->inposx-=3;
        }
    if (joueur->inposy <= 25)
        {
            joueur->inposy+=3;
        }
    if (joueur->inposy >= SCREEN_HEIGHT-SPRITE_SIZE-20)
        {
            joueur->inposy-=3;
        }
}

void collision (Joueur *joueur, Meduse *meduse, Input *input, Lvl *lvl)
{
   
    //collision entre les meduse et joueur
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

void collisionboss (Joueur *joueur, Boss *boss, Input *input, Lvl *lvl)
{
   
    //collision entre le boss et joueur
    //collision haut joueur
    if (boss->Life!=0)
    {
        if (((joueur->inposy <= boss->posmonsy + 128)&&(joueur->inposy >= boss->posmonsy )) && (((boss->posmonsx >= joueur->inposx) && (boss->posmonsx <= joueur->inposx+SPRITE_SIZE)) || ((boss->posmonsx + 128 >= joueur->inposx) && (boss->posmonsx + 128 <= joueur->inposx+SPRITE_SIZE))))
        {
            boss->posmonsy-=1;
            if (input->up == 1)
            {
                joueur->inposy+=3;  
            }
        }
        
        //collision bas joueur
        if (((joueur->inposy + SPRITE_SIZE >= boss->posmonsy) && (joueur->inposy <= boss->posmonsy)) && (((boss->posmonsx >= joueur->inposx) && (boss->posmonsx <= joueur->inposx+SPRITE_SIZE)) || ((boss->posmonsx + 128 >= joueur->inposx) && (boss->posmonsx + 128 <= joueur->inposx+SPRITE_SIZE))))
        {
            boss->posmonsy+=1;
            if (input->down == 1)
            {
                joueur->inposy-=3;  
            }   
        }

        // if (((joueur->inposx + SPRITE_SIZE >= boss->posmonsx) && (joueur->inposx <= boss->posmonsx)) && (((boss->posmonsy >= joueur->inposy) && (boss->posmonsy <= joueur->inposy+SPRITE_SIZE)) || ((boss->posmonsy + 128 >= joueur->inposy) && (boss->posmonsy + 128 <= joueur->inposy+SPRITE_SIZE))))
        // {
        //     boss->posmonsx+=1;
        //     if (input->down == 1)
        //     {
        //         joueur->inposx-=3;  
        //     }   
        // }

        // if (((joueur->inposx <= boss->posmonsx + 128)&&(joueur->inposx >= boss->posmonsx )) && (((boss->posmonsy >= joueur->inposy) && (boss->posmonsy <= joueur->inposy+SPRITE_SIZE)) || ((boss->posmonsy + 128 >= joueur->inposy) && (boss->posmonsy + 128 <= joueur->inposy+SPRITE_SIZE))))
        // {
        //     boss->posmonsx-=1;
        //     if (input->up == 1)
        //     {
        //         joueur->inposx+=3;  
        //     }
        // }
    
        // //coter droit joueur
        if (((joueur->inposx <= boss->posmonsx) && (joueur->inposx + SPRITE_SIZE >= boss->posmonsx)) && (((boss->posmonsy >= joueur->inposy) && (boss->posmonsy <= joueur->inposy+SPRITE_SIZE)) ||((joueur->inposx <= boss->posmonsx) && (joueur->inposx + SPRITE_SIZE >= boss->posmonsx) && (boss->posmonsy >= joueur->inposy) && (boss->posmonsy + 128 >= joueur->inposy) && (boss->posmonsy + 128 <= joueur->inposy + SPRITE_SIZE))))
                {
                    boss->posmonsx+=1;
                    if (input->right == 1)
                    {
                        joueur->inposx-=3;  
                    }   
                }


        
        //coter gauche joueur
        if (((joueur->inposx + SPRITE_SIZE >= boss->posmonsx) && (joueur->inposx <= boss->posmonsx + 128) && (boss->posmonsy >= joueur->inposy && boss->posmonsy <= joueur->inposy+SPRITE_SIZE)) || ((joueur->inposx + SPRITE_SIZE >= boss->posmonsx) && (joueur->inposx <= boss->posmonsx + 128) &&(boss->posmonsy + 128 >= joueur->inposy && boss->posmonsy + 128 <= joueur->inposy + SPRITE_SIZE)))
                {

                    boss->posmonsx-=1;
                    if (input->left == 1)
                    {
                        joueur->inposx+=3;  
                    }
                }
            } 
         }
    

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
    }}

int insidechevalierBoss (Joueur *joueur, Boss *boss)
{       int x=0;
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

int insideEclair(Joueur *joueur,int Eclairx, int Eclairy)
{
    int x=0;
    int y=0;
    if ((joueur->inposx>=Eclairx-22 || joueur->inposx+SPRITE_SIZE>=Eclairx-22) && (joueur->inposx<=Eclairx+22 || joueur->inposx + SPRITE_SIZE <=Eclairx+22))
    {
        x=1;
    }
    if ((joueur->inposy>=Eclairy-50+374 || joueur->inposy+SPRITE_SIZE>=Eclairy+374-50) && (joueur->inposy<=Eclairy+374+50 || joueur->inposy + SPRITE_SIZE <=Eclairy+374+50))
    {
        y=1;
    }
    if (x==1 && y==1)
    {
        return 1;
    }
}

int DegatChevalier(Meduse *meduse, Meduse *meduse1 , Meduse *meduse2, Chauvesouris *chauvesouris , Chauvesouris *chauvesouris1, Boss *boss)
{
    if  (meduse->coup==0 && meduse1->coup==0 && meduse2->coup==0 && chauvesouris->coup==0 && chauvesouris1->coup==0 && boss->coup==0 && boss->coupE1==0 && boss->coupE2==0 && boss->coupE3==0 && boss->coupE4==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}