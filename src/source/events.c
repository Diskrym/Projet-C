#include "../header/proto.h"

void collision (Pos *pos, Monstre *monstre, Input *input)
{
    //collision joueur mur
    if (pos->inposx <= 25)
        {
            pos->inposx+=3;
        }
     if (pos->inposx >= SCREEN_WIDTH-SPRITE_SIZE-25)
        {
            pos->inposx-=3;
        }
    if (pos->inposy <= 25)
        {
            pos->inposy+=3;
        }
    if (pos->inposy >= SCREEN_HEIGHT-SPRITE_SIZE-20)
        {
            pos->inposy-=3;
        }

    //collision entre les monstre et joueur
    //collision haut joueur

    if (((pos->inposy <= monstre->posmonsy + SPRITE_SIZE)&&(pos->inposy >= monstre->posmonsy )) && (((monstre->posmonsx >= pos->inposx) && (monstre->posmonsx <= pos->inposx+SPRITE_SIZE)) || ((monstre->posmonsx + SPRITE_SIZE >= pos->inposx) && (monstre->posmonsx + SPRITE_SIZE <= pos->inposx+SPRITE_SIZE))))
    {
        monstre->posmonsy-=1;
        //input->Life--;
        if (input->up == 1)
        {
          pos->inposy+=3;  
        }
    }

    //collision bas joueur
    if (((pos->inposy + SPRITE_SIZE >= monstre->posmonsy) && (pos->inposy <= monstre->posmonsy)) && (((monstre->posmonsx >= pos->inposx) && (monstre->posmonsx <= pos->inposx+SPRITE_SIZE)) || ((monstre->posmonsx + SPRITE_SIZE >= pos->inposx) && (monstre->posmonsx + SPRITE_SIZE <= pos->inposx+SPRITE_SIZE))))
    {
        monstre->posmonsy+=1;
        //input->Life--;
        if (input->down == 1)
        {
          pos->inposy-=3;  
        }   
    }
    
    // //coter droit joueur
    if (pos->inposx <= monstre->posmonsx)
    {
        if (pos->inposx + SPRITE_SIZE >= monstre->posmonsx)
        {
            if ((monstre->posmonsy >= pos->inposy) && (monstre->posmonsy <= pos->inposy+SPRITE_SIZE))
            {
                monstre->posmonsx+=1;
                //input->Life--;
                if (input->right == 1)
                {
                    pos->inposx-=3;  
                }   
            }

            if ((monstre->posmonsy + SPRITE_SIZE >= pos->inposy) && (monstre->posmonsy + SPRITE_SIZE <= pos->inposy + SPRITE_SIZE))
            {
                monstre->posmonsx+=1;
                //input->Life--;
                if (input->right == 1)
                {
                    pos->inposx-=3;  
                }  
            }
            
            
        }
        
    }
    //coter gauche joueur
    if (pos->inposx + SPRITE_SIZE >= monstre->posmonsx)
    {
        if (pos->inposx <= monstre->posmonsx + SPRITE_SIZE)
        {
            if (monstre->posmonsy >= pos->inposy && monstre->posmonsy <= pos->inposy+SPRITE_SIZE)
            {
                monstre->posmonsx-=1;
                //input->Life--;
                if (input->left == 1)
                {
                    pos->inposx+=3;  
                }
            }
            if (monstre->posmonsy + SPRITE_SIZE >= pos->inposy && monstre->posmonsy + SPRITE_SIZE <= pos->inposy + SPRITE_SIZE)
            {
                monstre->posmonsx-=1;
                //input->Life--;
                if (input->left == 1)
                {
                    pos->inposx+=3;  
                }
            } 
        } 
    }
}



int inside (Pos *pos, Monstre *monstre)
{
    int x=0;
    int y=0;
    if ((pos->inposx>=monstre->posmonsx-23 || pos->inposx+SPRITE_SIZE>=monstre->posmonsx-23) && (pos->inposx<=monstre->posmonsx+SPRITE_SIZE+23 || pos->inposx + SPRITE_SIZE <=monstre->posmonsx+SPRITE_SIZE+23))
    {
        x=1;
    }
    if ((pos->inposy>=monstre->posmonsy-23 || pos->inposy+SPRITE_SIZE>=monstre->posmonsy-23) && (pos->inposy<=monstre->posmonsy+SPRITE_SIZE+23 || pos->inposy + SPRITE_SIZE <=monstre->posmonsy+SPRITE_SIZE+23))
    {
        y=1;
    }
    if (x==1 && y==1)
    {
        return 1;
    }
}

int insidechevalier (Pos *pos, Monstre *monstre, Input *input)
{
    int x=0;
    int y=0;
    if (pos->Direction==1)
    {
    if ((monstre->posmonsx>=pos->inposx-21 || monstre->posmonsx+SPRITE_SIZE>=pos->inposx-21) && (monstre->posmonsx<=pos->inposx || monstre->posmonsx+SPRITE_SIZE<=pos->inposx))
    {
        x=1;
    }
    if ((monstre->posmonsy>=pos->inposy+32 || monstre->posmonsy+SPRITE_SIZE>=pos->inposy+32) && (monstre->posmonsy<=pos->inposy+SPRITE_SIZE || monstre->posmonsy+SPRITE_SIZE<=pos->inposy+SPRITE_SIZE))
    {
        y=1;
    }
    if (x==1 && y==1)
    {
        return 1;
    }
    }

    if (pos->Direction==0)
    {
    if ((monstre->posmonsx>=pos->inposx+SPRITE_SIZE || monstre->posmonsx+SPRITE_SIZE>=pos->inposx+SPRITE_SIZE) && (monstre->posmonsx<=pos->inposx+SPRITE_SIZE+21|| monstre->posmonsx+SPRITE_SIZE<=pos->inposx+SPRITE_SIZE+21))
    {
        x=1;
    }
    if ((monstre->posmonsy>=pos->inposy+32 || monstre->posmonsy+SPRITE_SIZE>=pos->inposy+32) && (monstre->posmonsy<=pos->inposy+SPRITE_SIZE || monstre->posmonsy+SPRITE_SIZE<=pos->inposy+SPRITE_SIZE))
    {
        y=1;
    }
    if (x==1 && y==1)
    {
        return 1;
    }
    }
}
