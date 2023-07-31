/*Ingresar un número entero mayor a 0. Debe dibujar una pirámide con * con tantas filas como el número indicado.
 En cada fila se va incrementando la cantidad de asteriscos de 2 en 2.
Por ejemplo, si se ingresa el número 5 debe mostrar en pantalla:
    *
   ***
  *****
 *******
*********

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,k,l,num,cont=1;
    do{printf("Ingrese un numero entero mayor a 0(cero): ");
    scanf("%d",&num);
    if(num<=0)
        printf("NUMERO INVALIDO");
    }while(num<=0);
    for(i=1;i<=num;i++)
    {
        for(j=1;j<=(num-i);j++)
        {
            printf(" ");
        }
        for(k=1;k<=cont;k++)
        {
            printf("*");
        }
        for(l=1;l<=(num-1);l++)
        {
        printf(" ");
        }
    printf("\n");
    cont+=2;
    }
    return 0;
}
