/*7.2.10 Ingresar por teclado valores enteros y generar una matriz de 5x3 (5 filas y 3 por columnas). Informar:
a. La suma de los elementos de las columnas.
b. Las sumas de los elementos de las filas.
c. La suma total de los elementos.
d. El valor promedio de toda la matriz.
e. El valor promedio por columna.
f. El máximo valor de la matriz y en qué posición se encuentra (el máximo es único).
g. El mínimo valor de cada columna y en qué posición se encuentra (el mínimo es único).
Utilizar funciones para la carga y para resolver cada uno de los puntos.*/

#include <stdio.h>
#include <stdlib.h>

void carga (int[][3],int,int);
void punto_a (int[][3],int,int);
void punto_b (int[][3],int,int);
void punto_c (int[][3],int,int);
void punto_d (int[][3],int,int);
void punto_e (int[][3],int,int);
void punto_f (int[][3],int,int);
void punto_g (int[][3],int,int);

int main()
{
    int m[5][3];
    carga (m,5,3);
    punto_a(m,5,3);
    punto_b(m,5,3);
    punto_c(m,5,3);
    punto_d(m,5,3);
    punto_e(m,5,3);
    punto_f(m,5,3);
    punto_g(m,5,3);
    return 0;
}

void carga (int m[][3],int f,int c)
{
    int x,i;
    for (x=0;x<f;x++)
    {
        for(i=0;i<c;i++)
        {
            printf("Ingrese el valor de la fila %d y columna %d: ",x+1,i+1);
            scanf("%d",&m[x][i]);
        }
    }
}

//a. La suma de los elementos de las columnas.
void punto_a(int m[][3],int f,int c)
{
    int suma_colum[3]={0},x,i;
    for(x=0;x<c;x++)
    {
        for(i=0;i<f;i++)
        {
            suma_colum[x]+=m[i][x];
        }
    }
    for(x=0;x<c;x++)
    {
        printf("\nLa suma de la columna nro %d es de: %d ",x+1,suma_colum[x]);
    }
}

//b. Las sumas de los elementos de las filas.
void punto_b(int m[][3],int f,int c)
{
    int suma_fila[5]={0},x,i;
    for(x=0;x<f;x++)
    {
        for(i=0;i<c;i++)
        {
            suma_fila[x]+=m[x][i];
        }
    }
    for(x=0;x<f;x++)
    {
        printf("\nLa suma de la fila nro %d es de: %d ",x+1,suma_fila[x]);
    }
}

//c. La suma total de los elementos.
void punto_c(int m[][3],int f,int c)
{
    int total=0,x,i;
    for(x=0;x<f;x++)
    {
        for(i=0;i<c;i++)
        {
            total+=m[x][i];
        }
    }
    printf("\nLa suma total de los numeros cargados es de: %d",total);
}

//d. El valor promedio de toda la matriz.
void punto_d(int m[][3],int f,int c)
{
    int total=0,x,i;
    float promedio;
    for(x=0;x<f;x++)
    {
        for(i=0;i<c;i++)
        {
            total+=m[x][i];
        }
    }
    promedio=(float)total/15;
    printf("\nEl valor promedio de los numeros cargados es de: %0.2f",promedio);
}

//e. El valor promedio por columna.
void punto_e(int m[][3],int f,int c)
{
    int suma_colum[3]={0},x,i;
    float prom_colum[3]={0};
    for(x=0;x<c;x++)
    {
        for(i=0;i<f;i++)
        {
            suma_colum[x]+=m[i][x];
        }
    }
    for(x=0;x<c;x++)
    {
        prom_colum[x]=suma_colum[x]/f;
        printf("\nEl valor promedio de la columna nro %d es de: %0.2f",x+1,prom_colum[x]);
    }
}

//f. El máximo valor de la matriz y en qué posición se encuentra (el máximo es único).
void punto_f(int m[][3],int f,int c)
{
    int x,i,max,fil,col;
    max=m[0][0];
    for(x=0;x<f;x++)
    {
        for(i=0;i<c;i++)
        {
            if(m[x][i]>=max)
            {
                max=m[x][i];
                fil=x+1;
                col=i+1;
            }
        }
    }
    printf("\nEl maximo valor de los numeros cargados es de %d",max);
    printf("\nQue se encuentra en la fila %d y columna %d",fil,col);
}

//g. El mínimo valor de cada columna y en qué posición se encuentra (el mínimo es único).
void punto_g(int m[][3],int f,int c)
{
    int min[3]={0},x,i,fil,col;
    min[0]=m[0][0];
    min[1]=m[0][1];
    min[2]=m[0][2];
    for(x=0;x<c;x++)
    {
        for(i=0;i<f;i++)
        {
            if(min[x]>=m[i][x])
            {
                min[x]=m[i][x];
                fil=i+1;
                col=x+1;
            }
        }
        printf("\nEl valor minimo de la columna nro %d es %d, cargado en la fila %d y columna %d",x+1,min[x],fil,col);
    }
}
