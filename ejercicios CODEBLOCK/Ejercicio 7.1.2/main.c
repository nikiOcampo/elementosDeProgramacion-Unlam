/*Realizar una función que reciba por parámetro dos vectores enteros de 5 elementos cada uno
y genere un vector de 10 posiciones con el contenido de ambos vectores uno a continuación del otro*/

#include <stdio.h>
#include <stdlib.h>

void concatenarVectores (int[],int[],int);
void carga(int[],int);
void mostrar(int[],int);

int main()
{
    int Vec1[5],Vec2[5];
    printf("Numeros del primer vector: ");
    carga(Vec1,5);
    system("cls");
    printf("Numeros del segundo vector: ");
    carga(Vec2,5);
    concatenarVectores(Vec1,Vec2,10);

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


void concatenarVectores (int v1[],int v2[], int n)
{
    int x,y;
    int result[10];
    int c = 0;
    for (x=0; x<n/2; x++)
    {
       result[c] = v1[x];
       c++;
    }
    for (y=0; y<n/2; y++)
    {
        result[c] = v2[y];
        c++;
    }
    mostrar(result, n);
}

void mostrar(int vector[],int n)
{
    int x;
    for(x=0; x<n; x++)
    {
        printf("\n el contenido %d es = %d",x+1, vector[x]);
    }

}




