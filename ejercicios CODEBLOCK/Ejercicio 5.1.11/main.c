/*Ingresar 18 valores de temperatura distintos de cero. Se pide determinar e informar
cuantas ternas (tres valores seguidos) de valores positivos y cuantas de negativos hay.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,temp,termaspos,termasneg,cantpos,cantneg;
    termasneg=termaspos=cantneg=cantpos=0;
    for(i=0;i<=18;i++)
    {
     printf("Ingrese un valor de temperaturas distinto de cero: ");
     fflush(stdin);
     scanf("%d",&temp);
     if(temp>0)
     {
         termasneg=0;
         termaspos++;
         if(termaspos==3)
         {
             cantpos++;
             termaspos=0;
         }
     }
    else
    {
        termaspos=0;
        termasneg++;
        if(termasneg==3)
        {
            cantneg++;
            termasneg=0;
        }
    }
    }
    printf("\nLa cantidad de ternas negativas fueron: %d",cantneg);
    printf("\nLa cantidad de ternas positivas fueron: %d",cantpos);
    return 0;
}
