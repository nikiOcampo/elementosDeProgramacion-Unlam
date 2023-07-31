/*7.2.3 Ingresar una matriz de 5x4 por teclado. Realizar una función que genere un vector con la suma por fila de dicha matriz.*/

#include <stdio.h>
#include <stdlib.h>

void carga (int[5][4]);
void vector (int[5][4],int []);
void mostrar (int[5][4], int []);

int main()
{
    int m[5][4],v[5]={0};
    carga(m);
    vector(m,v);
    //mostrar(m,v);
    return 0;
}


void carga (int m[5][4])
{
    int f,c;
    for(f=0;f<5;f++)
    {
        for(c=0;c<4;c++)
        {
            printf("Ingrese un numero para fila %d y columna %d: ",f,c);
            scanf("%d",&m[f][c]);
        }
    }
}

void vector(int m[5][4], int vec[])
{
    int x,i,acuml=0;
    for(x=0;x<5;x++)
    {
        for(i=0;i<4;i++)
        {
            acuml+=m[x][i];
        }
        vec[x]=acuml;
        acuml=0;
    }
     mostrar(m,vec);
}

void mostrar(int m[][4],int vec[])
{
    int x,i;
    for(x=0;x<5;x++)
    {
        printf("\n");
        for(i=0;i<4;i++)
        {
            printf(" | %d   ",m[x][i]);
        }
    }
    printf("\nLa suma de los numeros por fila es de: ");
    for(x=0;x<5;x++)
    {
        printf("\nFILA nro %d: %d",x+1,vec[x]);
    }

}
