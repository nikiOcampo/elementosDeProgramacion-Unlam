/*Se dispone de un archivo con las ventas del mes de cada una de las sucursales de una empresa.
El archivo se encuentra ordenado por sucursal y contiene la siguiente estructura:
• Sucursal (15 caracteres máximo)
• Código de producto (entero)
• Cantidad (entero)
Por otro lado, se dispone de un archivo de los productos que vende la empresa y el estado del stock al mes pasado
 con la siguiente estructura:
• Código de producto (entero)
• Descripción (20 caracteres máximo)
• Precio (float)
• Stock (entero)
• Punto de pedido (entero)
• Cantidad para pedido (entero)
No se sabe la cantidad exacta de productos, pero sí se sabe que no hay más de 200. Se desea:
a. Mostrar el importe total vendido en cada sucursal.
b. Mostrar la recaudación total de la empresa en el mes.
c. Determinar la sucursal que vendió mayor cantidad de productos.
d. Actualizar el archivo de productos con el nuevo stock.
e. Realizar un archivo llamado pedidos.dat que incluya aquellos productos que deben solicitarse (código y cantidad)
 de aquellos productos que al finalizar de procesar las ventas del mesa queden con stock menor al punto de pedido.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int cod_prod;
    char descripcion[20];
    float precio;
    int stock;
    int punto_pedido;
    int cant_pedido;
}productos;

typedef struct
{
    char nomb_sucursal[15];
    int cod_prod;
    int cant;
}sucursal;

int cargaProductos(productos[],int);
void ListarProductos (productos[], int);
float validarfloat();
int mayor_cero(int);
int cargaVentas(sucursal[],productos[],int);
int buscar(productos[],int,int);
void importes(int,sucursal[],productos[],int);
void puntoE(productos[],int);

int main()
{
    productos prod[200];
    sucursal sucu[1000];
    int cant_prod,cant_ventas;
    cant_prod=cargaProductos(prod,200);
    cant_ventas=cargaVentas(sucu,prod,cant_prod);
    importes(cant_ventas,sucu,prod,cant_prod);
    puntoE(prod,cant_prod);
    return 0;
}

int cargaProductos(productos prod[], int n)
{
    int x=0,pos,cod;
    FILE*fp;
    fp=fopen("productos.dat","wb");
    if(fp==NULL)
    {
        printf("\n Hay un error con el archivo");
        exit(1);
    }
    printf("\nIngrese el codigo del producto[SALIDA=0]: ");
    scanf("%d",&cod);
    while(cod!=0)
    {
        prod[x].cod_prod=cod;
        do
        {
            printf("\nIngrese la descripcion del producto %d:",prod[x].cod_prod);
            fflush(stdin);
            gets(prod[x].descripcion);
        }while(strlen(prod[x].descripcion)<1||strlen(prod[x].descripcion)>20);
        prod[x].precio=validarfloat();
        prod[x].stock=mayor_cero(1);
        prod[x].punto_pedido=mayor_cero(2);
        prod[x].cant_pedido=mayor_cero(3);
        fwrite(&prod[x],sizeof(productos),1,fp);
        x++;
        do
        {
            printf("\nIngrese el codigo del producto[SALIDA=0]: ");
            scanf("%d",&cod);
            pos=buscar(prod,cod,x);
        }while(pos!=-1);
    }
    fclose(fp);
    return x;
}

int cargaVentas(sucursal sucu[],productos prod[],int n)
{
    int x=0,cod,pos,j,i,sen=0;
    sucursal aux;
    FILE*fp2;
    FILE*fp3;
    fp2=fopen("ventas.dat","wb");
    if(fp2==NULL)
    {
        printf("\n Hay un error con el archivo");
        exit(1);
    }
    fp3=fopen("productos.dat","ab");
    if(fp2==NULL)
    {
        printf("\n Hay un error con el archivo");
        exit(1);
    }
    do
    {
        ListarProductos(prod,n);
        printf("\nIngrese el nombre de sucursal[SALIDA='TERMINO']: ");
        fflush(stdin);
        gets(sucu[x].nomb_sucursal);
    }while(strlen(sucu[x].nomb_sucursal)<1||strlen(sucu[x].nomb_sucursal)>15);
    while(strcmpi(sucu[x].nomb_sucursal,"TERMINO")!=0)
    {
        do
        {
            printf("\nIngrese el codigo de producto que se vendio: ");
            scanf("%d",&cod);
            pos=buscar(prod,cod,n);
            if(pos==-1)
                printf("\nEL CODIGO INGRESADO NO EXISTE");
        }while(pos==-1);
        sucu[x].cod_prod=cod;
        sucu[x].cant=mayor_cero(4);
        prod[pos].stock-=sucu[x].cant;
        fwrite(&prod[pos].stock,sizeof(productos),1,fp3);
        x++;
        do
        {
            ListarProductos(prod,n);
            printf("\nIngrese el nombre de sucursal[SALIDA='TERMINO']: ");
            fflush(stdin);
            gets(sucu[x].nomb_sucursal);
        }while(strlen(sucu[x].nomb_sucursal)<1||strlen(sucu[x].nomb_sucursal)>15);
    }
    printf("\nSE CARGARON %d VENTAS\n",x);
    //------------
    for(i=0;i<x;i++)
    {
        printf("\n%s  %d    %d    ",sucu[i].nomb_sucursal,sucu[i].cod_prod,sucu[i].cant);
    }
    //---------------------
    while(sen==0)
    {
        sen=1;
        for(j=0;j<x-1;j++)
        {
            if(strcmpi(sucu[j].nomb_sucursal,sucu[j+1].nomb_sucursal)>0)
            {
                aux=sucu[j];
                sucu[j]=sucu[j+1];
                sucu[j+1]=aux;
                sen=0;
                fwrite(&sucu[j],sizeof(sucursal),1,fp2);
            }
         }
    }
    //------------
    for(i=0;i<x;i++)
    {
        printf("\n%s  %d    %d    ",sucu[i].nomb_sucursal,sucu[i].cod_prod,sucu[i].cant);
    }
    //---------------------
    fclose(fp2);
    return x;
}

void importes(int nventas,sucursal sucu[],productos prod[],int nprod)
{
    int x=0,pos,cod,cant_x_sucursal=0,i=0,cantidades[100],mayor,j,posmayor;
    float acuml_x_sucursal=0,total=0;
    char anterior[15];
    FILE*fp2;
    fp2=fopen("ventas.dat","rb");
    if(fp2==NULL)
    {
        printf("\n Hay un error con el archivo 1");
        exit(1);
    }
    fread(&sucu[x],sizeof(sucursal),1,fp2);
    while(!feof(fp2))
    {
        acuml_x_sucursal=0;
        strcpy(anterior,sucu[x].nomb_sucursal);
        while(strcmpi(sucu[x].nomb_sucursal,anterior)==0&&!feof(fp2))
        {
            cod=sucu[x].cod_prod;
            pos=buscar(prod,cod,nprod);
            acuml_x_sucursal+=sucu[x].cant*prod[pos].precio;
            cant_x_sucursal+=sucu[x].cant;
            x++;
            fread(&sucu[x],sizeof(sucursal),1,fp2);
        }
        total+=acuml_x_sucursal;
        printf("\nEl importe total de la sucursal %s es de %0.2f",sucu[x].nomb_sucursal,acuml_x_sucursal);
        cantidades[i]=cant_x_sucursal;
        i++;
    }
    printf("\nLa recaudacion total es de: %0.2f ",total);
    mayor=cantidades[0];
    for(j=1;j<i;j++)
    {
        if(mayor<cantidades[i])
        {
            mayor=cantidades[i];
            posmayor=i;
        }
    }
    printf("\nLa sucursal que mas vendio fue %s, con un total de %d cantidades vendidas",sucu[posmayor].nomb_sucursal,mayor);
    fclose(fp2);
}

void puntoE(productos prod[],int cant_prod)
{
    int x;
    FILE*fp6;
    fp6=fopen("pedidos.dat","wb");
    if(fp6==NULL)
    {
        printf("\n Hay un error con el archivo 1");
        exit(1);
    }
    for(x=0;x<cant_prod;x++)
    {
        if(prod[x].stock<prod[x].punto_pedido)
        {
            fwrite(&prod[x].cod_prod,sizeof(productos),1,fp6);
            fwrite(&prod[x].cant_pedido,sizeof(productos),1,fp6);
        }
    }
    fclose(fp6);
}

int mayor_cero(int n)
{
    int dato;
    do
    {
        if(n==1)printf("\nIngrese el stock: ");
        if(n==2)printf("\nIngrese el punto de pedido: ");
        if(n==3)printf("\nIngrese la cantidad para el pedido: ");
        if(n==4)printf("\nIngrese la cantidad que se vendio de ese producto: ");
        scanf("%d",&dato);
    }while(dato<0);
    return dato;
}

float validarfloat()
{
    float dato;
    do
    {
        printf("\nIngrese el precio: ");
        scanf("%f",&dato);
    }while(dato<0);
    return dato;
}

void ListarProductos (productos vc[], int ce)
{
    int i;
    system("cls");
    printf("\n\nLISTADO DE PRODUCTOS\n");
    printf("--------------------\n\n");
    printf("\nCODIGO  DESCRIPCION  PRECIO   STOCK");
    printf("\n-----------------------------------");
    for (i=0;i<ce;i++)
    {
        printf("\n%d     %s        %0.2f   %d", vc[i].cod_prod, vc[i].descripcion,vc[i].precio,vc[i].stock);
    }
    printf("\n");
    system("Pause");
}

int buscar(productos pr[],int cod,int n)
{
  int p=-1,i=0;
  while(p==-1&&i<n)
  {
      if(pr[i].cod_prod==cod)
           p=i;
      else
          i++;
  }
  return p;
}



