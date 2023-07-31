/*7.1.12 Dados los legajos y sueldos de los empleados de una empresa (máximo 100 empleados).
Se pide determinar el/los empleados/as de máximo sueldo. El fin de carga de sueldos está dado por un legajo igual a cero.
a. Los números de legajo son números correlativos de 1 a 100.
b. Realizar el mismo ejercicio considerando que los números de legajos son números NO correlativos de 4 cifras.*/

#include <stdio.h>
#include <stdlib.h>
//el que tiene numeros correlativos

int carga(int[],int);
void maximo (int[],int);

int main()
{
    int sueldos[100];
    int cant;
    cant=carga(sueldos,100);
    maximo(sueldos,cant);
    return 0;
}

int carga(int suel[], int n)
{
    int x=0,salida,sen=0,i;
    for(i=0;i<n;i++)
    {
        while(salida!=0)
        {
            x++;
            printf("ingrese el sueldo del empleado con nro de legajo %d: ",x);
            scanf("%d",&suel[x-1]);
            sen=1;
            if(sen==1)
            {
                printf("Ingrese 0 si desea dejar de cargar sueldos o cualquier otro numero si quiere seguir cargando: ");
                scanf("%d",&salida);
                i=n;
            }
        }
    }
    return x;
}

void maximo ( int sueldos[], int n)
{
    int max,i,j;
    max=sueldos[0];
    for (i=1;i<n;i++)
    {
        if (sueldos[i]>max)
            max=sueldos[i];
    }
    printf("\n\nEl mayor sueldo es de %d, de el/los empleados: ",max);
    for(j=0;j<n;j++)
    {
        if(sueldos[j]==max)
            printf("\n%d",j+1);
    }
}


