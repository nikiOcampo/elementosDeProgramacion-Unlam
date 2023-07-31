/*7.1.12 Dados los legajos y sueldos de los empleados de una empresa (máximo 100 empleados).
Se pide determinar el/los empleados/as de máximo sueldo. El fin de carga de sueldos está dado por un legajo igual a cero.
a. Los números de legajo son números correlativos de 1 a 100.
b. Realizar el mismo ejercicio considerando que los números de legajos son números NO correlativos de 4 cifras.*/

#include <stdio.h>
#include <stdlib.h>

//el de numeros de legajo no correlativos

int carga (int[],int[],int);
void maximo (int[],int[],int);

int main()
{
    int legajos[100],sueldos[100];
    int cant;
    cant=carga(legajos,sueldos,100);
    maximo(legajos,sueldos,cant);
    return 0;
}

int carga(int leg[], int suel[], int n)
{
    int x=0;
    do
    {
        printf("Ingrese el numero de legajo del empleado[SALIDA=0]: ");
        scanf("%d",&leg[x]);
        if(leg[x]<1000||leg[x]>9999)
            printf("\nEl legajo ingresado es INCORRECTO\n");
    }while(leg[x]<1000||leg[x]>9999);
    while(leg[x]!=0)
    {
        x++;
        printf("\nIngrese el sueldo del empleado con dicho legajo: ");
        scanf("%d",&suel[x-1]);
        do
        {
            printf("Ingrese el numero de legajo del empleado[SALIDA=0]: ");
            scanf("%d",&leg[x]);
            if(leg[x]<1000||leg[x]>9999)
                printf("\nEl legajo ingresado es INCORRECTO\n");
        }while(leg[x]<1000||leg[x]>9999);
    }
    return x;
}

void maximo(int leg[],int suel[],int n)
{
    int x,max,j;
    max=suel[0];
    for(x=1;x<n;x++)
    {
        if(suel[x]>max)
            max=suel[x];
    }
    printf("\n\nEl mayor sueldo es de %d, de el/los empleados con legajo: ",max);
    for(j=0;j<n;j++)
    {
        if(suel[j]==max)
            printf("\n%d", leg[j]);
    }
}
