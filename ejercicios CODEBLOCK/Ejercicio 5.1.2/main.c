//Confeccionar un programa para calcular el valor de la siguiente suma: 100 + 95 + 90 + ... + 50.//

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,suma=0;
    for(i=100;i>=50;i=i-5)
    {
     suma+=i;
    }
    printf("La suma es =%d",suma);
    return 0;
}
