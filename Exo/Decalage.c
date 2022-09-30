#include <stdio.h>

int main(){
    int aj; 
    int tab[10]={0,0,0,0,0,0,0,0,0,0};

    for (int i=0; i<10; i++){ 

        printf ("Nombre : "); 
        scanf("%d",&aj);
        for(int f=9; f>0 ;f--){
            tab[f]=tab[f-1];
        }
        tab[0]=aj;
        for(int f=0; f<10;f++){
            printf("%d ,", tab[f]);
        }
        printf("\n");
    }
}