#include <stdio.h>
#include <stdlib.h>

int main()
{
    int hrs_trab, val_hr, sueldo;
    printf("Ingrese horas trabajadas: ");
    scanf("%d", &hrs_trab);
    printf("\n ingrese el valor hora: ");
    scanf("%d", &val_hr);
    sueldo=hrs_trab*val_hr;
    printf("\n\n\n El sueldo es: $%d",sueldo);
    return 0;
}
