/*Una empresa de venta de productos Odontológicos, “La Muela”, desea analizar las ventas efectuadas por sus
 20 vendedores diariamente.
Desarrollar el Diagrama con su correspondiente codificación C para que permita:
a)	Confeccionar y utilizar una FUNCIÓN para ingresar desde teclado los datos de los vendedores. Por cada vendedor, se ingresa:
	Número de vendedor (int 4 cifras)
	Sector (char de 13 caracteres)
Posibles valores: “Mostrador -  Capital  -  Gran Bs.As.  -   Interior  -  Terceros”

El fin de la carga de datos es con la pregunta ¿Continua con la Carga? [“SI” o “NO”] usar
variable de dos caracteres NO SE PUEDE PONER  ‘S’ o ‘N’.

b)	Procesar luego los datos de  ventas del día, que se ingresan por teclado, con el siguiente detalle:
                   . Código de vendedor (Buscar la existencia en carga anterior)
                   . Cantidad vendida (int > 0)
                   . Precio unitario (flotante >0)
                                                                             Validar los datos ingresados por teclado.
 Estos datos no se ingresan ordenados y la lectura debe detenerse cuando se ingrese un número de vendedor igual a 9999.

Salidas solicitadas:
1)	Emitir un informe que muestre el importe que se abona por cada Sector ordenado de Mayor a menor. (Para mostrar el listado de este punto se deben hacer dos funciones, la
      primera llamada  ORDENAR( )  ordena de mayor a menor  y la segunda función MOSTRAR()
      para mostrar el listado).
                                    LISTADO DE SUELDOS ABONADOS ORDENADO


Nota: En el caso de No haber datos, NO SE DEBE MOSTRAR el Sector con importe  $ 0 (cero).

2)	De cada vendedor, acumular los importes vendidos. Informar Mayor importe, con la siguiente forma :   Cod: 9999  Sector: XXXXXXXX  importe : $99999 (hay uno solo)
3)	Cual Sector realizo menos registros en cantidad vendida. (hay uno solo).
4)	Cuantos Vendedores NO registraron ventas en el período. Informar sólo la cantidad. */

#include <stdio.h>
#include <stdlib.h>

void carga(int[],int);
int busqueda_secuencial (int[],int,int);

int main()
{
    int m[5][20],num_vend[20]={0};
    char sector[13];
    carga(num_vend,20);
    return 0;
}

void carga(int v1[],int n)
{
    int x=0,pos,vendedor;
    //system("cls");
    while(x<n)
    {
        do
        {
            printf("\n Ingrese valor %d:",x+1);
            scanf("%d",&vendedor);
            pos=busqueda_secuencial(v1,n,vendedor);
            v1[x]=vendedor;
        }while((v1[x]<1000||v1[x]>9999)&& pos!=-1);
        x++;
    }
}

int busqueda_secuencial (int v[], int cant, int elem)
{
    int i, pos;
    i = 0;
    pos = -1;
    while(i < cant && pos == -1)
    {
        if(v[i] == elem)
            pos = i;
        else
            i++;
    }
    return pos;
}

