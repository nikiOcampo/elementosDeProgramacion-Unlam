#include <stdio.h>
#include <stdlib.h>

int main()
{
    float n1,n2,n3;
    printf("Ingrese el primer valor: ");
    scanf("%f",&n1);
    printf("\nIngrese el segundo valor: ");
    scanf("%f",&n2);
    printf("\nIngrese el tercer valor: ");
    scanf("%f",&n3);
    if (n1+n2>n3&&n2+n3>n1&&n1+n3>n2)
        printf("Se forma un triangulo");
    else
        printf("No se forma un triangulo");
    return 0;
}
