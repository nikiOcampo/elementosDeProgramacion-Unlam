#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Num_1, Num_2, Num_3;
    printf("Ingrese el primer numero: ");
    scanf("%d", &Num_1);
    printf("\n\nIngrese el segundo numero: ");
    scanf("%d", &Num_2);
    printf("\n\nIngrese el tercer numero: ");
    scanf("%d",&Num_3);
    if (Num_1>Num_2 && Num_1>Num_3)
        printf("\nEl numero mayor es %d", Num_1);
    else
    {
        if (Num_2>Num_1 && Num_2>Num_3)
            printf("\nEl numero mayor es %d", Num_2);
            else
            printf("\nEl numero mayor es %d", Num_3);
    }
    return 0;
}
