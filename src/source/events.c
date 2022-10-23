#include "../header/proto.h"

void collision (Joueur *joueur, Meduse *meduse, Input *input)
{
    //collision joueur mur
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

    //collision entre les meduse et joueur
    //collision haut joueur

    if (((joueur->inposy <= meduse->posmonsy + SPRITE_SIZE)&&(joueur->inposy >= meduse->posmonsy )) && (((meduse->posmonsx >= joueur->inposx) && (meduse->posmonsx <= joueur->inposx+SPRITE_SIZE)) || ((meduse->posmonsx + SPRITE_SIZE >= joueur->inposx) && (meduse->posmonsx + SPRITE_SIZE <= joueur->inposx+SPRITE_SIZE))))
    {
        meduse->posmonsy-=1;
        //input->Life--;
        if (input->up == 1)
        {
          joueur->inposy+=3;  
        }
    }

    //collision bas joueur
    if (((joueur->inposy + SPRITE_SIZE >= meduse->posmonsy) && (joueur->inposy <= meduse->posmonsy)) && (((meduse->posmonsx >= joueur->inposx) && (meduse->posmonsx <= joueur->inposx+SPRITE_SIZE)) || ((meduse->posmonsx + SPRITE_SIZE >= joueur->inposx) && (meduse->posmonsx + SPRITE_SIZE <= joueur->inposx+SPRITE_SIZE))))
    {
        meduse->posmonsy+=1;
        //input->Life--;
        if (input->down == 1)
        {
          joueur->inposy-=3;  
        }   
    }
    
    // //coter droit joueur
    if (joueur->inposx <= meduse->posmonsx)
    {
        if (joueur->inposx + SPRITE_SIZE >= meduse->posmonsx)
        {
            if ((meduse->posmonsy >= joueur->inposy) && (meduse->posmonsy <= joueur->inposy+SPRITE_SIZE))
            {
                meduse->posmonsx+=1;
                //input->Life--;
                if (input->right == 1)
                {
                    joueur->inposx-=3;  
                }   
            }

            if ((meduse->posmonsy + SPRITE_SIZE >= joueur->inposy) && (meduse->posmonsy + SPRITE_SIZE <= joueur->inposy + SPRITE_SIZE))
            {
                meduse->posmonsx+=1;
                //input->Life--;
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
                //input->Life--;
                if (input->left == 1)
                {
                    joueur->inposx+=3;  
                }
            }
            if (meduse->posmonsy + SPRITE_SIZE >= joueur->inposy && meduse->posmonsy + SPRITE_SIZE <= joueur->inposy + SPRITE_SIZE)
            {
                meduse->posmonsx-=1;
                //input->Life--;
                if (input->left == 1)
                {
                    joueur->inposx+=3;  
                }
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
    {if ((meduse->posmonsx>=joueur->inposx-21 || meduse->posmonsx+SPRITE_SIZE>=joueur->inposx-21) && (meduse->posmonsx<=joueur->inposx || meduse->posmonsx+SPRITE_SIZE<=joueur->inposx))
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
