#include "../header/proto.h"

void collision (Pos *pos, Monstre *monstre, Input *input)
{
    //collision joueur mur
    if (pos->inposx <= 25)
        {
            pos->inposx+=5;
        }
     if (pos->inposx >= SCREEN_WIDTH-SPRITE_SIZE-25)
        {
            pos->inposx-=5;
        }
    if (pos->inposy <= 25)
        {
            pos->inposy+=5;
        }
    if (pos->inposy >= SCREEN_HEIGHT-SPRITE_SIZE-20)
        {
            pos->inposy-=5;
        }

    //collision entre les monstre et joueur
    //collision haut joueur

    if (((pos->inposy <= monstre->posmonsy + SPRITE_SIZE)&&(pos->inposy >= monstre->posmonsy )) && (((monstre->posmonsx >= pos->inposx) && (monstre->posmonsx <= pos->inposx+SPRITE_SIZE)) || ((monstre->posmonsx + SPRITE_SIZE >= pos->inposx) && (monstre->posmonsx + SPRITE_SIZE <= pos->inposx+SPRITE_SIZE))))
    {
        monstre->posmonsy-=12;
        input->Life--;
        if (input->up == 1)
        {
          pos->inposy+=5;  
        }
    }

    //collision bas joueur
    if (((pos->inposy + SPRITE_SIZE >= monstre->posmonsy) && (pos->inposy <= monstre->posmonsy)) && (((monstre->posmonsx >= pos->inposx) && (monstre->posmonsx <= pos->inposx+SPRITE_SIZE)) || ((monstre->posmonsx + SPRITE_SIZE >= pos->inposx) && (monstre->posmonsx + SPRITE_SIZE <= pos->inposx+SPRITE_SIZE))))
    {
        monstre->posmonsy+=12;
        input->Life--;
        if (input->down == 1)
        {
          pos->inposy-=5;  
        }   
    }
    
    // //coter droit joueur
    if (pos->inposx <= monstre->posmonsx)
    {
        if (pos->inposx + SPRITE_SIZE >= monstre->posmonsx)
        {
            if ((monstre->posmonsy >= pos->inposy) && (monstre->posmonsy <= pos->inposy+SPRITE_SIZE))
            {
                monstre->posmonsx+=12;
                input->Life--;
                if (input->right == 1)
                {
                    pos->inposx-=5;  
                }   
            }

            if ((monstre->posmonsy + SPRITE_SIZE >= pos->inposy) && (monstre->posmonsy + SPRITE_SIZE <= pos->inposy + SPRITE_SIZE))
            {
                monstre->posmonsx+=12;
                input->Life--;
                if (input->right == 1)
                {
                    pos->inposx-=5;  
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
                monstre->posmonsx-=12;
                input->Life--;
                if (input->left == 1)
                {
                    pos->inposx+=5;  
                }
            }
            if (monstre->posmonsy + SPRITE_SIZE >= pos->inposy && monstre->posmonsy + SPRITE_SIZE <= pos->inposy + SPRITE_SIZE)
            {
                monstre->posmonsx-=12;
                input->Life--;
                if (input->left == 1)
                {
                    pos->inposx+=5;  
                }
            } 
        } 
    }
}



void DegatChevalier (Input *input)
{



}