#include <stdio.h>
int main (int argc, char** argv)
{
 float tab [10];
 short cpt;
 float moy;
 for (cpt=0; cpt<10; cpt++)
 {
 printf ("Saisissez la note numero %d : ", cpt);
 scanf ("%f", &(tab[cpt]) );
 } 
 moy = 0;
 
 for (cpt=0; cpt<10; cpt++)
 moy += tab[cpt];
 
 moy /= 10;
 printf ("La moyenne est : %.2f\n", moy);
}