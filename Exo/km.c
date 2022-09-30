#include <stdio.h>
int main(){
    int x,y;
    double cv, prix, km;
    float tabl [5][4] = {{0.451,0.270,0.315,906}, 
                        {0.518,0.291,0.349,1136}, 
                        {0.543,0.305,0.364,1188}, 
                        {0.568,0.32,0.382,1244}, 
                        {0.595,0.337,0.401,1288}};
    printf("Nombre de CV ?\n");
    scanf("%lf", &cv);
    printf("Nombre de km ?\n");
    scanf("%lf", &km);

    if (cv<=3){
        x=0;
    }
    if (cv==4){
        x=1;
    }
    if (cv==5){
        x=2;
    }
    if (cv==6){
        x=3;
    }
    if (cv>=7){
        x=4;
    }
    if(km<=5000){
        y=0;
    }
    if (km>5000 && km<20000){
        y=1;
    }
    if (km>20000){
        
        y=2;
    }
    if (km>5000 && km<20000){
        prix=((tabl[x][y])*km)+tabl[x][3];
    }
    else{    
        prix=((tabl[x][y])*km);
    }
    printf("Coût : %lf", prix);
}
