#include <stdio.h>
int main(){
    int tab [6] = {10,20,30,1,2,9};
    int min=tab[0];
    int max=tab[0];
    for(int i=1; i<6; i++)
    {
        if (min>tab[i]){
            min=tab[i];
        }
        if (max<tab[i]){
            max=tab[i];
        }
    }
    printf("min %d\n", min);
    printf("max %d\n", max);
}