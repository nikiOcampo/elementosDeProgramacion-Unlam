#include <stdio.h>
#include <stdlib.h>

int main()
{
    int valor_hr, cant_hr, sueldo, new_sueldo;
    printf("Ingrese la cantidad de horas trabajas: ");
    scanf("%d",&cant_hr);
    printf("\nIngrese el valor de la hora: ");
    scanf("%d",&valor_hr);
    sueldo=cant_hr*valor_hr;
    if(cant_hr>50)
    {
        if(cant_hr>150)
            new_sueldo=sueldo+1000;
            else
            new_sueldo=sueldo+500;

    }
    else
        new_sueldo=sueldo;
    printf("El sueldo es de: %d", new_sueldo);
    return 0;
}
