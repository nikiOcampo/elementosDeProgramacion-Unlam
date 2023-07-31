/*La Empresa DENTACOR  S.R.L. que se dedica a la importación y venta productos odontológicos.
Desea controlar las ventas realizadas en uno de sus locales que cuenta con 7 vendedores  y
cuenta también con casi 5000 productos hasta el momento, para ello se cuenta con los
siguientes datos de cada producto (estos datos se ingresan por teclado y finalizan cuando
se ingresa un Cero en Número de Producto):

  Número de Producto (int, entre 3.000 y 11.000).
  Cantidad de unidades en Stock (int, entre 1 y 2000).
  Precio de Producto (float).

Además cuenta con los datos de las ventas que realizan sus 7 vendedores (estos
datos se ingresan por teclado y finalizan cuando se ingresa un Cero en Número de Vendedor):
              Número de Vendedor (int, entre 1 y 7).
              Número de Producto (int, entre 3.000 y 11.000).
              Cantidad de unidades vendidas (int, entre 1 y 100).
NOTA: Rechazar los pedidos de aquellos productos cuyo stock es inferior al pedido.
Determinar e informar:
      a)	Informar el Stock de todos los productos luego de procesar las ventas de sus siete
                Vendedores.
      b)	Informar las comisiones que van a recibir cada uno de sus vendores luego de haber
                procesado todas las ventas.(el % de comisión hasta 10 Unidades 2%, hasta 50 2,5%,más 3%)
      c)	Informar el Producto que más facturo y cual el que menos facturo, luego de haber
                procesado todas las ventas.
    FUNCIONES:
     1. Para cargar en memoria todos los datos que se ingresan de los productos que tiene la empresa.
     2. Para validar producto y vendedor.
*/

#include <stdio.h>
#include <stdlib.h>

int carga(int[],int[],float[],int);
int busqueda_secuencial (int[],int,int);
void blanco(int [],int);
void blanco_float(float [],int);
void punto_b(int[],int,float[]);
void punto_c (int[],float[],int,int[]);

int main()
{
    int nro_producto[5000],stock[5000],cantporvendedor[7]={0};
    int cant,vendedor,pos,prod_vendido,x,vendido;
    float precio[5000];
    cant=carga(nro_producto,stock,precio,5000);
    int cant_vendidas[cant],stock_actualizado[cant];
    blanco(cant_vendidas,cant);
    blanco(stock_actualizado,cant);
    system("cls");
    do
    {
        printf("\nIngrese el numero del vendedor: ");
        scanf("%d",&vendedor);
        if(vendedor<1||vendedor>7)
            printf("\nEl numero de vendedor no existe");
    }while((vendedor<1||vendedor>7)&&vendedor!=0);
    while(vendedor!=0)
    {
        do
        {
            printf("\nIngrese el numero del producto que se vendio: ");
            scanf("%d",&prod_vendido);
            pos=busqueda_secuencial(nro_producto,cant,prod_vendido);
            if(pos==-1)
                printf("\nEl nro de producto no existe");
        }while(pos==-1);
        do
        {
            printf("\nIngrese la cantidad de unidades vendidas: ");
            scanf("%d",&vendido);
            if(vendido>stock[pos])
                printf("\nNo hay dicha cantidad de ese producto");
        }while(vendido>stock[pos]);
        cant_vendidas[pos]+=vendido;
        stock_actualizado[pos]=stock[pos]-cant_vendidas[pos];
        cantporvendedor[vendedor-1]+=vendido;
        do
        {
            printf("\nIngrese el numero del vendedor: ");
            scanf("%d",&vendedor);
            if(vendedor<1||vendedor>7)
                printf("\nEl numero de vendedor no existe");
        }while((vendedor<1||vendedor>7)&&vendedor!=0);
    }
    //a)	Informar el Stock de todos los productos luego de procesar las ventas de sus siete Vendedores.
    printf("\nPRODUCTO: \t STOCK:");
    for(x=0;x<cant;x++)
    {
        printf("\n%d\t\t%d",nro_producto[x],stock_actualizado[x]);
    }
    /*b)	Informar las comisiones que van a recibir cada uno de sus vendores luego de haber
                procesado todas las ventas.(el % de comisión hasta 10 Unidades 2%, hasta 50 2,5%,más 3%)*/
    printf("\nVENDEDOR\tCOMISION QUE RECIBE");
    for(x=0;x<7;x++)
    {
        if(cantporvendedor[x]<11&&cantporvendedor[x]>0)
            printf("\n%d\t\t2 porciento",x+1);
        if(cantporvendedor[x]>10&&cantporvendedor[x]<51)
            printf("\n%d\t\t2,5 porciento",x+1);
        if(cantporvendedor[x]>50)
            printf("\n%d\t\t3 porciento",x+1);
        if(cantporvendedor[x]==0)
            printf("\n%d\t\tNo realizo ventas",x+1);
    }
    //c)	Informar el Producto que más facturo y cual el que menos facturo, luego de haber procesado todas las ventas.
    punto_c(cant_vendidas,precio,cant,nro_producto);
    return 0;
}

