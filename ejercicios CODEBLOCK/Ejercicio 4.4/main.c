#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Num_1, Num_2, Num_3;
    printf("Ingresa el primer numero: ");
    scanf("%d", &Num_1);
    printf("\nIngresa el segundo numero: ");
    scanf("%d", &Num_2);
    printf("\nIngrese el tercer numero: ");
    scanf("%d", &Num_3);
    if(Num_1>Num_3 && Num_2>Num_3)
        printf("\nMayores al tercero");
    else
    {
        if(Num_1==Num_2&&Num_2==Num_3)
            printf("\nTres iguales");
        else
        {
            if(Num_1<Num_3||Num_2<Num_3)
                printf("Alguno es menor");
            else
                printf("No se cumple la consigna");
        }
    }
    return 0;
}
