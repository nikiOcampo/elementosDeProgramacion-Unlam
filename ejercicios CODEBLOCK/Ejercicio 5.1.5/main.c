//Confeccionar un programa para calcular
//la suma de los primeros N números naturales. El valor de N lo solicita por teclado el programa.//

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,i,suma=0;
    printf("Ingrese la cantidad de numeros a cargar: ");
    scanf("%d",&N);
    for(i=1;i<=N;i++)
    {
        suma+=i;
    }
    printf("La suma de los primeros %d numeros naturales es de %d",N,suma);
    return 0;
}
