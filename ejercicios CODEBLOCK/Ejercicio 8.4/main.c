//8.4. Se ingresan código y precio unitario de los productos que vende un negocio.
//     No se sabe la cantidad exacta de productos, pero sí se sabe que son menos de 50.
//     El código es alfanumérico de 3 caracteres y la carga de los datos de productos
//     termina con un código igual al “FIN”.
//
//     Luego se registran las ventas del día y por cada venta se ingresa el código de producto
//     y cantidad de unidades vendidas terminando con una cantidad igual a 0.
//     Se solicita:
//       a. Calcular la recaudación total del día y el producto del cual se vendió menor cantidad de unidades.
//       b. Mostrar el listado de productos con su precio ordenado en forma alfabética por código de producto.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Carga_productos(char [][10],float [],int);
int buscar_Producto(char [][10],char [10],int);
void ordenar(char [][10],float [], int);

int main()
{
     int Cant,CVent,pos;
     float Recauda=0;
     char Codi[10];
     char Codigo [50][10];
     float Precio[50];
     Cant = Carga_productos(Codigo,Precio,50);
     printf("\n Ingrese Cantidad Vendida :");
     scanf("%d",&CVent);
     while(CVent!=0)
     {
       printf("\n Ingrese Codigo Producto:");
       fflush(stdin);
       scanf("%s",Codi);
       pos=buscar_Producto(Codigo,Codi,Cant);
       if(pos!=-1)
           Recauda+=Precio[pos]*CVent;
       else
           printf("\n\t Producto No existe %d, %s",pos,Codigo[pos]);
       printf("\n Ingrese Cantidad Vendida :");
       scanf("%d",&CVent);
     }
     printf("\n\n\n Total Recaudado es %6.2f",Recauda);
     ordenar(Codigo,Precio,Cant);

    return 0;
}
int Carga_productos(char c[][10],float p[],int n)
{
    int x=0;
    printf("\n Ingrese Codigo: ");
    fflush(stdin);
    scanf("%s",c[x]);
    while((strcmpi(c[x],"FIN")!=0))
      {
       printf("\n Ingrese Precio Unitario: ");
       scanf("%f",&p[x]);
       x++;
       printf("\n Ingrese Codigo: ");
       fflush(stdin);
       scanf("%s",c[x]);
      }

   return x;
}
int buscar_Producto(char c[][10],char p[4],int n)
{
    int po=-1,x=0;
    while(po==-1&&x<n)
    {
        if(strcmpi(c[x],p)==0)
            po=x;
        else x++;
    }
  return po;
}
void ordenar(char c[][10],float p [], int n)
{
  int sen=0, x=0;
  char Aux[10];
  float aux;
  while(sen==0)
  {//Parte 01/04
     sen=1;
     for(x=0;x<n-1;x++)
     {
         if(strcmpi(c[x],c[x+1])>0)
         {   strcpy(Aux,c[x]);
             strcpy(c[x],c[x+1]);
             strcpy(c[x+1],Aux);
             aux=p[x];
             p[x]=p[x+1];
             p[x+1]=aux;
         }
     }
  }
  printf("\nPRODUCTO:\tPRECIO:");
  for(x=0;x<n;x++)
  {
      printf("\n%s\t\t%f",c[x],p[x]);
  }
}
