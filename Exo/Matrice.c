#include <stdio.h>
int main(){
    double Val;
    double Mat1[4][4]={{6,4,8,9},
                    {5,2,9,6},
                    {3,2,3,2},
                    {5,7,3,2}};
    double Mat2[4][4]={{6,5,8,9},
                    {9,7,9,6},
                    {3,2,5,3},
                    {5,7,2,2}};
    double Matadd[4][4];
    double Matmut[4][4];
    for (int i=0; i<4; i++){
        for (int y=0; y<4;y++){
            Matadd[i][y]=Mat1[i][y]+Mat2[i][y];
        }
    }
    for (int i=0; i<4;i++){
        for (int y=0; y<4;y++){
            printf("%lf, ",Matadd[i][y]);
        }
        printf("\n");
        printf("\n");
        printf("\n");
    }
    
    for(int i=0; i<4; i++){
        for (int l=0; l<4; l++){
            for (int y=0; y<4; y++){
            Val+=Mat1[i][y]*Mat2[l][y];
            }
            Matmut[i][l]=Val;
        Val=0;
        }
    }
    for (int i=0; i<4;i++){
        for (int y=0; y<4;y++){
            printf("%lf, ",Matmut[i][y]);
        }
        printf("\n");
    }
}
    