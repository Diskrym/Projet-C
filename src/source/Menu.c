#include "../header/proto.h"

void Statistiques(Stats * stats, Joueur *joueur, Lvl*lvl)
{
    // Gestion total pièce
    if (joueur->NbPiece>stats->Temp_pièce)
    {
        stats->Total_pièce+=(joueur->NbPiece-stats->Temp_pièce);
        stats->Temp_pièce=joueur->NbPiece;
    }
    if (stats->Temp_pièce>joueur->NbPiece)
    {
        stats->Temp_pièce=joueur->NbPiece;
    }
    //Gestion total tués
    if (lvl->MortMonstre>stats->Temp_Tués)
    {
        stats->Total_Tués+=(lvl->MortMonstre-stats->Temp_Tués);
        stats->Temp_Tués=lvl->MortMonstre;
    }
    if (stats->Temp_Tués>lvl->MortMonstre)
    {
        stats->Temp_Tués=lvl->MortMonstre;
    }
    //Gestion Nombre dague lancées !!! A diviser par 2 pour affichage
    if (joueur->Edague>stats->Temp_Dague_Lancées)
    {
        stats->Dague_Lancées+=(joueur->Edague-stats->Temp_Dague_Lancées);
        stats->Temp_Dague_Lancées=joueur->Edague;
    }
    if (stats->Temp_Dague_Lancées>joueur->Edague)
    {
        stats->Temp_Dague_Lancées=joueur->Edague;
    }    
    //Gestion Total mort
    if (lvl->reset == 1)
    {
        stats->Total_Mort+=1;
        
    }
    //Ratio
    if (stats->Total_Mort !=0)
    {
        stats->DIVI_Mort=stats->Total_Mort;
        stats->DIVI_Tués=stats->Total_Tués;
        stats->KDA=(stats->DIVI_Tués/stats->DIVI_Mort);
        sprintf(stats->affichage_kda,"%.2f",stats->KDA);
    }
    else
    {
        strcpy(stats->affichage_kda,"0.00");
    }
}

void Score_(Stats *stats,clock_t temps)
{
    for (int i = 0; i < 5; i++)
    {
        if (((double)temps/CLOCKS_PER_SEC)+stats->TEMPS_GENE <= stats->Score_Board[i])
        {
            char tempss[10];
            char tempm [10];
            char temph [10];
            stats->Score_Board[i]= (double)temps/CLOCKS_PER_SEC+stats->TEMPS_GENE;
            //si inférieur a 1minutes alors uniquement seconde
            if (stats->Score_Board[i] < 60)
            {   
                //sec
                sprintf(tempss,"%.2f",stats->Score_Board[i]);
                //Heure et Minute
                strcpy(stats->Convert_Score[i],"0:0:");
                strcat(stats->Convert_Score[i],tempss);
            }
            else if (stats->Score_Board[i] > 60 && stats->Score_Board[i] < 3600)
            {

                //Minute
                sprintf(tempm,"%.0f",stats->Score_Board[i]/60);

                //Seconde
                sprintf(tempss,"%.2f", (stats->Score_Board[i]/60-atof(tempm))*60);
    
                //tout
                strcpy(stats->Convert_Score[i],"0:");
                strcat(stats->Convert_Score[i],tempm);
                strcat(stats->Convert_Score[i],":");
                strcat(stats->Convert_Score[i],tempss);
            }
            else
            {
                //heure
                sprintf(temph,"%.0f",stats->Score_Board[i]/3600);
                //min
                sprintf(tempm,"%.0f",((stats->Score_Board[i]-atof(temph)*3600)/60));
                //sec
                sprintf(tempss,"%.2f", (stats->Score_Board[i]/60-atof(tempm))*60);

                strcpy(stats->Convert_Score[i],temph);
                strcat(stats->Convert_Score[i],":");
                strcat(stats->Convert_Score[i],tempm);
                strcat(stats->Convert_Score[i],":");
                strcat(stats->Convert_Score[i],tempss);
            }
            break;
        }
    }
}   