int carga (int prod[],int stock[],float precio[],int n)
{
    int x=0,cod;
    do
    {
        printf("Ingrese el numero del producto:");
        scanf("%d",&cod);
        if((cod<3000||cod>11000)&&cod!=0)
            printf("\nCODIGO NO EXISTENTE");
    }while((cod<3000||cod>11000)&&cod!=0);
    while(cod!=0&&x<n)
    {
        prod[x]=cod;
        do
        {
            printf("\nIngrese la cantidad de unidades en stock de ese producto: ");
            scanf("%d",&stock[x]);
            if(stock[x]<1||stock[x]>2000)
                printf("\nLa cantidad ingresada no es valida");
        }while(stock[x]<1||stock[x]>2000);
        do
        {
            printf("\nIngrese el precio del producto: ");
            scanf("%f",&precio[x]);
            if(precio[x]<0)
                printf("\nEl precio ingresado no es valido");
        }while(precio[x]<0);
        x++;
        do
        {
            printf("\nIngrese el numero del producto:");
            scanf("%d",&cod);
            if((cod<3000||cod>11000)&&cod!=0)
                printf("\nCODIGO NO EXISTENTE");
        }while((cod<3000||cod>11000)&&cod!=0);
    }
    return x;
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

void blanco(int a[],int n)
{
    int x;
    for(x=0;x<n;x++)
    {
        a[x]=0;
    }
}
void blanco_float (float a[],int n)
{
    int x;
    for(x=0;x<n;x++)
    {
        a[x]=0;
    }
}


/*Informar el Producto que más facturo y cual el que menos facturo, luego de haber
                procesado todas las ventas.*/
void punto_c (int cant_vendidas[],float precio[],int n,int prod[])
{
    int i,j,x;
    float facturado[n],max,min;
    blanco_float(facturado,n);
    for(x=0;x<n;x++)
    {
        facturado[x]=(float)cant_vendidas[x]*precio[x];
    }
    max=facturado[0];
    min=facturado[0];
    for (i=1;i<n;i++)
    {
        if (facturado[i]>max)
            max=facturado[i];
        if (facturado[i]<min)
            min=facturado[i];
    }
    printf("\nEl/los producto/s que mas facturo fueron: ");
    for(j=0;j<n;j++)
    {
        if(facturado[j]==max)
            printf("\n%d",prod[j]);
    }
    printf("\nQue facturo/raron un total de:%0.2f",max);
    printf("\n\n\nEl/los producto/s que menos facturo fueron: ");
    for(j=0;j<n;j++)
    {
        if(facturado[j]==min)
            printf("\n%d",prod[j]);
    }
    printf("\nQue facturo/raron un total de:%0.2f",min);
}
