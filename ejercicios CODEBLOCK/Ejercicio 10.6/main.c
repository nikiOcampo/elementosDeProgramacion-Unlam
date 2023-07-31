/*Realizar un programa que tome el archivo Faltantes.dat del ejercicio anterior y
unifique las cantidades sumariándolas por artículo (la empresa trabaja con 10 artículos en total,
pero no todos pueden estar en falta). Generar una planilla Excel para enviar al proveedor con el pedido a realizar.
 Para ello se debe crear un nuevo archivo llamado pedido.csv que contenga los registros por artículo conteniendo:
• Código de artículo (entero)
• Cantidad (entero)*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct
{
    int cod;
    int cant;
}faltantes;

int Lee_datos(faltantes[],int);

int main()
{
    faltantes falt[10];
    int cant,i,total=0;
    cant=Lee_datos(falt,10);
    FILE*fp;
    fp=fopen("pedido.csv","wt");
    if (fp==NULL)
    {
        printf("Error al abrir el archivo.");
        exit(1);
    }
    fprintf(fp,"PEDIDO A PROVEEDORES\n");
    fprintf(fp,"Codigo de producto;Cantidad\n");
    for(i=0;i<cant;i++)
    {
        if(falt[i].cant!=0)
           {
               fprintf(fp, "%d;%d\n", falt[i].cod,falt[i].cant);
               total+=falt[i].cant;
           }
    }
    fprintf(fp,"CANTIDAD TOTAL DE ARTICULOS SOLICITADOS:;%d",total);
    fclose(fp);
    return 0;
}

int Lee_datos(faltantes a[],int n )
{
     int i=0;
     FILE * rr;
     rr=fopen("faltantes.dat","rb");
     if(rr==NULL) {puts("Error en generacion de Archivo");exit(1);}
     fread(&a[i],sizeof(faltantes),1,rr);
     while(!feof(rr)&&i<n)
     {
          i++;
          fread(&a[i],sizeof(faltantes),1,rr);
     }
     fclose(rr);
     return i;
}
