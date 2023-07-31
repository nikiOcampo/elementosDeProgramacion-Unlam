/*7.2.2 Ingresar una matriz de 2x3 por teclado. Calcular la matriz transpuesta.*/

#include <stdio.h>
#include <stdlib.h>

void carga (int [][3]);
void transpuesta (int [2][3],int[3][2]);
void mostrar (int [][3],int[][2]);

int main()
{
    int m[2][3],m2[3][2]={0};
    carga(m);
    transpuesta(m,m2);
    return 0;
}

void carga (int m[][3])
{
    int f,c;
    for(f=0;f<2;f++)
    {
        for(c=0;c<3;c++)
        {
            printf("Ingrese un numero para fila %d y columna %d: ",f,c);
            scanf("%d",&m[f][c]);
        }
    }
}

void transpuesta (int m1[2][3],int m2[3][2])
{
    int x,i;
    for(x=0;x<3;x++)
    {
        for(i=0;i<3;i++)
        {
            m2[x][i]=m1[i][x];
        }
    }
    mostrar(m1,m2);
}

void mostrar(int m[2][3],int nue_m[3][2])
{
    int x,i;
    for(x=0;x<2;x++)
       {
        printf("\n");
        for(i=0;i<3;i++)
           {
            printf(" | %d   ",m[x][i]);
           }
       }
    for(x=0;x<3;x++)
       {
        printf("\n\n");
        for(i=0;i<2;i++)
           {
            printf(" | %d  ",nue_m[x][i]);
           }
       }
}
