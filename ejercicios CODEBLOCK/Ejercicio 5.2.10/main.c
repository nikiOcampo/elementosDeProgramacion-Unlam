/*En un proceso de control se evalúan valores de temperatura,
finalizando cuando de ingresa un valor ficticio de temperatura -50.
Determinar el valor máximo y mínimo medido y sus posiciones respecto al ingreso.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int temp, mayort,mayor_pos, menort,menor_pos;
    mayort=mayor_pos=menort=menor_pos=0;
    do
    {
        printf("Ingresa la temperatura Nro: ",);
        scanf("%d",&temp);
        if(temp>mayort)
        {
            mayort=temp;
            mayor_pos++;
        }
        if(temp<menort)
        {
            menort=temp;
            menor_pos++;
        }

    }while(temp>-50);
    printf("La temperatura maxima fue de: %d \nCargada en la posicion: %d",mayort,mayor_pos);
    printf("\nLa temperatura minima fue de: %d \nCargada en la posicion: %d",menort,menor_pos);
    return 0;
}
