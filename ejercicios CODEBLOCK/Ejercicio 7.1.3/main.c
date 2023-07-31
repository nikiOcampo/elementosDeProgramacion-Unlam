/*Realizar una función que reciba por parámetro dos vectores enteros de 5 elementos
cada uno y genere un vector de 10 posiciones con el contenido de ambos vectores intercalados.*/

#include <stdio.h>
#include <stdlib.h>

void intercalarVectores (int[],int[],int);
void carga(int[],int);
void mostrar(int[],int);

int main()
{
    int vec1[5],vec2[5];
    printf("Numeros del primer vector: ");
    carga(vec1,5);
    system("cls");
    printf("Numeros del segundo vector: ");
    carga(vec2,5);
    intercalarVectores(vec1,vec2,5);
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

void intercalarVectores (int v1[],int v2[],int n)
{
    int x;
    int resultado[10];
    for(x=0;x<n;x++)
    {
        resultado[x*2]= v1[x];
        resultado[(x*2)+1]= v2[x];
    }
    mostrar(resultado,10);
}

void mostrar(int resul[],int n)
{
    int x;
    for(x=0; x<n; x++)
    {
        printf("\n el contenido %d es = %d",x+1, resul[x]);
    }
}

