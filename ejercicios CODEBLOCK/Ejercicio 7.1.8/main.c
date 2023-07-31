/*Se ingresan DNI y nota de un parcial de los alumnos de un curso.
El ingreso de datos finaliza con un DNI negativo. Se sabe que como máximo pueden presentarse a rendir 60 alumnos. Mostrar:
a. Listado de alumnos con su correspondiente DNI y la nota obtenida (en forma de listado)
b. La máxima nota obtenida y el DNI de los alumnos que la obtuvieron.*/

#include <stdio.h>
#include <stdlib.h>

int carga (int[],int[], int );
void mostrarLista (int[], int[], int);
int maximo (int[],int);
void mostrarMaximo (int[],int[], int,int);

int main()
{
    int dni[60],notas[60],cant,max;
    cant=carga(dni,notas,60);
    mostrarLista(dni,notas,cant);
    max=maximo(notas,cant);
    mostrarMaximo(dni,notas,max,cant);
    return 0;
}

int carga(int dni_alum[], int not_alum[], int n)
{
    int i=0,j=0,dni,nota;
    printf("Ingrese el DNI del alumno: ");
    scanf("%d",&dni);
    while(dni>=0 && i<n)
    {
        dni_alum[i]=dni;
        i++;
        do
        {
            printf("Ingrese la nota del parcial del alumno: ");
            scanf("%d",&nota);
            if(nota<1||nota>10)
                printf("La nota ingresada no es valida\n");
        }while(nota<1||nota>10);
        not_alum[j]=nota;
        j++;
        if(i<n)
        {
            printf("Ingrese el DNI del alumno: ");
            scanf("%d",&dni);
        }
    }
    return i;
}

void mostrarLista (int dni[], int not[], int n)
{
    int x;
    printf("\nDNI:\t\tNOTAS:\n");
    for(x=0;x<n;x++)
    {
        printf("\n%d\t\t%d\n",dni[x],not[x]);
    }

}

int maximo ( int nota[], int n)
{
    int max,i;
    max=nota[0];
    for (i=1;i<n;i++)
    {
        if (nota[i]>max)
            max=nota[i];
    }
    return max;
}

void mostrarMaximo (int dni[],int nota[], int max , int n)
{
    int i;
    printf("\n\nLa nota mas alta es de %d y la tuvieron los alumnos con los siguientes DNI: \n", max);
    for (i=0;i<n;i++)
    {
        if(nota[i]==max)
            printf("\n%d\n",dni[i]);
    }
}
