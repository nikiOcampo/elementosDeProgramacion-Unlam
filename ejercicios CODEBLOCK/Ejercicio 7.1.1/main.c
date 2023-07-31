/*Ingresar un vector de 10 unidades reales mediante una función llamada CARGA.
 Luego mediante una segunda función llamada INVERTIR, generar un segundo vector del mismo tamaño
  con los elementos ubicados en el orden inverso al del vector original.
   Mostrar el vector invertido con una función llamada MOSTRAR-*/

#include <stdio.h>
#include <stdlib.h>

void carga(float [],int);

void invertir(float [],float [],int);

void mostrar(float [],int);

int main()
{
    float Vec_i[10],Vec_n[10];
    carga(Vec_i,5);
    invertir(Vec_i,Vec_n,5);
    mostrar(Vec_n,5);
    return 0;
}
void carga(float v1[],int n)
{
    int x;
    system("cls");
    for(x=0; x<n; x++)
    {
        printf("\n Ingrese valor %d:",x+1);
        scanf("%f",&v1[x]);
    }
}
;

void invertir(float v1[],float v2[],int n)
{
    int a;
    for(a=0; a<n; a++)
    {
        v2[(n-1)-a]=v1[a];
    }
}
;

void mostrar(float KK[],int n)
{
    int x;
    for(x=0; x<n; x++)
    {
        printf("\n el contenido %d es = %.2f",x+1,KK[x]);
    }

}
;
