#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
void main(){
    int x;
    int y;
    int f1;
    int f2;
    int jx;
    int jy;
    int w;
    int m3;
    int m2;
    char c;
    printf("Longueur ? :    ");
    scanf("%d",& x);
    printf("Largeur ? :     ");
    scanf("%d", & y);
    w=0;
    jx=x/2;
    jy=y/2;
    if (jx%2 != 0){
         jx+=1.5;
     }
     if (jy%2!=0){
         jy+=1.5;
     }
    x++;
    y++;
    while (w!=1)
    {
        
    for (f1=0; f1<=y; f1++){
        printf("# ");
        m2=f1;
    }
    printf("\n");
    for (f2=0; f2<=x-2; f2++){
        printf("# ");
        for (f1=0; f1<=y-2;f1++){
            if (f2==jx-1 && f1==jy-1){
                    printf("O ");
                }
                else {
                    printf("  ");
                }
            }
        printf("# ");
        m3=f2+2;
        printf("\n");
    }
    for (f1=0; f1<=y; f1++){
        printf("# ");
    }
    printf("\n");
    c=_getch();
    system("cls");
    switch (c){
    case 'z':
    case 'Z':
        jx--;
        if (jx==0){
            jx++;
            printf("Attention t'as pris le mur !!!!\n");
        }
        break;
    case 'q' :
    case 'Q' :
        jy--;
        if (jy==0){
            jy++;
            printf("Attention t'as pris le mur !!!!\n");
        }
        break;
    case 's':
    case 'S':
        jx++;
        if (jx==m3){
            jx--;
            printf("Attention t'as pris le mur !!!!\n");
        }
        break;
    case 'd':
    case 'D':
        jy++;
        if (jy==m2){
            jy--;
            printf("Attention t'as pris le mur !!!!\n");
        }
        break;
    case 'e':
    case 'E':
        printf("Fin de partie !");
        w=1;
        break;
    }
    }
}