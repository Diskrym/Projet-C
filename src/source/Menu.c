#include "../header/proto.h"

void Statistiques(Stats * stats, Joueur *joueur, Lvl*lvl)
{
    // Gestion total pièce(s)
    if (joueur->NbPiece>stats->Temp_pièce)
    {
        stats->Total_pièce+=(joueur->NbPiece-stats->Temp_pièce);
        stats->Temp_pièce=joueur->NbPiece;
    }
    if (stats->Temp_pièce>joueur->NbPiece)
    {
        stats->Temp_pièce=joueur->NbPiece;
    }
    //Gestion total tué(s)
    if (lvl->MortMonstre>stats->Temp_Tués)
    {
        stats->Total_Tués+=(lvl->MortMonstre-stats->Temp_Tués);
        stats->Temp_Tués=lvl->MortMonstre;
    }
    if (stats->Temp_Tués>lvl->MortMonstre)
    {
        stats->Temp_Tués=lvl->MortMonstre;
    }
    //Gestion Nombre dague(s) lancée(s) !!! A diviser par 2 pour affichage
    if (joueur->Edague>stats->Temp_Dague_Lancées)
    {
        stats->Dague_Lancées+=(joueur->Edague-stats->Temp_Dague_Lancées);
        stats->Temp_Dague_Lancées=joueur->Edague;
    }
    if (stats->Temp_Dague_Lancées>joueur->Edague)
    {
        stats->Temp_Dague_Lancées=joueur->Edague;
    }    
    //Gestion Total mort(s)
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
    char tempss[10];
    char tempm [10];
    char temph [10];
    char tempMM[3] = "";
    char tempHH[3]= "";
    char tempSS[3]= "";
    stats->Score_act_f= (double)temps/CLOCKS_PER_SEC+stats->TEMPS_GENE;
    
    //si inférieur à 1 minute, alors uniquement secondes
    if (stats->Score_act_f< 60)
    {   
        //Seconde(s)
        sprintf(tempss,"%.2f",stats->Score_act_f);
        //Heure(s) et Minute(s)
        strcpy(stats->Score_act,"0:00:");
        strcat(stats->Score_act,tempss);
    }
    //si supérieur à 1 min et inférieur à 1 heure
    else if (stats->Score_act_f >= 60 && stats->Score_act_f < 3600)
    {
        //Minute(s)
        sprintf(tempm,"%f",(stats->Score_act_f/60));
        //Seconde(s)
        if (stats->Score_act_f > 600)
        {
            strncat(tempMM,tempm,2);
        }
        else
        {
            strcpy(tempMM,"0");
            strncat(tempMM,tempm,1);
        }
        //Seconde(s)
         sprintf(tempss,"%.2f", (atof(tempm)-atof(tempMM))*60);

        if ((atof(tempm)-atof(tempMM))*60 >=10)
        {
            strncat(tempSS,tempss,2);
        }
        else
        {
            strcpy(tempSS,"0");
            strncat(tempSS,tempss,1);
        }

        //Tout en chaînes de caractères
        strcpy(stats->Score_act,"0:");
        strcat(stats->Score_act,tempMM);
        strcat(stats->Score_act,":");
        strcat(stats->Score_act,tempSS);
    }
    //Si supérieur à 1 heure
    else
    {
        //Heure(s)
        sprintf(temph,"%f",stats->Score_act_f/3600);
        if (stats->Score_act_f > 36000)
        {
            strncpy(tempHH,temph,2);
        }
        else
        {
            strcpy(tempHH,"0");
            strncat(tempHH,temph,1);
        }
        //Minute(s)
        sprintf(tempm,"%f",(stats->Score_act_f - atof(tempHH)*3600));
        //Seconde(s)
        if (stats->Score_act_f > 600)
        {
            strncat(tempMM,tempm,2);
        }
        else
        {
            strcpy(tempMM,0);
            strncat(tempMM,tempm,1);
        }
        //Seconde(s)
        sprintf(tempss,"%.2f", (atof(tempm)-atof(tempMM))*60);
        if ((atof(tempm)-atof(tempMM))*60 >= 10)
        {
             strncat(tempSS,tempss,2);
        }
        else
        {
            strcpy(tempSS,"0");
            strncat(tempSS,tempss,1);
        }
        
        strcpy(stats->Score_act,tempHH);
        strcat(stats->Score_act,":");
        strcat(stats->Score_act,tempMM);
        strcat(stats->Score_act,":");
        strcat(stats->Score_act,tempSS);
    }

    //reset pour gestion score_board
    strcpy(tempHH,"");
    strcpy(tempMM,"");
    strcpy(tempSS,"");
    //gestion meilleur score
    for (int i = 0; i < 5; i++)
    {    
        //Si nouveau meilleur score
        if (((double)temps/CLOCKS_PER_SEC)+stats->TEMPS_GENE <= stats->Score_Board[i])
        {
            for (int y = 4; y > i; y--)
            {
                strcpy(stats->Convert_Score[y],stats->Convert_Score[y-1]);
                stats->Score_Board[y]=stats->Score_Board[y-1];
            }
            stats->Score_Board[i]= (double)temps/CLOCKS_PER_SEC+stats->TEMPS_GENE;
            //si inférieur à 1 minute, alors uniquement seconde(s)
            if (stats->Score_Board[i] < 60)
            {   
                //Seconde(s)
                sprintf(tempss,"%.2f",stats->Score_Board[i]);
                //Heure(s) et Minute(s)
                strcpy(stats->Convert_Score[i],"0:0:");
                strcat(stats->Convert_Score[i],tempss);
            }
            else if (stats->Score_Board[i] >= 60 && stats->Score_Board[i] < 3600)
            {
                //Minute(s)
                sprintf(tempm,"%f",stats->Score_Board[i]/60);

                //Seconde(s)
                if (stats->Score_act_f > 600)
                {
                    strncat(tempMM,tempm,2);
                }
                else
                {
                    strncat(tempMM,tempm,1);
                }
                sprintf(tempss,"%.2f", (atof(tempm)-atof(tempMM))*60);

                strcpy(stats->Convert_Score[i],"0:");
                strcat(stats->Convert_Score[i],tempMM);
                strcat(stats->Convert_Score[i],":");
                strcat(stats->Convert_Score[i],tempss);
            }
            else
            {
                //Heure(s)
                sprintf(temph,"%f",stats->Score_Board[i]/3600);
                if (stats->Score_act_f > 36000)
                {
                    strncpy(tempHH,temph,2);
                }
                else
                {
                    strncpy(tempHH,temph,1);
                }
                //Minute(s)
                sprintf(tempm,"%f",(stats->Score_Board[i]- atof(tempHH)*3600));
                //Seconde(s)
                if (stats->Score_act_f > 600)
                {
                    strncpy(tempMM,tempm,2);
                }
                else
                {
                    strncpy(tempMM,tempm,1);
                }

                sprintf(tempss,"%.2f", (atof(tempm)-atof(tempMM))*60);

                strcpy(stats->Convert_Score[i],tempHH);
                strcat(stats->Convert_Score[i],":");
                strcat(stats->Convert_Score[i],tempMM);
                strcat(stats->Convert_Score[i],":");
                strcat(stats->Convert_Score[i],tempss);
            }
            break;
        }
    }
}   

