/*Una empresa debe registrar los pedidos recibidos de cada uno de sus 10 productos a lo largo del día.
 Por cada pedido se recibe:
• Código de producto (de 1 a 10)
• Cantidad de unidades solicitadas
Se puede recibir más de un pedido por producto.
La carga finaliza cuando se ingresa un producto con código igual a cero.
Al finalizar se debe emitir un listado con código y cantidad de unidades solicitadas de cada producto.*/

#include <stdio.h>
#include <stdlib.h>

int validarCod (int, int);
void mostrarLista(int[],int);

int main()
{
    int cod, cant,cantidad[10]={0};
    cod=validarCod(1,10);
    while (cod!=0)
    {
        printf("Ingrese la cantidad de unidades que desea de ese producto: ");
        scanf("%d",&cant);
        cantidad[cod-1]+= cant;
        cod=validarCod(1,10);
    }
    mostrarLista(cantidad,10);
    return 0;
}

int validarCod(int li,int ls)
{
    int codigo;
    do
    {
        printf("Ingrese el codigo del producto que desea comprar: ");
        scanf("%d",&codigo);
        if( (codigo<li||codigo>ls) && codigo!=0)
            printf("El codigo ingresado no es valido");
    }while((codigo<li || codigo>ls) && codigo!=0);
    return codigo;
}

void mostrarLista(int cant[], int n)
{
    int x;
    printf("Codigos: \t Cantidad: ");
    for (x=0;x<n;x++)
    {
        printf("\n%d\t\t%d",x+1 ,cant[x]);
    }
}
