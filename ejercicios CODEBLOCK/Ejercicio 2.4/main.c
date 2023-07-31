#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Pie, Pulgadas;
    float Yardas, Cms, Mts;
    printf("Ingrese la medida en pies: ");
    scanf("%d",&Pie);
    Pulgadas= Pie*12;
    Yardas= (float) Pie/3;
    Cms= (float)Pulgadas*2.54;
    Mts= (float)Cms/100;
    printf("\n\nPulgadas:%d", Pulgadas);
    printf("\n\nYardas: %f",Yardas);
    printf("\n\nCentimetros: %f",Cms);
    printf("\n\nMetros: %f", Mts);
    return 0;
}
