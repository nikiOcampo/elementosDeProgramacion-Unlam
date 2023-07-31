/*5.1.13 Realizar un programa que:
a. Muestre todos los números primos entre 1 y 100. (Un nro. es primo cuando es divisible solamente por 1 y por sí mismo)
b. Contar y mostrar la cantidad de primos encontrados.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,contnump=0;
    printf("Numeros primos: \n");
    for(i=1;i<=100;i++)
    {
        if(i%2==0||i%3==0||i%5==0||i%7==0)
        {
            if(i==2||i==3||i==5||i==7)
            {
                printf("\n %d",i);
                contnump++;
            }
        }
        else
        {
            printf("\n %d",i);
            contnump++;
        }
    }
    printf("\nLa cantidad de numeros primos entre el 1 y el 100 es de: %d",contnump);
    return 0;
}
