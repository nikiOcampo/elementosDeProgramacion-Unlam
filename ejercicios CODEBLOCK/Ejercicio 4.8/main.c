#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1,n2,resto;
    printf("Ingrese el primer numero: ");
    scanf("%d",&n1);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &n2);
    resto= n1%n2;
    if (resto==0)
    printf("El primer numero es divisible por el segundo");
    else
        printf("El primer numero NO es divisible por el segundo");
    return 0;
}
