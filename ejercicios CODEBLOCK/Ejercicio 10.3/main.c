/*10.3. Se desea realizar un programa que permita actualizar la lista de precios de una empresa en
forma individual a cada uno de sus productos.
La empresa trabaja con a lo sumo 100 productos que están guardados en el archivo productos.dat con la siguiente estructura:
• Código (entero)
• Precio (float)
• Descripción (de hasta 50 caracteres)
Para modificar un precio se ingresa por teclado el código del producto y el nuevo precio. La modificación
de precios finaliza con un código de producto igual a 0.
Al finalizar:
a. Actualizar el archivo de productos con los nuevos precios
b. Exportar a un archivo con formato de texto (.csv) para que la lista de precios pueda ser visualizada
directamente utilizando un programa de planillas de cálculo como por ejemplo el Excel.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
     int codigo;
     float precio;
     char descri[51];
}producto;

int carga_producto(producto [],int);
int buscar(producto [],int,int);
void actualiza(producto [],int);

int main()
{
    producto pro[100];
    int cant=0,i;
    cant=carga_producto(pro,100);
    printf("Cantidad de productos cargados: %d",cant);
    actualiza(pro,cant);
    FILE*fp;
    fp=fopen("productos.csv","wt");
    if (fp==NULL)
    {
        printf("Error al abrir el archivo.");
        exit(1);
    }
    fprintf(fp, "Codigo;Precio;Descripcion\n");
    for(i=0;i<cant;i++)
    {
      fprintf(fp, "%d;%.2f;%s\n", pro[i].codigo,pro[i].precio, pro[i].descri);
    }
    fclose(fp);
    return 0;
}
int carga_producto(producto p[],int n)
{
    int i=0;
    FILE * fp;
    fp=fopen ("productos.dat", "wb");
    if (fp==NULL)
    {
        printf("Error al abrir el archivo.");
        exit(1);
    }
    printf ("\n Ingrese Codigo Producto[Salida=0]:");
    scanf("%d", &p[i].codigo);
    while (p[i].codigo!=0)
    {
        printf ("\n Ingrese el precio:");
        scanf("%f", &p[i].precio);
        printf ("\n Ingrese el Descripcion:");
        fflush(stdin);
        gets(p[i].descri);
        fwrite(&p[i],sizeof(producto),1,fp);
        i++;
        printf ("\n Ingrese Codigo Producto[Salida=0]:");
        scanf("%d", &p[i].codigo);
    }
    fclose(fp);
    return i;
}
int buscar(producto pr[],int cod,int n)
{
  int p=-1,i=0;
  while(p==-1&&i<n)
  {
      if(pr[i].codigo==cod)
           p=i;
      else
          i++;
  }
  return p;
}
void actualiza(producto p[],int c)
{
     int cod,pos;
     printf("\n Codigo que actualiza[Salida=0] :");
     scanf("%d",&cod);
     while(cod!=0)
     {
        pos=buscar(p,cod,c);
        //printf("\t\t%d",pos);
        if(pos!=-1)
        {
            printf("\n Precio nuevo de %d :",p[pos].codigo);
            scanf("%f",&p[pos].precio);
        }
        else printf(" Codigo Inexistente");
        printf("\n Codigo que actualiza[Salida=0] :");
        scanf("%d",&cod);
     }
}
