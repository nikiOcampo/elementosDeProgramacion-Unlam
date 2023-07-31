/*La INMOBILARIA “TU HOGAR” nos encarga un programa que les permita hacer la carga
de movimientos realizados durante el semestre pasado y les permita obtener algunos informes.
Para hacer dicho informe se cuenta con los siguientes datos:
- Código Cliente (Char 10) formado dos primeros caracteres con iniciales Apellido y Nombre ej: ME0023330
- Mes (1 a 12)
- Operación (entero) 1- Venta, 2- Reserva, 3-Alquiler,4- Varios.
- Importe (Mayor a 0)
Finaliza la carga con un cliente igual “Salimos”.
Debemos sacar los siguientes informes:
1 El Importe Total que ingreso por Operación. Por separado y total.
2 Informar de Mayor a Menor el siguiente Listado (no mostrar mes con 0 Importe).
 Listado por Mes de Mayor a Menor Importe Ingresado
 Mes Importe
 11 $ 12.233.000
 12 $ 11.987.000
 07 $ 8.900.000
3 Informar el Total de Comisiones Cobradas por Ventas, durante todo el periodo
procesado. (la comisión es un 3 % del importe).
4 El Nombre de Cliente que realizo mayor Importe, Operación
 Ejemplo:
 el Cliente: MO0023330 realizo la Mayor operación de: Venta con: $1.245.000
Realizar dos funciones:
a) Validar (Mes, Operación e Importe) b) Ordenar. C) Punto 4*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int LeerYValidar (int, int,int);
float validarfloat(int);
void punto_A(float[][12],int,int);
void punto_B(float[][12],int,int);
void punto_C(float[],int);
void punto_D(char[][10],float [],int);

int main()
{
    int x=0,mes,operacion;
    char cod_clientes[100][10];
    float importe,m[4][12]={{0}},import[100];
    printf("\nIngrese el codigo de cliente:");
    fflush(stdin);
    gets(cod_clientes[x]);
    while((strcmpi(cod_clientes[x],"Salimos"))!=0)
    {
        mes=LeerYValidar(1,12,1);
        operacion=LeerYValidar(1,4,2);
        importe=validarfloat(0);
        import[x]=importe;
        m[operacion-1][mes-1]+=importe;
        x++;
        system("cls");
        printf("\nIngrese el codigo de cliente:");
        fflush(stdin);
        gets(cod_clientes[x]);
    }
    system("cls");
    punto_A(m,4,12);
    punto_B(m,4,12);
    punto_C(import,x);
    punto_D(cod_clientes,import,x);
    return 0;
}

int LeerYValidar(int x ,int y,int n)
{
    int dato;
    do
    {
        if(n==1) printf("\nIngrese el mes: ");
        if(n==2) printf("\nIngrese el numero de operacion: \n1- Venta\n2- Reserva,\n3- Alquiler\n4- Varios\n");
        scanf("%d",&dato);
    }while(dato<x||dato>y);
    return dato;
}


float validarfloat (int n)
{
    float dato;
    do
    {
        printf("\nIngrese el importe: ");
        scanf("%f",&dato);
    }while(dato<0);
    return dato;
}

//1 El Importe Total que ingreso por Operación. Por separado y total.
void punto_A(float m[4][12],int f,int c)
{
    int x,i;
    float suma_fila[4]={0},total=0;
    for(x=0;x<f;x++)
    {
        for(i=0;i<c;i++)
        {
            suma_fila[x]+=m[x][i];
        }
        total+=suma_fila[x];
    }
    for(x=0;x<f;x++)
    {
        printf("\nEl importe total de la operacion nro %d es de: %0.2f ",x+1,suma_fila[x]);
    }
    printf("\nEL total de ingresos de todas las operaciones es de: %0.2f",total);
}

/*2 Informar de Mayor a Menor el siguiente Listado (no mostrar mes con 0 Importe).
 Listado por Mes de Mayor a Menor Importe Ingresado
 Mes Importe
 11 $ 12.233.000
 12 $ 11.987.000
 07 $ 8.900.000*/
void punto_B(float m[][12],int f,int c)
{
    int x,i,meses[12]={1,2,3,4,5,6,7,8,9,10,11,12},sen=0,aux1;
    float suma_colum[12]={0},aux;
    for(x=0;x<c;x++)
    {
        for(i=0;i<f;i++)
        {
            suma_colum[x]+=m[i][x];
        }
    }
    while(sen==0)
	{
		sen=1;
		for(i=0;i<c-1;i++)
		{
			if(suma_colum[i]<suma_colum[i+1])
			   {
			   	aux=suma_colum[i];
			   	suma_colum[i]=suma_colum[i+1];
			   	suma_colum[i+1]=aux;
			   	aux1=meses[i];
			   	meses[i]=meses[i+1];
			   	meses[i+1]=aux1;
			   	sen=0;
			   }
		}
    }
   printf("\n MES:        IMPORTE:");
   for(i=0;i<12;i++)
     {
         if(suma_colum[i]!=0)
            printf("\n %d\t\t%0.2f",meses[i],suma_colum[i]);
	 }
}

/*3 Informar el Total de Comisiones Cobradas por Ventas, durante todo el periodo
procesado. (la comisión es un 3 % del importe).*/
void punto_C(float importes[],int n)
{
    int x;
    float total_comisiones=0;
    for(x=0;x<n;x++)
    {
        total_comisiones+=importes[x]*0.03;
    }
    printf("\nEl total de comisiones cobradas es de %0.2f",total_comisiones);
}

/*4 El Nombre de Cliente que realizo mayor Importe, Operación
 Ejemplo:
 el Cliente: MO0023330 realizo la Mayor operación de: Venta con: $1.245.000*/

void punto_D (char cliente[100][10],float importe[],int n)//numeros no correlativos
{
    int i,j;
    float max;
    max=importe[0];
    for (i=1;i<n;i++)
    {
        if (importe[i]>max)
            max=importe[i];
    }
    printf("\nEl importe mas alto es de %0.2f, realizado por el/los cliente/s:",max);
    for(j=0;j<n;j++)
    {
        if(importe[j]==max)
            printf("\n%s",cliente[j]);
    }
}
