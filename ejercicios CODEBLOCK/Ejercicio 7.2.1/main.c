/*7.2.1 Ingresar una matriz de 3x3 por teclado y un número entero. Realizar el producto de la matriz por la constante.*/

#include <stdio.h>
#include <stdlib.h>

void multiplicar(int[][3],int[][3],int);
void mostrar (int [][3],int[][3]);

int main()
{
    int m[3][3],num,f,c,producto[3][3];
    for(f=0;f<3;f++)
    {
        for(c=0;c<3;c++)
        {
            printf("Ingrese un numero para fila %d y columna %d: ",f,c);
            scanf("%d",&m[f][c]);
        }
    }
    printf("Ingrese el numero por el que desea multiplicar los numeros anteriormente cargados: ");
    scanf("%d",&num);
    multiplicar(m,producto,num);
    return 0;
}

void multiplicar(int m[][3],int prod[][3], int n)
{
    int x,i;
    for(x=0;x<3;x++)
    {
        for(i=0;i<3;i++)
        {
            prod[x][i]=m[x][i]*n;
        }
    }
    mostrar(m,prod);
}

void mostrar(int m[][3],int nue_m[][3])
{
    int x,i;
    for(x=0;x<3;x++)
       {
        printf("\n");
        for(i=0;i<3;i++)
           {
            printf(" | %4d   ",m[x][i]);
           }
       }
    for(x=0;x<3;x++)
       {
        printf("\n\n");
        for(i=0;i<3;i++)
           {
            printf(" | %4d  ",nue_m[x][i]);
           }
       }
}
