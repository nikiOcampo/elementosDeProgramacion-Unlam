#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Nota1, Nota2;
    float Promedio;
    printf("Ingrese la primer nota: ");
    scanf ("%d", &Nota1);
    printf("\nIngrese la segunda nota: ");
    scanf("%d", &Nota2);
    Promedio= (float)(Nota1+Nota2)/2 ;
    printf("\nEl promedio es: %f", Promedio);
    return 0;
}
