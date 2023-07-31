/*Una empresa de venta de productos Odontológicos, “La Nona”, desea analizar las ventas efectuadas por sus 27 vendedores diariamente.
Desarrollar el diagrama de lógica y su correspondiente codificación C para que permita:
a)	Confeccionar y utilizar una FUNCIÓN para ingresar desde teclado los datos de los vendedores:
Por cada vendedor, se ingresa
. Número de vendedor (números no consecutivos de 3 cifras)
. Sector  (1 a 5) 1-Mostrador/2-Capital/3.Gran Bs.As./4-Interior/5-Terceros

b)	Procesar luego los datos de las ventas del día, que se ingresan por teclado, con el siguiente detalle:
. Número de cliente (1 a 1000)
. Código de vendedor  (números no consecutivos de 3 cifras)
. Código de artículo (1 a 100)
. Cantidad vendida (entero > 0)
. Precio unitario (flotante >0)
Estos datos no se ingresan ordenados y la lectura debe detenerse cuando se ingrese un número de cliente igual a cero.
c)	Acumular los importes vendidos por cada vendedor, de todos los artículos e informarlos de menor a mayor, Código y Monto.
d)	Informar el total de importe vendidos correspondiente a cada sector.
e)	Cual fue el vendedor que menos monto vendió y a que sector corresponde.
*/

#include <stdio.h>
#include <stdlib.h>

int LeerYValidar(int,int,int);
int busqueda_secuencial (int[],int,int);
float validarfloat (int);
void ordenamiento(int[],float[],int n);

int main()
{
    int num_vend[7],sector[7],x,num_cliente,i=0,cod_vendedor,pos,cod_aticulo,cant_vendida;
    float precio,imp_x_vendedor[7]={0},imp_x_sector[5]={0},min;
    for(x=0;x<7;x++)
    {
        num_vend[x]=LeerYValidar(100,999,1);
        sector[x]=LeerYValidar(1,5,2);
    }
    system("cls");
    num_cliente=LeerYValidar(0,1000,3);
    while(num_cliente!=0)
    {
        do
        {
            cod_vendedor=LeerYValidar(0,1000,1);
            pos=busqueda_secuencial(num_vend,7,cod_vendedor);
        }while(pos==-1);
        cod_aticulo=LeerYValidar(1,100,4);
        precio=validarfloat(0);
        cant_vendida=LeerYValidar(0,999999,5);
        imp_x_vendedor[i]+=(float)precio*cant_vendida;
        imp_x_sector[sector[i]-1]+=(float)precio*cant_vendida;
        i++;
        system("cls");
        num_cliente=LeerYValidar(0,1000,3);
    }
    system("cls");
    ordenamiento(num_vend,imp_x_vendedor,7);
    //d)	Informar el total de importe vendidos correspondiente a cada sector.
    printf("\n\nTotal de importe por sector:");
    printf("\nSECTOR:    IMPORTE:");
    for(x=0;x<5;x++)
    {
        printf("\n%d        %0.2f",x+1,imp_x_sector[x]);
    }
    //e)	Cual fue el vendedor que menos monto vendió y a que sector corresponde.
    min=imp_x_vendedor[0];
    for(x=1;x<7;x++)
    {
        if(imp_x_vendedor[x]<min)
            min=imp_x_vendedor[x];
    }
    printf("\nEl/los vendedor/es que menos vendieron fue/ron: ");
    for(x=0;x<7;x++)
    {
        if(min==imp_x_vendedor[x])
            printf("\nVENDEDOR %d, del sector %d",num_vend[x],sector[x]);
    }
    return 0;
}

int LeerYValidar(int x ,int y,int n)
{
    int dato;
    do
    {
        if(n==1) printf("\nIngrese el numero de vendedor: ");
        if(n==2) printf("\nIngrese el sector en el que trabaja: ");
        if(n==3) printf("\ningrese el numero de cliente: ");
        if(n==4) printf("\nIngrese el codigo del articulo: ");
        if(n==5) printf("\ningrese la cantidad vendida de ese articulo: ");
        scanf("%d",&dato);
    }while(dato<x||dato>y);
    return dato;
}

int busqueda_secuencial (int v[], int cant, int elem)
{
    int i, pos;
    i = 0;
    pos = -1;
    while(i < cant && pos == -1)
    {
        if(v[i] == elem)
            pos = i;
        else
            i++;
    }
    return pos;
}

float validarfloat (int n)
{
    float dato;
    do
    {
        printf("\nIngrese el precio: ");
        scanf("%f",&dato);
    }while(dato<n);
    return dato;
}

//Acumular los importes vendidos por cada vendedor, de todos los artículos e informarlos de menor a mayor, Código y Monto.
void ordenamiento(int vendedor[],float importe[],int n)
{
	int sen=0,i,aux;
	float aux1;
	while(sen==0)
	{
		sen=1;
		for(i=0;i<n-1;i++)
		{
			if(importe[i]>importe[i+1])
			   {
			   	aux1=importe[i];
			   	importe[i]=importe[i+1];
			   	importe[i+1]=aux1;
			   	aux=vendedor[i];
			   	vendedor[i]=vendedor[i+1];
			   	vendedor[i+1]=aux;
			   	sen=0;
			   }
		}
    }
   printf("\n Listado Ordenado de menor a mayor de importes por vendedor \n");
   printf("\n   CODIGO:      MONTO: \n");
   for(i=0;i<n;i++)
     {
     	printf("\n    %d        %0.2f",vendedor[i],importe[i]);
	 }
}

