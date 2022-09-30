#include <stdio.h>

int hello()
{
    printf("hello world\n");
}

void pyra(){
    int Nbe;
    int i;
    int caseT;
    int caseM ;
    int x;
    int y ;
    
    Nbe=1 ;
    printf("Nombres de lignes ? :    ") ;
    scanf("%d",& i);
    caseM=(2*i-1)/2;
    for (y=0; y<i; y++){
         
        for (x=0; x <= caseM; x++)
        {
            printf(" ");
        }
        for (x=0; x <Nbe; x++)
        {
            printf("*");
        }
        for (x=0; x<= caseM; x++)
        {
            printf(" ");
        }
        Nbe+=2 ;
        caseM=(2*i-1-Nbe)/2;
        printf("\n");
    }
}

int xoxo(){
    int i ;
int y ;
i=0 ;
y=0;
    while (y<8)
    {
        if (y%2==0){
            if (i<9){
                if (i%2==0) {
                    printf("X") ;
                    i++ ;
                }
                else {
                    printf("O") ;
                    i++ ;
                }
            }
            else{
                printf("\n") ;
                y++ ;
                i=0;
            }
        }
        else{
            if (i<9){
                if (i%2==0) {
                    printf("O") ;
                    i++ ;
                }
                else {
                    printf("X") ;
                    i++ ;
                }
            }
            else{
                printf("\n") ;
                y++ ;
                i=0;
            }
        }
    }
}

void Air(){

    int x;
    int y;
    int f1;
    int f2;
    printf("Longueur ? :     ");
    scanf("%d",& y);
    printf("Largeur ? :    ");
    scanf("%d", & x);
    x++;
    y++;
    for (f1=0; f1<=x; f1++){
        printf("#");
    }
    f1=0;
    printf("\n");
    for (f2=0; f2<=y-2; f2++){
        printf("#");
        for (f1=0; f1<=x-2;f1++){
            printf(" ");
        }
        printf("#");
        printf("\n");
    }
    f1=0;
    for (f1=0; f1<=x; f1++){
        printf("#");
    }
    printf("\n");
}

int AirJoueur(){
    int x;
    int y;
    int f1;
    int f2;
    int jx;
    int jy;
    printf("Longueur ? :    ");
    scanf("%d",& x);
    printf("Largeur ? :     ");
    scanf("%d", & y);
    printf("Position x :    ");
    scanf("%d",& jx);
    printf("Position y :    ");
    scanf("%d",& jy);
    x++;
    y++;
    for (f1=0; f1<=y; f1++){
        printf("# ");
    }
    f1=0;
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
        printf("\n");
    }
    f1=0;
    for (f1=0; f1<=y; f1++){
        printf("# ");
    }
}



int main(){
xoxo();
pyra() ;
hello();
Air();
AirJoueur();
return 0 ;
}


