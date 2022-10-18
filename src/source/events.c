#include "../header/proto.h"

void collision (Pos *pos, Monstre *monstre)
{
    //collision joueur mur
    // if (pos->inposx <= 0)
    //     {
    //         pos->inposx+=5;
    //     }
    //  if (pos->inposx >= SCREEN_WIDTH-SPRITE_SIZE/2)
    //     {
    //         pos->inposx-=5;
    //     }
    // if (pos->inposy <= 0)
    //     {
    //         pos->inposy+=5;
    //     }
    // if (pos->inposy >= SCREEN_HEIGHT-SPRITE_SIZE/2)
    //     {
    //         pos->inposy-=5;
    //     }

    //collision entre les monstre et joueur
    if ((pos->inposy < monstre->posmonsy + SPRITE_SIZE/2) && ((pos->inposx <= monstre->posmonsx <= pos->inposx+SPRITE_SIZE/2) || (pos->inposx <= monstre->posmonsx+SPRITE_SIZE/2 <= pos->inposx+SPRITE_SIZE/2 )))
    {
        //pos->inposy+=5;
        monstre->posmonsy-=2;
    }
    if (pos->inposx >= monstre->posmonsx <= pos->inposx+SPRITE_SIZE/2 || pos->inposx >= monstre->posmonsx+SPRITE_SIZE/2 <= pos->inposx+SPRITE_SIZE/2)
    {
         printf("bbb");
    }
    
}