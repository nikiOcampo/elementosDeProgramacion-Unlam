/*La empresa TODOMODA desea controlar las ventas de sus productos.
 La empresa vende 200 productos diferentes. La información de los productos se ingresa por teclado. Cada producto contiene:
• Código de producto (int, 301 y 900).
• Unidades en stock. (int, mayor o igual a 0).
Luego ingresar la información de las ventas diarias, también por teclado.
 Los datos ingresados son (este lote de datos finaliza con un código de producto igual a 0):
• Código de producto (int, 301 y 900).
• Cantidad de unidades vendidas (int, 1 y 150).
Se piden procesar las ventas diarias y luego determinar:
a. Informar el stock de cada código de producto, indicando el código de producto y el stock del mismo.
b. Informar el código del producto que tiene el stock más alto.
c. Informar el código del producto de aquellos que hayan superado el stock promedio.
FUNCIONES:
I. Para controlar los datos ingresados por teclado (la función debe controlar un solo dato).
II. Para informar el punto a).*/

#include <stdio.h>
#include <stdlib.h>

int valida (int,int,int);
void mostrar_puntoA (int[],int[],int[],int);
void mostrar_puntoB (int[],int[],int);
void mostrar_puntoC (int[],int,int[],int);

int main()
{
    int cod_prod[5]={0},unid_stock[5]={0},cant_vend[5]={0};
    int cod,x=0,i;
    for(x=0;x<5;x++)
    {
        cod=valida(301,900,1);
        cod_prod[x]=cod;
        unid_stock[x]=valida(0,9999,2);
    }
    cod=valida(301,900,4);
    while(cod!=0)
    {
        for(i=0;i<5;i++)
        {
            if(cod_prod[i]==cod)
            {
                cant_vend[i]=valida(1,180,3);
            }
        }
        cod=valida(301,900,4);
    }
    mostrar_puntoA(cod_prod,unid_stock,cant_vend,5);
    /*//c. Informar el código del producto de aquellos que hayan superado el stock promedio.
    stock_promedio=(float)acumul_stock/5;*/
    return 0;
}

int valida(int i,int f,int t)
{
	int dato;
	if(t==1||t==2||t==3)
    {
        do
        {
           printf("\n Ingrese ");
          if(t==1)printf(" El codigo del producto: ");
          if(t==2)printf(" Las unidades de stock disponibles :");
          if(t==3)printf(" La cantidad de unidades vendidas:");
          scanf("%d",&dato);
        }while(dato<i||dato>f);
    }
    if(t==4)
    {
        do
        {
            printf(" Ingres El codigo del producto que se vendio: ");
            scanf("%d",&dato);
        }while((dato<i||dato>f)&&(dato!=0));
    }
 return dato;
}

void mostrar_puntoA(int cp[],int us[],int cv[], int n)
{
    int x,stock_nuevo[5]={0},j=0,acumul_stock=0;
    int stock_promedio;
    for(x=0;x<n;x++)
    {
        stock_nuevo[x]=us[x]-cv[x];
    }
    printf("\nLISTA DE STOCK ACTUALIZADO");
    printf("\nCODIGO:\t\tSTOCK:");
    for(j=0;j<5;j++)
    {
        printf("\n%d\t\t%d",cp[j],stock_nuevo[j]);
        acumul_stock+=stock_nuevo[j];
    }
    //b. Informar el código del producto que tiene el stock más alto.
    mostrar_puntoB(stock_nuevo,cp,n);
    //c. Informar el código del producto de aquellos que hayan superado el stock promedio.
    stock_promedio=acumul_stock/5;
    mostrar_puntoC(stock_nuevo,stock_promedio,cp,n);
}

void mostrar_puntoB(int st[],int cp[],int n)
{
    int max,i,j;
    max=st[0];
    for (i=1;i<n;i++)
    {
        if (st[i]>max)
            max=st[i];
    }
    printf("\nEl stock mas alto es de %d, y lo tienen el/los producto/s de codigo:",max);
    for(j=0;j<n;j++)
    {
        if(st[j]==max)
            printf("\n%d",cp[j]);
    }
}

void mostrar_puntoC(int st[], int sp, int cp[],int n)
{
    int x;
    printf("\nEl stock promedio es de %d, y lo superan los productos: ",sp);
    for(x=0;x<n;x++)
    {
       if(st[x]>sp)
        printf("\n%d",cp[x]);
    }
}
