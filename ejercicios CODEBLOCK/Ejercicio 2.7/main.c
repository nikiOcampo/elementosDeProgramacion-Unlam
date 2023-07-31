#include <stdio.h>
#include <stdlib.h>

int main()
{
    int NUM, Centena, Resto, Decena, Unidad;
    printf("Ingrese un numero de 3 cifras: ");
    scanf("%d", &NUM);
    Centena= NUM/100;
    Resto=NUM%100;
    Decena=Resto/10;
    Unidad=Resto%10;
    printf("\nUnidad: %d", Unidad);
    printf("\nDecena: %d",Decena);
    printf("\nCentena: %d",Centena);
    return 0;
}
