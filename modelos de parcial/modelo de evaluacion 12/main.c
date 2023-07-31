/*La empresario J.R. Juan Ramon, desea realizar un informe sobre las ventas realizadas por cada
uno de sus empleados. Tenemos registradas las ventas en montos, realizadas durante un
determinado mes, los datos son:
1- Realizar la carga de los 10 empleados, solo el Nombre en primer lugar.
2- Las Ventas de cada empleado:
o Nombre (char de 25).
o dia (1,24).
o MontoVenta (>0).
Finaliza la carga de Ventas con un Nombre = “Termino”
Los datos de cada empleado deben ser verificados con la función correspondiente. (Carga de
punto 1) Usar una Matriz para la carga de los distintos montos, puede existir mas de una venta
por día, Empleado.
Confeccionar un programa, diagrama y codificación que permita, a partir de dicha información,
poder realizar los siguientes puntos:
a) Emitir un informe que indique, por día, el total el Monto total Vendido.
b) Informar ordenado de mayor a menor por Monto, el Nombre y monto Vendido.
 LISTADO DE VENTAS ORDENADO POR MONTO DE MAYOR A MENOR
 Nombre Monto
 Marta Rosa $34.000
 Mónica Juana $32.600
 Ximena Varón $21.500
 Ana Pirucha $19.400
 Xxxxxxxxxxx ______
c) El/Los días que más ventas se realizaron. Puede haber varios, informar Dia y Monto.
d) Mostrar el Nombre de los Empleados que no realizaron Ventas
Funciones Obligatorias: Validar día y Monto de Venta, Buscar y Ordenar*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int buscar (char[][25],char[25],int);
int ValidarDia (int, int);
float validarmonto (int);
void mostrar(char[][25],int);
void punto_AyC (float[][10],int,int);
void punto_B (float [][10],int,int,char[][25]);
void ordenar(float [10],int,char [][25]);

int main()
{
    int x,pos,dia;
    float m[24][10]={{0}},monto;
    char nombres[10][25],nom[25];
    for(x=0;x<10;x++)
    {
        printf("\nIngrese el nombre del empleado nro %d: ",x+1);
        fflush(stdin);
        gets(nombres[x]);
    }
    system("cls");
    do
    {
        mostrar(nombres,10);
        printf("\nIngrese el nombre del empleado que realizo la venta: ");
        fflush(stdin);
        gets(nom);
        pos=buscar(nombres,nom,10);
        if(pos==-1&&((strcmpi(nom,"Termino"))!=0))
                printf("\nEl empleado ingresado no es valido\n");
    }while(pos==-1&&((strcmpi(nom,"Termino"))!=0));
    while((strcmpi(nom,"Termino"))!=0)
    {
        dia=ValidarDia(1,24);
        monto=validarmonto(0);
        m[dia-1][pos]+=monto;
        do
        {
            mostrar(nombres,10);
            printf("\nIngrese el nombre del empleado que realizo la venta: ");
            fflush(stdin);
            gets(nom);
            pos=buscar(nombres,nom,10);
            if(pos==-1&&((strcmpi(nom,"Termino"))!=0))
                    printf("\nEl empleado ingresado no es valido\n");
        }while(pos==-1&&((strcmpi(nom,"Termino"))!=0));
    }
    system("cls");
    punto_AyC(m,24,10);
    punto_B(m,24,10,nombres);
    return 0;
}

int buscar(char nombres[][25], char nom[25], int n)
{
    int pos=-1,x=0;
    while(pos==-1&&x<n)
    {
        if((strcmpi(nombres[x],nom))==0)
            pos=x;
        else
            x++;
    }
    return pos;
}

int ValidarDia(int x ,int y)
{
    int dato;
    do
    {
        printf("\nIngrese el dia [1 a 24]: ");
        scanf("%d",&dato);
        if(dato<x||dato>y)
            printf("\nEl dia ingresado no es correcto");
    }while(dato<x||dato>y);
    return dato;
}

float validarmonto (int n)
{
    float dato;
    do
    {
        printf("\nIngrese el monto: ");
        scanf("%f",&dato);
    }while(dato<n);
    return dato;
}

void mostrar(char vn[][25],int cant)
{
    int i;
    system("cls");
    printf("\nLista de empleados cargados:\n");
    for (i=0; i<cant; i++)
        puts(vn[i]);
    printf("Salida= Termino");
}

//a) Emitir un informe que indique, por día, el total el Monto total Vendido.
void punto_AyC(float m[][10],int f,int c)
{
    int x,i;
    float suma_fila[24]={0},max;
    for(x=0;x<f;x++)
    {
        for(i=0;i<c;i++)
        {
            suma_fila[x]+=m[x][i];
        }
    }
    printf("\nMonto vendido por dia:");
    printf("\nDIA:           MONTO:");
    for(x=0;x<f;x++)
    {
        printf("\n%d\t\t%0.2f",x+1,suma_fila[x]);
    }
    //c) El/Los días que más ventas se realizaron. Puede haber varios, informar Dia y Monto.
    max=suma_fila[0];
    for(x=1;x<f;x++)
    {
        if(suma_fila[x]>max)
            max=suma_fila[x];
    }
    printf("\nEl mayor monto obtenido fue de %0.2f obtenido los dias: ",max);
    for(x=0;x<f;x++)
    {
        if(suma_fila[x]==max)
            printf("\n%d",x+1);
    }
}

//b) Informar ordenado de mayor a menor por Monto, el Nombre y monto Vendido.
/*LISTADO DE VENTAS ORDENADO POR MONTO DE MAYOR A MENOR
 Nombre Monto
 Marta Rosa $34.000
 Mónica Juana $32.600
 Ximena Varón $21.500
 Ana Pirucha $19.400
 Xxxxxxxxxxx ______*/
 void punto_B(float m[][10],int f,int c,char nombres[][25])
{
    int x,i;
    float suma_colum[10]={0};
    for(x=0;x<c;x++)
    {
        for(i=0;i<f;i++)
        {
            suma_colum[x]+=m[i][x];
        }
    }
    ordenar(suma_colum,10,nombres);
    //d) Mostrar el Nombre de los Empleados que no realizaron Ventas
    printf("\nLos siguientes empleados no realizaron ventas: ");
    for(x=0;x<c;x++)
    {
        if(suma_colum[x]==0)
            printf("\n%s",nombres[x]);
    }
}

void ordenar(float monto[], int c,char nombres[10][25])
{
    int x,i,aux;
    char aux1[25];
    for(x=0;x<c;x++)
    {
        for(i=0;i<c-1-x;i++)
        {
            if(monto[i]<monto[i+1])
            {
                aux=monto[i];
                monto[i]=monto[i+1];
                monto[i+1]=aux;

                strcpy(aux1,nombres[i]);
                strcpy(nombres[i],nombres[i+1]);
                strcpy(nombres[i+1],aux1);
            }
        }
    }
    printf("\nLISTADO DE VENTAS ORDENADO POR MONTO DE MAYOR A MENOR:");
    printf("\nNOMBRE:\t\tMONTO:");
    for(x=0;x<c;x++)
    {
        if(monto[x]!=0)
            printf("\n%s\t\t%0.2f",nombres[x],monto[x]);
    }
}

