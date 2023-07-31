/*7.2.11 La cadena de supermercados NORTE, tiene 40 sucursales y
comercializa 120 rubros de distintas mercaderías. La Casa Central recibe a diario
las notas de pedido de mercaderías emitidas por cada una de las sucursales.
Se ingresa por teclado las unidades pedidas (estos datos se ingresan hasta que aparece una sucursal igual a 99,
los datos vienen desordenados, y puede venir más de una información de una misma sucursal y el mismo rubro):
• Número de sucursal (1 a 40).
• Código de rubro (1 a 120).
• Cantidad de unidades pedidas.
Informar:
a. La cantidad de pedidos por sucursal.
b. Cuál fue la sucursal que pidió la menor cantidad en total (puede haber varias sucursales que tienen el mismo valor mínimo).
FUNCIONES
I. Para inicializar la matriz.
II. Para mostrar el resultado del punto b.*/

#include <stdio.h>
#include <stdlib.h>

void inicializar (int[][120],int,int,int[],int[]);
void mostrar_puntoB(int[][120],int[],int,int);

int main()
{
    int m[40][120],cod_suc[40],cod_rubro[120],cantpedidos_sucu[40]={0};
    int numero_sucursal,numero_rubro,cant,x,i,cont[40]={0};
    inicializar(m,40,120,cod_suc,cod_rubro);
    do
    {
        printf("Ingrese el numero de sucursal: ");
        scanf("%d",&numero_sucursal);
        cont[numero_sucursal-1]++;
    }while((numero_sucursal<1||numero_sucursal>40)&& numero_sucursal!=99);
    while(numero_sucursal!=99)
    {
        do
        {
            printf("\nIngrese el codigo de rubro:");
            scanf("%d",&numero_rubro);
        }while(numero_rubro<1||numero_rubro>120);
        printf("\nIngrese la cantidad de unidades solicitadas: ");
        scanf("%d",&cant);
        m[numero_sucursal-1][numero_rubro-1]+=cant;
        do
        {
            printf("Ingrese el numero de sucursal: ");
            scanf("%d",&numero_sucursal);
            cont[numero_sucursal-1]++;
        }while((numero_sucursal<1||numero_sucursal>40)&& numero_sucursal!=99);
    }
    //a. La cantidad de pedidos por sucursal.
    for(x=0;x<40;x++)
    {
        printf("\nLa cantidad de pedidos de la sucursal nro %d, es de %d",x+1,cont[x]);
    }
    for(x=0;x<40;x++)
    {
        for(i=0;i<120;i++)
        {
            cantpedidos_sucu[x]+=m[x][i];
        }
    }
    /*for(x=0;x<40;x++)
    {
        printf("\nLa cantidad de pedidos de la sucursal nro %d es de: %d ",cod_suc[x],cantpedidos_sucu[x]);
    }*/
    mostrar_puntoB(m,cantpedidos_sucu,40,120);
    return 0;
}

void inicializar(int m[][120],int f,int c,int sucursal[],int rubro[])
{
    int x,i;
    for(x=0;x<f;x++)
    {
        sucursal[x]=x+1;
        for(i=0;i<c;i++)
        {
            m[x][i]=0;
            rubro[i]=i+1;
        }
    }
}

//b. Cuál fue la sucursal que pidió la menor cantidad en total (puede haber varias sucursales que tienen el mismo valor mínimo).
void mostrar_puntoB(int m[][120], int cantporsucursal[],int f,int c)
{
    int x,min;
    min=cantporsucursal[0];
    for(x=1;x<f;x++)
    {
        if(cantporsucursal[x]<min)
        {
            min=cantporsucursal[x];
        }
    }
    printf("\nLa menor cantidad de unidades pedidas fue de %d, de la/s sucursal/es nro:",min);
    for(x=0;x<f;x++)
    {
        if(cantporsucursal[x]==min)
            printf("\n%d",x+1);
    }
}
