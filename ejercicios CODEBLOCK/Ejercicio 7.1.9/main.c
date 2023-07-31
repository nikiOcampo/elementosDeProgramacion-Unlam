/*Se debe ingresar los códigos de 15 productos de una empresa (números de 3 dígitos).
Luego se ingresan las ventas realizadas durante el día. Por cada venta se ingresa código de vendedor,
código de artículo y cantidad.
Los vendedores son 5 y están codificados en forma correlativa de 1001 a 1005.
Se puede recibir más de una venta de un mismo vendedor y artículo.
El ingreso de datos finaliza con código de vendedor igual a 0. Se desea:
a. Mostrar un listado ordenado de mayor a menor por cantidad de unidades vendidas.
b. Indicar el/los vendedores que realizaron menor cantidad de ventas (no de unidades).*/

#include <stdio.h>
#include <stdlib.h>

int carga (int[], int [], int);
int busqueda_secuencial (int[], int, int);
void mostrarLista (int[],int[],int);
void ordenamiento (int[], int[],int);
int minimo (int[],int);
void mostrarMinimo (int[],int[],int,int);

int main()
{
    int cantDeVentas,cod_productos[15],cantidades[15]={0}/*,cod_vendedor[5]={1001,1002,1003,1004,1005}*/;
    cantDeVentas= carga(cod_productos,cantidades,15);
    ordenamiento(cod_productos,cantidades,cantDeVentas);
    printf("\nLa cantidad de ventas realizadas fueron %d",cantDeVentas);

    return 0;
}

int carga (int cod[],int cant[], int n)
{
    int x,codigo, num_vendedor,j=0,canti,codi,sen,min;
    int cant_ventas[5]={0},cod_vendedor[5]={1001,1002,1003,1004,1005};
    for(x=0;x<15;x++)
    {
        do
        {
            printf("Ingrese el codigo del producto %d :",x+1);
            scanf("%d",&codigo);
            if (codigo<100||codigo>999)
                printf("\nEl codgio es incorrecto, debe tener 3 cifras\n");
        }while(codigo<100||codigo>999);
        cod[x]=codigo;
    }
    do
    {
        printf("Ingrese el numero de vendedor: ");
        scanf("%d",&num_vendedor);
        if (num_vendedor<1001||num_vendedor>1005)
            printf("\nEl numero de vendedor no existe");
        if (num_vendedor==0)
            printf("\nFin de la carga");
        switch(num_vendedor)
        {
            case 1001:
                cant_ventas[0]++;
                break;
            case 1002:
                cant_ventas[1]++;
                break;
            case 1003:
                cant_ventas[2]++;
                break;
            case 1004:
                cant_ventas[3]++;
                break;
            case 1005:
                cant_ventas[4]++;
                break;
        }
    }while((num_vendedor<1001||num_vendedor>1005)&& num_vendedor!=0);
    while(num_vendedor!=0)
    {
        j++;
        do
        {
            printf("Ingrese el codigo del articulo: ");
            scanf("%d",&codi);
            sen= busqueda_secuencial(cod,15,codi);
            if(sen<0)
                printf("El codigo del articulo no existe\n");
        }while(sen<0);
        if (sen>=0)
        {
            printf("Ingrese la cantidad de ese producto que solicita: ");
            scanf("%d",&canti);
            cant[sen]+=canti;
            do
            {
                printf("Ingrese el numero de vendedor: ");
                scanf("%d",&num_vendedor);
                if ((num_vendedor<1001||num_vendedor>1005)&& num_vendedor!=0)
                    printf("\nEl numero de vendedor no existe");
                if (num_vendedor==0)
                    printf("\nFin de la carga");
                switch(num_vendedor)
                {
                    case 1001:
                        cant_ventas[0]++;
                        break;
                    case 1002:
                        cant_ventas[1]++;
                        break;
                    case 1003:
                        cant_ventas[2]++;
                        break;
                    case 1004:
                        cant_ventas[3]++;
                        break;
                    case 1005:
                        cant_ventas[4]++;
                        break;
                }
            }while((num_vendedor<1001||num_vendedor>1005)&& num_vendedor!=0);
        }
    }
    min= minimo(cant_ventas,5);
    mostrarMinimo(cod_vendedor,cant_ventas,min,5);
    return j;
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

void ordenamiento(int prod[],int cant[],int n)
{
    int x,j,aux;
    for(x=0;x<n-1;x++)
    {
        for(j=0;j<n-1-x;j++)
        {
            if(cant[j]>cant[j+1])
            {
                aux=prod[j];
                prod[j]=prod[j+1];
                prod[j+1]=aux;

                aux=cant[j];
                cant[j]=cant[j+1];
                cant[j+1]=aux;
            }
        }
    }
    mostrarLista (prod,cant,15);
}


void mostrarLista (int prod[], int cant[], int n)
{
    int x;
    printf("\nCODIGOS:\t\tCANTIDADES:\n");
    for(x=0;x<n;x++)
    {
        printf("\n%d\t\t%d",prod[x],cant[x]);
    }

}

int minimo ( int cantidades[], int n)
{
    int min,i;
    min= cantidades[0];
    for (i=1;i<n;i++)
    {
        if (cantidades[i]<min)
            min=cantidades[i];
    }
    return min;
}

void mostrarMinimo (int vendedores[],int ventas[], int min , int n)
{
    int i;
    printf("\n\nLa menor cantidad de ventas fue de %d que la tuvieron el/los vendedores:\n", min);
    for (i=0;i<n;i++)
    {
        if(ventas[i]==min)
            printf("\n%d\n",vendedores[i]);
    }
}

