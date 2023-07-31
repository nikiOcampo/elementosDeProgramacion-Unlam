#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Num;
    float MiB, GiB, TiB;
    printf("Ingrese un valor en KiB: ");
    scanf ("%d", &Num);
    MiB= (float) Num/1024;
    GiB= (float) MiB/1024;
    TiB= (float) GiB/1024;
    printf("\nMiB: %f",MiB);
    printf("\nGiB: %f",GiB);
    printf("\nTiB: %f",TiB);
    return 0;
}
