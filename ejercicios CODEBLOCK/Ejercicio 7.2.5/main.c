/*7.2.5 Se desea desarrollar un sistema de reservas de entradas para un cine.
La sala consta de 12 filas numeradas de la 1 a la 12 y cada fila tiene 9 butacas numeradas
a partir de la columna central, con las butacas impares a la derecha y las pares a la izquierda,
como en el siguiente esquema:
8 6 4 2 1 3 5 7 9
Para la carga, se debe mostrar al usuario un esquema con las butacas disponibles y reservadas,
 marcando con la letra D las disponibles y con la letra R las reservadas.
Por cada reserva se debe solicitar la fila y número de butaca a reservar.
Cada vez que se realice una reserva se deberá actualizar el esquema que muestra las butacas.
Si la butaca seleccionada ya estaba ocupada se debe informar al usuario para que seleccione otra.
 El proceso de reserva finaliza con una fila con un número negativo.
Al finalizar mostrar:
a. la cantidad de asientos disponibles y la cantidad de asientos reservados.
b. los números de filas que quedaron vacías.
c. la o las filas con mayor cantidad de espectadores.
d. un listado con la cantidad de personas que se sentaron en los mismos números
de butacas en todo el cine ordenado de mayor a menor. Por ejemplo:
Butaca Cantidad
1 20
3 15
2 10
..............*/

#include <stdio.h>
#include <stdlib.h>

void inicializar (char[12][9],int,int);
void mostrar (char[][9],int,int);
void reserva (char [][9],int,int);
void contardisponibles(char [][9],int,int);
void filasvacias (char[][9],int,int);
void contarporfila (char[][9],int[],int,int);
void contarporbutaca (char[][9],int[],int,int);
void ordenar (int[],int[],int);

int main()
{
    int filas[12],columnas[9],butacas[9]={8,6,4,2,1,3,5,7,9};
    char m[12][9];
    inicializar(m,12,9);
    reserva(m,12,9);
    contardisponibles(m,12,9);//puntoA
    filasvacias(m,12,9);//puntoB
    contarporfila(m,filas,12,9);//puntoC
    contarporbutaca(m,columnas,12,9);//puntoD
    ordenar(columnas,butacas,9);
    return 0;
}

void inicializar(char m[][9],int f, int c)
{
    int x,i;
    for(x=0;x<f;x++)
    {
        for(i=0;i<c;i++)
        {
            m[x][i]='D';
        }
    }
}

void mostrar(char m[12][9], int f,int c)
{
    int x,i;
    system("cls");
    printf("Cine UNLaM");
    printf("\n                 Butaca\n");
    printf("          8 6 4 2 1 3 5 7 9 ");
    for(x=0;x<f;x++)
    {
        printf("\nFila: %2d ",x+1);
        for(i=0;i<c;i++)
        {
            printf(" %c",m[x][i]);
        }
    }
}

void reserva(char m[12][9], int f, int c)
{
    int num,buta,sen;
    mostrar(m,f,c);
    do
    {
        printf("\nIngrese el numero de fila (finaliza con un numero negativo): ");
        scanf("%d",&num);
        if (num>12)
            printf("\nEl numero de fila NO EXISTE");
    }while(num>12);
    while(num>0)
    {
        do
        {
            printf("\nIngrese la butaca que desea: ");
            scanf("%d",&buta);
            if(buta<1||buta>9)
                printf("\nEl numero de butaca NO EXISTE");
        }while(buta<1||buta>9);
        switch(buta)
        {
        case 8:
            buta=0;
            break;
        case 6:
            buta=1;
            break;
        case 4:
            buta=2;
            break;
        case 2:
            buta=3;
            break;
        case 1:
            buta=4;
            break;
        case 3:
            buta=5;
            break;
        case 5:
            buta=6;
            break;
        case 7:
            buta=7;
            break;
        case 9:
            buta=8;
            break;
        }
        if (m[num-1][buta]=='D')
            m[num-1][buta]='R';
        else
        {
            printf("\nEl lugar seleccionado ESTA OCUPADO ");
            printf("\nPresione 0 para elegir otro ");
            scanf("%d",&sen);
        }
        mostrar(m,f,c);
        do
        {
            printf("\nIngrese el numero de fila (finaliza con un numero negativo): ");
            scanf("%d",&num);
            if (num>12)
                printf("\nEl numero de fila NO EXISTE");
        }while(num>12);
    }
}

//a. la cantidad de asientos disponibles y la cantidad de asientos reservados.
void contardisponibles(char m[][9],int f,int c)
{
    int x,i,cont=0;
    for(x=0;x<f;x++)
    {
        for(i=0;i<c;i++)
        {
            if(m[x][i]=='D')
                cont++;
        }
    }
    printf("\nLa cantidad de asientos disponibles es de: %d",cont);
    printf("\nLa cantidad de asientos reservados es de: %d",(12*9)-cont);
}

//b. los números de filas que quedaron vacías.
void filasvacias(char m[][9],int f,int c)
{
    int x,i;
    for(x=0;x<f;x++)
    {
        i=0;
        while(i<c && m[x][i]!='R')
            i++;
        if(i==c)
            printf("\nLa fila %d esta vacia",x+1);
    }
}

//c. la o las filas con mayor cantidad de espectadores.
void contarporfila(char m[][9],int fil[], int f, int c)
{
    int x,i,cont=0,max;
    for(x=0;x<f;x++)
    {
        for(i=0;i<c;i++)
        {
            if(m[x][i]=='R')
                cont++;
        }
        fil[x]=cont;
        cont=0;
    }
    max=fil[0];
    for(x=1;x<f;x++)
    {
        if(fil[x]>max)
            max=fil[x];
    }
    printf("\nLa mayor cantidad de reservas por filas fue de %d, dada en la/s fila/s nro:",max);
    for(x=0;x<f;x++)
    {
        if(fil[x]==max)
            printf("\n%d ",x+1);
    }
}

/*d. un listado con la cantidad de personas que se sentaron en los mismos números
de butacas en todo el cine ordenado de mayor a menor. Por ejemplo:
Butaca Cantidad
1 20
3 15
2 10
..............*/
void contarporbutaca (char m[][9], int colum[], int f, int c)
{
    int x,i;//,cont=0;
    for(x=0;x<c;x++)
    {
        colum[x]=0;
        for(i=0;i<f;i++)
        {
            if(m[i][x]=='R')
                colum[x]++;
        }
    }
}

void ordenar(int colum[], int butacas[], int c)
{
    int x,i,aux;
    for(x=0;x<c;x++)
    {
        for(i=0;i<c-1-x;i++)
        {
            if(colum[i]<colum[i+1])
            {
                aux=colum[i];
                colum[i]=colum[i+1];
                colum[i+1]=aux;

                aux=butacas[i];
                butacas[i]=butacas[i+1];
                butacas[i+1]=aux;
            }
        }
    }
    /*Butaca Cantidad
1 20
3 15
2 10*/
    printf("\nBUTACA:\t\tCANTIDAD:");
    for(x=0;x<c;x++)
    {
        printf("\n%d\t\t%d",butacas[x],colum[x]);
    }
}
