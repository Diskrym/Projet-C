#include "../header/proto.h"

void collision (Joueur *joueur, Monstre *monstre, Input *input)
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

    //collision entre les monstre et joueur
    //collision haut joueur

    if (((joueur->inposy <= monstre->posmonsy + SPRITE_SIZE)&&(joueur->inposy >= monstre->posmonsy )) && (((monstre->posmonsx >= joueur->inposx) && (monstre->posmonsx <= joueur->inposx+SPRITE_SIZE)) || ((monstre->posmonsx + SPRITE_SIZE >= joueur->inposx) && (monstre->posmonsx + SPRITE_SIZE <= joueur->inposx+SPRITE_SIZE))))
    {
        monstre->posmonsy-=1;
        //input->Life--;
        if (input->up == 1)
        {
          joueur->inposy+=3;  
        }
    }

    //collision bas joueur
    if (((joueur->inposy + SPRITE_SIZE >= monstre->posmonsy) && (joueur->inposy <= monstre->posmonsy)) && (((monstre->posmonsx >= joueur->inposx) && (monstre->posmonsx <= joueur->inposx+SPRITE_SIZE)) || ((monstre->posmonsx + SPRITE_SIZE >= joueur->inposx) && (monstre->posmonsx + SPRITE_SIZE <= joueur->inposx+SPRITE_SIZE))))
    {
        monstre->posmonsy+=1;
        //input->Life--;
        if (input->down == 1)
        {
          joueur->inposy-=3;  
        }   
    }
    
    // //coter droit joueur
    if (joueur->inposx <= monstre->posmonsx)
    {
        if (joueur->inposx + SPRITE_SIZE >= monstre->posmonsx)
        {
            if ((monstre->posmonsy >= joueur->inposy) && (monstre->posmonsy <= joueur->inposy+SPRITE_SIZE))
            {
                monstre->posmonsx+=1;
                //input->Life--;
                if (input->right == 1)
                {
                    joueur->inposx-=3;  
                }   
            }

            if ((monstre->posmonsy + SPRITE_SIZE >= joueur->inposy) && (monstre->posmonsy + SPRITE_SIZE <= joueur->inposy + SPRITE_SIZE))
            {
                monstre->posmonsx+=1;
                //input->Life--;
                if (input->right == 1)
                {
                    joueur->inposx-=3;  
                }  
            }
            
            
        }
        
    }
    //coter gauche joueur
    if (joueur->inposx + SPRITE_SIZE >= monstre->posmonsx)
    {
        if (joueur->inposx <= monstre->posmonsx + SPRITE_SIZE)
        {
            if (monstre->posmonsy >= joueur->inposy && monstre->posmonsy <= joueur->inposy+SPRITE_SIZE)
            {
                monstre->posmonsx-=1;
                //input->Life--;
                if (input->left == 1)
                {
                    joueur->inposx+=3;  
                }
            }
            if (monstre->posmonsy + SPRITE_SIZE >= joueur->inposy && monstre->posmonsy + SPRITE_SIZE <= joueur->inposy + SPRITE_SIZE)
            {
                monstre->posmonsx-=1;
                //input->Life--;
                if (input->left == 1)
                {
                    joueur->inposx+=3;  
                }
            } 
        } 
    }
}



int inside (Joueur *joueur, Monstre *monstre)
{
    int x=0;
    int y=0;
    if ((joueur->inposx>=monstre->posmonsx-23 || joueur->inposx+SPRITE_SIZE>=monstre->posmonsx-23) && (joueur->inposx<=monstre->posmonsx+SPRITE_SIZE+23 || joueur->inposx + SPRITE_SIZE <=monstre->posmonsx+SPRITE_SIZE+23))
    {
        x=1;
    }
    if ((joueur->inposy>=monstre->posmonsy-23 || joueur->inposy+SPRITE_SIZE>=monstre->posmonsy-23) && (joueur->inposy<=monstre->posmonsy+SPRITE_SIZE+23 || joueur->inposy + SPRITE_SIZE <=monstre->posmonsy+SPRITE_SIZE+23))
    {
        y=1;
    }
    if (x==1 && y==1)
    {
        return 1;
    }
}

int insidechevalier (Joueur *joueur, Monstre *monstre, Input *input)
{
    int x=0;
    int y=0;
    if (joueur->Direction==1)
    {
    if ((monstre->posmonsx>=joueur->inposx-21 || monstre->posmonsx+SPRITE_SIZE>=joueur->inposx-21) && (monstre->posmonsx<=joueur->inposx || monstre->posmonsx+SPRITE_SIZE<=joueur->inposx))
    {
        x=1;
    }
    if ((monstre->posmonsy>=joueur->inposy+32 || monstre->posmonsy+SPRITE_SIZE>=joueur->inposy+32) && (monstre->posmonsy<=joueur->inposy+SPRITE_SIZE || monstre->posmonsy+SPRITE_SIZE<=joueur->inposy+SPRITE_SIZE))
    {
        y=1;
    }
    if (x==1 && y==1)
    {
        return 1;
    }
    }

    if (joueur->Direction==0)
    {
    if ((monstre->posmonsx>=joueur->inposx+SPRITE_SIZE || monstre->posmonsx+SPRITE_SIZE>=joueur->inposx+SPRITE_SIZE) && (monstre->posmonsx<=joueur->inposx+SPRITE_SIZE+21|| monstre->posmonsx+SPRITE_SIZE<=joueur->inposx+SPRITE_SIZE+21))
    {
        x=1;
            

    }
    if ((monstre->posmonsy>=joueur->inposy+32 || monstre->posmonsy+SPRITE_SIZE>=joueur->inposy+32) && (monstre->posmonsy<=joueur->inposy+SPRITE_SIZE || monstre->posmonsy+SPRITE_SIZE<=joueur->inposy+SPRITE_SIZE))
    {
        y=1;
    
    }
    if (x==1 && y==1)
    {   printf("%d ",x,"%d ",y);
        return 1;
    }
    }
}
