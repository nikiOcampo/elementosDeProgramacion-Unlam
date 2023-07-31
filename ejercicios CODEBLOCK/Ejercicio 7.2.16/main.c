/*7.2.16 Realizar el juego de 3 líneas con un tablero de 6 filas por 10 columnas.
 El juego será para dos jugadores, uno utilizará fichas redondas representadas por la letra O y
 el otro jugador marcará sus fichas con la letra X.
El juego se desarrolla de a un turno por vez donde el jugador elije sobre que columna tirar su
ficha (numerarlas del 1 al 10). La ficha debe “caer” hasta la primera posición libre.
Cada vez que ponga una ficha en el tablero deberá verificarse si se ha ganado la partida al tener 3
fichas del mismo tipo consecutivas. Si se llena todo el tablero y ningún participante gana, se mostrará “empate”.
a. Chequear si se ganó el juego teniendo en cuenta si se forma 3 en línea solo en forma vertical.
b. Chequear si se ganó el juego teniendo en cuenta si se forma 3 en línea tanto en forma vertical como horizontal.
c. Chequear si se ganó el juego teniendo en cuenta si se forma 3 en cualquier dirección (vertical, horizontal, o diagonal).*/

#include <stdio.h>
#include <stdlib.h>

void mostrar(char[][10],int,int);
int comprobarEstado(char[][10],int,int);

int main()
{
    int columna,gano=0,x;
    char m[6][10]={0};
    while(gano==0)
    {
        mostrar(m,6,10);
        do
        {
            printf("\nJugador 1: ");
            printf("\nIngrese la columna donde desea tirar su ficha: ");
            scanf("%d",&columna);
        }while(columna<1||columna>10);
        for(x=5;x>=0;x--)
        {
            if(m[x][columna-1]==0)
            {
                 m[x][columna-1]='O';
                 x=0;
            }
        }
        mostrar(m,6,10);
        gano=comprobarEstado(m,6,10);
        if(gano==0)
        {
            do
            {
                printf("\nJugador 2: ");
                printf("\nIngrese la columna donde desea tirar su ficha: ");
                scanf("%d",&columna);
            }while(columna<1||columna>10);
            for(x=5;x>=0;x--)
            {
                if(m[x][columna-1]==0)
                {
                     m[x][columna-1]='X';
                     x=0;
                }
            }
            mostrar(m,6,10);
            gano=comprobarEstado(m,6,10);
        }
    }
    if(gano==1)
        printf("\n\n\n****GANADOR: JUGADOR 1!!!!****");
    if(gano==2)
        printf("\n\n\n****GANADOR: JUGADOR 2!!!!****");
    if(gano==3)
        printf("\n*****EMPATE******");
    return 0;
}

void mostrar(char m[][10],int f,int c)
{
    int x,i;
    system("cls");
    printf("****JUEGO DE TRES EN LINEA****");
    printf("\nJugador 1: O     Jugador 2: X");
    printf("\n      1        2        3        4        5       6        7        8        9        10\n");
    for(x=0; x<f; x++)
    {
        printf("\n %d",x+1);
        for(i=0; i<c; i++)
        {
            if(m[x][i]==0)
                printf("  |___|  ");

            else
            {
                printf("  | %c |  ",m[x][i]);
            }
        }
    }
}

/*a. Chequear si se ganó el juego teniendo en cuenta si se forma 3 en línea solo en forma vertical.
b. Chequear si se ganó el juego teniendo en cuenta si se forma 3 en línea tanto en forma vertical como horizontal.
c. Chequear si se ganó el juego teniendo en cuenta si se forma 3 en cualquier dirección (vertical, horizontal, o diagonal).*/

int comprobarEstado(char m[][10],int f,int c)
{
    int x,i,gano,cont=0;
    for(x=0;x<c;x++)//verticales
    {
        for(i=5;i>1;i--)
        {
            if(m[i][x]=='O'&&m[i-1][x]=='O'&&m[i-2][x]=='O')
                gano=1;
            if(m[i][x]=='X'&&m[i-1][x]=='X'&&m[i-2][x]=='X')
                gano=2;
        }
    }
    for(x=0;x<f;x++)//horizontales
    {
        for(i=0;i<c-1;i++)
        {
            if(m[x][i]=='O'&&m[x][i+1]=='O'&&m[x][i+2]=='O')
                gano=1;
            if(m[x][i]=='X'&&m[x][i+1]=='X'&&m[x][i+2]=='X')
                gano=2;
        }
    }
    for(x=0;x<6;x++)//diafonales
    {
        for(i=0;i<10;i++)
        {
            if((m[x][i]=='O'&&m[x+1][i-1]=='O'&&m[x+2][i-2]=='O')||(m[x][i]=='O'&&m[x-1][i-1]=='O'&&m[x-2][i-2]=='O'))
                gano=1;
            if((m[x][i]=='X'&&m[x+1][i-1]=='X'&&m[x+2][i-2]=='X')||(m[x][i]=='X'&&m[x-1][i-1]=='X'&&m[x-2][i-2]=='X'))
                gano=2;
        }
    }
    if(gano!=1&&gano!=2)
        gano=0;
    for(x=0;x<6;x++)//empate
    {
        for(i=0;i<10;i++)
        {
            if(m[x][i]!=0)
                cont++;
        }
    }
    if(cont==60)
        gano=3;
    return gano;
}
