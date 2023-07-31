/*Se ingresan números enteros, hasta que se ingrese el número cero. Determinar los 2 valores mayores.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num,mayor1=0,mayor2=0;
    do
    {
        printf("Ingrese un numero entero: ");
        scanf("%d",&num);
        if(num>mayor1&&num>mayor2)
        mayor2=num;
        else
        {
            if(num>mayor1||num>mayor2)
            mayor1=num;
        }
    }while(num!=0);
    printf("Los dos valores mas grandes son: %d  y  %d",mayor2,mayor1);
    return 0;
}
