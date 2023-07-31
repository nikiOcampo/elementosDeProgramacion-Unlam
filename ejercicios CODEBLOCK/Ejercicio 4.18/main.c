#include <stdio.h>
#include <stdlib.h>

int main()
{
    int diaHoy,mesHoy,anioHoy,diaNac,mesNac,anioNac,edad;
    printf("\nIngrese dia  hoy:");
    scanf("%d",&diaHoy);
    printf("\nIngrese mes  hoy:");
    scanf("%d",&mesHoy);
    printf("\nIngrese anio hoy:");
    scanf("%d",&anioHoy);
    printf("\n\n Ingrese dia Nacimiento :");
    scanf("%d",&diaNac);
    printf("\nIngrese mes  Nacimiento:");
    scanf("%d",&mesNac);
    printf("\nIngrese anio Nacimiento:");
    scanf("%d",&anioNac);
    edad=anioHoy-anioNac;
    if(mesNac>mesHoy)
        edad=edad-1;
    else
    {
        if(diaNac>diaHoy)
            edad=edad-1;
    }
    printf("La persona tiene %d anios",edad);
    return 0;
}
