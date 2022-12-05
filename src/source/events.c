#include "../header/proto.h"

//collision entre le joueur et les murs // haut ,bas ,gauche, droite
void Collision_Mur (Joueur *joueur, int x, int y, int z, int u)
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
void Collision_Meduse (Joueur *joueur, Meduse *meduse, Input *input, Lvl *lvl)
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
void Collision_Boss_Meduse (Joueur *joueur, Boss *boss, Input *input, Lvl *lvl)
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
void Collision_Yeti (Joueur *joueur, Yeti *yeti, Input *input, Lvl *lvl)
{  
    if (yeti->Life!=0)
    {   //collision haut joueur
        if((joueur->inposx>=yeti->posmonsx && joueur->inposx<=yeti->posmonsx+80 )||(joueur->inposx+SPRITE_SIZE>=yeti->posmonsx && joueur->inposx+SPRITE_SIZE<=yeti->posmonsx+80 )||((joueur->inposx>=yeti->posmonsx && joueur->inposx<=yeti->posmonsx+80 )&&(joueur->inposx+SPRITE_SIZE>=yeti->posmonsx && joueur->inposx+SPRITE_SIZE<=yeti->posmonsx+80 )))
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
        if((joueur->inposx>=yeti->posmonsx && joueur->inposx<=yeti->posmonsx+80 )||(joueur->inposx+SPRITE_SIZE>=yeti->posmonsx && joueur->inposx+SPRITE_SIZE<=yeti->posmonsx+80 )||((joueur->inposx>=yeti->posmonsx && joueur->inposx<=yeti->posmonsx+80 )&&(joueur->inposx+SPRITE_SIZE>=yeti->posmonsx && joueur->inposx+SPRITE_SIZE<=yeti->posmonsx+80 )))
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

void Collision_Boss_Yeti (Joueur *joueur, BossYeti *bossyeti, Input *input, Lvl *lvl)
{  
    if (bossyeti->Life!=0)
    {   //collision haut joueur
        if((joueur->inposx>=bossyeti->posmonsx && joueur->inposx<=bossyeti->posmonsx+108 )||(joueur->inposx+SPRITE_SIZE>=bossyeti->posmonsx && joueur->inposx+SPRITE_SIZE<=bossyeti->posmonsx+108 )||((joueur->inposx>=bossyeti->posmonsx && joueur->inposx<=bossyeti->posmonsx+108 )&&(joueur->inposx+SPRITE_SIZE>=bossyeti->posmonsx && joueur->inposx+SPRITE_SIZE<=bossyeti->posmonsx+108 )))
        {
            if ((joueur->inposy <= bossyeti->posmonsy+108)&&(joueur->inposy >= bossyeti->posmonsy+20 ))
            {
                bossyeti->posmonsy-=1;
                if (input->up == 1)
                {
                    joueur->inposy+=3;  
                }
            }
        }
       
        //collision bas joueur
        if((joueur->inposx>=bossyeti->posmonsx && joueur->inposx<=bossyeti->posmonsx+108 )||(joueur->inposx+SPRITE_SIZE>=bossyeti->posmonsx && joueur->inposx+SPRITE_SIZE<=bossyeti->posmonsx+108 )||((joueur->inposx>=bossyeti->posmonsx && joueur->inposx<=bossyeti->posmonsx+108 )&&(joueur->inposx+SPRITE_SIZE>=bossyeti->posmonsx && joueur->inposx+SPRITE_SIZE<=bossyeti->posmonsx+108 )))
        {
            if ((joueur->inposy+SPRITE_SIZE <= bossyeti->posmonsy+108)&&(joueur->inposy+SPRITE_SIZE >= bossyeti->posmonsy+20 ))        
            {
                bossyeti->posmonsy+=1;
                if (input->down == 1)
                {
                    joueur->inposy-=3;  
                }  
            }
        }
   
        // //coter droit joueur
        if((joueur->inposy>=bossyeti->posmonsy+20&& joueur->inposy<=bossyeti->posmonsy+108 )||(joueur->inposy+SPRITE_SIZE>=bossyeti->posmonsy+20&& joueur->inposy+SPRITE_SIZE<=bossyeti->posmonsy+108 )||((joueur->inposy>=bossyeti->posmonsy+20&& joueur->inposy<=bossyeti->posmonsy+108 )&&(joueur->inposy+SPRITE_SIZE>=bossyeti->posmonsy+20&& joueur->inposy+SPRITE_SIZE<=bossyeti->posmonsy+108 )))
        {
            if ((joueur->inposx+SPRITE_SIZE <= bossyeti->posmonsx + 65)&&(joueur->inposx+SPRITE_SIZE >= bossyeti->posmonsx ))
            {
                bossyeti->posmonsx+=1;
                if (input->right == 1)
                {
                    joueur->inposx-=3;  
                }  
            }
        }
       
        // //coter gauche joueur
        if((joueur->inposy>=bossyeti->posmonsy+20&& joueur->inposy<=bossyeti->posmonsy+108 )||(joueur->inposy+SPRITE_SIZE>=bossyeti->posmonsy+20&& joueur->inposy+SPRITE_SIZE<=bossyeti->posmonsy+108 )||((joueur->inposy>=bossyeti->posmonsy+20&& joueur->inposy<=bossyeti->posmonsy+108 )&&(joueur->inposy+SPRITE_SIZE>=bossyeti->posmonsy+20&& joueur->inposy+SPRITE_SIZE<=bossyeti->posmonsy+108 )))
        {
            if ((joueur->inposx <= bossyeti->posmonsx + 65)&&(joueur->inposx >= bossyeti->posmonsx ))
            {
                bossyeti->posmonsx-=1;
                if (input->left == 1)
                {
                    joueur->inposx+=3;  
                }
            }
        }
    }
}
 
//collision entre le squelette et joueur
void Collision_Squelette (Joueur *joueur, Squelette *squelette, Input *input, Lvl *lvl)
{  
    if (squelette->Life!=0)
    {   //collision haut joueur
        if((joueur->inposx>=squelette->posmonsx+4&& joueur->inposx<=squelette->posmonsx+57 )||(joueur->inposx+SPRITE_SIZE>=squelette->posmonsx+4&& joueur->inposx+SPRITE_SIZE<=squelette->posmonsx+57 )||((joueur->inposx>=squelette->posmonsx+4&& joueur->inposx<=squelette->posmonsx+57 )&&(joueur->inposx+SPRITE_SIZE>=squelette->posmonsx+4&& joueur->inposx+SPRITE_SIZE<=squelette->posmonsx+57 )))
        {
            if ((joueur->inposy <= squelette->posmonsy+64)&&(joueur->inposy >= squelette->posmonsy+13 ))
            {
                squelette->posmonsy-=1;
                if (input->up == 1)
                {
                    joueur->inposy+=3;  
                }
            }
        }
       
        //collision bas joueur
        if((joueur->inposx>=squelette->posmonsx+4&& joueur->inposx<=squelette->posmonsx+57 )||(joueur->inposx+SPRITE_SIZE>=squelette->posmonsx+4&& joueur->inposx+SPRITE_SIZE<=squelette->posmonsx+57 )||((joueur->inposx>=squelette->posmonsx+4&& joueur->inposx<=squelette->posmonsx+57 )&&(joueur->inposx+SPRITE_SIZE>=squelette->posmonsx+4&& joueur->inposx+SPRITE_SIZE<=squelette->posmonsx+57 )))
        {
            if ((joueur->inposy+SPRITE_SIZE <= squelette->posmonsy+64)&&(joueur->inposy+SPRITE_SIZE >= squelette->posmonsy+13 ))        
            {
                squelette->posmonsy+=1;
                if (input->down == 1)
                {
                    joueur->inposy-=3;  
                }  
            }
        }
   
        // //coter droit joueur
        if((joueur->inposy>=squelette->posmonsy+13&& joueur->inposy<=squelette->posmonsy+64 )||(joueur->inposy+SPRITE_SIZE>=squelette->posmonsy+13&& joueur->inposy+SPRITE_SIZE<=squelette->posmonsy+64 )||((joueur->inposy>=squelette->posmonsy+13&& joueur->inposy<=squelette->posmonsy+64 )&&(joueur->inposy+SPRITE_SIZE>=squelette->posmonsy+13&& joueur->inposy+SPRITE_SIZE<=squelette->posmonsy+64 )))
        {
            if ((joueur->inposx+SPRITE_SIZE <= squelette->posmonsx+4+ 65)&&(joueur->inposx+SPRITE_SIZE >= squelette->posmonsx+4))
            {
                squelette->posmonsx+=1;
                if (input->right == 1)
                {
                    joueur->inposx-=3;  
                }  
            }
        }
       
        // //coter gauche joueur
        if((joueur->inposy>=squelette->posmonsy+13&& joueur->inposy<=squelette->posmonsy+64 )||(joueur->inposy+SPRITE_SIZE>=squelette->posmonsy+13&& joueur->inposy+SPRITE_SIZE<=squelette->posmonsy+64 )||((joueur->inposy>=squelette->posmonsy+13&& joueur->inposy<=squelette->posmonsy+64 )&&(joueur->inposy+SPRITE_SIZE>=squelette->posmonsy+13&& joueur->inposy+SPRITE_SIZE<=squelette->posmonsy+64 )))
        {
            if ((joueur->inposx <= squelette->posmonsx+57)&&(joueur->inposx >= squelette->posmonsx+4))
            {
                squelette->posmonsx-=1;
                if (input->left == 1)
                {
                    joueur->inposx+=3;  
                }
            }
        }
    }
}
 
void Collision_Jerem_Boss (Joueur *joueur, Jerem_Boss *jerem, Input *input, Lvl *lvl)
{ 
    if (jerem->Life!=0)
    { 
if (jerem->Life>20 && jerem->Eattaque!=3)
{
//collision haut joueur
        if((joueur->inposx>=jerem->posmonsx && joueur->inposx<=jerem->posmonsx+84 )||(joueur->inposx+SPRITE_SIZE>=jerem->posmonsx && joueur->inposx+SPRITE_SIZE<=jerem->posmonsx+84 )||((joueur->inposx>=jerem->posmonsx && joueur->inposx<=jerem->posmonsx+84 )&&(joueur->inposx+SPRITE_SIZE>=jerem->posmonsx && joueur->inposx+SPRITE_SIZE<=jerem->posmonsx+84 )))
        {
            if ((joueur->inposy <= jerem->posmonsy+95)&&(joueur->inposy >= jerem->posmonsy ))
            {
                jerem->posmonsy-=1;
                if (input->up == 1)
                {
                    joueur->inposy+=3;  
                }
            }
        }
       
        //collision bas joueur
        if((joueur->inposx>=jerem->posmonsx && joueur->inposx<=jerem->posmonsx+84 )||(joueur->inposx+SPRITE_SIZE>=jerem->posmonsx && joueur->inposx+SPRITE_SIZE<=jerem->posmonsx+84 )||((joueur->inposx>=jerem->posmonsx && joueur->inposx<=jerem->posmonsx+84 )&&(joueur->inposx+SPRITE_SIZE>=jerem->posmonsx && joueur->inposx+SPRITE_SIZE<=jerem->posmonsx+84 )))
        {
            if ((joueur->inposy+SPRITE_SIZE <= jerem->posmonsy+95)&&(joueur->inposy+SPRITE_SIZE >= jerem->posmonsy ))        
            {
                jerem->posmonsy+=1;
                if (input->down == 1)
                {
                    joueur->inposy-=3;  
                }  
            }
        }
   
        // //coter droit joueur
        if((joueur->inposy>=jerem->posmonsy && joueur->inposy<=jerem->posmonsy+95 )||(joueur->inposy+SPRITE_SIZE>=jerem->posmonsy && joueur->inposy+SPRITE_SIZE<=jerem->posmonsy+95 )||((joueur->inposy>=jerem->posmonsy && joueur->inposy<=jerem->posmonsy+95 )&&(joueur->inposy+SPRITE_SIZE>=jerem->posmonsy && joueur->inposy+SPRITE_SIZE<=jerem->posmonsy+95 )))
        {
            if ((joueur->inposx+SPRITE_SIZE <= jerem->posmonsx+84)&&(joueur->inposx+SPRITE_SIZE >= jerem->posmonsx ))
            {
                jerem->posmonsx+=1;
                if (input->right == 1)
                {
                    joueur->inposx-=3;  
                }  
            }
        }
       
        // //coter gauche joueur
        if((joueur->inposy>=jerem->posmonsy && joueur->inposy<=jerem->posmonsy+95 )||(joueur->inposy+SPRITE_SIZE>=jerem->posmonsy && joueur->inposy+SPRITE_SIZE<=jerem->posmonsy+95 )||((joueur->inposy>=jerem->posmonsy && joueur->inposy<=jerem->posmonsy+95 )&&(joueur->inposy+SPRITE_SIZE>=jerem->posmonsy && joueur->inposy+SPRITE_SIZE<=jerem->posmonsy+95 )))
        {
            if ((joueur->inposx <= jerem->posmonsx+84)&&(joueur->inposx >= jerem->posmonsx ))
            {
                jerem->posmonsx-=1;
                if (input->left == 1)
                {
                    joueur->inposx+=3;  
                }
            }
        }
    	}
	if (jerem->Life<21 && jerem->Life>10 && jerem->Eattaque!=3)
{
//collision haut joueur
        if((joueur->inposx>=jerem->posmonsx && joueur->inposx<=jerem->posmonsx+93 )||(joueur->inposx+SPRITE_SIZE>=jerem->posmonsx && joueur->inposx+SPRITE_SIZE<=jerem->posmonsx+93 )||((joueur->inposx>=jerem->posmonsx && joueur->inposx<=jerem->posmonsx+93 )&&(joueur->inposx+SPRITE_SIZE>=jerem->posmonsx && joueur->inposx+SPRITE_SIZE<=jerem->posmonsx+93 )))
        {
            if ((joueur->inposy <= jerem->posmonsy+105)&&(joueur->inposy >= jerem->posmonsy ))
            {
                jerem->posmonsy-=1;
                if (input->up == 1)
                {
                    joueur->inposy+=3;  
                }
            }
        }
       
        //collision bas joueur
        if((joueur->inposx>=jerem->posmonsx && joueur->inposx<=jerem->posmonsx+93 )||(joueur->inposx+SPRITE_SIZE>=jerem->posmonsx && joueur->inposx+SPRITE_SIZE<=jerem->posmonsx+93 )||((joueur->inposx>=jerem->posmonsx && joueur->inposx<=jerem->posmonsx+93 )&&(joueur->inposx+SPRITE_SIZE>=jerem->posmonsx && joueur->inposx+SPRITE_SIZE<=jerem->posmonsx+93 )))
        {
            if ((joueur->inposy+SPRITE_SIZE <= jerem->posmonsy+105)&&(joueur->inposy+SPRITE_SIZE >= jerem->posmonsy ))        
            {
                jerem->posmonsy+=1;
                if (input->down == 1)
                {
                    joueur->inposy-=3;  
                }  
            }
        }
   
        // //coter droit joueur
        if((joueur->inposy>=jerem->posmonsy && joueur->inposy<=jerem->posmonsy+105 )||(joueur->inposy+SPRITE_SIZE>=jerem->posmonsy && joueur->inposy+SPRITE_SIZE<=jerem->posmonsy+105 )||((joueur->inposy>=jerem->posmonsy && joueur->inposy<=jerem->posmonsy+105 )&&(joueur->inposy+SPRITE_SIZE>=jerem->posmonsy && joueur->inposy+SPRITE_SIZE<=jerem->posmonsy+105 )))
        {
            if ((joueur->inposx+SPRITE_SIZE <= jerem->posmonsx+93)&&(joueur->inposx+SPRITE_SIZE >= jerem->posmonsx ))
            {
                jerem->posmonsx+=1;
                if (input->right == 1)
                {
                    joueur->inposx-=3;  
                }  
            }
        }
       
        // //coter gauche joueur
        if((joueur->inposy>=jerem->posmonsy && joueur->inposy<=jerem->posmonsy+105 )||(joueur->inposy+SPRITE_SIZE>=jerem->posmonsy && joueur->inposy+SPRITE_SIZE<=jerem->posmonsy+105 )||((joueur->inposy>=jerem->posmonsy && joueur->inposy<=jerem->posmonsy+105 )&&(joueur->inposy+SPRITE_SIZE>=jerem->posmonsy && joueur->inposy+SPRITE_SIZE<=jerem->posmonsy+105 )))
        {
            if ((joueur->inposx <= jerem->posmonsx+93)&&(joueur->inposx >= jerem->posmonsx ))
            {
                jerem->posmonsx-=1;
                if (input->left == 1)
                {
                    joueur->inposx+=3;  
                }
            }
        }
    	}
 
if (jerem->Life<=10 && jerem->Eattaque!=3)
{
//collision haut joueur
        if((joueur->inposx>=jerem->posmonsx && joueur->inposx<=jerem->posmonsx+107 )||(joueur->inposx+SPRITE_SIZE>=jerem->posmonsx && joueur->inposx+SPRITE_SIZE<=jerem->posmonsx+107 )||((joueur->inposx>=jerem->posmonsx && joueur->inposx<=jerem->posmonsx+107 )&&(joueur->inposx+SPRITE_SIZE>=jerem->posmonsx && joueur->inposx+SPRITE_SIZE<=jerem->posmonsx+107 )))
        {
            if ((joueur->inposy <= jerem->posmonsy+120)&&(joueur->inposy >= jerem->posmonsy ))
            {
                jerem->posmonsy-=1;
                if (input->up == 1)
                {
                    joueur->inposy+=3;  
                }
            }
        }
       
        //collision bas joueur
        if((joueur->inposx>=jerem->posmonsx && joueur->inposx<=jerem->posmonsx+107 )||(joueur->inposx+SPRITE_SIZE>=jerem->posmonsx && joueur->inposx+SPRITE_SIZE<=jerem->posmonsx+107 )||((joueur->inposx>=jerem->posmonsx && joueur->inposx<=jerem->posmonsx+107 )&&(joueur->inposx+SPRITE_SIZE>=jerem->posmonsx && joueur->inposx+SPRITE_SIZE<=jerem->posmonsx+107 )))
        {
            if ((joueur->inposy+SPRITE_SIZE <= jerem->posmonsy+120)&&(joueur->inposy+SPRITE_SIZE >= jerem->posmonsy ))        
            {
                jerem->posmonsy+=1;
                if (input->down == 1)
                {
                    joueur->inposy-=3;  
                }  
            }
        }
   
        // //coter droit joueur
        if((joueur->inposy>=jerem->posmonsy && joueur->inposy<=jerem->posmonsy+120 )||(joueur->inposy+SPRITE_SIZE>=jerem->posmonsy && joueur->inposy+SPRITE_SIZE<=jerem->posmonsy+120 )||((joueur->inposy>=jerem->posmonsy && joueur->inposy<=jerem->posmonsy+120 )&&(joueur->inposy+SPRITE_SIZE>=jerem->posmonsy && joueur->inposy+SPRITE_SIZE<=jerem->posmonsy+120 )))
        {
            if ((joueur->inposx+SPRITE_SIZE <= jerem->posmonsx+107)&&(joueur->inposx+SPRITE_SIZE >= jerem->posmonsx ))
            {
                jerem->posmonsx+=1;
                if (input->right == 1)
                {
                    joueur->inposx-=3;  
                }  
            }
        }
       
        // //coter gauche joueur
        if((joueur->inposy>=jerem->posmonsy && joueur->inposy<=jerem->posmonsy+120 )||(joueur->inposy+SPRITE_SIZE>=jerem->posmonsy && joueur->inposy+SPRITE_SIZE<=jerem->posmonsy+120 )||((joueur->inposy>=jerem->posmonsy && joueur->inposy<=jerem->posmonsy+120 )&&(joueur->inposy+SPRITE_SIZE>=jerem->posmonsy && joueur->inposy+SPRITE_SIZE<=jerem->posmonsy+120 )))
        {
            if ((joueur->inposx <= jerem->posmonsx+107)&&(joueur->inposx >= jerem->posmonsx ))
            {
                jerem->posmonsx-=1;
                if (input->left == 1)
                {
                    joueur->inposx+=3;  
                }
            }
        }
    	}
 
 
   }
}
 



void Collision_Decor (Joueur *joueur, Input *input, int x1, int x2, int y1, int y2)
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
int Inside_Chevalier_Meduse (Joueur *joueur, Meduse *meduse)
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
int Inside_Chevalier_Boss (Joueur *joueur, Boss *boss)
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
int Inside_Chevalier_Yeti (Joueur *joueur, Yeti *yeti)
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


int Inside_Chevalier_Boss_Yeti (Joueur *joueur, BossYeti *bossyeti)
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

int Inside_Chevalier_Boss_Jerem (Joueur *joueur, Jerem_Boss *jerem)
{
    int x=0;
    int y=0;
    if (joueur->Direction==1)
    {
        if ((jerem->posmonsx>=joueur->inposx || jerem->posmonsx+108>=joueur->inposx-21) && (jerem->posmonsx<=joueur->inposx || jerem->posmonsx+108<=joueur->inposx))
        {
            x=1;
        }
        if ((jerem->posmonsy>=joueur->inposy+32 || jerem->posmonsy+108>=joueur->inposy+32) && (jerem->posmonsy<=joueur->inposy+SPRITE_SIZE || jerem->posmonsy+108<=joueur->inposy+SPRITE_SIZE))
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
        if ((jerem->posmonsx>=joueur->inposx+SPRITE_SIZE || jerem->posmonsx+108>=joueur->inposx+SPRITE_SIZE) && (jerem->posmonsx<=joueur->inposx+SPRITE_SIZE+21|| jerem->posmonsx+108<=joueur->inposx+SPRITE_SIZE+21))
        {
            x=1;
        }
        if ((jerem->posmonsy>=joueur->inposy+32 || jerem->posmonsy+108>=joueur->inposy+32) && (jerem->posmonsy<=joueur->inposy+SPRITE_SIZE || jerem->posmonsy+108<=joueur->inposy+SPRITE_SIZE))
        {
            y=1;
        }
       
        if (x==1 && y==1)
        {return 1;}
        else
        {return 0;}
    }
}

int Inside_Chevalier_Squelette(Joueur *joueur, Squelette *squelette)
{
    int x=0;
    int y=0;
    if (squelette->Eattaque!=3)
    {
        if (joueur->Direction==1)
        {
            if ((squelette->posmonsx>=joueur->inposx-21|| squelette->posmonsx+64>=joueur->inposx-21) && (squelette->posmonsx<=joueur->inposx || squelette->posmonsx+64<=joueur->inposx))
            {
                x=1;
            }
            if ((squelette->posmonsy>=joueur->inposy+32 || squelette->posmonsy+62>=joueur->inposy+32) && (squelette->posmonsy<=joueur->inposy+SPRITE_SIZE || squelette->posmonsy+62<=joueur->inposy+SPRITE_SIZE))
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
            if ((squelette->posmonsx>=joueur->inposx+SPRITE_SIZE+21 || squelette->posmonsx+64>=joueur->inposx+SPRITE_SIZE+21) && (squelette->posmonsx<=joueur->inposx+SPRITE_SIZE || squelette->posmonsx+64<=joueur->inposx+SPRITE_SIZE))
            {
                x=1;
            }
            if ((squelette->posmonsy>=joueur->inposy+32 || squelette->posmonsy+62>=joueur->inposy+32) && (squelette->posmonsy<=joueur->inposy+SPRITE_SIZE || squelette->posmonsy+62<=joueur->inposy+SPRITE_SIZE))
            {
                y=1;
            }
        
            if (x==1 && y==1)
            {return 1;}
            else
            {return 0;}
        }
    }
    else
    {
        if (joueur->Direction==1)
        {
            if ((squelette->posmonsx+20>=joueur->inposx-21 || squelette->posmonsx+38>=joueur->inposx-21) && (squelette->posmonsx+20<=joueur->inposx || squelette->posmonsx+38<=joueur->inposx))
            {
                x=1;


            }
            if ((squelette->posmonsy+26>=joueur->inposy+32 || squelette->posmonsy+59>=joueur->inposy+32) && (squelette->posmonsy+26<=joueur->inposy+SPRITE_SIZE || squelette->posmonsy+59<=joueur->inposy+SPRITE_SIZE))
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
            if ((squelette->posmonsx+20>=joueur->inposx+64 || squelette->posmonsx+38>=joueur->inposx+64) && (squelette->posmonsx+20<=joueur->inposx+64+21|| squelette->posmonsx+38<=joueur->inposx+64+21))
            {
                x=1;
                
            }
            if ((squelette->posmonsy+26>=joueur->inposy+32 || squelette->posmonsy+59>=joueur->inposy+32) && (squelette->posmonsy+26<=joueur->inposy+SPRITE_SIZE || squelette->posmonsy+59<=joueur->inposy+SPRITE_SIZE))
            {
                y=1;
            }
        
            if (x==1 && y==1)
            {return 1;}
            else
            {return 0;}
        }
    }
}


//test si l'attaque de la méduse touche le joueur
int Inside_Meduse_Chevalier (Joueur *joueur, Meduse *meduse)
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
    else
    {
        return 0;
    }
}

int Inside_Squelette_Chevalier(Joueur *joueur, Squelette*squelette)
{
    int x=0;
    int y=0;
    if ((joueur->inposx>=squelette->posmonsx || joueur->inposx+SPRITE_SIZE>=squelette->posmonsx) && (joueur->inposx<=squelette->posmonsx+SPRITE_SIZE || joueur->inposx + SPRITE_SIZE <= squelette->posmonsx+SPRITE_SIZE))
    {
        x=1;
    }
    if ((joueur->inposy>=squelette->posmonsy || joueur->inposy+SPRITE_SIZE>=squelette->posmonsy) && (joueur->inposy<= squelette->posmonsy+SPRITE_SIZE || joueur->inposy + SPRITE_SIZE <=squelette->posmonsy+SPRITE_SIZE))
    {
        y=1;
    }
    if (x==1 && y==1)
    {
        return 1;
    }
    else
    {
    return 0;
    }
}

//test si l'attaque de la chauve-souris touche le joueur
int Inside_Chauvesouris_Chevalier (Joueur *joueur, Chauvesouris *chauvesouris)
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
int Inside_Boss_Meduse_Chevalier (Joueur *joueur, Boss *boss)
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
int Inside_Eclair_Chevalier(Joueur *joueur,int Eclairx, int Eclairy)
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
int Inside_Item (Joueur *joueur, Boss *boss)
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

int Inside_fissure (Joueur *joueur, BossYeti *bossyeti, int etape)
{
    int x=0;
    int y=0;
    if ((joueur->inposx>=bossyeti->xfissure || joueur->inposx+SPRITE_SIZE>=bossyeti->xfissure) && (joueur->inposx<=bossyeti->xfissure+300/etape || joueur->inposx + SPRITE_SIZE <= bossyeti->xfissure+300/etape))
    {
        x=1;
    }
    if ((joueur->inposy>= bossyeti->yfissure || joueur->inposy+SPRITE_SIZE>=bossyeti->yfissure+20) && (joueur->inposy <=bossyeti->yfissure+20 || joueur->inposy + SPRITE_SIZE <= bossyeti->yfissure+20))
    {
        y=1;
    }
    if (x==1 && y==1)
    {
        return 1;
    }
}

//            pos objet vol x,y  pos cible    taille cible x,y         taille obj vol x,y 
int Inside_Vol(int xobj, int yobj, int x, int y, int Margex, int Margey, int tailleObjx, int tailleObjy)
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
int Degat_Chevalier(Meduse *meduse, Meduse *meduse1 , Meduse *meduse2, Chauvesouris *chauvesouris , Chauvesouris *chauvesouris1, Boss *boss, Yeti *yeti, Yeti *yeti1, Yeti *yeti2, BossYeti *bossyeti, Squelette *squelette, Squelette *squelette1, Jerem_Boss *jerem)
{
    if  (meduse->coup==0 && meduse1->coup==0 && meduse2->coup==0 && chauvesouris->coup==0 && chauvesouris1->coup==0 && boss->coup==0 && boss->coupE1==0 && boss->coupE2==0 && boss->coupE3==0 && boss->coupE4==0 && yeti->coup==0 && yeti1->coup==0 && yeti2->coup==0 && bossyeti->coup==0 && bossyeti->coupfissure==0 && jerem->coup == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Degat_Bateau (Obstacle *tronc, Obstacle *Petit_rocher, Obstacle *Gros_rocher)
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