/*La empresa TODOLIMPIO que comercializa un máximo de 25 productos, dispone del archivo “LIMPIEZA.dat”,
 donde cada registro contiene:
• Número de Artículo (entero, 5 cifras)
• Unidades en stock (entero)
• Precio unitario (real)
Cada vez que se realiza una venta se ingresa por teclado, los siguientes datos:
• Número de Cliente (1 a 20) Función LEE_CONTROL
• Número de Artículo (entero, 5 cifras). Función LEE_CONTROL
• Cantidad de Unidades Vendidas. Función MAYORCERO.
Esta información termina con número de cliente igual a 0.
Si la cantidad de unidades vendidas es superior al stock existente de cada uno de los productos, NO realizar la venta y
 marcarla para un posterior reporte.
Se solicita confeccionar un programa que actualice el archivo “PRODUCTOS.dat” y e informar:
a. La facturación total por cliente.
b. La cantidad de veces que cada cliente realizó una compra.
c. Emitir un listado ordenado por monto de facturación de forma descendente de acuerdo con el siguiente diseño:
d. Emitir un listado con el número de artículos que no se pudo realizar las ventas por falta de stock.
e. Actualizar el archivo “LIMPIEZA.dat”, en UNIDADES en STOCK según las ventas ingresadas.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct
{
    int num_art;
    int stock;
    float precio;
}producto;

typedef struct
{
    int num_cliente;
    int num_art;
    int unidades_vendidas;
}ventas;

void cargaproductos(producto[],int);
int cargaventas(producto[],ventas[]);
void ListarCodigos (producto[], int ce);
int lee_control(int,int,int);
int mayor_cero(int);
int buscar(producto[],int,int);
void mostrar_puntoC(float[],int[],int);

int main()
{
    producto prod[/*25*/5];
    ventas vent[10000];
    FILE*fp2;
    int cant,x;
    fp2=fopen("limpieza.dat","wb");
    if(fp2==NULL)
    {
        printf("\n Hay un error con el archivo 1");
        exit(1);
    }
    cargaproductos(prod,5/*25*/);
    cant=cargaventas(prod,vent);
    //-----------------------
    printf("\nSE INGRESARON %d VENTAS",cant);
    //-----------------------
    printf("\nLISTADO DE ARTICULOS QUE NO ALCANZO EL STOCK: ");
    for(x=0;x<5/*25*/;x++)
    {
        if(prod[x].stock==-1)
            printf("\n%d",prod[x].num_art);
        fwrite(&prod[x].stock,sizeof(producto),1,fp2);
    }
    fclose(fp2);
    return 0;
}

void cargaproductos(producto prod[],int n)
{
    int x;
    FILE*fp;
    fp=fopen("productos.dat","wb");
    if(fp==NULL)
    {
        printf("\n Hay un error con el archivo 1");
        exit(1);
    }
    for(x=0;x<n;x++)
    {
       prod[x].num_art=lee_control(10000,99999,1);
       prod[x].stock=mayor_cero(1);
       do
       {
           printf("\nIngrese el precio unitario: ");
           scanf("%f",&prod[x].precio);
       }while(prod[x].precio<0);
       fwrite(&prod[x],sizeof(producto),1,fp);
    }
    fclose(fp);
}

int lee_control(int i,int s,int n)
{
    int dato;
    do
    {
        if(n==1)printf("\nIngrese el codigo del articulo[10000 a 99999]: ");
        if(n==2)printf("\nIngrese el numero de cliente[1 a 20/Salida=0]: ");
        scanf("%d",&dato);
    }while(dato<i||dato>s);
    return dato;
}

int mayor_cero(int n)
{
    int dato;
    do
    {
        if(n==1)printf("\nIngrese el stock: ");
        if(n==2)printf("\nIngrese la cantidad de unidades vendidas: ");
        scanf("%d",&dato);
    }while(dato<0);
    return dato;
}

int cargaventas(producto prod[],ventas vent[])
{
    int x=0,pos,i,cont[20]={0};
    float fact_x_cliente[20]={0};
    system("cls");
    printf("\nCARGA DE LAS VENTAS: ");
    vent[x].num_cliente=lee_control(0,20,2);
    while(vent[x].num_cliente!=0)
    {
        do
        {
            ListarCodigos(prod,/*25*/5);
            vent[x].num_art=lee_control(10000,99999,1);
            pos=buscar(prod,vent[x].num_art,/*25*/5);
        }while(pos==-1);
        vent[x].unidades_vendidas=mayor_cero(2);
        prod[pos].stock-=vent[x].unidades_vendidas;
        if(prod[pos].stock<0)
            prod[pos].stock=-1;
        if(prod[pos].stock==0)
            prod[pos].stock=-2;
        fact_x_cliente[vent[x].num_cliente-1]+=(float)vent[x].unidades_vendidas*prod[pos].precio;
        cont[vent[x].num_cliente-1]++;
        x++;
        system("cls");
        vent[x].num_cliente=lee_control(0,20,2);

    }
    printf("\nLISTA DE FACTURADO POR CLIENTE:");
    for(i=0;i<20;i++)
    {
        printf("\nCLIENTE:%d     FACTURO:%0.2f",i+1,fact_x_cliente[i]);
    }

    printf("\n\nCANTIDAD DE COMPRAS POR CLIENTE:");
    printf("\nCLIENTE:   CANTIDAD:");
    for(i=0;i<20;i++)
    {
        printf("\n%d             %d",i+1,cont[i]);
    }
    mostrar_puntoC(fact_x_cliente,cont,20);
    return x;
}

void mostrar_puntoC(float monto[],int cant[],int n)
{
    int x,j,aux,clientes[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    float auxf;
    for(x=0;x<n-1;x++)
    {
        for(j=0;j<n-1-x;j++)
        {
            if(monto[j]<monto[j+1])
            {
                auxf=monto[j];
                monto[j]=monto[j+1];
                monto[j+1]=auxf;

                aux=cant[j];
                cant[j]=cant[j+1];
                cant[j+1]=aux;

                aux=clientes[j];
                clientes[j]=clientes[j+1];
                clientes[j+1]=aux;
            }
        }
    }
    //system("cls");
    printf("\nCLIENTE:  MONTO:  CANT DE COMPRAS: ");
    for(x=0;x<n;x++)
    {
        printf("\n%d\t%0.2f\t\t%d ",clientes[x],monto[x],cant[x]);
    }
}

int buscar(producto pr[],int cod,int n)
{
  int p=-1,i=0;
  while(p==-1&&i<n)
  {
      if(pr[i].num_art==cod)
           p=i;
      else
          i++;
  }
  return p;
}

void ListarCodigos (producto vc[], int ce)
{
    int i;
    system("cls");
    printf("LISTADO DE CODIGOS DE ARTICULOS\n");
    printf("--------------------\n\n");
    printf("CODIGO  PRECIO.UNIDAD  STOCK\n");

    for (i=0;i<5/*ce*/;i++)
    {
        if(vc[i].stock!=-1&&vc[i].stock!=-2)
            printf("%d     %0.2f        %d\n", vc[i].num_art, vc[i].precio,vc[i].stock);
        else
            printf("%d     %0.2f        %s\n", vc[i].num_art, vc[i].precio,"SIN STOCK");
    }
    printf("\n");
}
