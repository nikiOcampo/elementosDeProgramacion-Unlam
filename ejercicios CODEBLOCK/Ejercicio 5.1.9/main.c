/*Confeccionar un programa que exhiba por pantalla una lista, a dos columnas,
 con los primeros 15 números impares en la primera y los 15 primeros pares en la segunda, incluyendo los títulos.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    printf("numeros pares\t");
    printf("numeros impares\n");
    for(i=1;i<=30;i++)
    {
    if(i%2==0)
        printf("%d\n",i);
    else
    {
       if(i!=1)
        printf("%d\t\t\t",i);
       else
        printf("%d\t\t\t",i);
    }
    }
    return 0;
}
