/*7.2.12 La empresa de turismo GUADALAJARA VIAJES comercializa 10 diferentes tours
a través de 15 agencias en todo el país. Diariamente cada agencia envía
 la cantidad de ventas efectuadas de cada tour, indicando agencia, tours y la cantidad de pasajes.
 Algunas agencias envían o/0 en la cantidad cuando no existen pasajes para un tour determinado, pero no en todas.
La información que se envía tiene los siguientes datos que se ingresan en forma desordenada:
• Código de agencia (de 1 a 15)
• Código de tour (1 a 10)
• Cantidad de pasajes (0 a 20)
Informar:
a. El total de pasajes vendidos por tour.
b. El número de agencia que obtuvo la máxima cantidad de pasajes vendidos.
FUNCIONES:
I. Para inicializar la matriz
II. Para mostrar el resultado del punto a.*/

#include <stdio.h>
#include <stdlib.h>

void inicializar (int[][15],int,int);
void punto_a(int[][15],int,int);
void punto_b(int[][15],int,int);

int main()
{
    int m[10][15];
    int cod_agencia,cod_tour,cant_pasajes,x,i;
    inicializar(m,10,15);
    for(i=0;i<3;i++)
    {
        do
        {
            printf("Ingrese el codigo de agencia: ");
            scanf("%d",&cod_agencia);
        }while(cod_agencia<1||cod_agencia>15);
        for(x=0;x<2;x++)
        {
            do
            {
                printf("\nIngrese el codigo de tour: ");
                scanf("%d",&cod_tour);
            }while(cod_tour<1||cod_tour>10);
            do
            {
                printf("\nIngrese la cantidad de pasajes vendidas de ese tour: ");
                scanf("%d",&cant_pasajes);
                //m[cod_tour-1][cod_agencia-1]+=cant_pasajes;
            }while(cant_pasajes<0||cant_pasajes>20);
            m[cod_tour-1][cod_agencia-1]+=cant_pasajes;
        }
    }
    punto_a(m,10,15);

    return 0;
}

void inicializar(int m[][15], int f,int c)
{
    int x,i;
    for(x=0;x<f;x++)
    {
        for(i=0;i<c;i++)
        {
            m[x][i]=0;
        }
    }
}

//a. El total de pasajes vendidos por tour.
void punto_a(int m[][15],int f,int c)
{
    int suma_tour[10]={0},x,i;
    for(x=0;x<f;x++)
    {
        for(i=0;i<c;i++)
        {
            suma_tour[x]+=m[x][i];
        }
    }
    for(x=0;x<f;x++)
    {
        printf("\nEl total de pasajes vendidos del tour nro %d es de: %d ",x+1,suma_tour[x]);
    }
}

//b. El número de agencia que obtuvo la máxima cantidad de pasajes vendidos.
void punto_b(int m[][15],int f,int c)
{
    int cantpasajes_age[15]={0},x,i,max;
    for(x=0;x<c;x++)
    {
        for(i=0;i<f;i++)
        {
            cantpasajes_age[x]+=m[i][x];
        }
    }
    max=cantpasajes_age[0];
    for(x=1;x<c;x++)
    {
        if(cantpasajes_age[x]>max)
            max=cantpasajes_age[x];
    }
    printf("\nLa mayor cantidad de pasajes vendidos fue de %d, de la/s agencia/s nro: ",max);
    for(x=0;x<c;x++)
    {
        if(cantpasajes_age[x]==max)
            printf("\n%d",x+1);
    }
}
