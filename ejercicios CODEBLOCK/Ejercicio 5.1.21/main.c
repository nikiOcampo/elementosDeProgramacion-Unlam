/*Tomando como base el ejercicio anterior ingresar un número entero mayor a 0
 y dibujar un rombo con *. Por ejemplo, si se ingresa el número 5 dibuja la
pirámide de 5 filas y luego completa el rombo al ir decrementando la cantidad de asteriscos.
*
***
*****
*******
*********
*******
*****
***
*

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,k,num,cont=1,sen=1;
    do{printf("Ingrese un numero entero mayor a 0(cero): ");
    scanf("%d",&num);
    if(num<=0)
        printf("NUMERO INVALIDO\n");
    }while(num<=0);
    for(i=1;i<=num;i++)
    {
        for(k=1;k<=cont;k++)
        {
            printf("*");
        }
    printf("\n");
    cont+=2;
    }
    for(;i>=sen;i--)
    {
        for(k=1;k<=cont;k++)
        {
            printf("*");
        }
    printf("\n");
    cont-=2;
    }
    return 0;
}
