#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Cant_Tu, Cant_PriCla, Precio, Clase_turista,Pr_clase,Recaudacion;
    printf("Ingrese la cantidad de pasajes clase turista: ");
    scanf("%d",&Cant_Tu);
    printf("\nIngrese la cantidad de pasajes de Primera clase: ");
    scanf("%d",&Cant_PriCla);
    Precio= 8800;
    Clase_turista= Cant_Tu*Precio;
    Pr_clase= Cant_PriCla*(Precio*1.3);
    Recaudacion= Clase_turista+Pr_clase;
    printf("\nLa recaudacion es de: %d", Recaudacion);

    return 0;
}
