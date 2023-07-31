#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Cant_empanadas, Cant_Doc, Cant_Un, Precio_total;
    printf("Ingrese la cantidad de empanadas: ");
    scanf("%d", &Cant_empanadas);
    Cant_Doc= Cant_empanadas/12;
    Cant_Un=Cant_empanadas%12;
    Precio_total= Cant_Doc*300 + Cant_Un*30;
    printf("\nEl precio total es de: $%d",Precio_total);
    return 0;
}
