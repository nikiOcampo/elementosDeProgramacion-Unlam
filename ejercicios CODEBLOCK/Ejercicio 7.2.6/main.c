/*7.2.6 Se solicita modificar el programa anterior para que además de la butaca y fila
ingrese la cantidad de butacas de la reserva. En dicho caso se deberá verificar si existen
a partir de la butaca ingresada la cantidad suficiente de butacas disponibles consecutivas
(tomar siempre hacia la derecha del seleccionado).
 Si están disponibles reservar todas las butacas, sino mostrar un mensaje de error.*/

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
    int num,buta,sen,numero,ban=0,x;
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
        {
            do
            {
                printf("\nIngrese la cantidad de butacas que desea reservar hacia la derecha(contando la ingresada): ");
                scanf("%d",&numero);
            }while(numero>9);
            if(buta+numero>9)
               {
                   printf("\nNo es posible reservar esa cantidad de asientos a la derecha");
                   printf("\nPresione 0 para elegir otro ");
                   scanf("%d",&sen);
               }
            else
            {
                ban=0;
                for(x=0;x<numero;x++)
                {
                    if(m[num-1][buta+x]=='D')
                        ban++;
                }
                if(ban==numero)
                {
                    for(x=0;x<numero;x++)
                       {
                           m[num-1][buta+x]='R';
                       }
                }
                else
                {
                    printf("\nNo es posible reservar esa cantidad de asientos ya que alguno esta OCUPADO");
                    printf("\nPresione 0 para elegir otro ");
                    scanf("%d",&sen);
                }
            }
        }
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