void Save(Joueur *joueur,Lvl *lvl, Input *input, Entité *entité, EffetSon *son,Stats *stats, clock_t temps)
{
    
    //Entrée pause
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

        //retour jeu
        if (input->PosMouseX >= 118 && input->PosMouseX <= 522 && input->PosMouseY >= 117 && input->PosMouseY <= 154)
        {
            lvl->Num = lvl->temp;
            SDL_ShowCursor(SDL_DISABLE);
        }
        //Quitter sans sauvegarde
        if (input->PosMouseX >= 329 && input->PosMouseX <= 522 && input->PosMouseY >= 164 && input->PosMouseY <= 203)
        {
            stats->TEMPS_GENE+=(double)temps/CLOCKS_PER_SEC;
            lvl->save = 1;
            lvl->quit = 1;
        }
        //Sauvegarder
        if (input->PosMouseX >= 118 && input->PosMouseX <= 311 && input->PosMouseY >= 167 && input->PosMouseY <= 204 || lvl->save == 1)
        {
            FILE* fichier = fopen ( nomFichier , "r+" );
            if ( fichier )
            {
                fprintf(fichier,"life=%d AttPice=%d NbPiece=%d nbDague=%d WinDonjon=%d/fin ",joueur->life,joueur->AttPiece,joueur->NbPiece,joueur->nbDague,lvl->WinDonjon);
                fclose(fichier);
            }
            FILE* fichier1 = fopen ( nomFichier1 , "r+" );
            if ( fichier1 )
            {
                
                fprintf(fichier1,"Total_pièce=%d Total_Tués=%d Total_Mort=%d Dague_Lancées=%d KDA=%f TEMPS_GENE=%lf temps=%s S1=%f S2=%f S3=%f S4=%f S5=%f %s %s %s %s %s",stats->Total_pièce,stats->Total_Tués,stats->Total_Mort,stats->Dague_Lancées,stats->KDA,stats->TEMPS_GENE,stats->Score_act,stats->Score_Board[0],stats->Score_Board[1],stats->Score_Board[2],stats->Score_Board[3],stats->Score_Board[4],stats->Convert_Score[0],stats->Convert_Score[1],stats->Convert_Score[2],stats->Convert_Score[3],stats->Convert_Score[4]);
                fclose(fichier1);
            }
            if (lvl->save != 1)
            {
                lvl->Num=lvl->temp;
            }
            lvl->save = 0;
            if (lvl->quit == 1)
            {
                exit(0);
            }
        }
        //reset base
        if (input->PosMouseX >= 118 && input->PosMouseX <= 524 && input->PosMouseY >= 263 && input->PosMouseY <= 300)
        {
            FILE* fichier = fopen ( nomFichier , "r+" );
            if ( fichier )
            {
                fprintf(fichier,"life=%d AttPice=%d NbPiece=%d nbDague=%d WinDonjon=%d/fin ",3,0,0,0,0);
                fclose(fichier);
            }
            FILE* fichier1 = fopen ( nomFichier1 , "r+" );
            if ( fichier1 )
            {
                fprintf(fichier1,"Total_pièce=%d Total_Tués=%d Total_Mort=%d Dague_Lancées=%d KDA=%f TEMPS_GENE=%f temps=%s:%s:%s.%s",0,0,0,0,0,0,"00","00","00","00");
                fclose(fichier1);
            }
            SDL_ShowCursor(SDL_DISABLE);
            stats->Diff_reset=clock();
            lvl->Num = -1 ;
            lvl->reset = 0;
            lvl->Load = 0;
            joueur->Ebateau = 0;
            lvl->cin = 1;
        }
        //Statistiques
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
    // quitter scoreboard
    if (lvl->Num == -3)
    {
        if (input->PosMouseX >= 222 && input->PosMouseX <= 416 && input->PosMouseY >= 313 && input->PosMouseY <= 351)
        {
            lvl->Num = -2 ;
        }  
    }  
    //quitter score
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
        //reset si map bateau
        if (lvl->Num == 9 || lvl->Num == 10)
        {
            joueur->Ebateau = 0 ;
            lvl->Avancement10 = 0 ;
        }
        char* nomFichier = "src/Save/Game.txt";
        FILE* fichier = fopen ( nomFichier , "r+" );
        if ( fichier )
        {
            fprintf(fichier,"life=%d AttPice=%d NbPiece=%d",3,0,0);
            fclose(fichier);
            SDL_ShowCursor(SDL_DISABLE);
            lvl->Num = -1 ;
            lvl->reset = 0;
            lvl->Load = 0;
            lvl->save = 1;
        }
    }
}