#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Num_1, Num_2, Num_3, Suma1, Suma2, Suma3;
    printf("Ingrese tres numeros: ");
    scanf ("%d %d %d", &Num_1, &Num_2, &Num_3);
    Suma1= Num_1+Num_2;
    Suma2= Num_1+Num_3;
    Suma3= Num_2+Num_3;
    if (Suma1==Num_3)
        printf("El tercer numero es igual a la suma de los otros dos");
        else
    {
        if(Suma2==Num_2)
            printf("El segundo numero es igual a la suma de los otros dos");
        else
        {
            if(Suma3==Num_1)
                printf("El primer numero es igual a la suma de los otros dos");
            else
                printf("No se cumple la consigna");
        }
    }
    return 0;
}
