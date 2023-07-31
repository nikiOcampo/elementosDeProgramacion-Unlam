/*Construir una función que reciba dos vectores enteros de igual tamaño y retorne un 1 si son guales o un 0 sino lo son.*/

#include <stdio.h>
#include <stdlib.h>

int unionVectores ( int [], int[], int);
void carga (int[], int);

int main()
{
    int cant, iguales;
    printf("Ingrese la cantidad de numeros que le quiere asignar a los vectores: ");
    scanf("%d",&cant);
    int vector1[cant], vector2[cant];
    printf("Numeros del primer vector: ");
    carga(vector1,cant);
    system("cls");
    printf("Numeros del segundo vector: ");
    carga(vector2,cant);
    iguales= unionVectores(vector1,vector2,cant);
    if (iguales==1)
        printf("Los vectores ingresados son iguales");
    else
        printf("Los vectores ingresados son distintos");
    return 0;
}

void carga(int v1[],int n)
{
    int x;
    for(x=0; x<n; x++)
    {
        printf("\n Ingrese valor %d:",x+1);
        scanf("%d",&v1[x]);
    }
}

int unionVectores (int v1[], int v2[], int n)
{
    int igual;
    int i=0;
    while(i<n)
    {
        if(v1[i]==v2[i])
            i++;
        else
            i=n+1;
    }
    if (i==n)
        igual=1;
    else
        igual=0;
    return igual;
}
