/*Confeccionar un programa que calcule e informe los valores de
las potencias de 2 cuyo resultado sean menores que 600. (1 2 4 8 16 …)*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    printf("potencias de 2");
    for(i=1;i<=600;i=i*2)
    {
        printf("\n%d",i);
    }
    return 0;
}