void Save(Joueur *joueur,Lvl *lvl, Input *input, Entité *entité, EffetSon *son,Stats *stats, clock_t temps)
{
    
    //entrer pause
    if (input->echap == 1 && lvl->Num != -2 && lvl->Num != -3 && lvl->Num !=-4)
    {
        lvl->temp = lvl->Num;
        lvl->Num = -2;
    }
    //menu pause
    if (lvl->Num == -2 || lvl->save == 1)
    {       
        SDL_ShowCursor(SDL_ENABLE);
        char* nomFichier = "src/Save/Game.txt";
        char* nomFichier1= "src/Save/Stats.txt";
        //save
        if (input->PosMouseX >= 118 && input->PosMouseX <= 311 && input->PosMouseY >= 167 && input->PosMouseY <= 204 || lvl->save == 1)
        {
            stats->TEMPS_GENE=(double)temps/CLOCKS_PER_SEC;
            FILE* fichier = fopen ( nomFichier , "r+" );
            if ( fichier )
            {
                fprintf(fichier,"life=%d AttPice=%d NbPiece=%d nbDague=%d WinDonjon=%d",joueur->life,joueur->AttPiece,joueur->NbPiece,joueur->nbDague,lvl->WinDonjon);
                fclose(fichier);
            }
            FILE* fichier1 = fopen ( nomFichier1 , "r+" );
            if ( fichier1 )
            {
                
                fprintf(fichier1,"Total_pièce=%d Total_Tués=%d Total_Mort=%d Dague_Lancées=%d KDA=%f TEMPS_GENE=%lf S1=%f S2=%f S3=%f S4=%f S5=%f C1=%s C2=%s C3=%s C4=%s C5=%s",stats->Total_pièce,stats->Total_Tués,stats->Total_Mort,stats->Dague_Lancées,stats->KDA,stats->TEMPS_GENE,stats->Score_Board[0],stats->Score_Board[1],stats->Score_Board[2],stats->Score_Board[3],stats->Score_Board[4],stats->Convert_Score[0],stats->Convert_Score[1],stats->Convert_Score[2],stats->Convert_Score[3],stats->Convert_Score[4]);
                fclose(fichier1);
            }
            if (lvl->save != 1)
            {
                lvl->Num=lvl->temp;
            }
            lvl->save = 0;

        }

        //retour jeux
        if (input->PosMouseX >= 118 && input->PosMouseX <= 522 && input->PosMouseY >= 117 && input->PosMouseY <= 154)
        {
            lvl->Num = lvl->temp;
            SDL_ShowCursor(SDL_DISABLE);
        }
        //Quit sans save
        if (input->PosMouseX >= 329 && input->PosMouseX <= 522 && input->PosMouseY >= 164 && input->PosMouseY <= 203)
        {
            exit(0);
        }
        //reset base
        if (input->PosMouseX >= 118 && input->PosMouseX <= 524 && input->PosMouseY >= 263 && input->PosMouseY <= 300)
        {
            FILE* fichier = fopen ( nomFichier , "r+" );
            if ( fichier )
            {
                fprintf(fichier,"life=%d AttPice=%d NbPiece=%d nbDague=%d WinDonjon=%d",3,0,0,0,0);
                fclose(fichier);
            }
            FILE* fichier1 = fopen ( nomFichier1 , "r+" );
            if ( fichier1 )
            {
                fprintf(fichier1,"Total_pièce=%d Total_Tués=%d Total_Mort=%d Dague_Lancées=%d KDA=%f TEMPS_GENE=%f",0,0,0,0,0,0);
                fclose(fichier1);
            }
            SDL_ShowCursor(SDL_DISABLE);
            stats->Diff_reset=clock();
            lvl->Num = -1 ;
            lvl->reset = 0;
            lvl->Load = 0;
        }
        //Stats
        if (input->PosMouseX >= 118 && input->PosMouseX <= 311 && input->PosMouseY >= 213 && input->PosMouseY <= 250)
        {
            lvl->Num = -3;
        }
        //score board
        if (input->PosMouseX >= 329 && input->PosMouseX <= 523 && input->PosMouseY >= 213 && input->PosMouseY <= 250)
        {
            lvl->Num = -4;
        }
        
    }
    // quit scoreboard
    if (lvl->Num == -3)
    {
        if (input->PosMouseX >= 222 && input->PosMouseX <= 416 && input->PosMouseY >= 313 && input->PosMouseY <= 351)
        {
            lvl->Num = -2 ;
        }  
    }  
    //quit score
    if (lvl->Num == -4)
    {
        if (input->PosMouseX >= 222 && input->PosMouseX <= 416 && input->PosMouseY >= 305 && input->PosMouseY <= 343)
        {
            lvl->Num = -2 ;
        }  
    } 
    //reset si mort
    if (lvl-> reset == 1)
    {
        char* nomFichier = "src/Save/Game.txt";
        FILE* fichier = fopen ( nomFichier , "r+" );
        if ( fichier )
        {
            fprintf(fichier,"life=%d AttPice=%d NbPiece=%d nbDague=%d",3,0,0,0);
            fclose(fichier);
            SDL_ShowCursor(SDL_DISABLE);
            lvl->Num = -1 ;
            lvl->reset = 0;
            lvl->Load = 0;
            joueur->Ebateau = 1 ;
        }
    }
}