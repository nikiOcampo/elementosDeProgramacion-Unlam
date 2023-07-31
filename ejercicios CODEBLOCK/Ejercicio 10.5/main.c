/*Se dispone de un archivo llamado Stock.dat que contiene la información de los 10 productos que vende una fábrica.
En el archivo se guarda:
• Código de artículo (entero)
• Descripción (50 caracteres máximo)
• Stock (entero)
Luego se ingresan por teclado las ventas a realizar indicando:
• Código de artículo
• Cantidad
La carga por teclado de las ventas finaliza con un código de artículo igual a 0.
Por cada venta se debe controlar si hay stock suficiente y si lo hay, restar el stock de dicho producto,
 sino hay stock se debe vender lo que quede disponible y grabar un registro en un archivo Faltantes.dat con la
 cantidad que no pudo venderse, dicho registro debe contener:
• Código de artículo
• Cantidad
Se genera un registro por cada venta que no pudo concretarse, pudiendo quedar en el archivo varios registros
faltantes del mismo producto.
Al finalizar actualizar el archivo Stock.dat con el stock actualizado luego de procesar las ventas.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct
{
    int cod;
    char descripcion[51];
    int stock;
}producto;

typedef struct
{
    int cod;
    int cant;
}faltantes;

void cargaproductos(producto[],int);
int buscar(producto[],int ,int);
int ventas(producto[],faltantes[],int);
void mostrar(producto[],faltantes[],int);

int main()
{
    producto prod[10];
    faltantes falt[10];
    int cant;
    cargaproductos(prod,10);
    system("cls");
    cant=ventas(prod,falt,10);
    system("cls");
    mostrar(prod,falt,cant);
}

void cargaproductos(producto prod[],int n)
{
    FILE*fp;
    int x;
    fp=fopen("stock.dat", "wb");
    if(fp==NULL)
    {
        printf("\nEl archivo tiene algun error");
        exit(1);
    }
    for(x=0;x<n;x++)
    {
        printf("\nIngrese el codigo del producto nro %d: ",x+1);
        scanf("%d", &prod[x].cod);
        do
        {
            printf("\nIngrese la descripcion del producto:");
            getchar();
            gets(prod[x].descripcion);
        }while(strlen(prod[x].descripcion)<1||strlen(prod[x].descripcion)>50);
        do
        {
            printf("\nIngrese el stock del producto: ");
            scanf("%d", &prod[x].stock);
        }while(prod[x].stock<0);
        fwrite(&prod[x], sizeof(producto), 1, fp);
    }
    fclose(fp);
}

int ventas(producto prod[],faltantes falt[],int n)
{
    FILE*fp;
    FILE*fp2;
    int codigo,pos,cant_vendida,x=0,cont=0;
    fp=fopen("stock.dat", "ab");
    if(fp==NULL)
    {
        printf("\n Hay un error con el archivo 1");
        exit(1);
    }
    fp2=fopen("faltantes.dat", "wb");
    if(fp2==NULL)
    {
        printf("\n Hay un error con el archivo 2");
        exit(1);
    }
    printf("CARGA DE LAS VENTAS:");
    do
    {
        printf("\nIngrese el codigo del producto[Salida=0]: ");
        scanf("%d",&codigo);
        pos=buscar(prod,codigo,n);
    }while(pos==-1&&codigo!=0);
    while(codigo!=0)
    {
        do
        {
            printf("\nIngrese la cantidad vendida: ");
            scanf("%d",&cant_vendida);
        }while(cant_vendida<0);
        if(cant_vendida<=prod[pos].stock)
        {
            prod[pos].stock-=cant_vendida;
            fwrite(&prod[pos],sizeof(producto),1,fp);
        }
        else
        {
            falt[x].cod=prod[pos].cod;
            falt[x].cant=cant_vendida-prod[pos].stock;
            prod[pos].stock=0;
            fwrite(&falt[x],sizeof(faltantes),1,fp2);
            fwrite(&prod[pos],sizeof(producto),1,fp);
            x++;
            cont++;
        }
         do
        {
            printf("\nIngrese el codigo del producto[Salida=0]: ");
            scanf("%d",&codigo);
            pos=buscar(prod,codigo,n);
        }while(pos==-1&&codigo!=0);
    }
    fclose(fp);
    fclose(fp2);
    return cont;
}


int buscar(producto pr[],int cod,int n)
{
  int p=-1,i=0;
  while(p==-1&&i<n)
  {
      if(pr[i].cod==cod)
           p=i;
      else
          i++;
  }
  return p;
}

void mostrar(producto prod[],faltantes falt[], int n)
{
    FILE*fp;
    FILE*fp2;
    int x;
    fp=fopen("stock.dat", "rb");
    if(fp==NULL)
    {
        printf("\n Hay un error con el archivo 1");
        exit(1);
    }
    fp2=fopen("faltantes.dat", "rb");
    if(fp2==NULL)
    {
        printf("\n Hay un error con el archivo 2");
        exit(1);
    }
    printf("\nLISTA DE PRODUCTOS CON SUS STOCKS:\n");
    for(x=0;x<10;x++)
    {
        printf("\nCODIGO:       %d",prod[x].cod);
        printf("\nDESCRIPCION:  %s",prod[x].descripcion);
        if(prod[x].stock==0)
            printf("\nSTOCK:        %s\n\n","FALTANTE");
        else
            printf("\nSTOCK:    %d\n\n",prod[x].stock);
    }
    system("pause");
    printf("\nLISTA DE PRODUCTOS FALTANTES CON SUS CANTIDADES:\n");
    for(x=0;x<n;x++)
    {
        printf("\nCODIGO:       %d",falt[x].cod);
        printf("\nSTOCK:        %d\n\n",falt[x].cant);
    }
    fclose(fp);
    fclose(fp2);
}
