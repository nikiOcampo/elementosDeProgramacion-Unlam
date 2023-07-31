//Trabajo con Ejercicio 9.1
// solo modificar
// 1) En este Ejercicio solo debe cargarlo en CODE BLOCK y en pantalla siempre debe verse Alumno Nombre ________ Apellido_________
// 2) Cuando termine envie por Mensaje el .c para probar los cambios, Gracias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
  char  Codigo[5];
  float Precio;
  char  Descripcion [30];
  int   CantUniVend;
  float ImpTotal;
}articulos;

int carga_articulos(articulos []);
void carga_ventas(articulos [], int);
int Buscar(char [],articulos [], int);
void mostrar(articulos [],int );

int main()
{
   articulos art[50];
   int cant;
   cant=carga_articulos(art);
   carga_ventas(art,cant);
   mostrar(art,cant);

   return 0;
}
int carga_articulos(articulos a [])
{
  int i=0;
  system("cls");
  printf("                                                      OCAMPO NCIOLE");
  printf("\n Ingrese Descripcion Articulo :");
  fflush(stdin);
  gets(a[i].Descripcion);
while(strcmpi(a[i].Descripcion,"FIN")!=0)
  {
  do{
     printf("\n Ingrese Codigo Articulo :");
     fflush(stdin);
     gets(a[i].Codigo);
   }while(strlen(a[i].Codigo)<1||strlen(a[i].Codigo)>5);
  do{
     printf("\n Ingrese Precio Articulo :");
     scanf("%f",&a[i].Precio);
    }while(a[i].Precio<1);
  do{
     printf("\n Ingrese Cantidad Vendida:");
     scanf("%d",&a[i].CantUniVend);
    }while(a[i].CantUniVend<1);
  do{
     printf("\n Ingrese Importe Total  :");
     scanf("%f",&a[i].ImpTotal);
    }while(a[i].ImpTotal<1);
  system("cls");
  i++;
  printf("\n Ingrese Descripcion Articulo :");
  fflush(stdin);
  gets(a[i].Descripcion);
  }
  return i;
};
void carga_ventas(articulos a[], int n)
{
  char Cod[5];
  int cant,pos;
  system("cls");
  printf("                                                      OCAMPO NCIOLE");
  do{
     printf("\n Cantidad Vendida:");
     scanf("%d",&cant);
    }while(cant<0);
  while(cant!=0)
  {
   printf("\n Codigo Articulo  Vendido:");
   fflush(stdin);
   gets(Cod);
   pos=Buscar(Cod,a,n);
   if(pos!=-1)
     {
      a[pos].CantUniVend+=cant;
      a[pos].ImpTotal+=a[pos].Precio*cant;
     }
   else
      printf("\n Codigo Inexistente");
  system("cls");
  printf("                                                   OCAMPO NCIOLE");
  do{
     printf("\n Cantidad Vendida:");
     scanf("%d",&cant);
    }while(cant<0);

}
};
int Buscar(char b[],articulos donde[], int n)
{
  int p=-1,i=0;
  while(p==-1&&i<n)
  {
   if(strcmpi(b,donde[i].Codigo)==0)
        p=i;
   else i++;
  }
 return p;
};
void mostrar(articulos a[],int n)
{
    int x;
    system("cls");
    printf("                                                    OCAMPO NCIOLE");
    printf("\n DESCRIPCION  CANTIDAD UNIDADES VENDIDAS  IMPORTE TOTAL VENDIDO\n ");
    for(x=0; x<n; x++)
        printf("\n  %s           %d               %8.2f  ",a[x].Descripcion,a[x].CantUniVend,a[x].ImpTotal);
};
