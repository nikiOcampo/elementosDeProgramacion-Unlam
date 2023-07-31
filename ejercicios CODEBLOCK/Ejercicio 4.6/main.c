#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Num_1, Num_2,Num_3,Num_4,Num_menor,Num_orden;
    printf("Ingrese el primer numero: ");
    scanf("%d", &Num_1);
    printf("\nIngrese el segundo numero: ");
    scanf("%d",&Num_2);
    printf("\nIngrese el tercer numero: ");
    scanf("%d",&Num_3);
    printf("\nIngrese el cuarto numero: ");
    scanf("%d",&Num_4);
    if (Num_1<Num_2&&Num_1<Num_3&&Num_1<Num_4)
    {
        Num_menor= Num_1;
        Num_orden= 1;
    }
    else
    {
        if(Num_2<Num_1&&Num_2<Num_3&&Num_2<Num_4)
        {
            Num_menor=Num_2;
            Num_orden= 2;
        }
        else
        {
            if(Num_3<Num_1&&Num_3<Num_2&&Num_3<Num_4)
            {
                Num_menor=Num_3;
                Num_orden=3;
            }
            else
            {
                Num_menor=Num_4;
                Num_orden=4;
            }
        }
    }
    printf("Los numeros cargados son: %d - %d - %d - %d ",Num_1,Num_2,Num_3,Num_4);
    printf("\nEl numero menor es: %d", Num_menor);
    printf("\nSu numero de orden es: %d",Num_orden);
    return 0;
}
