/*7.2.15 BATALLA NAVAL: Realizar el juego con un tablero de 5x5.
Inicialmente el retador deberá ingresar la ubicación de sus barcos indicando las coordenadas donde se encuentra.
Los barcos ocupan un solo casillero y se deben ubicar 5 barcos en distintas posiciones.
La matriz a utilizar es de char inicializándola con espacio en blanco y marcando la ubicación de los barcos con la letra B.
Una vez ubicado los barcos se muestra al jugador una pantalla con las coordenadas para que pueda realizar su disparo.
 En caso de no encontrar un barco en la posición indicada se debe poner en la celda de la matriz una letra A (agua).
 Si se encuentra un barco se marcará como hundido con la letra X. Cada vez que se realiza un disparo se debe actualizar
 la matriz y mostrarla en pantalla pero sin mostrar la ubicación de los barcos (letra B). Se debe mostrar si el barco fue
 hundido con la letra X. Contar la cantidad de disparos necesarios para hundir los 5 barcos de forma que pueda desafiar a
 la otra persona a resolverlo en menos disparos.
Complementos:
a. Mejorar el juego al no permitir ubicar barcos en casilleros adyacentes teniendo en cuenta que al hundir
un barco se deberán marcar todos los casilleros como agua (letra A).
b. Agregar la posibilidad de poner barcos de distinto tamaño, por ejemplo, 2 barcos de 2 casilleros y 3 de un casillero,
lo que implica que un barco estará hundido solo cuando se alcancen con un disparo en todas sus partes.*/

#include <stdio.h>
#include <stdlib.h>

void mostrar(char[][5],int,int);
int comprobarEstado(char[][5],int,int);

int main()
{
    int x,fila,col,gano=0,cant_disparos=0;
    char m[5][5]={0};
    mostrar(m,5,5);
    for(x=0;x<5;x++)
    {
        do
        {
            printf("\nIngrese las coordenadas en donde quiere ubicar su barco nro%d:  ",x+1);
            scanf("%d %d",&fila,&col);
        }while(fila<1||fila>5||col<1||col>5);
        m[fila-1][col-1]='B';
        mostrar(m,5,5);
    }
    while(gano==0)
    {
        do
        {
            printf("\nIngrese las coordenadas en donde quiere realizar su disparo[fila-columna]: ");
            scanf("%d %d",&fila,&col);
        }while(fila<1||fila>5||col<1||col>5);
        cant_disparos++;
        if(m[fila-1][col-1]=='B')
            m[fila-1][col-1]='X';
        else
            m[fila-1][col-1]='A';
        mostrar(m,5,5);
        gano=comprobarEstado(m,5,5);
    }
    printf("\n\nFELICIDADES GANO!!!");
    printf("Cantidad de disparos: %d",cant_disparos);
    return 0;
}

void mostrar(char m[][5],int f,int c)
{
    int x,i;
    system("cls");
    printf("\n     1        2        3        4        5\n");
    for(x=0; x<f; x++)
    {
        printf("\n %d",x+1);
        for(i=0; i<c; i++)
        {
            if(m[x][i]==0||m[x][i]=='B')
                printf("  |___|  ");

            else
            {
                printf("  | %c |  ",m[x][i]);
            }
        }
    }
}

int comprobarEstado(char m[][5],int f,int c)
{
    int x,i,cont=0,gano;
    for(x=0;x<f;x++)
    {
        for(i=0;i<c;i++)
        {
            if(m[x][i]=='X')
                cont++;
        }
    }
    if(cont==5)
        gano=1;
    else
        gano=0;
    return gano;
}
