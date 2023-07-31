#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Fecha, Dia, Resto, Mes, Anio, Nueva_Fecha;
    printf("Ingrese fecha en formato ddmmaa: ");
    scanf("%d", &Fecha);
    Dia= Fecha/10000;
    Resto= Fecha%10000;
    Mes=Resto/100;
    Anio= Resto%100;
    Nueva_Fecha= Anio*1000+Mes*100+Dia;
    printf("\nFecha en formato aammdd: %d",Nueva_Fecha);
    return 0;
}
