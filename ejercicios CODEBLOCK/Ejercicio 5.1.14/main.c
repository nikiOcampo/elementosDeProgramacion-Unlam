/*Confeccionar un programa que determine e informe los números perfectos
 comprendidos entre 1 y 9000. Un número es
 perfecto cuando es igual a la suma de sus divisores positivos menores que él.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,z,divisores=0;
    printf("Los numeros primos son:");
    for(i=1;i<=9000;i++)
    {
        for(z=1;z<=i;z++)
        {
            if(i%z==0)
                divisores+=z;
        }
        if(divisores==i)
            printf("\n%d",i);
        divisores=0;
    }
    return 0;
}
