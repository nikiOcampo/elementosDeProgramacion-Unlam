#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Num_1,Num_2,Num_3;
    printf("Ingrese el primer numero: ");
    scanf("%d", &Num_1);
    printf("\nIngrese el segundo numero: ");
    scanf("%d", &Num_2);
    printf("\nIngrese el tercer numero: ");
    scanf("%d", &Num_3);
    if (Num_1<Num_2 && Num_1<Num_3)
        printf("El primer numero es el menor");
        else
        printf("El primer numero no es el menor");
    return 0;
}
