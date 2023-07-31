/*Ingresar un n�mero entero mayor a 0.
Debe dibujar un tri�ngulo rect�ngulo con * con tantas filas como el n�mero indicado.
En cada fila se va incrementando la cantidad de asteriscos. Por ejemplo, si se ingresa el n�mero 6 debe mostrar en pantalla:
*
**
***
****
*****
*******/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num,i,j;
    do{printf("Ingresa un numero entero mayor a cero: ");
    scanf("%d",&num);
    if(num<=0)
        printf("NUMERO INVALIDO\n");
    }while(num<=0);
    for(i=1;i<=num;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("*");
        }
    printf("\n");
    }

    return 0;
}
