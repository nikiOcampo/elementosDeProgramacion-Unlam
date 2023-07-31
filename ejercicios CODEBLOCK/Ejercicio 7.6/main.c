/*Ídem ejercicio anterior, pero con código de productos no correlativos de 4 dígitos.
Los códigos deben solicitarse al iniciar el programa mediante la función IngresaCodigos. Luego de la carga determinar:
a. El / los productos del cual se solicitaron mayor cantidad de unidades.
b. El / los productos del cual se solicitaron menos cantidad de unidades.

#include <stdio.h>
#include <stdlib.h>

int ingresaCodigos (int, int);
void mostrarLista(int[],int);

int main()
{
    int codigo,cant;
    int cantidad[];
    codigo= ingresaCodigos(1000,9999);
    while(codigo!=0)
    {
        printf("Ingrese la cantidad de unidades que desea de ese producto: ");
        scanf("%d",&cant);
        codigo= ingresaCodigos(1000,9999);
    }
    return 0;
}

int ingresaCodigos(int li ,int ls )
{
    int cod,sen=0;
    do
    {
        printf("Ingresa el codigo del producto: ");
        scanf("%d",&cod);
        if ((cod<li||cod>ls)&& cod!=0)
            printf("Codigo fuera de rango");
        if(sen==cod+1)
            printf("Los codigos no pueden ser correlativos");
    }while((sen==cod+1)||((cod<li||cod>ls)&& cod!=0));
    sen=cod;
    return cod ;
}

void mostrarLista(int cant[], int n)
{
    int x;
    printf("Codigos: \t Cantidad: ");
    for (x=0;x<n;x++)
    {
        printf("\n%d\t\t%d",x+1 ,cant[x]);
    }
}*/

#include <stdio.h>
#include <stdlib.h>

int busqueda_secuencial (int [], int , int );
void IngresaCodigo(int [],int );
void blanco(int [],int);

int main()
{
	int Cant,Cantidad[10],x,Codigo[10],pos,Cod;
    int MayPro,MenPro,CodMay,CodMen;
	blanco(Cantidad,10);
    blanco(Codigo,10);
	IngresaCodigo(Codigo,10);

     do
     {
      system("cls");
      printf("\n Ingrese Producto Nro:");
	  scanf("%d",&Cod);
	  pos= busqueda_secuencial(Codigo,10,Cod);

	 }while(pos==-1&&Cod!=0);


	while(Cod!=0)
	{
      printf("\n Cantidad Solicitada?:");
	  scanf("%d",&Cant);
	  Cantidad[pos]+=Cant;
	do
    {
	  system("cls");
      printf("\n Ingrese Producto Nro:");
	  scanf("%d",&Cod);
	  pos= busqueda_secuencial(Codigo,10,Cod);
	}while(pos==-1&&Cod!=0);
   }
   MayPro=Cantidad[0];
   MenPro=Cantidad[0];
   CodMay=Codigo[0];
   CodMen=Codigo[0];
   for(x=0;x<10;x++)
     {
      if(MayPro<Cantidad[x])
        {
         MayPro=Cantidad[x];
         CodMay=Codigo[x];
        }
	  if(MenPro>Cantidad[x])
        {
         MenPro=Cantidad[x];
         CodMen=Codigo[x];
        }
	 }
  system("cls");
  printf("\n Producto Mas   Pedido es %d , con %d",CodMay,MayPro);
  printf("\n Producto Menos Pedido es %d , con %d",CodMen,MenPro);
 return 0;
}

void blanco(int a[],int n)
{
 int x;
 for(x=0;x<n;x++)
 {
  a[x]=0;
 }
};

void IngresaCodigo(int c[], int n)
{
  int x,pos;
  for(x=0;x<n;x++)
  {
	system("cls");
	printf("\n \t\t Carga de Codigo nro %d", x+1);
	do
	 {
	  do
	   {
         printf("\n Ingrese Producto Nro:");
         scanf("%d",&c[x]);
       }while(c[x]<1000||c[x]>9999);
      pos= busqueda_secuencial(c,x,c[x]);
     }while(pos!=-1);
  }
}

int busqueda_secuencial (int v[], int cant, int elem)
 {
   int i, pos;
   i = 0;
   pos = -1;
   while(i < cant && pos == -1)
     {
      if(v[i] == elem) pos = i;
      else i++;
     }
   return pos;
}



