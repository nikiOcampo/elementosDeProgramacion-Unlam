/*9.1. Una empresa que vende neumáticos desea realizar un programa para actualizar el total de ventas del mes de sus productos.
 Para ello primeramente se ingresan la información de los productos formados por:
• Código (5 caracteres).
• Precio (real).
• Descripción (30 caracteres).
• Cantidad de unidades vendidas (al mes anterior, entero).
• Importe Total Vendido (al mes anterior, real).
Se sabe que la empresa no vende más de 50 productos. El ingreso de la carga de productos finaliza con un producto
con descripción “FIN”.
Luego ingresan las ventas del mes:
• Código de Producto (5 caracteres).
• Cantidad pedida.
El ingreso de datos de las ventas finaliza con una cantidad igual a 0. Se solicita:
a. Actualizar la información de los productos con las ventas realizadas en el mes.
b. Al finalizar, mostrar el listado de productos actualizado, informando:
DESCRIPCION
CANTIDAD UNIDADES VENDIDAS
IMPORTE TOTAL VENDIDO
XXXXXXX
XXXX
$XXXXX,XX
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char codigo[6];
    float precio;
    char descripcion[31];
    int cant_vend;
    float import_vend;
}producto;

int buscar(producto[], char [], int);
void listar (producto[], int);

int main()
{
    producto prod[50];
    int i=0,pos,cantvendida;
    char cod[6];
    printf("                                                    OCAMPO NICOLE");
    do
    {
        printf("\nIngrese la descripcion del producto[Salida='FIN']:");
        fflush(stdin);
        gets(prod[i].descripcion);
    }while(strlen(prod[i].descripcion)<1||strlen(prod[i].descripcion)>30);
    while((strcmpi(prod[i].descripcion,"fin")!=0)&&i<50)
    {
        do
        {
            printf("\nIngrese el codigo de producto[no mas de 5 caracteres]: ");
            fflush(stdin);
            gets(cod);
            strcpy(prod[i].codigo,cod);
            pos=buscar(prod,cod,i);
            if(pos!=-1)
                printf("Ya se han registrado datos para dicho producto.\n");
        }while(pos!=-1);
        do
        {
            printf("\nIngrese el precio del prodcuto: ");
            scanf("%f",&prod[i].precio);
        }while(prod[i].precio<0);
        do
        {
            printf("\nIngrese la cantidad vendida al mes anterior: ");
            scanf("%d",&prod[i].cant_vend);
        }while(prod[i].cant_vend<0);
        prod[i].import_vend=(float)prod[i].precio*prod[i].cant_vend;
        i++;
        do
        {
            printf("\nIngrese la descripcion del producto[Salida='FIN']:");
            fflush(stdin);
            gets(prod[i].descripcion);
        }while(strlen(prod[i].descripcion)<1||strlen(prod[i].descripcion)>30);
    }
    system("cls");
    printf("                                                    OCAMPO NICOLE");
    do
    {
        printf("\nIngrese la cantidad pedida del producto a vender[Salida=0]: ");
        scanf("%d",&cantvendida);
    }while(cantvendida<0);
    while (cantvendida!=0)
    {
        do
        {
            printf("\nIngrese el codigo del producto del que se pidio esa cantidad: ");
            fflush(stdin);
            gets(cod);
            pos=buscar(prod,cod,i);
        }while(pos==-1);
        prod[pos].cant_vend+=cantvendida;
        prod[pos].import_vend+=(float)cantvendida*prod[pos].precio;
        do
        {
            printf("\nIngrese la cantidad pedida del producto a vender[Salida=0]: ");
            scanf("%d",&cantvendida);
        }while(cantvendida<0);
    }
    listar(prod,i);
    return 0;
}

int buscar( producto prod[], char cod[], int n)
{
    int pos=-1,x=0;
    while(pos==-1&&x<n)
    {
        if((strcmpi(prod[x].codigo,cod))==0)
            pos=x;
        else
            x++;
    }
    return pos;
}

void listar ( producto prod[], int n)
{
    int i;
    printf ("\nDESCRIPCION   UNIDADES VEND.   IMPORTE VEND.");
    for (i=0; i<n; i++)
        printf ("\n%s\t%d\t\t%0.2f", prod[i].descripcion, prod[i].cant_vend, prod[i].import_vend);
}
