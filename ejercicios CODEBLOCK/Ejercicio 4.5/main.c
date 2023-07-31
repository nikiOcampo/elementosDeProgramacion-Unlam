#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Num_1, Num_2, Num_3, Primer_num, Segundo_Num, Tercer_num;
    Primer_num=Segundo_Num=Tercer_num=0;
    printf("Ingrese el primer numero: ");
    scanf("%d", &Num_1);
    printf("\nIngrese el segundo numero: ");
    scanf("%d", &Num_2);
    printf("\nIngrese el tercer numero: ");
    scanf("%d", &Num_3);
    if (Num_1<Num_2&&Num_1<Num_3)
    {
        Primer_num=Num_1;
        if (Num_2<Num_3)
        {
            Segundo_Num=Num_2;
            Tercer_num= Num_3;
        }
            else
            {
                Segundo_Num= Num_3;
                Tercer_num= Num_2;
            }
    }
    else
    {
        if(Num_2<Num_1&&Num_2<Num_3)
        {
            Primer_num= Num_2;
            if (Num_1<Num_3)
            {
                Segundo_Num= Num_1;
                Tercer_num= Num_3;
            }
            else
            {
                Segundo_Num=Num_3;
                Tercer_num= Num_1;
            }
        }
        else
        {
            Primer_num= Num_3;
            if(Num_1<Num_2)
            {
                Segundo_Num= Num_1;
                Tercer_num= Num_2;
            }
            else
            {
                Segundo_Num= Num_2;
                Tercer_num= Num_1;
            }
        }

    }
    printf("El orden creciente de los numeros ingresados es: %d - %d - %d", Primer_num,Segundo_Num,Tercer_num);
    return 0;
}
